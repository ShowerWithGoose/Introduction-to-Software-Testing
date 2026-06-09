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
            if(y[p]>='a'&&y[p]<='z'); // @@ [This semicolon creates an empty statement, making the following else clause unconditional and logically incorrect. It should be removed to associate the else with the if.]
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
                i++; // @@ [Incrementing 'i' only when a new word is added is correct, but here it's inside the 'if(z[0]...)' block which is okay. However, combined with earlier logic errors, this may cause miscounting. The primary issue remains the use of scanf instead of file reading.]
            }
        }
    }
    qsort(a,i,sizeof(a[0]),cmp);
    for(int j=0; j<i; j++)
    {
        if(a[j].x[0]<'a') continue; // @@ [This check is redundant and potentially harmful because all words should already consist of lowercase letters. However, due to earlier flawed parsing (especially the semicolon bug), some entries might be empty or invalid, leading to undefined behavior or missing output.]
        printf("%s %d\n",a[j].x,a[j].num);
    }
    fclose(in);
    return 0;
}