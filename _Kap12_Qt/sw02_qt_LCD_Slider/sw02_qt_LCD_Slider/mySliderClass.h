#pragma once
#include <QSlider>

//Erweitere QSlider - Widget um die Funktionen plus() und minus()
class mySliderClass : public QSlider {
	Q_OBJECT
public:
	//Konstruktor erbt Parameter von Elternklasse
	mySliderClass(Qt::Orientation orientation, QWidget *parent = Q_NULLPTR) : QSlider(orientation, parent) {}

	//--- hinzufügen von eigenen Slots und Signals
	public slots :
		void plus() {
		//vgl http://doc.qt.io/qt-5/qslider-members.html
		int wert = value();
		wert++;
		setValue(wert);
		repaint();
	}
	void minus() {
		int wert = value();
		wert--;
		setValue(wert);
		repaint();
	}

};