#include "Qt_Designer_Btn_LCD_Slider.h"

Qt_Designer_Btn_LCD_Slider::Qt_Designer_Btn_LCD_Slider(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void Qt_Designer_Btn_LCD_Slider::myMinusSlot()
{
	int aktWert = ui.horizontalSlider->value();
	aktWert -= 1;
	ui.horizontalSlider->setValue(aktWert);
	ui.lcdNumber->display(aktWert);

}
void Qt_Designer_Btn_LCD_Slider::myPlusSlot() {
	int aktWert = ui.horizontalSlider->value();
	aktWert += 1;
	ui.horizontalSlider->setValue(aktWert);
	ui.lcdNumber->display(aktWert);
}