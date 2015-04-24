#ifndef TOMATO_COUNTER_H
#define TOMATO_COUNTER_H

#include <QtWidgets/QMainWindow>
#include <QTime>
#include <QThread>
#include <QMessageBox>
#include "ui_tomato_counter.h"


class Message : QWidget
{
    Q_OBJECT
public:
    Message()
    {
        connect(this, SIGNAL(notify_sig(QString)), this, SLOT(notify_slot(QString)));
        msg_.setParent(0);
        msg_.setWindowFlags(Qt::WindowStaysOnTopHint);
    }
    void notify(QString str)
    {
        emit notify_sig(str);
    }
signals:
    void notify_sig(QString str);
private slots:
    void notify_slot(QString str)
    {
        msg_.setText(str);
        msg_.exec();
    }
private:
    QMessageBox msg_;
};

class RunCounterThread : public QThread
{
    Q_OBJECT
public:
    enum ThreadStatus
    {
        WORK = 0,
        REST
    };
    RunCounterThread()
    {
        stop_ = false;
        status_ = WORK;
        work_time_ = 1500000;
        rest_time_ = 300000;
        elapse_time_ = work_time_;
        isrunning_ = false;
        ui_ = nullptr;
    }
    ~RunCounterThread(){ ui_ = nullptr; }
    void RegisterUI(Ui::tomato_counterClass *ui){ ui_ = ui; }
    void RegisterMsg(Message *msg){ msg_ = msg; };
    void ChangeStatus()
    {
        if (status_ == WORK)
        {
            status_ = REST;
            elapse_time_ = rest_time_;
            ui_->startButton->setText("rest now");
            msg_->notify("work timeout! have a rest!");
        }
        else
        {
            status_ = WORK;
            elapse_time_ = work_time_;
            ui_->startButton->setText("start work now");
            msg_->notify("rest timeout! work now!");
        }
    }

signals:
public slots:
    void Stop(){ if (stop_ == false && isrunning_ == true) stop_ = true; }
protected:
    void run()
    {
        if (ui_)
        {
            QTime t;
            t.start();
            isrunning_ = true;
            //经过时间
            int misec;
            //主循环
            while (!stop_)
            {
                misec = t.elapsed();
                ui_->timeCounter->display(QTime::fromMSecsSinceStartOfDay(misec).toString("mm:ss"));
                msleep(1);
                //触发时间溢出
                if (misec >= elapse_time_)
                {
                    ChangeStatus();
                    break;
                }
            }
            isrunning_ = false;
            if (stop_)
            {
                stop_ = false;
                ChangeStatus();
            }
            ui_->timeCounter->display("00:00");
        }
    }
private:
    Ui::tomato_counterClass *ui_;
    Message *msg_;
    bool stop_;
    bool isrunning_;
    ThreadStatus status_;
    int elapse_time_;
    int work_time_;
    int rest_time_;
};

// 主窗口
class tomato_counter : public QMainWindow
{
    Q_OBJECT
public:
    //构造函数中连接信号槽
    tomato_counter(QWidget *parent = 0);
    ~tomato_counter();
private slots:
    void StartCounter();
    void StopCounter();
private:
    Ui::tomato_counterClass ui_;
    RunCounterThread run_thread_;
    Message msg_;
};



#endif // TOMATO_COUNTER_H
