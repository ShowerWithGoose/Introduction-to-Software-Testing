#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
char string[1000];
int num;
}abt;
int cp(const void *p1,const void *p2)
{
    const abt *p3=p1,*p4=p2;
    if(strcmp(p3->string,p4->string)>0)
        return 1;
    else
        return -1;
}
int main(){
abt a[1000];
memset(a,0,sizeof(a));
int i=0,j=0,k=0;
char str[1000];
FILE *in=fopen("article.txt","r");
while(fgets(str,999,in)!=NULL)
{
    char cc[1000];
    memset(cc,0,sizeof(cc));
    for(j=0;str[j]!='\0';j++)
    {
    int t,g=0;
    if(str[j]>='A'&&str[j]<='Z')
    {cc[k++]=str[j]-'A'+'a';
    }
    else if(str[j]>='a'&&str[j]<='z')
    {cc[k++]=str[j];
    }
    else if(k>=1)
    {cc[k]='\0';
    g=1;
    }
    else
    cc[k]='\0';
    if(g==1)
    {
    for(t=0;t<i;t++)
    if(strcmp(a[t].string,cc)==0)
    {
        a[t].num++;
        break;
    }
    if(t==i)
    {strcpy(a[i].string,cc);
    a[i].num++;
    i++;
    }
    k=0;
    g=0;
    }

}
}
qsort(a,i,sizeof(a[0]),cp);
for(int j=0;j<i;j++)
if(a[j].num!=0&&a[j].string[0]>='a'&&a[j].string[0]<='z')
printf("%s %d\n\n",a[j].string,a[j].num);
fclose(in);
return 0;
}



