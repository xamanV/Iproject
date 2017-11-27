#include "p4.h"
#include "ui_p4.h"

P4::P4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::P4)
{
    ui->setupUi(this);
    connect(ui->EJECUTAR,SIGNAL(clicked()),this,SLOT(ejecutar()));//execute button, click to execut the method
        connect(ui->BORRAR,SIGNAL(clicked()),this,SLOT(borrar()));//clean button, click to clean the spinboxes and display
        connect(ui->SALIR,SIGNAL(clicked()),this,SLOT(close()));//exit button, click to close the program
}

P4::~P4()
{
    delete ui;
}
void P4::ejecutar(){//sart
QString tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8,tmp9,tmp10;//temporal strings
//declare arrays

int i=0;//counter
//results
double x1=0.0;
double x2=0.0;
double x3=0.0;
double x4=0.0;
//values using to calculate the error, these are the last value part in the ec.
double x1a=0.0;
double x2a=0.0;
double x3a=0.0;
double x4a=0.0;


//get the spinboxe' values,  row 1
double fila11=ui->m11->value();
double fila12=ui->m12->value();
double fila13=ui->m13->value();
double fila14=ui->m14->value();
double A=ui->A->value();

//get the spinboxe' values,  row 2
double fila21=ui->m21->value();
double fila22=ui->m22->value();
double fila23=ui->m23->value();
double fila24=ui->m24->value();
double B=ui->B->value();
//get the spinboxe' values,  row 3
double fila31=ui->m31->value();
double fila32=ui->m32->value();
double fila33=ui->m33->value();
double fila34=ui->m34->value();
double C=ui->C->value();
//get the spinboxe' values,  row 4
double fila41=ui->m41->value();
double fila42=ui->m42->value();
double fila43=ui->m43->value();
double fila44=ui->m44->value();
double D=ui->D->value();

double err=ui->ERROR->value();//error value
//error
double err1=0;
double err2=0;
double err3=0;
double err4=0;
int ni=ui->ITE->value();//iterations value
double ea=100.0;

while((ea>err) && (i<ni)){

    x1=((A-(fila12*x2)-(fila13*x3)-(fila14*x4))/fila11);//uses the formula
    err1=100*std::abs(x1-x1a)/(x1);//calculates the error 1
    x1a=x1;//x1a gets the x1 value, then when we use the error furmula, we have the last value saved

    x2=((B-(fila21*x1)-(fila23*x3)-(fila24*x4))/fila22);//uses the second formula
    err2=100*std::abs(x2-x2a)/(x2);//calculates the new error 2
    x2a=x2;//saved the last value

    x3=((C-(fila31*x1)-(fila32*x2)-(fila34*x4))/fila33);
    err3=100*std::abs(x3-x3a)/(x3);//error 3
    x3a=x3;

    x4=((D-(fila41*x1)-(fila42*x2)-(fila43*x3))/fila44);
    err4=100*std::abs(x4-x4a)/(x4);//fourth error
    x4a=x4;
    i++;
}
tmp1.append(" X1=").append(tmp2.setNum(x1)).append("\n X2=").append(tmp3.setNum(x2)).append("\n X3=").append(tmp4.setNum(x3)).append("\n X4=").append(tmp5.setNum(x4)).append("\n Error1=").append(tmp6.setNum(err1)).append("\n Error2=").append(tmp7.setNum(err2)).append("\n Error3=").append(tmp8.setNum(err3)).append("\n Error4=").append(tmp9.setNum(err4)).append("\n No. Iteraciones=").append(tmp10.setNum(i));//Text
ui->TEXTO->setText(tmp1);//shows the text

}
void P4::borrar(){
    //cleans all
    ui->m11->setValue(0.0);
    ui->m12->setValue(0.0);
    ui->m13->setValue(0.0);
    ui->m14->setValue(0.0);
    ui->m21->setValue(0.0);
    ui->m22->setValue(0.0);
    ui->m23->setValue(0.0);
    ui->m24->setValue(0.0);
    ui->m31->setValue(0.0);
    ui->m32->setValue(0.0);
    ui->m33->setValue(0.0);
    ui->m34->setValue(0.0);
    ui->m41->setValue(0.0);
    ui->m42->setValue(0.0);
    ui->m43->setValue(0.0);
    ui->m44->setValue(0.0);
    ui->A->setValue(0.0);
    ui->B->setValue(0.0);
    ui->C->setValue(0.0);
    ui->D->setValue(0.0);
    ui->ERROR->setValue(0.0);
    ui->ITE->setValue(0);
    ui->TEXTO->clear();
}
