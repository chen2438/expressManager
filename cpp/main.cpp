#include "expressObject.cpp"
// #include "expressObject.h"

int main(int argc, char* argv[]) {  //系统界面传参
    //参数：本身,执行动作，动作参数
    if (argc == 1) {  //无参数传入，执行控制台UI
        // codes

    } else if (argv[1] == "signUp") {
        // ofstream out("main.out", ios::out | ios::trunc);
        // out << argv[2] << argv[3] << argv[4];
        // out.close();
        User user;
        user.signUp(argv[2], argv[3], argv[4]);
    }
    return 0;
}