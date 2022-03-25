#include "gui.h"
#include "ui_gui.h"

Gui::Gui(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Gui)
{
    ui->setupUi(this);

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Gui::Timer_timeout);
    m_gpio = new Gpio(this);
}

Gui::~Gui()
{
    delete ui;
}

void Gui::on_startButton_clicked()
{
    m_timer->start(1000 / ui->horizontalSlider->value());
}

void Gui::on_horizontalSlider_valueChanged(int value)
{
    m_timer->setInterval(1000 / value); // T[ms] = 1000 / f
}

void Gui::Timer_timeout()
{
    m_state = !m_state;
    ui->blinkLabel->setNum(m_state);
    m_gpio->set(LEDS[0], m_state);
}
