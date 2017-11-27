#ifndef P6_H
#define P6_H

#include <QMainWindow>

namespace Ui {
class P6;
}

class P6 : public QMainWindow
{
    Q_OBJECT

public:
    explicit P6(QWidget *parent = 0);
    ~P6();
    double x[7];//X's column
    double y[7];//Y's column

private:
    Ui::P6 *ui;
public slots:
 void ejecutar();//declarates execute slot
 void borrar();//declaraes clean slot
};

#endif // P6_H
