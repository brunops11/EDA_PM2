#ifndef CONTROLEST_H_INCLUDED
#define CONTROLEST_H_INCLUDED

typedef struct{
    float costoAcumulado;
    float costoMax;
    int cant;
}bloque;

bloque costoABB[4];
bloque costoLI[4];
bloque costoLSOBB[4];

void initC(bloque *);
void initM(float *);

vhlo dat;
vhlo exitoE;
vhlo exitoEv;
int exito = 0,opc = 0;
char patAux[8];
float mABB[4],mLI[4],mLSOBB[4],costo;

int Lectura_operaciones(){
    FILE *fp;
    int codOp,exitoL;
    if((fp=fopen("Operaciones.txt","r"))==NULL)
        return 0;
    else{
        //cantabb = 0;
        //cantli= 0;
        cantlsobb = 0;
        while(!(feof(fp))){
            vhlo aux;
            fscanf(fp,"%d",&codOp);
            fgetc(fp);
            if(codOp==1||codOp==2){
                fgets(aux.patente,8,fp);
                fgetc(fp);
                fgets(aux.marcamod,60,fp);
                fscanf(fp,"%d",&aux.anio);
                fgetc(fp);
                fgets(aux.nom,50,fp);
                fgets(aux.tel,15,fp);
                fgets(aux.serv,70,fp);
                fscanf(fp,"%f",&aux.importe);
                fgetc(fp);
                fgets(aux.fecha,11,fp);
                fgetc(fp);
                if(codOp==1){
                    /*if(cantabb<250){
                        costo = 0;
                        Alta1(aux,&exitoL,&costo);
                        if(exitoL){
                            costoABB[0].costoAcumulado = costoABB[0].costoAcumulado + costo;
                            costoABB[0].cant++;
                            if(costo>costoABB[0].costoMax)
                                costoABB[0].costoMax = costo;
                        }
                    }
                    if(cantli<250){
                    costo = 0;
                    Alta2(aux,&exitoL,&costo);
                        if(exitoL){
                            costoLI[0].costoAcumulado = costoLI[0].costoAcumulado + costo;
                            costoLI[0].cant++;
                            if(costo>costoLI[0].costoMax)
                                costoLI[0].costoMax = costo;
                        }
                    }*/
                    if(cantlsobb<250){
                        costo = 0;
                        Alta3(aux,&exitoL,&costo);
                        if(exitoL){
                            costoLSOBB[0].costoAcumulado = costoLSOBB[0].costoAcumulado + costo;
                            costoLSOBB[0].cant++;
                            if(costo>costoLSOBB[0].costoMax)
                                costoLSOBB[0].costoMax = costo;
                        }
                    }
                }else{
                    /*if(cantabb>0){
                        costo = 0;
                        Baja1(aux.patente,aux,&exitoL,2,&costo);
                        if(exitoL){
                        costoABB[1].costoAcumulado = costoABB[1].costoAcumulado + costo;
                        costoABB[1].cant++;
                        if(costo > costoABB[1].costoMax)
                            costoABB[1].costoMax = costo;
                        }
                    }
                    if(cantli>0){
                        costo = 0;
                        Baja2(aux.patente,aux,&exitoL,2,&costo);
                        if(exitoL){
                            costoLI[1].costoAcumulado = costoLI[1].costoAcumulado + costo;
                            costoLI[1].cant++;
                            if(costo > costoLI[1].costoMax)
                                costoLI[1].costoMax = costo;
                        }
                    }*/
                    if(cantlsobb>0){
                        costo = 0;
                        Baja3(aux.patente,aux,&exitoL,2,&costo);
                        if(exitoL){
                        costoLSOBB[1].costoAcumulado = costoLSOBB[1].costoAcumulado + costo;
                        costoLSOBB[1].cant++;
                        if(costo > costoLSOBB[1].costoMax)
                            costoLSOBB[1].costoMax = costo;
                        }
                    }
                }
            }else{
                if(codOp==3){
                    fgets(aux.patente,8,fp);
                    fgetc(fp);
                    vhlo aux1;
                    /*costo = 0;
                    if(cantabb==0)
                        exitoL = 0;
                    else
                        Evocar1(aux.patente,&aux1,&exitoL,&costo);
                    if(exitoL){
                        costoABB[2].costoAcumulado = costoABB[2].costoAcumulado + costo;
                        costoABB[2].cant++;
                        if(costo > costoABB[2].costoMax)
                            costoABB[2].costoMax = costo;
                    }else{
                        costoABB[3].costoAcumulado = costoABB[3].costoAcumulado + costo;
                        costoABB[3].cant++;
                        if(costo > costoABB[3].costoMax)
                            costoABB[3].costoMax = costo;
                    }
                    costo = 0;
                    if(cantli==0)
                        exitoL = 0;
                    else
                        Evocar2(aux.patente,&aux1,&exitoL,&costo);
                    if(exitoL){
                        costoLI[2].costoAcumulado = costoLI[2].costoAcumulado + costo;
                        costoLI[2].cant++;
                        if(costo > costoLI[2].costoMax)
                            costoLI[2].costoMax = costo;
                    }else{
                        costoLI[3].costoAcumulado = costoLI[3].costoAcumulado + costo;
                        costoLI[3].cant++;
                        if(costo > costoLI[3].costoMax)
                            costoLI[3].costoMax = costo;
                    }*/
                    costo = 0;
                    if(cantlsobb==0)
                        exitoL = 0;
                    else
                        Evocar3(aux.patente,&aux1,&exitoL,&costo);
                    if(exitoL){
                        costoLSOBB[2].costoAcumulado = costoLSOBB[2].costoAcumulado + costo;
                        costoLSOBB[2].cant++;
                        if(costo > costoLSOBB[2].costoMax)
                            costoLSOBB[2].costoMax = costo;
                    }else{
                        costoLSOBB[3].costoAcumulado = costoLSOBB[3].costoAcumulado + costo;
                        costoLSOBB[3].cant++;
                        if(costo > costoLSOBB[3].costoMax)
                            costoLSOBB[3].costoMax = costo;
                    }
                }else
                    printf("Error: Codigo de operador desconocido.\n");
            }
        }
        fclose(fp);
        //ABB
        /*if(costoABB[0].cant != 0)
            mABB[0] = costoABB[0].costoAcumulado * (1.0/costoABB[0].cant);
        if(costoABB[1].cant != 0)
            mABB[1] = costoABB[1].costoAcumulado * (1.0/costoABB[1].cant);
        if(costoABB[2].cant != 0)
            mABB[2] = costoABB[2].costoAcumulado * (1.0/costoABB[2].cant);
        if(costoABB[3].cant != 0)
            mABB[3] = costoABB[3].costoAcumulado * (1.0/costoABB[3].cant);
        //LI
        if(costoLI[0].cant != 0)
            mLI[0] = costoLI[0].costoAcumulado * (1.0/costoLI[0].cant);
        if(costoLI[1].cant != 0)
            mLI[1] = costoLI[1].costoAcumulado * (1.0/costoLI[1].cant);
        if(costoLI[2].cant != 0)
            mLI[2] = costoLI[2].costoAcumulado * (1.0/costoLI[2].cant);
        if(costoLI[3].cant != 0)
            mLI[3] = costoLI[3].costoAcumulado * (1.0/costoLI[3].cant);*/
        //LSOBB
        if(costoLSOBB[0].cant != 0)
            mLSOBB[0] = costoLSOBB[0].costoAcumulado * (1.0/costoLSOBB[0].cant);
        if(costoLSOBB[1].cant != 0)
            mLSOBB[1] = costoLSOBB[1].costoAcumulado * (1.0/costoLSOBB[1].cant);
        if(costoLSOBB[2].cant != 0)
            mLSOBB[2] = costoLSOBB[2].costoAcumulado * (1.0/costoLSOBB[2].cant);
        if(costoLSOBB[3].cant != 0)
            mLSOBB[3] = costoLSOBB[3].costoAcumulado * (1.0/costoLSOBB[3].cant);

        return 1;
    }

}

void Comparacion(){
    printf("\t COMPARACION DE ESTRUCTURAS\n\n");
    printf("CANTIDAD\tABB\tLI\tLSOBB\n");
    printf("\t\t%d\t%d\t%d\t\n\n",2/*cantabb*/,3/*cantli*/,cantlsobb);
    printf("COSTOS\t\tABB\t\tLI\t\tLSOBB\n");
    printf("____________________________________________________________________\n");
    printf("MAX.ALTA\t%.2f\t\t%.2f\t\t%.2f\t\t\n",costoABB[0].costoMax,costoLI[0].costoMax,costoLSOBB[0].costoMax);
    printf("MED.ALTA\t%.2f\t\t%.2f\t\t%.2f\t\t\n",mABB[0],mLI[0],mLSOBB[0]);
    printf("____________________________________________________________________\n");
    printf("MAX.BAJA\t%.2f\t\t%.2f\t\t%.2f\t\t\n",costoABB[1].costoMax,costoLI[1].costoMax,costoLSOBB[1].costoMax);
    printf("MED.BAJA\t%.2f\t\t%.2f\t\t%.2f\t\t\n",mABB[1],mLI[1],mLSOBB[1]);
    printf("____________________________________________________________________\n");
    printf("MAX.EVOEX\t%.2f\t\t%.2f\t\t%.2f\t\t\n",costoABB[2].costoMax,costoLI[2].costoMax,costoLSOBB[2].costoMax);
    printf("MED.EVOEX\t%.2f\t\t%.2f\t\t%.2f\t\t\n",mABB[2],mLI[2],mLSOBB[2]);
    printf("____________________________________________________________________\n");
    printf("MAX.EVONOEX\t%.2f\t\t%.2f\t\t%.2f\t\t\n", costoABB[3].costoMax,costoLI[3].costoMax,costoLSOBB[3].costoMax);
    printf("MED.EVONOEX\t%.2f\t\t%.2f\t\t%.2f\t\t\n\n", mABB[3],mLI[3],mLSOBB[3]);
    system("PAUSE");
    system("cls");
}

#endif // CONTROLEST_H_INCLUDED
