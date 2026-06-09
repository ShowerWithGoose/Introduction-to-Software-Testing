#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define maxline 1024
int main()
{
    char s[maxline],c[110],p[505][110],m[maxline];
    int i,j,max,k;
    int len,len1;
    int num;
    int num1,num2,num3;
    char ch1[50],ch2[20],ch3[30],ch4[11];
    FILE *fp;
    FILE *f;
    if((fp=fopen("article.txt","r"))==NULL)
    {
        printf("cannot found\n");
        return 0;
    }
    j=0;
    while(fgets(s,maxline,fp)!=NULL)
    {
        len=strlen(s);
        i=0;
        while(i<len)
        {
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
            {
                k=0;
                if(s[i]>='A'&&s[i]<='Z')
                {
                    s[i]+='a'-'A';
                }
                while(1)
                {
                    if(s[i]>='a'&&s[i]<='z')
                    {
                        p[j][k]=s[i];
                        i++;
                        k++;
                    }
                    else if(s[i]>='A'&&s[i]<='Z')
                    {
                        p[j][k]=s[i]+'a'-'A';
                        i++;
                        k++;
                    }
                    else
                    {
                        i++;
                        j++;
                        break;
                    }
                }
            }
            else
            {
                i++;
            }
        }
    }
    max=j;
    i=0;
    while(i<max-1)
    {
        j=0;
        while(j<max-1)
        {
            if(p[j][0]>p[j+1][0])
            {
                memset(c,'\0',sizeof(c));
                strcpy(c,p[j]);
                memset(p[j],'\0',sizeof(p[j]));
                strcpy(p[j],p[j+1]);
                memset(p[j+1],'\0',sizeof(p[j+1]));
                strcpy(p[j+1],c);
                j++;
            }
            else if(p[j][0]==p[j+1][0])
            {
                k=1;
                while(1)
                {
                    if(p[j][k]>p[j+1][k])
                    {
                        memset(c,'\0',sizeof(c));
                        strcpy(c,p[j]);
                        memset(p[j],'\0',sizeof(p[j]));
                        strcpy(p[j],p[j+1]);
                        memset(p[j+1],'\0',sizeof(p[j+1]));
                        strcpy(p[j+1],c);
                        j++;
                        break;
                    }
                    else if(p[j][k]==p[j+1][k])
                    {
                        k++;
                    }
                    else
                    {
                        j++;
                        break;
                    }
                }
            }
            else
            {
                j++;
            }
        }
        i++;
    }
    i=0;
    while(i<max)
    {
        printf("%s ",p[i]);
        len=strlen(p[i]);
        j=1;
        while(1)
        {
            k=0;
            if(p[i][k]==p[i+j][k])
            {
                k++;
                while(k<=len)
                {
                    if(p[i][k]==p[i+j][k])
                    {
                        k++;
                    }
                    else break;
                }
                if(k==len+1) j++;
                else break;
            }
            else break;
        }
        printf("%d\n",j);
        i+=j;
    }
    return 0;
}

//scanf记得加&，printf没有&，输出特殊字符要"/"
//memset(a,0,sizeof(a));数组置零（任意数值均可）
//strcpy(a,b);将b拷贝到a(数组或地址拷贝，单个元素不行）

