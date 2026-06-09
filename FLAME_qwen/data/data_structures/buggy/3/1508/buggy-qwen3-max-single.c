#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//小数点前面是不是零――不是――找小数点后0的个数n――e(-n) 
//                    ――是 ―― 找小数点前数字位数n――e(n-1) 
int main()
{
    char s[105];
    int bit,i,j,k;
    fgets(s,sizeof(s),stdin);
    int length=strlen(s);
//小数点前面是0 
    if(s[0]=='0'&&s[1]=='.')
    {
        for(i=2;i<length;i++)
        {
            if(s[i]!='0')
            {
                bit=i-1;
                // 底数是整数 
                if(atoi(s+i+1)==0)
                {
                    printf("%de-%d\n",s[i]-'0',bit);
                }
                //底数是小数 
                else
                {
                    printf("%d.%se-%d\n",s[i]-'0',s+i+1,bit); @@ [Using %s in printf with a pointer into the middle of a string that may contain a newline or null terminator issues; also, s+i+1 may include the newline character from fgets, leading to incorrect output. Additionally, if the remaining part after s[i] has trailing zeros (which shouldn't happen per problem statement), this might still print them, violating "no trailing zeros" rule.]
                }
                break;
            }
        }
    }
//小数点前面不是0 
    else
    {
        for(i=0;i<length;i++)
        {
            if(s[i]=='.')
            {
                bit=i-1;
                for(k=j=0;s[k]!='\0';k++)
                    {
                        if(s[k]!='.')
                        {
                            s[j]=s[k];j++;
                        }
                    }
                s[k]='\0'; @@ [This line writes beyond the modified string length; after removing '.', the new string ends at index j, but s[k]='\0' uses original k (which is length including newline), potentially leaving garbage or not properly terminating the new string. Should be s[j]='\0';]
                printf("%d.",s[0]-'0');
                for(i=1;i<length;i++)
                {
                    if(s[i]!='\n')
                    printf("%c",s[i]); @@ [Here, 'i' is reused from outer loop and now iterates over original 'length', but s has been modified in-place and its meaningful length is now j. Also, after removing '.', the digits after first are at s[1] to s[j-1], but this loop prints up to original length, possibly printing old data or newline. Moreover, the loop condition should use j instead of length.]
                }
                printf("e%d",bit);
            }    
        }     
    }
    return 0;
}