#include <QtCore/QCoreApplication>
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"

QString tmpValue = "";
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
    visor->setGeometry(QRect(QPoint(25,15), QSize(250, 50)));
    visor->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    visor->setStyleSheet("font-weight: bold; color: black");

    /* Clear Button */
    clearButton = new QPushButton("C", this);
    clearButton->setGeometry(QRect(QPoint(125, 80), QSize(75,50)));
    // when clearButton is released, connect it with clear call.
    connect(clearButton, SIGNAL(released()), this, SLOT(clear()));

    /* Clear All Button */
    clearAllButton = new QPushButton("CE", this);
    clearAllButton->setGeometry(QRect(QPoint(25, 80), QSize(75,50)));
    connect(clearButton, SIGNAL(released()), this, SLOT(clearAll()));

    /* Equals Button */
    equalsButton = new QPushButton("=", this);
    equalsButton->setGeometry(QRect(QPoint(225, 80), QSize(50,50)));
    connect(equalsButton, SIGNAL(released()), this, SLOT(equals()));

    /* Add Button */
    addButton = new QPushButton("+", this);
    addButton->setGeometry(QRect(QPoint(225, 140), QSize(50,50)));
    connect(addButton, SIGNAL(released()), this, SLOT(add()));

    /* Substract Button */
    substractButton = new QPushButton("-", this);
    substractButton->setGeometry(QRect(QPoint(225, 200), QSize(50,50)));
    connect(substractButton, SIGNAL(released()), this, SLOT(substract()));

    /* Multiply Button */
    multiplyButton = new QPushButton("*", this);
    multiplyButton->setGeometry(QRect(QPoint(225, 260), QSize(50,50)));
    connect(multiplyButton, SIGNAL(released()), this, SLOT(multiply()));

    /* Divide Button */
    equalsButton = new QPushButton("/", this);
    equalsButton->setGeometry(QRect(QPoint(225, 320), QSize(50,50)));
    connect(equalsButton, SIGNAL(released()), this, SLOT(equals()));

    /* Zero Button */
    divideButton = new QPushButton("0", this);
    divideButton->setGeometry(QRect(QPoint(30, 315), QSize(100,50)));
    connect(divideButton, SIGNAL(released()), this, SLOT(divide()));

    /* One Button */
    oneButton = new QPushButton("1", this);
    oneButton->setGeometry(QRect(QPoint(30, 260), QSize(50,50)));
    connect(oneButton, SIGNAL(released()), this, SLOT(one()));

    /* Two Button */
    twoButton = new QPushButton("2", this);
    twoButton->setGeometry(QRect(QPoint(85, 260), QSize(50,50)));
    connect(twoButton, SIGNAL(released()), this, SLOT(two()));

    /* Three Button */
    threeButton = new QPushButton("3", this);
    threeButton->setGeometry(QRect(QPoint(140, 260), QSize(50,50)));
    connect(threeButton, SIGNAL(released()), this, SLOT(three()));

    /* Four Button */
    fourButton = new QPushButton("4", this);
    fourButton->setGeometry(QRect(QPoint(30, 205), QSize(50,50)));
    connect(fourButton, SIGNAL(released()), this, SLOT(four()));

    /* Five Button */
    fiveButton = new QPushButton("5", this);
    fiveButton->setGeometry(QRect(QPoint(85, 205), QSize(50,50)));
    connect(fiveButton, SIGNAL(released()), this, SLOT(five()));

    /* Six Button */
    sixButton = new QPushButton("6", this);
    sixButton->setGeometry(QRect(QPoint(140, 205), QSize(50,50)));
    connect(sixButton, SIGNAL(released()), this, SLOT(six()));

    /* Seven Button */
    sevenButton = new QPushButton("7", this);
    sevenButton->setGeometry(QRect(QPoint(30, 150), QSize(50,50)));
    connect(sevenButton, SIGNAL(released()), this, SLOT(seven()));

    /* Eight Button */
    eightButton = new QPushButton("8", this);
    eightButton->setGeometry(QRect(QPoint(85, 150), QSize(50,50)));
    connect(eightButton, SIGNAL(released()), this, SLOT(eight()));

    /* Nine Button */
    nineButton = new QPushButton("9", this);
    nineButton->setGeometry(QRect(QPoint(140, 150), QSize(50,50)));
    connect(nineButton, SIGNAL(released()), this, SLOT(nine()));
}

/* Clears the visor */
void MainWindow::clear()
{
    tmpValue = "";
    visor->setText(tmpValue);
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
    tmpValue = "";
    visor->setText(tmpValue);
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
    rhs = tmpValue.toDouble();
    if (addBool)
        total = QString::number(lhs+rhs);
    else if (substractBool)
        total = QString::number(lhs-rhs);
    else if (multiplyBool)
        total = QString::number(lhs*rhs);
    else if (divideBool)
        total = QString::number(lhs/rhs);
    else
        total = QString::number(lhs);
    visor->setText(total);
    // Clears temporal values.
    rhs = 0.0;
    lhs = 0.0;
    addBool = false;
    substractBool = false;
    multiplyBool = false;
    divideBool = false;
    tmpValue = total;
}

/* Add action */
void MainWindow::add()
{
    lhs = tmpValue.toDouble();
    tmpValue = "";
    visor->setText(tmpValue);
    addBool = true;
}

/* Substract action */
void MainWindow::substract()
{
    lhs = tmpValue.toDouble();
    tmpValue = "";
    visor->setText(tmpValue);
    substractBool = true;
}

/* Multiply action */
void MainWindow::multiply()
{
    lhs = tmpValue.toDouble();
    tmpValue = "";
    visor->setText(tmpValue);
    multiplyBool = true;
}

/* Divide action */
void MainWindow::divide()
{
    lhs = tmpValue.toDouble();
    tmpValue = "";
    visor->setText(tmpValue);
    divideBool = true;
}

/* Add Zero to visor */
void MainWindow::zero()
{
    tmpValue = tmpValue + "0";
    visor->setText(tmpValue);
}

/* Add One to visor */
void MainWindow::one()
{
    tmpValue = tmpValue + "1";
    visor->setText(tmpValue);
}

/* Add Two to visor */
void MainWindow::two()
{
    tmpValue = tmpValue + "2";
    visor->setText(tmpValue);
}

/* Add Three to visor */
void MainWindow::three()
{
    tmpValue = tmpValue + "3";
    visor->setText(tmpValue);
}

/* Add Four to visor */
void MainWindow::four()
{
    tmpValue = tmpValue + "4";
    visor->setText(tmpValue);
}

/* Add Five to visor */
void MainWindow::five()
{
    tmpValue = tmpValue + "5";
    visor->setText(tmpValue);
}

/* Add Six to visor */
void MainWindow::six()
{
    tmpValue = tmpValue + "6";
    visor->setText(tmpValue);
}

/* Add Seven to visor */
void MainWindow::seven()
{
    tmpValue = tmpValue + "7";
    visor->setText(tmpValue);
}

/* Add Eight to visor */
void MainWindow::eight()
{
    tmpValue = tmpValue + "8";
    visor->setText(tmpValue);
}

/* Add Nine to visor */
void MainWindow::nine()
{
    tmpValue = tmpValue + "9";
    visor->setText(tmpValue);
}

MainWindow::~MainWindow()
{
}
