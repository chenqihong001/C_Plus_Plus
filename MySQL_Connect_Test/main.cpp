#include <mysql.h>
#include <iostream>
int main()
{
    MYSQL *mysql;
    mysql = mysql_init(NULL);
    if (mysql_real_connect(mysql, "localhost", "root", "0322", "study", 3306, NULL, 0) == NULL)
        return 0;
    mysql_set_character_set(mysql, "utf8");
    // 执行SQL语句
    int n = mysql_query(mysql, "select * from stu");

    MYSQL_RES *res = mysql_store_result(mysql);
    int row = mysql_num_rows(res);
    int col = mysql_num_fields(res);
    for (int i = 0; i < row; i++)
    {
        MYSQL_ROW row = mysql_fetch_row(res);
        for (int j = 0; j < col; j++)
        {
            std::cout << row[j] << " ";
        }
        std::cout << std::endl;
    }
    // 释放资源
    mysql_free_result(res);
    mysql_close(mysql);
    return 0;
}