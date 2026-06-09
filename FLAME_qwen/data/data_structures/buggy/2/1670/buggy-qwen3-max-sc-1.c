#include<stdio.h>
#include<string.h>
int main()
{
    int num[10005],num1[10005]={0};
    int i=0,sum=0,m;
    char str[10005];
    while(1){
        scanf("%d %c",&num[i],&str[i]);
        if(str[i]=='='){
            break;
        }
        i++;
    }
    m=strlen(str); @@ [strlen(str) counts up to the null terminator, but str may not be null-terminated because it's filled character-by-character without ensuring termination. This leads to undefined behavior when calling strlen.]
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ @@ [On the first iteration (i=0), str[i-1] accesses str[-1], which is out-of-bounds memory access — undefined behavior.]
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ @@ [Same issue: when i=0, str[i-1] is str[-1], invalid access. Also, logic is reversed: should be num1[i-1]/num[i], not num[i]/num1[i-1].]
            num1[i]=num[i]/num1[i-1];
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){
            str[0]='+'; @@ [This assignment doesn't fix the underlying parsing logic and is applied only once; also, modifying operator precedence this way is logically flawed.]
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='+'; @@ [This is a comparison (==), not an assignment (=). Should be str[i] = '+'; same for next line.]
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='-'; @@ [Same error: using == instead of =, so no assignment occurs.]
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; @@ [sum is reset to num1[0] in every iteration, so previous additions/subtractions are lost. Should initialize sum before the loop.]
        if(str[i-1]=='+'){
            sum=sum+num1[i];    
        }
        else if(str[i-1]=='-'){
            sum=sum-num1[i];
        }
        if(str[i]=='='){ @@ [Loop runs for i from 1 to m-1, but '=' is at str[i] where i equals original input count; however, due to earlier logic errors, this condition may never trigger correctly. Also, output may be printed multiple times or not at all.]
            printf("%d",sum);
        }
    }
    return 0;
}