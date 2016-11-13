#include "configuration.h"


Configuration::Configuration()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "calculator.conf";
    QFile file(path);
    if (file.exists()) {
        file.open(QFile::ReadOnly);
        QTextStream stream(&file);
        int displayed = Configuration::getInstance().isAdditionalButtonsDisplayed ? 1 : 0;
        stream >> displayed >> Configuration::getInstance().numbersAfterPoint;
        file.close();
    }
}

Configuration::~Configuration()
{

}
