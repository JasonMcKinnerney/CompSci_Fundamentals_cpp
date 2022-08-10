#include "widget.h"
#include <QGridLayout>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <fstream>

Widget::Widget(QWidget *parent)
    : QWidget(parent) {

    QGridLayout *layout = new QGridLayout(this);
    //Input Widgets: Format Outlined on 1st input
    //1st input - Length of Cable (7-99 odd), Spinbox
    QLabel *label1 = new QLabel;                // Label Creation and string set
    label1->setText("Length of Cable");
    QLCDNumber *num1 = new QLCDNumber();        // LCD Number Creation and default value
    num1->display(7);
    spinBox1 = new QSpinBox;          // Widget Creation and range set
    spinBox1->setRange(7, 99);
    spinBox1->setSingleStep(2);

    //2nd input - Max Length of Message (1-5), Radio Button Group
    QLabel *label2 = new QLabel;
    label2->setText("Max Length of Message");
    num2 = new QLCDNumber();
    num2->display(1);

    QRadioButton *radio1 = new QRadioButton(("1"));
    QRadioButton *radio2 = new QRadioButton(("2"));
    QRadioButton *radio3 = new QRadioButton(("3"));
    QRadioButton *radio4 = new QRadioButton(("4"));
    QRadioButton *radio5 = new QRadioButton(("5"));
    radio1->setChecked(true);

    QGroupBox *radioBox = new QGroupBox;            //Group Box containing all radio buttons
    QButtonGroup *radioGroup = new QButtonGroup;
    QVBoxLayout *radioVBox = new QVBoxLayout;

    radioGroup -> addButton(radio1,1);
    radioGroup -> addButton(radio2,2);
    radioGroup -> addButton(radio3,3);
    radioGroup -> addButton(radio4,4);
    radioGroup -> addButton(radio5,5);

    radioVBox -> addWidget(radio1);
    radioVBox -> addWidget(radio2);
    radioVBox -> addWidget(radio3);
    radioVBox -> addWidget(radio4);
    radioVBox -> addWidget(radio5);
    radioVBox -> addStretch(1);
    radioVBox -> setAlignment(Qt::AlignCenter);
    radioBox -> setLayout(radioVBox);


    //3rd input - Probability 10-50% - QDial
    QLabel *label3 = new QLabel;
    label3->setText("Probability (Percent)");
    QLCDNumber *num3 = new QLCDNumber();
    num3->display(10);
    dial = new QDial();
    dial->setRange(10, 50);

    //4th input - Maximum Ticks Sensing 1-5 - Horizontal Slider
    QLabel *label4 = new QLabel;
    label4->setText("Maximum Ticks Sensing");
    QLCDNumber *num4 = new QLCDNumber();
    num4->display(1);
    slider1 = new QSlider(Qt::Horizontal);
    slider1->setRange(1,5);

    //5th input - Number of Ticks - Vertical Slider
    QLabel *label5 = new QLabel;
    label5->setText("Number of Ticks");
    QLCDNumber *num5 = new QLCDNumber();
    num5->display(3000);
    slider2 = new QSlider(Qt::Vertical);
    slider2->setRange(3000,10000);


    // LCD Numbers style changes, create function for future
    num1->setMode(QLCDNumber::Dec);
    num1->setPalette(Qt::black);
    num1->setStyleSheet("background: white");
    num2->setMode(QLCDNumber::Dec);
    num2->setPalette(Qt::black);
    num2->setStyleSheet("background: white");
    num3->setMode(QLCDNumber::Dec);
    num3->setPalette(Qt::black);
    num3->setStyleSheet("background: white");
    num4->setMode(QLCDNumber::Dec);
    num4->setPalette(Qt::black);
    num4->setStyleSheet("background: white");
    num5->setMode(QLCDNumber::Dec);
    num5->setPalette(Qt::black);
    num5->setStyleSheet("background: white");


    // Connecting LCD Screens to input widgets
    QObject::connect(spinBox1, SIGNAL(valueChanged(int)),
    num1, SLOT(display(int)));
    QObject::connect(radioGroup, SIGNAL(idToggled(int,bool)),
    num2, SLOT(display(int)));
    QObject::connect(dial, SIGNAL(valueChanged(int)),
    num3, SLOT(display(int)));
    QObject::connect(slider1, SIGNAL(valueChanged(int)),
    num4, SLOT(display(int)));
    QObject::connect(slider2, SIGNAL(valueChanged(int)),
    num5, SLOT(display(int)));



    //Forming execution button
    button = new QPushButton("Execute", this);

    // Connect button signal to appropriate slot


    //Forming Grid Layout, adding input widgets (divided into respective columns),

    layout->addWidget(num1, 0, 0);
    layout->addWidget(spinBox1, 1, 0);
    layout->addWidget(label1, 2, 0);

    layout->addWidget(num2, 0, 1);
    layout->addWidget(radioBox, 1, 1, Qt::AlignCenter);
    layout->addWidget(label2, 2, 1);

    layout->addWidget(num3, 0, 2);
    layout->addWidget(dial, 1, 2);
    layout->addWidget(label3, 2, 2);

    layout->addWidget(num4, 0, 3);
    layout->addWidget(slider1, 1, 3);
    layout->addWidget(label4, 2, 3, Qt::AlignCenter);

    layout->addWidget(num5, 0, 4);
    layout->addWidget(slider2, 1, 4);
    layout->addWidget(label5, 2, 4);

    layout->addWidget(button, 3, 4);

    setLayout(layout);

    QObject::connect(button, SIGNAL(clicked()),
    this, SLOT(runSim()));
}

void Widget::runSim() {

    int cableLength, messLength, prob, senseTicks, maxTicks;
    cableLength = spinBox1->value();
    messLength = num2->intValue();
    prob = dial->value();
    senseTicks = slider1->value();
    maxTicks = slider2->value();

    QTextStream out(stdout);
    QString filename = "Test2.csv";
    QFile file(filename);

    int ticks = 0;
     Simulator::station phone[3];

     phone[0].name = "S1";
     phone[1].name = "S2";
     phone[2].name = "S3";

     phone[0].location = 1;
     phone[1].location = ((cableLength + 1) / 2);
     phone[2].location = cableLength;

     for (int i = 0; i < 3; i++) {
         phone[i].idle = true;

     }

     Simulator::carrier phoneLine;

     phoneLine.length = cableLength;
     phoneLine.busy = false;
     phoneLine.busyTime = 0;


     srand (time(NULL));
     int probTot = 100;
     Simulator::message messWaiting[3];

if (file.open(QIODevice::WriteOnly)) {
  QTextStream out(&file);
     while (ticks < maxTicks) {
         for (int i = 0; i < 3; i++) {
             if (phone[i].idle == true) {
                 int chance = (rand() % (100 + 1));
                 if (chance <= prob) {
                     bool different = false;
                     while (different == false) {
                         int statSel = (rand() % (3));
                         if (statSel != i) {
                             different = true;
                             messWaiting[i].senderName = phone[i].name;
                             messWaiting[i].recieverName = phone[statSel].name;
                             messWaiting[i].senderLoc = phone[i].location;
                             messWaiting[i].recieverLoc = phone[statSel].location;
                             messWaiting[i].length = ((rand() % messLength) + 1);
                             phone[i].idle = false;
                             phone[i].busyStatTime = 0;
                         }
                     }
                 }
             }
         }

         for (int i = 0; i < 3; i++) {
             if (phoneLine.busy == false && phone[i].busyStatTime == 0) {
                   int number = (ticks + (abs(messWaiting[i].recieverLoc - messWaiting[i].senderLoc) + messWaiting[i].length));
                   int messLength = messWaiting[i].length;
                   QString tempSen = QString::fromUtf8(messWaiting[i].senderName);
                   QString tempRec = QString::fromUtf8(messWaiting[i].recieverName);

                   out << number << "," << tempSen << "," << tempRec << "," << messLength << Qt::endl;


                     phoneLine.busyTime = (abs(messWaiting[i].recieverLoc - messWaiting[i].senderLoc) + messWaiting[i].length);
                     phone[i].idle = true;
                     phoneLine.busy = true;
                 }
             else {
                 if (phone[i].busyStatTime > 0) {
                     phone[i].busyStatTime = (phone[i].busyStatTime) - 1;
                 }
                 else {phone[i].busyStatTime = (rand() % senseTicks) + 1;
                 }
             }
         }
         if (phoneLine.busyTime > 0) {
             phoneLine.busyTime--;
         }
         else {phoneLine.busy = false;
         }


         ticks++;
     }
file.close();
}
}

Widget::~Widget()
{
}

