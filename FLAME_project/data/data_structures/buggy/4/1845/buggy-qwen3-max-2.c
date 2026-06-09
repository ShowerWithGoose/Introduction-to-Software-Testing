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
    while(~scanf("%s",y)) // @@ [The program reads from stdin using scanf instead of reading from the file "article.txt" via fscanf or fgets. This causes it to ignore the input file entirely.]
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
                i++; // @@ [The index 'i' is incremented even when a new word is added, but also when an existing word is found? Actually, no: 'i' is only incremented in the 'else' block, but note that 'i' is incremented AFTER assigning to a[i], which is correct. However, the real issue is that 'i' is incremented inside the loop over split parts, but the 'find' function uses current 'i' as the count of valid entries. But the bigger problem is the use of scanf instead of file reading.]
            }
        }
    }
    qsort(a,i,sizeof(a[0]),cmp);
    for(int j=0; j<i; j++)
    {
        if(a[j].x[0]<'a') continue; // @@ [This condition may skip valid words that start with non-letter after processing, but more critically, due to incorrect tokenization and file reading, many words might not be processed correctly. Also, since the input reading is wrong, this loop may output nothing or garbage.]
        printf("%s %d\n",a[j].x,a[j].num);
    }
    fclose(in);
    return 0;
}