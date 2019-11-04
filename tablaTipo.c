#include <stdlib.h>
#include "tablaTipo.h"

type *crearTipo(){
    type *t = (type*)malloc(sizeof(type));
    t->next = NULL;
    return t;
}
void borrarType(type *t){
    free(t);
}

int insertarTipo(typetab *tt, type *t){
    type *t_aux, *t_next;
    t_aux = tt->root;
    t_next = t_aux->next;
    while(t_aux != NULL){
        if(t_next == NULL){
            t_aux->next = t;
            tt->num++;
            return tt->num;
        }
        t_aux = t_next->next;
        t_next = t_aux->next;
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