#include <stdio.h>
int main()
{
    int a1[100]={0},a2[100]={0},a3[100]={0},a4[100]={0};
    int i,b1,b2;
    for(i=0; ;i++){
        scanf("%d",&a1[i]);
        scanf("%d",&a2[i]);
        if(getchar()=='\n'){
                b1=i;
            break;
        }
    }
    for(i=0; ;i++){
        scanf("%d",&a3[i]);
        scanf("%d",&a4[i]);
        if(getchar()=='\n'){
                b2=i;
            break;
        }
    }
    int j,h1[500]={0},h2[500]={0},k=0;
    for(i=0;i<=b1;i++){
        for(j=0;j<=b2;j++){
           h1[k]=a1[i]*a3[j];
           h2[k]=a2[i]+a4[j];
           k++;
        }
    }
    int tem1,tem2;
    for(i=0;i<k-1;i++){
       int flag=0;
       for(j=0;j<k-i-1;j++){
        if(h2[j]<=h2[j+1]) // @@ The sorting condition uses <= which makes the sort unstable and potentially incorrect for descending order when exponents are equal, but more importantly, the merging logic below fails to handle multiple terms with the same exponent correctly if they are not adjacent after this sort or if the merge loop doesn't iterate properly. However, the primary logical error leading to Wrong Answer is in the merging step.
        {
            tem1=h1[j];tem2=h2[j];
            h1[j]=h1[j+1];h2[j]=h2[j+1];
            h1[j+1]=tem1;h2[j+1]=tem2;
            flag=1;
        }
       }
       if(flag==0)
            break;
    }
   int g=k;
    for(i=0;i<k-1;i++){ // @@ The loop bound and logic for merging terms with same exponents is flawed. When a term is merged (k--), the current index i should not be incremented immediately because the new term at i might need to be merged with the next one again. Also, the inner shift loop bound `j<k-1` uses the original k or updated k incorrectly relative to the outer loop structure. Specifically, if h2[i]==h2[i+1], we merge them. But if h2[i] is also equal to h2[i+2] (which shifts to i+1), the current loop increments i, skipping the check for the new neighbor. A `while` loop or decrementing `i` is needed.
       if(h2[i]==h2[i+1])
       {
           h1[i]+=h1[i+1];
           for(j=i+1;j<k-1;j++){
            h1[j]=h1[j+1];h2[j]=h2[j+1];
           }
           k--;
           i--; // @@ Missing decrement of i to re-check the current position after merging and shifting. Without this, if three terms have the same exponent, the second and third might not be merged correctly with the first.
       }
    }
    for(i=0;i<k;i++){
        printf("%d %d ",h1[i],h2[i]);
    }
    return 0;
}