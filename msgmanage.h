#ifndef MSGMANAGE_H
#define MSGMANAGE_H

#include <QSqlDatabase>

#include <QSqlQuery>

#include <QVariant>

#include <defiction.h>

extern int ID;

struct QueryMsg{
    int id;
    QString from;
    QString to;
    QString time;
    int state;
    };

class MsgManage : public DeFiction
{
public:
    MsgManage();

    bool VerificationLogin(QString Username, QString Password,int* ID);

    bool VerificationRegister(QString Username,QString Password,QString Name,bool Man,bool woman,QString telephone,QString Cardnumber);

    bool VerificationOldpassword(QString Oldpassword,int ID);

    bool VerificationSeekpassword(QString Username,QString Name,QString Telephone,QString Cardnumber,int* ID);

    bool VerificationTelephone(QString Telephone);

    bool VerificationCardnumber(QString Cardnumber);

    bool ChangeUserName(QString Newusername,int ID);

    bool ChangePassword(QString Newpassword,int ID);

    bool VerificationQuery(QString from,QString to,QString time);

    bool VerificationCall(QString to,QString time);

    bool MsgDelete(int ID);

    bool QueryDelete(int ID);

    bool QueryFinish(int ID);

    bool QueryTimeEnsure(int ID);

    bool QueryAutoFinish(int ID);

    int NumberCheck(int ID);

    QString UserNameRead(int ID);

    bool QueryExist();

    QueryMsg* Msgfill(int ID);

};

#endif // MSGMANAGE_H
