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
                 if(str[i+1]<='z'&&str[i+1]>='a') // @@ The code fails to check if str[i+1] > str[i-1]. For input "B-e", this block is skipped correctly because 'B' is not lowercase, but the logic for handling the hyphen when expansion is NOT performed is missing. When expansion conditions are not met, the hyphen and surrounding characters should be output as is. The current logic only appends expanded characters to strtrue if expansion happens. It does not handle the case where expansion is invalid (like B-e), leaving the hyphen and the second character unprocessed or handled incorrectly by the subsequent logic. Specifically, if expansion doesn't happen, the code falls through without adding the '-' or the next char to strtrue in this block. The logic relies on the first `if` to capture chars before '-', but if expansion fails, the '-' itself and the char after it need to be preserved. The current structure is flawed because it doesn't explicitly output the '-' when expansion is skipped.
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
                 if(str[i+1]<='Z'&&str[i+1]>='A') // @@ Same issue: missing check for str[i+1] > str[i-1]. More importantly, if this condition is false (as in B-e, where 'e' is not uppercase), the code does nothing. It doesn't add the '-' to the output. The character 'B' was added by the first `if` block (when i was at index 0, str[0]='B', str[1]='-'). But the '-' at index 1 is processed here. Since 'e' is not uppercase, this block does nothing. The 'e' is processed later.
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