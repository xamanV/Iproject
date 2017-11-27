#ifndef P9_H
#define P9_H

#include <QMainWindow>

namespace Ui {
class P9;
}

class P9 : public QMainWindow
{
    Q_OBJECT

public:
    explicit P9(QWidget *parent = 0);
    ~P9();

private:
    Ui::P9 *ui;
private slots:
    void procesar_i();
    void borrar_i();
};

#endif // P9_H
