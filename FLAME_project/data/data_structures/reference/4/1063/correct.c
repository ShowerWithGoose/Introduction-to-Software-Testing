#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void bubble(char[][50],int[],int);
int flag[200];
char line[200],word[200][50];
int main()
{
    int i,j=0,k=0,g;
    FILE *in;
    in=fopen("article.txt","r");
    while(fgets(line,200,in)!=NULL)
    {
        for(i=0;i<strlen(line);i++)
        {
            if((line[i]>='a'&&line[i]<='z')||(line[i]>='A'&&line[i]<='Z'))
            {
                word[j][k]=tolower(line[i]);
                k++;
            }
            else if(word[j][0]!=NULL)
            {
                flag[j]++;
                j++;
                k=0;
            }
        }
    }
    for(i=0;i<j;i++)
    {   
        for(g=0;g<j;g++)
        {
            if(g!=i&&word[i][0]!=word[g][0])
                continue;
            else if(g!=i)
            {
                for(k=0;word[i][k]!='\0';k++)
                {
                    if(word[i][k]!=word[g][k])
                        break;
                }
                if(word[i][k]=='\0'&&word[g][k]=='\0')
                {
                    flag[i]++;
                    word[g][0]=0;
                }
            }
        }
    }
    bubble(word,flag,j);

    for(i=0;i<j;i++)
    {
        if(word[i][0]!='\0')
            printf("%s %d\n",word[i],flag[i]);
    }    
    
    return 0;
}
void bubble(char word[][50],int flag[],int n)
{
    int i,j,k,g,h;
    char hold1[50],hold2;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(word[j][0]>word[j+1][0])//比较第一位顺序
            {
                strcpy(hold1,word[j]);
                memset(word[j],'0',strlen(word[j]));
                strcpy(word[j],word[j+1]);
                memset(word[j+1],'0',strlen(word[j+1]));
                strcpy(word[j+1],hold1);//换顺序
                memset(hold1,'0',strlen(hold1));

                hold2=flag[j];
                flag[j]=flag[j+1];
                flag[j+1]=hold2;
            }
            else if(word[j][0]==word[j+1][0])//如果首字母相同，顺次比较其他字母
            {
                    for(g=1;word[j][g]==word[j+1][g];g++);
                    if((word[j][g]>word[j+1][g]))
                    {
                        strcpy(hold1,word[j]);
                        memset(word[j],'0',strlen(word[j]));
                        strcpy(word[j],word[j+1]);
                        memset(word[j+1],'0',strlen(word[j+1]));
                        strcpy(word[j+1],hold1);//换书顺序
                        memset(hold1,'0',strlen(hold1));

                        hold2=flag[j];
                        flag[j]=flag[j+1];
                        flag[j+1]=hold2;
                    }
            }
        }
    }
}
