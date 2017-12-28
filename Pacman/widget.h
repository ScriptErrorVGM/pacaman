#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QShortcut>
#include <QTimer>
#include <QKeyEvent>

#include <pacman.h>
#include <wallblock.h>
#include <ghost.h>
#include <piece.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    QList<QGraphicsItem *> wallblocks;
    QList<Ghost *> ghosts;
    Ghost *ghost;
    QList<QGraphicsItem *> pieces;
    Ui::Widget *ui;
    QGraphicsScene *scene;
    PacMan *pacman;    
    QTimer *timer;
    double countscope = 0, bpause = 0;
    double countdeath = 0;
    bool die = 0;
    void incrementScore();
    void death();
    void restart();
    void win();
    void nextlevel(int level);
    QByteArray block, block1, block2, block3;
    QPixmap d, w;
    QGraphicsItem *dl, *wl;
    void keyPressEvent(QKeyEvent *);
    int score = 0, level = 1;
    void pause();
    void endpause();

private slots:
     void stop(QGraphicsItem * item);
     void revive();     
};

#endif // WIDGET_H
