#include "expressObject.h"

vector<string> User::getDBInformation() {
    //从文件读取数据库登入信息
    ifstream connectDB("/var/www/html/connectDB.in", ios::in);
    vector<string> res(10);
    int argc = 0;
    while (connectDB >> res[argc]) {
        argc++;
    }
    connectDB.close();
    return res;
}

int User::signUp(string phone, string passwd, string userType) {
    vector<string> argv = getDBInformation();
    MyDB db;
    db.initDB(argv[0], argv[1], argv[2], argv[3]);  // host,user,passwd,dbName
    db.echoSQL("use expressDB;");
    db.exeSQL("use expressDB;");
    string sqlCMD = "insert user values('" + phone + "','" + passwd + "','" +
                    userType + "');";
    db.echoSQL(sqlCMD);
    db.exeSQL(sqlCMD);
    return 0;
}

int User::logIn(string phone, string passwd) {
    vector<string> argv = getDBInformation();
    MyDB db;
    db.initDB(argv[0], argv[1], argv[2], argv[3]);  // host,user,passwd,dbName
    db.echoSQL("use expressDB;");
    db.exeSQL("use expressDB;");
    string sqlCMD =
        "select passwd,userType from user where phone = '" + phone + "';";
    db.echoSQL(sqlCMD);
    vector<vector<string>> res = db.exeSQL(sqlCMD);
    cout << "debug" << endl;
    if (res[0][0] == passwd) {
        cout << "Password correct." << endl;
        // cout << res[0][1].size() << endl;
        if (res[0][1][0] == 'r') {
            cout << "This is a recepient account." << endl;
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