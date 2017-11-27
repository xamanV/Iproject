#ifndef P11_H
#define P11_H

#include <QMainWindow>

namespace Ui {
class P11;
}

class P11 : public QMainWindow
{
    Q_OBJECT

public:
    explicit P11(QWidget *parent = 0);
    ~P11();
    double P(double x);
    double Q(double y);
    double xinit,yinit,x,h,f1,f2;

private:
    Ui::P11 *ui;
public slots:
    void Procesar();
    void Reinicio();

};

#endif // P11_H
