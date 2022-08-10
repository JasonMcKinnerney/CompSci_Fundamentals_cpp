#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QDial>
#include <QSlider>
#include <QSpinBox>
#include <QLabel>
#include <QLCDNumber>
#include <QRadioButton>
#include <QGroupBox>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QSpinBox *spinBox1;
    QSlider *slider1;
    QSlider *slider2;
    QDial *dial;
    QPushButton *button;
    QLCDNumber *num2;
public slots:
    void runSim();

};

class Simulator {


public:

struct station {

public:

    std::string name;
    int location;
    bool idle;
    int busyStatTime;



};

struct carrier {

public:
    int length;
    bool busy;
    int busyTime;
    void recieve();

};

struct message {

    public:

    std::string senderName;
    std::string recieverName;
    int senderLoc;
    int recieverLoc;
    int length;
    };
};


#endif // WIDGET_H
