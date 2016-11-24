#include "logger.h"
#include <QIODevice>
#include <QTime>
#include "configuration.h"

Logger::Logger()
{
    file.setFileName(Configuration::getInstance().logPath);
    file.open(QIODevice::Append);
    stream.setDevice(&file);
}

void Logger::info(const QString &message, int computationTime)
{
    if (!loggingEnabled) return;
    stream << "[INFO] "
           << QTime::currentTime().toString("hh:mm:ss.zzz") << " "
           << message << " "
           << (computationTime >= 0 ? ". Computation took " + QString::number(computationTime) + " ms." : "")
           << "\r\n";
}

void Logger::onLogFilePathChanged(const QString &newPath)
{
    file.close();
    file.setFileName(newPath);
    file.open(QIODevice::Append);
    stream.setDevice(&file);
}

Logger::~Logger()
{
    file.close();
}
