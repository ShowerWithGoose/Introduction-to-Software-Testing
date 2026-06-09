#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct word
{
    char x[100];
    int num;
};
struct word a[100005];
struct flag
{
    int s[100];
    int nu;
};
struct flag b;

int find(struct word a[],char y[],int n)
{
    for(int i=0; i<n; i++)
    {
        if(strcmp(a[i].x,y)==0)
        {
            return i;
        }
    }
    return -1;
}

int cmp(const void *p1,const void *p2)
{
    struct word *a=(struct word *)p1;
    struct word *b=(struct word *)p2;
    return strcmp(a->x,b->x);
}

int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    int i=0;
    char y[100];
    while(~scanf("%s",y)) // @@ [The program reads from stdin using scanf instead of reading from the file "article.txt". This causes incorrect input handling and likely infinite loop or wrong data.]
    {
        int o=strlen(y);
        b.nu=0;
        b.s[0]=0;
        for(int p=0; p<o; p++)
        {
            y[p]=tolower(y[p]);
            if(y[p]>='a'&&y[p]<='z'); // @@ [This semicolon creates an empty statement, making the following else clause unconditional and logically incorrect. It should be removed to properly handle non-alphabetic characters.]
            else
            {
                b.nu++;
                b.s[b.nu]=p;
            }
        }
        b.s[b.nu+1]=o;
        for(int l=0; l<=b.nu; l++)
        {
            char z[100]={};
            int e=0;
            for(int h=b.s[l]; h<b.s[l+1]; h++)
            {
                if(y[h]>='a'&&y[h]<='z')
                {
                z[e]=y[h];
                e++;
                }
                else
                    continue;
            }
            z[e]='\0';
            if(z[0]>='a'&&z[0]<='z')
            {
                int k=find(a,z,i);
                if(k>-1)
                {
                    a[k].num++;
                }
                else
                {
                    int j;
                    for(j=0; z[j]!='\0'; j++)
                    {
                        a[i].x[j]=z[j];
                    }
                    a[i].x[j]='\0';
                    a[i].num=1;
                }
                i++; // @@ [Incrementing 'i' happens even when the word already exists (in the 'if(k>-1)' branch), causing duplicate entries and skipping uninitialized array slots. It should only increment when adding a new word.]
            }
        }
    }
    qsort(a,i,sizeof(a[0]),cmp);
    for(int j=0; j<i; j++)
    {
        if(a[j].x[0]<'a') continue; // @@ [This check is redundant and potentially harmful; words are already filtered to contain only lowercase letters, but uninitialized entries might have garbage. The real issue is that 'i' may count duplicates due to misplaced increment.]
    }
    fclose(in);
    return 0;
}