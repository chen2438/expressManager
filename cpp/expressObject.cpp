#include "expressObject.h"

int User::signUp(string phone, string passwd, string userType) {
    ifstream connectDB("/var/www/html/connectDB.in",
                       ios::in);  //从文件读取数据库登入信息
    string argv[10];
    int argc = 0;
    while (connectDB >> argv[argc]) {
        // cout << argv[argc] << endl;
        argc++;
    }
    connectDB.close();

    MyDB db;                                        //建立数据库连接
    db.initDB(argv[0], argv[1], argv[2], argv[3]);  // host,user,passwd,dbName
    db.exeSQL("use expressDB;");
    string cmd =
        "insert user values(" + phone + "," + passwd + "," + userType + ");";
    db.exeSQL(cmd);
    return 1;
}
