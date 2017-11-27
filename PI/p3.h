#ifndef P3_H
#define P3_H

#include <QMainWindow>

namespace Ui {
class P3;
}

class P3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit P3(QWidget *parent = 0);
    ~P3();

private:
    Ui::P3 *ui;
public slots:
    void ejecutar();//slot to execute
    void borrar();//slot to clean

};

#endif // P3_H
