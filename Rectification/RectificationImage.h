#ifndef RECTIFICATIONIMAGE_H
#define RECTIFICATIONIMAGE_H

#include <qimage.h>
#include <qwidget.h>
#include <qpixmap.h>
#include <qlabel.h>

class RectificationImage:public QWidget
{
 Q_OBJECT

 private:
 QImage *imagem;
 int pontos[20][2]; // coluna, linha
 QPixmap *pix;

 public:
 QLabel *zoomLabel;
 void setImagem (QImage *img);
 QImage *getImagem ();
 void setPix (QPixmap *p);
 void setPonto (int col, int lin, int valor);
 void drawZoom(int x, int y);

 public slots:
 //void drawZoom(int x, int y);

 signals:
 void clicked();

};

#endif // RECTIFICATIONIMAGE_H
