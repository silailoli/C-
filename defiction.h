#ifndef DEFICTION_H
#define DEFICTION_H

#include <QString>

class DeFiction
{
public:
    DeFiction();

    int get_random_number();

    double DayPrice(int length);

    double NightPrice(int length);

    bool TimeCounter(int Hour,int Minute);

    bool Isdigital(QString str);

    bool Ischinese(QString str);
};

#endif // DEFICTION_H
