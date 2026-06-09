#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long 
#define ull unsigned long long
int read()
{
	int x=0,fl=1;char ci=getchar();
	while(ci<'0'||ci>'9'){ if(ci=='-')fl=-1; ci=getchar();}
	while(ci>='0'&&ci<='9') x=x*10+ci-'0',ci=getchar();
	return x*fl;
}
struct skr
{
    char w[1005];
    int num;
}a[1005];
int n;
char ci[1005];
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
    while(fgets(ci,1000,in)!=NULL)
    {
        int l=strlen(ci);
        for(int i=0;i<l;i++)
            if(ci[i]>='A'&&ci[i]<='Z') ci[i]=ci[i]-'A'+'a';
        for(int i=0;i<l;i++)
        {
            if(ci[i]>='a'&&ci[i]<='z')
            {
                int l=i;
                while(l+1<l&&ci[l+1]>='a'&&ci[l+1]<='z')
                {
                    l++;
                }
                strncpy(word,ci+i,l-i+1);
                word[l-i+1]='\0';
                int fl=0;
                for(int i=1;i<=n;i++)
                    if(strcmp(a[i].w,word)==0)
                    {
                        a[i].num++;
                        fl=1;
                        break;
                    }
                if(fl==0)
                {
                    strcpy(a[++n].w,word);
                    a[n].num=1;
                } 
                i=l;
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



