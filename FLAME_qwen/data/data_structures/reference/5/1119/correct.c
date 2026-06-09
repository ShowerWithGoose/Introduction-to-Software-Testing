#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
struct mult{
    int co;
    int index;
}M1[150],M2[150],M3[150];
int cmp(const void*a,const void*b){
	struct mult*aa=(struct mult*)a;
	struct mult*bb=(struct mult*)b;
    if((aa->index)!=(bb->index))
	    return ((bb->index)-(aa->index));
    else
        return ((bb->co)-(aa->co));

}
int main(){
    int i=0, j=0,k,l,num=0,num1;
    char x='\0';
    scanf("%d %d%c", &M1[i].co, &M1[i].index, &x);
    while(x!='\n'){
        i++;
        scanf("%d %d%c", &M1[i].co,&M1[i].index, &x);
    }
    x = '\0';
    scanf("%d %d%c", &M2[j].co, &M2[j].index, &x);
    while(x!='\n'){
        j++;
        scanf("%d %d%c", &M2[j].co, &M2[j].index, &x);
    }
    for (k = 0; k <= i; k++){
        for (l = 0; l <= j; l++){
            M3[num].co = M1[k].co * M2[l].co;
            M3[num].index = M1[k].index + M2[l].index;
            num++;
        }
    }
    num1 = num;
    for (k = 0; k < num-1; k++){
        for (l = k + 1; l < num; l++){
            if(M3[k].index==M3[l].index&&M3[l].co!=0&&M3[k].co!=0){
                M3[k].co+= M3[l].co;
                M3[l].co = 0;
                M3[l].index = 0;
                num1--;
            }
            
        }
    }
    qsort(M3,num ,sizeof(struct mult) , cmp);
    for (k = 0; k < num1;k++){
        printf("%d %d ", M3[k].co, M3[k].index);
    }
    return 0;
}
