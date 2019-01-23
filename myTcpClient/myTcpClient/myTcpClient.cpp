#include "myTcpClient.h"

myTcpClient::myTcpClient(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//Label instanziieren und konfigurieren
	lbl = new QLabel(this);
	lbl->setText(" Label zur Ausgabe von Text ");
	lbl->setGeometry(10, 40, 500, 50);
	this->connect();
}

//-- Funktion zum Senden einer Anfrage an den Server --
void myTcpClient::connect() {
	//Instanzieren einer TcpSocket
	socket = new QTcpSocket(this);
	// Verbinden ueber die IP localhost, Port 80
	socket->connectToHost("localhost", 80);
	//Wartezeit bis Verbidnung etabliert
	if (socket->waitForConnected(3000)) {
		lbl->setText(" Verbindung steht !" );
		// Anfrage an Server senden
		socket->write("Hallo Server, wie ist das Wetter heute? \r\n");
		socket->waitForBytesWritten(1000);
		// Warte auf Antwort
		socket->waitForReadyRead(3000);
		// Antwort auf Label schreiben
		lbl->setText(socket->readAll());
		socket->close();
	}
	else 
		lbl->setText("Keine Verbindung !");
}

