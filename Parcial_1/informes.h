#include "instrumento.h"
#include "musico.h"
#include "orquesta.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int Informes_listarMusicos(Musico arrayA[], Instrumento arrayB[], int sizeI, int sizeJ);

int Informes_a(Orquesta array[], int size);
int Informes_b(Musico arrayA[], Orquesta arrayB[], Instrumento arrayC[], int sizeI, int sizeJ, int sizek);
int Informes_c(Orquesta arrayA[], Musico arrayB[], int sizeI, int sizeJ);
int Informes_d(Orquesta arrayA[], Musico arrayB[], Instrumento arrayC[], int sizeI, int sizeJ, int sizek);
int Informes_e(Orquesta arrayA[], Musico arrayB[], Instrumento arrayC[], int sizeI, int sizeJ, int sizek);
int Informes_f(Orquesta arrayA[], Musico arrayB[], int sizeI, int sizeJ);
int Informes_g(Orquesta arrayA[], Instrumento arrayB[], int sizeI, int sizeJ);
int Informes_h(Musico arrayA[], Instrumento arrayB[], int sizeI, int sizeJ);


#endif // INFORMES_H_INCLUDED
