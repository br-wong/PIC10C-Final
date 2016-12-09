#include "Target.h"
#include "Game.h"
#include "Mainwindow.h"

#include <QGraphicsScene>
#include <QDebug>

extern Game *newGame;

Target::Target(){
    //Set random position for target to spawn
    int random_pos = rand() % 700;
    setPos(random_pos, 0);
    setTransformOriginPoint(50, 50);
    setRotation(180.0);
    setScale(qreal(2.0));

    QTimer *timer = new QTimer();

    //Connects the timer to this class' move functions
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(20);

    //Set graphic
    setPixmap(QPixmap(":/images/enemyTank.png"));
}

void Target::move(){
    //Move target straight down
    setPos(x(), y() + 3);

    if(pos().y() - pixmap().height() > 600){
        //For every enemy that passes the shooter, decrease the shooter's health
        //Make it so enemy has to touch? - Make them faster?
        newGame->health->decrease();

        scene()->removeItem(this);
        qDebug() << "Bullet deleted";
        delete this;
    }
}
