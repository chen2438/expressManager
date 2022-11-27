#include "head.h"

class User {  //人员基类
   public:
    int signUp(char* argv[]);  //注册:phone,passwd,userType
    int logIn(char* argv[]);   //登录:phone,passwd
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
    int recordExpress(
        char* argv[]);  // expressID, pickupID, company, weight, receiver,
                        // receiverPhone,receiverAddress, receiverZip, sender,
                        // senderPhone, senderAddress,senderZip;
};

class UserInterface {  //系统界面
};