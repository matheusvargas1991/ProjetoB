#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QWidget>
#include <QObject>
#include <QMouseEvent>
#include <QImage>
#include "RectificationImage.h"

class myLabel : public QLabel
{

    Q_OBJECT

  public:
    explicit myLabel(QWidget *parent = 0);
    QLabel *linha;
    QLabel *coluna;
    RectificationImage *recimage;

  protected:
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // MYLABEL_H
