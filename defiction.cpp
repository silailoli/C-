#include "defiction.h"

#include <QTime>

DeFiction::DeFiction()
{

}

//随机数获取
int DeFiction::get_random_number()
{
   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
   int r = qrand()%20;
   return r+1;
}
//检测时间早晚
bool DeFiction::TimeCounter(int Hour,int Minute)
{
    if(Hour>=22||Hour<=4)return false;
    if(Hour==5&&Minute<=30)return false;
    return true;
}
//计算白天打车价格
double DeFiction::DayPrice(int length)
{
    double p=0;
    if(length<=2){
        p=8;
    }else{
        p=8+2*(length-2);
    }
    return p;
}
//计算晚上打车价格
double DeFiction::NightPrice(int length)
{
    double p=0;
    if(length<=2){
        p=10;
    }else{
        p=10+2.4*(length-2);
    }
    return p;
}
//检测是否为纯中文
bool DeFiction::Ischinese(QString str)
{
    int nCount = str.count();
    int n=0;
    for(int i = 0 ; i < nCount ; i++)
    {
        QChar cha = str.at(i);
        ushort uni = cha.unicode();
        if(uni >= 0x4E00 && uni <= 0x9FA5) n++;
    }
    if(n==nCount)return false;
    return true;
}
//检测是否为纯数字
bool DeFiction::Isdigital(QString str)
{
    bool isDigital=QString(str).contains(QRegExp("^\\d+$"));
    if(isDigital)return false;
    return true;
}
