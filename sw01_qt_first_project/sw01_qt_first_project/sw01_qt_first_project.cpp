#include "sw01_qt_first_project.h"

//-------------- Konstruktor der Klasse -----------
sw01_qt_first_project::sw01_qt_first_project(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// --- Button konstruieren ---
	myButton = new QPushButton(this);
	myButton->setGeometry(50,30,200,40); //x,y,w,h
	myButton->setText(" TIN goes Qt");

	// Signal mit Slot verbinden
	this->connect(myButton, SIGNAL(clicked()), this, SLOT(myButtonSlotFkt()));
}

// ---- Slot-Funktion ----
void sw01_qt_first_project::myButtonSlotFkt()
{	
	myButton->setText(" Clicked!");
	
}