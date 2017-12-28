#include "ghost.h"

Ghost::Ghost(QObject *parent) : QObject(parent), QGraphicsItem()
{
    angle = 0;
    setRotation(angle);
    Vy = 1;
    //SpriteImage = new QPixmap(":s4");
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Ghost::MoveOnTime);
    timer->start(1000/200);
}

QRectF Ghost::boundingRect() const
{
    return QRectF(-10, -10, 20, 20);
}

void Ghost::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    counter++;
    if(counter > 16)counter = 0;
    //painter->setBrush(Qt::green);
    //painter->drawEllipse(-10, -10, 20, 20);
    painter->setBrush(Qt::green);
    painter->setPen(Qt::green);
    painter->drawEllipse(-10, -10, 20, 10); //верх
    painter->drawRect(-10, -5, 20, 10); //туловище

    painter->drawEllipse(-10, 5, 3, 3);
    painter->drawEllipse(7, 5, 3, 3);

    if(counter > 8)
    painter->drawEllipse(-3, 5, 6, 3);
    else
    {
    painter->drawEllipse(-5, 5, 3, 3);
    painter->drawEllipse(1, 5, 3, 3);
    }

    painter->setBrush(Qt::white); //белки глаз
    painter->drawEllipse(-8, -5, 7, 8);
    painter->drawEllipse(2, -5, 7, 8);

    painter->setBrush(Qt::black); //зрачки
    painter->setPen(Qt::black);
    if(Vy == 1){ //взгляд вниз
    painter->drawEllipse(-6, -2, 3, 3);
    painter->drawEllipse(4, -2, 3, 3);
    }
    if(Vy == -1){ //взгляд вверх
    painter->drawEllipse(-6, -5, 3, 3);
    painter->drawEllipse(4, -5, 3, 3);
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Ghost::MoveOnTime()
{
    if(KeyA){
        if(GetAsyncKeyState(VK_LEFT))go();
        if(GetAsyncKeyState(VK_RIGHT))go();
        if(GetAsyncKeyState(VK_UP))go();
        if(GetAsyncKeyState(VK_DOWN))go();
    }

    setPos(mapToParent(0, Vy));
    if(this->y() - 10 < -260){
        this->setY(250);
    }
    if(this->y() + 10 > 260){
        this->setY(-250);
    }
}

void Ghost::stop()
{
    Vy = 0;
}

void Ghost::go()
{
    Vy = 1;
}
