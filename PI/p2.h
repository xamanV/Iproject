#ifndef P2_H
#define P2_H

#include <QMainWindow>

namespace Ui {
class P2;
}

class P2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit P2(QWidget *parent = 0);
    ~P2();
    double funcion0(double c);//function without deriving
    double funciond1(double c);//first derivative
    double funciond2(double c);//second derivative


private:
    Ui::P2 *ui;
public slots:

    void procesar();//process function
    void borrar();//erase function

};

#endif // P2_H
