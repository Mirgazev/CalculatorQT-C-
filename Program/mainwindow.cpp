#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <stdlib.h>
#include <QTextEdit>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <QRandomGenerator>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_tabl_clicked()
{
    ui->tableWidget->setColumnCount(1);
    bool flag;
    int razmer = ui->lineEdit_kolvo->text().toInt(&flag);
    if (!flag)
    {
        QMessageBox::information(this,"Внимание","Данные введены не правильно");
        return;
    }
    if (razmer<1 or razmer>200 )
    {
        QMessageBox::information(this,"Внимание","кол-во элементов долдно быть от 1 до 200");
        return;
    }

    ui->tableWidget->setRowCount(razmer);
}


void MainWindow::on_pushButton_sl_clicked()
{

   int n_row = ui->tableWidget->rowCount();
    srand(clock());
    int chislo;
    QString stroka;
    for (int i=0;i<n_row;i++)
    {
        if (ui->tableWidget->item(i,0)==NULL)
        {
            QTableWidgetItem*  new_item;
            new_item = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,new_item);
        }
        chislo = rand()%201-100;
        stroka.setNum(chislo);
        ui->tableWidget->item(i,0)->setText(stroka);
    }
 ui->label_polog_100->clear();
 ui->label_sumch->clear();
 ui->label_sumnech->clear();
 ui->label_proiz_polog->clear();

}


void MainWindow::on_pushButton_sum_nech_clicked()
{
    int nech = ui->tableWidget->rowCount();
    int mas[nech];
    bool flag;
    for (int i = 0;i<nech;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag);

        }
        else
        {
            QMessageBox::information(this,"Внимание","пустая ячека");
            return;
        }
        if(!flag)
        {
            QMessageBox::information(this,"Внимание","ячейка должна содержать число");
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            return;
        }


    }
    double sum=0;
    for (int i =0;i<nech;i++)
    {
        if(mas[i] % 2 !=0)
        sum += mas[i];


    }
    ui->label_sumnech->setText(QString::number(sum));
}


void MainWindow::on_pushButton_sum_ch_clicked()
{
    int ch = ui->tableWidget->rowCount();
    int mas[ch];
    bool flag;
    for (int i = 0;i<ch;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag);

        }
        else
        {
            QMessageBox::information(this,"Внимание","пустая ячека");
            return;
        }
        if(!flag)
        {
            QMessageBox::information(this,"Внимание","ячейка должна содержать число");
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            return;
        }


    }
    double sum=0;
    for (int i =0;i<ch;i++)
    {
        if(mas[i]%2 == 0 )
        sum += mas[i];


    }
    ui->label_sumch->setText(QString::number(sum));
}


void MainWindow::on_pushButton_polog_100_clicked()
{
    int polog_100 = ui->tableWidget->rowCount();
    int mas[polog_100];
    bool flag;
    for (int i = 0;i<polog_100;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag);

        }
        else
        {
            QMessageBox::information(this,"Внимание","пустая ячека");
            return;
        }
        if(!flag)
        {
            QMessageBox::information(this,"Внимание","ячейка должна содержать число");
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            return;
        }


    }
    int k =0;
    for (int i =0;i<polog_100;i++)
    {
        if((mas[i]>0)and(mas[i]<100))
        k = k+1;


    }
    ui->label_polog_100->setText(QString::number(k));
}


void MainWindow::on_pushButton__proiz_polog_clicked()
{
    int proiz_polog = ui->tableWidget->rowCount();
    int mas[proiz_polog];
    bool flag;
    for (int i = 0;i<proiz_polog;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag);

        }
        else
        {
            QMessageBox::information(this,"Внимание","пустая ячека");
            return;
        }
        if(!flag)
        {
            QMessageBox::information(this,"Внимание","ячейка должна содержать число");
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            return;
        }


    }
    double proiz =1;
    for (int i =0;i<proiz_polog;i++)
    {
        if(mas[i]>0)

    proiz= proiz*mas[i];

    }
    ui->label_proiz_polog->setText(QString::number(proiz));
}


void MainWindow::on_pushButton_kolvo_otr_zn_clicked()
{
    int kolvo_otr_zn = ui->tableWidget->rowCount();
    int mas[kolvo_otr_zn];
    bool flag;
    for (int i = 0;i<kolvo_otr_zn;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag);

        }
        else
        {
            QMessageBox::information(this,"Внимание","пустая ячека");
            return;
        }
        if(!flag)
        {
            QMessageBox::information(this,"Внимание","ячейка должна содержать число");
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            return;
        }


    }
    double k =0;
    for (int i =0;i<kolvo_otr_zn;i++)
    {
        if(mas[i]<0)

    k=k+1;

    }
    ui->label_kolvo_otr_zn->setText(QString::number(k));
}


void MainWindow::on_pushButton_cht_ind_clicked()
{
    int cht_ind = ui->tableWidget->rowCount();
    int mas[cht_ind];
    bool flag;
    for (int i = 0;i<cht_ind;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag);

        }
        else
        {
            QMessageBox::information(this,"Внимание","пустая ячека");
            return;
        }
        if(!flag)
        {
            QMessageBox::information(this,"Внимание","ячейка должна содержать число");
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            return;
        }


    }
    int sum =0;
    for (int i =0;i<cht_ind;i++)
    {

        if (i%2 != 0 )
            sum += mas[i];


    }
    ui->label_cht_ind->setText(QString::number(sum));
}


void MainWindow::on_pushButton_cht_neind_clicked()
{
    int cht_ind = ui->tableWidget->rowCount();
    int mas[cht_ind];
    bool flag;
    for (int i = 0;i<cht_ind;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag);

        }
        else
        {
            QMessageBox::information(this,"Внимание","пустая ячека");
            return;
        }
        if(!flag)
        {
            QMessageBox::information(this,"Внимание","ячейка должна содержать число");
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            return;
        }


    }
    int sum =0;
    for (int i =0;i<cht_ind;i++)
    {

        if (i%2 == 0 )
            sum += mas[i];


    }
    ui->label_cht_neind->setText(QString::number(sum));
}


void MainWindow::on_pushButton_factorial_clicked()
{
    int cht_ind = ui->tableWidget->rowCount();
    int mas[cht_ind];
    bool flag;
    for (int i = 0;i<cht_ind;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag);

        }
        else
        {
            QMessageBox::information(this,"Внимание","пустая ячека");
            return;
        }
        if(!flag)
        {
            QMessageBox::information(this,"Внимание","ячейка должна содержать число");
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            return;
        }


    }
    //Вводим переменные номера нужного элемента и количества его повторения.
    int maxelement = 1, nomer = -1;
    //перебираем все элементы массива
    for (int i = 0; i < cht_ind; i++)
    {
        int element(0);
        //перебираем все элементы от i до конца
        for (int j = i; j < cht_ind; j++)
        {
            //если элемент i совпадает с одним из последующих (j), то увеличиваем число
            if (mas[i] == mas[j])
            {
                element++;
            }

            //если число больше ранее сохраненного - перезаписываем
            if (maxelement < element)
            {
                maxelement = element;
                nomer = i;
            }
        }
    }
    ui->label_factorial->setText(QString::number(mas[nomer]));//Выводим результат
}
