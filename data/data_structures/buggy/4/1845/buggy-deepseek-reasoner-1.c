#include<stdio.h>
#include<string.h>
#include<ctype.h> @@ Missing #include<stdlib.h> for qsort function (compilation error in C99)

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
    in=fopen("article.txt","r"); @@ File opened but never used; program reads from stdin instead of the file
    int i=0;
    char y[100];
    while(~scanf("%s",y)) @@ Should read from file using fscanf(in, "%s", y); also condition should check for 1 successful read, not ~scanf
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
                int k=find(a,z,i); @@ i is total number of tokens, not unique word count; should use separate variable
                if(k>-1)
                {
                    a[k].num++;
                }
                else
                {
                    int j;
                    for(j=0; z[j]!='\0'; j++)
                    {
                        a[i].x[j]=z[j]; @@ Uses i as index for new word, but i is the total token count, not the next unique word slot
                    }
                    a[i].x[j]='\0';
                    a[i].num=1;
                }
                i++; @@ i is incremented for every token, even if word already existed; this causes a to contain garbage and unique count is lost
            }
        }
    }
    qsort(a,i,sizeof(a[0]),cmp); @@ Sorting uses i (total tokens) as number of elements, which includes many uninitialized entries
    for(int j=0; j<i; j++)
    {
        if(a[j].x[0]<'a') continue; @@ Unnecessary skip; may filter out some words that erroneously start with non‑lowercase
        printf("%s %d\n",a[j].x,a[j].num);
    }
    fclose(in);
    return 0;
}