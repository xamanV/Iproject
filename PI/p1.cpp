#include "p1.h"
#include "ui_p1.h"
#include <QString>  //Librería para el uso de cadenas de texto
#include <cmath>    //Librería para el uso de funciones matemáticas

P1::P1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::P1)
{
    ui->setupUi(this);
    //inicio de las conexiones
QObject::connect(ui->METODO,SIGNAL(clicked()),this,SLOT(proceso()));//Botton conection whith method
QObject::connect(ui->RESET,SIGNAL(clicked()),this,SLOT(borrar()));//Botton coneecion whit RESET
QObject::connect(ui->SALIR,SIGNAL(clicked()),this,SLOT(close()));//Botton coneccion whith EXIT
}

P1::~P1()
{
    delete ui;
}
double P1::funcion(double c){
    return(exp(-c)); //función a evaluar
}
void P1::proceso(){
    QString tmp1,tmp2,tmp3,tmp4; //cadena para mostrar texto posteriormente
    double x1=ui->X1->value(); //recupera el valor del spinbox x1
    double error=ui->ERROR->value();//recupera el valor del spinbox ERROR
    double it=0;//iteración
    double ea=100;//valor de error
    double ni=0;//numero de iteraciones

    while(ea>error){
            it=funcion(x1);//eval de la funcion
            ea=100*std::abs(it-x1)/it;//calculo del error
            x1=it;// toma el valor anterior
            ni=ni+1;//agrago la iteracio
    }
 tmp1.append("La Raiz es= ").append(tmp2.setNum(it)).append("\nEl Error=").append(tmp3.setNum(ea)).append("\nNo. de Iteraciones=").append(tmp4.setNum(ni));  //Se prepara el texto para ser presentado
 ui->TEXTO->setText(tmp1);  //Se muestra en pantalla
}
void P1::borrar(){
    ui->X1->setValue(0.0);    //Se borran los spinbox
    ui->ERROR->setValue(0.0);
    ui->TEXTO->clear();      //Se borra el texto
}



