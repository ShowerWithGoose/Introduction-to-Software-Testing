#include<stdio.h>
#include<string.h>
char strtrue[100000];
int main()
{
    char str[100000]={"0"};
    gets(str);
    int j=-1;//str中'-'的位置 
    int line;
    char temp[100000]={"0"};
    line=strlen(str); 
    for(int i=0;i<line;i++)
    {
        
        if(str[i]!='-'&&str[i+1]=='-')//把不用变动的加到后面 
@@ // [Error: out-of-bounds access when i = line-1, str[i+1] is beyond string terminator; also fails to handle dash at start/end correctly]
        {
            int cha=i-j; 
            for(int x=0;x<cha;x++)
            {
                temp[x]=str[j+1];
                j++;
            }
            strcat(strtrue,temp);
            memset(temp,0,sizeof(temp));
            j=i+1;
         }
         if(str[i]=='-')//把缺少的补上 
@@ // [Error: dash not preserved when no expansion occurs; should copy dash itself if no valid range is expanded]
         {
             if(str[i-1]<='z'&&str[i-1]>='a')
@@ // [Error: out-of-bounds access when i = 0, str[i-1] is before array start]
             {
                 if(str[i+1]<='z'&&str[i+1]>='a')
@@ // [Error: out-of-bounds access when i = line-1, str[i+1] is past string end]
                 {
                     int x=str[i+1]-str[i-1]-1;
                     if(x>0)
                     {
                         for(int k=0;k<x;k++)
                     {
                         temp[k]=str[i-1]+1+k;
                     }
                     strcat(strtrue,temp);
                     memset(temp,0,sizeof(temp));
                     }
                 }
            }
            if(str[i-1]<='Z'&&str[i-1]>='A')
@@ // [Error: out-of-bounds access when i = 0]
            {
                 if(str[i+1]<='Z'&&str[i+1]>='A')
@@ // [Error: out-of-bounds access when i = line-1]
                 {
                     int x=str[i+1]-str[i-1]-1;
                     if(x>0)
                     {
                         for(int k=0;k<x;k++)
                     {
                         temp[k]=str[i-1]+1+k;
                     }
                     strcat(strtrue,temp);
                     memset(temp,0,sizeof(temp));
                     }
                 }
            }
            if(str[i-1]<='9'&&str[i-1]>='0')
@@ // [Error: out-of-bounds access when i = 0]
            {
                 if(str[i+1]<='9'&&str[i+1]>='0')
@@ // [Error: out-of-bounds access when i = line-1]
                 {
                     int x=str[i+1]-str[i-1]-1;
                     if(x>0)
                     {
                         for(int k=0;k<x;k++)
                     {
                         temp[k]=str[i-1]+1+k;
                     }
                     strcat(strtrue,temp);
                     memset(temp,0,sizeof(temp));
                     }
                 } 
             }
         }
         
        if(i==line-1) 
        {
            int cha2=i-j; 
            for(int x=0;x<cha2;x++)
            {
                temp[x]=str[j+1];
                j++;
            }
            strcat(strtrue,temp);
            memset(temp,0,sizeof(temp));
        }    
         
    }
    puts(strtrue);
    return 0;
}