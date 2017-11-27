#include "p7.h"
#include "ui_p7.h"
#include"math.h"

P7::P7(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::P7)
{
    ui->setupUi(this);
    connect(ui->PROCESAR_RM,SIGNAL(clicked()),this,SLOT(procesar_RM()));//execute button, click to execut the method
    connect(ui->BORRAR_RM,SIGNAL(clicked()),this,SLOT(borrar_RM()));//clean button, click to clean the spinboxes and display
    connect(ui->SALIR_RM,SIGNAL(clicked()),this,SLOT(close()));//exit button, click to close the program
}

P7::~P7()
{
    delete ui;
}
void P7::procesar_RM(){
    QString tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8,tmp9;//temporal strings
    //counters
    int j_RM=3;
    int i_RM=4;
    int k_RM=0;

    int n_RM=6;//number of points
    int c_RM=6;//maxium number of rows

    double X1_RM[c_RM];//X1's column
    double X2_RM[c_RM];//X2's column
    double Y_RM[c_RM];//Y's column
    //Values to calculate, so we need them to complete the formula and method
    double x1i_RM=0;
    double x2i_RM=0;
    double yi_RM=0;
    double x1ix2i_RM=0;
    double x1iyi_RM=0;
    double x2iyi_RM=0;
    double x1i2_RM=0;
    double x2i2_RM=0;
    double yi2_RM=0;
    double xp_RM=0;
    double yp_RM=0;
    double a1_RM=0;//value to complete the formula Y=a0+a1x1+a2x2
    double a0_RM=0;//value to complete the formula Y=a0+a1x1+a2x2
    double a2_RM=0;//value to complete the formula Y=a0+a1x1+a2x2
    double Sr_RM=0;
    double St_RM=0;
    double Sxy_RM=0;//standar estimated error
    double t1_RM=0;
    double t2_RM=0;
    double t3_RM=0;
    double r_RM=0;//coefficient correlation
    double f_RM[j_RM][i_RM];//matrix
    double val_RM;


        //X1's row values taken from the interface
    X1_RM[1]=ui->X1_11RM->value();
    X1_RM[2]=ui->X1_12RM->value();
    X1_RM[3]=ui->X1_13RM->value();
    X1_RM[4]=ui->X1_14RM->value();
    X1_RM[5]=ui->X1_15RM->value();
    X1_RM[6]=ui->X1_16RM->value();
    //X2's row values taken from the interface

    X2_RM[1]=ui->X2_21RM->value();
    X2_RM[2]=ui->X2_22RM->value();
    X2_RM[3]=ui->X2_23RM->value();
    X2_RM[4]=ui->X2_24RM->value();
    X2_RM[5]=ui->X2_25RM->value();
    X2_RM[6]=ui->X2_26RM->value();

    //y's values taken from the interface
    Y_RM[1]=ui->Y_31RM->value();
    Y_RM[2]=ui->Y_32RM->value();
    Y_RM[3]=ui->Y_33RM->value();
    Y_RM[4]=ui->Y_34RM->value();
    Y_RM[5]=ui->Y_35RM->value();
    Y_RM[6]=ui->Y_36RM->value();

   /* n_RM=0;
    for(j_RM=1;j_RM<=7;j_RM++){//gets the number of points from the interface
        if(((X1_RM[j_RM])!=(0)) && ((X2_RM[j_RM])!=(0)) && ((Y_RM[j_RM])!=(0))){
            n_RM++;
        }
    }*/
    if(n_RM>=3){//condition, we need at least 3 points
    for(j_RM=1;j_RM<=n_RM;j_RM++){//gets the nescesary values to continue with the method
        x1i_RM=x1i_RM+X1_RM[j_RM];
        x2i_RM=x2i_RM+X2_RM[j_RM];
        yi_RM=yi_RM+Y_RM[j_RM];
        x1ix2i_RM=x1ix2i_RM+((X1_RM[j_RM])*(X2_RM[j_RM]));
        x1iyi_RM=x1iyi_RM+((X1_RM[j_RM])*(Y_RM[j_RM]));
        x2iyi_RM=x2iyi_RM+((X2_RM[j_RM])*(Y_RM[j_RM]));
        x1i2_RM=x1i2_RM+((X1_RM[j_RM])*(X1_RM[j_RM]));
        x2i2_RM=x2i2_RM+((X2_RM[j_RM])*(X2_RM[j_RM]));
        //yi2_RM=yi2_RM+((Y_RM[j_RM])*(Y_RM[j_RM]));
    }
    }
    n_RM=6;
//declarate the matrix
    f_RM[0][0]=n_RM;
    f_RM[0][1]=x1i_RM;
    f_RM[0][2]=x2i_RM;
    f_RM[0][3]=yi_RM;
    f_RM[1][0]=x1i_RM;
    f_RM[1][1]=x1i2_RM;
    f_RM[1][2]=x1ix2i_RM;
    f_RM[1][3]=x1iyi_RM;
    f_RM[2][0]=x2i_RM;
    f_RM[2][1]=x1ix2i_RM;
    f_RM[2][2]=x2i2_RM;
    f_RM[2][3]=x2iyi_RM;

//solve the matrix
    for(i_RM=1;i_RM<3;i_RM++)
    {
        for (j_RM=i_RM;j_RM<3;j_RM++)
        {
            val_RM=(f_RM[j_RM][i_RM-1])/(f_RM[i_RM-1][i_RM-1]);
        for(k_RM=0;k_RM<4;k_RM++)
        {
             f_RM[j_RM][k_RM]=(f_RM[j_RM][k_RM]-((f_RM[i_RM-1][k_RM])*val_RM));
     }
    }
    val_RM=0;
      }

    //gets the necessary values from the matrix that was solved
  a2_RM=(f_RM[2][3]/f_RM[2][2]);
  a1_RM=(((f_RM[1][3])-(f_RM[1][2]*a2_RM))/(f_RM[1][1]));
  a0_RM=((f_RM[0][3])-(a2_RM*f_RM[0][2])-(a1_RM*f_RM[0][1]))/(f_RM[0][0]);

   yp_RM=yi_RM/n_RM;//necesary value
   for(j_RM=1;j_RM<=n_RM;j_RM++){//gets the Sr and St, necesary to calculate the standar estimated error
       Sr_RM=Sr_RM+((Y_RM[j_RM]-a0_RM-(a1_RM*X1_RM[j_RM])-(a2_RM*X2_RM[j_RM]))*(Y_RM[j_RM]-a0_RM-(a1_RM*X1_RM[j_RM])-(a2_RM*X2_RM[j_RM])));
       St_RM=St_RM+((Y_RM[j_RM]-yp_RM)*(Y_RM[j_RM]-yp_RM));
   }
   t1_RM=St_RM-Sr_RM;
   t2_RM=t1_RM/Sr_RM;
   r_RM=sqrt(t2_RM);//gets the coefficient correlation

    tmp1.append("Y=").append(tmp2.setNum(a0_RM)).append("+").append(tmp3.setNum(a1_RM)).append(" x1+").append(tmp4.setNum(a2_RM)).append(" x2").append("\nr=").append(tmp5.setNum(r_RM));//values that are going to be shown
    ui->TEXTO_RM->setText(tmp1);//show the values
    }
void P7::borrar_RM() //cleaning process
{
        //cleans all
        ui->X1_11RM->setValue(0.0);
        ui->X1_12RM->setValue(0.0);
        ui->X1_13RM->setValue(0.0);
        ui->X1_14RM->setValue(0.0);
        ui->X1_15RM->setValue(0.0);
        ui->X1_16RM->setValue(0.0);
        ui->X2_21RM->setValue(0.0);
        ui->X2_22RM->setValue(0.0);
        ui->X2_23RM->setValue(0.0);
        ui->X2_24RM->setValue(0.0);
        ui->X2_25RM->setValue(0.0);
        ui->X2_26RM->setValue(0.0);
        ui->Y_31RM->setValue(0.0);
        ui->Y_32RM->setValue(0.0);
        ui->Y_33RM->setValue(0.0);
        ui->Y_34RM->setValue(0.0);
        ui->Y_35RM->setValue(0.0);
        ui->Y_36RM->setValue(0.0);
        ui->TEXTO_RM->clear();
    }
