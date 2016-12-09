#ifndef TARGET_H
#define TARGET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Target: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Target();

public slots:
    void move();
};

#endif // TARGET_H
