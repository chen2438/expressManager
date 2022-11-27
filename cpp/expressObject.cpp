#include "expressObject.h"

vector<string> User::getDBInfo() {
    //从文件读取数据库登入信息
    ifstream connectDB("/var/www/html/connectDB.in", ios::in);
    vector<string> res(10);
    int cnt = 0;
    while (connectDB >> res[cnt]) {
        cnt++;
    }
    connectDB.close();
    return res;
}

int User::signUp(char* argv[]) {  //注册:phone,passwd,userType
    vector<string> DBInfo = getDBInfo();
    MyDB db;
    db.initDB(DBInfo[0], DBInfo[1], DBInfo[2],
              DBInfo[3]);  // host,user,passwd,dbName
    db.echoSQL("use expressDB;");
    db.exeSQL("use expressDB;");
    string sqlCMD = "insert user values('" + (string)argv[0] + "','" +
                    (string)argv[1] + "','" + (string)argv[2] + "');";
    db.echoSQL(sqlCMD);
    db.exeSQL(sqlCMD);
    return 0;
}

int User::logIn(char* argv[]) {  //登录:phone,passwd
    vector<string> DBInfo = getDBInfo();
    MyDB db;
    db.initDB(DBInfo[0], DBInfo[1], DBInfo[2],
              DBInfo[3]);  // host,user,passwd,dbName
    db.echoSQL("use expressDB;");
    db.exeSQL("use expressDB;");
    string sqlCMD = "select passwd,userType from user where phone = '" +
                    (string)argv[0] + "';";
    db.echoSQL(sqlCMD);
    vector<vector<string>> res = db.exeSQL(sqlCMD);
    if (res.size() == 0) {
        cout << "Account doesn't exist." << endl;
        return 0;
    }
    if (res[0][0] == (string)argv[1]) {
        cout << "Password correct." << endl;
        // cout << res[0][1].size() << endl;
        if (res[0][1][0] == 'r') {
            cout << "This is a recipient account." << endl;
            return 1;
        } else {
            cout << "This is a collector account." << endl;
            return 2;
        }
    } else {
        cout << "Password wrong." << endl;
        return 0;
    }
}