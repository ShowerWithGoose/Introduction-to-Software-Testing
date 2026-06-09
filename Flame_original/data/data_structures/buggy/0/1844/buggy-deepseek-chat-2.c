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
            if((a[j-1]>='0'&&a[j+1]<='9'&&a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<a[j+1])){ // @@ The condition for digits is incomplete; it only checks the right bound for digits but not the left bound (should be a[j-1]>='0' as well). Also, the condition for letters is similarly incomplete; it should check both left and right bounds (e.g., a[j-1]>='a' && a[j-1]<='z' && a[j+1]>='a' && a[j+1]<='z').
                delta=a[j+1]-a[j-1];
                for(k=1;k<=delta-1;k++){ // @@ The loop should run while k <= delta, not delta-1, to include all characters between a[j-1] and a[j+1] (e.g., for a-d, delta=3, should print b,c,d, but delta-1=2 only prints b,c).
                printf("%c",a[j-1]+k);
                }
                
                
            }
        }
    }
    return 0;
}