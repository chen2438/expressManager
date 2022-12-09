#include "MyDB.h"

MyDB::MyDB() {
    mysql = mysql_init(NULL);  // 初始化数据库连接变量
    if (mysql == NULL) {
        cout << "Error:" << mysql_error(mysql);
        exit(1);
    }
}

MyDB::~MyDB() {
    if (mysql != NULL) {  // 关闭数据连接
        mysql_close(mysql);
    }
}

bool MyDB::initDB(vector<string> argv) {  // 连接mysql:host,user,passwd,db_name
    // 函数mysql_real_connect建立一个数据库连接
    // 成功返回MYSQL*连接句柄，失败返回NULL
    mysql = mysql_real_connect(mysql, argv[0].c_str(), argv[1].c_str(),
                               argv[2].c_str(), argv[3].c_str(), 0, NULL, 0);
    if (mysql == NULL) {
        cout << "Error: " << mysql_error(mysql);
        exit(1);
    }
    return true;
}

vector<vector<string>> MyDB::exeSQL(string sql) {
    echoSQL(sql);
    vector<vector<string>> res;
    if (mysql_query(mysql, sql.c_str())) {
        cout << "Query Error: " << mysql_error(mysql);
        exit(1);
    } else {
        result = mysql_store_result(mysql);  // 获取结果集
        if (result) {
            int num_fields = mysql_num_fields(result);  // 字段数
            int num_rows = mysql_num_rows(result);      // 行数
            for (int i = 0; i < num_rows; i++) {
                row = mysql_fetch_row(result);  // 获取一行
                if (row < 0) break;
                vector<string> t;
                for (int j = 0; j < num_fields; j++) {  // 每一字段
                    // cout << row[j] << " ";
                    t.push_back(row[j]);
                }
                res.push_back(t);
                // cout << endl;
            }

        } else {                                            // result==NULL
            if (mysql_field_count(mysql) == 0) {            // 非 select 语句
                int num_rows = mysql_affected_rows(mysql);  // 行数
            } else {                                        // error
                cout << "Get result error: " << mysql_error(mysql);
                exit(1);
            }
        }
    }
    return res;
}

void MyDB::echoSQL(string SQL) { cout << "SQL_CMD: " << SQL << endl; }

vector<string> MyDB::getDBInfo() {
    // 从文件读取数据库登入信息
    ifstream connectDB("/var/www/html/connectDB.in", ios::in);
    vector<string> res(10);
    int cnt = 0;
    while (connectDB >> res[cnt]) {
        cnt++;
    }
    connectDB.close();
    return res;
}

int MyDB::insert(string table, int argc, char* argv[]) {  // insert,限定字符串
    string sqlCMD = "insert " + table + " values(";
    for (int i = 0; i < argc - 1; i++) {
        sqlCMD = sqlCMD + "'" + (string)argv[i] + "',";
    }
    sqlCMD = sqlCMD + "'" + (string)argv[argc - 1] + "');";
    exeSQL(sqlCMD);
    return 0;
}