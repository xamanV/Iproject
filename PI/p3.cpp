#include "p3.h"
#include "ui_p3.h"

P3::P3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::P3)
{
    ui->setupUi(this);
    connect(ui->EJECUTAR,SIGNAL(clicked()),this,SLOT(ejecutar()));//execute button, click to execut the method
    connect(ui->BORRAR,SIGNAL(clicked()),this,SLOT(borrar()));//clean button, click to clean the spinboxes and display
    connect(ui->SALIR,SIGNAL(clicked()),this,SLOT(close()));//exit button, click to close the program
}

P3::~P3()
{
    delete ui;
}
void P3::ejecutar(){//start
    QString tmp1,tmp2,tmp3,tmp4,tmp5;//temporal strings

    //results, they will take their values at the end
    double x1=0.0;
    double x2=0.0;
    double x3=0.0;
    double x4=0.0;


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

//obtains the 0's in the first column, except value 1,1
    //for row 2
    fila21=(fila21)-((fila11)/(fila11))*(fila21);
    fila22=(fila22)-((fila12)/(fila11))*(fila21);
    fila23=(fila23)-((fila13)/(fila11))*(fila21);
    fila24=(fila24)-((fila14)/(fila11))*(fila21);
    B=(B)-((A)/(fila11))*(fila21);
// for row 3
    fila31=(fila31)-((fila11)/(fila11))*(fila31);
    fila32=(fila32)-((fila12)/(fila11))*(fila31);
    fila33=(fila33)-((fila13)/(fila11))*(fila31);
    fila34=(fila34)-((fila14)/(fila11))*(fila31);
    C=(C)-((A)/(fila11))*(fila31);
//for row 4
    fila41=(fila41)-((fila11)/(fila11))*(fila41);
    fila42=(fila42)-((fila12)/(fila11))*(fila41);
    fila43=(fila43)-((fila13)/(fila11))*(fila41);
    fila44=(fila44)-((fila14)/(fila11))*(fila41);
    D=(D)-((A)/(fila11))*(fila41);

//obtains the 0's in the second column, except values 2,1 and 2,2
    //for row 3
    fila32=(fila32)-((fila22)/(fila22))*(fila32);
    fila33=(fila33)-((fila23)/(fila22))*(fila32);
    fila34=(fila34)-((fila24)/(fila22))*(fila32);
    C=(C)-((B)/(fila22))*(fila32);
    //for row 4
    fila42=(fila42)-((fila22)/(fila22))*(fila42);
    fila43=(fila43)-((fila23)/(fila22))*(fila42);
    fila44=(fila44)-((fila24)/(fila22))*(fila42);
    D=(D)-((B)/(fila11))*(fila42);
//obtains the 0's in the third column, except values 3,1 3,2 and 3,3
    //for row 4 only
    fila43=(fila43)-((fila33)/(fila33))*(fila43);
    fila44=(fila44)-((fila34)/(fila33))*(fila43);
    D=(D)-((C)/(fila33))*(fila43);
//gets the x1..x4 values
    x4=(D)/(fila44);
    x3=((C)-((fila34)*(x4)))/(fila33);
    x2=((B)-((fila24)*(x4))-((fila23)*(x3)))/(fila22);
    x1=((A)-((fila14)*(x4))-((fila13)*(x3))-((fila12)*(x2)))/(fila11);

    tmp1.append(" X1=").append(tmp2.setNum(x1)).append("\n X2=").append(tmp3.setNum(x2)).append("\n X3=").append(tmp4.setNum(x3)).append("\n X4=").append(tmp5.setNum(x4));//the text that will be shown
    ui->TEXTO->setText(tmp1);//shows

}


void P3::borrar(){//the cleans instruction
    //set 0's in the matrix
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
    ui->TEXTO->clear();      //cleans display
}
