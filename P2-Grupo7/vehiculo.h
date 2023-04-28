#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED
#include <string.h>

typedef struct {
    char patente[8];
    char marcamod[60];
    int anio;
    char nom[50];
    char tel[15];
    char serv[70];
    float importe;
    char fecha[11];
}vhlo;

void estvhlo(char *p,char *mm,int a,char *n,char *t,char *s,float i,char *f,vhlo *v){
    strcpy((*v).patente,p);
    (*v).anio = a;
    strcpy((*v).marcamod,mm);
    strcpy((*v).nom,n);
    strcpy((*v).tel,t);
    strcpy((*v).serv,s);
    (*v).importe = i;
    strcpy((*v).fecha,f);
}

#endif // VEHICULO_H_INCLUDED
