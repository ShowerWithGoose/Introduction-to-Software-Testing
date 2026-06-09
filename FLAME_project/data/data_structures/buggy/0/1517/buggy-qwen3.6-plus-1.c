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
         }
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
             else // @@ The logic fails to handle cases where expansion is NOT performed (e.g., mixed types like B-e). When expansion conditions are not met, the '-' and surrounding characters should be preserved as is, but the current code only appends to strtrue when expansion happens or in the specific non-dash block. The 'else' branch is missing to handle the case where '-' exists but no expansion occurs, leading to missing output or incorrect state. Actually, the primary issue is that if expansion doesn't happen, the code does nothing for the '-', and the subsequent logic for appending remaining chars might skip it or handle it incorrectly depending on 'j'. Specifically, for "B-e", the first block `if(str[i]!='-'&&str[i+1]=='-')` handles 'B'. Then `if(str[i]=='-')` checks expansion. Since 'B' is upper and 'e' is lower, none of the inner if blocks execute. So nothing is added to strtrue for the '-' or the expanded part. Then at `i==line-1`, it appends from `j+1`. `j` was updated to `i+1` (index of 'e') in the first block? No, `j=i+1` happens in the first block. For "B-e": i=0 ('B'), str[1] is '-'. Enters first block. cha = 0 - (-1) = 1. temp[0]='B'. j becomes 0. strcat "B". j becomes 1. i=1 ('-'). First block false. Second block true. Checks types. Mismatch. Does nothing. i=2 ('e'). First block false (str[3] is null). Second block false. Last block `i==line-1` true. cha2 = 2 - 1 = 1. temp[0] = str[1+1] = str[2] = 'e'. j becomes 2. strcat "e". Result "Be". The '-' is lost. The error is that when expansion is skipped, the '-' itself is never added to strtrue.
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