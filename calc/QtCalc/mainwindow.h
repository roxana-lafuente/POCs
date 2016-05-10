#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void clear();
    void clearAll();
    void equals();
    void add();
    void substract();
    void multiply();
    void divide();
    void zero();
    void one();
    void two();
    void three();
    void four();
    void five();
    void six();
    void seven();
    void eight();
    void nine();

private:
    QLabel * visor;
    QPushButton * clearButton;
    QPushButton * clearAllButton;
    QPushButton * equalsButton;
    QPushButton * addButton;
    QPushButton * substractButton;
    QPushButton * multiplyButton;
    QPushButton * divideButton;
    QPushButton * zeroButton;
    QPushButton * oneButton;
    QPushButton * twoButton;
    QPushButton * threeButton;
    QPushButton * fourButton;
    QPushButton * fiveButton;
    QPushButton * sixButton;
    QPushButton * sevenButton;
    QPushButton * eightButton;
    QPushButton * nineButton;

};

#endif // MAINWINDOW_H
