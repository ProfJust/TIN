#pragma once

#include <QPushButton>
//Aufz�hlung der M�glichkeiten 
// Wem geh�rt das Spielfeld/Button
enum ownerTyp { noOwner, X, O}; 

class MyButton : public QPushButton
{
public:
	MyButton(const int, const int, QWidget* );
	~MyButton();
	//Position des Buttons im Array
	int btnReihe;
	int btnSpalte;
	ownerTyp owner;
};


