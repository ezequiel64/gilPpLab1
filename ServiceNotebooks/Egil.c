#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Egil.h"

int getInt(int* valor,int intentos,int limx,int limy,char mensaje[],char error[])
{
    int i=0,tam,vf=1,rta=0,auxInt;//vf=verdadero o falso
    char num[50];

    while(i<intentos)
    {
        if (i==0)
        {
            printf("%s",mensaje);
            fflush(stdin);
            gets(num);
        }
        else
        {
            printf("%s",error);
            fflush(stdin);
            gets(num);
        }
        tam=strlen(num);
        for (int j = 0; j < tam && vf == 1; )
        {
            if(num[0]=='-' && j==0)
            {
                j++;
            }
            else if(isdigit(num[j]))
                j++;
            else
            {
                vf=0;
                break;
            }
        }
        auxInt=atoi(num);
        if (auxInt>=limx && auxInt<=limy && vf==1)
        {
            rta=1;
            *valor=auxInt;
            break;
        }
        else
        {
            vf=1;
            i++;
        }

    }
    return rta;
}

int getFloat (float* valor,int intentos,int limx,int limy,char mensaje[],char error[])
{
    int tam,vf=1,cont=0,j=0,rta=0;//vf=verdadero o falso
    float auxFloat;
    char num[50];

    while(j<intentos)
    {
        if(j==0)
        {
            printf("%s", mensaje);
            fflush(stdin);
            gets(num);
        }
        else
        {
            printf("%s", error);
            fflush(stdin);
            gets(num);
        }
        tam=strlen(num);
        for(int i=0; i<tam && vf==1; )//valida que el numero ingresado que cumpla con las caracteristicas de un flotante.
        {
            if(num[0]=='-' && i==0)//corrobora si el numero es negativo
            {
                i++;
            }
            else if(isdigit(num[i]))//corrobora si es un digito
            {
                i++;
            }
            else if(num[i]!='.')//si no es un digito corrobora que sea distinto de un punto, si es otro tipo de caracer ingresa e iguala el contador a 2, de lo contrario seria un punto y solo incremento el contador a 1.
            {
                cont=2;
            }
            else
            {
                cont++;
                i++;
            }
            if(cont>1)//si el contador es mayor a uno quiere decir de que se ingresaron caracteres los cuales no cumplen el requisito para ser un flotante.
            {
                vf=0;
                break;
            }
        }
        auxFloat=atof(num);
        if (auxFloat>=limx && auxFloat<=limy&&vf==1)//controla de que lo ingresado sea un numero flotante por medio de la variable vf, y que este dentro de los rangos indicados.
        {
            rta=1;
            *valor=auxFloat;
            break;
        }
        else
            {
            vf=1;cont=0;//reinicializo todos los flags
            j++;
            }

    }
    return rta;
}


//int validarRango(int* valor,int limX,int limY,int intentos,char mensaje[],char error[])
//{
//int isInt,i=0,num,vf=1;
//
//
//    printf("%s",mensaje);
//    if((isInt=getInt(&num)))
//    {
//        while((limX>num || limY<num || isInt==0)&&i<=intentos)
//        {
//        i++;
//        printf("%s",error);
//            if(intentos)
//            {
//                if(!(isInt=getInt(&num)))
//                {
//                printf("No ha ingresado un numero. \n");
//                vf=0;
//                break;
//                }
//            }else
//                {
//                printf("No ha ingresado un numero. \n");
//                vf=0;
//                }
//        }
//    }else
//        {
//        printf("No ha ingresado un numero. \n");
//        vf=0;
//        }
//    if(isInt==1&&vf==1)
//    {
//        *valor=num;
//    }
//    return vf;
//}

void formatearNombre(char cad1[],char cad2[],char cad3[])
{
strcpy(cad3,cad2);
strcat(cad3,", ");
strcat(cad3,cad1);
strlwr(cad3);
cad3[0]=toupper(cad3[0]);
for (int i = 1;cad3[i]!='\0' ; ++i)
{
    if (cad3[i]==' ')
    cad3[i+1]=toupper(cad3[i+1]);
}
}

int getString(char *cadena,int tam,char mensaje[],char error[],int intentos)
{
    int rta=0,i=0;
    char auxCad[tam*2+1];
    fflush(stdin);
    printf("%s",mensaje);
    gets(auxCad);
    while(tam<strlen(auxCad) && i<intentos)
    {
    i++;
    printf("Le queda %d intento/s\n",intentos);
    printf("%s",error);
    fflush(stdin);
    gets(auxCad);
    }
    if (i<=intentos && tam>=strlen(auxCad))
    {
    strcpy(cadena,auxCad);
    rta = 1;

    }
    return rta;
}

int getChar(char* valor,int intentos,int criterio,char limx,char limy,char mensaje[],char error[])
{
    int rta = 0,i=0;
    char auxChar;
    printf("%s",mensaje );
    fflush(stdin);
    scanf("%c",&auxChar);
    while(i<intentos)
    {
    if(i)
    {
    printf("%s",error);
    fflush(stdin);
    scanf("%c",&auxChar);
    }
    auxChar=tolower(auxChar);
        if (!criterio)
        {
            if (auxChar>=limx && auxChar<=limy)
            {
                rta=1;
                break;
            }
        }else
            {
            if (auxChar==limx || auxChar==limy)
            {
                rta=1;
                break;
            }
            }
    i++;
    }
    if (rta)
    {
        *valor=auxChar;
    }
    return rta;

}
