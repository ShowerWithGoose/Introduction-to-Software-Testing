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
            num[k]=s[i]-'0'; // @@ [k is uninitialized, leading to undefined behavior; should initialize k=0 before this loop]
            while(s[i+1]>='0'&&s[i+1]<='9'){
                num[k]=num[k]*10+s[i+1]-'0';
                i++;
            }
            k++;
        }
        num[k]='\0'; // @@ [This line writes a null terminator into an integer array, which is meaningless and corrupts data; also k may be out of bounds]
    }
    for(i=0,j=0;i<strlen(s);i++){           //记录符号
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            fuh[j]=s[i];
            j++;
        }
    }
    for(i=0;i<strlen(fuh);i++){                //先乘除
        if(fuh[i]=='*'){
            num[i+1]=num[i]*num[i+1]; // @@ [Does not handle operator precedence correctly across multiple * and /; processes left-to-right but overwrites num[i] without adjusting later indices]
            num[i]=' '; // @@ [Storing space character in integer array is invalid; should mark for deletion differently or use a different algorithm]
            i++;
        }
        if(fuh[i]=='/'){ // @@ [After i++ in '*' case, this may skip checking '/' at the same position; also same issues as '*' above]
            num[i+1]=num[i]/num[i+1];
            num[i]=' ';
            i++;
        }
    }
    for(j=0,i=0;i<k;i++){           //清除空格
        if(num[i]!=' ') // @@ [Comparing integer array elements to space character ' ' is incorrect; the earlier assignment num[i]=' ' stored ASCII 32, but this logic is fragile and wrong]
            num[j++]=num[i];
    }
    num[j]='\0'; // @@ [Again, storing '\0' (0) in integer array corrupts numeric data]
    int an=num[0];
    for(i=0,j=0;i<strlen(fuh);i++){           //后加减
        if(fuh[i]=='+')
            an+=num[++j]; // @@ [Indexing into num with ++j assumes num has been compacted correctly, but due to earlier errors, num may have wrong values or length]
        if(fuh[i]=='-')
            an-=num[++j]; // @@ [Same indexing issue as above; also doesn't account for reduced number of operands after * and / processing]
    }
    printf("%d",an);
    return 0;
}