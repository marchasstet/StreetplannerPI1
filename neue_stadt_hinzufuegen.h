#ifndef NEUE_STADT_HINZUFUEGEN_H
#define NEUE_STADT_HINZUFUEGEN_H

#include <QDialog>
#include "city.h"
namespace Ui {
class Neue_Stadt_Hinzufuegen;
}

class Neue_Stadt_Hinzufuegen : public QDialog
{
    Q_OBJECT

public:
    int hoehe;
    int weite;
    explicit Neue_Stadt_Hinzufuegen(QWidget *parent = nullptr);
    ~Neue_Stadt_Hinzufuegen();
     City* on_pushButton_clicked();
    void getWidth(int a, int b){hoehe=a;weite=b;}

private slots:
   void on_buttonBox_accepted();



private:
    Ui::Neue_Stadt_Hinzufuegen *ui;

};

#endif // NEUE_STADT_HINZUFUEGEN_H
