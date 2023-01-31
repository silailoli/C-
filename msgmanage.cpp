#include "msgmanage.h"

#include<widget.h>

#include<QtGlobal>

#include <QTime>

int ID=0;

MsgManage::MsgManage()
{

}

//登录信息查询
bool MsgManage::VerificationLogin(QString Username, QString Password,int *ID)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        QSqlQuery query(db);
        if(query.exec("select * from usermsg.user"))
        {
            while(query.next())
            {
                QString username = query.value(1).toString().trimmed();
                QString password = query.value(2).toString().trimmed();
                if((Username == username) && (Password == password)){
                    *ID = query.value(0).toInt();
                    return true;
                }
            }
            db.close();
        }
    }
    return false;
}
//预约信息写入
bool MsgManage::VerificationRegister(QString Username,QString Password,QString Name,bool Man,bool woman,QString telephone,QString Cardnumber)
{
    Widget r;
    if(r.Check(Username,Password,Name,Man,woman,telephone,Cardnumber)){
    int sex =0;
    if(Man) sex=1;
    int Age=2022-Cardnumber.mid(6,4).toInt();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        QString sql = QString("insert into usermsg.user(username,password,name,age,man,telephone,cardnumber) values('%1','%2','%3','%4','%5','%6','%7')").arg(Username).arg(Password).arg(Name).arg(Age).arg(sex).arg(telephone).arg(Cardnumber);;
        QSqlQuery query;
        query.exec(sql);
        db.close();
        return true;
    }
    }
    return false;
}
//找回密码信息查询
bool MsgManage::VerificationSeekpassword(QString Username,QString Name,QString Telephone,QString Cardnumber,int* ID)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        QSqlQuery query(db);
        if(query.exec("select * from usermsg.user"))
        {
            while(query.next())
            {
                QString username = query.value(1).toString().trimmed();
                QString name = query.value(3).toString().trimmed();
                QString telephone = query.value(6).toString().trimmed();
                QString cardnumber = query.value(7).toString().trimmed();
                if((Username == username)&&(Name==name)&&(Telephone==telephone)&&(Cardnumber==cardnumber)){
                    *ID = query.value(0).toInt();
                    return true;
                }
            }
            db.close();
        }
    }
    return false;
}
//手机号查询
bool MsgManage::VerificationTelephone(QString Telephone)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        QSqlQuery query(db);
        if(query.exec("select * from usermsg.user"))
        {
            while(query.next())
            {
                QString telephone = query.value(6).toString().trimmed();
                if(Telephone==telephone){
                    return true;
                }
            }
            db.close();
        }
    }
    return false;
}
//身份证号查询
bool MsgManage::VerificationCardnumber(QString Cardnumber)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        QSqlQuery query(db);
        if(query.exec("select * from usermsg.user"))
        {
            while(query.next())
            {
                QString cardnumber = query.value(7).toString().trimmed();
                if(Cardnumber==cardnumber){
                    return true;
                }
            }
            db.close();
        }
    }
    return false;
}
//老密码查询
bool MsgManage::VerificationOldpassword(QString Oldpassword,int ID)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        QSqlQuery query(db);
        if(query.exec("select * from usermsg.user"))
        {
            while(query.next())
        {
            int id = query.value(0).toInt();
            QString password = query.value(2).toString().trimmed();
            if((ID==id) && (Oldpassword == password)){
                return true;
            }
        }
            db.close();
        }

    }
    return false;
}
//密码信息修改
bool MsgManage::ChangePassword(QString Newpassword,int ID)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        QSqlQuery query;
        QString sql = QString("update user set password='%1' where iduser='%2'").arg(Newpassword).arg(ID);
            query.exec(sql);
            db.close();
            return true;
    }
    return false;
}
//订单信息写入
bool MsgManage::VerificationQuery(QString from,QString to,QString time)
{
    Widget a;
    if(a.Check(from,to,time)){
        if(a.PlaceCheck(from,to)){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        int ddid = get_random_number();
        QString sql = QString("insert into usermsg.userquery(useid,fromm,tow,time,ddid,statee) values('%1','%2','%3','%4','%5','1')").arg(ID).arg(from).arg(to).arg(time).arg(ddid);;
        QSqlQuery query;
        query.exec(sql);
        db.close();
        return true;
    }
        }
}
    return false;
}
//订单信息查询
bool MsgManage::QueryExist()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        QSqlQuery query(db);
        if(query.exec("select * from usermsg.userquery"))
        {
            while(query.next())
            {
                int id = query.value(1).toInt();
                int state = query.value(6).toInt();
                if(ID == id&&state==1)
                    return true;
            }
            db.close();
        }
    }
    return false;
}
//订单信息写入
bool MsgManage::VerificationCall(QString to,QString time)
{
    Widget c;
    if(c.Check(to)){
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");//localhost
        db.setPort(3306);
        db.setDatabaseName("usermsg");
        db.setUserName("root");
        db.setPassword("liuxiangyu");
        if(db.open())
        {
            QString from="中南大学南校区";
            int ddid = get_random_number();
            QString sql = QString("insert into usermsg.userquery(useid,fromm,tow,time,ddid,statee) values('%1','%2','%3','%4','%5','1')").arg(ID).arg(from).arg(to).arg(time).arg(ddid);;
            QSqlQuery query;
            query.exec(sql);
            db.close();
            return true;
        }
    }
    return false;
}
//用户信息删除
bool MsgManage::MsgDelete(int ID)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        QString sql = QString("delete from usermsg.user where iduser = '%1'").arg(ID);
        QSqlQuery query;
        query.exec(sql);
        sql = QString("delete from usermsg.userquery where useid = '%1'").arg(ID);
        query.exec(sql);
        db.close();
        return true;
    }
    return false;
}
//订单信息修改取消
bool MsgManage::QueryDelete(int ID)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        QSqlQuery query;
        QString sql = QString("update userquery set statee='-1' where useid='%1'&&statee='1'").arg(ID);
            query.exec(sql);
            db.close();
            return true;
    }
    return false;
}
//订单信息修改完成
bool MsgManage::QueryFinish(int ID)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        QSqlQuery query;
        QString sql = QString("update userquery set statee='0' where useid='%1'&&statee='1'").arg(ID);
            query.exec(sql);
            db.close();
            return true;
    }
    return false;
}
//用户名读入
QString MsgManage::UserNameRead(int ID)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        QSqlQuery query(db);
        if(query.exec("select * from usermsg.user"))
        {
            while(query.next())
            {
                int id = query.value(0).toInt();
                QString username = query.value(1).toString().trimmed();
                if(id==ID){
                    return username;
                }
            }
        }
        db.close();
    }
    return NULL;
}
//用户名信息修改
bool MsgManage::ChangeUserName(QString Newusername,int ID)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        QSqlQuery query;
        QString sql = QString("update user set username='%1' where iduser='%2'").arg(Newusername).arg(ID);
            query.exec(sql);
            db.close();
            return true;
    }
    return false;
}
//自动完成时间检测
bool MsgManage::QueryAutoFinish(int ID)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        QSqlQuery query(db);
        QString Querytime="";
        if(query.exec("select * from usermsg.userquery"))
        {
            while(query.next())
        {
                int id = query.value(1).toInt();
                int state = query.value(6).toInt();
                QString timee = query.value(4).toString().trimmed();
                if(ID==id&&state==1){
                    Querytime=timee;
                }

            }
    }
      db.close();
      QDateTime time = QDateTime::currentDateTime();
      int NTime = time.addDays(-1).toTime_t();
      Querytime=QString("2022-%1-%2 %3:%4:00").arg(Querytime.mid(0,2)).arg(Querytime.mid(3,2)).arg(Querytime.mid(6,2)).arg(Querytime.mid(9,2));
      QDateTime Qtime = QDateTime::fromString(Querytime,"yyyy-MM-dd hh:mm:ss");
      int QTime = Qtime.toTime_t();
      if(NTime>QTime)return true;
      }
    return false;
}
//完成时间检测
bool MsgManage::QueryTimeEnsure(int ID)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        QSqlQuery query(db);
        QString Querytime="";
        if(query.exec("select * from usermsg.userquery"))
        {
            while(query.next())
        {
                int id = query.value(1).toInt();
                int state = query.value(6).toInt();
                QString timee = query.value(4).toString().trimmed();
                if(ID==id&&state==1){
                    Querytime=timee;
                }

            }
    }
      db.close();
      QDateTime time = QDateTime::currentDateTime();
      int NTime = time.addSecs(-600).toTime_t();
      Querytime=QString("2022-%1-%2 %3:%4:00").arg(Querytime.mid(0,2)).arg(Querytime.mid(3,2)).arg(Querytime.mid(6,2)).arg(Querytime.mid(9,2));
      QDateTime Qtime = QDateTime::fromString(Querytime,"yyyy-MM-dd hh:mm:ss");
      int QTime = Qtime.toTime_t();
      if(NTime>QTime)return true;
}
    return false;
}
//订单数读入
int MsgManage::NumberCheck(int ID)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    int n=0;
    if(db.open())
    {
        QSqlQuery query(db);
        if(query.exec("select * from usermsg.userquery"))
        {
            while(query.next())
        {
                int id = query.value(1).toInt();
                if(ID==id){
                    n++;
                }
            }
        }
    }
     db.close();
     return n;
}
//订单信息读入结构体
QueryMsg* MsgManage::Msgfill(int ID)
{
    const int n=NumberCheck(ID);
    QueryMsg* p=new QueryMsg[n];
    int i=0;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setPort(3306);
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        QSqlQuery query(db);
        if(query.exec("select * from usermsg.userquery"))
        {
            while(query.next())
        {
            int id = query.value(1).toInt();
            QString from = query.value(2).toString();
            QString to = query.value(3).toString();
            QString time = query.value(4).toString();
            int state = query.value(6).toInt();
            if(id==ID){
                p[i].id=n-i;
                p[i].from=from;
                p[i].to=to;
                p[i].time=time;
                p[i].state=state;
                i++;
                }
            }
        }
    }
    db.close();
    return p;
}
