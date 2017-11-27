#ifndef PI_H
#define PI_H

#include <QMainWindow>
#include "P1.h"
#include "P2.h"
#include "P3.h"
#include "P4.h"
#include "P5.h"
#include "P6.h"
#include "P7.h"
#include "P8.h"
#include "P9.h"
#include "P10.h"
#include "P11.h"

namespace Ui {
class PI;
}

class PI : public QMainWindow
{
    Q_OBJECT

public:
    explicit PI(QWidget *parent = 0);
    ~PI();
    P1*p1;
    P2*p2;
    P3*p3;
    P4*p4;
    P5*p5;
    P6*p6;
    P7*p7;
    P8*p8;
    P9*p9;
    P10*p10;
    P11*p11;


private:
    Ui::PI *ui;
public slots:
    void P1();
    void P2();
    void P3();
    void P4();
    void P5();
    void P6();
    void P7();
    void P8();
    void P9();
    void P10();
    void P11();
    void Sal();
};

#endif // PI_H
