#ifndef MAKESTREET_H
#define MAKESTREET_H
#include <QList>
#include "city.h"
#include "street.h"
#include "map.h"
#include <QDialog>

namespace Ui {
class MakeStreet;
}

class MakeStreet : public QDialog
{
    Q_OBJECT

public:
    explicit MakeStreet(QWidget *parent = nullptr);
    void setCityList(const QList<City*> cities);
    Street* createStreet(Map*) const;
    ~MakeStreet();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

private:
    Ui::MakeStreet *ui;
};

#endif // MAKESTREET_H
