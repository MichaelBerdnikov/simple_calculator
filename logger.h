#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>

class Logger : public QObject
{
private:
    Logger();
    ~Logger();

    QFile file;
    QTextStream stream;
    bool loggingEnabled = true;

    Q_OBJECT
public:
    static Logger& getInstance() {
        static Logger logger;
        return logger;
    }

    void info(const QString& message, int computationTime = -1);

public slots:
    void onLogFilePathChanged(const QString& newPath);
};

#endif // LOGGER_H
