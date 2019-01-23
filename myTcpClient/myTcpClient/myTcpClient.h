#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_myTcpClient.h"
#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QLabel>

class myTcpClient : public QMainWindow
{
	Q_OBJECT

public:
	myTcpClient(QWidget *parent = Q_NULLPTR);
	void connect();
	QLabel * lbl;

private:
	QTcpSocket *socket;
	Ui::myTcpClientClass ui;
};
