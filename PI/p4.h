#ifndef P4_H
#define P4_H

#include <QMainWindow>

namespace Ui {
class P4;
}

class P4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit P4(QWidget *parent = 0);
    ~P4();

private:
    Ui::P4 *ui;
public slots:
    void ejecutar();//slot to execute
    void borrar();//slot to clean
};

#endif // P4_H
