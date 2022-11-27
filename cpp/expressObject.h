#include "head.h"

class User {  //人员基类
   public:
    string ID;
    string passwd;
    string userType;
    int signUp(char* argv[]);                //注册
    int logIn(string phone, string passwd);  //登入
    vector<string> getDBInfo();              //读取数据库登入信息
};

class Collector : public User {  //代收员
   public:
    static const char* adminPasswd;  //初始管理员权限密码
};

class Recipient : public User {  //收件人
};

class Express {  //快件
   public:
    string expressID, pickupID, company, weight, receiver, receiverPhone,
        receiverAddress, receiverZip, sender, senderPhone, senderAddress,
        senderZip;
};

class ExpressManager {  //快件管理
   public:
    int recordExpress();
};

class UserInterface {  //系统界面
};