#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include "gpio.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Gui; }
QT_END_NAMESPACE

class Gui : public QWidget
{
    Q_OBJECT

public:
    Gui(QWidget *parent = nullptr);
    ~Gui();

private slots:
    void on_startButton_clicked();
    void on_horizontalSlider_valueChanged(int value);

    void Timer_timeout();

private:
    Ui::Gui *ui;
    QTimer* m_timer;
    bool m_state = false;
    Gpio* m_gpio;
};
#endif // GUI_H
