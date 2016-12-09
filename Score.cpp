#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
   //Initialize score to 0
   score = 0;
   setPlainText(QString("Score: ") + QString::number(score));
   setDefaultTextColor(Qt::blue);
   setFont(QFont("Arial", 16));
}

void Score::increase(){
    ++score;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore(){
    return score;
}


