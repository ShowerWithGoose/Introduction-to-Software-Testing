#include<stdio.h>
int main()
{
    char s,a[100];
    int i,j,k,delta;
    for(i=0;scanf("%c",&s)!=EOF;i++){
        a[i]=s;
    }
    for(j=0;j<=i;j++){ @@ [Loop goes out of bounds: j<=i includes uninitialized a[i] which holds the last read character (likely '\n' or EOF-induced), and accessing a[j+1] when j==i causes undefined behavior. Also, input reading doesn't stop at newline, causing potential buffer overflow.]
        if(a[j]!='-'){
            printf("%c",a[j]);
        }
        else if(a[j]=='-'){
            if((a[j-1]>='0'&&a[j+1]<='9'&&a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<a[j+1])){ @@ [Incorrect range checks: e.g., 'a[j-1]>='0'' alone doesn't ensure a[j+1] is >= '0'; similarly for letters. Should check both ends are in same category. Also, missing bounds check for j-1 and j+1 being valid indices.]
                delta=a[j+1]-a[j-1];
                for(k=1;k<=delta-1;k++){
                printf("%c",a[j-1]+k);
                }
                
                
            }
        }
    }
    return 0;
}