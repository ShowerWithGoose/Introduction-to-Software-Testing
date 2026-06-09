#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
/*struct word{
char w[30];
int freqency;
}in[10000];*/
int high(char *p1,char *p2)
{
    return strcmp(p1,p2);
}
char in[5000][20],a[100][100];
int main()
{
    char ch;
    int i,j,frequency,k,u;
    FILE *fp;
    fp=fopen("article.txt","r");
    for(j=0;fgets(a[j],100,fp)!=NULL;j++)
    {
        for(u=0;a[j][u]!='\0';u++)
        {
            ch=a[j][u];
            if(isalpha(ch)==0&&ch!='\n'&&ch!='\0') a[j][u]=' ';
            if(isupper(ch)) a[j][u]+=32;
        }
    }
    fclose(fp);
    fp=fopen("out.txt","w");
    for(i=0;i<j;i++) fputs(a[i],fp);
    fp=fclose(fp);
    /*while(ch=fgetc(fp)!=EOF)
    {
        if(isalpha(ch)==0&&ch!='\n'&&ch!='\0') ch='\n';
        if(isupper(ch)) ch+=32;
    }*/
    fp=fopen("out.txt","r");
    for(i=0;fscanf(fp,"%s",in[i])!=EOF;i++);
    qsort(in,i,sizeof(char[20]),high);
    for(j=0;j<i;j++)
    {
        frequency=1;
        if(j<i-1) for(;strcmp(in[j],in[j+1])==0;j++) frequency++;
        printf("%s %d\n",in[j],frequency);
    }

    return 0;
}











