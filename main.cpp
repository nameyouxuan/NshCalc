#include "nshcalc.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NshCalc w;
    w.show();
    return a.exec();
}
