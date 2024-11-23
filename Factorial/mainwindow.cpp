#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);//Создаем интерфейс
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Функция факториала
double factorial(double n)
{
    //Если элемент равен 0 или 1, то возвращаем 1
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);//Рекурсивно вызываем функцию, т.к факториал это 3!=3*2!, 2!=2*1!, 1!=1 - база рекурсии, которая осуществляет выход из нее.
}
//Если нажимаем кнопку
void MainWindow::on_pushButton_clicked()
{
    bool flag;//Создаем флаг успешности преобразования
    int element = ui->lineEdit->text().toInt(&flag);//Считываем значение с lineedit и переводим из строки в число
    if(element<0)
    {
        //Ошибка если число отрицательное
        QMessageBox::information(this,"Внимание!","Число должно быть положительным!");
        return;
    }
    if(element>9999)
    {
        //Ошибка если число слишком большое
        ui->label_rez->setText("Ошибка бесконечности");
        return;
    }
    if(!flag)
    {
        //Ошибка если число некорректно
        QMessageBox::information(this,"Внимание!","Значение некорректно!");
        return;
    }
    else
    {
        //Если число подходит, то начинаем вычисления
        double res = factorial(element); //Вызов функции и запись результата
        if(qIsInf(res))
        {
            //Проверка на бесконечность
            ui->label_rez->setText("Ошибка бесконечности");
            return;
        }
        else if (qIsNaN(res))
        {
            //Проверка на пустоту
            ui->label_rez->setText("Ошибка пустоты");
            return;
        }
        else
        {
            //Записываем результат преобразовывая из числа в строку
            ui->label_rez->setText(QString::number(res));
        }
    }
}

