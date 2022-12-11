#include "head.h"

class User {  // 人员基类
   public:
    void signUp(char* argv[]);  // 注册:phone,passwd,userType
    int logIn(char* argv[]);    // 登录:phone,passwd
};

class Collector : public User {  // 代收员
   public:
    static const char* adminPasswd;  // 初始管理员权限密码
    void changeSuperPassword();      // 修改初始管理员权限密码,TODO
    void changePassword();           // 修改密码,TODO
};

class Recipient : public User {  // 收件人
    void changePassword();       // 修改密码,TODO
};

class ExpressManager {  // 快件管理
   public:
    void record(char* argv[]);  // 录入快递
    // 参数: expressID, pickupID, company, weight, receiver,
    // receiverPhone,receiverAddress, receiverZip, sender,
    // senderPhone, senderAddress, senderZip, picked
    // inDate, outDate
    string getPickupID(char* argv[]);  // 生成取件码, 参数同 record()
    void query(char* argv[]);          // 查询快递
    // 参数: expressID, pickupID, phone
    void queryAll();          // 查询所有未取快递
    void stats();             // 信息统计，TODO
    void del(char* argv[]);   // 删除快递,参数:expressID
    void mark(char* argv[]);  // 标记取件,参数:pickupID
};