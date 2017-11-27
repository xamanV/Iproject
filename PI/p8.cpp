#include "p8.h"
#include "ui_p8.h"
#include"math.h"
#include <cmath>


P8::P8(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::P8)
{
    ui->setupUi(this);
    connect(ui->EJECUTAR_D,SIGNAL(clicked()),this,SLOT(procesar_d()));//execute button, click to execut the method
    connect(ui->BORRAR_D,SIGNAL(clicked()),this,SLOT(borrar_d()));//clean button, click to clean the spinboxes and display
    connect(ui->SALIR_D,SIGNAL(clicked()),this,SLOT(close()));//exit button, click to close the program

}

P8::~P8()
{
    delete ui;
}
double P8::funcion0(double x){//original function
    return (-(0.1*pow(x,4))-(0.15*pow(x,3))-(0.5*pow(x,2))-(0.25*x)+(1.2));
}
double  P8::funciond1(double x){//first derivate
    return (-(0.4*pow(x,3))-(0.45*pow(x,2))-(x)-(0.25));
}
double  P8::funciond2(double x){//second derivate
    return (-(1.2*pow(x,2))-(0.9*x)-(1));
}
double  P8::funciond3(double x){//third derivate
    return (-(2.4*x)-(0.9));
}
double  P8::funciond4(double x){//fourth derivate
    return (-2.4);
}
void P8::procesar_d(){//starts the process after clicking buttom Ejecutar
    QString tmpa,tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8,tmp9,
            tmp10,tmp11,tmp12,tmp13,tmp14,tmp15,tmp16,tmp17,
            tmp18,tmp19,tmp20,tmp21,tmp22,tmp23,tmp24,tmp25,
            tmp26,tmp27,tmp28,tmp29,tmp30,tmp31,tmp32,tmp33,
            tmp34,tmp35,tmp36,tmp37,tmp38,tmp39,tmp40,tmp41,
            tmp42,tmp43,tmp44,tmp45,tmp46,tmp47,tmp48,tmp49;//temporal strings
    //gets the fx colum's values
    double fxime5_d=ui->FXME5_D->value();
    double fxime4_d=ui->FXME4_D->value();
    double fxime3_d=ui->FXME3_D->value();
    double fxime2_d=ui->FXME2_D->value();
    double fxime1_d=ui->FXME1_D->value();
    double fxi_d=ui->FX_D->value();
    double fxima1_d=ui->FXMA1_D->value();
    double fxima2_d=ui->FXMA2_D->value();
    double fxima3_d=ui->FXMA3_D->value();
    double fxima4_d=ui->FXMA4_D->value();
    double fxima5_d=ui->FXMA5_D->value();
    //gets the Xi's value, we only will need the value from
    //X column, other values are optional
    double x_d=ui->X_d->value();
    //gets the increase value
    double h_d=ui->H_D->value();
    //variables  to contain the derivates values
    double ade1raoh,ade1raoh2,ade2daoh,ade2daoh2,ade3raoh,ade3raoh2,ade4taoh,ade4taoh2;
    double atr1raoh,atr1raoh2,atr2daoh,atr2daoh2,atr3raoh,atr3raoh2,atr4taoh,atr4taoh2;
    double cen1raoh,cen1raoh2,cen2daoh,cen2daoh2,cen3raoh,cen3raoh2,cen4taoh,cen4taoh2;
    //vsriables to contain the errors of the derivates
    double eade1raoh,eade1raoh2,eade2daoh,eade2daoh2,eade3raoh,eade3raoh2,eade4taoh,eade4taoh2;
    double eatr1raoh,eatr1raoh2,eatr2daoh,eatr2daoh2,eatr3raoh,eatr3raoh2,eatr4taoh,eatr4taoh2;
    double ecen1raoh,ecen1raoh2,ecen2daoh,ecen2daoh2,ecen3raoh,ecen3raoh2,ecen4taoh,ecen4taoh2;
    //derivates forward derivates
    //uses the formula to get 1st derivates(oh and oh^2) and their errors
    ade1raoh=(fxima1_d-fxi_d)/h_d;
    eade1raoh=100*std::abs(funciond1(x_d)-ade1raoh)/funciond1(x_d);
    ade1raoh2=(-(fxima2_d)+(4*fxima1_d)-(3*fxi_d))/(2*h_d);
    eade1raoh2=100*std::abs(funciond1(x_d)-ade1raoh2)/funciond1(x_d);
    //uses the formula to get 2nd derivates(oh and oh^2) and their errors
    ade2daoh=((fxima2_d)-(2*fxima1_d)+(fxi_d))/(pow(h_d,2));
    eade2daoh=100*std::abs(funciond2(x_d)-ade2daoh)/funciond2(x_d);
    ade2daoh2=(-(fxima3_d)+(4*fxima2_d)-(5*fxima1_d)+(2*fxi_d))/(pow(h_d,2));
    eade2daoh2=100*std::abs(funciond2(x_d)-ade2daoh2)/funciond2(x_d);
    //uses the formula to get 3rd derivates(oh and oh^2) and their errors
    ade3raoh=((fxima3_d)-(3*fxima2_d)+(3*fxima1_d)-(fxi_d))/(pow(h_d,3));
    eade3raoh=100*std::abs(funciond3(x_d)-ade3raoh)/funciond3(x_d);
    ade3raoh2=(-(3*fxima4_d)+(14*fxima3_d)-(24*fxima2_d)+(18*fxima1_d)-(5*fxi_d))/(2*pow(h_d,3));
    eade3raoh2=100*std::abs(funciond3(x_d)-ade3raoh2)/funciond3(x_d);
    //uses the formula to get 4th derivates(oh and oh^2) and their errors
    ade4taoh=((fxima4_d)-(4*fxima3_d)+(6*fxima2_d)-(4*fxima1_d)+(fxi_d))/(pow(h_d,4));
    eade4taoh=100*std::abs(funciond4(x_d)-ade4taoh)/funciond4(x_d);
    ade4taoh2=(-(2*fxima5_d)+(11*fxima4_d)-(24*fxima3_d)+(26*fxima2_d)-(14*fxima1_d)+(3*fxi_d))/(pow(h_d,4));
    eade4taoh2=100*std::abs(funciond4(x_d)-ade4taoh2)/funciond4(x_d);

    //backward derivates
    //uses the formula to get 1st derivates(oh and oh^2) and their errors
    atr1raoh=((fxi_d)-(fxime1_d))/(h_d);
    eatr1raoh=100*std::abs(funciond1(x_d)-atr1raoh)/funciond1(x_d);
    atr1raoh2=((3*fxi_d)-(4*fxime1_d)+(fxime2_d))/(2*h_d);
    eatr1raoh2=100*std::abs(funciond1(x_d)-atr1raoh2)/funciond1(x_d);
    //uses the formula to get 2nd derivates(oh and oh^2) and their errors
    atr2daoh=((fxi_d)-(2*fxime1_d)+(fxime2_d))/(pow(h_d,2));
    eatr2daoh=100*std::abs(funciond2(x_d)-atr2daoh)/funciond2(x_d);
    atr2daoh2=((2*fxi_d)-(5*fxime1_d)+(4*fxime2_d)-(fxime3_d))/(pow(h_d,2));
    eatr2daoh2=100*std::abs(funciond2(x_d)-atr2daoh2)/funciond2(x_d);
    //uses the formula to get 3rd derivates(oh and oh^2) and their errors
    atr3raoh=((fxi_d)-(3*fxime1_d)+(3*fxime2_d)-(fxime3_d))/(pow(h_d,3));
    eatr3raoh=100*std::abs(funciond3(x_d)-atr3raoh)/funciond3(x_d);
    atr3raoh2=((5*fxi_d)-(18*fxime1_d)+(24*fxime2_d)-(14*fxime3_d)+(3*fxime4_d))/(2*pow(h_d,3));
    eatr3raoh2=100*std::abs(funciond3(x_d)-atr3raoh2)/funciond3(x_d);
    //uses the formula to get 4th derivates(oh and oh^2) and their errors
    atr4taoh=((fxi_d)-(4*fxime1_d)+(6*fxime2_d)-(4*fxime3_d)+(fxime4_d))/(pow(h_d,4));
    eatr4taoh=100*std::abs(funciond4(x_d)-atr4taoh)/funciond4(x_d);
    atr4taoh2=((3*fxi_d)-(14*fxime1_d)+(26*fxime2_d)-(24*fxime3_d)+(11*fxime4_d)-(2*fxime5_d))/(pow(h_d,4));
    eatr4taoh2=100*std::abs(funciond4(x_d)-atr4taoh2)/funciond4(x_d);

  //central derivates
    //uses the formula to get 1st derivates(oh and oh^2) and their errors
    cen1raoh=((fxima1_d)-(fxime1_d))/(2*h_d);
    ecen1raoh=100*std::abs(funciond1(x_d)-cen1raoh)/funciond1(x_d);
    cen1raoh2=(-(fxima2_d)+(8*fxima1_d)-(8*fxime1_d)+(fxime2_d))/(12*h_d);
    ecen1raoh2=100*std::abs(funciond1(x_d)-cen1raoh2)/funciond1(x_d);
    //uses the formula to get 2nd derivates(oh and oh^2) and their errors
    cen2daoh=((fxima1_d)-(2*fxi_d)+(fxime1_d))/(pow(h_d,2));
    ecen2daoh=100*std::abs(funciond2(x_d)-cen2daoh)/funciond2(x_d);
    cen2daoh2=(-(fxima2_d)+(16*fxima1_d)-(30*fxi_d)+(16*fxime1_d)-(fxime2_d))/(12*pow(h_d,2));
    ecen2daoh2=100*std::abs(funciond2(x_d)-cen2daoh2)/funciond2(x_d);
    //uses the formula to get 3rd derivates(oh and oh^2) and their errors
    cen3raoh=((fxima2_d)-(2*fxima1_d)+(2*fxime1_d)-(fxime2_d))/(2*pow(h_d,3));
    ecen3raoh=100*std::abs(funciond3(x_d)-cen3raoh)/funciond3(x_d);
    cen3raoh2=(-(fxima3_d)+(8*fxima2_d)-(13*fxima1_d)+(13*fxime1_d)-(8*fxime2_d)+(fxime3_d))/(8*pow(h_d,3));
    ecen3raoh2=100*std::abs(funciond3(x_d)-cen3raoh2)/funciond3(x_d);
    //uses the formula to get 4th derivates(oh and oh^2) and their errors
    cen4taoh=((fxima2_d)-(4*fxima1_d)+(6*fxi_d)-(4*fxime1_d)+(fxime2_d))/(pow(h_d,4));
    ecen4taoh=100*std::abs(funciond4(x_d)-cen4taoh)/funciond4(x_d);
    cen4taoh2=(-(fxima3_d)+(12*fxima2_d)+(39*fxima1_d)+(56*fxi_d)-(39*fxime1_d)+(12*fxime2_d)+(fxime3_d))/(6*pow(h_d,4));
    ecen4taoh2=100*std::abs(funciond4(x_d)-cen4taoh2)/funciond4(x_d);

    //form of the text that will be shown
    tmpa.append("DERIVADAS HACIA ADELANTE \n\nf(x)'=").append(tmp1.setNum(ade1raoh))
    .append("    O(h)->error=").append(tmp25.setNum(eade1raoh))
    .append("\nf(x)'=").append(tmp2.setNum(ade1raoh2))
    .append("    O(h^2)->error=").append(tmp26.setNum(eade1raoh2))

    .append("    \n\nf(x)''=").append(tmp3.setNum(ade2daoh))
    .append("    O(h)->error=").append(tmp27.setNum(eade2daoh))
    .append("    \nf(x)''=").append(tmp4.setNum(ade2daoh2))
    .append("    O(h^2)->error=").append(tmp28.setNum(eade2daoh2))

    .append("    \n\nf(x)'''=").append(tmp5.setNum(ade3raoh))
    .append("    O(h)->error=").append(tmp29.setNum(eade3raoh))
    .append("    \nf(x)'''=").append(tmp6.setNum(ade3raoh2))
    .append("    O(h^2)->error=").append(tmp30.setNum(eade3raoh2))

    .append("    \n\nf(x)''''=").append(tmp7.setNum(ade4taoh))
    .append("    O(h)->error=").append(tmp31.setNum(eade4taoh))
    .append("    \nf(x)''''=").append(tmp8.setNum(ade4taoh2))
    .append("    O(h^2)->error=").append(tmp32.setNum(eade4taoh2))

    .append("    \n\n\nDERIVADAS HACIA ATRAS\n\nf(x)'=").append(tmp9.setNum(atr1raoh))
    .append("    O(h)->error=").append(tmp33.setNum(eatr1raoh))
    .append("    \nf(x)'=").append(tmp10.setNum(atr1raoh2))
    .append("    O(h^2)->error=").append(tmp34.setNum(eatr1raoh2))

    .append("    \n\nf(x)''=").append(tmp11.setNum(atr2daoh))
    .append("    O(h)->error=").append(tmp35.setNum(eatr2daoh))
    .append("    \nf(x)''=").append(tmp12.setNum(atr2daoh2))
    .append("    O(h^2)->error=").append(tmp36.setNum(eatr2daoh2))

    .append("    \n\nf(x)'''=").append(tmp13.setNum(atr3raoh))
    .append("    O(h)->error=").append(tmp37.setNum(eatr3raoh))
    .append("    \nf(x)'''=").append(tmp14.setNum(atr3raoh2))
    .append("    O(h^2)->error=").append(tmp38.setNum(eatr3raoh2))

    .append("    \n\nf(x)''''=").append(tmp15.setNum(atr4taoh))
    .append("    O(h)->error=").append(tmp39.setNum(eatr4taoh))
    .append("    \nf(x)''''=").append(tmp16.setNum(atr4taoh2))
    .append("    O(h^2)->error=").append(tmp40.setNum(eatr4taoh2))

    .append("    \n\n\nDERIVADAS CENTRADAS\n\nf(x)'=").append(tmp17.setNum(cen1raoh))
    .append("    O(h)->error=").append(tmp41.setNum(ecen1raoh))
    .append("    \nf(x)'=").append(tmp18.setNum(cen1raoh2))
    .append("    O(h^2)->error=").append(tmp42.setNum(ecen1raoh2))

    .append("    \n\nf(x)''=").append(tmp19.setNum(cen2daoh))
    .append("    O(h)->error=").append(tmp43.setNum(ecen2daoh))
    .append("    \nf(x)''=").append(tmp20.setNum(cen2daoh2))
    .append("    O(h^2)->error=").append(tmp44.setNum(ecen2daoh2))

    .append("    \n\nf(x)'''=").append(tmp21.setNum(cen3raoh))
    .append("    O(h)->error=").append(tmp45.setNum(ecen3raoh))
    .append("    \nf(x)'''=").append(tmp22.setNum(cen3raoh2))
    .append("    O(h^2)->error=").append(tmp46.setNum(ecen3raoh2))

    .append("    \n\nf(x)''''=").append(tmp23.setNum(cen4taoh))
    .append("    O(h)->error=").append(tmp47.setNum(ecen4taoh))
    .append("    \nf(x)''''=").append(tmp24.setNum(cen4taoh2))
    .append("    O(h^2)->error=").append(tmp48.setNum(ecen4taoh2));

    ui->TEXTO_D->setText(tmpa);//shows the text

}
void P8::borrar_d(){//cleans all
    ui->FX_D->setValue(0.0);
    ui->FXMA1_D->setValue(0.0);
    ui->FXMA2_D->setValue(0.0);
    ui->FXMA3_D->setValue(0.0);
    ui->FXMA4_D->setValue(0.0);
    ui->FXMA5_D->setValue(0.0);
    ui->FXME1_D->setValue(0.0);
    ui->FXME2_D->setValue(0.0);
    ui->FXME3_D->setValue(0.0);
    ui->FXME4_D->setValue(0.0);
    ui->FXME5_D->setValue(0.0);
    ui->X_d->setValue(0.0);
    ui->XME1_D->setValue(0.0);
    ui->XME2_D->setValue(0.0);
    ui->XME3_D->setValue(0.0);
    ui->XME4_D->setValue(0.0);
    ui->XME5_D->setValue(0.0);
    ui->XMA1_D->setValue(0.0);
    ui->XMA2_D->setValue(0.0);
    ui->XMA3_D->setValue(0.0);
    ui->XMA4_D->setValue(0.0);
    ui->XMA5_D->setValue(0.0);
    ui->TEXTO_D->clear();
}
