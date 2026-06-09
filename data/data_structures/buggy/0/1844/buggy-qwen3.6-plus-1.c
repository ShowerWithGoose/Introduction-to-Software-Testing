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
            if((a[j-1]>='0'&&a[j+1]<='9'&&a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<a[j+1])){ // @@ The condition incorrectly checks only one bound for each character (e.g., a[j-1]>='0' and a[j+1]<='9'), failing to ensure both characters are within the same valid range. It should check both lower and upper bounds for a[j-1] and a[j+1].
                delta=a[j+1]-a[j-1];
                for(k=1;k<=delta-1;k++){ // @@ The loop condition k<=delta-1 stops one character short, missing the end character of the expansion. It should be k<=delta to include a[j+1].
                printf("%c",a[j-1]+k);
                }
                
                
            }
        }
    }
    return 0;
}