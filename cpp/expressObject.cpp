#include "expressObject.h"

void echo(string str) { cout << str << endl; }

void User::signUp(char* argv[]) {  // 注册:phone,passwd,userType
    MyDB db;
    db.initDB(db.getDBInfo());  // host,user,passwd,dbName
    db.exeSQL("use expressDB;");
    db.insert("user", 3, argv + 0);
}

int User::logIn(char* argv[]) {  // 登录:phone,passwd
    MyDB db;
    db.initDB(db.getDBInfo());
    db.exeSQL("use expressDB;");
    string sqlCMD = "select passwd,userType from user where phone = '" +
                    (string)argv[0] + "';";
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

void ExpressManager::record(char* argv[]) {  // 录入快递
    MyDB db;
    db.initDB(db.getDBInfo());
    db.exeSQL("use expressDB;");
    argv[1] = (char*)getPickupID(argv + 0).c_str();
    argv[12] = (char*)"no";  // picked
    time_t now = time(0);
    tm* ltm = localtime(&now);
    string Time = to_string(ltm->tm_year + 1900) + "-" +
                  to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday);
    argv[13] = (char*)Time.c_str();  // inDate
    argv[14] = (char*)"null";        // outDate
    db.insert("express", 13, argv + 0);
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

void ExpressManager::query(char* argv[]) {
    // 参数: expressID, pickupID, phone, picked
    string expressID = argv[0], pickupID = argv[1], phone = argv[2],
           picked = argv[3];
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
    } else if (picked == "no") {
        res = db.exeSQL("select * from express where picked = 'no';");
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
    echo("</tr></thead><tbody>");
    for (auto i : res) {
        echo("<tr>");
        for (auto j : i) {
            echo("<td>" + j + "</td>");
        }
        echo("</tr>");
    }
    echo("</tbody></table><br>");
    cout << "Return for PHP end." << endl;
}

void ExpressManager::queryAll() {
    // expressID, pickupID, phone, picked=no
    char* argv[] = {(char*)"null", (char*)"null", (char*)"null", (char*)"no"};
    query(argv + 0);
}

void ExpressManager::del(char* argv[]) {  // 删除快递,参数:expressID
    string expressID = argv[0];
    MyDB db;
    db.initDB(db.getDBInfo());
    db.exeSQL("use expressDB;");
    db.exeSQL("delete from express where expressID='" + expressID + "';");
}

void ExpressManager::mark(char* argv[]) {  // 标记取件,参数:pickupID
    string pickupID = argv[0];
    MyDB db;
    db.initDB(db.getDBInfo());
    db.exeSQL("use expressDB;");

    time_t now = time(0);
    tm* ltm = localtime(&now);
    string Time = to_string(ltm->tm_year + 1900) + "-" +
                  to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday);
    db.exeSQL("update express set picked='yes' where pickupID='" + pickupID +
              "';");
    db.exeSQL("update express set outDate='" + Time + "' where pickupID='" +
              pickupID + "';");
}