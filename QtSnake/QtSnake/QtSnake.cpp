//------ QtSnake.cpp -----------
#include "QtSnake.h"

QtSnake::QtSnake(QWidget *parent)
	: QMainWindow(parent)
{ //Konstruktor
	ui.setupUi(this);

	this->setFixedSize(WINDOWSIZE_X, WINDOWSIZE_Y); //yo
	this->setWindowTitle("TIN - Qt Snake");

	//---create Label ---
	label = new QLabel(this);
	labelPos = new QLabel(this);
	QFont labelFont;
	labelFont.setPixelSize(16);
	label->setFont(labelFont);
	label->setText("Willkommen bei TIN - Qt - Snake");
	label->setGeometry(00, 10, WINDOWSIZE_X, 20);
	labelPos->setText("Position des Kopfes ");
	labelPos->setGeometry(600, 10, WINDOWSIZE_X, 20);

	//--- create  PushButton ---
	btn = new QPushButton(this);
	btn->setGeometry(400, 0, 100, 40);
	btn->setText("Start");
	connect(btn, SIGNAL(clicked()), this, SLOT(myBtnSlot()));

	//--- create a timer ---
	timer = new QTimer(this);
	//Verbinden des Timers mit der Funktion MyTimerSlot() 
	connect(timer, SIGNAL(timeout()), this, SLOT(myTimerSlot()), Qt::UniqueConnection);
	// Timer konfigurieren
	timer->setInterval(TIMER_INTERVALL);
	/*timer->start();*/

	//--- create Snake ----
	snake = new Snake(START_X, START_Y, RIGHT);

	//--- create Futter ---
	pille = new Futter;

}
void QtSnake::paintEvent(QPaintEvent *e) {
	p = new QPainter(this);
	p->setPen(Qt::black);
	p->setBrush(Qt::blue);

	//--- Pille zeichnen ---
	p->setBrush(Qt::red);
	p->drawRect(pille->x, pille->y, SN_EL_SIZE, SN_EL_SIZE);
	
	//--- Snake position ---
	SnakeGlied* pAkt = snake->pKopf;
	char str[40];
	sprintf(str, "x: %d  y: %d", pAkt->x, pAkt->y);
	labelPos->setText(str);
	
	//--- Snake zeichnen ----
	p->setBrush(Qt::blue);	//nur Kopf Blau
		do {
		// Quadrat zeichnen 
		p->drawRect(pAkt->x, pAkt->y, SN_EL_SIZE, SN_EL_SIZE);
		pAkt = pAkt->pNext; // nächstes Glied
		p->setBrush(Qt::green);

	} while (pAkt->x >= 0);   //pNext != NULL);
}
void QtSnake::myTimerSlot() {	
	
	GamePlay();
	repaint();
	GameOverCheck();
}
void QtSnake::myBtnSlot() {
	static bool start = true;
	if (start) {
		timer->start();
		btn->setText("Pause");
		start = false;
	}
	else
	{
		timer->stop();
		btn->setText("Start");
		start = true;
	}

}
void QtSnake::keyPressEvent(QKeyEvent *event){
	//--- WASD-Steuerung ---
	//180° Drehungen unterdrücken
	switch (event->key()) {
	case Qt::Key_W: 
		if(snake->dir != DOWN) 		snake->dir = UP;
		break;
	case Qt::Key_A: 
		if (snake->dir != RIGHT) 	snake->dir = LEFT;
		break;
	case Qt::Key_S: 
		if (snake->dir != UP)       snake->dir = DOWN;
		break;
	case Qt::Key_D: 
		if (snake->dir != LEFT) 	snake->dir = RIGHT;
		break;
	}
}
void QtSnake::GamePlay() {
	SnakeGlied *pAkt;   //Zeiger auf zu bearbeitendes Glied
	int Ax, Ay, Bx, By; //Positionspeicher vorherige Pos und temp. Merker

	pAkt = snake->pKopf; //Beginne mit dem Kopf
	Bx = pAkt->x;  //Merke Position
	By = pAkt->y;

	//neu Kopfposition bestimmen
	if (snake->dir == RIGHT) { Ax = Bx + SN_EL_SIZE; Ay = By; }
	if (snake->dir == LEFT) { Ax = Bx - SN_EL_SIZE; Ay = By; }
	if (snake->dir == UP) { Ax = Bx; Ay = By - SN_EL_SIZE; }
	if (snake->dir == DOWN) { Ax = Bx; Ay = By + SN_EL_SIZE; }

	//...und setzen
	pAkt->x = Ax;
	pAkt->y = Ay;
	//...Alte Position übergeben
	Ax = Bx;
	Ay = By;

	//Rumpf folgt dem Kopf
	while (pAkt->pNext->x >= 0) { //gibt es ein nächstes Glied?
		pAkt = pAkt->pNext; //gehe dorthin
		Bx = pAkt->x;  // merke Position
		By = pAkt->y;

		pAkt->x = Ax; //Position des vorherigen Gliedes einsetzen
		pAkt->y = Ay;

		Ax = Bx; //gemerkte Pos ist neue vorherige Position
		Ay = By;
	}

	// Futter erreicht?? 
	if (pille->x == snake->pKopf->x && pille->y == snake->pKopf->y) {
		label->setText("Lecker !!");
		QSound::play("Lecker.wav");
		//= > Snake verlängern
		//A, pAkt hat Pos. des bisher letzten El. vor d. Pos.wechsel
		pAkt->pNext = new SnakeGlied(Ax, Ay);
		//--- neue Futterposition (nur im SN_EL_SIZE-Raster)
		int rasterX = WINDOWSIZE_X / SN_EL_SIZE;
		pille->x = SN_EL_SIZE* (rand() % rasterX);
		pille->y = SN_EL_SIZE* (rand() % rasterX);
	}
	else {
		label->setText("Hunger !!");
	}
}
void QtSnake::GameOverCheck() {
	// Wände berührt?
	if (snake->pKopf->x < 0)			  GameOver(LINKS);
	if (snake->pKopf->x > WINDOWSIZE_X)   GameOver(RECHTS);
	if (snake->pKopf->y < 0)			  GameOver(OBEN);
	if (snake->pKopf->y > WINDOWSIZE_Y)   GameOver(UNTEN);

	//Prüfe ob Schlange sich selbts berührt
	SnakeGlied *pK = snake->pKopf;        //Vergleichszeiger 1
	SnakeGlied *pI = snake->pKopf->pNext; //Vergleichszeiger 2
	while(pI->x >=0) {
		if (pK->x == pI->x && pK->y == pI->y) //Kopf trifft Element pI
			GameOver(SELBST);
		else
			pI = pI->pNext; //nächste Element
	} 
}
void QtSnake::GameOver(GameOverTyp reason) {
	switch (reason) {
	case LINKS:
	case RECHTS:
	case UNTEN:
	case OBEN:
		label->setText("GAME OVER - an den Rand gestossen!");
		break;
	case SELBST:
		label->setText("GAME OVER - Eigenberuehrungt!");
	}	
	repaint();
	Sleep(5000);
	exit(0);
}