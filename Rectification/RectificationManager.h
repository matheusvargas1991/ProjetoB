#ifndef RECTIFICATIONMANAGER_H
#define RECTIFICATIONMANAGER_H

#include "RectificationImage.h"
#include <QPixmap>
#include <QString>

class RectificationManager:public QWidget
{
 Q_OBJECT

 private: 
 QPixmap imgpix;

 public:
 RectificationImage *imagem;
 QPixmap openImage (QString arqname);
 void saveImage (QString arqname); 

 public slots:
 //void drawZoom(int x, int y);

 signals:
 //void clicked();

};

#endif // RECTIFICATIONMANAGER_H
