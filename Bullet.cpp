#include "Bullet.h"
#include "Target.h"
#include "Game.h"
#include "Mainwindow.h"

#include <QGraphicsScene>
#include <QList>
#include <QMediaPlayer>
#include <unistd.h>

extern Game *newGame;

Bullet::Bullet(){
    //Draw image with QGraphicsPixmap
    setPixmap(QPixmap(":/images/clash2.png"));
    setScale(qreal(0.12));


    QTimer *timer = new QTimer();

    //Connects the timer to this class' move functions
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(auto item : colliding_items){
        if(typeid(*item) == typeid(Target)){

            //Target *targetItem = (Target*)item;

            QMediaPlayer *bombSound = new QMediaPlayer();
            bombSound->setMedia(QUrl("qrc:/sounds/bomb.mp3"));
            bombSound->play();

            //Increase the score for each enemy hit
            newGame->score->increase();

            //Remove both the bullet and target if they collide
            //targetItem->setPixmap(QPixmap(":/images/enemyDead.png"));
            //sleep(4.0);

            scene()->removeItem(item);
            scene()->removeItem(this);

            //Free memory
            delete item;
            delete this;

            //Return here because we don't want to execute block of code below with a deleted item
            return;
        }
    }

    //Move bullet straight up from origin point
    setPos(x(), y() - 10);

    //Delete the bullet's memory when it's out of our sight
    if(pos().y() + pixmap().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
