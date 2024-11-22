#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include "ctime"
#include <QDeadlineTimer>
#include <QfILE>
#include <QTextStream>
#include <QFileDialog>
#include <QStandardItemModel>

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
    void on_pushButton_clicked();

    void on_pushButton_random_clicked();

    void on_pushButton_min_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_max_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_sf_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_rash_clicked();

    void on_pushButton_faster_clicked();

    void on_pushButton_monkey_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *csvModel;
};

#endif // MAINWINDOW_H
