#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct node
{
    int val;
    struct node *next;
} node;

// Functions du prof
node *init_list(void);
node *new_node(int val);
node *addHead(node *head, int new_elmt);
void addTail(node *head, int new_elmt);
void display_list(node *head);

// Perso
// int list_empty(node *list);

int main(int argc, char *argv[])
{
    int i;
    int nombre_a_ajouter = 0;

    node *list = init_list();

    /*
        Ajout de 10 éléments au début
        Comprendre que le dernier i sera en tete de list, (10)
    */

    // Génération du nombre aléatoire
    srand(time(NULL));
    nombre_a_ajouter = (rand() % 101);

    for (i = 1; i <= 10; i++)
    {
        list = addHead(list, nombre_a_ajouter + i);
    }

    //  on ajoute un élément a la fin de la liste
    addTail(list, 17);

    // Et on affiche la liste au complet
    display_list(list);
    printf("\n");
    return 0;
}

node *init_list(void)
{
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        exit(1);
    }
    n->val = -1;
    return n;
}

// int list_empty(node *list)
// {
//     return (list == NULL);
// }

node *new_node(int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->val = val;
    return n;
}

node *addHead(node *head, int new_elmt)
{
    if (head->val == -1)
    {
        head->val = new_elmt;
        return head;
    }
    else
    {
        node *p = new_node(new_elmt);
        p->next = head;
        head = p;
        return head;
    }
}

void addTail(node *head, int new_elmt)
{
    if (head == NULL)
        addHead(head, new_elmt);
    else
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
        node *p = new_node(new_elmt);
        p->val = new_elmt;
        head->next = p;
    }
}

void display_list(node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// void delete (node *list)
// {
//     if (list == NULL)
//     {
//         exit(1);
//     }
// }
