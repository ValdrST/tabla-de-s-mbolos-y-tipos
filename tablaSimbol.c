#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablaSimbol.h"
param *crearParam(int tipo){
    param *p = (param*)malloc(sizeof(param));
    p->tipo = tipo;
    p->next = NULL;
    return p;
}

void borraParam(param *p){
    while(p!=NULL){
        borraParam(p->next);
        free(p);
    }
}

listParam *crearLP(){
    listParam *lp = (listParam*)malloc(sizeof(listParam));
    return lp;
}

void add(listParam lp, int tipo){
    param *p, *p_next;
    p = lp.root;
    while(p != NULL){
        p_next = p->next;
        if(p_next == NULL){
            p->next = crearParam(tipo);
        }
        p = p_next->next;
        
    }
    lp.num++;
}

void borrarListParam(listParam *lp){
    borraParam(lp->root);
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
    while(s!=NULL){
        borrarSymbol(s->next);
        free(s);
    }
}

symtab *crearSymTab(){
    symtab *st = (symtab*)malloc(sizeof(symtab));
    st->next=NULL;
    st->num = 0;
    st->root = NULL;
    return st;
}

void borrarSymTab(symtab *st){
    while(st!=NULL){
        borrarSymTab(st->next);
        borrarSymbol(st->root);
        free(st);
    }
}

int insertar(symtab *st, symbol *sym){
    symbol *s, *s_next;
    s = st->root;
    while(s != NULL){
        s_next = s->next;
        if(s_next == NULL){
            s->next = sym;
            sym->next = NULL;
            st->num++;
            return st->num;
        }
        s = s_next;
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
    return NULL;
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


char* getParams(param *p){
    param *p_next;
    char* param_s = "";
    do{
        char* c = malloc(sizeof(char)*100);
        strcat(param_s," ");
        sprintf(c, "%d", p->tipo);
        strcat(param_s,c);
        p_next = p->next;
    }while(p_next != NULL);
    return param_s;
}

void printTablaSimbolos(symtab *st){
    symbol *s_next;
    if(st!=NULL)
    do{
        if(st->root != NULL){
            printf("id: %d dir: %d tipo: $d tipoVar: %d params: %s\n",st->root->id,st->root->dir,st->root->tipo,st->root->tipoVar,getParams(st->root->params->root));
            s_next = st->root->next;
        }
    }while(s_next != NULL);
    else{
        printf("No hay simbolos en la tabla\n");
    }
    
}