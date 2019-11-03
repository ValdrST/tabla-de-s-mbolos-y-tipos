#ifndef PILATABLASIMBOL_H_INCLUDED
typedef struct _symstack symstack;
struct _symstack{
symtab *root;
int num;
};
symstack *crearSymStack();
void borrarSymStack();
void insertarSymTab(symtab *sym);
symtab* getCima(symstack *s);
symtab* sacarSymTab(symstack *ss);
#define PILATABLASIMBOL_H_INCLUDED
#endif