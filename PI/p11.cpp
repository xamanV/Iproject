#include "p11.h"
#include "ui_p11.h"
#include "math.h"

P11::P11(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::P11)
{
    ui->setupUi(this);
    // Slots Connections
    connect(ui->Procesar,SIGNAL(clicked()),this,SLOT(Procesar()));
    connect(ui->Reinicio,SIGNAL(clicked()),this,SLOT(Reinicio()));
    connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));
}

P11::~P11()
{
    delete ui;
}
//Functions
double P11::P(double x){
    return (-2*(x*x*x))+(12*(x*x))-(20*x)+8.5;
}


double P11::Q(double y){
    return -(0.5*(y*y*y*y))+(4*(y*y*y))-(10*(y*y))+(8.5*y)+1;
}

//execution of the process

void P11::Procesar(){
    QString temp, temp1, temp2, temp3, temp4;
     xinit=ui->x->value();
    yinit=ui->y->value();
    double h=ui->H->value();
    int range=0;
    int i;
    xinit=0;
    double error=0, yp=0, Vreal=0;


    range=(yinit-x)/h;

    for(i=0;i<range;i++){

    Vreal=P(xinit)+(P(xinit)*h);

    xinit=(xinit+h);

    yp=Q(xinit);
//error calculation

    error=100*std::abs(Vreal-yp)/Vreal;

    temp.append("\n\ny(").append(temp1.setNum(xinit)).append(")=").append(temp2.setNum(Vreal)).append("\n\nValor Real:\n").append(temp3.setNum(yp)).append("\nEl Error es:\n").append(temp4.setNum(error)).append("%");
    Vreal=0;yp=0;error=0;
    }
//sample of results

    ui->resultados->setText(temp);
    }
//send the functions to zero to restart

void P11::Reinicio(){
    ui->x->setValue(0.0);
    ui->y->setValue(0.0);
    ui->H->setValue(0.0);
    ui->resultados->clear();
}
