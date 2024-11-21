#ifndef CALCULATORMIRKAL_H
#define CALCULATORMIRKAL_H

#include <QMainWindow>

namespace Ui {
class CalculatorMirKal;
}

class CalculatorMirKal : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalculatorMirKal(QWidget *parent = nullptr);
    ~CalculatorMirKal();

private slots:
    void on_pushButton_name_clicked();

private:
    Ui::CalculatorMirKal *ui;
};

#endif // CALCULATORMIRKAL_H
