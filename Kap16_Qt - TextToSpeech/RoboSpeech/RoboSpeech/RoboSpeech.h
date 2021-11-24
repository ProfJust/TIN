#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_RoboSpeech.h"
#include <QTextToSpeech>
#include <QPushButton>
#include <QDebug>

class RoboSpeech : public QMainWindow
{
    Q_OBJECT

public:
    RoboSpeech(QWidget *parent = Q_NULLPTR);
    QPushButton* btn_speak;
    QPushButton* btn_rede;
    QTextToSpeech* speech;

public slots:
    void speak();
    void rede();

private:
    Ui::RoboSpeechClass ui;
};

/*  QTextToSpeech* m_speech;
  QVector<QVoice> m_voices;*/