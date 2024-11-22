#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_sf->hide();
    ui->label_min->hide();
    ui->label_max->hide();
    ui->pushButton_max->setEnabled(false);
    ui->pushButton_min->setEnabled(false);
    ui->pushButton_sf->setEnabled(false);
    ui->pushButton_2->setEnabled(false);//пузырьковая
    ui->pushButton_random->setEnabled(false);
    ui->pushButton_3->setEnabled(false);//гномья
    ui->pushButton_rash->setEnabled(false);//расчесткой
    ui->pushButton_faster->setEnabled(false);//быстрая
    ui->pushButton_monkey->setEnabled(false);//макака
    ui->pushButton_search->setEnabled(false);//поиск
    ui->pushButton_4->setEnabled(false);//поиск
    ui->pushButton_5->setEnabled(false);//поиск
}

MainWindow::~MainWindow()
{
    delete ui;

}

//Ф-ции сортировки
void bubleSort(int *arr,int size)//пузырьковая сортировка
{
    for (int i=0;i<size;i++)// перебираем элементы, которые расположены до i-го элемента
    {
        for (int j=0;j<i;j++)// перебираем элементы, которые расположены до i-го элемента
        {
            if (arr[j] > arr[i])//меняем местами 2 эл массива
            {
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void Gnom(int *arr,int size)//гномья сортировка
{
    int i = 1; // счётчик
    while (i < size)
    {
        if (i == 0) {
            i = 1;
        }
        if (arr[i-1] <= arr[i]) {
            ++i; // идём вперед
        } else {
            // меняем местами
            long tmp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = tmp;
            // идём назад
            --i;
        }
    }
}

void raschestka(int *arr,int size)// Сортировка расчесткой
{
    int step=size; // готовим начальный шаг
    bool pr_peres=true;// вводим контроль перестановки
    while(step>1 or pr_peres)
    {
        step/=1.247f; // шаг на этом проходе.  На первом проходе получается примерно 80% от размера массива,
        // и легкие элементы в хвосте переносятся в первые 20%
        if (step<1) step=1; // 0 быть не может, присвоим 1
        pr_peres =false;
        for (int i=0; i+step<size;++i)
        { // двигаемся, пока сравниваемый элемент (на шаг от текущего) в массиве
            if(arr[i]>arr[i+step])
            {
                int tmp=arr[i];
                arr[i]=arr[i+step];
                arr[i+step]=tmp;
                pr_peres=true;//перестановка выполнена
            }
        }
    }
}

void FastSort(int *arr,int low,int high)//Быстрая сортировка
{
    int i = low; //Левая граница
    int j = high; //Правая граница
    int pivot = arr[(i + j) / 2]; //Опорный центральный элемент
    int temp; //Временная переменная

    while (i <= j) //Пока левая граница меньше правой
    {
        while (arr[i] < pivot) //Если левый элемент меньше опорного, то идем далее
            i++;
        while (arr[j] > pivot) //Если правый элемент больше опорного, то идем далее
            j--;
        if (i <= j) // Если левый элемент меньше или равен правому, то делаем замену
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    //Рекурсией проверяем левые и правые границы
    if (j > low)
        FastSort(arr, low, j);
    if (i < high)
        FastSort(arr, i, high);
}

//CОРТИРОВКА ДРОБОВИКОВ, СЛУЧАЙНАЯ, ОБЕЗЬЯНЬЯ
bool correct(int *arr, int size) //Проверяем корректность данных
{
    while (--size > 0 )
        if (arr[size - 1] > arr[size])
            return true;
    return false;
}

void shuffle(int *arr, int size) // Рандомно раскидываем элементы
{
    for (int i = 0; i < size; ++i)
    {
        int rnd = rand() % size;
        int temp = arr[i];
        arr[i] = arr[rnd];
        arr[rnd] = temp;
        //      std::swap(arr[i], arr[(rand() % size)]);
    }
}

void MonkeySort(int *arr, int size) //Сортируем вслепую
{
    while (correct(arr, size))
        shuffle(arr, size);
}

//Нажатые кнопки
void MainWindow::on_pushButton_clicked() //Кнопка принять
{


    ui->tableWidget->setColumnCount(1);
    bool flag;
    int razmer = ui->lineEdit->text().toInt(&flag);
    if (!flag)
    {
        QMessageBox::information(this,"Внимание","Данные некорректны! Введите число!");
        return;
    }
    if (razmer<1 or razmer>1000000)
    {
        QMessageBox::information(this,"Внимание","Размер должен быть от 1 до 1.000.000 строк!");
        return;
    }
    ui->pushButton_max->setEnabled(true);
    ui->pushButton_min->setEnabled(true);
    ui->pushButton_sf->setEnabled(true);
    ui->pushButton_2->setEnabled(true);//пузырьковая
    ui->pushButton_random->setEnabled(true);
    ui->pushButton_3->setEnabled(true);//гномья
    ui->pushButton_rash->setEnabled(true);//расчесткой
    ui->pushButton_faster->setEnabled(true);//быстрая
    ui->pushButton_monkey->setEnabled(true);//макака
    ui->pushButton_search->setEnabled(true);//поиск
    ui->pushButton_5->setEnabled(true);//сохранение
    ui->tableWidget->setRowCount(razmer);
}

void MainWindow::on_pushButton_random_clicked()//Кнопка рандомного заполнения таблицы
{
    QElapsedTimer timer;
    timer.start();
    QDeadlineTimer deadline(1500);
    int n_row = ui->tableWidget->rowCount();//получаем количество строк
    srand(clock());
    int chislo;
    QString stroka;
    bool check=true;
    for(int i=0;i<n_row;i++)
    {
        if(check && deadline.hasExpired())
        {
            QMessageBox::information(this,"Внимание","Время работы более 3-х секунд!");//выводим ошибку
            check=false;
        }
        if (ui->tableWidget->item(i,0)==nullptr)
        {
            QTableWidgetItem * new_item;// Создаем указатель
            new_item = new QTableWidgetItem; //Выделяем память
            ui->tableWidget->setItem(i,0,new_item); //Заносим ячейку в таблицу
        }
        chislo= rand()%201-100;// рандомное число от -100 до 100
        stroka.setNum(chislo);
        ui->tableWidget->item(i,0)->setText(stroka);// заносим число в таблицу
        ui->tableWidget->item(i,0)->setBackground(Qt::white);
    }
    ui->label_sf->hide();
    ui->label_min->hide();
    ui->label_max->hide();
    ui->lineEdit_indexkey->clear();
    ui->textEdit->clear();
    ui->pushButton_4->setEnabled(false);
}

void MainWindow::on_pushButton_min_clicked() //Минимальное значение массива
{
    int size = ui->tableWidget->rowCount();//получаем количество строк
    int *mas= new int[size];//Создаем динамический массив
    bool flag2;

    bool error = false;

    for (int i=0;i<size;i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i,0); //Получаем указатель на ячейку
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag2);
            if (flag2)
            {
                ui->tableWidget->item(i,0)->setBackground(Qt::white);
            }
            if(!flag2)
            {
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
                ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
                error = true;
            }
        }
        else
        {
            item = new QTableWidgetItem;//выделяем память под ячейк
            ui->tableWidget->setItem(i,0,item); //сообщаем таблице, что мы вручили выд память под ячейку
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
            ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
            error = true;
        }
    }
    if (error)
    {
        ui->label_sf->hide();
        ui->label_min->hide();
        ui->label_max->hide();
        QMessageBox::information(this,"Внимание","Таблица заполнена не корректно");//выводим ошибку
        delete [] mas;
        return;
    }
    int min=mas[0];// запись нулевого значения массива

    for (int i=0;i<size;i++)
    {
        if (mas[i]<min)
        {
            min=mas[i];
        }
    }
    ui->label_min->setText(QString::number(min));
    ui->label_min->show();
}

void MainWindow::on_pushButton_max_clicked() //Максимальное значение массива
{
    int size = ui->tableWidget->rowCount();//получаем количество строк
    int *mas= new int[size];//Создаем динамический массив
    bool flag2;

    bool error = false;

    for (int i=0;i<size;i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i,0); //Получаем указатель на ячейку
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag2);
            if (flag2)
            {
                ui->tableWidget->item(i,0)->setBackground(Qt::white);
            }
            if(!flag2)
            {
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
                ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
                error = true;
            }
        }
        else
        {
            item = new QTableWidgetItem;//выделяем память под ячейк
            ui->tableWidget->setItem(i,0,item); //сообщаем таблице, что мы вручили выд память под ячейку
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
            ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
            error = true;
        }
    }
    if (error)
    {
        ui->label_sf->hide();
        ui->label_min->hide();
        ui->label_max->hide();
        QMessageBox::information(this,"Внимание","Таблица заполнена не корректно");//выводим ошибку
        delete [] mas;
        return;
    }
    int max=mas[0];// запись нулевого значения массива

    for (int i=0;i<size;i++)
    {
        if (mas[i]>max)
        {
            max=mas[i];
        }
    }
    ui->label_max->setText(QString::number(max));
    ui->label_max->show();
}

void MainWindow::on_pushButton_sf_clicked()//Среднее значение массива
{
    int size = ui->tableWidget->rowCount();//получаем количество строк
    int *mas= new int[size];//Создаем динамический массив
    int sf;
    bool flag2;

    bool error = false;

    for (int i=0;i<size;i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i,0); //Получаем указатель на ячейку
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag2);
            if (flag2)
            {
                ui->tableWidget->item(i,0)->setBackground(Qt::white);
            }
            if(!flag2)
            {
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
                ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
                error = true;
            }
        }
        else
        {
            item = new QTableWidgetItem;//выделяем память под ячейк
            ui->tableWidget->setItem(i,0,item); //сообщаем таблице, что мы вручили выд память под ячейку
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
            ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
            error = true;
        }
    }
    if (error)
    {
        ui->label_sf->hide();
        ui->label_min->hide();
        ui->label_max->hide();
        QMessageBox::information(this,"Внимание","Таблица заполнена не корректно");//выводим ошибку
        delete [] mas;
        return;
    }
    int sum=0;// запись нулевого значения массива

    for (int i=0;i<size;i++)
    {
        sum+=mas[i];
    }
    sf = sum/size;
    ui->label_sf->setText(QString::number(sf));
    ui->label_sf->show();
}

void MainWindow::on_pushButton_2_clicked()//Пузырьковая
{
    QElapsedTimer timer;
    timer.start();
    QDeadlineTimer deadline(1500);
    int size = ui->tableWidget->rowCount();//получаем количество строк
    int *mas= new int[size];//Создаем динамический массив
    bool flag2;

    bool error = false;

    for (int i=0;i<size;i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i,0); //Получаем указатель на ячейку
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag2);
            if (flag2)
            {
                ui->tableWidget->item(i,0)->setBackground(Qt::white);
            }
            if(!flag2)
            {
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
                ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
                error = true;
            }
        }
        else
        {
            item = new QTableWidgetItem;//выделяем память под ячейк
            ui->tableWidget->setItem(i,0,item); //сообщаем таблице, что мы вручили выд память под ячейку
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
            ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
            error = true;
        }
    }
    if (error)
    {
        ui->label_sf->hide();
        ui->label_min->hide();
        ui->label_max->hide();
        QMessageBox::information(this,"Внимание","Таблица заполнена не корректно");//выводим ошибку
        delete [] mas;
        return;
    }
    else
    {
        bool check=true;
        for (int i=0;i<size;i++)// перебираем элементы, которые расположены до i-го элемента
        {
            for (int j=0;j<i;j++)// перебираем элементы, которые расположены до i-го элемента
            {
                if(check && deadline.hasExpired())
                {
                    QMessageBox::information(this,"Внимание","Время работы более 3-х секунд!");//выводим ошибку
                    check=false;
                }

                if (mas[j] > mas[i])//меняем местами 2 эл массива
                {
                    int temp = mas[i];
                    mas[i]=mas[j];
                    mas[j]=temp;
                }
            }
        }
        for (int i=0;i<size;i++)
        {
            ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
        }
        ui->pushButton_4->setEnabled(true);//Удаление дубликатов
        ui->label_4->show();//Дубликаты
    }
}

void MainWindow::on_pushButton_3_clicked() //Гномья Сортировка
{
    QElapsedTimer timer;
    timer.start();
    QDeadlineTimer deadline(1500);
    int size = ui->tableWidget->rowCount();//получаем количество строк
    int *mas= new int[size];//Создаем динамический массив
    bool flag2;

    bool error = false;

    for (int i=0;i<size;i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i,0); //Получаем указатель на ячейку
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag2);
            if (flag2)
            {
                ui->tableWidget->item(i,0)->setBackground(Qt::white);
            }
            if(!flag2)
            {
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
                ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
                error = true;
            }
        }
        else
        {
            item = new QTableWidgetItem;//выделяем память под ячейк
            ui->tableWidget->setItem(i,0,item); //сообщаем таблице, что мы вручили выд память под ячейку
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
            ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
            error = true;
        }
    }
    if (error)
    {
        ui->label_sf->hide();
        ui->label_min->hide();
        ui->label_max->hide();
        QMessageBox::information(this,"Внимание","Таблица заполнена не корректно");//выводим ошибку
        delete [] mas;
        return;
    }
    else
    {
        bool check=true;
        int i = 1; // счётчик
        while (i < size)
        {
            if(check && deadline.hasExpired())
            {
                QMessageBox::information(this,"Внимание","Время работы более 3-х секунд!");//выводим ошибку
                check=false;
            }
            if (i == 0) {
                i = 1;
            }
            if (mas[i-1] <= mas[i]) {
                ++i; // идём вперед
            } else {
                // меняем местами
                long tmp = mas[i];
                mas[i] = mas[i-1];
                mas[i-1] = tmp;
                // идём назад
                --i;
            }
        }
        for (int i=0;i<size;i++)
        {
            ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
        }
        ui->pushButton_4->setEnabled(true);//Удаление дубликатов
        ui->label_4->show();//Дубликаты
    }
}

void MainWindow::on_pushButton_rash_clicked()//Сортировка расческой
{
    QElapsedTimer timer;
    timer.start();
    QDeadlineTimer deadline(1500);
    int size = ui->tableWidget->rowCount();//получаем количество строк
    int *mas= new int[size];//Создаем динамический массив
    bool flag2;

    bool error = false;

    for (int i=0;i<size;i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i,0); //Получаем указатель на ячейку
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag2);
            if (flag2)
            {
                ui->tableWidget->item(i,0)->setBackground(Qt::white);
            }
            if(!flag2)
            {
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
                ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
                error = true;
            }
        }
        else
        {
            item = new QTableWidgetItem;//выделяем память под ячейк
            ui->tableWidget->setItem(i,0,item); //сообщаем таблице, что мы вручили выд память под ячейку
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
            ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
            error = true;
        }
    }
    if (error)
    {
        ui->label_sf->hide();
        ui->label_min->hide();
        ui->label_max->hide();
        QMessageBox::information(this,"Внимание","Таблица заполнена не корректно");//выводим ошибку
        delete [] mas;
        return;
    }
    {
        int step=size; // готовим начальный шаг
        bool pr_peres=true;
        bool check=true;// вводим контроль перестановки
        while(step>1 or pr_peres)
        {
            if(check && deadline.hasExpired())
            {
                QMessageBox::information(this,"Внимание","Время работы более 3-х секунд!");//выводим ошибку
                check=false;
            }
            step/=1.247f; // шаг на этом проходе.  На первом проходе получается примерно 80% от размера массива,
            // и легкие элементы в хвосте переносятся в первые 20%
            if (step<1) step=1; // 0 быть не может, присвоим 1
            pr_peres =false;
            for (int i=0; i+step<size;++i)
            { // двигаемся, пока сравниваемый элемент (на шаг от текущего) в массиве
                if(mas[i]>mas[i+step])
                {
                    int tmp=mas[i];
                    mas[i]=mas[i+step];
                    mas[i+step]=tmp;
                    pr_peres=true;//перестановка выполнена
                }
            }
        }
        for (int i=0;i<size;i++)
        {
            ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
        }
        ui->pushButton_4->setEnabled(true);//Удаление дубликатов
        ui->label_4->show();//Дубликаты
    }
}

void MainWindow::on_pushButton_faster_clicked()//Быстрая сортировка
{
    QElapsedTimer timer;
    timer.start();
    QDeadlineTimer deadline(1500);
    int size = ui->tableWidget->rowCount();//получаем количество строк
    int *mas= new int[size];//Создаем динамический массив
    bool flag2;

    bool error = false;

    for (int i=0;i<size;i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i,0); //Получаем указатель на ячейку
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag2);
            if (flag2)
            {
                ui->tableWidget->item(i,0)->setBackground(Qt::white);
            }
            if(!flag2)
            {
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
                ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
                error = true;
            }
        }
        else
        {
            item = new QTableWidgetItem;//выделяем память под ячейк
            ui->tableWidget->setItem(i,0,item); //сообщаем таблице, что мы вручили выд память под ячейку
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
            ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
            error = true;
        }
    }
    if (error)
    {
        ui->label_sf->hide();
        ui->label_min->hide();
        ui->label_max->hide();
        QMessageBox::information(this,"Внимание","Таблица заполнена не корректно");//выводим ошибку
        delete [] mas;
        return;
    }
    else
    {
        FastSort(mas,0,size-1);//вызов функции сортировки массива
        for (int i=0;i<size;i++)
        {
            ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
        }
        ui->pushButton_4->setEnabled(true);//Удаление дубликатов
    }
}

void MainWindow::on_pushButton_monkey_clicked()//Случайная обезьянья сортировка
{
    int size = ui->tableWidget->rowCount();//получаем количество строк
    int *mas= new int[size];//Создаем динамический массив
    bool flag,flag2;
    int razmer = ui->lineEdit->text().toInt(&flag);

    if(razmer>5)
    {
        ui->label_sf->hide();
        ui->label_min->hide();
        ui->label_max->hide();
        QMessageBox::information(this,"Внимание","Для данной сортировки не более 5 элементов!");//выводим ошибку
        return;
    }


    bool error = false;

    for (int i=0;i<size;i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i,0); //Получаем указатель на ячейку
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag2);
            if (flag2)
            {
                ui->tableWidget->item(i,0)->setBackground(Qt::white);
            }
            if(!flag2)
            {
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
                ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
                error = true;
            }
        }
        else
        {
            item = new QTableWidgetItem;//выделяем память под ячейк
            ui->tableWidget->setItem(i,0,item); //сообщаем таблице, что мы вручили выд память под ячейку
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
            ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
            error = true;
        }
    }
    if (error)
    {
        ui->label_sf->hide();
        ui->label_min->hide();
        ui->label_max->hide();
        QMessageBox::information(this,"Внимание","Таблица заполнена не корректно");//выводим ошибку
        delete [] mas;
        return;
    }
    else
    {
        MonkeySort(mas,size);//вызов функции сортировки массива
        for (int i=0;i<size;i++)
        {
            ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
        }
        ui->pushButton_4->setEnabled(true);//Удаление дубликатов
    }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1) //Если меняем количество элементов
{
    ui->label_sf->hide();
    ui->label_min->hide();
    ui->label_max->hide();
    ui->pushButton_max->setEnabled(false);
    ui->pushButton_min->setEnabled(false);
    ui->pushButton_sf->setEnabled(false);
    ui->pushButton_2->setEnabled(false);//пузырьковая
    ui->pushButton_random->setEnabled(false);
    ui->pushButton_3->setEnabled(false);//гномья
    ui->pushButton_rash->setEnabled(false);//расчесткой
    ui->pushButton_faster->setEnabled(false);//быстрая
    ui->pushButton_monkey->setEnabled(false);//макака
    ui->pushButton_search->setEnabled(false);//поиск
    ui->pushButton_4->setEnabled(false);//Удаление дубликатов
}

void MainWindow::on_pushButton_search_clicked() //Кнопка поиска
{
    bool flag,flag2;
    int index_key = ui->lineEdit_indexkey->text().toInt(&flag);//Считываем значение ключа
    int size = ui->tableWidget->rowCount();//получаем количество строк
    int *mas= new int[size];//Создаем динамический массив
    int h=0;//Опорное число
    ui->textEdit->clear();

    if (!flag) //Если введено не число в поиск
    {
        QMessageBox::information(this,"Внимание","Данные некорректны! Введите число!");
        delete [] mas;
        return;
    }
    bool error = false; //Вводим чек на ошибку

    for (int i=0;i<size;i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i,0); //Получаем указатель на ячейку
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag2);
            if (flag2)
            {
                ui->tableWidget->item(i,0)->setBackground(Qt::white);
            }
            if(!flag2)
            {
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
                ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
                error = true;
            }
        }
        else
        {
            item = new QTableWidgetItem;//выделяем память под ячейк
            ui->tableWidget->setItem(i,0,item); //сообщаем таблице, что мы вручили выд память под ячейку
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
            ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
            error = true;
        }
    }
    if (error)
    {
        ui->label_sf->hide();
        ui->label_min->hide();
        ui->label_max->hide();
        QMessageBox::information(this,"Внимание","Таблица заполнена не корректно");//выводим ошибку
        delete [] mas;
        return;
    }
    else
    {
        //БИНАРНЫЙ ПОИСК
        if (!correct(mas, size))//Если массив отсортирован(бинарный поиск)
        {
            //QMessageBox::information(this,"Количество совпадений","Опа, бинарочка");//Бинарный поиск
            int low, high, mid,score;

            low = 0; high = size-1;score=0;

            bool nashel=false;
            for (int i=0;i<size-1;i++)
            {
                while(low<=high)
                {
                    mid = (low+high)/2;
                    if (mas[mid] == index_key)//проверяем ключ со серединным элементом
                    {
                        QString A="Число найдено в строке: ";
                        ui->textEdit->insertPlainText(A+QString::number(mid+1)+"\n");
                        QTableWidgetItem *item = ui->tableWidget->item(mid,0); //Получаем указатель на ячейку
                        item->setBackground(Qt::green);
                        nashel=true;
                        score++;
                        //mas[mid++]=i;
                        mas[mid]++;
                    }
                    if (mas[mid] > index_key) high = mid - 1; // проверяем, какую часть нужно отбросить
                    else low = mid + 1;
                }
            }
            if(nashel)
            {
                QString A="Всего совпадений: ";
                ui->textEdit->insertPlainText(A+QString::number(score)+"\n");
            }
            if(!nashel)
            {
                QMessageBox::information(this,"Внимание","Таких чисел нет в массиве!");
            }
        }

        //ПОСЛЕДОВАТЕЛЬНЫЙ ПОИСК
        if (correct(mas, size))//Если массив не отсортирован(последовательный поиск)
        {
            for (int i = 0; i <size; i++)
            {
                if (mas[i] == index_key)
                { // проверяем равен ли arr[i] ключу
                    mas[h++] = i;
                    QString A="Число найдено в строке: ";
                    ui->textEdit->insertPlainText(A+QString::number(i+1)+"\n");
                    QTableWidgetItem *item = ui->tableWidget->item(i,0); //Получаем указатель на ячейку
                    item->setBackground(Qt::green);
                }
            }
            if (h != 0)
            {
                QString A="Всего совпадений: ";
                ui->textEdit->insertPlainText(A+QString::number(h)+" ");
            }
            else
            {
                QMessageBox::information(this,"Внимание","Таких чисел нет в массиве!");
            }

        }
    }
}

int DeleteDublecate(int *arr, int size) //Удаляем дубликаты
{

    bool var;
    int *temp_massive= new int[size];
    int index = 0;
    for(int i = 0; i < size; i++) {
        int temp_el = arr[i];
        var = true;
        for(int s = 0; (s < size) && var; s++) {
            if(temp_el == temp_massive[s]) var = false;
            else if(s == size-1) {
                temp_massive[index] = arr[i];
                index++;
            }
        }
    }
    for(int i = 0; i < index; i++)
    {
        arr[i] = temp_massive[i];
    }
    return index;
}

void MainWindow::on_pushButton_4_clicked()
{
    int size = ui->tableWidget->rowCount();//получаем количество строк
    int *mas= new int[size];//Создаем динамический массив
    bool flag2;

    bool error = false;

    for (int i=0;i<size;i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i,0); //Получаем указатель на ячейку
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag2);
            if (flag2)
            {
                ui->tableWidget->item(i,0)->setBackground(Qt::white);
            }
            if(!flag2)
            {
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
                ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
                error = true;
            }
        }
        else
        {
            item = new QTableWidgetItem;//выделяем память под ячейк
            ui->tableWidget->setItem(i,0,item); //сообщаем таблице, что мы вручили выд память под ячейку
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
            ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
            error = true;
        }
    }
    if (error)
    {
        ui->label_sf->hide();
        ui->label_min->hide();
        ui->label_max->hide();
        QMessageBox::information(this,"Внимание","Таблица заполнена не корректно");//выводим ошибку
        delete [] mas;
        return;
    }
    else
    {
        if(!correct(mas, size))
        {
            int size1 = DeleteDublecate(mas,size);
            if(size==size1)
            {
                QMessageBox::information(this,"Внимание","Дубликатов нету в массиве!");//выводим ошибку
                delete [] mas;
                return;
            }
            ui->tableWidget->setRowCount(size1);
            for (int i=0;i<size1;i++)
            {
                ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
            }
            ui->lineEdit->setText(QString::number(size1));
            ui->pushButton_max->setEnabled(true);
            ui->pushButton_min->setEnabled(true);
            ui->pushButton_sf->setEnabled(true);
            ui->pushButton_2->setEnabled(true);//пузырьковая
            ui->pushButton_random->setEnabled(true);
            ui->pushButton_3->setEnabled(true);//гномья
            ui->pushButton_rash->setEnabled(true);//расчесткой
            ui->pushButton_faster->setEnabled(true);//быстрая
            ui->pushButton_monkey->setEnabled(true);//макака
            ui->pushButton_search->setEnabled(true);//поиск
        }
        else
        {
            QMessageBox::information(this,"Внимание","Вы изменили значение в массиве и он теперь сортирован неправильно :( \nНажмите на кнопку сортировки и мы удалим дубликаты!");//выводим ошибку
            delete [] mas;
            return;
        }

    }
}

void MainWindow::on_pushButton_5_clicked()//Запись в файл
{
    int size = ui->tableWidget->rowCount();//получаем количество строк
    int *mas= new int[size];//Создаем динамический массив
    bool flag2;

    bool error = false;

    for (int i=0;i<size;i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i,0); //Получаем указатель на ячейку
        if(ui->tableWidget->item(i,0)!= nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag2);
            if (flag2)
            {
                ui->tableWidget->item(i,0)->setBackground(Qt::white);
            }
            if(!flag2)
            {
                ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
                ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
                error = true;
            }
        }
        else
        {
            item = new QTableWidgetItem;//выделяем память под ячейк
            ui->tableWidget->setItem(i,0,item); //сообщаем таблице, что мы вручили выд память под ячейку
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));//Выделение ячейки с ошибкой
            ui->tableWidget->item(i,0)->setBackground(Qt::red); //Устанавливаем красный цвет,информируя об ошибке
            error = true;
        }
    }
    if (error)
    {
        ui->label_sf->hide();
        ui->label_min->hide();
        ui->label_max->hide();
        QMessageBox::information(this,"Внимание","Таблица заполнена не корректно");//выводим ошибку
        delete [] mas;
        return;
    }
    QFile myfile(QFileDialog::getSaveFileName(this,"Сохранить Файл","c:/Qt","Binary(*.bin);; All Files(*.*)"));//Выбор пути для файла
    if (myfile.open(QFile::WriteOnly | QFile::Truncate))//Если файл открылся
    {
        for (int i = 0; i <size; ++i)//Записываем в него значения из массива
        {
            QDataStream out(&myfile);
            out << (qint32) mas[i];//Запись и отступ
        }
    }
    myfile.close();//Закрываем файл
    delete [] mas;//Удаляем массивчик
}

void MainWindow::on_pushButton_6_clicked()//Чтение Файла
{
    QFile file(QFileDialog::getOpenFileName(this,"Открыть файл","c:/Qt","Binary(*.bin);; All Files(*.*)"));//Выбор пути файла
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//Если файл неоткрывается
        return;
    QDataStream in(&file);
    int i=0,t;
    i=file.size()/4;
    ui->tableWidget->setRowCount(i);//Задаем кол-во строк
    ui->lineEdit->setText(QString::number(i));//Меняем значение в лайн эдит
    ui->tableWidget->setColumnCount(1);

    i=0;
    file.seek(0);
    while(!file.atEnd())
    {
        in>>t;

        QTableWidgetItem *item = ui->tableWidget->item(i,0);
        if(item== nullptr)
        {
            item = new QTableWidgetItem();
            ui->tableWidget->setItem(i,0,item);
        }
        item->setText(QString::number(t));
        i++;
    }
    ui->pushButton_max->setEnabled(true);
    ui->pushButton_min->setEnabled(true);
    ui->pushButton_sf->setEnabled(true);
    ui->pushButton_2->setEnabled(true);//пузырьковая
    ui->pushButton_random->setEnabled(true);
    ui->pushButton_3->setEnabled(true);//гномья
    ui->pushButton_rash->setEnabled(true);//расчесткой
    ui->pushButton_faster->setEnabled(true);//быстрая
    ui->pushButton_monkey->setEnabled(true);//макака
    ui->pushButton_search->setEnabled(true);//поиск
    ui->pushButton_5->setEnabled(true);//сохранение
    file.close();//Закрываем файл
}
//    int row = 0;//Вводим переменную
//    int g=file.size()/4;
//    while (!file.atEnd()) {
//        //Цикл пока файл не кончится
//        QString line = file.readLine();//Считываем построчные значения

//        QStringList ss = line.split('\t');//Ставим момент разделения чисел

//        if(ui->tableWidget->rowCount() < row + 1);
//        ui->tableWidget->setRowCount(row + 1);
//        if(ui->tableWidget->columnCount() < ss.size())
//            ui->tableWidget->setColumnCount( ss.size() );

//        for( int column = 0; column < ss.size(); column++) //Цикл где передаем таблице значения цифр в массиве
//        {
//            QTableWidgetItem *newItem = new QTableWidgetItem( ss.at(column) );
//            ui->tableWidget->setItem(row, column, newItem);
//        }
//        row++;
//    }
