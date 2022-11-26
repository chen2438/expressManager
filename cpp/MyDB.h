#ifndef _MYDB_H
#define _MYDB_H

#include <mysql/mysql.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MyDB {
   public:
    MyDB();
    ~MyDB();
    bool initDB(string host, string user, string passwd,
                string db_name);                //连接mysql
    vector<vector<string>> exeSQL(string sql);  //执行sql语句
    void echoSQL(string sql);                   //打印执行的SQL语句
   private:
    MYSQL *mysql;       //连接mysql句柄指针
    MYSQL_RES *result;  //指向查询结果的指针
    MYSQL_ROW row;      //按行返回的查询信息
};

#endif
