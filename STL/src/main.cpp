#include <iostream>
#include <mysql.h>

using namespace std;
int main()
{
    cout << "Hello, world!" << endl;
    // q1();
    MYSQL conn;
    int res;
    mysql_init(&conn);
    if (mysql_real_connect(&conn, "127.0.0.1", "root", "123", "test", 0, NULL, CLIENT_FOUND_ROWS)) //"root":数据库管理员 ,:123密码 "test":数据库的名字
    {
        printf("connect success!\n");
        res = mysql_query(&conn, "insert into test values('user','123456')");
        if (res)
        {
            printf("error\n");
        }
        else
        {
            printf("OK\n");
        }
        mysql_close(&conn);
    }
    else
    {
        printf("connect errot!\n");
    }
    return 0;
}
