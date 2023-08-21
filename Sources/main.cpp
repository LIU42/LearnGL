#include "mainwindow.h"

void setHighDPIScalePolicy()
{
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Floor);
}

int main(int argc, char *argv[])
{
    setHighDPIScalePolicy();

    QApplication app(argc, argv);
    MainWindow window;

    window.init();
    window.show();

    return app.exec();
}