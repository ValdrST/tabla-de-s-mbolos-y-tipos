#include <stdlib.h>
#include <stdio.h>
#include "tablaTipo.h"
#include "pilaTablaTipo.h"

//Se crea una nueva pila de tablas de tipos y se inicializa
typestack *crearTypeStack(){
    typestack *ts = malloc(sizeof(typestack));
    ts->num = 0;
    ts->root=NULL;
    return ts;
}
// Elimina la pila y limpia la memoria elemento a elemento
void borrarTypeStack(typestack *ts){
    if(ts != NULL){
        borrarTypeTab(ts->root);
        free(ts);
    }
}
// Inserta una tabla de simbolos y aumenta el contador
void insertarTypeTab(typestack *ts, typetab *sym){
    typetab *tb_aux, *tb_next;
    tb_aux = ts->root;
    if(tb_aux == NULL){
        ts->root = sym;
        ts->num++;
    }  else
        while(tb_aux != NULL){
            tb_next = tb_aux->next;
            if(tb_next==NULL){
                tb_aux->next=sym;
                ts->num++;
            }
            tb_aux = tb_next;   
        }
}
// Se obtiene el elemento que esta en la cima de la tabla de simbolo
typetab* getCimaType(typestack *ts){
    typetab *ts_aux, *ts_next;
    ts_aux = ts->root;
    
    while(ts_aux != NULL){
        ts_next = ts_aux->next;
        if(ts_next==NULL){
            return ts_aux;
        }
        ts_aux = ts_next;   
    }
    
    return NULL;
}

// Hace operacion pop en la pila
typetab* sacarTypeTab(typestack *ts){
    typetab *ts_aux, *ts_next, *tt;
    tt = (typetab*)malloc(sizeof(typetab));
    ts_aux = ts->root;
    while(ts_aux != NULL){
        ts_next = ts_aux->next;
        if(ts_next==NULL){
            *tt = (*ts_aux);
            free(ts_aux);
            return tt;
        }
        ts_aux = ts_next;   
    }
    return NULL;
}