#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my_fune();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::my_fune()
{
    bool op1,op2,res;
    op1 = (ui->comboBox_op1->currentIndex()==0);
    op2 = (ui->comboBox_op2->currentIndex()==0);
    int index = ui->comboBox_operacii->currentIndex();
    switch (index) {
    case 0://Дизьюнкция
        res = op1 || op2;
        ui->comboBox_op2->setVisible(true);//Показали OP2.
        break;
    case 1://Коньюкция
        res = op1 && op2;
        ui->comboBox_op2->setVisible(true);//Показали OP2.
        break;
    case 2://Эквиваленция
        res = op1 == op2;
        ui->comboBox_op2->setVisible(true);//Показали OP2.
        break;
    case 3://Исключающее ИЛИ
        res = op1^op2;
        ui->comboBox_op2->setVisible(true);//Показали OP2.
        break;
    case 4://Импликация
        if (op1 == 1 && op2 ==0)
        {
            res=0;
        }
        else {
            res=1;
        }
        ui->comboBox_op2->setVisible(true);//Показали OP2.
        break;
    case 5://Инверсия
        res = !op1;
        ui->comboBox_op2->setVisible(false);//Спрятали OP2.
        break;
    }
    QPalette pal = ui->centralWidget->palette();
    if(res)
    {
        pal.setColor(QPalette::Window,Qt::green);
    }
    else
    {
        pal.setColor(QPalette::Window,Qt::red);
    }
    ui->centralWidget->setAutoFillBackground(true);
    ui->centralWidget->setPalette(pal);
}
void MainWindow::on_comboBox_op1_currentIndexChanged(int index)
{
    my_fune();
}

void MainWindow::on_comboBox_operacii_currentIndexChanged(int index)
{
    my_fune();
}

void MainWindow::on_comboBox_op2_currentIndexChanged(int index)
{
    my_fune();
}
