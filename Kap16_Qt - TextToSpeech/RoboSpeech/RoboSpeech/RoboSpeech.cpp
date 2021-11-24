#include "RoboSpeech.h"
// https://www.ics.com/blog/text-speech-look-qt-speech-module
RoboSpeech::RoboSpeech(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    btn_speak = new QPushButton(this);
    btn_speak->setGeometry(10, 10, 200, 40);
    btn_speak->setText(" Speak! ");
    connect(btn_speak, SIGNAL(clicked()), this, SLOT(speak()));

    btn_rede = new QPushButton(this);
    btn_rede->setGeometry(10, 50, 200, 40);
    btn_rede->setText(" Rede! ");
    connect(btn_rede, SIGNAL(clicked()), this, SLOT(rede()));
}   

void RoboSpeech::speak()
{
    // Create an instance using the default engine/plugin.
    speech = new QTextToSpeech();
    // Set locale.
    speech->setLocale(QLocale(QLocale::English, QLocale::LatinScript, QLocale::UnitedStates));
    // Say something.
    speech->say("Hello, world! This is the module technical computer science at the bocholt campus.");    
}

void RoboSpeech::rede()
{  
    // Create an instance using the default engine/plugin.
    speech = new QTextToSpeech();
    // Set locale.
    speech->setLocale(QLocale(QLocale::German, QLocale::LatinScript, QLocale::Germany));
    // Say something.
    speech->say("Hallo Welt! Dies ist das Modul Technische Informatik am Campus Bocholt.");
}


//// List the available engines.
//   QStringList engines = QTextToSpeech::availableEngines();
//   qDebug() << "Available engines:";
//   for (auto engine : engines) {
//       qDebug() << "  " << engine;
//   }
//
//   // List the available locales.
//   qDebug() << "Available locales:";
//   for (auto locale : speech->availableLocales()) {
//       qDebug() << "  " << locale;
//   }
//   // Set locale.
//   speech->setLocale(QLocale(QLocale::English, QLocale::LatinScript, QLocale::UnitedStates));
//   // List the available voices.
//   qDebug() << "Available voices:";
//   for (auto voice : speech->availableVoices()) {
//       qDebug() << "  " << voice.name();
//   }
//
//   // Display properties.
//   qDebug() << "Locale:" << speech->locale();
//   qDebug() << "Pitch:" << speech->pitch();
//   qDebug() << "Rate:" << speech->rate();
//   qDebug() << "Voice:" << speech->voice().name();
//   qDebug() << "Volume:" << speech->volume();
//   qDebug() << "State:" << speech->state();   

