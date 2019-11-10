#include <stdio.h>
#include "tablaSimbol.h"
#include "pilaTablaSimbol.h"
#include "tablaTipo.h"
#include "pilaTablaTipo.h"




int main(int argc, char *argv[]){
    typestack *ptt = crearTypeStack();
    symstack *pts = crearSymStack();
    insertarTypeTab(ptt,crearTypeTab()); //Insertar tabla de tipos y crearla
    insertarTipo(getCimaType(ptt),crearTipo("int",4,1));
    if(ptt->root == NULL){
        printf("que wey");
    }
    printTablaTipos(ptt->root);
    return 0;
}