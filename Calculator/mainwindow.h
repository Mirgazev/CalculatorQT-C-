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
    void on_radioButton_sum_clicked();

    void on_pushButton_clicked();

    void on_radioButton_sub_clicked();

    void on_radioButton_mul_clicked();

    void on_radioButton_del_clicked();

    void on_radioButton_stepen_clicked();

    void on_radioButton_koren_clicked();

    void on_radioButton_sin_clicked();

    void on_radioButton_cos_clicked();

    void on_radioButton_arcsin_clicked();

    void on_radioButton_arccos_clicked();

    void on_radioButton_tg_clicked();

    void on_radioButton_arctg_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
