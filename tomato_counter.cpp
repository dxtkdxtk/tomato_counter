#include "tomato_counter.h"


tomato_counter::tomato_counter(QWidget *parent) : QMainWindow(parent)
{
    ui_.setupUi(this);
    ui_.timeCounter->display("00:00");
    run_thread_.RegisterMsg(&msg_);
    run_thread_.RegisterUI(&ui_);
    connect(ui_.exitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui_.startButton, SIGNAL(clicked()), this, SLOT(StartCounter()));
    connect(ui_.stopButton, SIGNAL(clicked()), this, SLOT(StopCounter()));
    connect(this, SIGNAL(notify_sig(QString)), this, SLOT(notify_slot(QString)));

}

tomato_counter::~tomato_counter()
{

}

void tomato_counter::StartCounter()
{
    
    run_thread_.start();
}
void tomato_counter::StopCounter()
{
    run_thread_.Stop();
}
