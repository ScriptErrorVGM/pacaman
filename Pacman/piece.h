#ifndef PIECE_H
#define PIECE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class Piece: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Piece(QObject *parent = 0);
    ~Piece();

signals:

public slots:

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PIECE_H
