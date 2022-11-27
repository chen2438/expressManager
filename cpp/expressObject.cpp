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
            // cout << "This is a recipient account." << endl;
            return 1;
        } else {
            // cout << "This is a collector account." << endl;
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
    cout << "debug" << endl;
    argv[1] = (char*)getPickupID(argv + 0).c_str();
    for (int i = 0; i < 12; i++) {
        cout << argv[i] << endl;
    }
    cout << "debug" << endl;
    db.insert("express", 12, argv + 0);
    return 0;
}

string ExpressManager::getPickupID(char* argv[]) {  //生成取件码
    // 2位快递公司缩写+后2位快递单号+收件人后2位手机号+重量模100+2位时间戳
    string company = argv[2];
    string expressID = argv[0];
    expressID = expressID.substr(expressID.size() - 2, 2);
    string receiverPhone = argv[5];
    receiverPhone = receiverPhone.substr(receiverPhone.size() - 2, 2);
    string weight = argv[3];
    weight = weight.substr(weight.size() - 2, 2);
    string nowTime = to_string(time(0));  // 1970 到现在经过秒数
    nowTime = nowTime.substr(nowTime.size() - 2, 2);
    string pickupID = company + expressID + receiverPhone + weight + nowTime;
    return pickupID;
}