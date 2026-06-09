#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int i=0,k=0,n=0;
    FILE *in;
    in=fopen("article.txt","r");
    char a,x[1002],b[100][200],temp[100],count[100]={0};
    while((a=fgetc(in))!=EOF)
    {
        x[i]=a;
        i++;
    }
    for(int i=0;i<strlen(x);i++)
    {
        if(x[i]>='A'&&x[i]<='Z')
            x[i]=x[i]+32;
    }
    for(int i=0;i<strlen(x);i++)
    {
        if(x[i]>='a'&&x[i]<='z')
        {
            for(int j=0;x[j+i]<='z'&&x[j+i]>='a';j++)
            {
                b[k][j]=x[j+i];
                n=j;
            }
            b[k][n+1]='\0';
            k++;
            i+=n;
        }
    }
    for(int i=0;i<k;i++)
    {
        count[i]=1;
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k-i-1;j++)
        {
            if(strcmp(b[j],b[j+1])>0)
            {
                strcpy(temp,b[j]);
                strcpy(b[j],b[j+1]);
                strcpy(b[j+1],temp);
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        if(strcmp(b[i],b[i+1])==0)
        {
            count[i]++;
            for(int j=i;j<k;j++)
            {
                strcpy(b[j],b[j+1]);
            }
            for(int j=i+1;j<k;j++)
            {
                count[j]=count[j+1];
            }
            k--;
            i--;
        }
    }
    for(int i=0;i<k;i++)
    {
            printf("%s %d",b[i],count[i]);
            printf("\n");
    }
    return 0;
}

