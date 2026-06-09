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
         } // @@ [This block incorrectly assumes that a '-' always follows a non-'-' character and tries to copy characters before '-', but fails to handle cases where '-' appears at the start or when multiple '-' are present. Also, it doesn't account for invalid expansions like 'B-e'.]
         if(str[i]=='-')//把缺少的补上 
         {
             if(str[i-1]<='z'&&str[i-1]>='a')
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
         } // @@ [This block expands only when both sides are same type and in increasing order, which is correct per requirements. However, it does not output the original '-' when expansion conditions are not met (e.g., 'B-e'), leading to omission of the '-' in output.]
         
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
        } // @@ [This final copy block assumes all remaining characters after last processed position should be appended, but due to flawed logic in tracking 'j', it may skip or mis-copy characters, especially when no valid '-' expansion occurs. In case like 'B-e', the '-' is never added to output because it's neither expanded nor copied in any block.]
         
    }
    puts(strtrue);
    return 0;
}