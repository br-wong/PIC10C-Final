#ifndef SHOOTER_H
#define SHOOTER_H

#include <QGraphicsRectItem>

class Shooter : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawn();
};

#endif // SHOOTER_H
