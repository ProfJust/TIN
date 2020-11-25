#include "sw02_qt_LCD_Slider.h"
#include "mySliderClass.h"

//---- Konstruktor der Klasse ----------
sw02_qt_LCD_Slider::sw02_qt_LCD_Slider(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//---- Label instanzieren ---
	QLabel * myLabel = new QLabel(" WHS - TIN goes Qt ",this);
	// relative Position und Groesse
	myLabel->setGeometry(0, 20, 400, 20);  //(x,y)der linken unteren Ecke +(w,h)
	// Schriftart 
	myLabel->setFont(QFont("Helvetica", 10, QFont::Normal));

	//--- Schieber instanzieren ---
	//QSlider * mySlider = new QSlider(Qt::Horizontal, this);
	mySliderClass * mySlider = new mySliderClass(Qt::Horizontal, this);
	mySlider->setMinimum(0);
	mySlider->setMaximum(99);
	mySlider->setValue(20);
	mySlider->setGeometry(10, 50, 180, 30);

	//--- LCD instanzieren ---
	QLCDNumber *myLCD = new QLCDNumber(2, this);
	myLCD->setGeometry(60, 100, 80, 50);
	myLCD->display(20);

	//---- Signal und Slot verbinden ---
	QObject::connect(mySlider, SIGNAL(valueChanged(int)),myLCD, SLOT(display(int)));
	//valueChanged(int) ist ein von der Klasse QSlider    bereitgestelltes SIGNAL
	//display(int)      ist ein von der Klasse QLCDNumber bereitgestellter SLOT

	//---- Button 1 -------------
	QPushButton * button1 = new QPushButton("<", this);
	// Position und Groesse
	button1->setGeometry(10, 110, 50, 30);
	button1->setFont(QFont("Helvetica", 18, QFont::Bold));
	// Signal mit Slot verbinden
	QObject::connect(button1, SIGNAL(clicked()), mySlider, SLOT(minus()));
	// eigener Slot minus() in mySliderClass

	//---- Button 2 -------------
	QPushButton * button2 = new QPushButton(">",this);

	// Position und Groesse
	button2->setGeometry(140, 110, 50, 30);
	button2->setFont(QFont("Helvetica", 18, QFont::Bold));

	// Signal mit Slot verbinden 
	QObject::connect(button2, SIGNAL(clicked()), mySlider, SLOT(plus()));
	// eigener Slot plus() in mySliderClass

	//----- PixMap mit WHS Label -----
	QLabel * lbl1 = new QLabel(this);
	lbl1->setGeometry(10, 180, 200, 53);
	QPixmap pix("WH_logo_CMYK_02.jpg");
	lbl1->setPixmap(pix);
	
}
