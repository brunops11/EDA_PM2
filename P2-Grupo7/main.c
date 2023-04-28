#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vehiculo.h"
#include "lsobbt.h"
#include "controlEst.h"

void limpiar(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void CargarVehiculo(vhlo*);
void MostrarLSOBB();

int main()
{
    int opctipo,opcestructura,opc,exito,res;
    vhlo nuevo;
    char pCE[7];
    do{
        printf("Elija una opcion:\n<1>Administracion de estructuras.\n<2>Comparacion de estructuras.\n<3>Salir\n");
        scanf("%d",&opctipo);
        switch(opctipo){
            case 1: do{
                    printf("Elija una estructura:\n<1>Arbol binario de busqueda.\n<2>Lista invertida (Busqueda binaria).\n<3>Lista secuencial ordenada (Busqueda binaria).\n<4>Salir\n");
                    scanf("%d",&opcestructura);
                    switch(opcestructura){
                        case 1: //abb
                        break;
                        case 2: //libbb
                        break;
                        case 3: do{
                                    printf("Elija la opcion a realizar:\n<1>Ingresar vehiculo.\n<2>Eliminar vehiculo.\n<3>Servicio realizado a un vehiculo.\n<4>Consultar informacion completa.\n<5>Mostrar estructura.\n<6>Salir.\n");
                                    scanf("%d",&opc);
                                    switch(opc){
                                        case 1: if(cantlsobb==250)
                                                    printf("Lista llena.\n");
                                                else{
                                                    CargarVehiculo(&nuevo);
                                                    Alta3(nuevo,&exito,&costo);
                                                    if(exito)
                                                        printf("\nVehiculo ingresado.\n");
                                                    else
                                                        printf("El vehiculo ya se encuentra en la lista.\n");
                                                    }
                                                system("pause");
                                                limpiar();
                                        break;
                                        case 2: if(cantlsobb==0)
                                                    printf("Lista vacia.\n");
                                                else{
                                                    printf("Ingrese patente del vehiculo a eliminar.\n");
                                                    fflush(stdin);
                                                    scanf("%7[^\n]",pCE);
                                                    Baja3(pCE,nuevo,&exito,opctipo,&costo);
                                                    if(exito==1)
                                                        printf("Vehiculo eliminado.\n");
                                                    else{
                                                        if(exito==2)
                                                            printf("Elimincacion del vehiculo cancelada.\n");
                                                        else
                                                            printf("No fue posible eliminar el vehiculo.\n");
                                                    }
                                                }
                                                system("pause");
                                                limpiar();
                                        break;
                                        case 3: if(cantlsobb==0)
                                                    printf("Lista vacia.\n");
                                                else{
                                                    printf("Ingrese patente del vehiculo a consultar por servicio.\n");
                                                    fflush(stdin);
                                                    scanf("%7[^\n]",pCE);
                                                    Evocar3(pCE,&nuevo,&exito,&costo);
                                                    if(exito){
                                                        if(strlen(nuevo.serv)==0)
                                                            printf("NO se le ha realizado servicio mecanico al vehiculo con patente %s.\n",pCE);
                                                        else
                                                            printf("SI se le ha realizado servicio mecanico al vehiculo con patente %s.\n",pCE);
                                                    }else
                                                        printf("No fue posible consultar por el vehiculo.\n");
                                                }
                                                system("pause");
                                                limpiar();
                                        break;
                                        case 4: if(cantlsobb==0)
                                                    printf("Lista vacia.\n");
                                                else{
                                                    printf("Ingrese patente del vehiculo a consultar.\n");
                                                    fflush(stdin);
                                                    scanf("%7[^\n]",pCE);
                                                    Evocar3(pCE,&nuevo,&exito,&costo);
                                                    if(exito){
                                                        printf("\nResultado de la consulta:\n\n");
                                                        printf("Patente: %s\n\n",nuevo.patente);
                                                        printf("Marca y modelo: %s\n\n",nuevo.marcamod);
                                                        printf("A%co de fabricacion: %d\n\n",164,nuevo.anio);
                                                        printf("Nombre del due%co: %s\n\n",164,nuevo.nom);
                                                        printf("Telefono: %s\n\n",nuevo.tel);
                                                        printf("Servicio efectuado: %s\n\n",nuevo.serv);
                                                        printf("Importe: %.2f\n\n",nuevo.importe);
                                                        printf("Fecha: %s\n\n",nuevo.fecha);
                                                    }else
                                                        printf("No fue posible consultar por el vehiculo.\n");
                                                }
                                                system("pause");
                                                limpiar();
                                        break;
                                        case 5: if(cantlsobb==0){
                                                    printf("Lista vacia. Ingrese vehiculos.\n");
                                                    system("pause");
                                                }else
                                                    MostrarLSOBB();
                                                limpiar();
                                        break;
                                        case 6: printf("Saliendo de la estructura...\n");
                                                system("pause");
                                                limpiar();
                                    }
                                }while(opc!=6);
                        break;
                        case 4: printf("\nSaliendo del programa...\n");
                        break;
                    }
                    }while(opcestructura!=4);
            break;
            case 2: printf("Cargando datos...\n");
                    res = Lectura_operaciones();
                    if(res){
                        printf("Lectura exitosa.\n");
                        Comparacion();
                    }else
                        printf("Error: Carga de datos no exitosa.\n");
        }
    }while(opctipo!=3);
    return 0;
}

void CargarVehiculo(vhlo *v){
    int nanio;
    float nImporte;
    char nPatente[8],nMM[60],nNombre[50],nTel[15],nServ[70],nFecha[11];
    printf("\nIngrese los siguentes datos del nuevo vehiculo:\n");
    printf("\nPatente: ");
    fflush(stdin);
    scanf("%8[^\n]",nPatente);
    printf("\nMarca y modelo: ");
    fflush(stdin);
    scanf("%60[^\n]",nMM);
    printf("\nA%co de fabricacion: ",164);
    fflush(stdin);
    scanf("%d",&nanio);
    printf("\nNombre del due%co: ",164);
    fflush(stdin);
    scanf("%50[^\n]",nNombre);
    printf("\nTelefono: ");
    fflush(stdin);
    scanf("%15[^\n]",nTel);
    printf("\nServicio realizado: ");
    fflush(stdin);
    scanf("%70[^\n]",nServ);
    printf("\nImporte: ");
    fflush(stdin);
    scanf("%f",&nImporte);
    printf("\nFecha: ");
    fflush(stdin);
    scanf("%11[^\n]",nFecha);
    estvhlo(nPatente,nMM,nanio,nNombre,nTel,nServ,nImporte,nFecha,v);
}

void MostrarLSOBB(){
    int i;
    vhlo aux;
    printf("Mostrando...\n");
    for(i=0;i<cantlsobb;i++){
        aux = lsobb[i];
        printf("\n----------[%d]----------\n",i+1);
        printf("Patente: %s\n\n",aux.patente);
        printf("Marca y modelo: %s\n\n",aux.marcamod);
        printf("A%co de fabricacion: %d\n\n",165,aux.anio);
        printf("Nombre del due%co: %s\n\n",165,aux.nom);
        printf("Telefono: %s\n\n",aux.tel);
        printf("Servicio efectuado: %s\n\n",aux.serv);
        printf("Importe: %.2f\n\n",aux.importe);
        printf("Fecha: %s\n\n",aux.fecha);
    }
    system("pause");
}
