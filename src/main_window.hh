#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <memory>

namespace Ui {
    class main_window;
}

namespace my {

class main_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit main_window(QWidget* parent = 0);
    ~main_window();

private slots:
    void on_actionExit_triggered();

private:
    std::unique_ptr<Ui::main_window> ui;
};

}

#endif // MAINWINDOW_H