#include <iostream>
#include <mysql.h>
#include <vector>
#include <mutex>
#include <mysql/client_plugin.h>

class ConnectionPool
{
private:
    std::vector<MYSQL *> connections;
    std::vector<bool> in_use;
    std::string host;
    std::string user;
    std::string password;
    std::string database;
    int port;
    int max_connections;
    std::mutex mtx;

public:
    ConnectionPool(const std::string &host, const std::string &user, const std::string &password,
                   const std::string &database, int port, int max_conn)
        : host(host), user(user), password(password), database(database), port(port), max_connections(max_conn)
    {
        connections.resize(max_connections, nullptr);
        in_use.resize(max_connections, false);
    }

    ~ConnectionPool()
    {
        for (auto conn : connections)
        {
            if (conn != nullptr)
            {
                mysql_close(conn);
            }
        }
    }

    MYSQL *getConnection()
    {
        std::lock_guard<std::mutex> lock(mtx);
        for (int i = 0; i < max_connections; ++i)
        {
            if (!in_use[i])
            {
                if (connections[i] == nullptr)
                {
                    connections[i] = mysql_init(nullptr);
                    if (!connections[i])
                    {
                        std::cerr << "Error initializing MySQL connection" << std::endl;
                        return nullptr;
                    }
                    if (!mysql_real_connect(connections[i], host.c_str(), user.c_str(),
                                            password.c_str(), database.c_str(), port, nullptr, 0))
                    {
                        std::cerr << "Error connecting to MySQL: " << mysql_error(connections[i]) << std::endl;
                        mysql_close(connections[i]);
                        connections[i] = nullptr;
                        return nullptr;
                    }
                }
                in_use[i] = true;
                return connections[i];
            }
        }
        return nullptr; // No available connections
    }

    void releaseConnection(MYSQL *conn)
    {
        std::lock_guard<std::mutex> lock(mtx);
        for (int i = 0; i < max_connections; ++i)
        {
            if (connections[i] == conn)
            {
                in_use[i] = false;
                break;
            }
        }
    }
};

int main()
{
    ConnectionPool pool("localhost", "root", "password", "my_database", 3306, 5);

    MYSQL *conn1 = pool.getConnection();
    if (conn1 == nullptr)
    {
        std::cerr << "Failed to get connection." << std::endl;
        return 1;
    }

    // Use the connection conn1 here...

    pool.releaseConnection(conn1);

    MYSQL *conn2 = pool.getConnection();
    if (conn2 == nullptr)
    {
        std::cerr << "Failed to get connection." << std::endl;
        return 1;
    }

    // Use the connection conn2 here...

    pool.releaseConnection(conn2);

    return 0;
}
