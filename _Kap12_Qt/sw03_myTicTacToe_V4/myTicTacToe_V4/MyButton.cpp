#include "MyButton.h"
#include <QPushButton>

//--- Überladen des Konstruktors ----
MyButton::MyButton(const int i, const int j, QWidget* parent)
	: QPushButton(parent)
{
	btnReihe = i;
	btnSpalte = j;
	owner = noOwner;
}
//--- Der Destruktor ----
MyButton::~MyButton()
{
}


