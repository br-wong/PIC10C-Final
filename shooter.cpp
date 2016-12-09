#include "Shooter.h"
#include "Bullet.h"
#include "Target.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMediaPlayer>

void Shooter::keyPressEvent(QKeyEvent *event)
{
    //Move coordinates of shooter based on key pressed
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0)
            setPos(x() - 12.0, y());
    }else if(event->key() == Qt::Key_Right){
        if(pos().x() + pixmap().width() < scene()->width())
            setPos(x() + 12.0, y());
    }
    /*else if(event->key() == Qt::Key_Up){
        setPos(x(), y() - 10.0);
    }else if(event->key() == Qt::Key_Down){
        setPos(x(), y() + 10.0);
    }*/

    //If spacebar is clicked, shoot a bullet
    if(event->key() == Qt::Key_Space){
        Bullet *bullet = new Bullet();

        QMediaPlayer *shootSound = new QMediaPlayer();
        shootSound->setMedia(QUrl("qrc:/sounds/shoot.mp3"));

        //Check to see if bullet sound is already playing. If so reset it over and over for each shot
        if(shootSound->state() == QMediaPlayer::PlayingState){
            shootSound->setPosition(0);
        }else if(shootSound->state() == QMediaPlayer::StoppedState){
            shootSound->play();
        }

        //Add bullet to the same scene our shooter is in
        bullet->setPos(x() + 23.0 , y() - 40.0);
        scene()->addItem(bullet);
    }
}

void Shooter::spawn(){
    Target *target = new Target();
    scene()->addItem(target);
}
