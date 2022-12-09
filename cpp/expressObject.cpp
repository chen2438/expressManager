#include "expressObject.h"

void echo(string str) { cout << str << endl; }

int User::signUp(char* argv[]) {  // 注册:phone,passwd,userType
    MyDB db;
    db.initDB(db.getDBInfo());  // host,user,passwd,dbName
    db.exeSQL("use expressDB;");
    db.insert("user", 3, argv + 0);
    return 0;
}

int User::logIn(char* argv[]) {  // 登录:phone,passwd
    MyDB db;
    db.initDB(db.getDBInfo());  // host,user,passwd,dbName
    db.exeSQL("use expressDB;");
    string sqlCMD = "select passwd,userType from user where phone = '" +
                    (string)argv[0] + "';";
    db.echoSQL(sqlCMD);
    vector<vector<string>> res = db.exeSQL(sqlCMD);
    if (res.size() == 0) {
        echo("Account doesn't exist.");
        return 0;
    }
    if (res[0][0] == (string)argv[1]) {
        echo("Password correct.");
        if (res[0][1][0] == 'r') {  // recipient account
            return 1;
        } else {  // collector account
            return 2;
        }
    } else {
        echo("Password wrong.");
        return 0;
    }
}

int ExpressManager::record(char* argv[]) {  // 录入快递
    MyDB db;
    db.initDB(db.getDBInfo());  // host,user,passwd,dbName
    db.exeSQL("use expressDB;");
    argv[1] = (char*)getPickupID(argv + 0).c_str();
    argv[12] = (char*)"no";
    db.insert("express", 13, argv + 0);
    return 0;
}

string ExpressManager::getPickupID(char* argv[]) {  // 生成取件码
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

int ExpressManager::query(char* argv[]) {
    // 参数: expressID, pickupID, phone
    string expressID = argv[0], pickupID = argv[1], phone = argv[2];
    MyDB db;
    db.initDB(db.getDBInfo());  // host,user,passwd,dbName
    db.exeSQL("use expressDB;");
    vector<vector<string>> res;
    if (expressID != "null") {
        res = db.exeSQL("select * from express where expressID = '" +
                        expressID + "';");
    } else if (pickupID != "null") {
        res = db.exeSQL("select * from express where pickupID = '" + pickupID +
                        "';");
    } else if (phone != "null") {
        res = db.exeSQL("select * from express where receieverPhone = '" +
                        phone + "';");
    }
    vector<vector<string>> column_name;
    column_name = db.exeSQL(
        "select column_name from information_schema.columns where table_name = "
        "'express';");

    if (res.empty()) {
        echo("The results do not exist!");
        exit(0);
    }
    echo("Return for PHP begin:");
    echo("<br>");
    echo(
        "<table style='border-color: #efefef;' border='1px' cellpadding='5px' "
        "cellspacing='0px' >");
    echo("<caption>Express Query Result</caption>");
    echo("<thead><tr>");
    for (auto i : column_name) {
        echo("<th>" + i[0] + "</th>");
    }
    echo("</tr></thead>");
    echo("<tbody><tr>");
    for (auto i : res) {
        for (auto j : i) {
            echo("<td>" + j + "</td>");
        }
    }
    echo("</tr></tbody>");
    echo("</table>");
    echo("<br>");
    cout << "Return for PHP end." << endl;
    return 0;
}

int ExpressManager::del(string expressID) {
    MyDB db;
    db.initDB(db.getDBInfo());  // host,user,passwd,dbName
    db.exeSQL("use expressDB;");
    vector<vector<string>> res;
    // db.exeSQL("")
}