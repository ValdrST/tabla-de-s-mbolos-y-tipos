#include <stdlib.h>
#include "tablaSimbol.h"
#include "pilaTablaSimbol.h"
symstack *crearSymStack(){
    symstack *ss = malloc(sizeof(symstack));
    ss->num = 0;
    ss->root=NULL;
    return ss;
}

void borrarSymStack(symstack *ss){
    if(ss != NULL){
        borrarSymTab(ss->root);
        free(ss);
    }
}

void insertarSymTab(symstack *ss, symtab *sym){
    symtab *st_aux, *st_next;
    st_aux = ss->root;
    while(st_aux == NULL){
        st_next = st_aux->next;
        if(st_next==NULL){
            st_aux->next=sym;
            ss->num++;
        }
        st_aux = st_next;   
    }
}

symtab* getCima(symstack *ss){
    symtab *st_aux, *st_next;
    st_aux = ss->root;
    while(st_aux == NULL){
        st_next = st_aux->next;
        if(st_next==NULL){
            return st_aux;
        }
        st_aux = st_next;   
    }
    return NULL;
}

symtab* sacarSymTab(symstack *ss){
    symtab *ts_aux, *ts_next, *tt;
    tt = (symtab*)malloc(sizeof(symtab));
    ts_aux = ss->root;
    while(ts_aux == NULL){
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

