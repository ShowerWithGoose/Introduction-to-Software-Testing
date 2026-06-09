#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    char w[50];
    int n;
}Node;
Node list[10000],tem;
char read[100];
char into[100];
FILE *in;
int i,j,k,l,f,q;

signed main()
{
    in=fopen("article.txt","r");
    while((fscanf(in,"%s",read))!=EOF)
    {
        l=strlen(read);
        j=0;
        for(i=0;i<l;i++)
        {
            if(read[i]>='a'&&read[i]<='z')
            {
                into[j]=read[i];
                j++;
            }
            else if(read[i]>='A'&&read[i]<='Z')
            {
                into[j]=read[i]-'A'+'a';
                j++;
            }
            else
            {
                if(j==0)
                continue;
                into[j]='\0';
                f=0;
                for(q=0;q<k;q++)
                {
                    if(strcmp(list[q].w,into)==0)
                    {
                    list[q].n++;
                    f=1;
                    break;
                    }
                }
                if(f==0)
                {
                    j=strlen(into);
                    for(f=0;f<j;f++)
                    list[q].w[f]=into[f];
                    list[q].n=1;
                    k++;
                }
                ///printf("%s ",into);
                j=0;
            }
        }
        if(j==0)
        continue;
        into[j]='\0';
        f=0;
        for(i=0;i<k;i++)
        {
            if(strcmp(list[i].w,into)==0)
            {
            list[i].n++;
            f=1;
            break;
            }
        }
        if(f==0)
        {
            j=strlen(into);
            for(f=0;f<j;f++)
            list[i].w[f]=into[f];
            list[i].n=1;
            k++;
        }
        ///printf("%s:%d\n",read,list[i].n);
    }
    /*
    for(i=0;i<k;i++)
    printf("%d:%s %d\n\n",i,list[i].w,list[i].n);
    */
    for(i=0;i<k;i++)
    {
        for(j=0;j<k-1;j++)
        {
            ///printf("%d/%d,%d:%s %s\n\n",strcmp(list[j].w,list[j+1].w),i,j,list[j].w,list[j+1].w);
            if(strcmp(list[j].w,list[j+1].w)>0)
            {
                
                tem=list[j];
                list[j]=list[j+1];
                list[j+1]=tem;
            }
           
        }
    }
    for(i=0;i<k;i++)
    {
       printf("%s %d\n",list[i].w,list[i].n);
    }
    fclose(in);
    
}
