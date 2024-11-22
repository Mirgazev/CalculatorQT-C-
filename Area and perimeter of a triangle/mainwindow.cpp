#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "math.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_ploshad->setVisible(false); //Cкрываю пред.результат(другой способ).
    ui->label_perimetr->setVisible(false); //Cкрываю пред.результат(другой способ).
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//жмак кнопка
{
    double ugol,dl1,dl2,dl3,perimetr,ploshad,sinus,cosinus; //Ввожу значения
    QString stroka; //Строка для переобразования.
    bool flag,flag2,flag3; //Признак (флаг) успешности преобразования.

    dl1=ui->lineEdit_dl1->text().toDouble(&flag); //Преобразование стороны 1 с фор.флага
    dl2=ui->lineEdit_dl2->text().toDouble(&flag2); //Преобразование стороны 2 с фор.флага
    ugol=ui->lineEdit_ugol->text().toDouble(&flag3); //Преобразование угла с фор.флага

    if (!flag)//Проверяю значения стороны
    {
        QMessageBox::warning(this,"Ошибка!","Введите корректное значение первой стороны треугольника!!");
        ui->label_ploshad->setVisible(false); //Cкрываю пред.результат(другой способ).
        ui->label_perimetr->setVisible(false); //Cкрываю пред.результат(другой способ).
        return;
    }
    if (dl1<=0)//Проверяю длину стороны
    {
        QMessageBox::warning(this,"Ошибка!","Длина первой стороны должна быть больше нуля!");
        ui->label_ploshad->setVisible(false); //Cкрываю пред.результат(другой способ).
        ui->label_perimetr->setVisible(false); //Cкрываю пред.результат(другой способ).
        return;
    }
    if (!flag2)//Проверяю значения стороны
    {
        QMessageBox::warning(this,"Ошибка!","Введите корректное значение второй стороны треугольника!");
        ui->label_ploshad->setVisible(false); //Cкрываю пред.результат(другой способ).
        ui->label_perimetr->setVisible(false); //Cкрываю пред.результат(другой способ).
        return;
    }
    if (dl2<=0)//Проверяю длину стороны
    {
        QMessageBox::warning(this,"Ошибка!","Длина второй стороны должна быть больше нуля!");
        ui->label_ploshad->setVisible(false); //Cкрываю пред.результат(другой способ).
        ui->label_perimetr->setVisible(false); //Cкрываю пред.результат(другой способ).
        return;
    }
    if (!flag3)//Проверяю значение угла.
    {
        QMessageBox::warning(this,"Ошибка!","Введите корректное значение угла!");
        ui->label_ploshad->setVisible(false); //Cкрываю пред.результат(другой способ).
        ui->label_perimetr->setVisible(false); //Cкрываю пред.результат(другой способ).
        return;
    }
    if (ugol<=0 || ugol>=180)//Проверяю значение угла.
    {
        QMessageBox::warning(this,"Ошибка!","Значение угла должно быть в пределах 1° – 179°!");
        ui->label_ploshad->setVisible(false); //Cкрываю пред.результат(другой способ).
        ui->label_perimetr->setVisible(false); //Cкрываю пред.результат(другой способ).
        return;
    }

    //Расчеты площади ЛЕТСССС ГОУ
    sinus=sin(ugol * M_PI / 180);//Считаем синус в градусах
    ploshad= 0.5*dl1*dl2*sinus;//Считаем площадь
    ui->label_ploshad->setNum(ploshad);//Задаем значение площади
    ui->label_ploshad->show(); //show результат.

    //Расчет перимтра SO SAD:(
    cosinus=cos(ugol * M_PI / 180);//Считаем косинус в градусах
    if (ugol==90)//если угол равен 90
    {
        dl3= sqrt(dl1*dl1 + dl2*dl2);//shitaem dl3
        perimetr= dl1+dl2+dl3;//shitaem per
        ui->label_perimetr->setNum(perimetr);//Задаем значение perimetr
        ui->label_perimetr->show(); //show результат.
    }
    else
    {
        dl3=sqrt(dl1*dl1 + dl2*dl2 - 2*dl1*dl2*cosinus);//shitaem dl3
        perimetr= dl1+dl2+dl3;//shitaem per
        ui->label_perimetr->setNum(perimetr);//Задаем значение perimetr
        ui->label_perimetr->show(); //show результат.
    }
}
