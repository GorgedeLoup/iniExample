#include <QApplication>
#include <QtWidgets>
#include <QSettings>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    void WriteSettings();
    QStringList ReadSettings();

    QStringList m_config;
    m_config = ReadSettings();
    qDebug() << m_config;

    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *label1 = new QLabel();
    QLabel *label2 = new QLabel();

    layout->addWidget(label1);
    layout->addWidget(label2);
    widget->setLayout(layout);

    label1->setText(QString("Address:\n %1").arg(m_config.at(0)));
    label2->setText(QString("Port:\n %1").arg(m_config.at(1)));

    widget->show();

    WriteSettings();

    return a.exec();
}


void WriteSettings()
{
    QSettings *settings = new QSettings(":/Config/IPConfig.ini", QSettings::IniFormat);

    settings->setValue("UserIPConfiguration/Address", "192.168.31.1");
    settings->setValue("UserIPConfiguration/Port", "86");
    delete settings;
}


QStringList ReadSettings()
{
    QSettings *settings = new QSettings(":/Config/IPConfig.ini", QSettings::IniFormat);
    QStringList config;
    config << settings->value("IPConfiguration/Address").toString()
           << settings->value("IPConfiguration/Port").toString();
    delete settings;
    return config;
}
