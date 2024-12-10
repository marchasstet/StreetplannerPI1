#include "makestreet.h"
#include "ui_makestreet.h"
#include <QDialogButtonBox>
#include <QPushButton>
MakeStreet::MakeStreet(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MakeStreet)
{
    ui->setupUi(this);
    QPushButton *okBtn = this->ui->buttonBox->button(QDialogButtonBox::Ok);
    okBtn->setDisabled(true);
}

MakeStreet::~MakeStreet()
{
    delete ui;
}
/**
 * @brief Setzt die Liste der Städte für die ComboBoxen in der Dialogbox zum Erstellen einer Straße.
 *
 * Diese Methode wird verwendet, um die ComboBoxen in der Dialogbox (`MakeStreet`) mit einer Liste von
 * Städten zu füllen. Falls die übergebene Liste leer ist, wird in den ComboBoxen ein Platzhaltertext
 * angezeigt, um darauf hinzuweisen, dass keine Städte verfügbar sind. Andernfalls werden die Namen der
 * Städte aus der Liste in die ComboBoxen eingefügt, damit der Benutzer eine Stadt als Start- und
 * Zielort der Straße auswählen kann.
 *
 * @param cities Eine Liste von Zeigern auf `City`-Objekte, die in den ComboBoxen angezeigt werden sollen.
 *
 * @note Diese Methode geht davon aus, dass die ComboBoxen `comboBox` und `comboBox_2` existieren und
 * gültig sind.
 */
void MakeStreet::setCityList(const QList<City*> cities) {
    if (cities.isEmpty()) {
        ui->comboBox->setPlaceholderText("Keine Städte vorhanden");
        ui->comboBox_2->setPlaceholderText("Keine Städte vorhanden");
        return;
    }
    for (auto city : cities) {
        QString name = city->getName();
        ui->comboBox->addItem(name);
        ui->comboBox_2->addItem(name);
    }
}
/**
 * @brief Erstellt eine neue Straße basierend auf den ausgewählten Städten in den ComboBoxen.
 *
 * Diese Methode erstellt eine neue Straße zwischen zwei ausgewählten Städten in den ComboBoxen
 * der Dialogbox (`MakeStreet`). Sie sucht die entsprechenden `City`-Objekte in der übergebenen
 * Karte (`map`) anhand der ausgewählten Stadtnamen und erstellt eine neue Straße zwischen diesen
 * beiden Städten, falls beide Städte gefunden werden können.
 *
 * @param map Ein Zeiger auf die Karte (`Map`), in der die Städte gesucht werden sollen.
 * @return Ein Zeiger auf die erstellte Straße (`Street`) oder nullptr, wenn eine oder beide
 * Städte nicht gefunden werden konnten.
 *
 * @note Diese Methode geht davon aus, dass die ComboBoxen `comboBox` und `comboBox_2` existieren
 * und gültige Städtenamen enthalten.
 */
Street* MakeStreet::createStreet(Map* map) const {
    QString startName = ui->comboBox->currentText();
    QString destinationName = ui->comboBox_2->currentText();
    City* city1 = map->findCity(startName);
    City* city2 = map->findCity(destinationName);

    if (city1 == nullptr || city2 == nullptr) return nullptr;

    Street* strasse = new Street(city1, city2);
    return strasse;
}
/**
 * @brief Reagiert auf Änderungen im Text der ComboBox für Stadtauswahl.
 *
 * Diese Methode wird aufgerufen, wenn der Text in der ComboBox (`comboBox`) für die Auswahl
 * der Startstadt geändert wird. Sie überprüft, ob der neue Text der ComboBox identisch mit dem
 * aktuellen Text der ComboBox (`comboBox_2`) für die Zielstadt ist oder ob einer der Texte leer ist.
 * Wenn eine dieser Bedingungen erfüllt ist, wird der OK-Button deaktiviert. Andernfalls wird der
 * OK-Button aktiviert.
 *
 * @param arg1 Der neue Text der ComboBox für die Startstadt.
 *
 * @note Diese Methode geht davon aus, dass die ComboBoxen `comboBox` und `comboBox_2` existieren
 * und gültige Stadtnamen enthalten. Der OK-Button wird de-/aktiviert basierend auf den aktuellen
 * Texten der ComboBoxen.
 */
void MakeStreet::on_comboBox_currentTextChanged(const QString &arg1)
{
    QPushButton *okBtn = this->ui->buttonBox->button(QDialogButtonBox::Ok);
    QString otherInputText = ui->comboBox_2->currentText();
    if (arg1 == otherInputText || arg1.isEmpty() || otherInputText.isEmpty()) {
        okBtn->setDisabled(true);
    } else {
        okBtn->setEnabled(true);
    }
}

/**
 * @brief Reagiert auf Änderungen im Text der ComboBox für Zielstadtauswahl.
 *
 * Diese Methode wird aufgerufen, wenn der Text in der ComboBox (`comboBox_2`) für die Auswahl
 * der Zielstadt geändert wird. Sie überprüft, ob der neue Text der ComboBox identisch mit dem
 * aktuellen Text der ComboBox (`comboBox`) für die Startstadt ist oder ob einer der Texte leer ist.
 * Wenn eine dieser Bedingungen erfüllt ist, wird der OK-Button deaktiviert. Andernfalls wird der
 * OK-Button aktiviert.
 *
 * @param arg1 Der neue Text der ComboBox für die Zielstadt.
 *
 * @note Diese Methode geht davon aus, dass die ComboBoxen `comboBox` und `comboBox_2` existieren
 * und gültige Stadtnamen enthalten. Der OK-Button wird de-/aktiviert basierend auf den aktuellen
 * Texten der ComboBoxen.
 */
void MakeStreet::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    QPushButton *okBtn = this->ui->buttonBox->button(QDialogButtonBox::Ok);
    QString otherInputText = ui->comboBox->currentText();
    if (arg1 == otherInputText || arg1.isEmpty() || otherInputText.isEmpty()) {
        okBtn->setDisabled(true);
    } else {
        okBtn->setEnabled(true);
    }
}

