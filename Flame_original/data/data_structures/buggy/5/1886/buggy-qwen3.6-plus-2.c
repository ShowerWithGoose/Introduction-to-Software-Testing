#include <stdio.h>
#include <stdlib.h>
struct x{
    int a;
    int n;
    
};
int cmp(const void* a,const void* b){
    return (((struct x*)b)->n-((struct x*)a)->n);
}
struct x  num1[200000], num2[200000], result[200000];
int main()
{
    
    int A,N,i=0,n1,n2;
     while (1) {
        scanf("%d", &A);
        scanf("%d", &N);
        num1[i].a = A;
        num1[i].n = N;
        i++;
        if (getchar() == '\n') {
            break; 
        }  
    }
    n1=i;
    i=0;
    
     while (1) {
        scanf("%d", &A);
        scanf("%d", &N);
        num2[i].a = A;
        num2[i].n = N;
        i++;
        if (getchar() == '\n') {
            break; 
        }  
    }
    n2=i;
    
    int re=0;
    for(i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
        result[re].a=num1[i].a*num2[j].a;
        result[re].n=num1[i].n+num2[j].n;
        re++;
        }
    }
    qsort(result,re-1,sizeof(result[0]),cmp); // @@ The second parameter should be 're' instead of 're-1', as qsort requires the total number of elements to sort.

    int A1,N1;
    A1=result[0].a;
    N1=result[0].n;
    for(int z=0;z<re;z++){ // @@ The loop logic fails to print the last accumulated term after the loop finishes, and incorrectly handles term merging.
        if(result[z].n==N1){
            if(z==0&&re!=1){
                continue;
            }
            if(re==1){ // @@ This condition is misplaced and causes incorrect output behavior; it disrupts the accumulation logic for single-term results.
                printf("%d ",A1);
                printf("%d ",N1);
            }
            A1+=result[z].a; // @@ Fails to check if the accumulated coefficient becomes zero, which should be omitted from the output.
        }else{
            printf("%d ",A1);
            printf("%d ",N1);
            N1=result[z].n;
            A1=result[z].a;
        }
    } // @@ Missing code to print the final accumulated term (A1 and N1) after the loop completes.
    
    return 0;
}