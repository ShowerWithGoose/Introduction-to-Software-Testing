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
        if(h2[j]<=h2[j+1])
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
    for(i=0;i<k-1;i++){
       if(h2[i]==h2[i+1])
       {
           h1[i]+=h1[i+1];
           for(j=i+1;j<k-1;j++){
            h1[j]=h1[j+1];h2[j]=h2[j+1];
           }
           k--; // @@ Missing i-- after decrementing k causes the loop to skip checking the newly shifted element against the current one
       }
    }
    for(i=0;i<k;i++){
        printf("%d %d ",h1[i],h2[i]); // @@ Should check if h1[i] != 0 before printing to avoid outputting terms with zero coefficients
    }
    return 0;
}