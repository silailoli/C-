#include "widget.h"

#include "ui_widget.h"

#include <msgmanage.h>

#include<QIcon>

#include <QMessageBox>

#include<QTimer>

#include <QDateTime>

extern int ID;
//ui窗口设置
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(900,600);
    setWindowIcon(QIcon(":/res/resource/title.png"));
    setWindowTitle("DD打车系统");
    ui->L_p1_ti->hide();
    ui->L_p1_fg->installEventFilter(this);
    QTimer *timer_calendar;
    timer_calendar = new QTimer(this);
    connect(timer_calendar,SIGNAL(timeout()),this,SLOT(showtime()));
    timer_calendar->start(1000);
    ui->stackedWidget->setCurrentWidget(ui->page_1);
    ui->tableWidget_1->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

Widget::~Widget()
{
    delete ui;
}
//显示系统时间
void Widget::showtime()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("当前时间是：\nyyyy-MM-dd hh:mm:ss dddd");
    ui->L_p1_ti->setText(str);
}
//跳转注册页面
void Widget::on_Ptn_p1_r_clicked()
{
    ui->L_p1_u->clear();
    ui->L_p1_p->clear();
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}
//用户登录
void Widget::on_Ptn_p1_l_clicked()
{
    if(Check(ui->L_p1_u->text().trimmed(), ui->L_p1_p->text().trimmed())){
    MsgManage database;
    if(database.VerificationLogin(ui->L_p1_u->text().trimmed(), ui->L_p1_p->text().trimmed(),&ID))
    {
       ui->L_p1_u->clear();
       ui->L_p1_p->clear();
       ui->stackedWidget->setCurrentWidget(ui->page_3);
    }else
    {
        QMessageBox::warning(this,tr("警告！"),tr("用户名或者密码错误！"),QMessageBox::Yes);
        ui->L_p1_u->clear();
        ui->L_p1_p->clear();
        ui->L_p1_u->setFocus();
    }
    }
}
//事件过滤器使左键触发跳转找回密码界面
bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->L_p1_fg)
     {
         if (event->type() == QEvent::MouseButtonPress)
         {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->button() == Qt::LeftButton){
                ui->stackedWidget->setCurrentWidget(ui->page_13);
                return true;
             }
             else return false;
         }else return false;
    }else return QWidget::eventFilter(obj, event);
}
//检测登录输入
bool Widget::Check(QString Username,QString Password)
{
    if(Username=="") {QMessageBox::warning(this,tr("警告！"),tr("用户名不能为空！"),QMessageBox::Yes);ui->L_p2_u->setFocus();return false;}
    if(Password=="") {QMessageBox::warning(this,tr("警告！"),tr("密码不能为空！"),QMessageBox::Yes);ui->L_p2_p->setFocus();return false;}
    return true;
}
//返回登录页面
void Widget::on_Ptn_p2_b_clicked()
{
    CleanRegister();
    ui->stackedWidget->setCurrentWidget(ui->page_1);
}
//用户注册
void Widget::on_Ptn_p2_o_clicked()
{
    MsgManage database;
    if(database.VerificationRegister(ui->L_p2_u->text().trimmed(), ui->L_p2_p->text().trimmed(),ui->L_p2_n->text().trimmed(),ui->rPtn_p2_m->isChecked(),ui->rPtn_p2_wm->isChecked(),ui->L_p2_t->text().trimmed(),ui->L_p2_c->text().trimmed())){
        QMessageBox::warning(this,tr("警告！"),tr("注册成功！"),QMessageBox::Yes);
        CleanRegister();
        ui->stackedWidget->setCurrentWidget(ui->page_1);
    }
}
//清空注册页面
void Widget::CleanRegister()
{
    ui->L_p2_u->clear();
    ui->L_p2_p->clear();
    ui->L_p2_pp->clear();
    ui->L_p2_n->clear();
    ui->L_p2_t->clear();
    ui->L_p2_c->clear();
    ui->rPtn_p2_m->setChecked(false);
    ui->rPtn_p2_wm->setChecked(false);
}
//检测确认密码
void Widget::on_L_p2_pp_editingFinished()
{
    QString password,password_check;
    if((password=ui->L_p2_p->text())==(password_check=ui->L_p2_pp->text())){

    }else{
        QMessageBox::warning(this,tr("警告！"),tr("密码与确认密码不符！"),QMessageBox::Yes);
        ui->L_p2_p->clear();
        ui->L_p2_pp->clear();
        ui->L_p2_p->setFocus();
    }
}
//检测找回密码信息输入
bool Widget::Check(QString Username,QString Name,QString Telephone,QString Cardnumber)
{
    if(Username=="") {
        QMessageBox::warning(this,tr("警告！"),tr("用户名不能为空！"),QMessageBox::Yes);
        ui->L_p13_u->setFocus();
        return false;}
    if(Name=="") {QMessageBox::warning(this,tr("警告！"),tr("姓名不能为空！"),QMessageBox::Yes);
        ui->L_p13_n->setFocus();
        return false;}
    if(Telephone=="") {
        QMessageBox::warning(this,tr("警告！"),tr("电话号码不能为空！"),QMessageBox::Yes);
        ui->L_p13_t->setFocus();
        return false;}
    if(Telephone.length()!=11||Isdigital(Telephone)||Telephone.mid(0,1).toInt()!=1){
        QMessageBox::warning(this,tr("警告！"),tr("电话号码格式错误！"),QMessageBox::Yes);
        ui->L_p13_t->clear();
        ui->L_p13_t->setFocus();
        return false;}
    if(Cardnumber=="") {
        QMessageBox::warning(this,tr("警告！"),tr("身份证号不能为空！"),QMessageBox::Yes);
        ui->L_p13_c->setFocus();
        return false;}
    if(Cardnumber.length()!=18){
        QMessageBox::warning(this,tr("警告！"),tr("身份证号格式错误！"),QMessageBox::Yes);
        ui->L_p13_c->clear();
        ui->L_p13_c->setFocus();
        return false;}
    if(Cardnumber.toUpper().endsWith("X"))
        Cardnumber=Cardnumber.left(Cardnumber.size()-1);
    if(Isdigital(Cardnumber)){
        QMessageBox::warning(this,tr("警告！"),tr("身份证号格式错误！"),QMessageBox::Yes);
        ui->L_p13_c->clear();
        ui->L_p13_c->setFocus();
        return false;}
    if(((Cardnumber.mid(10,2).toInt()>12)||(Cardnumber.mid(10,2).toInt()==00))||((Cardnumber.mid(12,2).toInt()>31)||(Cardnumber.mid(12,2).toInt()==00))){
        QMessageBox::warning(this,tr("警告！"),tr("身份证号格式错误！"),QMessageBox::Yes);
        ui->L_p13_c->clear();
        ui->L_p13_c->setFocus();
        return false;}
    return true;
}
//检测注册信息输入
bool Widget::Check(QString Username,QString Password,QString Name,bool Man,bool woman,QString telephone,QString Cardnumber)
{
    MsgManage m;
    if(Username=="") {
        QMessageBox::warning(this,tr("警告！"),tr("用户名不能为空！"),QMessageBox::Yes);
        ui->L_p2_u->setFocus();
        return false;}
    if(Password=="") {
        QMessageBox::warning(this,tr("警告！"),tr("密码不能为空！"),QMessageBox::Yes);
        ui->L_p2_p->setFocus();
        return false;}
    if(Password.length()<6){
        QMessageBox::warning(this,tr("警告！"),tr("密码不得少于6位！"),QMessageBox::Yes);
        ui->L_p2_p->setFocus();
        return false;}
    if(Name=="") {
        QMessageBox::warning(this,tr("警告！"),tr("姓名不能为空！"),QMessageBox::Yes);
        ui->L_p2_n->setFocus();
        return false;}
    if(Ischinese(Name)||Name.length()>4||Name.length()<2){
        QMessageBox::warning(this,tr("警告！"),tr("姓名格式错误！"),QMessageBox::Yes);
        ui->L_p2_n->clear();
        ui->L_p2_n->setFocus();
        return false;}
    if(telephone=="") {
        QMessageBox::warning(this,tr("警告！"),tr("电话号码不能为空！"),QMessageBox::Yes);
        ui->L_p2_t->setFocus();
        return false;}
    if(telephone.length()!=11||Isdigital(telephone)||telephone.mid(0,1).toInt()!=1){
        QMessageBox::warning(this,tr("警告！"),tr("电话号码格式错误！"),QMessageBox::Yes);
        ui->L_p2_t->clear();
        ui->L_p2_t->setFocus();
        return false;}
    if(m.VerificationTelephone(telephone)){
        QMessageBox::warning(this,tr("警告！"),tr("电话号码已被注册！"),QMessageBox::Yes);
        ui->L_p2_t->clear();
        ui->L_p2_t->setFocus();
        return false;
    }
    if(Cardnumber=="") {
        QMessageBox::warning(this,tr("警告！"),tr("身份证号不能为空！"),QMessageBox::Yes);
        ui->L_p2_c->setFocus();
        return false;}
    if(Cardnumber.length()!=18){
        QMessageBox::warning(this,tr("警告！"),tr("身份证号格式错误！"),QMessageBox::Yes);
        ui->L_p2_c->clear();
        ui->L_p2_c->setFocus();
        return false;}
    if(Cardnumber.toUpper().endsWith("X"))
        Cardnumber=Cardnumber.left(Cardnumber.size()-1);
    if(Isdigital(Cardnumber)){
        QMessageBox::warning(this,tr("警告！"),tr("身份证号格式错误！"),QMessageBox::Yes);
        ui->L_p2_c->clear();
        ui->L_p2_c->setFocus();
        return false;}
    if(((Cardnumber.mid(10,2).toInt()>12)||(Cardnumber.mid(10,2).toInt()==00))||((Cardnumber.mid(12,2).toInt()>31)||(Cardnumber.mid(12,2).toInt()==00))){
        QMessageBox::warning(this,tr("警告！"),tr("身份证号格式错误！"),QMessageBox::Yes);
        ui->L_p2_c->clear();
        ui->L_p2_c->setFocus();
        return false;}
    if(m.VerificationCardnumber(Cardnumber)){
        QMessageBox::warning(this,tr("警告！"),tr("身份证号已被注册！"),QMessageBox::Yes);
        ui->L_p2_c->clear();
        ui->L_p2_c->setFocus();
        return false;
    }
    if(Man&&woman) {
        QMessageBox::warning(this,tr("警告！"),tr("请填写性别！"),QMessageBox::Yes);
        ui->rPtn_p2_m->setFocus();
        return false;}
    return true;
}
//跳转打车界面
void Widget::on_Ptn_p3_ca_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_4);
}
//跳转预约界面
void Widget::on_Ptn_p3_ap_clicked()
{
    QDateTimeEdit(QDateTime::currentDateTime(),ui->L_p5_ti);
    ui->L_p5_ti->setMaximumDate(QDate::currentDate().addDays(7));
    ui->L_p5_ti->setMinimumDateTime(QDateTime::currentDateTime());
    ui->stackedWidget->setCurrentWidget(ui->page_5);
}
//跳转订单查询界面
void Widget::on_Ptn_p3_q_clicked()
{
    MsgManage m;
    if(m.QueryAutoFinish(ID))m.QueryFinish(ID);
    if(m.QueryExist()){
    Tablemanage();
    ui->Ptn_7_qt->show();
    ui->Ptn_p7_ca->show();
    ui->Ptn_p7_fi->hide();
    ui->Ptn_p7_o_2->hide();
    ui->L_p7_1->show();
    ui->L_p7_2->hide();
    if(m.QueryTimeEnsure(ID)){
        ui->Ptn_p7_fi->show();
        ui->Ptn_p7_ca->hide();
    }
    ui->stackedWidget->setCurrentWidget(ui->page_7);
    }else{
    ui->stackedWidget->setCurrentWidget(ui->page_6);
    }
}
//订单表显示
void Widget::Tablemanage()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");//localhost
    db.setDatabaseName("usermsg");
    db.setUserName("root");
    db.setPassword("liuxiangyu");
    if(db.open())
    {
        QSqlQuery query(db);
        int ddid = 0;
        QString from="";
        QString to="";
        QString time="";
        if(query.exec("select * from usermsg.user"))
        {
            while(query.next())
        {
            int id = query.value(0).toInt();
            QString Username = query.value(1).toString().trimmed();
            QString telephone = query.value(6).toString().trimmed();
            if(ID==id){
                    ui->tableWidget_1->setItem(0,0,new QTableWidgetItem(Username));
                    ui->tableWidget_1->setItem(0,4,new QTableWidgetItem(telephone));
            }
        }
        }
        if(query.exec("select * from usermsg.userquery"))
        {
            while(query.next())
        {
            int id = query.value(1).toInt();
            QString fromm = query.value(2).toString().trimmed();
            QString tow = query.value(3).toString().trimmed();
            QString timee = query.value(4).toString().trimmed();
            int state = query.value(6).toInt();
            if(ID==id&&state==1){
                    ui->tableWidget_1->setItem(0,1,new QTableWidgetItem(fromm));
                    ui->tableWidget_1->setItem(0,2,new QTableWidgetItem(tow));
                    ui->tableWidget_1->setItem(0,3,new QTableWidgetItem(timee));
                    ddid = query.value(5).toInt();
                    from=fromm;
                    to=tow;
                    time=timee;
            }
        }
        }
        if(query.exec("select * from usermsg.driver"))
        {
            while(query.next())
        {
            int id = query.value(0).toInt();
            QString name = query.value(1).toString().trimmed();
            QString carnumber = query.value(2).toString().trimmed();
            QString telephone = query.value(3).toString().trimmed();
            if(ddid==id){
                    ui->tableWidget_1->setItem(0,5,new QTableWidgetItem(name));
                    ui->tableWidget_1->setItem(0,6,new QTableWidgetItem(carnumber));
                    ui->tableWidget_1->setItem(0,7,new QTableWidgetItem(telephone));
            }
        }
        }
        if(query.exec("select * from usermsg.place"))
        {
            while(query.next())
        {
            QString fromm = query.value(1).toString().trimmed();
            QString tow = query.value(2).toString().trimmed();
            int lengthh = query.value(3).toInt();
            if(fromm==from&&tow==to){
                QString length = QString("%1千米").arg(lengthh);
                int Hour=time.mid(6,2).toInt();
                int Minute=time.mid(8,2).toInt();
                double pricee=0;
                if(TimeCounter(Hour,Minute)){
                    pricee=DayPrice(lengthh);
                }else{
                    pricee=NightPrice(lengthh);
                }
                QString price = QString("%1元").arg(pricee);
                ui->tableWidget_1->setItem(0,8,new QTableWidgetItem(length));
                ui->tableWidget_1->setItem(0,9,new QTableWidgetItem(price));
            }
        }
        }
        db.close();
    }
}
//跳转设置界面
void Widget::on_Ptn_p3_ch_clicked()
{
    MsgManage u;
    QString Username=u.UserNameRead(ID);
    ui->L_p11_u->setText(Username);
    ui->Ptn_p11_o->setEnabled(false);
    ui->stackedWidget->setCurrentWidget(ui->page_11);
}
//返回登录界面
void Widget::on_Ptn_p3_b_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_1);
}
//返回目录界面
void Widget::on_Ptn_p6_b_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}
//返回目录界面
void Widget::on_Ptn_p8_b_clicked()
{
    ui->L_p8_op->clear();
    ui->L_p8_np->clear();
    ui->L_p8_npp->clear();
    ui->stackedWidget->setCurrentWidget(ui->page_11);
}
//用户修改密码
void Widget::on_Ptn_p8_o_clicked()
{
    if(ui->L_p8_np->text().trimmed()==ui->L_p8_npp->text().trimmed()){
    MsgManage database;
    if(database.VerificationOldpassword(ui->L_p8_op->text().trimmed(),ID))
    {
        if(ui->L_p8_np->text().trimmed().length()>=6){
        if(database.ChangePassword(ui->L_p8_np->text().trimmed(),ID)){
            QMessageBox::warning(this,tr("警告！"),tr("更改密码成功！"),QMessageBox::Yes);
            ui->L_p8_op->clear();
            ui->L_p8_np->clear();
            ui->L_p8_npp->clear();
            ui->stackedWidget->setCurrentWidget(ui->page_3);
        }
        }else {
            QMessageBox::warning(this,tr("警告！"),tr("新密码不得少于6位！"),QMessageBox::Yes);
            ui->L_p8_np->setFocus();
        }
    }else{
    QMessageBox::warning(this,tr("警告！"),tr("原密码错误！"),QMessageBox::Yes);
    ui->L_p8_op->clear();
    ui->L_p8_np->clear();
    ui->L_p8_npp->clear();
    ui->L_p8_op->setFocus();
    }
    }else{
        QMessageBox::warning(this,tr("警告！"),tr("密码与确认密码不符！"),QMessageBox::Yes);
        ui->L_p8_np->clear();
        ui->L_p8_npp->clear();
        ui->L_p8_np->setFocus();
    }
}
//返回目录界面
void Widget::on_Ptn_p5_b_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}

void Widget::on_Ptn_p5_o_clicked()
{
    MsgManage m;
    if(m.QueryExist()){
        QMessageBox::warning(this,tr("警告！"),tr("您已有预约订单！"),QMessageBox::Yes);
        ui->stackedWidget->setCurrentWidget(ui->page_3);
    }else{
    MsgManage database;
    if(database.VerificationQuery(ui->L_p5_f->currentText().trimmed(), ui->L_p5_to->currentText().trimmed(), ui->L_p5_ti->text())){
        QMessageBox::warning(this,tr("警告！"),tr("预约成功！请前往订单查询查询你的订单。"),QMessageBox::Yes);
        ui->stackedWidget->setCurrentWidget(ui->page_3);
}
    }
}
//检测预约信息输入
bool Widget::Check(QString from,QString to,QString time){
    if(from=="") {QMessageBox::warning(this,tr("警告！"),tr("起始地不能为空！"),QMessageBox::Yes);ui->L_p5_f->setFocus();return false;}
    if(to=="") {QMessageBox::warning(this,tr("警告！"),tr("目的地不能为空！"),QMessageBox::Yes);ui->L_p5_to->setFocus();return false;}
    if(time=="") {QMessageBox::warning(this,tr("警告！"),tr("预约时间不能为空！"),QMessageBox::Yes);ui->L_p5_ti->setFocus();return false;}
    return true;
}
//检测两地重复
bool Widget::PlaceCheck(QString from,QString to){
    if(from==to) {QMessageBox::warning(this,tr("警告！"),tr("起始地与目的地不能相同！"),QMessageBox::Yes);ui->L_p5_f->setFocus();return false;}
    return true;
}
//返回目录界面
void Widget::on_Ptn_p4_b_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}
//用户打车
void Widget::on_Ptn_p4_o_clicked()
{
    MsgManage m;
    if(m.QueryExist()){
        QMessageBox::warning(this,tr("警告！"),tr("您已有预约订单！"),QMessageBox::Yes);
        ui->stackedWidget->setCurrentWidget(ui->page_3);
    }else{
    MsgManage database;
    QDateTime time = QDateTime::currentDateTime();
    QString timer = time.toString("MM月dd日hh时mm分");
    if(database.VerificationCall(ui->L_p4_to->currentText().trimmed(),timer)){
    ui->stackedWidget->setCurrentWidget(ui->page_9);
    QTimer::singleShot(6000, this,[=](){
        QMessageBox::warning(this,tr("警告！"),tr("打车成功！请前往订单查询查询你的订单。"),QMessageBox::Yes);
        ui->stackedWidget->setCurrentWidget(ui->page_3);
    });
    }
    }
}
//检测打车信息输入
bool Widget::Check(QString to)
{
    if(to=="") {QMessageBox::warning(this,tr("警告！"),tr("目的地不能为空！"),QMessageBox::Yes);ui->L_p4_to->setFocus();return false;}
    return true;
}
//返回目录界面
void Widget::on_Ptn_p7_o_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}
//跳转用户信息界面
void Widget::on_Ptn_p3_ms_clicked()
{
    MsgTableManage();
    ui->stackedWidget->setCurrentWidget(ui->page_10);
}
//用户信息表显示
void Widget::MsgTableManage()
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
            QString Username = query.value(1).toString().trimmed();
            QString name = query.value(3).toString().trimmed();
            QString cardnumber = query.value(7).toString().trimmed();
            QString telephone = query.value(6).toString().trimmed();
            int agee = query.value(4).toInt();
            QString age =QString("%1岁").arg(agee);
            int sex = query.value(5).toInt();
            if(ID==id){
                    ui->tableWidget_2->setItem(0,0,new QTableWidgetItem(Username));
                    ui->tableWidget_2->setItem(0,1,new QTableWidgetItem(name));
                    ui->tableWidget_2->setItem(0,4,new QTableWidgetItem(telephone));
                    ui->tableWidget_2->setItem(0,5,new QTableWidgetItem(cardnumber));
                    ui->tableWidget_2->setItem(0,2,new QTableWidgetItem(age));
                    if(sex==1) ui->tableWidget_2->setItem(0,3,new QTableWidgetItem("男"));
                    if(sex==0) ui->tableWidget_2->setItem(0,3,new QTableWidgetItem("女"));
            }
        }
        }
    }
    db.close();
}
//返回目录界面
void Widget::on_Ptn_p10_o_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}
//返回目录界面
void Widget::on_Ptn_p11_b_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}
//跳转修改密码界面
void Widget::on_Ptn_p11_c_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_8);
}
//用户注销
void Widget::on_Ptn_p11_d_clicked()
{
    if(QMessageBox::Yes==QMessageBox::question(this,tr("提醒"),tr("您确认要注销账号吗？"),QMessageBox::Yes|QMessageBox::No)){
        MsgManage m;
        if(m.MsgDelete(ID)){
        QMessageBox::warning(this,tr("警告！"),tr("账号已注销"),QMessageBox::Yes);
        ui->stackedWidget->setCurrentWidget(ui->page_1);
        }
    }
}
//用户名更改
void Widget::on_Ptn_p11_o_clicked()
{
    MsgManage u;
    if(ui->L_p11_u->text()!=""){
        if(u.ChangeUserName(ui->L_p11_u->text().trimmed(),ID)){
        QMessageBox::warning(this,tr("警告！"),tr("用户名已更改！"),QMessageBox::Yes);
        QString Username=u.UserNameRead(ID);
        ui->L_p11_u->setText(Username);
        ui->Ptn_p11_o->setEnabled(false);
        }
    }else{
       QMessageBox::warning(this,tr("警告！"),tr("用户名不能为空！"),QMessageBox::Yes);
       QString Username=u.UserNameRead(ID);
       ui->L_p11_u->setText(Username);
       ui->Ptn_p11_o->setEnabled(false);
    }
}
//用户名栏编辑感应
void Widget::on_L_p11_u_textEdited(const QString &arg1)
{
    MsgManage u;
    QString Username=u.UserNameRead(ID);
    if(Username!=arg1) ui->Ptn_p11_o->setEnabled(true);
}
//时间显示隐藏控制
void Widget::on_Ptn_p1_ti_clicked()
{
    static int coin =0;
    coin++;
    if(coin==1){
        ui->L_p1_ti->show();
    };
    if(coin==2){
        coin=0;
        ui->L_p1_ti->hide();
    };
}
//提示显示
void Widget::on_Ptn_7_q_clicked()
{
    QMessageBox::warning(this,tr("提示"),tr("起步价：白天起步2公里内8元，夜间（22:00—次日5:30）2公里内10元。\n车公里价：白天2公里以上续程单价每公里2元，夜间（22:00—次日5:30）2公里以上续程单价每公里2.4元。"),QMessageBox::Yes);
}
//用户取消预约
void Widget::on_Ptn_p7_ca_clicked()
{
    if(QMessageBox::Yes==QMessageBox::question(this,tr("提醒"),tr("您确认要取消预约吗？（请与司机协商后取消预约，如遇司机投诉，本平台概不负责）"),QMessageBox::Yes|QMessageBox::No)){
        MsgManage m;
        if(m.QueryDelete(ID)){
        QMessageBox::warning(this,tr("警告！"),tr("订单已取消"),QMessageBox::Yes);
        ui->stackedWidget->setCurrentWidget(ui->page_3);
        }
    }
}
//跳转预约记录页面
void Widget::on_Ptn_p11_q_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_12);
    MsgManage m;
    if(m.QueryAutoFinish(ID))m.QueryFinish(ID);
    ListManage(ID);
}
//预约记录表显示
void Widget::ListManage(int ID)
{
    MsgManage l;
    QueryMsg* p=l.Msgfill(ID);
    int n=l.NumberCheck(ID);
    QString state="";
    QString from="";
    QString to="";
    QListWidgetItem *aItem;
    QWidget *aWidget;
    QPushButton *Ptn_list;
    QHBoxLayout *layout;
    ui->listWidget->addItem(QString("序号\t起始地\t\t目的地\t\t预约时间\t\t预约状态"));
    for(int i=n-1;i>=0;i--){
    if(p[i].state==1) state ="正在进行";
    if(p[i].state==0) state ="已完成";
    if(p[i].state==-1) state ="已取消";
    if(p[i].from.length()<4)from=p[i].from + "\t";else from=p[i].from;
    if(p[i].to.length()<4)to=p[i].to + "\t";else to=p[i].to;
    QString str = QString("%1\t%2\t%3\t%4\t%5").arg(p[i].id).arg(from).arg(to).arg(p[i].time).arg(state);
    aItem = new QListWidgetItem();
    aItem->setSizeHint(QSize(20, 45));
    Ptn_list = new QPushButton();
    Ptn_list->setText("查看详情");
    Ptn_list->setStyleSheet("QPushButton {background-color: rgb(170, 255, 255);color: rgb(255, 0, 127);} QPushButton:hover {background-color: rgb(151, 227, 227);color: rgb(255, 255, 255);}");
    layout = new QHBoxLayout;
    aWidget=new QWidget();
    layout->addStretch();
    layout->addWidget(Ptn_list);
    aWidget->setLayout(layout);
    Ptn_list->resize(20,40);
    connect(Ptn_list,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentWidget(ui->page_7);
        ui->Ptn_p7_fi->hide();
        ui->Ptn_p7_ca->hide();
        ui->Ptn_7_qt->hide();
        ui->Ptn_p7_o_2->show();
        ui->L_p7_1->hide();
        ui->L_p7_2->show();
        Tablemanage_2(p[i].time);
    });
    aItem->setText(str);
    ui->listWidget->addItem(aItem);
    ui->listWidget->setItemWidget(aItem,aWidget);
    }
}
//订单详情表显示
void Widget::Tablemanage_2(QString Time)
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
        int ddid = 0;
        QString from="";
        QString to="";
        QString time="";
        if(query.exec("select * from usermsg.user"))
        {
            while(query.next())
        {
            int id = query.value(0).toInt();
            QString Username = query.value(1).toString().trimmed();
            QString telephone = query.value(6).toString().trimmed();
            if(ID==id){
                    ui->tableWidget_1->setItem(0,0,new QTableWidgetItem(Username));
                    ui->tableWidget_1->setItem(0,4,new QTableWidgetItem(telephone));
            }
        }
        }
        if(query.exec("select * from usermsg.userquery"))
        {
            while(query.next())
        {
            int id = query.value(1).toInt();
            QString fromm = query.value(2).toString().trimmed();
            QString tow = query.value(3).toString().trimmed();
            QString timee = query.value(4).toString().trimmed();
            if(ID==id&&timee==Time){
                    ui->tableWidget_1->setItem(0,1,new QTableWidgetItem(fromm));
                    ui->tableWidget_1->setItem(0,2,new QTableWidgetItem(tow));
                    ui->tableWidget_1->setItem(0,3,new QTableWidgetItem(timee));
                    ddid = query.value(5).toInt();
                    from=fromm;
                    to=tow;
                    time=timee;
            }
        }
        }
        if(query.exec("select * from usermsg.driver"))
        {
            while(query.next())
        {
            int id = query.value(0).toInt();
            QString name = query.value(1).toString().trimmed();
            QString carnumber = query.value(2).toString().trimmed();
            QString telephone = query.value(3).toString().trimmed();
            if(ddid==id){
                    ui->tableWidget_1->setItem(0,5,new QTableWidgetItem(name));
                    ui->tableWidget_1->setItem(0,6,new QTableWidgetItem(carnumber));
                    ui->tableWidget_1->setItem(0,7,new QTableWidgetItem(telephone));
            }
        }
        }
        if(query.exec("select * from usermsg.place"))
        {
            while(query.next())
        {
            QString fromm = query.value(1).toString().trimmed();
            QString tow = query.value(2).toString().trimmed();
            int lengthh = query.value(3).toInt();
            if(fromm==from&&tow==to){
                QString length = QString("%1千米").arg(lengthh);
                int Hour=time.mid(6,2).toInt();
                int Minute=time.mid(8,2).toInt();
                double pricee=0;
                if(TimeCounter(Hour,Minute)){
                    pricee=DayPrice(lengthh);
                }else{
                    pricee=NightPrice(lengthh);
                }
                QString price = QString("%1元").arg(pricee);
                ui->tableWidget_1->setItem(0,8,new QTableWidgetItem(length));
                ui->tableWidget_1->setItem(0,9,new QTableWidgetItem(price));
            }
        }
        }
        db.close();
    }
}
//返回设置界面
void Widget::on_Ptn_p12_o_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_11);
    ui->listWidget->clear();
}
//用户完成订单
void Widget::on_Ptn_p7_fi_clicked()
{
    if(QMessageBox::Yes==QMessageBox::question(this,tr("提醒"),tr("您确认订单已完成吗？"),QMessageBox::Yes|QMessageBox::No)){
        MsgManage m;
        if(m.QueryFinish(ID)){
        QMessageBox::warning(this,tr("警告！"),tr("订单已完成，欢迎再次使用DD打车！"),QMessageBox::Yes);
        ui->stackedWidget->setCurrentWidget(ui->page_3);
        }
    }
}
//提示显示
void Widget::on_Ptn_7_qt_clicked()
{
    QMessageBox::warning(this,tr("提示"),tr("订单开始10分钟后可完成订单，订单完成后若未点击完成订单，一天后订单将自动完成。"),QMessageBox::Yes);
}
//返回预约记录界面
void Widget::on_Ptn_p7_o_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_12);
}
//返回登录界面
void Widget::on_Ptn_p13_b_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_1);
}
//用户找回密码
void Widget::on_Ptn_p13_o_clicked()
{
    if(Check(ui->L_p13_u->text().trimmed(), ui->L_p13_n->text().trimmed(), ui->L_p13_t->text().trimmed(), ui->L_p13_c->text().trimmed())){
    MsgManage database;
    if(database.VerificationSeekpassword(ui->L_p13_u->text().trimmed(), ui->L_p13_n->text().trimmed(), ui->L_p13_t->text().trimmed(), ui->L_p13_c->text().trimmed(),&ID))
    {
       ui->L_p13_u->clear();
       ui->L_p13_n->clear();
       ui->L_p13_t->clear();
       ui->L_p13_c->clear();
       ui->stackedWidget->setCurrentWidget(ui->page_14);
    }else
    {
        QMessageBox::warning(this,tr("警告！"),tr("验证失败！"),QMessageBox::Yes);
        ui->L_p13_u->clear();
        ui->L_p13_n->clear();
        ui->L_p13_t->clear();
        ui->L_p13_c->clear();
    }
    }
}
//返回登录界面
void Widget::on_Ptn_p14_b_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_1);
}
//用户设置新密码
void Widget::on_Ptn_p14_o_clicked()
{
    if(ui->L_p14_np->text().trimmed()==ui->L_p14_npp->text().trimmed()){
    MsgManage database;
        if(ui->L_p14_np->text().trimmed().length()>=6){
        if(database.ChangePassword(ui->L_p14_np->text().trimmed(),ID)){
            QMessageBox::warning(this,tr("警告！"),tr("找回密码成功！"),QMessageBox::Yes);
            ui->L_p14_np->clear();
            ui->L_p14_npp->clear();
            ui->stackedWidget->setCurrentWidget(ui->page_1);
        }
        }else {
            QMessageBox::warning(this,tr("警告！"),tr("新密码不得少于6位！"),QMessageBox::Yes);
            ui->L_p14_np->setFocus();
        }
    }else{
        QMessageBox::warning(this,tr("警告！"),tr("密码与确认密码不符！"),QMessageBox::Yes);
        ui->L_p14_np->clear();
        ui->L_p14_npp->clear();
        ui->L_p14_np->setFocus();
    }
}
