#ifndef P5_H
#define P5_H

#include <QMainWindow>

namespace Ui {
class P5;
}

class P5 : public QMainWindow
{
    Q_OBJECT

public:
    explicit P5(QWidget *parent = 0);
    ~P5();
    double x[5];//array for x's rows
    double fx[5];//array for y's rows

private:
    Ui::P5 *ui;
public slots:
    void ejecutar();
    void borrar();
};

#endif // P5_H
