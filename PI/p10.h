#ifndef P10_H
#define P10_H

#include <QMainWindow>

namespace Ui {
class P10;
}

class P10 : public QMainWindow
{
    Q_OBJECT

public:
    explicit P10(QWidget *parent = 0);
    ~P10();
    //declaration of variables
    double P(double x);
    double Q(double y);
    double xinit,yinit,x;
private:
    Ui::P10 *ui;
public slots:
    void Procesar();
    void Reinicio();
};

#endif // P10_H
