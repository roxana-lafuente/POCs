#include <QApplication>
#include <QDesktopWidget>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // Set Window title.
    w.setWindowTitle("QtCalc");
    // QtCalc window will have a fixed size.
    w.setFixedSize(300, 400);
    // QtCalc window will appear on the center of the screen.
    w.move(QApplication::desktop()->screen()->rect().center() - w.rect().center());
    w.show();
    
    return a.exec();
}
