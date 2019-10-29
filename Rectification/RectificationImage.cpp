#include <qimage.h>
#include <qwidget.h>
#include <qpixmap.h>
#include <qpainter.h>
#include "RectificationImage.h"

void RectificationImage::setImagem (QImage *img)
{
    imagem = img;
}

QImage *RectificationImage::getImagem ()
{
    return imagem;
}

void RectificationImage::setPix (QPixmap *p)
{
    pix = p;
}

void RectificationImage::setPonto (int col, int lin, int valor)
{
    pontos[col][lin] = valor;
}

void RectificationImage::drawZoom(int x, int y)
{
 // Desenha o zoom
 QPixmap *pix = new QPixmap(20,20);
 //bitBlt(pix,0,0,this,x-10,y-10,20,20);
 //QPainter::drawImage()
 QPainter paint;
 paint.drawImage(0,0,*imagem,x-10,y-10,20,20);
 /*
 QBrush brush( Qt::yellow, Qt::SolidPattern );
 QBrush bgbrush( Qt::green, Qt::SolidPattern );
 paint.begin(pix);
 // Bordas
 if (x-10<0)
   paint.fillRect(0,0,10-x,20,bgbrush);
 if (y-10<0)
   paint.fillRect(0,0,20,10-y,bgbrush);
 if (x+9>imagem->width()-1)
   paint.fillRect(19,0,(imagem->width()-1)-x-9,20,bgbrush);
 if (y+9>imagem->height()-1)
   paint.fillRect(0,19,20,(imagem->height()-1)-y-9,bgbrush);
 // Desenha ponto central
 paint.fillRect(10,10,1,1,brush);
 paint.end();
 // Copia do buffer para o Label*/
 zoomLabel->setPixmap(*pix);
 delete pix;
}
