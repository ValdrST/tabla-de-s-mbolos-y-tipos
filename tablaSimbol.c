#include <stdlib.h>
#include <string.h>
#include "tablaSimbol.h"
param *crearParam(int tipo){
    param *p = (param*)malloc(sizeof(param));
    p->tipo = tipo;
    p->next = NULL;
    return p;
}

void borraParam (param *p){
    free(p);
}

listParam *crearLP(){
    listParam *lp = (listParam*)malloc(sizeof(listParam));
    return lp;
}

void add(listParam lp, int tipo){
    param *p, *p_next;
    p = lp.root;
    p_next = p->next;
    while(p != NULL){
        if(p_next == NULL){
            p->next = crearParam(tipo);
        }
        p = p_next->next;
        p_next = p->next;
    }
    lp.num++;
}

void borrarListParam(listParam *lp){
    free(lp);
}

int getNumListParam(listParam *lp){
    return lp->num;
}

symbol *crearSymbol(){
    symbol *s = (symbol*)malloc(sizeof(symbol));
    s->next=NULL;
    s->params=NULL;
    return s;
}

void borrarSymbol(symbol *s){
    free(s);
}

symtab *crearSymTab(){
    symtab *st = (symtab*)malloc(sizeof(symtab));
    st->next=NULL;
    st->num = 0;
    st->root = NULL;
    return st;
}

void borrarSymTab(symtab *st){
    free(st);
}

int insertar(symtab *st, symbol *sym){
    symbol *s, *s_next;
    s = st->root;
    s_next = s->next;
    while(s != NULL){
        if(s_next == NULL){
            s->next = sym;
            sym->next = NULL;
            st->num++;
            return st->num;
        }
        s = s_next->next;
        s_next = s->next;
    }
    return -1;
}

int buscar(symtab *st, char *id){
    symbol *s;
    s = st->root;
    int i = 0;
    while(s != NULL){
        if(strcmp(s->id,id)==0){
            return i;
        }
        s = s->next;
        i++;
    }
    return -1;
}

int getTipo(symtab *st, char *id){
    symbol *s;
    s = st->root;
    while(s != NULL){
        if(strcmp(s->id,id)==0){
            return s->tipo;
        }
        s = s->next;
    }
    return -1;
}

int getTipoVar(symtab *st, char *id){
    symbol *s;
    s = st->root;
    while(s != NULL){
        if(strcmp(s->id,id)==0){
            return s->tipoVar;
        }
        s = s->next;
    }
    return -1;
}

int getDir(symtab *st, char *id){
    symbol *s;
    s = st->root;
    while(s != NULL){
        if(strcmp(s->id,id)==0){
            return s->dir;
        }
        s = s->next;
    }
    return -1;
}

listParam *getListParam(symtab *st, char *id){
    symbol *s;
    s = st->root;
    while(s != NULL){
        if(strcmp(s->id,id)==0){
            return s->params;
        }
        s = s->next;
    }
    return -1;
}

int getNumParam(symtab *st, char *id){
    symbol *s;
    s = st->root;
    while(s != NULL){
        if(strcmp(s->id,id)==0){
            return s->params->num;
        }
        s = s->next;
    }
    return -1;
}