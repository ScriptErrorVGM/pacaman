#include "pacman.h"
#ifdef Q_OS_WIN
#include <windows.h>
#endif

PacMan::PacMan(QObject *parent) : QObject(parent), QGraphicsItem()
{
    angle = 0;
    setRotation(angle);
    SpritePos = 0;
    SpriteImage = new QPixmap(":s4");
}

QRectF PacMan::boundingRect() const
{
    return QRectF(-10, -10, 20, 20);
}

void PacMan::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-10,-10, *SpriteImage, SpritePos, 0, 20,20);
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &PacMan::NextFrame);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void PacMan::MoveOnTime()
{
    QList<QGraphicsItem *> foundItems = scene()->items(QPolygonF()
                                                       << mapToScene(0, 0)
                                                       << mapToScene(-10, 12)
                                                       << mapToScene(10, 12));
    foreach (QGraphicsItem *item, foundItems) {
        if (item == this)
            continue;
        emit signalCheckItem(item);
    }


    SpritePos += 20;
    if (SpritePos >= 80 ) SpritePos = 0;

    setPos(mapToParent(0, Vx));

    if(this->x() - 10 < -260){
        this->setX(250);
    }
    if(this->x() + 10 > 260){
        this->setX(-250);
    }
    if(this->y() - 10 < -260){
        this->setY(250);
    }
    if(this->y() + 10 > 260){
        this->setY(-250);
    }

    bool cross = 0;
    if(KeyA){
        if(GetAsyncKeyState(VK_LEFT))tern = 1;
        if(GetAsyncKeyState(VK_RIGHT))tern = 2;
        if(GetAsyncKeyState(VK_UP))tern = 3;
        if(GetAsyncKeyState(VK_DOWN))tern = 4;
    }

    if(tern == 1){   //left
        setRotation(180);
        setPos(mapToParent(3, 0));
        if(!scene()->collidingItems(this).isEmpty()){
            cross = 1;
        }
        setPos(mapToParent(-3, 0));
        if(!cross){
            ;
            angle = 90;
            Vx = 1;
            tern = 0;
        }
        else{
            tern = 1;
        }
        setRotation(angle);
    }
    if(tern == 2){   //right
        setRotation(180);
        setPos(mapToParent(-3, 0));
        if(!scene()->collidingItems(this).isEmpty()){
            cross = 1;
        }
        setPos(mapToParent(3, 0));
        if(!cross){
            angle = 270;
            Vx = 1;
            tern = 0;
        }
        else{
            tern = 2;
        }
        setRotation(angle);
    }
    if(tern == 3){  //up
        setRotation(180);
        setPos(mapToParent(0, 3));
        if(!scene()->collidingItems(this).isEmpty()){
            cross = 1;
        }
        setPos(mapToParent(0, -3));
        if(!cross){
            angle = 180;
            Vx = 1;
            tern = 0;
        }
        else{
            tern = 3;
        }
        setRotation(angle);
    }
    if(tern == 4){ //dowen
        setRotation(180);
        setPos(mapToParent(0, -3));
        if(!scene()->collidingItems(this).isEmpty()){
            cross = 1;
        }
        setPos(mapToParent(0, 3));
        if(!cross){
            angle = 0;
            Vx = 1;
            tern = 0;
        }
        else{
            tern = 4;
        }
        setRotation(angle);
    }
}

void PacMan::PushButton(int agle)
{

}

void PacMan::NextFrame(){
    SpritePos += 20;
    if (SpritePos >= 80 ) SpritePos = 0;
    this->update(-10,-10,20,20);
}

void PacMan::stop()
{
    Vx = 0;
}

void PacMan::go()
{
    Vx = 1;
    pacd = 0;
}

void PacMan::die()
{
    pacd = 1;
}
