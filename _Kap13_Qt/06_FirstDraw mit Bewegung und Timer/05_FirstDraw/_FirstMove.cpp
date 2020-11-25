#include "_FirstMove.h"

//--- Konstruktor -----
_FirstDraw::_FirstDraw(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	// create a timer
	timer = new QTimer(this);
	timer->setInterval(20);
	// Verbinden des Timers mit der Funktion MyTimerSlot() 
	connect(timer, SIGNAL(timeout()), this, SLOT(MyTimerSlot()), Qt::UniqueConnection);
	timer->start();
}

void _FirstDraw::paintEvent(QPaintEvent *e)
{
	this->setFixedSize(500,900);  //width , height
	this->setWindowTitle("TIN - First Move mit QT");
	zeichne();  //Aufruf der Zeichenfunktion
}


void _FirstDraw::zeichne()
{
	//QPainter p(this);
	
	// Zeichne roten Kreis
	p.setPen(Qt::black);
	p.setBrush(Qt::red);
	p.drawEllipse(pos_x, pos_y, 20, 20);	

	// Textausgabe
	char str[40];
	sprintf(str, "  pos_x: %5d     pos_y: %5d", pos_x, pos_y);
	QStaticText m_staticText(str);  //Eine Text-Objekt instanzieren
	QFont myFont;

	p.setPen(Qt::darkBlue);
	myFont.setPixelSize(20);
	p.setFont(myFont);
	p.drawStaticText(20, 10, m_staticText);		
}



// Funktion, die über den Timer immer wieder aufgerufen wird
void _FirstDraw::MyTimerSlot()
{	
	//Neue Position des Balls
	pos_x += 1;
	pos_y += 2;

	// statt cout hier qDebug
	qDebug() << "\n aktuelle Position" << pos_x << " " << pos_y;

	//Widgets neu zeichnen
	repaint();

}
