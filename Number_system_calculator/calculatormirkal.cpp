#include "calculatormirkal.h"
#include "ui_calculatormirkal.h"

CalculatorMirKal::CalculatorMirKal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalculatorMirKal)
{
    ui->setupUi(this);
}

CalculatorMirKal::~CalculatorMirKal()
{
    delete ui;
}

void CalculatorMirKal::on_pushButton_name_clicked()
{
    QString text = ui->lineEdit_chislun->text();
    QString t1 = ui->lineEdit_t1->text();
    QString t2 = ui->lineEdit_t2->text();

    bool flag;
    bool flag1;
    bool flag2;

    int chislo1 = t1.toInt(&flag1);
    int chislo2 = t2.toInt(&flag2);
    int chislo = text.toInt(&flag,chislo1);

    if(flag == true and flag1 == true and flag2 == true)
    {
        text.setNum(chislo,chislo2);
        ui->label_text->setText(text);

    }
    else {
        ui->label_text->setText("Error 404");
    }

}
