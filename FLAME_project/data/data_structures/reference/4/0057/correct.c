#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct word {
    char wor[15];
    int total;
    struct word *link;
};
struct word wo, *oz = NULL, *pz = NULL, *qz = NULL, *vz = NULL, *first = NULL;
void main()
{
    int i, j, t, u;
    char x;
    FILE * IN = fopen ("article.txt", "r");
    first = (struct word *) malloc (sizeof (struct word));
    memset (first, 0, sizeof (struct word));
    pz = first;
    u = 0;
    while (1) {
        //  printf ("2 ");
        vz = (struct word *) malloc (sizeof (struct word));
        memset (vz, 0, sizeof (struct word));
        i = 0;
        t = 0;
        while (1) {///////////////////////
            if (fscanf (IN, "%c", &x) == EOF) {
                u = 1;
                break;
            }
            if (x >= 'A' && x <= 'Z') x+=32;
            if ((x < 'a' || x > 'z') && t == 0) continue;
            if (x >= 'a' && x <= 'z') {
                vz -> wor[i] = x;
                i++;
                t = 1;
            }
            if ((x < 'a' || x > 'z') && t == 1) break;
        }
        // if (x == EOF) {/////////////////////
        //     printf ("s");
        //     break;
        // }
        pz = first;
        while (1) {
            if (pz -> link == NULL) {
                vz -> total = 1;
                pz -> link = vz;
                break;
            }
            if (strcmp (pz -> link -> wor, vz -> wor) == 0) {
                pz -> link -> total ++;
                break;
            }
            if (strcmp (pz -> link -> wor, vz -> wor) > 0) {
                vz -> total = 1;
                vz -> link = pz -> link;
                pz -> link = vz;
                break;
            }
            pz = pz -> link;
        }
        if (u == 1) break;
    }
    
     pz = first;
    while (pz -> link != NULL) {
        if (pz -> link -> wor[0] != '\0') printf ("%s %d\n", pz -> link -> wor, pz -> link -> total);
        pz = pz -> link;
    }
    fclose (IN);
    return ;
}
