#include <QPixmap>
#include <QImage>
#include <QLabel>
#include "RectificationManager.h"
#include "RectificationImage.h"

QPixmap RectificationManager::openImage (QString arqname)
{
    QLabel *msgbox = new QLabel(arqname);
    //msgbox->show();
    QPixmap img (arqname);
    imagem = new RectificationImage();
    QImage *image;
    *image = img.toImage();
    imagem -> setImagem(image);
    int h = img.height();
    QString s = QString::number(h,10);
    msgbox->setText(s);
    //QLabel *msgbox = new QLabel(arqname);
    msgbox->show();
    return img;
}

void RectificationManager::saveImage (QString arqname)
{
    //salvar
}

