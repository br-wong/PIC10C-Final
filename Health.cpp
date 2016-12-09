#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent)
{
    //Initialize health to 5
    health = 5;

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Arial", 16));
}

void Health::decrease(){
    --health;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth(){
    return health;
}
