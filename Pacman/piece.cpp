#include "piece.h"

Piece::Piece(QObject *parent):QObject(parent), QGraphicsItem()
{

}

Piece::~Piece()
{

}

QRectF Piece::boundingRect() const
{
    return QRectF(-5,-5,10,10);
}

void Piece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(-5, -5, 10, 10);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
