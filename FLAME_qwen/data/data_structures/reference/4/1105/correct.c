#include <stdio.h>
#include <stdlib.h>
typedef struct art
{
char word[100];
int point;
}art;
char r[1024],p[50];
int com(const void *x,const void *y)
{
    return strcmp(((art*)x)->word,((art*)y)->word);
}
int main()
{
    int i,n=0,j,flag,mark,k;
    struct art op[100],x;
    for(i=0;i<100;i++)
        op[i].point=0;
    FILE *in;
    in=fopen("article.txt","r");
    while(fgets(r,1024,in)!=NULL)
    {
        flag=0;
        for(i=0;i<strlen(r);i++)
            if(r[i]>='A'&&r[i]<='Z')r[i]=r[i]-'A'+'a';
        for(i=0,j=0;i<strlen(r);i++)
        {
        if(r[i]>='a'&&r[i]<='z'){p[j]=r[i];j++;flag=1;}
        if(flag==1&&!(r[i]>='a'&&r[i]<='z'))
        {
        mark=0;
        for(k=0;k<100;k++)
        if(strcmp(p,op[k].word)==0&&strlen(op[k].word)==strlen(p))
        {op[k].point++;mark=1;break;}
        if(mark==0)
        {
            strcpy(op[n].word,p);
            op[n].point++;
            n++;
        }
        for(k=0;k<50;k++)
            p[k]=0;
            j=0;
            flag=0;
        }
        }
    }
    fclose(in);
    qsort(op,n,sizeof(art),com);
    for(i=0;i<n;i++)
        printf("%s %d\n",op[i].word,op[i].point);
    return 0;
}



