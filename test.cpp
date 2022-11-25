#include <iostream>

#include "MyDB.h"
using namespace std;

int main() {
    MyDB db;
    //连接数据库
    db.initDB("localhost", "root", "Chen2438!", "test");
    //将用户信息添加到数据库
    db.exeSQL("INSERT user values('10000','123456','13456982338');");
    // db.exeSQL("INSERT accounts values('axin','456');");
    //将所有用户信息读出，并输出。
    db.exeSQL("SELECT * from user;");

    return 0;
}
