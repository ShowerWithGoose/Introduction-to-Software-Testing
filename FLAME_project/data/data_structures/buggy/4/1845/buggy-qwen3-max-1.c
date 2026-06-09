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
    while(~scanf("%s",y)) // @@ [The program reads from stdin using scanf instead of reading from the file "article.txt". This causes it to ignore the input file entirely.]
    {
        int o=strlen(y);
        b.nu=0;
        b.s[0]=0;
        for(int p=0; p<o; p++)
        {
            y[p]=tolower(y[p]);
            if(y[p]>='a'&&y[p]<='z');
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
                    i++; // @@ [The increment of 'i' should happen only when a new word is added, but it's currently outside the else block, causing 'i' to be incremented even when the word already exists. However, looking closely: actually, 'i++' is missing inside the else block and is placed after the entire if-else, which causes every token (even duplicates) to increase 'i', leading to uninitialized entries and wrong counts. But wait — in the current code, 'i++' is AFTER the entire if/else, so even when word exists (k>-1), i is still incremented. That’s a critical bug.]
                }
                // @@ [Missing 'i++' inside the else block and extra 'i++' outside causes array index corruption. The 'i++' should only occur in the else branch.]
            }
        }
    }
    qsort(a,i,sizeof(a[0]),cmp);
    for(int j=0; j<i; j++)
    {
        if(a[j].x[0]<'a') continue; // @@ [This condition may skip valid words that start with non-letter due to leftover garbage, but more critically, because 'i' was over-incremented, many entries in 'a' are uninitialized or zero-length, and this check is unreliable. Also, words are already filtered to contain only letters, so this check shouldn't be needed if logic were correct.]
        printf("%s %d\n",a[j].x,a[j].num);
    }
    fclose(in);
    return 0;
}