#include "expressObject.h"

int User::signUp(char* argv[]) {  //注册:phone,passwd,userType
    MyDB db;
    db.initDB(db.getDBInfo());  // host,user,passwd,dbName
    db.exeSQL("use expressDB;");
    db.insert("user", 3, argv + 0);
    return 0;
}

int User::logIn(char* argv[]) {  //登录:phone,passwd
    MyDB db;
    db.initDB(db.getDBInfo());  // host,user,passwd,dbName
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

int ExpressManager::record(char* argv[]) {
    MyDB db;
    db.initDB(db.getDBInfo());  // host,user,passwd,dbName
    db.exeSQL("use expressDB;");
    db.insert("express", 12, argv + 0);
    return 0;
}