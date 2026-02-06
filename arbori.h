#ifndef _arbori
#define _arbori

typedef struct nod_arbore{
    int val;
    struct nod_arbore *p, *st, *dr;
}nod_arb;

typedef struct arb{
    struct nod_arbore* root;
}arbore;

nod_arb* arb_init_root ( arbore *tree, int x );

nod_arb* arb_create ( int x );

void arb_inorder ( nod_arb *radac );

void arb_postorder ( nod_arb *radac );

void arb_preorder ( nod_arb *radac );

nod_arb* arb_min ( nod_arb* n );

nod_arb* arb_max ( nod_arb* n );

void arb_insert ( arbore *tree, nod_arb *node );

void arb_del ( arbore *tree, nod_arb *node );

nod_arb* arb_search_it ( nod_arb *node, int key );

nod_arb* arb_search_rec ( nod_arb *node, int key );

void arb_transplant ( arbore *tree, nod_arb *node1, nod_arb *node2 );

nod_arb* arb_succ ( nod_arb *n );

#endif // _arbori
