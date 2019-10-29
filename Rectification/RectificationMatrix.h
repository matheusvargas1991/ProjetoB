#ifndef RECTIFICATIONMATRIX_H
#define RECTIFICATIONMATRIX_H

#include <iostream>
#include <stdlib.h>
#include <math.h>
//#include <qtable.h>

class RectificationMatrix
{
 private:
  long double** m;  //RectificationMatrix
  int lin,col;  //dimensoes da RectificationMatrix
 public:
  int maxlin(void);
  int maxcol(void);
  char* nome; //nome da RectificationMatrix
  RectificationMatrix(int linha,int coluna); //construtor
  void show(void); //Exibe a RectificationMatrix
  void report(void); //Exibe a RectificationMatrix no report
  void atribui(int linha,int coluna,long double val); //Atribui um valor val a uma posicao linha x coluna da RectificationMatrix
  long double valor(int linha,int coluna); //retorna um valor da posicao linha x coluna da RectificationMatrix
  void fillrand(int lim); //(para testes) Preenche a RectificationMatrix com valores randomicos dentro de um intervalo de 0 at?lim
  void identidade(void); //transforma a RectificationMatrix em identidade
  RectificationMatrix soma(RectificationMatrix m1); // Soma entre 2 RectificationMatrixes de mesmo tamanho
  RectificationMatrix subtrai(RectificationMatrix m1); // Subtração entre 2 RectificationMatrixes de mesmo tamanho
  float det(); // Determinante de uma RectificationMatrix
  RectificationMatrix produto(RectificationMatrix m1); //Retorna o produto da RectificationMatrix dona do metodo e a RectificationMatrix m1
  RectificationMatrix produto_escalar(double pesc);
  RectificationMatrix transp(void); //Retorna a transposta da RectificationMatrix
  RectificationMatrix inversa(int size); //Retorna a inversa da RectificationMatrix
  RectificationMatrix copia(void); //Retorna uma copia da RectificationMatrix
  void namao(void); //(para testes) Preenche valores um a um na RectificationMatrix
  //void showGui(QTable* tabela); //Exibe a RectificationMatrix num objeto QTable do QT
  //~RectificationMatrix(void);
};

#endif // RECTIFICATIONMATRIX_H
