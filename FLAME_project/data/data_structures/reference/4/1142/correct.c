#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long 
#define ull unsigned long long
int read()
{
	int x=0,fl=1;char st=getchar();
	while(st<'0'||st>'9'){ if(st=='-')fl=-1; st=getchar();}
	while(st>='0'&&st<='9') x=x*10+st-'0',st=getchar();
	return x*fl;
}
struct skr
{
    char w[1005];
    int num;
}a[1005];
int n;
char st[1005];
char word[1005];
int cmp(const void *a,const void *b)
{
    struct skr c=*(struct skr *)a;
    struct skr d=*(struct skr *)b;
    return strcmp(c.w,d.w);
}
int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    while(fgets(st,1000,in)!=NULL)
    {
        int l=strlen(st);
        for(int i=0;i<l;i++)
            if(st[i]>='A'&&st[i]<='Z') st[i]=st[i]-'A'+'a';
        for(int i=0;i<l;i++)
        {
            if(st[i]>='a'&&st[i]<='z')
            {
                int j=i;
                while(j+1<l&&st[j+1]>='a'&&st[j+1]<='z')
                {
                    j++;
                }
                strncpy(word,st+i,j-i+1);
                word[j-i+1]='\0';
                int fl=0;
                for(int k=1;k<=n;k++)
                    if(strcmp(a[k].w,word)==0)
                    {
                        a[k].num++;
                        fl=1;
                        break;
                    }
                if(fl==0)
                {
                    strcpy(a[++n].w,word);
                    a[n].num=1;
                } 
                i=j;
            }
        }
    }
    qsort(a+1,n,sizeof(a[0]),cmp);
    for(int i=1;i<=n;i++)
    {
        printf("%s %d\n",a[i].w,a[i].num);
    }
    fclose(in);
	return 0;
}



