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
    bool initDB(vector<string> argv);  //连接mysql:host,user,passwd,db_name
    vector<vector<string>> exeSQL(string sql);         //执行sql语句
    int insert(string table, int argc, char *argv[]);  // insert,限定字符串
    void echoSQL(string sql);    //打印执行的SQL语句
    vector<string> getDBInfo();  //读取数据库登录信息
   private:
    MYSQL *mysql;       //连接mysql句柄指针
    MYSQL_RES *result;  //指向查询结果的指针
    MYSQL_ROW row;      //按行返回的查询信息
};

#endif
