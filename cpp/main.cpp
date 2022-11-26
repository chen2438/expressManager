#include "expressObject.cpp"

// #include <fstream>
// #include <iostream>
using namespace std;

int main(int argc, string argv[]) {  //系统界面传参
    //参数：本身,执行动作，动作参数
    cout << (argv[1] == "signUp") << endl;
    if (argc == 1) {  //无参数传入，执行控制台UI
        // codes
    } else if (argv[1] == "signUp") {
        cout << "enter signup modle" << endl;
        User user;
        user.signUp(argv[2], argv[3], argv[4]);
    }
    return 0;
}