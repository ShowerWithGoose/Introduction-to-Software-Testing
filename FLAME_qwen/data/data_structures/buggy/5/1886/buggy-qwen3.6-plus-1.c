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
    qsort(result,re-1,sizeof(result[0]),cmp); // @@ [Error: The second parameter of qsort should be the total number of elements 're', not 're-1'. Using 're-1' excludes the last term from sorting.]
    
    int A1,N1;
    A1=result[0].a;
    N1=result[0].n;
    for(int z=0;z<re;z++){ // @@ [Error: The loop logic incorrectly skips accumulation for the first element when re>1, and critically fails to print the last accumulated term after the loop ends.]
        if(result[z].n==N1){
            if(z==0&&re!=1){
                continue;
            }
            if(re==1){
                printf("%d ",A1);
                printf("%d ",N1);
            }
            A1+=result[z].a;
        }else{
            printf("%d ",A1);
            printf("%d ",N1);
            N1=result[z].n;
            A1=result[z].a;
        }
    } 
    
    return 0; // @@ [Error: Missing code to print the final accumulated term (A1, N1) after the loop finishes, causing the last group of merged terms to be omitted from the output.]
}