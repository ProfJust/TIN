#ifndef MYTIMER_H
#define MYTIMER_H

#include <QTimer>
#include "qtimer.h"
#include "primegame_maingui.h"


class MyTimer : public QObject

{
	Q_OBJECT
		bool gameoverOutput;

public:
	MyTimer();
	QTimer *timer;
	void MyTimer::getApplication(PrimeGame_MainGUI* application);

	public slots: void MyTimerSlot();
};

#endif // MYTIMER_H