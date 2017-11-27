#include "p6.h"
#include "ui_p6.h"

P6::P6(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::P6)
{
    ui->setupUi(this);
    connect(ui->EJECUTAR,SIGNAL(clicked()),this,SLOT(ejecutar()));//execute button, click to execut the method
    connect(ui->BORRAR,SIGNAL(clicked()),this,SLOT(borrar()));//clean button, click to clean the spinboxes and display
    connect(ui->SALIR,SIGNAL(clicked()),this,SLOT(close()));//exit button, click to close the program
}

P6::~P6()
{
    delete ui;
}
void P6::ejecutar(){
    QString tmp1,tmp2,tmp3,tmp4,tmp5,tmp6;//temporal strings
    //counter
    int j;
    int n=0;//number of points
    int c=7;//maxium number of rows

    double x[c];//X's column
    double y[c];//Y's column
    //Values to calculate, so we need them to complete the formula and method
    double xi=0;
    double yi=0;
    double xiyi=0;
    double x2i=0;
    double y2i=0;
    double xp=0;
    double yp=0;
    double a1=0;//value to complete the formula Y=a0+a1x
    double a0=0;//value to complete the formula Y=a0+a1x
    double Sr=0;
    double Sxy=0;//standar estimated error
    double t1=0;
    double t2=0;
    double t3=0;
    double r=0;//coefficient correlation

        //X's row values taken from the interface
    x[1]=ui->x1->value();
    x[2]=ui->x2->value();
    x[3]=ui->x3->value();
    x[4]=ui->x4->value();
    x[5]=ui->x5->value();
    x[6]=ui->x6->value();
    x[7]=ui->x7->value();
    //X's row values taken from the interface
    y[1]=ui->y1->value();
    y[2]=ui->y2->value();
    y[3]=ui->y3->value();
    y[4]=ui->y4->value();
    y[5]=ui->y5->value();
    y[6]=ui->y6->value();
    y[7]=ui->y7->value();

    n=0;
    for(j=1;j<=7;j++){//gets the number of points from the interface
        if((x[j])!=(0)){
            n++;
        }
    }
    if(n>=3){//condition, we need at least 3 points
    for(j=1;j<=n;j++){//gets the nescesary values to continue with the method
        xi=xi+x[j];
        yi=yi+y[j];
        xiyi=xiyi+((x[j])*(y[j]));
        x2i=x2i+((x[j])*(x[j]));
        y2i=y2i+((y[j])*(y[j]));
    }
    a1=((n*xiyi)-(xi*yi))/((n*x2i)-(xi*xi));//gets a1
    xp=xi/n;//values to calculate a0
    yp=yi/n;
    a0=yp-(a1*xp);//gets a0
    for(j=1;j<=n;j++){//gets the Sr, necesary to calculate the standar estimated error
        Sr=Sr+((yi-a0-(a1*x[j]))*(yi-a0-(a1*x[j])));
    }
    Sxy=sqrt(Sr/(n-2));//standar estimated error
    //calculates the necesary values to complete the coefficient correlation's formula
    t1=sqrt(((n*x2i)-(xi*xi)));
    t2=sqrt((n*y2i)-(yi*yi));
    t3=(n*xiyi)-(xi*yi);
    r=t3/(t2*t1);//gets the coefficient correlation
    tmp1.append("Y=").append(tmp2.setNum(a0)).append("+").append(tmp3.setNum(a1)).append("x").append("\nr=").append(tmp5.setNum(r));//text that will be shown
    ui->TEXTO->setText(tmp1);//shows
    }
}

void P6::borrar()//clean process
{
    //cleans all
    ui->x1->setValue(0.0);
    ui->x2->setValue(0.0);
    ui->x3->setValue(0.0);
    ui->x4->setValue(0.0);
    ui->x5->setValue(0.0);
    ui->x6->setValue(0.0);
    ui->x7->setValue(0.0);
    ui->y1->setValue(0.0);
    ui->y2->setValue(0.0);
    ui->y3->setValue(0.0);
    ui->y4->setValue(0.0);
    ui->y5->setValue(0.0);
    ui->y6->setValue(0.0);
    ui->y7->setValue(0.0);
    ui->TEXTO->clear();
}
