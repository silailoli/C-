#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QMouseEvent>

#include <defiction.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget , public DeFiction
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

    bool Check(QString Username,QString Password);

    bool Check(QString Username,QString Name,QString Telephone,QString Cardnumber);

    bool Check(QString Username,QString Password,QString Name,bool Man,bool woman,QString telephone,QString Cardnumber);

    bool Check(QString from,QString to,QString time);

    bool Check(QString to);

    bool PlaceCheck(QString from,QString to);

    bool eventFilter(QObject *obj, QEvent *event);

    void CleanRegister();

    void Tablemanage();

    void ListManage(int ID);

    void MsgTableManage();

    void Tablemanage_2(QString Time);

    ~Widget();

private slots:
    void on_Ptn_p1_r_clicked();

    void on_Ptn_p1_l_clicked();

    void on_Ptn_p2_b_clicked();

    void on_Ptn_p2_o_clicked();

    void on_L_p2_pp_editingFinished();

    void on_Ptn_p3_ca_clicked();

    void on_Ptn_p3_ap_clicked();

    void on_Ptn_p3_q_clicked();

    void on_Ptn_p3_ch_clicked();

    void on_Ptn_p3_b_clicked();

    void on_Ptn_p6_b_clicked();

    void on_Ptn_p8_b_clicked();

    void on_Ptn_p8_o_clicked();

    void on_Ptn_p5_b_clicked();

    void on_Ptn_p5_o_clicked();

    void on_Ptn_p4_b_clicked();

    void on_Ptn_p4_o_clicked();

    void on_Ptn_p7_o_clicked();

    void on_Ptn_p3_ms_clicked();

    void on_Ptn_p10_o_clicked();

    void on_Ptn_p11_b_clicked();

    void on_Ptn_p11_c_clicked();

    void on_Ptn_p11_d_clicked();

    void on_Ptn_p11_o_clicked();

    void on_L_p11_u_textEdited(const QString &arg1);

    void on_Ptn_p1_ti_clicked();

    void showtime();

    void on_Ptn_7_q_clicked();

    void on_Ptn_p7_ca_clicked();

    void on_Ptn_p11_q_clicked();

    void on_Ptn_p12_o_clicked();

    void on_Ptn_p7_fi_clicked();

    void on_Ptn_7_qt_clicked();

    void on_Ptn_p7_o_2_clicked();

    void on_Ptn_p13_b_clicked();

    void on_Ptn_p13_o_clicked();

    void on_Ptn_p14_b_clicked();

    void on_Ptn_p14_o_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
