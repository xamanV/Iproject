#ifndef P8_H
#define P8_H

#include <QMainWindow>

namespace Ui {
class P8;
}

class P8 : public QMainWindow
{
    Q_OBJECT

public:
    explicit P8(QWidget *parent = 0);
    ~P8();
    double funcion0(double x);//original function
    double funciond1(double x);//first derivate
    double funciond2(double x);//second derivate
    double funciond3(double x);//third derivate
    double funciond4(double x);//fourth derivate


private:
    Ui::P8 *ui;
    void procesar_d();//slot that will contain the function procesar
    void borrar_d();//slot that will contain the function borrar
};

#endif // P8_H
