#include "expressObject.cpp"

// #include <iostream>
using namespace std;

int main(int argc, char* argv[]) {  //系统界面传参
    //参数：本身,执行动作，动作参数
    if (argc == 1) {
    } else if (argv[1][0] == 's') {
        cout << "enter signup modle" << endl;
        User user;
        user.signUp(argv[2], argv[3], argv[4]);
        cout << "signUp ends" << endl;
    }
    return 0;
}