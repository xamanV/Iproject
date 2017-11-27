#include "p9.h"
#include "ui_p9.h"

P9::P9(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::P9)
{
    ui->setupUi(this);
    connect(ui->EJECUTAR_I,SIGNAL(clicked()),this,SLOT(procesar_i()));//execute button, click to execut the method
    connect(ui->BORRAR_I,SIGNAL(clicked()),this,SLOT(borrar_i()));//clean button, click to clean the spinboxes and display
    connect(ui->SALIR_I,SIGNAL(clicked()),this,SLOT(close()));//exit button, click to close the program
}

P9::~P9()
{
    delete ui;
}
void P9::procesar_i(){
    QString tmp1,tmp2;
    //gets the x's columns
    double x1_I=ui->X1_I->value();
    double x2_I=ui->X2_I->value();
    double x3_I=ui->X3_I->value();
    double x4_I=ui->X4_I->value();
    double x5_I=ui->X5_I->value();
    double x6_I=ui->X6_I->value();
    double x7_I=ui->X7_I->value();
    double x8_I=ui->X8_I->value();
    double x9_I=ui->X9_I->value();
    //gets fx's columns
    double fx1_I=ui->FX1_I->value();
    double fx2_I=ui->FX2_I->value();
    double fx3_I=ui->FX3_I->value();
    double fx4_I=ui->FX4_I->value();
    double fx5_I=ui->FX5_I->value();
    double fx6_I=ui->FX6_I->value();
    double fx7_I=ui->FX7_I->value();
    double fx8_I=ui->FX8_I->value();
    double fx9_I=ui->FX9_I->value();
    //gets h's value
    double h_I=ui->H_I->value();

    double integral=0.0;//integration value

    integral=(h_I/2)*(fx1_I+(2*fx2_I)+(2*fx3_I)+(2*fx4_I)+(2*fx5_I)+(2*fx6_I)+(2*fx7_I)+(2*fx8_I)+fx9_I);//calculates the integration valu
    tmp1.append("El resultado de la integral es \n").append(tmp2.setNum(integral));//text that will be shown
    ui->TEXTO_I->setText(tmp1);//shows the text

}
void P9::borrar_i(){//cleans all
    ui->X1_I->setValue(0.0);
    ui->X2_I->setValue(0.0);
    ui->X3_I->setValue(0.0);
    ui->X4_I->setValue(0.0);
    ui->X5_I->setValue(0.0);
    ui->X6_I->setValue(0.0);
    ui->X7_I->setValue(0.0);
    ui->X8_I->setValue(0.0);
    ui->X9_I->setValue(0.0);
    ui->FX1_I->setValue(0.0);
    ui->FX2_I->setValue(0.0);
    ui->FX3_I->setValue(0.0);
    ui->FX4_I->setValue(0.0);
    ui->FX5_I->setValue(0.0);
    ui->FX6_I->setValue(0.0);
    ui->FX7_I->setValue(0.0);
    ui->FX8_I->setValue(0.0);
    ui->FX9_I->setValue(0.0);
    ui->H_I->setValue(0.0);
    ui->TEXTO_I->clear();
}
