#include "_FirstDraw.h"

_FirstDraw::_FirstDraw(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}



void _FirstDraw::paintEvent(QPaintEvent *e)
{
	this->setFixedSize(500,400);  //width , height
	this->setWindowTitle("TIN - First Draw mit QT");
	zeichne();  //Aufruf der Zeichenfunktion
}



void _FirstDraw::zeichne()
{
	QPainter p(this);
	
	// Zeichne grünen Punkt
	p.setBrush(Qt::green);
	p.drawPoint(250, 200); //Genau in die Mitte der Grafik

	//Zeichne Linie
	p.setPen(Qt::red);
	p.drawLine(10, 10, 450, 300);
	
	
	// Zeichne blaues Rechteck
	p.setPen(Qt::green);
	p.setBrush(Qt::blue);
	p.drawRect(10, 10, 100, 80);

	// Zeichne roten Kreis
	p.setPen(Qt::black);
	p.setBrush(Qt::red);
	p.drawEllipse(100, 150, 20, 20);
	
	// karierte Ellipse
	p.setPen(QPen(Qt::black, 4, Qt::DashDotLine, Qt::RoundCap));
	p.setBrush(QBrush(Qt::darkCyan, Qt::CrossPattern));
	p.drawEllipse(200, 200, 100, 50);

	// Zeichne Kuchendiagramm
	p.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
	p.setBrush(QBrush(Qt::darkCyan, Qt::Dense2Pattern));
	p.drawPie(100, 300, 100, 100, 0, 900);
	p.setBrush(QBrush(Qt::red, Qt::Dense4Pattern));
	p.drawPie(100, 300, 100, 100, 900, 300);

	// Textausgabe
	p.setPen(Qt::darkBlue);
	QStaticText m_staticText("TIN goes Qt");  //Eine Text-Objekt instanzieren
	QFont myFont;

	myFont.setUnderline(true);
	myFont.setPixelSize(40);
	p.setFont(myFont);
	p.drawStaticText(200, 10, m_staticText);

}

