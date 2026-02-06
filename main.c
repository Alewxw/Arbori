#include <stdio.h>
#include <stdlib.h>
#include "arbori.h"

int main()
{
    arbore A;
    A.root = NULL;
    int x;
    nod_arb *rad;
    printf("Ce valoare vrei sa aibe radacina arborului tau?\n");
    scanf("%d", &x);
    rad = arb_init_root(&A, x);

    int cheie = -2;
    

    while ( cheie )
    {
        printf("\n!~~Meniu~~!\n");
        printf("Ce operatie vrei sa faci?\n");
        printf("0: Iesire din program\n");
        printf("1: Inserare nod in arbore\n");
        printf("2: Stergere nod din arbore\n"); 
        printf("3: Cautare nod in arbore iterativ\n");
        printf("4: Afisare element minim\n");
        printf("5: Afisare element maxim\n");
        printf("6: Afisare arbore inordine\n");
        printf("7: Afisare arbore preordine\n");
        printf("8: Afisare arbore postordine\n");
        printf("9: Cautare nod in arbore recursiv\n");
        printf("10: Succesorul unui nod\n");

        scanf("%d", &cheie);
        switch ( cheie )
        {
            case 0:
            {
                printf("Programul a fost incheiat!\n");
                return 0;
            }

            case 1:
            {
                int elem;

                printf("Ce valoare vrei sa aiba nodul inserat?\n");
                scanf("%d", &elem);

                nod_arb* nod = arb_create(elem);

                arb_insert(&A, nod);

                printf("Nodul cu valoarea %d a fost inserat in arbore!\n", nod->val);
                rad = A.root; // rad fiind local, trebuie actualizat daca se intampla o stergere si apoi o inserare din nou asupra radacinii

                break;
            }

            case 2:
            {
                int x;
                printf("Ce valoare vrei sa aibe nodul sters?\n");
                scanf("%d", &x);

                nod_arb *aux = arb_search_it(rad, x);
                if ( NULL == aux ) printf("Elementul nu poate fi sters pentru ca nu exista\n");
                else
                {
                    arb_del(&A, aux);
                    printf("Elementul a fost sters cu succes\n");
                }

                rad = A.root;
                break;
            }

            case 3:
            {
                if (rad == NULL)
                {
                    printf("Arborele este gol, deci cautarea nu se poate efectua\n");
                    break;
                }

                int elem;
                printf("Ce valoarea vrei sa cauti iterativ in arbore?\n");
                scanf("%d", &elem);

                nod_arb* rez = arb_search_it(rad, elem);

                if ( NULL == rez ) printf("Elementul %d nu a fost gasit iterativ in arbore\n", elem);
                else printf("Elementul %d a fost gasit iterativ in arbore\n", elem);

                break;
            }

            case 4:
            {
                nod_arb* min = arb_min(rad);

                if ( NULL == min ) printf("Arborele este gol deci nu se poate gasi minimul\n");
                else printf("Elementul minim gasit in arbore este: %d\n", min->val);

                break;
            }

            case 5:
            {
                nod_arb* max = arb_max(rad);

                if ( NULL == max ) printf("Arborele este gol deci nu se poate gasi maximul\n");
                else printf("Elementul maxim gasit in arbore este: %d\n", max->val);

                break;
            }

            case 6:
            {
                printf("Parcurgerea inordine a arborelui este: ");
                arb_inorder(rad);
                break;
            }

            case 7:
            {
                printf("Parcurgerea preordine a arborelui este: ");
                arb_preorder(rad);
                break;
            }

            case 8:
            {
                printf("Parcurgerea postordine a arborelui este: ");
                arb_postorder(rad);
                break;
            }

            case 9:
            {
                int x;
                printf("Ce valoare vrei sa aibe nodul pe care-l cauti recursiv in arbore?\n");
                scanf("%d", &x);

                nod_arb* node = arb_search_rec(rad, x);
                if ( NULL == node ) printf("Elementul nu a fost gasit recursiv in arboren\n");
                else printf("Elementul a fost gasit recursiv in arbore\n");

                break;
            }

            case 10:
            {
                int x;
                printf("Ce valoare vrei sa aibe nodul caruia ii cautam succesorul?\n");
                scanf("%d", &x );

                nod_arb* aux = arb_search_rec(rad, x);
                if ( NULL == aux ) printf("Nodul nu a fost gasit in arbore\n");
                else printf("Succesorul elementului %d este %d\n", x, aux->val);

            }

            default:
            {
                printf("Operatie inexistenta!");
                break;
            }

        }

    }
    return 0;
}
