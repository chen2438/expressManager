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
};

class ExpressManager {  //快件管理
   public:
    int record(char* argv[]);  //录入快递
    // 参数: expressID, pickupID, company, weight, receiver,
    // receiverPhone,receiverAddress, receiverZip, sender,
    // senderPhone, senderAddress, senderZip, picked
    string getPickupID(char* argv[]);  //生成取件码, 参数同 record()
    int query(char* argv[]);           //查询快递
    //参数: expressID, pickupID, phone
    vector<vector<string>> queryAll(char* argv[]);  //查询所有快件
    void echo(string str);
};

class UserInterface {  //系统界面
};