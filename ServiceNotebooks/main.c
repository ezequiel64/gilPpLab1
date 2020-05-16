#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Egil.h"
#include "datawarehouse.h"


typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int id;
    char descripcion[20];

}eMarca;

typedef struct
{
    int id;// comienza en 5000
    char descripcion[20];

}eTipo;

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTiopo;
    float precio;
    int isEmpty;

}eNotebook;

typedef struct
{
    int id;
    char descripcion[25];
    float precio;

}eServicio;

typedef struct
{
    int id;//auto incrementar
    int idNotebook[25];
    int idServicio;
    eFecha fecha;

}eTrabajo;



int menuNotebook (void);
int menuModificacion (void);
void menuMarca(eMarca listMarca[],int tamMarca);
void menuTipo(eTipo list[],int tamTipo);
void inicializarNotebook(eNotebook list[] ,int tam);
int buscarLibre(eNotebook list[],int tam);
void mostrarNotebook(eNotebook list,eMarca marca[],int tamMarca,eTipo tipo,int tamTipo,int indice);
int buscarNotebook(eNotebook list[],int tam,int idx);
void modificarNotebook(eNotebook list[],int tamNote,eTipo tipo[],int tamTipo);
int altaNotebook(eNotebook list[],int tam,eTipo tipo[],int tamTipo,eMarca marca[],int tamMarca,int id,int indice);
int bajaNotebook(eNotebook list[],int tamNote,eTipo tipo[],int tamTipo,eMarca marca[],int tamMar);
void modificarNotebook(eNotebook list[],int indice,eTipo tipo[],int tamTipo);
int isEmpty(eNotebook list[],int tam);
//void hardcodeTipo(eNotebook list[],int tam);




#define TAMNOTE 2
#define TAMTIPO 4
#define TAMM 4
#define TAMSERV 4
#define HARDCTIPO 4
#define HARDMARCA 4
#define HARDSERV 4

int main()
{

eNotebook notebooks[TAMNOTE]={{100,"Rojo",1,2,25000,0},{}};
eTipo tipos[TAMTIPO] = {{5000 , "Gamer"} , {5001 ,"Disenio"},{ 5002, "Ultrabook"},{ 5003,"Normalita"}};
eMarca marcas[TAMM] = {{1000,"Compaq"},{1002,"Asus"},{1003,"Acer"},{1004,"HP"}};
//eServicio servicios [TAMSERV] = {{20000,"Bateria", 250}, {20001,"Antivirus", 300}, {20002,"Actualizacion", 400},{20003,"Fuente", 600}};

char salir='n';
int proxId=101,indice;

inicializarNotebook(notebooks,TAMNOTE);

printf("******Gestion Notebook******\n");
do
{




switch(menuNotebook())
{
	case 'a':
            printf("****Alta Notebook****\n");

            if (-1<(indice=buscarLibre(notebooks,TAMNOTE)))
            {
                if(altaNotebook(notebooks,TAMNOTE,tipos,TAMTIPO,marcas,TAMM,proxId,indice))
                {
                    system("cls");
                    proxId++;
                    printf("Se a dado de alta correctamente\n\n");
                }else
                    {
                    system("cls");
                    printf("Ocurrio un error al intentar dar de alta la NOTEBOOK.\nIntentelo nuevamente\n\n");
                    }
            }else
                {
                printf("No hay espacio disponible para ingresar un nuevo empleado.\n\n");
                }
		break;
	case 'b':
	    printf("*****Modificacion de Notebook****\n");
	    if(isEmpty(notebooks,TAMNOTE))
        {
        modificarNotebook(notebooks,TAMNOTE,tipos,TAMTIPO);

        }else
            printf("Debe generar por lo menos un alta.\n\n");
		break;
	case 'c':
	    printf("*****Baja de Notebook*****\n");
	    if(isEmpty(notebooks,TAMNOTE))
        {
        if (bajaNotebook(notebooks,TAMNOTE,tipos,TAMTIPO,marcas,TAMM))
        printf("Baja Exitosa.\n");
        else
        printf("no se realizo la baja.");
        }else
            printf("Debe generar por lo menos un alta.\n\n");
		break;

	case 'd':

		break;

	case 'e':

		break;

	case 'f':

		break;

	case 'g':

		break;

	case 'h':

		break;

	case 'i':

		break;

	case 'j':

		break;
	default:
	printf("La opcion ingresada no existe\n");
		break;

}
system("pause");
system("cls");
}while(salir!='s');
}


//menus

int menuModificacion (void)
{
    int op;
    printf("1)Precio\n");
    printf("2)Tipo\n");
    printf("3)salir\n");
    fflush(stdin);
    scanf("%d",&op);
    return	op;

}

int menuNotebook (void)
{
    char op;
    printf("a)ALTA NOTEBOOK\n");
    printf("b)MODIFICAR NOTEBOOK\n");
    printf("c)BAJA NOTEBOOK\n");
    printf("d)LISTAR NOTEBOOKS\n");
    printf("e)LISTAR  MARCAS \n");
    printf("f)LISTAR TIPOS\n");
    printf("g)LISTAR SERVICIOS\n");
    printf("h)ALTA TRABAJO\n");
    printf("i)LISTAR TRABAJOS\n");
    printf("j)salir\n\n");
    fflush(stdin);
    scanf("%c",&op);
    op=tolower(op);
    return	op;

}

//devuelve el indice
int buscarLibre(eNotebook list[],int tam)
{
    int rta=0;
    for (int i = 0; i < tam; ++i)
    {
        if (list[i].isEmpty)
        {
            rta = i;
            break;
        }

    }
    return rta;
}

void inicializarNotebook(eNotebook list[] ,int tam)
{
    for (int i = 0; i < tam; ++i)
    {
        list[i].isEmpty = 1;
    }
}

int altaNotebook(eNotebook list[],int tam,eTipo tipo[],int tamTipo,eMarca marca[],int tamMarca,int id,int indice)
{
   int rta = 0;
    eNotebook auxNote;
    auxNote.isEmpty=0;
    auxNote.id=id;
    system("cls");
    printf("****Alta de Notebook****\n\n");

    if(getString(auxNote.modelo,20,"Ingrese Modelo (color)","Error. Ingrese Modelo  (color)",2))
    {
        menuMarca(marca,tamMarca);
        if(getInt(&auxNote.idMarca,2,1000,1003,"Ingrese id de marca.\nRango valido de 1000 a 1003: ","Error. Ingrese id de marca.\nRango valido de 1000 a 10003: "))
        {
            menuTipo(tipo,tamTipo);
            if(getInt(&auxNote.idTiopo,2,5000,5003,"Ingrese id de tipo.\nRango valido de 1000 a 10003: ","Error. Ingrese id de tipo.\nRango valido de 1000 a 10003: "))
            {
                if(getFloat(&auxNote.precio,2,25000,150000,"Ingrse el precio.\nValores validos desde $25.000 a $150.000: ","Error.\nValores validos desde $25.000 a $150.000: "))
                {
                rta = 1;
                list[indice]=auxNote;
                }
            }
        }
    }
    return rta;

}



//Marca
int cargarDescripcionMarca(char descripcion[],int idMarca,eMarca marca[],int tamMarca)
{
int rta=0;
for (int i = 0; i < tamMarca; ++i)
{
    if (marca[i].id==idMarca)
    {
        strcpy(descripcion,marca[i].descripcion);
        rta=1;
        break;
    }
}
return rta;
}

int cargarDescripcionTipo(char descripcion[],int idTipo,eTipo tipo[],int tamTipo)
{
int rta=0;
for (int i = 0; i < tamTipo; ++i)
{
    if (tipo[i].id==idTipo)
    {
        strcpy(descripcion,tipo[i].descripcion);
        rta=1;
        break;
    }
}
return rta;
}

void menuMarca(eMarca listMarca[],int tamMarca)
{

    for (int i = 0; i < tamMarca; ++i)
    {
        if (i==0)
        {
        printf("Id Marca     Descripcion\n");
        }
        printf("    %d         %10s\n",listMarca[i].id,listMarca[i].descripcion );
    }

}


void menuTipo(eTipo list[],int tamTipo)
{
      for (int i = 0; i < tamTipo; ++i)
    {
        if (i==0)
        {
        printf("Id Sector     Descripcion\n");
        }
        printf("    %d         %10s\n",list[i].id,list[i].descripcion);
    }
}

int isEmpty(eNotebook list[],int tam)
{

    int rta=0;
    for (int i = 0; i < tam; ++i)
    {
        if (!list[i].isEmpty)
        {
            rta = 1;
        }
    }
    return rta;
}

void modificarNotebook(eNotebook list[],int tamNote,eTipo tipo[],int tamTipo)
{
char salir='n';
int indice,id;
eNotebook auxNote;
system("cls");
printf("****Modificacion de Notebook****\n\n");

do
{
     if(getInt(&id,1,100,150,"Ingrese el id de la notebook que desea modificar: ","Error. Ingrese el id de la notebook que desea modificar: "))
            {
            if (-1<(indice=buscarNotebook(list,tamNote,id)))
            {
    switch(menuModificacion())
	{


        printf("\n--------------------------------------------\n");
		case 1:
		if(getFloat(&auxNote.precio,2,25000,150000,"Ingrse el precio.\nValores validos desde $25.000 a $150.000: ","Error.\nValores validos desde $25.000 a $150.000: "))
			{printf("\nSe han cargado cambios\n");
            list[indice].precio=auxNote.precio;
			}
			else
				printf("Ocurrio un error en la carga. Vuelva a intentaro.\n");
        break;
		case 2:
            menuTipo(tipo,tamTipo);
            if(getInt(&auxNote.idTiopo,2,5000,5003,"Ingrese id de tipo.\nRango valido de 1000 a 10003: ","Error. Ingrese id de tipo.\nRango valido de 1000 a 10003: "))
                {printf("\nSe han cargado cambios\n");
            	list[indice].idTiopo=auxNote.idTiopo;
        		}
                else
                printf("Ocurrio un error en la carga. Vuelva a intentaro.\n");
            break;

		case 3:
		    system("cls");
            printf("****Salir****\n");
            getChar(&salir,3,1,'s','n',"Confirma salir? (S/N): ","Caracteres invalidos 's' para salir, 'n' para quedarse en el programa\nConfirma salir? (S/N): ");
			break;

		default:
		printf("La opcion ingresada no existe.\n");
			break;

    }
        }
            }else
            printf("El id de la notebook ingresado no EXISTE o NO SE ENCUENTA ACTIVO en la base de datos.\n\n");
}while(salir!='s');

}

int buscarNotebook(eNotebook list[],int tam,int idx)
{
    int rta=0;
    for (int i = 0; i < tam; ++i)
    {
        if (list[i].id==idx && list[i].isEmpty==0)
        {
            rta = i;
            break;
        }

    }
    return rta;
}


int bajaNotebook(eNotebook list[],int tamNote,eTipo tipo[],int tamTipo,eMarca marca[],int tamMar)
{
    int rta=0,id,indice;

    printf("****Baja notebook****\n");

     if(getInt(&id,1,100,150,"Ingrese el id de la notebook que desea dar de baja: ","Error. Ingrese el id de la notebook que desea dar de baja: "))
            {
            if (-1<(indice=buscarNotebook(list,tamNote,id)))
            {
            list[indice].isEmpty=1;
            rta =1;
            }
            }else
            	printf("El id de la notebook ingresado no EXISTE o NO SE ENCUENTA ACTIVO en la base de datos.\n\n");
      return rta;

}

//void mostrarNotebook(eNotebook list,eMarca marca[],int tamMarca,eTipo tipo,int tamTipo,int indice)
//{
//    char descripcionMarca[20],descripcionTipo[20];
//    cargarDescripcionTipo(descripcionTipo,list[indice].idTiopo,tipo,tamTipo);
//
//    cargarDescripcionMarca(descripcionMarca,list[indice].idMarca,marca,tamMarca);
//    printf("%4d     %9s      %9s       %c       %2d     %.2f       %02d/%02d/%4d      %10s\n",list.id,list.nombre,list.apellido,list.sexo,list.edad,list.sueldo,list.fechaIngreso.dia,list.fechaIngreso.mes,list.fechaIngreso.anio,descripcionSec);
//}
//
//void mostrarNotebooks(eNotebook list,eMarca marca[],int tamMarca,eTipo tipo,int tamTipo,int indice)
//{
//
//}

