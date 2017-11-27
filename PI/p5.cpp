#include "p5.h"
#include "ui_p5.h"

P5::P5(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::P5)
{
    ui->setupUi(this);connect(ui->EJECUTAR,SIGNAL(clicked()),this,SLOT(ejecutar()));//execute button, click to execut the method
    connect(ui->RESET,SIGNAL(clicked()),this,SLOT(borrar()));//clean button, click to clean the spinboxes and display
    connect(ui->SALIR,SIGNAL(clicked()),this,SLOT(close()));//exit button, click to close the program
}

P5::~P5()
{
    delete ui;
}
void P5::ejecutar(){//execute proces
    QString tmp1,tmp2,tmp3,tmp4,tmp5;
    //counters
    int i;
    int j;
    int n;
    int s=4;//max grade value
    double X=ui->X->value();//get X's value
    double tmult;//saves the total value
    double tsum;//saves the sum value
    double grado[s];//array for grade's values

    //gets the X's values
    x[0]=ui->x1->value();
    x[1]=ui->x2->value();
    x[2]=ui->x3->value();
    x[3]=ui->x4->value();

    //gets the Y's values
    fx[0]=ui->fx1->value();
    fx[1]=ui->fx2->value();
    fx[2]=ui->fx3->value();
    fx[3]=ui->fx4->value();


    for(n=1;n<=s;n++){//starts for the values of the grade results, in this case is 4
        tsum=0;//resets sums, 0 because we dont have to modify the sum
        for(i=0;i<n+1;i++){//cycle for the sums part
            tmult=1;//rests mult, 1 because we dont have to modify the multiplication
            for(j=0;j<n+1;j++){//cycle for the multiplication part
                if(i!=j){//condition, only if i and j are different
                 tmult=tmult*((X-x[j])/(x[i]-x[j]));//start the formula, multiply with the last one and saves
                }
            }
            tmult=tmult*fx[i];//continous the formula
            tsum=tsum+tmult;//addes the value with the last one and saves
        }
        grado[n]=tsum;//saves the value in their grade
    }

   tmp1.append("Grado 1=").append(tmp2.setNum(grado[1])).append("\nGrado 2=").append(tmp3.setNum(grado[2])).append("\nGrado 3=").append(tmp4.setNum(grado[3])).append("\nGrado 4=").append(tmp5.setNum(grado[4]));
   ui->TEXTO->setText(tmp1);//show the result

        }
   void P5::borrar()//clean process
   {
       //cleans all
       ui->x1->setValue(0.0);
       ui->x2->setValue(0.0);
       ui->x3->setValue(0.0);
       ui->x4->setValue(0.0);
       ui->x5->setValue(0.0);
       ui->fx1->setValue(0.0);
       ui->fx2->setValue(0.0);
       ui->fx3->setValue(0.0);
       ui->fx4->setValue(0.0);
       ui->fx5->setValue(0.0);
       ui->X->setValue(0.0);
       ui->TEXTO->clear();
   }

