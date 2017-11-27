#ifndef P7_H
#define P7_H

#include <QMainWindow>

namespace Ui {
class P7;
}

class P7 : public QMainWindow
{
    Q_OBJECT

public:
    explicit P7(QWidget *parent = 0);
    ~P7();
    double X1_RM[6];//x1's column
    double X2_RM[6];//x2's column
    double Y_RM[6];//y's column
    double f[3][4];//matrix

private:
    Ui::P7 *ui;
public slots:
    void procesar_RM();//processing slot
    void borrar_RM();//claning slot
};

#endif // P7_H
