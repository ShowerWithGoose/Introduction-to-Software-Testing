#include<stdio.h>
int r()
{
    int x_=0,y_=1;
    char z_=getchar();
    while(z_<'0'||z_>'9')
    {
        if(z_=='-')
        {
            y_=-1;
        }
        z_=getchar();
    }
    while(z_>='0'&&z_<='9')
    {
        x_=x_*10+z_-'0';
        z_=getchar();
    }
    return x_*y_;
}
void wrt(int _x)
{
    if(_x==0)
    {
        putchar('0');
        putchar(' ');
        return;
    }
    char _X[600];
    int tp=0;
    if(_x>0&&0<_x)
    {
        tp=_x;
    }
    else
    {
        tp=-_x;
    }
    if(_x<0&&0>_x)
    {
        putchar('-');
    }
    int tot=0;
    for(;tp!=0;)
    {
        _X[tot]=tp%10+'0';
        tp/=10;
        tot++;
    }
    for(;tot!=0;)
    {
        tot--;
        putchar(_X[tot]);
    }
    putchar(' ');
}
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct X
{
    char w[60];
    int t;
};
struct X x[600];
char s[6000],t[60];
int tot,top;
int opr(const void *u,const void *v)
{
    return strcmp((*(struct X*)u).w,(*(struct X*)v).w);
}
int ss()
{
    if(s[top]=='\0')
    {
        return 0;
    }
    for(;!isalpha(s[top]);)
    {
        top++;
    }
    for(int q=0;isalpha(s[top]);top++,q++)
    {
        t[q]=s[top];
    }
    t[q] = '\0'; // @@ [The string t is not null-terminated after copying characters, leading to undefined behavior when using strlen or strcmp later.]
    return 1;
}
int main()
{
    FILE *r;
    r=fopen("article.txt","r");
   // (gets(s))!=0
    for(int o=0;(fgets(s,6000,r))!=0;o++)
    {
        unsigned long st=strlen(s);
        s[st]='\0';
        for(int q=0;q!=st;q++)
        {
            s[q]=tolower(s[q]);
        }
        
        for(int o=0;(ss())!=0;o++)
        {
            if(strlen(t)==0)
            {
                continue;
            }
            int z=0;
            for(int q=0;q!=tot;q++)
            {
                if(strcmp(x[q].w,t)==0)
                {
                    z=1;
                    x[q].t++;
                    break;
                }
            }
            if(z==0)
            {
                strcpy(x[tot].w, t);
                x[tot].t++; // @@ [The count for a new word should be initialized to 1, not incremented from an uninitialized/garbage value. It should be x[tot].t = 1;]
                tot++;
            }
            for(int q=0;q!=60;q++)
            {
                t[q]=0;
            }
        }
        top=0;
        for(int q=0;q!=6000;q++)
        {
            s[q]=0;
        }
    }
    qsort(x, tot, sizeof(x[0]), opr);
    for(int q=0;q!=tot;q++)
    {
        if(x[q].w[0]=='P') // @@ [This condition arbitrarily skips words starting with 'p', which is incorrect. The problem requires outputting all words. This likely stems from debugging residue or a misunderstanding.]
        {
            continue;
        }
        printf("%s %d",x[q].w,x[q].t);
        putchar(10);
    }
    fclose(r);
}