#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char s[1000][20];
int cnt1=0,cnt2;
struct dic
{
    char word[20];
    int times;
};
char c;
int flag=0;
struct dic x[10000];
int cmp(const void*a,const void*b)
{
	struct dic *aa=(struct dic*)a;
	struct dic *bb=(struct dic*)b;
	if(strcmp(aa->word,bb->word)!=0)
	    return strcmp(aa->word,bb->word);
};
int main()
{
    FILE *in;
    memset(&x,0,sizeof(struct dic));//对吗？
    in=fopen("article.txt","r");
    while((c=fgetc(in))!=EOF)
    {
        c=tolower(c);
        if(c>=97&&c<=122)
        {   while(c>=97&&c<=122)
            {
                s[cnt1][cnt2]=c;
                c=fgetc(in);
                c=tolower(c);
                cnt2++;
            }
            s[cnt1][cnt2]='\0';
            for (int i=0;i<cnt1;i++)
            {
                if(strcmp(x[i].word,s[cnt1])==0)
                {
                    x[i].times++;
                    flag=1;
                }
            }
            if (flag==0)
            {
                strcpy(x[cnt1].word,s[cnt1]);
                x[cnt1].times++;
                cnt1++;
            }
            flag=0;
            cnt2=0;
         }

    }
    qsort(x,cnt1,sizeof(x[0]),cmp);
    for (int i=0;i<cnt1;i++)
        printf("%s %d\n",x[i].word,x[i].times);
    fclose(in);
    return 0;
}
