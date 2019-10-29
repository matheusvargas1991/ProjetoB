#include "myLabel.h"
#include <QLabel>
#include <QMouseEvent>
#include <QString>
#include <QPainter.h>
#include "ui_formrectification.h"
#include "RectificationImage.h"

myLabel::myLabel (QWidget *parent):QLabel(parent)
{

}

void myLabel::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    QString sx = QString::number(x,10);
    QString sy = QString::number(y,10);
    coluna->setText(sx);
    linha->setText(sy);
    recimage->drawZoom(x,y);
}
