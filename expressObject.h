#include "head.h";

class User {  //人员基类
   public:
    string ID;
    string password;
    string userType;
    int login(string ID, string password, string userType);
};

class Collector : public User {  //代收员
   public:
};

class Recipient : public User {  //收件人
};

class Express {  //快件
};

class ExpressManager {  //快件管理
};

class UserInterface {  //系统界面
};