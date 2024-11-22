#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_name_textChanged(const QString &arg1)//Ограничение символов в имени.
{
    QString name = arg1;//Записываем в переменную name значения из lineedit
    int symvols = name.count();// получаем кол-во символов в имени

    if(symvols<3 || symvols>20)//Ограничение на имя.
    {
        ui->label_error->show();//Показываем ошибку.
    }
    else
    {
        ui->label_error->hide();//Прячем ошибку.
    }

    // делаем проверку на пробелы
    if(name.contains(" ")) // если имя содержит пробелы
    {
        ui->label_error->show();//Показываем ошибку.
    }
}

void MainWindow::on_lineEdit_power_textChanged(const QString &arg1)
{
    QString text = arg1;// получаем текст из лайн эдит
    bool flag;
    int value = text.toInt(&flag);


    QPalette pal = ui->label_power->palette();// получаем текущую политру для силы
    if(flag)//если число корректное
    {
        if(value >= 1 && value <=3)
        {
            pal.setColor(QPalette::WindowText, Qt::red);// Задаем цвет
        }
        else if(value >= 4 && value<=6)
        {
            pal.setColor(QPalette::WindowText, Qt::yellow);// Задаем цвет
        }
        else if(value >= 7 && value<=10)
        {
            pal.setColor(QPalette::WindowText, Qt::green);// Задаем цвет
        }
        else // число вышло за диапозон
        {
            pal.setColor(QPalette::WindowText, Qt::black);// Задаем цвет
        }
    }
    else //если число некорректное
    {
        pal.setColor(QPalette::WindowText, Qt::black); // Задаем цвет
    }

    //Проверка ограничений по полу
    if(ui->radioButton_woman->isChecked() && value >=8 && value <=10)
    {
        pal.setColor(QPalette::WindowText, Qt::red);//задаем цвет
    }

    ui->label_power->setPalette(pal);//применяем политру
    ostatok();//после ввода нового значения обновляю кол-во оставшихся очков
}
void MainWindow::on_lineEdit_lovkost_textChanged(const QString &arg1)
{
    QString text = arg1;// получаем текст из лайн эдит
    bool flag;
    int value = text.toInt(&flag);


    QPalette pal = ui->label_lovkost->palette();// получаем текущую политру для силы
    if(flag)//если число корректное
    {
        if(value >= 1 && value <=3)
        {
            pal.setColor(QPalette::WindowText, Qt::red);// Задаем цвет
        }
        else if(value >= 4 && value<=6)
        {
            pal.setColor(QPalette::WindowText, Qt::yellow);// Задаем цвет
        }
        else if(value >= 7 && value<=10)
        {
            pal.setColor(QPalette::WindowText, Qt::green);// Задаем цвет
        }
        else // число вышло за диапозон
        {
            pal.setColor(QPalette::WindowText, Qt::black);// Задаем цвет
        }
    }
    else //если число некорректное
    {
        pal.setColor(QPalette::WindowText, Qt::black); // Задаем цвет
    }
    ui->label_lovkost->setPalette(pal);//применяем политру

    ostatok();//после ввода нового значения обновляю кол-во оставшихся очков
}
void MainWindow::on_lineEdit_intelekt_textChanged(const QString &arg1)
{
    QString text = arg1;// получаем текст из лайн эдит
    bool flag;
    int value = text.toInt(&flag);


    QPalette pal = ui->label_intelekt->palette();// получаем текущую политру для силы
    if(flag)//если число корректное
    {
        if(value >= 1 && value <=3)
        {
            pal.setColor(QPalette::WindowText, Qt::red);// Задаем цвет
        }
        else if(value >= 4 && value<=6)
        {
            pal.setColor(QPalette::WindowText, Qt::yellow);// Задаем цвет
        }
        else if(value >= 7 && value<=10)
        {
            pal.setColor(QPalette::WindowText, Qt::green);// Задаем цвет
        }
        else // число вышло за диапозон
        {
            pal.setColor(QPalette::WindowText, Qt::black);// Задаем цвет
        }
    }
    else //если число некорректное
    {
        pal.setColor(QPalette::WindowText, Qt::black); // Задаем цвет
    }
    ui->label_intelekt->setPalette(pal);//применяем политру
    ostatok();//после ввода нового значения обновляю кол-во оставшихся очков
}

void MainWindow::on_lineEdit_udacha_textChanged(const QString &arg1)
{
    QString text = arg1;// получаем текст из лайн эдит
    bool flag;
    int value = text.toInt(&flag);


    QPalette pal = ui->label_udacha->palette();// получаем текущую политру для силы
    if(flag)//если число корректное
    {
        if(value >= 1 && value <=3)
        {
            pal.setColor(QPalette::WindowText, Qt::red);// Задаем цвет
        }
        else if(value >= 4 && value<=6)
        {
            pal.setColor(QPalette::WindowText, Qt::yellow);// Задаем цвет
        }
        else if(value >= 7 && value<=10)
        {
            pal.setColor(QPalette::WindowText, Qt::green);// Задаем цвет
        }
        else // число вышло за диапозон
        {
            pal.setColor(QPalette::WindowText, Qt::black);// Задаем цвет
        }
    }
    else //если число некорректное
    {
        pal.setColor(QPalette::WindowText, Qt::black); // Задаем цвет
    }

    //Проверка ограничений по полу
    if(ui->radioButton_man->isChecked() && value >=8 && value <=10)
    {
        pal.setColor(QPalette::WindowText, Qt::red);//задаем цвет
    }
    ui->label_udacha->setPalette(pal);//применяем политру
    ostatok();//после ввода нового значения обновляю кол-во оставшихся очков
}

void MainWindow::on_pushButton_raschet_clicked()
{
    int power,lovkost,inteleckt, udacha;// создаем переменные
    bool flag;
    QString str = ui->lineEdit_power->text();// считываем значение силы с lineedit

    power = str.toInt(&flag);// делаем перевод в число

    if(!flag)// если ошибка
    {
        QMessageBox::warning(this,"Ошибка!","Неккоректное значение силы!");
        return;
    }
    else if(power<1 || power>10)
    {
        QMessageBox::warning(this,"Ошибка!","Кол-во очков силы может быть от 1 до 10!");
        return;
    }

    //учитываем ловкость
    str = ui->lineEdit_lovkost->text();// считываем значение ловкости с lineedit

    lovkost = str.toInt(&flag);// делаем перевод в число
    if(!flag)// если ошибка
    {
        QMessageBox::warning(this,"Ошибка!","Неккоректное значение ловкости!");
        return;
    }
    else if(lovkost<1 || lovkost>10)
    {
        QMessageBox::warning(this,"Ошибка!","Кол-во очков ловкости должно быть от 1 до 10!");
        return;
    }

    //учитываем интеллект
    str = ui->lineEdit_intelekt->text();// считываем значение интеллекта с lineedit

    inteleckt = str.toInt(&flag);// делаем перевод в число
    if(!flag)// если ошибка
    {
        QMessageBox::warning(this,"Ошибка!","Неккоректное значение интеллекта!");
        return;
    }
    else if(inteleckt<1 || inteleckt>10)
    {
        QMessageBox::warning(this,"Ошибка!","Кол-во очков интеллекта должно быть от 1 до 10!");
        return;
    }

    //учитываем удачу
    str = ui->lineEdit_udacha->text();// считываем значение удачи с lineedit

    udacha = str.toInt(&flag);// делаем перевод в число
    if(!flag)// если ошибка
    {
        QMessageBox::warning(this,"Ошибка!","Неккоректное значение удачи!");
        return;
    }
    else if(udacha<1 || udacha>10)
    {
        QMessageBox::warning(this,"Ошибка!","Кол-во очков удачи должно быть от 1 до 10!");
        return;
    }
    //расчет вторичных хар-к
    int hp, defend, attack, mana;
    hp = udacha*2 + inteleckt*3 + lovkost*5 + power*9;
    defend = udacha*7 + inteleckt*4 + lovkost*9 + power*3;
    attack = udacha*5 + inteleckt*7 + lovkost*8 + power*3;
    mana = udacha*4 + inteleckt*10 + lovkost*5 + power*1;







    //Проверка пола
    if(!ui->radioButton_man->isChecked() && !ui->radioButton_woman->isChecked())
    {
        QMessageBox::warning(this,"Ошибка!","Выберите пол!");
        return;
    }

    if(ui->radioButton_man->isChecked() && udacha>=8 && udacha<=10)
    {
        QMessageBox::warning(this,"Ошибка!","У мужчин ограничена удача до 8 очков!");
        return;
    }
    if(ui->radioButton_woman->isChecked() && power>=8 && power<=10)
    {
        QMessageBox::warning(this,"Ошибка!","У женщин ограничена сила до 8 очков!");
        return;
    }

    //Проверка никнейма
    QString name =ui->lineEdit_name->text();//Записываем в переменную name значения из lineedit
    int symvols = name.count();// получаем кол-во символов в имени
    if(symvols>20 || symvols<3)
    {
        QMessageBox::warning(this,"Ошибка!","Введите имя правильно!");
        return;
    }

    //Чтобы юзались все очки
    int ostat;
    QString ost = ui->lineEdit_ostatok->text();// считываем значение силы с lineedit
    ostat = ost.toInt(&flag);// делаем перевод в число]
    if(ostat<0)
    {
        QMessageBox::warning(this,"Ошибка!","У вас не более 20 очков на все характеристики");
        return;
    }
    else if(ostat!=0)
    {
        QMessageBox::warning(this,"Ошибка!","Нужно использовать все очки!");
        return;
    }

    ui->label_hp->setNum(hp);
    ui->label_defend->setNum(defend);
    ui->label_attack->setNum(attack);
    ui->label_mana->setNum(mana);



    // klass dlya man
    if(ui->radioButton_man->isChecked())
    {
        if((mana+hp)>210)
        {
            ui->label_klass->setText("Орк");
        }
        else if((defend+hp)>210)
        {
            ui->label_klass->setText("Воин");
        }
        else if((attack+mana)>210)
        {
            ui->label_klass->setText("Маг");
        }
        else if((defend+attack)>210)
        {
            ui->label_klass->setText("Лучник");
        }
    }
    //класс для woman
    if(ui->radioButton_woman->isChecked())
    {
        if((mana+hp)>210)
        {
            ui->label_klass->setText("Орк девушка");
        }
        else if((defend+hp)>210)
        {
            ui->label_klass->setText("Валькирия");
        }
        else if((attack+mana)>210)
        {
            ui->label_klass->setText("Колдунья");
        }
        else if((defend+attack)>210)
        {
            ui->label_klass->setText("Лучница");
        }
    }

}



void MainWindow::on_pushButton_sbros_clicked()
{
    int res=1;
    QString str;
    ui->lineEdit_power->setText(QString::number(res));
    ui->lineEdit_lovkost->setText(QString::number(res));
    ui->lineEdit_intelekt->setText(QString::number(res));
    ui->lineEdit_udacha->setText(QString::number(res));
    ui->label_defend->setText("0");
    ui->label_hp->setText("0");
    ui->label_mana->setText("0");
    ui->label_attack->setText("0");
    ui->label_klass->setText("Нет");
}

void MainWindow::ostatok()//Создаем функцию
{
    double power= ui->lineEdit_power->text().toDouble();// Задаем переменную и берем значение с лайнэдит
    double lovkost= ui->lineEdit_lovkost->text().toDouble();// Задаем переменную и берем значение с лайнэдит
    double intelekt= ui->lineEdit_intelekt->text().toDouble();// Задаем переменную и берем значение с лайнэдит
    double udacha= ui->lineEdit_udacha->text().toDouble();// Задаем переменную и берем значение с лайнэдит

    double ostatok = 20 - (power+lovkost+intelekt+udacha);//Задаем переменную остаток и считаем ее
    QString str;// задаем переменную
    str.setNum(ostatok); // делаем перевод из числа
    ui->lineEdit_ostatok->setText(str);//Меняем значения остатка в лайн эдит
    if (qIsInf(ostatok) || qIsNaN(ostatok))//Проверяем результат на существование
    {
        ui->lineEdit_ostatok->setText("Error");//Меняем значения остатка в лайн эдит
    }
    //Предупреждение о кол-во в реал тайм
    //  if(ostatok<0)
    //  {
    //       QMessageBox::warning(this,"Ошибка!","У вас не более 20 очков на все характеристики");
    //       return;
    //   }

}


