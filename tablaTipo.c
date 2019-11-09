#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tablaTipo.h"

typetab *crearTypeTab(){
    typetab *tt = malloc(sizeof(typetab));
    tt->root = NULL;
    tt->num = 0;
    tt->next=NULL;
}

type *crearTipo(char* nombre,int tam, int numElem,tipoBase tb){
    type *t = (type*)malloc(sizeof(type));
    strcpy(t->nombre,nombre);
    t->tamBytes = tam;
    t->numElem = numElem;
    t->tb = tb;
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

void printTablaTipos(typetab *tt){
    type *t_next;
    if(tt->root != NULL)
        do{
            printf("id: %d nombre: %s numero elementos: %d tamaño: %d\n",tt->root->id,tt->root->nombre,tt->root->numElem,tt->root->tamBytes);
            t_next = tt->root->next;
        }while(t_next!=NULL);
    else
        printf("No hay tipos en la tabla\n");
    
}