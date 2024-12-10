#include "pathdialog.h"
#include "ui_pathdialog.h"
#include "dijkstra.h"
#include <QDialogButtonBox>
#include <QPushButton>

PathDialog::PathDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PathDialog)
{
    ui->setupUi(this);
    QPushButton *okBtn = this->ui->buttonBox->button(QDialogButtonBox::Ok);
    okBtn->setDisabled(true);
}
/**
 * @brief Fills the start and destination city selection dropdowns with city names.
 *
 * Sets the items in the startCity_Selection and destinationCity_Selection QComboBoxes
 * based on the provided list of cities. If the list is empty, sets a placeholder text
 * indicating no cities are available.
 *
 * @param cities The list of cities to populate in the dropdowns.
 */
void PathDialog::setCityList(const QList<City*> cities) {
    if (cities.isEmpty()) {
        ui->startCity_Selection->setPlaceholderText("Keine Städte vorhanden");
        ui->destinationCity_Selection->setPlaceholderText("Keine Städte vorhanden");
        return;
    }
    for (auto city : cities) {
        QString name = city->getName();
        ui->startCity_Selection->addItem(name);
        ui->destinationCity_Selection->addItem(name);
    }
}
/**
 * @brief Sets the current texts of start and destination city selection dropdowns.
 *
 * Sets the current text of ui->startCity_Selection and ui->destinationCity_Selection
 * QComboBoxes based on the provided city names.
 *
 * @param city1 The name of the city to set as current text in the start city selection.
 * @param city2 The name of the city to set as current text in the destination city selection.
 */
void PathDialog::setCity12(QString city1, QString city2) {
    ui->startCity_Selection->setCurrentText(city1);
    ui->destinationCity_Selection->setCurrentText(city2);
}
/**
 * @brief Finds a path between the selected start and destination cities using Dijkstra's algorithm.
 *
 * Uses Dijkstra's algorithm to find a path between the cities selected in the start and destination
 * city selection dropdowns (ui->startCity_Selection and ui->destinationCity_Selection).
 *
 * @param map The map object containing cities and streets.
 * @return A list of streets representing the shortest path between the selected cities.
 */
QList<Street*> PathDialog::findPath(Map& map) const {
    QString startName = ui->startCity_Selection->currentText();
    QString destinationName = ui->destinationCity_Selection->currentText();

    return Dijkstra::search(map, startName, destinationName);
}
/**
 * @brief Creates a new street object between the selected start and destination cities.
 *
 * Creates and returns a new Street object connecting the cities selected in the start and
 * destination city selection dropdowns (ui->startCity_Selection and ui->destinationCity_Selection).
 *
 * @param map Pointer to the Map object where the cities are stored.
 * @return Pointer to the newly created Street object, or nullptr if either city is not found.
 */
Street* PathDialog::createStreet(Map* map) const {
    QString startName = ui->startCity_Selection->currentText();
    QString destinationName = ui->destinationCity_Selection->currentText();
    City* city1 = map->findCity(startName);
    City* city2 = map->findCity(destinationName);

    if (city1 == nullptr || city2 == nullptr) return nullptr;

    Street* strasse = new Street(city1, city2);
    return strasse;
}


PathDialog::~PathDialog()
{
    delete ui;
}
/**
 * @brief Slot function called when the text in the start city selection dropdown changes.
 *
 * This slot function is called whenever the text in the start city selection dropdown
 * (ui->startCity_Selection) changes. It updates the enabled state of the OK button in
 * the button box based on whether the selected start city is different from the selected
 * destination city and both fields are not empty.
 *
 * @param arg1 The new text in the start city selection dropdown.
 */
void PathDialog::on_startCity_Selection_currentTextChanged(const QString &arg1)
{
    QPushButton *okBtn = this->ui->buttonBox->button(QDialogButtonBox::Ok);
    QString otherInputText = ui->destinationCity_Selection->currentText();
    if (arg1 == otherInputText || arg1.isEmpty() || otherInputText.isEmpty()) {
        okBtn->setDisabled(true);
    } else {
        okBtn->setEnabled(true);
    }
}

/**
 * @brief Slot function called when the text in the destination city selection dropdown changes.
 *
 * This slot function is called whenever the text in the destination city selection dropdown
 * (ui->destinationCity_Selection) changes. It updates the enabled state of the OK button in
 * the button box based on whether the selected destination city is different from the selected
 * start city and both fields are not empty.
 *
 * @param arg1 The new text in the destination city selection dropdown.
 */
void PathDialog::on_destinationCity_Selection_currentTextChanged(const QString &arg1)
{
    QPushButton *okBtn = this->ui->buttonBox->button(QDialogButtonBox::Ok);
    QString otherInputText = ui->startCity_Selection->currentText();
    if (arg1 == otherInputText || arg1.isEmpty() || otherInputText.isEmpty()) {
        okBtn->setDisabled(true);
    } else {
        okBtn->setEnabled(true);
    }
}

