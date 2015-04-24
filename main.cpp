#include "tomato_counter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    tomato_counter w;
    w.show();
    return app.exec();
}
