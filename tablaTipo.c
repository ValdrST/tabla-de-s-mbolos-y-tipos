#include <stdlib.h>
#include "tablaTipo.h"

type *crearTipo(){
    type *t = (type*)malloc(sizeof(type));
    t->next = NULL;
    return t;
}

void borrarTypeTab(typetab *tt){
    while(tt!=NULL){
        borrarTypeTab(tt->next);
        borrarType(tt->root);
        free(tt);
    }
}

void borrarType(type *t){
    while(t!=NULL){
        borrarType(t->next);
        free(t);
    }
}

int insertarTipo(typetab *tt, type *t){
    type *t_aux, *t_next;
    t_aux = tt->root;
    while(t_aux != NULL){
        t_next = t_aux->next;
        if(t_next == NULL){
            t_aux->next = t;
            tt->num++;
            return tt->num;
        }
        t_aux = t_next;
    }
    return -1;
}

tipoBase getTipoBase(typetab *tt , int id){
    type *t;
    t = tt->root;
    while(t != NULL){
        if(t->id==id){
            return t->tb;
        }
        t = t->next;
    }
    tipoBase tb;
    tb.est=false;
    return tb;
}

int getTam(typetab *tt, int id){
    type *t;
    t = tt->root;
    while(t != NULL){
        if(t->id==id){
            return t->tamBytes;
        }
        t = t->next;
    }
    return -1;
}

int getNumElem(typetab *tt, int id){
type *t;
    t = tt->root;
    while(t != NULL){
        if(t->id==id){
            return t->numElem;
        }
        t = t->next;
    }
    return -1;
}

char* getNombre(typetab *tt, int id){
    type *t;
    t = tt->root;
    while(t != NULL){
        if(t->id==id){
            return t->nombre;
        }
        t = t->next;
    }
    return NULL;
}