#include <stdio.h>
#include <stdlib.h>

#define N 10000
int main()
{
    char s[N],fuh[N];
    int num[N];
    int i,j,k;
    gets(s);
    for(j=0,i=0;i<strlen(s);i++){            //清除空格
        if(s[i]!=' ')
            s[j++]=s[i];
    }
    s[j]='\0';
    for(i=0,j=0;i<strlen(s);i++){           //记录数字
        if(s[i]>='0'&&s[i]<='9'){
            num[k]=s[i]-'0';
            while(s[i+1]>='0'&&s[i+1]<='9'){
                num[k]=num[k]*10+s[i+1]-'0';
                i++;
            }
            k++;
        }
        num[k]='\0'; // @@ Error: This line incorrectly sets num[k] to '\0' after each number, but k is the count of numbers, so it overwrites the next number's position. Also, '\0' is not a valid integer marker; it should not be used here.
    }
    for(i=0,j=0;i<strlen(s);i++){           //记录符号
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            fuh[j]=s[i];
            j++;
        }
    }
    for(i=0;i<strlen(fuh);i++){                //先乘除
        if(fuh[i]=='*'){
            num[i+1]=num[i]*num[i+1];
            num[i]=' '; // @@ Error: Setting num[i] to ' ' (space) corrupts the integer array; this is not a valid way to mark a number as used. It will cause issues when later clearing spaces.
            i++;
        }
        if(fuh[i]=='/'){
            num[i+1]=num[i]/num[i+1];
            num[i]=' '; // @@ Error: Same issue as above; setting num[i] to space corrupts the integer array.
            i++;
        }
    }
    for(j=0,i=0;i<k;i++){           //清除空格
        if(num[i]!=' ') // @@ Error: Comparing integer num[i] with character ' ' is incorrect; num[i] is an integer, not a character. This condition will never be true for valid integers, so all numbers are removed.
            num[j++]=num[i];
    }
    num[j]='\0'; // @@ Error: Setting num[j] to '\0' is incorrect; num is an integer array, and '\0' is a character constant (0), which may accidentally work but is semantically wrong. Also, j may not be the correct index.
    int an=num[0];
    for(i=0,j=0;i<strlen(fuh);i++){           //后加减
        if(fuh[i]=='+')
            an+=num[++j];
        if(fuh[i]=='-')
            an-=num[++j];
    }
    printf("%d",an);
    return 0;
}