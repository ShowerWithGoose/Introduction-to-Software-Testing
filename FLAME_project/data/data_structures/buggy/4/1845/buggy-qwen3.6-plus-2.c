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
    while(~scanf("%s",y)) // @@ The program should read from the file "article.txt" using fscanf or fgets, not from standard input using scanf. Also, scanf with %s stops at whitespace, so it won't capture punctuation attached to words correctly for processing in the inner loop as intended by the logic which tries to split non-alpha chars. However, the primary issue is reading from stdin instead of the file pointer 'in'.
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
                }
                i++; // @@ This line increments the total word count 'i' even if the word was already found (k > -1). It should only increment when a new word is added (inside the else block). Currently, it corrupts the count of unique words and leaves uninitialized entries in the array for duplicate words.
            }
        }
    }
    qsort(a,i,sizeof(a[0]),cmp);
    for(int j=0; j<i; j++)
    {
        if(a[j].x[0]<'a') continue;
        printf("%s %d\n",a[j].x,a[j].num);
    }
    fclose(in);
    return 0;
}