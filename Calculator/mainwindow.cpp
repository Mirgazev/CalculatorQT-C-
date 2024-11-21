#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#define PI 3.14
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); //Создание интерфейса.Не трогать.
    ui->radioButton_sum->click();//Имитация клика мышкой по radioButton_sum.
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_sum_clicked() //Выбран режим Сложения o_O.
{
    ui->label_op1->setText("Cлагаемое 1"); // Поменяли текст на операнде 1.
    ui->label_op2->setText("Cлагаемое 2"); // Поменяли текст на операнде 2.
    ui->pushButton->setText("Сумма"); //Поменяли текст на кнопке результата.
    ui->label_error->hide(); //Скрываю пред. ошибку.
    ui->label_rez->setVisible(false); //Cкрываю пред.результат(другой способ).
    ui->label_op2->setVisible(true);//показываем op2
    ui->lineEdit_op2->setVisible(true);//показываем line op2
}
void MainWindow::on_radioButton_sub_clicked()//Выбран режим Вычитания o_O.
{
    ui->label_op1->setText("Вычитаемое"); // Поменяли текст на операнде 1.
    ui->label_op2->setText("Уменьшаемое"); // Поменяли текст на операнде 2.
    ui->pushButton->setText("Разность"); //Поменяли текст на кнопке результата.
    ui->label_error->hide(); //Скрываю пред. ошибку.
    ui->label_rez->setVisible(false); //Cкрываю пред.результат(другой способ).
    ui->label_op2->setVisible(true);//показываем op2
    ui->lineEdit_op2->setVisible(true);//показываем line op2
}
void MainWindow::on_radioButton_mul_clicked()//Выбран режим Умножения o_O.
{
    ui->label_op1->setText("Множитель 1"); // Поменяли текст на операнде 1.
    ui->label_op2->setText("Множитель 2"); // Поменяли текст на операнде 2.
    ui->pushButton->setText("Произведение"); //Поменяли текст на кнопке результата.
    ui->label_error->hide(); //Скрываю пред. ошибку.
    ui->label_rez->setVisible(false); //Cкрываю пред.результат(другой способ).
    ui->label_op2->setVisible(true);//показываем op2
    ui->lineEdit_op2->setVisible(true);//показываем line op2
}
void MainWindow::on_radioButton_del_clicked()//Выбран режим Деления o_O.
{
    ui->label_op1->setText("Делимое"); // Поменяли текст на операнде 1.
    ui->label_op2->setText("Делитель"); // Поменяли текст на операнде 2.
    ui->pushButton->setText("Частное"); //Поменяли текст на кнопке результата.
    ui->label_error->hide(); //Скрываю пред. ошибку.
    ui->label_rez->setVisible(false); //Cкрываю пред.результат(другой способ).
    ui->label_op2->setVisible(true);//показываем op2
    ui->lineEdit_op2->setVisible(true);//показываем line op2
}
void MainWindow::on_radioButton_stepen_clicked()//Выбран режим нахождения степени o_O.
{
    ui->label_op1->setText("Число"); // Поменяли текст на операнде 1.
    ui->label_op2->setText("Степень"); // Поменяли текст на операнде 2.
    ui->pushButton->setText("Результат"); //Поменяли текст на кнопке результата.
    ui->label_error->hide(); //Скрываю пред. ошибку.
    ui->label_rez->setVisible(false); //Cкрываю пред.результат(другой способ).
    ui->label_op2->setVisible(true);//показываем op2
    ui->lineEdit_op2->setVisible(true);//показываем line op2
}
void MainWindow::on_radioButton_koren_clicked()//Выбран режим нахождения корня о_О.
{
    ui->label_op1->setText("Число"); // Поменяли текст на операнде 1.
    ui->label_op2->setText("Корень"); // Поменяли текст на операнде 2.
    ui->pushButton->setText("Результат"); //Поменяли текст на кнопке результата.
    ui->label_error->hide(); //Скрываю пред. ошибку.
    ui->label_rez->setVisible(false); //Cкрываю пред.результат(другой способ).
    ui->label_op2->setVisible(false);//hide op2
    ui->lineEdit_op2->setVisible(false);//hide line op2
}
void MainWindow::on_radioButton_sin_clicked()//Выбран режим нахождения sin о_О.
{
    ui->label_op1->setText("Угол"); // Поменяли текст на операнде 1.
    ui->pushButton->setText("Результат"); //Поменяли текст на кнопке результата.
    ui->label_error->hide(); //Скрываю пред. ошибку.
    ui->label_rez->setVisible(false); //Cкрываю пред.результат(другой способ).
    ui->label_op2->setVisible(false);//Прячем op2
    ui->lineEdit_op2->setVisible(false);//Прячем line op2
}
void MainWindow::on_radioButton_cos_clicked()//Выбран режим нахождения cos о_О.
{
    ui->label_op1->setText("Угол"); // Поменяли текст на операнде 1.
    ui->pushButton->setText("Результат"); //Поменяли текст на кнопке результата.
    ui->label_error->hide(); //Скрываю пред. ошибку.
    ui->label_rez->setVisible(false); //Cкрываю пред.результат(другой способ).
    ui->label_op2->setVisible(false);//Прячем op2
    ui->lineEdit_op2->setVisible(false);//Прячем line op2
}
void MainWindow::on_radioButton_tg_clicked()//Выбран режим нахождения tg о_О.
{
    ui->label_op1->setText("Угол"); // Поменяли текст на операнде 1.
    ui->pushButton->setText("Результат"); //Поменяли текст на кнопке результата.
    ui->label_error->hide(); //Скрываю пред. ошибку.
    ui->label_rez->setVisible(false); //Cкрываю пред.результат(другой способ).
    ui->label_op2->setVisible(false);//Прячем op2
    ui->lineEdit_op2->setVisible(false);//Прячем line op2
}
void MainWindow::on_radioButton_arcsin_clicked()//Выбран режим нахождения arcsin о_О.
{
    ui->label_op1->setText("Значение"); // Поменяли текст на операнде 1.
    ui->pushButton->setText("Результат"); //Поменяли текст на кнопке результата.
    ui->label_error->hide(); //Скрываю пред. ошибку.
    ui->label_rez->setVisible(false); //Cкрываю пред.результат(другой способ).
    ui->label_op2->setVisible(false);//Прячем op2
    ui->lineEdit_op2->setVisible(false);//Прячем line op2
}
void MainWindow::on_radioButton_arccos_clicked()//Выбран режим нахождения arccos о_О.
{
    ui->label_op1->setText("Значение"); // Поменяли текст на операнде 1.
    ui->pushButton->setText("Результат"); //Поменяли текст на кнопке результата.
    ui->label_error->hide(); //Скрываю пред. ошибку.
    ui->label_rez->setVisible(false); //Cкрываю пред.результат(другой способ).
    ui->label_op2->setVisible(false);//Прячем op2
    ui->lineEdit_op2->setVisible(false);//Прячем line op2
}
void MainWindow::on_radioButton_arctg_clicked()//Выбран режим нахождения arctg о_О.
{
    ui->label_op1->setText("Значение"); // Поменяли текст на операнде 1.
    ui->pushButton->setText("Результат"); //Поменяли текст на кнопке результата.
    ui->label_error->hide(); //Скрываю пред. ошибку.
    ui->label_rez->setVisible(false); //Cкрываю пред.результат(другой способ).
    ui->label_op2->setVisible(false);//Прячем op2
    ui->lineEdit_op2->setVisible(false);//Прячем line op2
}

void MainWindow::on_pushButton_clicked() //Нажата кнопка вычислений.
{
    {
        if (ui->radioButton_sum->isChecked()) // Выбран режим Сложения.
        {
            double op1,op2,rez; //Операнд 1/Оп 2/Результат.
            QString stroka; //Строка для переобразования.
            bool flag,flag2; //Признак (флаг) успешности преобразования.

            op1=ui->lineEdit_op1->text().toDouble(&flag); //Преобразование операнд 1 с фор.флага
            op2=ui->lineEdit_op2->text().toDouble(&flag2); //Преобразование операнд 2 с фор.флага
            if (flag==true or flag2==true)
            {
                if (flag) //проверим успешность преобразования
                {//Успешно op1
                    if (flag2) //проверим успешность преобразования
                    {//Успешно op2
                        rez=op1+op2;//Выч.рез.
                        if (qIsInf(rez) || qIsNaN(rez))
                        {//Не успешно
                            ui->label_error->setText("Ошибка"); //Формируем текст ошибки в Label
                            ui->label_error->show(); //Отображение Label с ошибкой
                            ui->label_rez->hide(); //Cпрятали результат
                        }
                        else
                        {
                            ui->label_rez->setNum(rez);//Форм. label с рез.
                            ui->label_rez->setVisible(true);//Показываем результат.
                            ui->label_error->setVisible(false);//Прячем rez.
                        }
                    }
                    else
                    {//Не успешно
                        ui->label_error->setText("Ошибка в слагаемом 2"); //Формируем текст ошибки в Label
                        ui->label_error->show(); //Отображение Label с ошибкой
                        ui->label_rez->hide(); //Cпрятали результат
                    }

                }
                else
                {//Не успешно
                    ui->label_error->setText("Ошибка в слагаемом 1"); //Формируем текст ошибки в Label
                    ui->label_error->show(); //Отображение Label с ошибкой
                    ui->label_rez->hide(); //Cпрятали результат
                }
            }
            else {
                ui->label_error->setText("Ошибка в слагаемом 1 и слагаемом 2."); //Формируем текст ошибки в Label
                ui->label_error->show(); //Отображение Label с ошибкой
                ui->label_rez->hide(); //Cпрятали результат
            }

        }
    }
    {
        if (ui->radioButton_sub->isChecked()) // Выбран режим Вычитания.
        {
            double op1,op2,rez; //Операнд 1/Оп 2/Результат.
            QString stroka; //Строка для переобразования.
            bool flag,flag2; //Признак (флаг) успешности преобразования.

            op1=ui->lineEdit_op1->text().toDouble(&flag); //Преобразование операнд 1 с фор.флага
            op2=ui->lineEdit_op2->text().toDouble(&flag2); //Преобразование операнд 2 с фор.флага
            if (flag==true or flag2==true)
            {
                if (flag) //проверим успешность преобразования
                {//Успешно op1
                    if (flag2) //проверим успешность преобразования
                    {//Успешно op2
                        rez=op1-op2;//Выч.рез.
                        if (qIsInf(rez) || qIsNaN(rez))
                        {//Не успешно
                            ui->label_error->setText("Ошибка"); //Формируем текст ошибки в Label
                            ui->label_error->show(); //Отображение Label с ошибкой
                            ui->label_rez->hide(); //Cпрятали результат
                        }
                        else
                        {
                            ui->label_rez->setNum(rez);//Форм. label с рез.
                            ui->label_rez->setVisible(true);//Показываем результат.
                            ui->label_error->setVisible(false);//Прячем rez.
                        }
                    }
                    else
                    {//Не успешно
                        ui->label_error->setText("Ошибка в уменьшаемом"); //Формируем текст ошибки в Label
                        ui->label_error->show(); //Отображение Label с ошибкой
                        ui->label_rez->hide(); //Cпрятали результат
                    }

                }
                else
                {//Не успешно
                    ui->label_error->setText("Ошибка в вычитаемом"); //Формируем текст ошибки в Label
                    ui->label_error->show(); //Отображение Label с ошибкой
                    ui->label_rez->hide(); //Cпрятали результат
                }
            }
            else
            {//Не успешно
                ui->label_error->setText("Ошибка в уменьшаемом и вычитаемом."); //Формируем текст ошибки в Label
                ui->label_error->show(); //Отображение Label с ошибкой
                ui->label_rez->hide(); //Cпрятали результат
            }
        }
    }
    {
        if (ui->radioButton_mul->isChecked()) // Выбран режим Умножения.
        {
            double op1,op2,rez; //Операнд 1/Оп 2/Результат.
            QString stroka; //Строка для переобразования.
            bool flag,flag2; //Признак (флаг) успешности преобразования.

            op1=ui->lineEdit_op1->text().toDouble(&flag); //Преобразование операнд 1 с фор.флага
            op2=ui->lineEdit_op2->text().toDouble(&flag2); //Преобразование операнд 2 с фор.флага
            if (flag==true or flag2==true)
            {
                if (flag) //проверим успешность преобразования
                {//Успешно op1
                    if (flag2) //проверим успешность преобразования
                    {//Успешно op2
                        rez=op1*op2;//Выч.рез.
                        if (qIsInf(rez) || qIsNaN(rez))
                        {//Не успешно
                            ui->label_error->setText("Ошибка"); //Формируем текст ошибки в Label
                            ui->label_error->show(); //Отображение Label с ошибкой
                            ui->label_rez->hide(); //Cпрятали результат
                        }
                        else
                        {
                            ui->label_rez->setNum(rez);//Форм. label с рез.
                            ui->label_rez->setVisible(true);//Показываем результат.
                            ui->label_error->setVisible(false);//Прячем rez.
                        }
                    }
                    else
                    {//Не успешно
                        ui->label_error->setText("Ошибка в 2-ом множителе."); //Формируем текст ошибки в Label
                        ui->label_error->show(); //Отображение Label с ошибкой
                        ui->label_rez->hide(); //Cпрятали результат
                    }

                }
                else
                {//Не успешно
                    ui->label_error->setText("Ошибка в 1-ом множителе."); //Формируем текст ошибки в Label
                    ui->label_error->show(); //Отображение Label с ошибкой
                    ui->label_rez->hide(); //Cпрятали результат
                }
            }
            else {
                ui->label_error->setText("Ошибка в 1-ом множителе и 2-ом множителе."); //Формируем текст ошибки в Label
                ui->label_error->show(); //Отображение Label с ошибкой
                ui->label_rez->hide(); //Cпрятали результат
            }
        }
    }

    {
        if (ui->radioButton_del->isChecked()) // Выбран режим Деления.
        {
            double op1,op2,rez; //Операнд 1/Оп 2/Результат.
            QString stroka; //Строка для переобразования.
            bool flag,flag2; //Признак (флаг) успешности преобразования.

            op1=ui->lineEdit_op1->text().toDouble(&flag); //Преобразование операнд 1 с фор.флага
            op2=ui->lineEdit_op2->text().toDouble(&flag2); //Преобразование операнд 2 с фор.флага
            if (flag==true or flag2==true)
            {
                if (flag) //проверим успешность преобразования
                {//Успешно op1
                    if (flag2) //проверим успешность преобразования
                    {//Успешно op2
                        if(abs(op2 - 0.0) < 1e-7) //Если делитель равен 0
                        {//Не успешно
                            ui->label_error->setText("Нельзя делить на 0."); //Формируем текст ошибки в Label
                            ui->label_error->show(); //Отображение Label с ошибкой
                            ui->label_rez->hide(); //Cпрятали результат
                        }
                        else
                        {//Успешно
                            rez=op1/op2;//Деление рез.
                            if (qIsInf(rez) || qIsNaN(rez))
                            {//Не успешно
                                ui->label_error->setText("Ошибка"); //Формируем текст ошибки в Label
                                ui->label_error->show(); //Отображение Label с ошибкой
                                ui->label_rez->hide(); //Cпрятали результат
                            }
                            else
                            {
                                ui->label_rez->setNum(rez);//Форм. label с рез.
                                ui->label_rez->setVisible(true);//Показываем результат.
                                ui->label_error->setVisible(false);//Прячем rez.
                            }
                        }
                    }
                    else
                    {//Не успешно
                        ui->label_error->setText("Ошибка в делителе"); //Формируем текст ошибки в Label
                        ui->label_error->show(); //Отображение Label с ошибкой
                        ui->label_rez->hide(); //Cпрятали результат
                    }

                }
                else
                {//Не успешно
                    ui->label_error->setText("Ошибка в делимом"); //Формируем текст ошибки в Label
                    ui->label_error->show(); //Отображение Label с ошибкой
                    ui->label_rez->hide(); //Cпрятали результат
                }
            }
            else
            {
                ui->label_error->setText("Ошибка в делимом и делителе."); //Формируем текст ошибки в Label
                ui->label_error->show(); //Отображение Label с ошибкой
                ui->label_rez->hide(); //Cпрятали результат
            }
        }
    }
    {
        if (ui->radioButton_stepen->isChecked()) // Выбран режим Степени.
        {
            double op1,op2,rez; //Операнд 1/Оп 2/Результат.
            QString stroka; //Строка для переобразования.
            bool flag,flag2; //Признак (флаг) успешности преобразования.

            op1=ui->lineEdit_op1->text().toDouble(&flag); //Преобразование операнд 1 с фор.флага
            op2=ui->lineEdit_op2->text().toDouble(&flag2); //Преобразование операнд 2 с фор.флага
            if (flag==true or flag2==true)
            {
                if (flag) //проверим успешность преобразования
                {//Успешно op1
                    if (flag2) //проверим успешность преобразования
                    {//Успешно op2
                        rez=pow(op1,op2);
                        if (qIsInf(rez) || qIsNaN(rez))
                        {//Не успешно
                            ui->label_error->setText("Ошибка"); //Формируем текст ошибки в Label
                            ui->label_error->show(); //Отображение Label с ошибкой
                            ui->label_rez->hide(); //Cпрятали результат
                        }
                        else
                        {
                            ui->label_rez->setNum(rez);//Форм. label с рез.
                            ui->label_rez->setVisible(true);//Показываем результат.
                            ui->label_error->setVisible(false);//Прячем rez.
                        }
                    }
                    else
                    {//Не успешно
                        ui->label_error->setText("Ошибка в степени."); //Формируем текст ошибки в Label
                        ui->label_error->show(); //Отображение Label с ошибкой
                        ui->label_rez->hide(); //Cпрятали результат
                    }

                }
                else
                {//Не успешно
                    ui->label_error->setText("Ошибка в числе."); //Формируем текст ошибки в Label
                    ui->label_error->show(); //Отображение Label с ошибкой
                    ui->label_rez->hide(); //Cпрятали результат
                }
            }
            else {
                ui->label_error->setText("Ошибка в числе и степени."); //Формируем текст ошибки в Label
                ui->label_error->show(); //Отображение Label с ошибкой
                ui->label_rez->hide(); //Cпрятали результат

            }
        }
    }
    {
        if (ui->radioButton_koren->isChecked()) // Выбран режим корня.
        {
            double op1,rez; //Операнд 1/Оп 2/Результат.
            QString stroka; //Строка для переобразования.
            bool flag; //Признак (флаг) успешности преобразования.

            op1=ui->lineEdit_op1->text().toDouble(&flag); //Преобразование операнд 1 с фор.флага
            if (flag) //проверим успешность преобразования
            {//Успешно op1
                if(op1>=0) //Определяем промежутки сущ. арксин
                {//Успешно
                    rez=sqrt(op1);//Выч.рез.
                    ui->label_rez->setNum(rez);//Форм. label с рез.
                    ui->label_rez->setVisible(true);//Показываем результат.
                    ui->label_error->setVisible(false);//Прячем error.
                }
                else
                {
                    ui->label_error->setText("Число под корнем должно быть больше 0."); //Формируем текст ошибки в Label
                    ui->label_error->show(); //Отображение Label с ошибкой
                    ui->label_rez->hide(); //Cпрятали результат
                }
            }
            else
            {//Не успешно
                ui->label_error->setText("Ошибка в корне"); //Формируем текст ошибки в Label
                ui->label_error->show(); //Отображение Label с ошибкой
                ui->label_rez->hide(); //Cпрятали результат
            }

        }
    }
    {
        if (ui->radioButton_sin->isChecked()) // Выбран режим sin.
        {
            double op1,rez; //Операнд 1/Оп 2/Результат.
            QString stroka; //Строка для переобразования.
            bool flag; //Признак (флаг) успешности преобразования.

            op1=ui->lineEdit_op1->text().toDouble(&flag); //Преобразование операнд 1 с фор.флага
            if (flag) //проверим успешность преобразования
            {//Успешно op1
                rez=sin((op1/180)*PI);//Выч.рез.
                if (qIsInf(rez) || qIsNaN(rez))
                {//Не успешно
                    ui->label_error->setText("Ошибка"); //Формируем текст ошибки в Label
                    ui->label_error->show(); //Отображение Label с ошибкой
                    ui->label_rez->hide(); //Cпрятали результат
                }
                else
                {
                    ui->label_rez->setNum(rez);//Форм. label с рез.
                    ui->label_rez->setVisible(true);//Показываем результат.
                    ui->label_error->setVisible(false);//Прячем rez.
                }
            }
            else
            {//Не успешно
                ui->label_error->setText("Ошибка в угловой величине"); //Формируем текст ошибки в Label
                ui->label_error->show(); //Отображение Label с ошибкой
                ui->label_rez->hide(); //Cпрятали результат
            }

        }
    }
    {
        if (ui->radioButton_cos->isChecked()) // Выбран режим cos.
        {
            double op1,rez; //Операнд 1/Оп 2/Результат.
            QString stroka; //Строка для переобразования.
            bool flag; //Признак (флаг) успешности преобразования.

            op1=ui->lineEdit_op1->text().toDouble(&flag); //Преобразование операнд 1 с фор.флага
            if (flag) //проверим успешность преобразования
            {//Успешно op1
                rez=cos((op1/180)*PI);//Выч.рез.
                if (qIsInf(rez) || qIsNaN(rez))
                {//Не успешно
                    ui->label_error->setText("Ошибка"); //Формируем текст ошибки в Label
                    ui->label_error->show(); //Отображение Label с ошибкой
                    ui->label_rez->hide(); //Cпрятали результат
                }
                else
                {
                    ui->label_rez->setNum(rez);//Форм. label с рез.
                    ui->label_rez->setVisible(true);//Показываем результат.
                    ui->label_error->setVisible(false);//Прячем rez.
                }
            }
            else
            {//Не успешно
                ui->label_error->setText("Ошибка в угловой величине"); //Формируем текст ошибки в Label
                ui->label_error->show(); //Отображение Label с ошибкой
                ui->label_rez->hide(); //Cпрятали результат
            }

        }
    }
    {
        if (ui->radioButton_tg->isChecked()) // Выбран режим tg.
        {
            double op1,rez; //Операнд 1/Оп 2/Результат.
            QString stroka; //Строка для переобразования.
            bool flag; //Признак (флаг) успешности преобразования.

            op1=ui->lineEdit_op1->text().toDouble(&flag); //Преобразование операнд 1 с фор.флага
            if (flag) //проверим успешность преобразования
            {//Успешно op1
                if (op1==90)
                {//Не успешно
                    ui->label_error->setText("Нет такого значения"); //Формируем текст ошибки в Label
                    ui->label_error->show(); //Отображение Label с ошибкой
                    ui->label_rez->hide(); //Cпрятали результат
                }
                else
                {
                    rez=tan((op1/180)*PI);//Выч.рез.
                    if (qIsInf(rez) || qIsNaN(rez))
                    {//Не успешно
                        ui->label_error->setText("Ошибка"); //Формируем текст ошибки в Label
                        ui->label_error->show(); //Отображение Label с ошибкой
                        ui->label_rez->hide(); //Cпрятали результат
                    }
                    else
                    {
                        ui->label_rez->setNum(rez);//Форм. label с рез.
                        ui->label_rez->setVisible(true);//Показываем результат.
                        ui->label_error->setVisible(false);//Прячем rez.
                    }
                }
            }
            else
            {//Не успешно
                ui->label_error->setText("Ошибка в угловой величине"); //Формируем текст ошибки в Label
                ui->label_error->show(); //Отображение Label с ошибкой
                ui->label_rez->hide(); //Cпрятали результат
            }

        }
    }
    {
        if (ui->radioButton_arcsin->isChecked()) // Выбран режим arcsin.
        {
            double op1,rez; //Операнд 1/Оп 2/Результат.
            QString stroka; //Строка для переобразования.
            bool flag; //Признак (флаг) успешности преобразования.

            op1=ui->lineEdit_op1->text().toDouble(&flag); //Преобразование операнд 1 с фор.флага
            if (flag) //проверим успешность преобразования
            {//Успешно op1
                if(op1>=-1 && op1<=1) //Определяем промежутки сущ. арксин
                {//Успешно
                    rez=asin(op1)*180.0/M_PI;//Выч.рез.
                    ui->label_rez->setNum(rez);//Форм. label с рез.
                    ui->label_rez->setVisible(true);//Показываем результат.
                    ui->label_error->setVisible(false);//Прячем error.
                }
                else
                {//Не успешно
                    ui->label_error->setText("Значение должно быть в диапазоне от -1 до 1."); //Формируем текст ошибки в Label
                    ui->label_error->show(); //Отображение Label с ошибкой
                    ui->label_rez->hide(); //Cпрятали результат
                }
            }
            else
            {//Не успешно
                ui->label_error->setText("Ошибка в числовом значении."); //Формируем текст ошибки в Label
                ui->label_error->show(); //Отображение Label с ошибкой
                ui->label_rez->hide(); //Cпрятали результат
            }
        }
    }
    {
        if (ui->radioButton_arccos->isChecked()) // Выбран режим arccos.
        {
            double op1,rez; //Операнд 1/Оп 2/Результат.
            QString stroka; //Строка для переобразования.
            bool flag; //Признак (флаг) успешности преобразования.

            op1=ui->lineEdit_op1->text().toDouble(&flag); //Преобразование операнд 1 с фор.флага
            if (flag) //проверим успешность преобразования
            {//Успешно op1
                if(op1>=-1 && op1<=1) //Определяем промежутки сущ. арккос.
                {//Успешно
                    rez=acos(op1)*180.0/M_PI;//Выч.рез.
                    ui->label_rez->setNum(rez);//Форм. label с рез.
                    ui->label_rez->setVisible(true);//Показываем результат.
                    ui->label_error->setVisible(false);//Прячем error.
                }
                else
                {//Не успешно
                    ui->label_error->setText("Значение должно быть в диапазоне от -1 до 1."); //Формируем текст ошибки в Label
                    ui->label_error->show(); //Отображение Label с ошибкой
                    ui->label_rez->hide(); //Cпрятали результат
                }
            }
            else
            {//Не успешно
                ui->label_error->setText("Ошибка в числовом значении."); //Формируем текст ошибки в Label
                ui->label_error->show(); //Отображение Label с ошибкой
                ui->label_rez->hide(); //Cпрятали результат
            }
        }
    }
    {
        if (ui->radioButton_arctg->isChecked()) // Выбран режим arctg.
        {
            double op1,rez; //Операнд 1/Оп 2/Результат.
            QString stroka; //Строка для переобразования.
            bool flag; //Признак (флаг) успешности преобразования.

            op1=ui->lineEdit_op1->text().toDouble(&flag); //Преобразование операнд 1 с фор.флага
            if (flag) //проверим успешность преобразования
            {//Успешно op1
                rez=atan(op1)*180.0/M_PI;//Выч.рез.
                ui->label_rez->setNum(rez);//Форм. label с рез.
                ui->label_rez->setVisible(true);//Показываем результат.
                ui->label_error->setVisible(false);//Прячем error.
            }
            else
            {//Не успешно
                ui->label_error->setText("Ошибка в значении."); //Формируем текст ошибки в Label
                ui->label_error->show(); //Отображение Label с ошибкой
                ui->label_rez->hide(); //Cпрятали результат
            }

        }
    }
}
