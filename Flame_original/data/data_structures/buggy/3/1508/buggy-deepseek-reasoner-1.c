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
                    printf("%d.%se-%d\n",s[i]-'0',s+i+1,bit); // @@ This line prints the substring including the trailing newline from fgets, causing a line break inside the scientific notation output.
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
                s[k]='\0';
                printf("%d.",s[0]-'0');
                for(i=1;i<length;i++)
                {
                    if(s[i]!='\n')
                    printf("%c",s[i]);
                }
                printf("e%d",bit);
            }    
        }     
    }
    return 0;
}