#include "configuration.h"

#include <QJsonObject>


Configuration::Configuration()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "calculator.conf";
    QFile file(path);
    if (file.exists()) {
        file.open(QFile::ReadOnly);
        QTextStream stream(&file);
        int displayed = 0;
        stream >> displayed >> numbersAfterPoint;
        isAdditionalButtonsDisplayed = displayed == 1;
        file.close();
    }
}

Configuration::~Configuration()
{

}
