#include <stdio.h>
#include "tablaSimbol.h"
#include "pilaTablaSimbol.h"
#include "tablaTipo.h"
#include "pilaTablaTipo.h"




int main(int argc, char *argv[]){
    typestack *ptt = crearTypeStack();
    symstack *pts = crearSymStack();
    insertarTypeTab(ptt,crearTypeTab()); //Insertar tabla de tipos y crearla
    
    insertarSymTab(pts,crearSymTab());
    // Imprimir las tablas
    printTablaTipos(getCimaType(ptt));
    printTablaSimbolos(getCima(pts));
    return 0;
}