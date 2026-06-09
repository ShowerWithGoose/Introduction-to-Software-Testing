#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char const *argv[])
{
    char str[1000],aim[1000];
    gets(str);
    int j=0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i]!='-'||i==0||str[i+1]=='\0')
        {
            aim[j]=str[i];
            j++;
        }
        else{
            if (str[i-1]<str[i+1])
            {
                if (str[i-1]==str[i+1]-1)
                {
                    continue;
                }
                
                else if((str[i-1]>=48&&str[i+1]<=57)||(str[i-1]>=65&&str[i+1]<=90)||(str[i-1]>=97&&str[i+1]<=122)){
                    for (int k=1;  str[i-1]+k<str[i+1]; k++)
                    {
                        aim[j]=str[i-1]+k;
                        j++;
                    }
                }
                else{
                    aim[j]=str[i];
                    j++;
                }
                
            }
            else{
                aim[j]=str[i];
                j++;
            }
            
        }
        aim[j]='\0';
        
    }
    puts(aim);
    

    getchar();
    return 0;
}


