#ifndef MODULES_H
#define MODULES_H

typedef struct node 
{
    char module_name[64];
    struct node *next;
} node;

int add_modules(const char *name);

void list_modules();

#endif