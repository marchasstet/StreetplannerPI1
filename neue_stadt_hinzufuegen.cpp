#include "neue_stadt_hinzufuegen.h"
#include "ui_neue_stadt_hinzufuegen.h"
#include "city.h"

Neue_Stadt_Hinzufuegen::Neue_Stadt_Hinzufuegen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Neue_Stadt_Hinzufuegen)
{
    ui->setupUi(this);
}

Neue_Stadt_Hinzufuegen::~Neue_Stadt_Hinzufuegen()
{
    delete ui;
}

void Neue_Stadt_Hinzufuegen::on_buttonBox_accepted()
{

}

/**
 * @brief Creates a new City object based on user input.
 *
 * Reads the name, x-coordinate, and y-coordinate from the UI elements and creates
 * a new City object with these parameters.
 *
 * @return A pointer to the newly created City object.
 */
City* Neue_Stadt_Hinzufuegen::on_pushButton_clicked()
{
    QString name= ui->lineEdit->text();
    //ui->spinBox->setMinimum(-100);
   // ui->spinBox_2->setMinimum(-100);
    int x = ui->spinBox->value();
    int y = ui->spinBox_2->value();

    qDebug()<<name;
    qDebug()<<x;
    qDebug()<<y;
    return new City(name,x,y);
}

