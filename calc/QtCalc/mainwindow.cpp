#include <QtCore/QCoreApplication>
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"

QString value = "";
QString total = "";
double lhs, rhs; //left hand side and right hand side
bool addBool = false;
bool substractBool = false;
bool multiplyBool = false;
bool divideBool = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    /* Visor */
    visor = new QLabel("0", this);
    visor->setGeometry(QRect(QPoint(0,0), QSize(50, 150)));

    /* Clear Button */
    clearButton = new QPushButton("C", this);
    clearButton->setGeometry(QRect(QPoint(105, 100), QSize(75,50)));
    // when clearButton is released, connect it with clear call.
    connect(clearButton, SIGNAL(released()), this, SLOT(clear()));

    /* Clear All Button */
    clearAllButton = new QPushButton("CE", this);
    clearAllButton->setGeometry(QRect(QPoint(30, 100), QSize(75,50)));
    connect(clearButton, SIGNAL(released()), this, SLOT(clearAll()));

    /* Equals Button */
    equalsButton = new QPushButton("=", this);
    equalsButton->setGeometry(QRect(QPoint(225, 100), QSize(50,50)));
    connect(equalsButton, SIGNAL(released()), this, SLOT(equals()));

    /* Add Button */
    addButton = new QPushButton("+", this);
    addButton->setGeometry(QRect(QPoint(225, 150), QSize(50,50)));
    connect(addButton, SIGNAL(released()), this, SLOT(add()));

    /* Substract Button */
    substractButton = new QPushButton("-", this);
    substractButton->setGeometry(QRect(QPoint(225, 200), QSize(50,50)));
    connect(substractButton, SIGNAL(released()), this, SLOT(substract()));

    /* Multiply Button */
    multiplyButton = new QPushButton("*", this);
    multiplyButton->setGeometry(QRect(QPoint(225, 250), QSize(50,50)));
    connect(multiplyButton, SIGNAL(released()), this, SLOT(multiply()));

    /* Divide Button */
    equalsButton = new QPushButton("/", this);
    equalsButton->setGeometry(QRect(QPoint(225, 300), QSize(50,50)));
    connect(equalsButton, SIGNAL(released()), this, SLOT(equals()));

    /* Zero Button */
    divideButton = new QPushButton("0", this);
    divideButton->setGeometry(QRect(QPoint(30, 300), QSize(50,50)));
    connect(divideButton, SIGNAL(released()), this, SLOT(divide()));

    /* One Button */
    oneButton = new QPushButton("1", this);
    oneButton->setGeometry(QRect(QPoint(30, 250), QSize(50,50)));
    connect(oneButton, SIGNAL(released()), this, SLOT(one()));

    /* Two Button */
    twoButton = new QPushButton("2", this);
    twoButton->setGeometry(QRect(QPoint(80, 250), QSize(50,50)));
    connect(twoButton, SIGNAL(released()), this, SLOT(two()));

    /* Three Button */
    threeButton = new QPushButton("3", this);
    threeButton->setGeometry(QRect(QPoint(130, 250), QSize(50,50)));
    connect(threeButton, SIGNAL(released()), this, SLOT(three()));

    /* Four Button */
    fourButton = new QPushButton("4", this);
    fourButton->setGeometry(QRect(QPoint(30, 200), QSize(50,50)));
    connect(fourButton, SIGNAL(released()), this, SLOT(four()));

    /* Five Button */
    fiveButton = new QPushButton("5", this);
    fiveButton->setGeometry(QRect(QPoint(80, 200), QSize(50,50)));
    connect(fiveButton, SIGNAL(released()), this, SLOT(five()));

    /* Six Button */
    sixButton = new QPushButton("6", this);
    sixButton->setGeometry(QRect(QPoint(130, 200), QSize(50,50)));
    connect(sixButton, SIGNAL(released()), this, SLOT(six()));

    /* Seven Button */
    sevenButton = new QPushButton("7", this);
    sevenButton->setGeometry(QRect(QPoint(30, 150), QSize(50,50)));
    connect(sevenButton, SIGNAL(released()), this, SLOT(seven()));

    /* Eight Button */
    eightButton = new QPushButton("8", this);
    eightButton->setGeometry(QRect(QPoint(80, 150), QSize(50,50)));
    connect(eightButton, SIGNAL(released()), this, SLOT(eight()));

    /* Nine Button */
    nineButton = new QPushButton("9", this);
    nineButton->setGeometry(QRect(QPoint(130, 150), QSize(50,50)));
    connect(nineButton, SIGNAL(released()), this, SLOT(nine()));
}

/* Clears the visor */
void MainWindow::clear()
{
    value = "0";
    visor->setText(value);
    rhs = 0;
    lhs = 0;
    total = "";
    addBool = false;
    substractBool = false;
    multiplyBool = false;
    divideBool = false;
}

/* Clears the visor */
void MainWindow::clearAll()
{
    value = "0";
    visor->setText(value);
    rhs = 0;
    lhs = 0;
    total = "";
    addBool = false;
    substractBool = false;
    multiplyBool = false;
    divideBool = false;
}

/* Equal action */
void MainWindow::equals()
{
    rhs = value.toDouble();
    if (addBool)
        total = QString::number(lhs+rhs);
    else if (substractBool)
        total = QString::number(lhs-rhs);
    else if (multiplyBool)
        total = QString::number(lhs*rhs);
    else if (divideBool)
        total = QString::number(lhs/rhs);
    visor->setText(value);
    clear();
}

/* Add action */
void MainWindow::add()
{
    lhs = value.toDouble();
    value = "";
    visor->setText(value);
    addBool = true;
}

/* Substract action */
void MainWindow::substract()
{
    lhs = value.toDouble();
    value = "";
    visor->setText(value);
    substractBool = true;
}

/* Multiply action */
void MainWindow::multiply()
{
    lhs = value.toDouble();
    value = "";
    visor->setText(value);
    multiplyBool = true;
}

/* Divide action */
void MainWindow::divide()
{
    lhs = value.toDouble();
    value = "";
    visor->setText(value);
    divideBool = true;
}

/* Add Zero to visor */
void MainWindow::zero()
{
    value = value + "0";
    visor->setText(value);
}

/* Add One to visor */
void MainWindow::one()
{
    value = value + "1";
    visor->setText(value);
}

/* Add Two to visor */
void MainWindow::two()
{
    value = value + "2";
    visor->setText(value);
}

/* Add Three to visor */
void MainWindow::three()
{
    value = value + "3";
    visor->setText(value);
}

/* Add Four to visor */
void MainWindow::four()
{
    value = value + "4";
    visor->setText(value);
}

/* Add Five to visor */
void MainWindow::five()
{
    value = value + "5";
    visor->setText(value);
}

/* Add Six to visor */
void MainWindow::six()
{
    value = value + "6";
    visor->setText(value);
}

/* Add Seven to visor */
void MainWindow::seven()
{
    value = value + "7";
    visor->setText(value);
}

/* Add Eight to visor */
void MainWindow::eight()
{
    value = value + "8";
    visor->setText(value);
}

/* Add Nine to visor */
void MainWindow::nine()
{
    value = value + "9";
    visor->setText(value);
}

MainWindow::~MainWindow()
{
}
