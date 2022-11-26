#include "expressObject.cpp"

const char* Collector::adminPasswd = "admin";

int main(int argc, char* argv[]) {  //系统界面传参
    if (argc == 1) {
    } else if (strcmp(argv[1], "signUp") == 0) {
        // self,action,phone,passwd,userType
        cout << "Start registration." << endl;
        if (strcmp(argv[4], "0") == 0) {
            cout << "Register for recipient." << endl;
            Recipient recipient;
            argv[4] = "recipient";
            recipient.signUp(argv[2], argv[3], argv[4]);
        } else if (strcmp(argv[4], Collector::adminPasswd) == 0) {
            cout << "Correct password. Register for collector." << endl;
            Collector collector;
            argv[4] = "collector";
            collector.signUp(argv[2], argv[3], argv[4]);
        }
        cout << "Registration successful!" << endl;
    }
    return 0;
}