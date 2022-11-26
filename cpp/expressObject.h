#include "head.h"

class User {  //人员基类
   public:
    string ID;
    string passwd;
    string userType;
    int signUp(string phone, string passwd, string userType);  //注册
    int logIn(string phone, string passwd);                    //登入
    vector<string> getDBInformation();  //读取数据库登入信息
};

class Collector : public User {  //代收员
   public:
    static const char* adminPasswd;
};

class Recipient : public User {  //收件人
};

class Express {  //快件
};

class ExpressManager {  //快件管理
};

class UserInterface {  //系统界面
};