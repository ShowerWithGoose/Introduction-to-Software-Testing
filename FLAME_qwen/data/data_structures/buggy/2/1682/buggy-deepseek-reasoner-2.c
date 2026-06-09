#include <stdio.h>
#include <stdlib.h>

#define N 10000
int main()
{
    char s[N],fuh[N];
    int num[N];
    int i,j,k; // @@ [k is uninitialized; should be initialized to 0]
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
        num[k]='\0';
    }
    for(i=0,j=0;i<strlen(s);i++){           //记录符号
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            fuh[j]=s[i];
            j++;
        }
    } // @@ [fuh is not null-terminated; strlen(fuh) will cause undefined behavior]
    for(i=0;i<strlen(fuh);i++){                //先乘除 // @@ [strlen(fuh) uses undefined behavior due to missing null terminator; logic flawed: operators not removed, index skipping error]
        if(fuh[i]=='*'){
            num[i+1]=num[i]*num[i+1];
            num[i]=' '; // @@ [using space (32) as marker may conflict with valid numbers]
            i++; // @@ [double increment skips operators; does not update operator array]
        }
        if(fuh[i]=='/'){ // @@ [should be else if; after a multiplication, i may point to wrong operator]
            num[i+1]=num[i]/num[i+1];
            num[i]=' '; // @@ [same marker issue as above]
            i++; // @@ [same double increment issue]
        }
    }
    for(j=0,i=0;i<k;i++){           //清除空格
        if(num[i]!=' ')
            num[j++]=num[i];
    }
    num[j]='\0';
    int an=num[0];
    for(i=0,j=0;i<strlen(fuh);i++){           //后加减 // @@ [strlen(fuh) again undefined; if fuh empty, behavior undefined]
        if(fuh[i]=='+')
            an+=num[++j];
        if(fuh[i]=='-')
            an-=num[++j];
    }
    printf("%d",an);
    return 0;
}