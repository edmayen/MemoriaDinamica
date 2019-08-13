#include<stdio.h>
#include<stdlib.h>
void Crear(int**,int*);
void Cargar(int*,int);
void Proceso(int*,int,int*,float*);
void Imprimir(int*,int,int,float);

int main()
{
    system("color F0");
    int *memo=NULL, tamano=0, mayor;
    float promedio;
    Crear(&memo,&tamano);
    tamano=tamano/sizeof(int);
    Cargar(memo,tamano);
    Proceso(memo,tamano,&mayor,&promedio);
    Imprimir(memo,tamano,mayor,promedio);
    free(memo);
    getchar();
    getchar();
}

void Crear(int **memo, int *tamano)
{
    printf("\n\t\t\t\tMemoria Dinamica.\n\n");
    printf("Ingesa el Tamano de Memoria a Utilizar.\n\n");
    scanf("%d",tamano);
    *tamano=*tamano*sizeof(int);
    *memo=(int*)malloc(*tamano);
    if(*memo==NULL)
    {
        printf("\n\nError. Memoria Insuficiente.\n\n");
        exit(1);
    }
}

void Cargar(int *memo, int tamano)
{
    int i;
    printf("\n\nIngresa los Datos al Arreglo.\n\n");
    for(i=0;i<tamano;++i)
    scanf("%d",memo+i);
}

void Proceso(int *memo, int tamano, int *mayor, float *promedio)
{
    int i;
    float suma=0;
    for(i=0;i<tamano;++i)
    {
        suma+=*(memo+i);
    }
    *promedio=suma/tamano;
    *mayor=*(memo+0);
    for(i=1;i<tamano;++i)
    {
        if(*(memo+i)>*mayor)
        {
            *mayor=*(memo+i);
        }
    }
}

void Imprimir(int *memo, int tamano, int mayor, float promedio)
{
    int i;
    printf("\n\nLos Datos Ingresados son:\n");
    for(i=0;i<tamano;++i)
    {
        printf("%d\t",*(memo+i));
    }
    printf("\n\nEl Numero Mayor Encontrado en el Arreglo es: %d\n\n",mayor);
    printf("El Promedio del Arreglo es: %f\n\n",promedio);
}
