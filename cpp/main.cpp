#include "expressObject.cpp"

const char* Collector::adminPasswd = "admin";

int main(int argc, char* argv[]) {  //系统界面传参
    if (argc == 1) {
    } else if (strcmp(argv[1], "signUp") == 0) {
        // self,action,phone,passwd,userType
        cout << "Start registration." << endl;
        if (strcmp(argv[4], "0") == 0) {
            Recipient recipient;
            recipient.signUp(argv[2], argv[3], "recipient");
        } else if (strcmp(argv[4], Collector::adminPasswd) == 0) {
            Collector collector;
            collector.signUp(argv[2], argv[3], "collector");
        }
        cout << "Registration successful!" << endl;
    }
    return 0;
}