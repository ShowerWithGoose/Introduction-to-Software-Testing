#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define N 1005
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
typedef long long ll;
int read();
typedef struct{

char words[10000];
int cnt;

} word;
word w[10000];
typedef struct{
char s[10000];
} sentence;
sentence a[10000];
int isok(char a)
{
    if(a>='a'&&a<='z')
    return 1;
    else if(a>='A'&&a<'Z')
    return 1;
    else 
    return 0;
}
int isbig(char a)
{
    if(a>='A'&&a<='Z')
    return 1;
    else 
    return 0;
}
int main()
{

FILE *dp;
dp=fopen("article.txt","r");
int i=0;
int j;
while(fgets(a[i].s,1000,dp)!=NULL)
{
 for(j=0;j<strlen(a[i].s);j++)
 {
     if(isok(a[i].s[j])==0)
     a[i].s[j]=' ';
 }
 i++;
}
int len=i;
int k;
int cntt=0;
int count=0;
for(j=0;j<len;j++)
{

for(i=0;i<strlen(a[j].s);i++)
{
if(isok(a[j].s[i])==1)
{
 count=0;   
 for(k=i;isok(a[j].s[k])==1;k++)
 {
     w[cntt].words[count]=a[j].s[k];
     count++;
 }
 w[cntt].words[count]='\0';
 i=k;
 cntt++;
}
}
}
for(i=0;i<cntt;i++)
{
for(j=0;j<strlen(w[i].words);j++)
{
if(isbig(w[i].words[j])==1)
w[i].words[j]=w[i].words[j]+'a'-'A';
}    
w[i].cnt=1;
}
for(i=0;i<cntt;i++)
{
for(j=0;j<cntt;j++)
{
if(strcmp(w[i].words,w[j].words)==0&&i!=j)
{
 w[i].cnt++;
 w[j].words[0]='\0';
 w[j].cnt=0;
}
}

}
word swi;
for(i=0;i<cntt;i++)
{
for(j=0;j<cntt-i;j++)
{
if(strcmp(w[j].words,w[j+1].words)<0)
{
swi=w[j];
w[j]=w[j+1];
w[j+1]=swi;
}

}
}
for(i=cntt-1;i>=0;i--)
{   if(w[i].words[0]!='\0')
    printf("%s %d\n",w[i].words,w[i].cnt);
}

return 0;
}
int read(){
int x=0,f=1,c=getchar();
while(c<'0'||c>'9')(c=='-')?(f=-1):0,c=getchar();
while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
return x*f;
}
