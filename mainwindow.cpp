#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QFileDialog>
#include <QStandardPaths>

#include "city.h"
#include "map.h"
#include "neue_stadt_hinzufuegen.h"
#include "mapionrw.h"
#include "dijkstra.h"
#include "pathdialog.h"
#include "makestreet.h"
#include "smallcity.h"
#include "bigtown.h"
#include "mapiofileinput.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),scene(new QGraphicsScene),map(new Map), mapio(new MapIoNrw)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/**
 * @brief Schließt das Hauptfenster.
 *
 * Diese Methode wird aufgerufen, wenn die Exit-Aktion in der Menüleiste ausgelöst wird.
 * Sie schließt das Hauptfenster der Anwendung.
 */
void MainWindow::on_actionExit_triggered()
{
    close();
}

/**
 * @brief Zeigt Informationen über die Anwendung an.
 *
 * Diese Methode wird aufgerufen, wenn die About-Aktion in der Menüleiste ausgelöst wird.
 * Sie zeigt eine QMessageBox mit Informationen über die Anwendung an.
 */

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msg;
    msg.about(this,"Does Stuff","Does Stuff and Evenmore stuff");
}

/**
 * @brief Verarbeitet den Klick auf die Schaltfläche.
 *
 * Diese Methode wird aufgerufen, wenn die Schaltfläche (QPushButton) in der Benutzeroberfläche
 * angeklickt wird. Sie verarbeitet den Inhalt eines Textfelds (QLineEdit), führt eine Berechnung
 * durch und zeigt das Ergebnis in einer QMessageBox an. Außerdem wird ein rotes Rechteck zu einer
 * QGraphicsScene hinzugefügt und diese angezeigt.
 */

void MainWindow::on_pushButton_clicked()
{
    bool ok;
    QString str1= ui->lineEdit->text();
    QString str2;
    int x= str1.toInt(&ok);
    if(ok==false){
        str2=QString("fuck you %1").arg(str1);
        qDebug() << str2;
    }
    else{
        str2=QString("fuck you %1").arg(x+4);
        qDebug() << str2;
    }
    QMessageBox msgBox;
    msgBox.setText(str2);
    msgBox.exec();
    int pos_x = QRandomGenerator::global()->bounded(scene->width());
    int pos_y = QRandomGenerator::global()->bounded(scene->height());
    qDebug() << pos_x;
    qDebug() << pos_y;
    scene->addRect(pos_x, pos_y, 5, 5,QPen(Qt::red),QBrush(Qt::red,Qt::SolidPattern));

    ui->graphicsView->show();

}

/**
 * @brief Löscht alle Objekte in der QGraphicsScene.
 *
 * Diese Methode wird aufgerufen, wenn die Clear Scene-Aktion in der Menüleiste ausgelöst wird.
 * Sie löscht alle Objekte (z.B. Rechtecke, Texte) in der aktuellen QGraphicsScene.
 */
void MainWindow::on_actionclear_scene_triggered()
{
    scene->clear();
}

/**
 * @brief Zeigt Teststädte in der QGraphicsScene an.
 *
 * Diese Methode wird aufgerufen, wenn die Schaltfläche "Test draw City" in der Benutzeroberfläche geklickt wird.
 * Sie erstellt zwei Teststädte (`City`-Objekte) mit spezifischen Namen und Koordinaten und zeichnet sie auf der
 * aktuellen QGraphicsScene.
 *
 * @details Die Methode erzeugt ein `City`-Objekt für Aachen mit den Koordinaten (10, 10) und ein weiteres für Köln
 * mit den Koordinaten (-5, -5). Anschließend werden die `draw`-Methoden der `City`-Objekte aufgerufen, um sie auf der
 * QGraphicsScene `scene` zu zeichnen.
 */
void MainWindow::on_pushButton_2_clicked()//Test draw City
{
  City* test=  new City("Aachen",10,10);
  City* test1=  new City("Köln",-5,-5);
    test->draw(*scene);
  test1->draw(*scene);

}

/**
 * @brief Zeichnet alle Städte auf der Karte in der QGraphicsScene.
 *
 * Diese Methode wird aufgerufen, wenn die Schaltfläche "draw all cities" in der Benutzeroberfläche geklickt wird.
 * Sie fügt drei Städte (Dortmund, Aachen, Düsseldorf) zur Karte (`map`) hinzu und zeichnet diese auf der
 * aktuellen QGraphicsScene.
 *
 * @details Die Methode erstellt neue `City`-Objekte für Dortmund (100, 100), Aachen (50, 150) und Düsseldorf (80, 120)
 * und fügt sie zur Karte (`map`) hinzu. Anschließend wird die `draw`-Methode der `map` aufgerufen, um alle Städte
 * auf der QGraphicsScene `scene` zu zeichnen.
 */
void MainWindow::on_pushButton_3_clicked()//draw all cities
{    map->addCity(new City("Dortmund", 100, 100));
    map->addCity(new City("Aachen", 50, 150));
    map->addCity(new City("Düsseldorf", 80, 120));
    map->draw(*scene);
}
/**
 * @brief Erstellt und zeichnet Teststraßen zwischen Städten in der QGraphicsScene.
 *
 * Diese Methode wird aufgerufen, wenn die Schaltfläche "test streets" in der Benutzeroberfläche geklickt wird.
 * Sie erstellt zwei Teststädte (`City`-Objekte) mit spezifischen Namen und Koordinaten sowie eine Teststraße
 * (`Street`-Objekt), die diese Städte verbindet. Anschließend werden die Städte und die Straße auf der aktuellen
 * QGraphicsScene gezeichnet.
 *
 * @details Die Methode erstellt ein `City`-Objekt für Aachen mit den Koordinaten (10, 10) und ein weiteres für Köln
 * mit den Koordinaten (-20, -20). Danach wird ein `Street`-Objekt erstellt, das Aachen und Köln verbindet. Alle
 * Objekte werden anschließend auf der QGraphicsScene `scene` gezeichnet.
 */

void MainWindow::on_pushButton_4_clicked()// test streets
{
    City* test=  new City("Aachen",10,10);
    City* test1=  new City("Köln",-20,-20);
    Street* test2= new Street(test,test1);

    test2->draw(*scene);
    test->draw(*scene);
    test1->draw(*scene);
}

/**
 * @brief Testet und zeichnet Straßen zwischen Städten in der QGraphicsScene.
 *
 * Diese Methode wird aufgerufen, wenn die Schaltfläche "test if streets r allowed nd draw them otherwise"
 * in der Benutzeroberfläche geklickt wird. Sie erstellt zwei Teststädte (`City`-Objekte) mit spezifischen
 * Namen und Koordinaten sowie zwei Teststraßen (`Street`-Objekte), die die Städte verbinden. Ein Stadtobjekt
 * wird mehrmals hinzugefügt, um zu testen, wie das Programm damit umgeht. Alle Städte und Straßen werden auf
 * der aktuellen QGraphicsScene gezeichnet.
 *
 * @details Die Methode erstellt ein `City`-Objekt für Aachen mit den Koordinaten (10, 10) und ein weiteres für Köln
 * mit den Koordinaten (-20, -20). Dann werden zwei `Street`-Objekte erstellt: `test2`, das Aachen und Köln verbindet,
 * und `test5`, das Aachen mit sich selbst verbindet. Diese Straßen werden zur Karte (`map`) hinzugefügt, zusammen mit
 * den Städten. Anschließend werden die Städte und Straßen auf der QGraphicsScene `scene` gezeichnet.
 */

void MainWindow::on_pushButton_5_clicked()//test if streets r allowed nd draw them otherwise
{
    City* test=  new City("Aachen",10,10);
    City* test1=  new City("Köln",-20,-20);
    Street* test2= new Street(test,test1);

    City* test3=  new City("Aachen",10,10);
    Street* test5= new Street(test,test);
    map->addStreet(test2);
    map->addStreet(test5);
    map->addCity(test);
    map->addCity(test1);
    test1->draw(*scene);
    test->draw(*scene);
    map->addStreet(test2);
    map->addStreet(test5);
    map->draw(*scene);
}




/**
 * @brief Versteckt oder zeigt mehrere Schaltflächen basierend auf dem Zustand eines Kontrollkästchens.
 *
 * Diese Methode wird aufgerufen, wenn das Kontrollkästchen (QCheckBox) in der Benutzeroberfläche angeklickt wird.
 * Sie versteckt oder zeigt mehrere Schaltflächen (`QPushButton`), abhängig vom Zustand des Kontrollkästchens.
 *
 * @param checked Der Zustand des Kontrollkästchens (`true`, wenn angeklickt und `false`, wenn nicht).
 */
void MainWindow::on_checkBox_clicked(bool checked)
{
    ui->pushButton_2->setHidden(checked);
    ui->pushButton_3->setHidden(checked);
    ui->pushButton_4->setHidden(checked);
    ui->pushButton_5->setHidden(checked);
    ui->pushButton_8->setHidden(checked);
    ui->pushButton_9->setHidden(checked);
}
/**
 * @brief Öffnet ein Dialogfenster zum Hinzufügen einer neuen Stadt und fügt die Stadt zur Karte hinzu.
 *
 * Diese Methode wird aufgerufen, wenn die Schaltfläche "pushButton_6" in der Benutzeroberfläche geklickt wird.
 * Sie öffnet ein Dialogfenster (`Neue_Stadt_Hinzufuegen`), um dem Benutzer die Möglichkeit zu geben, eine neue
 * Stadt hinzuzufügen. Nachdem der Benutzer die Stadt hinzugefügt hat, wird sie zur Karte (`map`) hinzugefügt
 * und die Karte wird auf der aktuellen QGraphicsScene gezeichnet.
 *
 * @details Die Methode ruft die Methode `getWidth` des `newStadt`-Objekts auf, um die Breite und Höhe des Dialogfensters
 * zu erhalten und sie zu debuggen. Anschließend wird das Dialogfenster `newStadt` geöffnet und darauf gewartet, dass
 * der Benutzer die Aktionen darin ausführt. Wenn eine neue Stadt erfolgreich hinzugefügt wurde (über den Rückgabewert
 * von `exec()`), wird sie zur Karte hinzugefügt und die aktualisierte Karte wird auf der QGraphicsScene gezeichnet.
 */

void MainWindow::on_pushButton_6_clicked()
{
    Neue_Stadt_Hinzufuegen newStadt;
    newStadt.getWidth(minimumHeight(),minimumWidth());
    qDebug()<<minimumHeight()<<minimumWidth();
    int accepted = newStadt.exec();
    if(!accepted){
        qDebug()<<"Error beim hinzufüegen einer neuen stadt";
        return;
    }
    City* newCity= newStadt.on_pushButton_clicked();

    map->addCity(newCity);
    map->draw(*scene);
}

/**
 * @brief Füllt die Karte aus der MapIO-Instanz und zeichnet sie auf der QGraphicsScene.
 *
 * Diese Methode wird aufgerufen, wenn die Schaltfläche "pushButton_7" in der Benutzeroberfläche geklickt wird.
 * Sie ruft die Methode `fillMap` der `mapio`-Instanz auf, um die Karte (`map`) mit Daten zu füllen. Anschließend
 * wird die aktualisierte Karte auf der QGraphicsScene (`scene`) gezeichnet.
 *
 * @details Die Methode verwendet die `fillMap`-Methode der `mapio`-Instanz, um die Karte mit Daten aus einer externen
 * Quelle zu füllen. Danach wird die `draw`-Methode der Karte aufgerufen, um sie auf der QGraphicsScene zu zeichnen.
 */
void MainWindow::on_pushButton_7_clicked()
{
    mapio->fillMap(*(this->map));
    this->map->draw(*(this->scene));
}

/**
 * @brief Führt Tests für die Map-Klasse aus.
 *
 * Diese Methode wird aufgerufen, wenn die Schaltfläche "pushButton_8" in der Benutzeroberfläche geklickt wird.
 * Sie führt eine Reihe von Tests für die Funktionalitäten der Map-Klasse durch, einschließlich Hinzufügen von Städten
 * und Straßen, Suchen von Städten, Ermitteln gegensätzlicher Städte, Bestimmen der Straßenlänge und Abrufen der
 * Straßenliste für eine bestimmte Stadt.
 *
 * @details Die Methode erstellt eine Testkarte (`testMap`), fügt verschiedene Städte (`a`, `b`, `c`) und Straßen (`s`, `s2`)
 * hinzu und überprüft dann die korrekte Ausführung der Methoden der Map-Klasse. Die Ergebnisse der Tests werden über
 * Debug-Ausgaben ausgegeben.
 */

void MainWindow::on_pushButton_8_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map->getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";

}

/**
 * @brief Öffnet einen Dialog zur Pfadfindung zwischen Städten und zeichnet den gefundenen Pfad auf der Karte.
 *
 * Diese Methode wird aufgerufen, wenn die Schaltfläche "pushButton_9" in der Benutzeroberfläche geklickt wird.
 * Sie öffnet einen Dialog (`PathDialog`), um dem Benutzer die Möglichkeit zu geben, einen Pfad zwischen Städten
 * auf der Karte zu finden. Der gefundene Pfad wird dann auf der Karte hervorgehoben und auf der aktuellen
 * QGraphicsScene gezeichnet.
 *
 * @details Die Methode erstellt einen neuen `PathDialog`, setzt die Liste der Städte mit Straßen für die Pfadfindung,
 * und wartet auf die Benutzeraktionen im Dialog. Wenn der Benutzer einen Pfad erfolgreich gefunden hat, werden die
 * Straßen des Pfades auf der Karte hervorgehoben (`setHighlightedStreets`) und die Karte auf der QGraphicsScene
 * neu gezeichnet (`draw`).
 */
void MainWindow::on_pushButton_9_clicked()
{
    PathDialog newDialog;
    newDialog.setCityList(map->getCitiesWithStreets());

    int accepted = newDialog.exec();

    if (!accepted) {
        qDebug() << "Fehler beim finden des Weges (Dialog failed / cancelled)";
        return;
    }

    QList<Street*> strassenliste = newDialog.findPath(*(this->map));

    if (strassenliste.empty()) {
        qDebug() << "Fehler beim findes des Weges (weg wurde nicht gefunden)";
        return;
    }

    this->map->setHighlightedStreets(strassenliste);

    this->map->draw(*(this->scene));
}

/**
 * @brief Erstellt eine neue Straße zwischen ausgewählten Städten und zeichnet sie auf der Karte.
 *
 * Diese Methode wird aufgerufen, wenn die Schaltfläche "pushButton_10" in der Benutzeroberfläche geklickt wird.
 * Sie öffnet einen Dialog (`MakeStreet`), um dem Benutzer die Möglichkeit zu geben, eine neue Straße zwischen
 * ausgewählten Städten zu erstellen. Nachdem die Straße erstellt wurde, wird sie zur Karte hinzugefügt und die
 * Karte wird auf der aktuellen QGraphicsScene neu gezeichnet.
 *
 * @details Die Methode erstellt einen neuen `MakeStreet`-Dialog und setzt die Liste der verfügbaren Städte,
 * zwischen denen die Straße erstellt werden kann. Nachdem der Benutzer eine Straße erstellt hat (oder den Dialog
 * abgebrochen hat), wird überprüft, ob die Straße erfolgreich erstellt wurde. Falls ja, wird die Straße zur Karte
 * hinzugefügt (`addStreet`) und die Karte auf der QGraphicsScene neu gezeichnet (`draw`).
 *
 * @note Wenn beim Erstellen der Straße ein Fehler auftritt und `createStreet` NULL zurückgibt, wird eine Fehlermeldung
 * ausgegeben, obwohl es unwahrscheinlich ist, dass dies geschieht, da der Dialog normalerweise Städte validiert, bevor
 * eine Straße erstellt wird.
 */
void MainWindow::on_pushButton_10_clicked()
{
    MakeStreet newStreet;
    newStreet.setCityList(map->getCities());

    int accepted = newStreet.exec();
    if (!accepted) {
        qDebug() << "Fehler beim erstellen der strasse (Dialog failed / cancelled)";
        return;
    }

    Street *neueStrasse = newStreet.createStreet(this->map);

    if (neueStrasse == nullptr) {
        qDebug() << "Fehler beim erstellen der strasse (idk was, aber wahrscheinlich städte nicht gefunden (sollte nicht möglich sein))";
        return;
    }
    this->map->addStreet(neueStrasse);

    this->map->draw(*(this->scene));

}
/**
 * @brief Testet das Zeichnen von Objekten verschiedener Stadttypen und einer Straße auf der Karte.
 *
 * Diese Methode wird aufgerufen, wenn die Schaltfläche "pushButton_11" in der Benutzeroberfläche geklickt wird.
 * Sie erstellt eine Instanz von `SmallCity` und `BigTown`, erstellt dann eine Straße zwischen diesen beiden
 * Städten (`Street`), und zeichnet diese Objekte auf der aktuellen QGraphicsScene.
 *
 * @details Die Methode erstellt ein `SmallCity`-Objekt mit dem Namen "Aachen" und Koordinaten (10, 10), ein
 * `BigTown`-Objekt mit dem Namen "Köln" und Koordinaten (-20, -20), sowie eine `Street`, die die beiden Städte
 * verbindet. Anschließend werden diese Objekte auf der Grafikszene (`scene`) gezeichnet, wobei jedes Objekt seine
 * eigene Zeichenmethode (`draw()`) aufruft, um auf der Szene dargestellt zu werden.
 *
 * @note Diese Methode dient hauptsächlich zum Testen der Zeichenfunktionalität für verschiedene Stadtklassen und
 * Straßen.
 */

void MainWindow::on_pushButton_11_clicked()
{
    SmallCity* test=  new SmallCity("Aachen",10,10);
    BigTown* test1=  new BigTown("Köln",-20,-20);
    Street* test2= new Street(test,test1);

    test2->draw(*scene);
    test->draw(*scene);
    test1->draw(*scene);
}
/**
 * @brief Öffnet Dateidialoge zum Laden von Städte- und Straßendateien und füllt die Karte damit.
 *
 * Diese Methode wird aufgerufen, wenn die Schaltfläche "pushButton_12" in der Benutzeroberfläche geklickt wird.
 * Sie öffnet zwei Dateidialoge, um den Benutzer dazu aufzufordern, eine Datei mit Städteinformationen und eine
 * Datei mit Straßeninformationen auszuwählen. Anschließend werden die ausgewählten Dateien eingelesen, um eine
 * Instanz von `MapIoFileinput` zu erstellen, die verwendet wird, um die Karte (`map`) zu füllen. Danach wird die
 * aktualisierte Karte auf der aktuellen QGraphicsScene neu gezeichnet.
 *
 * @details Die Methode verwendet `QFileDialog`, um den Benutzer zur Auswahl der Textdateien (*.txt) aufzufordern.
 * Wenn keine Dateien ausgewählt werden, wird die Methode vorzeitig verlassen. Andernfalls wird eine Instanz von
 * `MapIoFileinput` erstellt, die die ausgewählten Dateinamen für Städte und Straßen übernimmt. Anschließend wird die
 * Methode `fillMap()` aufgerufen, um die Karte mit den geladenen Informationen zu füllen. Schließlich wird die Methode
 * `draw()` aufgerufen, um die aktualisierte Karte auf der QGraphicsScene (`scene`) zu zeichnen.
 *
 * @note Diese Methode sollte sicherstellen, dass die geladenen Dateien im erwarteten Format vorliegen, da keine
 * Validierung der Dateiinhalte innerhalb dieser Methode erfolgt.
 */

void MainWindow::on_pushButton_12_clicked()//File Fill
{


        QString cityFileName = QFileDialog::getOpenFileName(
            this,
            tr("Open Cities"),
            QStandardPaths::writableLocation(QStandardPaths::HomeLocation),
            tr("Text Files (*.txt)")
            );
        if (cityFileName.isEmpty()) return;

        QString streetFileName = QFileDialog::getOpenFileName(
            this,
            tr("Open Streets"),
            "",
            tr("Text Files (*.txt)")
            );
        if (streetFileName.isEmpty()) return;

        MapIoFileinput *fileIn = new MapIoFileinput(cityFileName, streetFileName);
        this->mapio = fileIn;
        this->mapio->fillMap(*(this->map));
        this->map->draw(*(this->scene));

}

