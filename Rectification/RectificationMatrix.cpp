//Para exibir graficamente
//#include <qtable.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <qstring.h>
#include <QLabel>
#include "RectificationMatrix.h"
#include <stdio.h>
#include <time.h>

using namespace std;

//IMPLEMENTACOES

RectificationMatrix::RectificationMatrix(int linha, int coluna)
{
 int i;
 lin = linha;
 col = coluna;
 m = new long double*[lin];
 for (i=0;i<lin;i++)
  m[i] = new long double[col];
}

//RectificationMatrix::~RectificationMatrix()  { delete m;  }

void RectificationMatrix::atribui(int linha,int coluna,long double val)
{
 m[linha][coluna] = val;
}

void RectificationMatrix::show()
{
 int i,j;
 for (i=0;i<lin;i++)
 {
  for (j=0;j<col;j++)
  {
   cout << m[i][j] << " ";
   if (j == (col-1)) cout << endl;
  }
 }
}

void RectificationMatrix::report()
{
 int i,j;
 QString msg,s;

 msg="";
 for (i=0;i<lin;i++)
 {
   msg=msg+"| ";
   for (j=0;j<col;j++)
   {
       s = QString::number(m[i][j],'f',10);
       s.truncate(10);
       msg=msg+" "+s;
   }
   msg=msg+" |\n";
 }
 QLabel *msgbox = new QLabel(msg);
 msgbox->show();
}

void RectificationMatrix::fillrand(int lim)
{
 int i,j;
 srand(time(NULL));
 for (i=0;i<lin;i++)
 {
  for (j=0;j<col;j++)
  {
   m[i][j] = floor(rand() % lim);
  }
 }
}

void RectificationMatrix::identidade(void)
{
 int i,j;
 if (lin == col)
 {
   for (i=0;i<lin;i++)
   {
      for (j=0;j<col;j++)
      {
        if (i == j)
        {
           m[i][j] = 1;
        }
        else
        {
           m[i][j] = 0;
        }
      }
   }
 }
 else
 {
      cout << "Impossivel criar identidade";
 }
}

RectificationMatrix RectificationMatrix::soma(RectificationMatrix m1)
{
              int  i,j;
              RectificationMatrix soma(lin,col);
              if ((m1.col==col)&&(m1.lin==lin))
              {
                    for (i=0; i<lin; i++)
                    {
                            for (j=0; j<col; j++)
                                soma.m[i][j]=m1.m[i][j]+m[i][j];
                    }
              }
              else
                   cout << "RectificationMatrixes devem ser do mesmo tamanho! \n";
              return soma;
}

RectificationMatrix RectificationMatrix::subtrai(RectificationMatrix m1)
{
              // A.subtrai(B)
             // Faz   A - B
              int  i,j;
              RectificationMatrix subtrai(lin,col);
              if ((m1.col==col)&&(m1.lin==lin))
              {
                    for (i=0; i<lin; i++)
                    {
                            for (j=0; j<col; j++)
                                subtrai.m[i][j]=m[i][j]-m1.m[i][j];
                    }
              }
              else
                   cout << "RectificationMatrixes devem ser do mesmo tamanho! \n";
              return subtrai;
}

float RectificationMatrix::det()
{
  int i,j,mm,nn;
  float det=0,prdp,prdn;
  if (lin!=col)
  {
     cout << "Determinante somente de RectificationMatrix quadrada!\n";
     return 0;
  }
  if (lin==1)
    return m[0][0];
  j=lin;
  if (lin==2)
    j=1;
  for (i=0; i<j; i++)
  {
     nn=i;
     mm=0;
     prdp=1;
     prdn=-1;
     while (mm<lin)
     {
 prdp=prdp*m[mm][nn];
 prdn=prdn*m[mm][(col-1)-nn];
 nn++;
 mm++;
 if (nn>=col)
    nn=0;
     }
     det=det+prdp+prdn;
  }
  return det;
}

RectificationMatrix RectificationMatrix::produto(RectificationMatrix m1)
{
 int i,j,k;
 RectificationMatrix prod(lin,m1.col);

 if (col == m1.lin)
 {
  for (i=0;i<lin;i++)   //Percorre linhas da 1 RectificationMatrix
  {
   for (k=0;k<m1.col;k++)  //Percorre colunas da 2 RectificationMatrix
   {
    prod.m[i][k]=0;
    for (j=0;j<col;j++)
    {
     prod.m[i][k]=prod.m[i][k]+m[i][j]*m1.m[j][k];
    }
   }
  }
  return(prod);
 }
 else
 {
  cout << "Impossivel multiplicar";
 }
}

RectificationMatrix RectificationMatrix::produto_escalar(double pesc)
{
  int i,j;
  RectificationMatrix prod(lin,col);

  for (i=0;i<lin;i++)
  {
   for (j=0;j<col;j++)
     prod.m[i][j]=m[i][j]*pesc;
  }
  return(prod);
}

RectificationMatrix RectificationMatrix::transp(void)
{
 int i,j;
 RectificationMatrix transposta(col,lin);
 for (i=0;i<lin;i++)
 {
  for (j=0;j<col;j++)
  {
   transposta.m[j][i] = m[i][j];
  }
 }
 return transposta;

}

RectificationMatrix RectificationMatrix::copia(void)
{
 int i,j;
 RectificationMatrix clone(lin,col);
 for (i=0;i<lin;i++)
 {
  for (j=0;j<col;j++)
  {
   clone.m[i][j] = m[i][j];
  }
 }
 return clone;
}

RectificationMatrix RectificationMatrix::inversa(int size)
{
 int i,j,k,l; //this function inv.merts a square matrix (of course)
 long double det=1;   //M, having a (size X size) size.
 long double p,c,x;
 RectificationMatrix inv(size,size);   // RectificationMatrix nova int
 RectificationMatrix mat(lin,col); // RectificationMatrix nova mat
 mat = copia();  // C�pia da RectificationMatrix em uso em mat
 /*
    Cria RectificationMatrix identidade (I) em inv
    |1 0 0|
    |0 1 0|
    |0 0 1|
 */
 for (i=0;i<size;i++)
 {
  for (j=0;j<size;j++)
  {
   if (i==j) inv.m[i][j]=1;
   else inv.m[i][j]=0;
  }
 }
 i=0;
 while (i<size)//((i<size)&&(det!=0))
 {
  c=mat.m[i][i]; // Valor da diagonal i,i em c
  l=i;  // Guarda esta posi��o em l
  // Percorre a coluna do i, de i+1 ao final
  for (k=i+1;k<size;k++)
  {
   // Se o valor absoluto da diagonal for menor que o valor atual
   if (abs(c)<abs(m[k][i]))
   {
    c=mat.m[k][i]; // Guarda este valor em c
    l=k;  // e guarda esta posi��o em l
   }
  }
  // Caso o valor guardado seja diferente do original (l <> i)
  if (l!=i)
  {
   det = det*(-1);  // det = -det
   // Percorre toda a linha do i
   for (j=0;j<size;j++)
   {
    x=mat.m[i][j];   // $
    mat.m[i][j]=mat.m[l][j]; // $ Troca mat(i,j) <-> mat(l,j)
    mat.m[l][j]=x;   // $
    x=inv.m[i][j];   // &
    inv.m[i][j]=inv.m[l][j]; // & Troca inv(i,j) <-> inv(l,j)
    inv.m[l][j]=x;   // &
   }
  }
  p=mat.m[i][i]; // Guarda o valor da diagonal i,i em p
  det=det*p; // det = det*p
  // Se p for diferente de 0
  if (p!=0)
  {
   // Percorre a linha de i
   for(j=0;j<size;j++)
   {
    mat.m[i][j]=mat.m[i][j]/p; // Pega o valor da posi��o atual e divide por p
    inv.m[i][j]=inv.m[i][j]/p; // Pega o valor da posi��o atual e divide por p
   }
   // Percorre a coluna de i
   for(k=0;k<size;k++)
   {
    // Somente se k n�o pertencer a i
    if (k!=i)
    {
     p=mat.m[k][i]; // Guarda o valor da posi��o atual em p
     // Percorre a linha
     for(j=0;j<size;j++)
     {
      mat.m[k][j]=mat.m[k][j]-p*mat.m[i][j]; // mat(k,j) = mat(k,j)-p*mat(i,j)
      inv.m[k][j]=inv.m[k][j]-p*inv.m[i][j]; // inv(k,j) = inv(k,j)-p*inv(i,j)
     }
    }
   }
   // Pr�ximo ponto
   i++;
  }
 }
 //if (det==0) cout << "RectificationMatrix nao e inversivel!\n";
 return(inv);

}

void RectificationMatrix::namao()
{
 int i,j;
 cout << "Preenchendo a RectificationMatrix" << nome;
 for (i=0;i<lin;i++)
 {
  for (j=0;j<col;j++)
  {
   cout << "\nInforme o valor da posicao" << i << " x " << j << "\n";
   cin >> m[i][j];
  }
 }
}

long double RectificationMatrix::valor(int linha,int coluna)
{
 return m[linha][coluna];
}

int RectificationMatrix::maxlin()
{
 return lin;
}
int RectificationMatrix::maxcol()
{
 return col;
}

/*
void RectificationMatrix::showGui(QTable *tab)
{
 int i,j;
 tab->setNumRows(lin);
 tab->setNumCols(col);
 QString *str = new QString();

 for (i=0;i<lin;i++)
 {
  for (j=0;j<col;j++)
  {
   tab->setText(i,j,str->number(double(m[i][j])));
  }
 }
}
*/
