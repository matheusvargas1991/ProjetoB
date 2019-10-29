#include <QtGui/QApplication>
#include "formrectification.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormRectification w;
    w.show();

    return a.exec();
}
