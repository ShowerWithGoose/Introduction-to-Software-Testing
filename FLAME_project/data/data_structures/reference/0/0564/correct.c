#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char a[100],b[100];
    scanf("%s",a);
    int l=strlen(a),i,j=0,k;
    for(i=0;i<l;i++)
    {
        if(a[i]=='-')
        {
            if((isupper(a[i-1])&isupper(a[i+1]))|(islower(a[i-1])&islower(a[i+1]))|(isdigit(a[i-1])&isdigit(a[i+1])))
            {
                for(k=1;b[j-1]<a[i+1]-1;j++,k++) b[j]=a[i-1]+k;
                if(k==1) {b[j]=a[i];j++;}
            }
            else {b[j]=a[i];j++;}
        }
        else {b[j]=a[i];j++;}
    }
    int m=strlen(b);
    for(i=m-1;b[i]!=a[l-1];i--);
    for(j=0;j<=i;j++) printf ("%c",b[j]);
    printf("\n");

    return 0;
}





















