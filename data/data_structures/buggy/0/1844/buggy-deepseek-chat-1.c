#include<stdio.h>
int main()
{
    char s,a[100];
    int i,j,k,delta;
    for(i=0;scanf("%c",&s)!=EOF;i++){
        a[i]=s;
    }
    for(j=0;j<=i;j++){
        if(a[j]!='-'){
            printf("%c",a[j]);
        }
        else if(a[j]=='-'){
            if((a[j-1]>='0'&&a[j+1]<='9'&&a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<a[j+1])){
                delta=a[j+1]-a[j-1];
                for(k=1;k<=delta-1;k++){ // @@ The loop condition should be k < delta, not k <= delta-1, to correctly output characters between the two endpoints. Also, the original reference program uses k <= s[i+1]-s[i-1], which is equivalent to k <= delta, but here delta-1 is used, which may cause off-by-one errors.
                printf("%c",a[j-1]+k);
                }
                
                
            }
        }
    }
    return 0;
}