#include <QApplication>

#include "main_window.hh"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    my::main_window w;
    w.show();

    return a.exec();
}