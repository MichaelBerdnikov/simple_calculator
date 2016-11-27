#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QStandardPaths>

class Configuration
{
private:
    Configuration();
    ~Configuration();
public:
    int numbersAfterPoint = 0;
    bool isAdditionalButtonsDisplayed = true;
    QString logPath = QStandardPaths::writableLocation(QStandardPaths::TempLocation) + "log.txt";

    static Configuration& getInstance() {
        static Configuration configuration;
        return configuration;
    }

    static void save() {
        QString path = QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "calculator.conf";
        QFile file(path);
        file.open(QFile::WriteOnly);
        QTextStream stream(&file);
        int displayed = Configuration::getInstance().isAdditionalButtonsDisplayed ? 1 : 0;
        stream << displayed << " " << Configuration::getInstance().numbersAfterPoint << " " << Configuration::getInstance().logPath;
        file.close();
    }

};

#endif // CONFIGURATION_H
