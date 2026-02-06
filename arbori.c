#include <stdlib.h>
#include <stdio.h>
#include "arbori.h"

nod_arb* arb_init_root ( arbore* tree, int x )
{
    tree->root = (nod_arb*)malloc(sizeof(nod_arb));

    tree->root->val = x;
    tree->root->p = NULL;
    tree->root->st = NULL;
    tree->root->dr = NULL;

    return tree->root;
}

nod_arb* arb_create ( int x )
{
    nod_arb* node = (nod_arb*)malloc(sizeof(nod_arb));

    node->val = x;
    node->p = NULL;
    node->st = NULL;
    node->dr = NULL;

    return node;
}

void arb_insert ( arbore *tree, nod_arb *node )
{
    nod_arb *y, *x;

    y = NULL;
    x = tree->root;

    while ( NULL != x )
    {
        y = x;
        if ( node->val < x->val ) x = x->st;
        else x = x->dr;
    }

    node->p = y;
    if ( NULL == y ) tree->root = node;
    else if ( node->val < y->val ) y->st = node;
         else y->dr = node;
}

nod_arb* arb_search_it ( nod_arb *node, int key )
{
    while ( NULL != node && node->val != key )
        if ( key > node->val ) node = node->dr;
        else node = node->st;

    return node;
}

void arb_inorder ( nod_arb *radac )
{
    if ( NULL == radac ) return ;
    else
    {
        arb_inorder(radac->st);
        printf("%d ", radac->val);
        arb_inorder(radac->dr);
    }
}

void arb_preorder ( nod_arb *radac )
{
    if ( NULL == radac ) return ;
    else
    {
        printf("%d ", radac->val);
        arb_preorder(radac->st);
        arb_preorder(radac->dr);
    }
}

void arb_postorder ( nod_arb *radac )
{
    if ( NULL == radac ) return ;
    else{
        arb_postorder(radac->st);
        arb_postorder(radac->dr);
        printf("%d ", radac->val);
    }

}

nod_arb* arb_min ( nod_arb* n )
{
    if ( NULL == n )
    {
        printf("Arbore gol!\n");
        return NULL;
    }

    while ( NULL != n->st ) n = n->st;

    return n;
}

nod_arb* arb_max ( nod_arb* n )
{
    if ( NULL == n )
    {
        printf("Arbore gol!\n");
        return NULL;
    }

    while ( NULL != n->dr ) n = n->dr;

    return n;
}

nod_arb* arb_search_rec ( nod_arb *node, int key )
{
    if ( NULL == node || node->val == key ) return node;
    else{
        if ( node->val > key ) arb_search_rec(node->st, key);
        else arb_search_rec(node->dr, key);
    }
}

nod_arb* arb_succ ( nod_arb *n )
{
    if ( NULL == n ) return NULL;

    if ( NULL != n->dr ) return arb_min(n->dr);

    nod_arb* y = n->p;

    while ( NULL != y && y->dr == n )
    {
        n = y;
        y = y->p;
    }

    return y;
}

void arb_transplant ( arbore *tree, nod_arb *node1, nod_arb *node2 )
{
    if ( NULL == node1->p ) tree->root = node2;
    else if ( node1 == node1->p->st ) node1->p->st = node2;
         else node1->p->dr = node2;

    if ( NULL != node2 ) node2->p = node1->p;
}

void arb_del ( arbore *tree, nod_arb *node )
{
    if ( NULL == node )
    {
        printf("Nodul nu exista\n");
        return ;
    }

    nod_arb *y;
    if ( NULL == node->st ) arb_transplant(tree, node, node->dr);
    else if ( NULL == node->dr ) arb_transplant(tree, node, node->st);
         else
         {
             y = arb_min(node->dr);

             if ( node != y->p )
             {
                arb_transplant(tree, y, y->dr);
                node->dr->p = y;
                y->dr = node->dr;
             }

             arb_transplant(tree, node, y);
             y->st = node->st;
             y->st->p = y;

         }
}
