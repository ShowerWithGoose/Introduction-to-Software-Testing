#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int TIME[2500];
int Hash(char *x)
{
    int l=strlen(x);
    unsigned long long ans=0;
    for(int i=0;i<=l;i++)
    {
       ans=ans*167+(int)x[i];
    }
    return ans%2129;
}
struct words
{
    char word[100];
}w[1000];
int cmp(const void*e,const void*f)
{
	struct words ee = *(struct words *)e;
    struct words ff = *(struct words *)f;
	int pan;
	pan=strcmp(ee.word,ff.word);
	if(pan<0)
	return -1;
	else return 1;
}
int main()
{
    FILE *in;
    in=fopen("article.txt", "r");
    int number=0;
    char s[100],word0[100];
    while(fgets(s,100,in)!=NULL)
    {
        int l=strlen(s);
        for(int i=0;i<l;i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            s[i]+='a'-'A';
        }
        for(int i=0;i<l;i++)
        {
            if(islower(s[i]))
            {
                int k=i;
                for(;islower(s[k]);k++)
                {
                   word0[k-i]=s[k];
                }
                word0[k-i]='\0';
                if(!TIME[Hash(word0)])
                {
                number++;
                strcpy(w[number].word,word0);   
                }
                TIME[Hash(word0)]++;
                i=k;
            }
        }
    }
    qsort(w+1,number,sizeof(w[1]),cmp);
    for(int i=1;i<=number;i++)
    {
        printf("%s %d\n",w[i].word,TIME[Hash(w[i].word)]);
    }
    fclose(in);
    return 0;
}
