#ifndef WALLBLOCK_H
#define WALLBLOCK_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class WallBlock: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit WallBlock(QObject *parent = 0);
    ~WallBlock();

signals:

public slots:

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // WALLBLOCK_H
