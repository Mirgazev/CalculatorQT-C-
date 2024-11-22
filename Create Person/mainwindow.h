#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_raschet_clicked();

    void on_pushButton_sbros_clicked();

    void on_lineEdit_name_textChanged(const QString &arg1);

    void on_lineEdit_power_textChanged(const QString &arg1);

    void ostatok(); //Функция которая считает остаток очков

    void on_lineEdit_lovkost_textChanged(const QString &arg1);

    void on_lineEdit_intelekt_textChanged(const QString &arg1);

    void on_lineEdit_udacha_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
