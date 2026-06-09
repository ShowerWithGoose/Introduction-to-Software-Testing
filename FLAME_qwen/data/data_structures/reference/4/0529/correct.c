#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
struct ci
{
    char c[30];
    int a;
};
struct ci z[500],temp;
int main()
{
    int i=0,j=0,k=0,key=0;
    char ch,ch1[30]={0};
    FILE *fp;
    fp=fopen("article.txt","r");
    ch=fgetc(fp);
    while(ch!=EOF)
    {
        if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
        {
            ch=tolower(ch);
            ch1[i]=ch;
            i++;
        }
        else
        {
            if(strcmp(ch1,"\0")!=0)
            {
                for(j=0;j<k;j++)
                {
                    if(strcmp(ch1,z[j].c)==0)
                    {
                        key=1;
                        z[j].a++;
                        break;
                    }
                    else
                        key=0;
                }
                if(key==0)
                {
                    strcpy(z[k].c,ch1);
                    z[k].a=1;
                    k++;
                }
                memset(ch1,0,sizeof(ch1));
                i=0;
            }
        }
        ch=fgetc(fp);
    }
    for(i=0;i<k;i++)
        for(j=i+1;j<k;j++)
    {
        if(strcmp(z[i].c,z[j].c)>0)
        {
            temp=z[j];
            z[j]=z[i];
            z[i]=temp;
        }
    }
    for(i=0;i<k;i++)
    {
        printf("%s %d\n",z[i].c,z[i].a);
    }

return 0;
}

