#include "expressObject.cpp"

const char* Collector::adminPasswd = "admin";

int main(int argc, char* argv[]) {  // 系统界面传参
    if (argc == 1) {
        exit(0);
    } else if (strcmp(argv[1], "signUp") == 0) {  // 注册
        // self,action,phone,passwd,userType
        cout << "Start registration." << endl;
        if (strcmp(argv[4], "0") == 0) {
            cout << "Register for recipient." << endl;
            Recipient recipient;
            argv[4] = (char*)"recipient";
            recipient.signUp(argv + 2);
            cout << "Registration successful!" << endl;
        } else if (strcmp(argv[4], Collector::adminPasswd) == 0) {
            cout << "Password correct. Register for collector." << endl;
            Collector collector;
            argv[4] = (char*)"collector";
            collector.signUp(argv + 2);
            cout << "Registration successful!" << endl;
        } else {
            cout << "Admin password wrong." << endl;
            cout << "Registration failed!" << endl;
        }
    } else if (strcmp(argv[1], "logIn") == 0) {  // 登录
        cout << "Start login." << endl;
        User user;
        int res = user.logIn(argv + 2);
        if (res == 1) {
            cout << "Login successful!" << endl;
            cout << "Recipient, welcome!" << endl;
        } else if (res == 2) {
            cout << "Login successful!" << endl;
            cout << "Collector, welcome!" << endl;
        } else {
            cout << "Login failed!" << endl;
        }
    } else if (strcmp(argv[1], "record") == 0) {  // 录入
        cout << "Start recording." << endl;
        ExpressManager manager;
        manager.record(argv + 2);
        cout << "Recording successful!" << endl;
    } else if (strcmp(argv[1], "query") == 0) {  // 查询
        cout << "Start querying." << endl;
        ExpressManager manager;
        argv[5] = (char*)"null";
        manager.query(argv + 2);
        cout << "Querying successful!" << endl;
    } else if (strcmp(argv[1], "delete") == 0) {  // 删除
        cout << "Start deleting." << endl;
        ExpressManager manager;
        manager.del(argv + 2);
        cout << "Delete successful!" << endl;
    } else if (strcmp(argv[1], "queryAll") == 0) {  // 查询所有未取
        cout << "Start querying." << endl;
        ExpressManager manager;
        manager.queryAll();
        cout << "Querying successful!" << endl;
    }
    return 0;
}