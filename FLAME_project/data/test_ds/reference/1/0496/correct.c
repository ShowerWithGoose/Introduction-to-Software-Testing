#include<stdio.h>
int main(){
char a[100];
gets(a);
int i=0,j=0;
for(;i<=strlen(a);i++){
    if(a[i]=='-'&&a[i-1]<a[i+1]&&a[i-1]>='a'&&a[i+1]<='z')
    {
        for(char c=a[i-1]+1;c<a[i+1];c++)
            printf("%c",c);
    }
else if(a[i]=='-'&&a[i-1]<a[i+1]&&a[i-1]>='0'&&a[i+1]<='9')
    {
        for(char c=a[i-1]+1;c<a[i+1];c++)
            printf("%c",c);
    }
   else if(a[i]=='-'&&a[i-1]<a[i+1]&&a[i-1]>='A'&&a[i+1]<='Z')
    {
        for(char c=a[i-1]+1;c<a[i+1];c++)
            printf("%c",c);
    }
    else
        printf("%c",a[i]);
}
return 0;
}



