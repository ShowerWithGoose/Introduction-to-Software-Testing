#include<stdio.h>
#include<string.h>
char strtrue[100000];
int main()
{
    char str[100000]={"0"};
    gets(str); // @@ gets is deprecated and removed in C11, causing compilation errors in modern compilers; use fgets instead.
    int j=-1;//str中'-'的位置 
    int line;
    char temp[100000]={"0"};
    line=strlen(str); 
    for(int i=0;i<line;i++)
    {
        
        if(str[i]!='-'&&str[i+1]=='-')//把不用变动的加到后面  // @@ Accesses str[i+1] which may be logically out of bounds when i == line-1; logic also fails to correctly handle string segments.
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
         if(str[i]=='-')//把缺少的补上  // @@ Missing bounds check for i>0 and i<line-1, causing out-of-bounds access when '-' is at the start or end of the string.
         {
             if(str[i-1]<='z'&&str[i-1]>='a') // @@ Only handles valid expansion cases; fails to output the unchanged string when types mismatch or right <= left, violating problem requirements.
             {
                 if(str[i+1]<='z'&&str[i+1]>='a')
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
            {
                 if(str[i+1]<='Z'&&str[i+1]>='A')
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
            {
                 if(str[i+1]<='9'&&str[i+1]>='0')
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
         
        if(i==line-1)  // @@ Logic for copying remaining characters is flawed because j is not correctly updated when expansion is skipped, leading to missing or duplicated output.
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