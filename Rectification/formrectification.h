#ifndef FORMRECTIFICATION_H
#define FORMRECTIFICATION_H

#include <QMainWindow>
#include "RectificationManager.h"

namespace Ui {
    class FormRectification;
}

class FormRectification : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormRectification(QWidget *parent = 0);
    ~FormRectification();

public slots:
        void chooseImage();
    //    void mousePressEvent(QMouseEvent *event);
/*protected:
    void mouseMoveEvent(QMouseEvent *event);*/

public:
    Ui::FormRectification *ui;

private:
    RectificationManager recman;
};

#endif // FORMRECTIFICATION_H
