#include "head.h"

class User {  //人员基类
   public:
    string ID;
    string passwd;
    string userType;
    int signUp(string phone, string passwd, string userType);  //注册
    int logIn(string phone, string passwd, string userType);   //登入
};

class Collector : public User {  //代收员
   public:
    static char* adminPasswd;
};

class Recipient : public User {  //收件人
};

class Express {  //快件
};

class ExpressManager {  //快件管理
};

class UserInterface {  //系统界面
};