#include <stdio.h>
#include <string.h>
int main()
{
    int Tnum=0,stm[500]={0};
    char words[500][18];
    int flag=0,flg=0,x=0;
    char str[18]={'\0'},ch;
    FILE *fp=NULL;
    fp=fopen("article.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%c",&ch);
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
        {
            flag=1;
            if(ch>='A'&&ch<='Z')
            {
                ch=ch+'a'-'A';
            }
            str[x]=ch;
            x++;
        }
        else
        {
            if(flag==1)
            {
                for(int i=0;i<Tnum;i++)
                {
                    if(strcmp(words[i],str)==0)
                   {
                        stm[i]++;
                        flg=1;
                    }
                }
                if(flg==0)
                {
                    strcpy(words[Tnum],str);
                    stm[Tnum]=1;
                    Tnum++;
                }
                flg=0;
            }
            for(int i=0;i<=x;i++)
            {
                str[i]='\0';
            }
            flag=0;
            x=0;
        }
    }
    fclose(fp);
 
    int num;
    char word[18];
    for(int i=0;i<Tnum-1;i++)
    {
        for(int j=0;j<Tnum-1;j++)
        {
            if(strcmp(words[j],words[j+1])>0)
            {        
                strcpy(word,words[j]);
                strcpy(words[j],words[j+1]);
                strcpy(words[j+1],word);
                num=stm[j];
                stm[j]=stm[j+1];
                stm[j+1]=num;
            }
        }
    }

    for(int i=0;i<Tnum;i++)
    {
        printf("%s %d",words[i],stm[i]);
        if(i<Tnum-1)
        {
            printf("\n");
        }
    }
    return 0;
}



