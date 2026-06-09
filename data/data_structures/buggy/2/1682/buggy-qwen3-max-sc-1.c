#include <stdio.h>
#include <stdlib.h>

#define N 10000
int main()
{
    char s[N],fuh[N];
    int num[N];
    int i,j,k;
    gets(s); // @@ [Using `gets` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, `gets` is removed entirely, leading to a compilation error. Use `fgets` instead.]
    for(j=0,i=0;i<strlen(s);i++){            //清除空格
        if(s[i]!=' ')
            s[j++]=s[i];
    }
    s[j]='\0';
    for(i=0,j=0;i<strlen(s);i++){           //记录数字
        if(s[i]>='0'&&s[i]<='9'){
            num[k]=s[i]-'0'; // @@ [Variable `k` is used uninitialized. This leads to undefined behavior—writing to a random index in `num`. Should initialize `k = 0` before this loop.]
            while(s[i+1]>='0'&&s[i+1]<='9'){
                num[k]=num[k]*10+s[i+1]-'0';
                i++;
            }
            k++;
        }
        num[k]='\0'; // @@ [This line is misplaced—it overwrites the next number slot with a null terminator (which is zero), corrupting data. Also, `num` is an int array; using `'\0'` (zero) here deletes a valid number. Should be removed.]
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
            num[i]=' '; // @@ [Storing `' '` (space character, ASCII 32) in an integer array as a marker is incorrect. Later, when checking `num[i] != ' '`, it compares against 32, but actual numbers could coincidentally be 32. Should use a separate flag or shift array properly instead of marking with space.]
            i++;
        }
        if(fuh[i]=='/'){
            num[i+1]=num[i]/num[i+1];
            num[i]=' '; // @@ [Same issue as above: using `' '` as a placeholder in integer array is logically flawed and error-prone.]
            i++;
        }
    }
    for(j=0,i=0;i<k;i++){           //清除空格
        if(num[i]!=' ')
            num[j++]=num[i];
    }
    num[j]='\0'; // @@ [Again, `num` is an integer array; setting `num[j] = '\0'` (i.e., 0) truncates the number list incorrectly if any number was zero. Also unnecessary since we track count with `j`.]
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