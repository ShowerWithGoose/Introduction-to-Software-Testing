#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct xiang {
    int xishu;
    int zhishu;
    struct xiang *link;
};
struct xiang xi, *first[3] = {NULL}, *oz = NULL, *pz = NULL, *qz = NULL, *vz = NULL;

void peek(struct xiang* x){
    for(x=x;x;x=x->link) printf("%d*x^%d, ", x->xishu, x->zhishu);
    printf("\n");
}
void main()
{
    pz = (struct xiang *) malloc (sizeof (struct xiang));
    memset (pz, 0, sizeof (struct xiang));
    first[0] = pz;
    // freopen("input", "r", stdin);
    while (1) {
        vz = (struct xiang *) malloc (sizeof (struct xiang));
        memset (vz, 0, sizeof (struct xiang));
        scanf ("%d%d", &vz -> xishu, &vz -> zhishu);
        pz -> link = vz;
        if (getchar () != ' ') break;
        pz = pz -> link;
    }
    // peek(first[0]);
    
    pz = (struct xiang *) malloc (sizeof (struct xiang));
    memset (pz, 0, sizeof (struct xiang));
    first[1] = pz;
    while (1) {
        vz = (struct xiang *) malloc (sizeof (struct xiang));
        memset (vz, 0, sizeof (struct xiang));
        scanf ("%d%d", &vz -> xishu, &vz -> zhishu);
        pz -> link = vz;
        if (getchar () != ' ') break;
        pz = pz -> link;
    }
    // peek(first[1]);
    pz = (struct xiang *) malloc (sizeof (struct xiang));
    memset (pz, 0, sizeof (struct xiang));
    first[2] = pz;
    oz = first[0] -> link;
    qz = first[1] -> link;
    while (1) {
        if (oz == NULL) {
            // peek(qz);
            qz = qz -> link;
            oz = first[0] -> link;
        }
        // peek (oz);
        if (qz == NULL) {
            break;
        }
        vz = (struct xiang *) malloc (sizeof (struct xiang));
        memset (vz, 0, sizeof (struct xiang));
        vz -> xishu = oz -> xishu * qz -> xishu;
        vz -> zhishu = oz -> zhishu + qz -> zhishu;
        // peek(vz);
        pz = first[2];
        if (pz -> link == NULL) {
            pz -> link = vz;
            // peek(pz);
        }
        else
            while (pz -> link != NULL) {
                // printf ("%d %d\n", pz -> link -> zhishu, vz -> zhishu);
                // printf ("1");
                // return ;
                
                if (pz -> link -> zhishu == vz -> zhishu) {
                    // printf ("2 ");
                    pz -> link -> xishu += vz -> xishu;
                    break;
                }
                else if (pz -> link -> zhishu < vz -> zhishu) {
                    // printf ("3");
                    vz -> link = pz -> link;
                    pz -> link = vz;
                    break;
                    // return ;
                }
                else if (pz -> link -> link == NULL) {
                    // printf ("4 ");
                    pz -> link -> link = vz;
                    break;
                    // return ;
                }
                pz = pz -> link;
            }
            // printf ("end");
        oz = oz -> link;
    }
    // printf ("end");
    pz = first[2];
    while (pz -> link != NULL) {
        printf ("%d %d ", pz -> link -> xishu, pz -> link -> zhishu);
        pz = pz -> link;
    }
    return ;
}
