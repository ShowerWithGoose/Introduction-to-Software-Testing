#include<stdio.h>
#include<stdlib.h>

typedef struct a{
    int coefficient;
    int power;
}POLY;

int cmp(const void *a, const void *b);

int main(){
    POLY p1[50000], p2[50000], multi[90000];
    char c;
    int i = 0, n1, n2;
    do
    {
        scanf("%d%d%c", &p1[i].coefficient, &p1[i].power, &c);
        ++i;
    } while (c != '\n');
    n1 = i;

    i = 0;
    while (scanf("%d%d", &p2[i].coefficient, &p2[i].power) != EOF)
    {
        ++i;
    }
    n2 = i;
    /*读入数据，存放在两个数组里面*/

    /*遍历两个数组，依次做乘法*/
    int m = 0;
    for(int j = 0; j < n1; ++j){
        for(int k = 0; k < n2; ++k){
            multi[m].coefficient = p1[j].coefficient * p2[k].coefficient;
            multi[m].power = p1[j].power + p2[k].power;
            ++m;
        }
    }

    qsort(multi, m, sizeof(multi[0]), cmp);
    POLY max;
    max = multi[0];
    for(int k = 1; k < m; k++){
        if(max.power == multi[k].power){
            max.coefficient += multi[k].coefficient;
        }
        else{
            printf("%d %d ", max.coefficient, max.power);
            max = multi[k];
        }
    }

    printf("%d %d", max.coefficient, max.power);


    
    




    return 0;
}

int cmp(const void *a, const void *b){
    POLY *c = (POLY*)a;
    POLY *d = (POLY*)b;
    return -(c->power - d->power);
}
