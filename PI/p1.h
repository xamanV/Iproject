#ifndef P1_H
#define P1_H

#include <QMainWindow>

namespace Ui {
class P1;
}

class P1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit P1(QWidget *parent = 0);
    ~P1();
      double funcion(double c);

private:
    Ui::P1 *ui;
public slots:

    void proceso(); //Slot make method
     void borrar(); //Slot make ereaser
};

#endif // P1_H
