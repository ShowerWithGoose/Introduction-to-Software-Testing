#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int mergeline(char linea[],char lineb[],char line[]);
int normalize(char line[]);
int deletechar(char key[],int position);
int getword(char line[],char word[],int position);
int judgeword(char word[],char bank[][30],int banksize);
int addword(char word[],char bank[][30],int times[],int banksize);
int bankbubble(char bank[][30],int times[],int banksize);
int wordcompare(char a[],char b[]);
int max(int a,int b);
int whichisshort(char a[],char b[]);
int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    char bank[505][30];
    int time[505];
    char line[210];
    char line1[105],line2[105];
    char word[105];
    int i,j,k,l,m,n,bs,x;
    bs=1;
    bank[0][0]='*';
    time[0]=0;
    while(fgets(line1,105,in)!=NULL)
    {
        if(fgets(line2,105,in)!=NULL)
        {
            mergeline(line1,line2,line);
        }
        else
        {
            strcpy(line,line1);
        }
        i=0;
        l=strlen(line);
        normalize(line);
        while(getword(line,word,i)!=0)
        {
            bs=addword(word,bank,time,bs);
            i=getword(line,word,i);
        }
        x=bankbubble(bank,time,bs);
    }
    for(i=1;i<bs;i++)
    {
        for(j=0;bank[i][j]!='\0';j++)
        {
            printf("%c",bank[i][j]);
        }
        printf(" %d\n",time[i]);
    }
    return 0;
}

int mergeline(char linea[],char lineb[],char line[])
{
    int la,lb,l,i,j,k;
    la=strlen(linea);
    lb=strlen(lineb);
    l=la+lb;
    for(i=0;i<la;i++)
    {
        line[i]=linea[i];
    }
    for(j=0;lineb[j]!='\0';i++,j++)
    {
        line[i]=lineb[j];
    }
    line[i]='\0';
    return 0;
}

int normalize(char line[])
{
    int i,j,k,l,m,ld;
    char save[105];
    l=strlen(line);
    ld=0;
    for(i=0;i<l;i++)
    {
        if(line[i]>='a'&&line[i]<='z')
        {
            continue;
        }
        else if(line[i]>='A'&&line[i]<='Z')
        {
            line[i]+=32;
        }
        else if(line[i]==' ')
        {
            line[i]='_';
        }
        else if(line[i]!='_'&&line[i]!='\0')
        {
            line[i]='_';
        }
    }
    line[l-ld]='\0';
    if(line[0]=='_')
    {
        deletechar(line,0);
    }
    return 0;
}

int deletechar(char key[],int position)
{
    int i,k,m,n,l;
    l=strlen(key);
    if(position==l-1)
    {
        key[position]='\0';
        return 0;
    }
    else
    {
        l--;
        char save[105];
        for(k=position+1,m=0;key[k]!='\0';k++,m++)
        {
            save[m]=key[k];
        }
        save[m]='\0';
        for(k=position,n=0;save[n]!='\0';k++,n++)
        {
            key[k]=save[n];
        }
        key[k]='\0';
    }
    return 0;
}

int getword(char line[],char word[],int position)
{
    int i,j;
    i=position;
    j=0;
    while(line[i]=='_')
    {
        i++;
    }
    while(line[i]>='a'&&line[i]<='z')
    {
        word[j]=line[i];
        j++;
        i++;
    }
    word[j]='\0';
    if(j==0)
    {
        return 0;
    }
    else
    {
        return i;
    }
}

int judgeword(char word[],char bank[][30],int banksize)
{
    int i,f;
    if(banksize==0)
    {
        return 0;
    }
    else
    {
        for(i=0;i<=banksize;i++)
        {
            if(strcmp(word,bank[i])==0)
            {
                return i;
            }
        }
    }
    return 0;
}

int addword(char word[],char bank[][30],int times[],int banksize)
{
    int i;
    i=judgeword(word,bank,banksize);
    if(i==0)
    {
        strcpy(bank[banksize],word);
        times[banksize]=1;
        banksize++;
        return banksize;
    }
    else
    {
        times[i]++;
        return banksize;
    }
}

int bankbubble(char bank[][30],int times[],int banksize)
{
    int i,j,h;
    char hold[30];
    for(i=1;i<banksize;i++)
    {
        for(j=1;j<banksize-i;j++)
        {
            if(wordcompare(bank[j],bank[j+1])==-1)
            {
                strcpy(hold,bank[j]);
                h=times[j];
                strcpy(bank[j],bank[j+1]);
                times[j]=times[j+1];
                strcpy(bank[j+1],hold);
                times[j+1]=h;
            }
        }
    }
    return 0;
}

int wordcompare(char a[],char b[])
{
    int la,lb,lm,s,i;
    char u;
    for(i=0;i<30;i++)
    {
        u=a[i]-b[i];
        if(u>0)
        {
            return -1;
        }
        else if(u<0)
        {
            return 1;
        }
    }
}

int max(int a,int b)
{
    int m;
    m=a;
    if(b>a)
    {
        m=b;
    }
    return m;
}

int whichisshort(char a[],char b[])
{
    int la,lb;
    la=strlen(a);
    lb=strlen(b);
    if(la<lb)
    {
        return 1;
    }
    else if(la>lb)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}



