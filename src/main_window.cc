#include "main_window.hh"

#include "main_window_ui.hh"

namespace my {

main_window::main_window(QWidget* parent) :
    QMainWindow(parent),
    ui(std::make_unique<Ui::main_window>())
{
    this->ui->setupUi(this);
}

main_window::~main_window()
{
    
}

void main_window::on_actionExit_triggered()
{
    this->close();
}

}