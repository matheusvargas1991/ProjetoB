#include <QPixmap>
#include "formrectification.h"
#include "ui_formrectification.h"
//#include "RectificationMatrix.h"
#include "RectificationManager.h"
#include <QFileDialog>
#include <QLabel>
#include <QMouseEvent>

FormRectification::FormRectification(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormRectification)
{
    ui->setupUi(this);
    connect(ui-> openButton_4,SIGNAL(clicked()),this,SLOT(chooseImage()));
    ui->label->setMouseTracking(true);
    ui->label->linha = ui->linha;
    ui->label->coluna = ui->coluna;
    recman.imagem->zoomLabel = ui->zoomLabel;
    ui->label->recimage = recman.imagem;
    //ui->label->mouseMoveEvent(QMouseEvent *event);
    //setMouseTracking(false);
}

void FormRectification::chooseImage(){

    /*RectificationMatrix m(3,3);
    m.fillrand(10);
    m.report();*/
    //RectificationManager recman;
/*
    QString arquivo_nome = Q3FileDialog::getOpenFileName
      (".",QString::null,this,"Open File Dialog","Select one image ORIGINAL to load") ;
  */
    QString arquivo_nome = QFileDialog::getOpenFileName(this,
      tr("Select one image ORIGINAL to load"), ".", tr("Image Files (*.png *.jpg *.bmp)"));

    QPixmap img = recman.openImage(arquivo_nome);
    int h = img.width();
    QString s = QString::number(h,10);
    QLabel *msgbox = new QLabel(s);
    msgbox->show();
    ui ->label ->setPixmap(img.scaled(641,431,Qt::KeepAspectRatio));
}
/*
void FormRectification::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    QString sx = QString::number(x,10);
    QString sy = QString::number(y,10);
    ui->coluna->setText(sx);
    ui->linha->setText(sy);
}
*/
FormRectification::~FormRectification()
{
    delete ui;
}
