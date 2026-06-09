#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define M 100
#define ll long long

typedef struct node{
    int index;
    int coeff;
} node;

int inc(const void *a, const void *b) {
    struct node *aa=(struct node *)a;
	struct node *bb=(struct node *)b;
	return aa->index-bb->index;
}

// coefficient
// index
// multi

int main() {
    node multi1[M],multi2[M],ans[2*M];
    int i,j,k,n1=0,n2=0;
    char c=' ';
    do{
        scanf("%d%d%c",&multi1[n1].coeff,&multi1[n1].index,&c);
        n1++;
    }while(c!='\n');
    do{
        scanf("%d%d%c",&multi2[n2].coeff,&multi2[n2].index,&c);
        n2++;
    }while(c!='\n');

    // for(i=0;i<n1;i++){
    //     printf("%d %d ",multi1[i].coeff,multi1[i].index);
    // }
    // printf("\n");
    // for(i=0;i<n2;i++){
    //     printf("%d %d ",multi2[i].coeff,multi2[i].index);
    // }

    for(i=0,k=0;i<n1;i++){
        for(j=0;j<n2;j++){
            ans[k].coeff=multi1[i].coeff*multi2[j].coeff;
            ans[k].index=multi1[i].index+multi2[j].index;
            k++;
        }
    }

    qsort(ans, k, sizeof(node), inc);

    for(i=0;i<k;i++){
        for(j=i+1;j<k;j++){
            if(ans[i].index==ans[j].index){
                ans[i].coeff+=ans[j].coeff;
                ans[j].coeff=0;
            }else{
                break;
            }
        }
    }

    for(i=k-1;i>=0;i--){
        if(ans[i].coeff!=0){
            printf("%d %d ",ans[i].coeff,ans[i].index);
        }     
    }

	return 0;
}
