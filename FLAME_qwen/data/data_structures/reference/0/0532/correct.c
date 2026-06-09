#include <stdio.h>
#include <string.h>
int main(){
    char a[10000],b[10000];
scanf("%s",a);
int len=strlen(a);
b[0]=a[0];
int i,j;
for(i=1,j=1;i<len-1;i++)
{
    if(a[i]=='-'&&(('0'<=a[i-1]&&a[i-1]<=a[i+1]&&a[i+1]<='9')||('a'<=a[i-1]&&a[i-1]<=a[i+1]&&a[i+1]<='z')||('A'<=a[i-1]&&a[i-1]<=a[i+1]&&a[i+1]<='Z')))
        {
            for(int t=a[i+1]-a[i-1],m=1;m<t;m++,j++)
                b[j]=a[i-1]+m;
        }
    else
    b[j++]=a[i];
}
b[j]=a[i];
b[j+1]='\0';
printf("%s",b);
}



