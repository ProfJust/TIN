#pragma once

#include <QPushButton>
//Aufzählung der Möglichkeiten 
// Wem gehört das Spielfeld/Button
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


