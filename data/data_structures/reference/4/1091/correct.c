#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void turn(char[]);
char line[200],a[100][100],line1[100];
int cmp(const void *d,const void *b)
{
    return strcmp((char *)d,(char *)b);
}
int hash[100];
int main()
{
    FILE *in;
    int i=0,j=0,k=0,p=0,q=0;
    in=fopen("article.txt","r");
    while((fgets(line1,199,in))!=NULL)
    {
        k=0;
        j=0;
        i++;
        p=0;
        turn(line1);
        for(q=0;q<strlen(line1);q++)
        {
            if((line1[q]>='a'&&line1[q]<='z')||line1[q]==' ')
            {
                line[p++]=line1[q];
            }
            else
            {
                line[p++]=' ';
            }
        }
        line[p]='\0';
        while(line[k]!='\0')
        {
            while(line[k]!=' '&&line[k]!='\0')
            {
                    a[i][j++]=line[k];
                    k++;
            }
            k++;
            i++;
            j=0;
        }
         memset(line,'\0',strlen(line));
        memset(line1,'\0',strlen(line1));
    }
    qsort(a,i,sizeof(a[0]),cmp);
   for(p=0;p<i;p++)
   {
       for(q=p-1;q>=0;q--)
       {
           if(strcmp(a[p],a[q])==0)
           {
               hash[q]++;
               memset(a[p],'\0',strlen(a[p]));
           }
       }
   }
   for(j=0;j<i;j++)
   {
       if(a[j][0]!='\0')
       {
            for(k=0;k<strlen(a[j]);k++)
            {
                printf("%c",a[j][k]);
            }
            printf(" ");
            printf("%d\n",hash[j]+1);
       }
   }
   fclose(in);
    return 0;
}
void turn(char a[])
{
    int i;
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]>='A'&&a[i]<='Z')
        {
            a[i]=a[i]-'A'+'a';
        }
    }
}//转换为小写
