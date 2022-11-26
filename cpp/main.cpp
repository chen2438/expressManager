#include "expressObject.cpp"

const char* Collector::adminPasswd = "admin";

int main(int argc, char* argv[]) {  //系统界面传参
    if (argc == 1) {
        exit(0);
    } else if (strcmp(argv[1], "signUp") == 0) {  //注册
        // self,action,phone,passwd,userType
        cout << "Start registration." << endl;
        if (strcmp(argv[4], "0") == 0) {
            cout << "Register for recipient." << endl;
            Recipient recipient;
            argv[4] = (char*)"recipient";
            recipient.signUp(argv[2], argv[3], argv[4]);
            cout << "Registration successful!" << endl;
        } else if (strcmp(argv[4], Collector::adminPasswd) == 0) {
            cout << "Password correct. Register for collector." << endl;
            Collector collector;
            argv[4] = (char*)"collector";
            collector.signUp(argv[2], argv[3], argv[4]);
            cout << "Registration successful!" << endl;
        } else {
            cout << "Admin password wrong." << endl;
            cout << "Registration failed!" << endl;
        }
    } else if (strcmp(argv[1], "logIn") == 0) {  //登录
        cout << "Start Login." << endl;
        User user;
        int res = user.logIn(argv[2], argv[3]);
        if (res == 1) {
            cout << "Login successful!" << endl;
        } else if (res == 2) {
            cout << "Login successful!" << endl;
        } else {
            cout << "Login failed!" << endl;
        }
    }
    return 0;
}