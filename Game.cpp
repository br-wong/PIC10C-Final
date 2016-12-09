#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include <QBrush>
#include <QGraphicsScene>

Game::Game(QWidget *parent){
    //Create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

    setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));

    //Make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    //It can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //Create the player
    player = new Shooter();
    player->setPixmap(QPixmap(":/images/playerTank.png"));
    //player->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    player->setScale(qreal(2.0));
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    //Create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    //Spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //Play background music
    QMediaPlayer *bgMusic = new QMediaPlayer();
    bgMusic->setMedia(QUrl("qrc:/sounds/bgSound.mp3"));
    bgMusic->play();

    show();
}
