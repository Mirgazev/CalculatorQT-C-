#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_tabl_clicked();

    void on_pushButton_sl_clicked();

    void on_pushButton_sum_nech_clicked();

    void on_pushButton_sum_ch_clicked();

    void on_pushButton_polog_100_clicked();

    void on_pushButton__proiz_polog_clicked();

    void on_pushButton_kolvo_otr_zn_clicked();

    void on_pushButton_cht_ind_clicked();

    void on_pushButton_cht_neind_clicked();

    void on_pushButton_factorial_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
