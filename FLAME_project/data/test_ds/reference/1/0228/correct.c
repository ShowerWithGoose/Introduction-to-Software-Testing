#include <stdio.h>
#include <stdlib.h>

char a[500000],c[500000];
int main()
{
    int i,j,k;
    scanf("%s",a);
    for(i=0,j=0;i<=strlen(a)-1;i++,j++){
        if(a[i]!='-'){
            c[j]=a[i];
        }
        //printf("%c\n",c[j]);
        if(a[i]=='-'){
            if((a[i+1]>='0'&&a[i+1]<='9'&&a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>a[i-1])||(a[i+1]>='a'&&a[i+1]<='z'&&a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>a[i-1])||(a[i+1]>='A'&&a[i+1]<='Z'&&a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>a[i-1])){
                for(;a[i+1]>c[j-1]+1;j++){
                    c[j]=c[j-1]+1;
                }
                j-=1;
            }
            else{
                c[j]=a[i];
        }

        }
        //printf("%c\n",c[j]);
    }
   printf("%s",c);

}

