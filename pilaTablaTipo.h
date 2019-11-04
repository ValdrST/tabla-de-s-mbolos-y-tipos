#ifndef PILATABLATIPO_H_INCLUDED

typedef struct _typestack typestack;
struct _typestack{
typetab *root;
int num;
};

typestack *crearTypeStack();
void borrarTypeStack(typestack *ts);
void insertarTypeTab(typestack *ts, typetab *sym);
typetab* getCimaType(typestack *ts);
typetab* sacarTypeTab(typestack *ts);
#define PILATABLATIPO_H_INCLUDED
#endif

