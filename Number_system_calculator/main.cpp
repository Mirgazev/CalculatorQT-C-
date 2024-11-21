#include "calculatormirkal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalculatorMirKal w;
    w.show();

    return a.exec();
}
