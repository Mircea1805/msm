#ifndef MODULES_H
#define MODULES_H

/* Loaded modules are kept in a linked list */
typedef struct node 
{
    char module_name[64];
    struct node *next;
} node;

/* Function for adding and running modules */
int add_modules(const char *name);

/* Function for listing loaded modules */
void list_modules();

#endif