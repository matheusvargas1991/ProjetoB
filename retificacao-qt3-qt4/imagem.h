/****************************************************************************
**
**This file was generated by the author
**
**Marcelo Teixeira Silveira, E-FOTO 2005
****************************************************************************/


#ifndef IMAGEM_H
#define IMAGEM_H

#include <qapplication.h>
#include <q3scrollview.h>
#include <qimage.h>
#include <qwidget.h>
#include <qpixmap.h>
//Added by qt3to4:
#include <QPaintEvent>
#include <QMouseEvent>

class Imagem:public QWidget
{
 Q_OBJECT

 public:
 Imagem(int ords); 
 QImage *figura;
 int pontos[20][3]; // coluna, linha, exibir?
 int orides;
 QPixmap *pix;
  
 public slots:
 void openImage(QString arquivo);
 void saveImage(QString arquivo);
 void zeroPontos(int inicio);
 void imageInfo(int enable);
 void drawZoom(int x, int y);

 signals:
 void clicked();
 void moved();
 void explain(const QString&);
 
 protected:
 virtual void paintEvent(QPaintEvent *e);
 virtual void mouseMoveEvent(QMouseEvent *e);
 virtual void mousePressEvent(QMouseEvent *e); 
  
 private:
};

#endif // IMAGEM_H
