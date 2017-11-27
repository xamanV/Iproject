#include "pi.h"
#include "ui_pi.h"

PI::PI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PI)
{
    ui->setupUi(this);
    p1 = new P1();
    p2 = new P2();
    p3 = new P3();
    p4 = new P4();
    p5 = new P5();
    p6 = new P6();
    p7 = new P7();
    p8 = new P8();
    p9 = new P9();
    p10 = new P10();
    p11 = new P11();

    connect(ui->P1,SIGNAL(clicked()),this,SLOT(P1()));
    connect(ui->P2,SIGNAL(clicked()),this,SLOT(P2()));
    connect(ui->P3,SIGNAL(clicked()),this,SLOT(P3()));
    connect(ui->P4,SIGNAL(clicked()),this,SLOT(P4()));
    connect(ui->P5,SIGNAL(clicked()),this,SLOT(P5()));
    connect(ui->P6,SIGNAL(clicked()),this,SLOT(P6()));
    connect(ui->P7,SIGNAL(clicked()),this,SLOT(P7()));
    connect(ui->P8,SIGNAL(clicked()),this,SLOT(P8()));
    connect(ui->P9,SIGNAL(clicked()),this,SLOT(P9()));
    connect(ui->P10,SIGNAL(clicked()),this,SLOT(P10()));
    connect(ui->P11,SIGNAL(clicked()),this,SLOT(P11()));
    connect(ui->Sal,SIGNAL(clicked()),this,SLOT(SALIR()));
}

PI::~PI()
{
    delete ui;
}
void PI::P1(){
    p1->show();
}

void PI::P2(){
    p2->show();
}

void PI::P3(){
    p3->show();
}
void P1::P4(){
    p4->show();
}
void P1::P5(){
    p5->show();
}
void PI::P6(){
    p6->show();
}
void PI::P7(){
    p7->show();
}
void PI::P8(){
    p8->show();
}
void PI::P9(){
    p9->show();
}
void PI::P10(){
    p10->show();
}
void PI::P11(){
    p11->show();
}
void sistema::Salir(){
    delete P1;
    delete P2;
    delete P3;
    delete P4;
    delete P5;
    delete P6;
    delete P7;
    delete P8;
    delete P9;
    delete P10;
    delete P11;
    SALIR();
}
