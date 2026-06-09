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
    m=strlen(str); // @@ [strlen(str) is incorrect because str may not be null-terminated; also, the loop above does not store a '\0' in str, so strlen behavior is undefined]
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ // @@ [when i=0, str[i-1] accesses str[-1], which is out-of-bounds and undefined behavior]
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ // @@ [same out-of-bounds access when i=0; also division order is reversed: should be num1[i-1]/num[i], not num[i]/num1[i-1]]
            num1[i]=num[i]/num1[i-1]; // @@ [division operands are swapped; should be num1[i-1] / num[i]]
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){
            str[0]='+'; // @@ [this assignment has no effect on later logic and doesn't fix operator precedence correctly]
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='+'; // @@ [this is a comparison (==), not an assignment (=); typo causes no change to str[i]]
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='-'; // @@ [same typo: == instead of =; intended to replace * or / with previous + or -, but fails due to comparison]
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; // @@ [sum is reset to num1[0] in every iteration, so only last operation affects output]
        if(str[i-1]=='+'){
            sum=sum+num1[i];    
        }
        else if(str[i-1]=='-'){
            sum=sum-num1[i];
        }
        if(str[i]=='='){ // @@ [loop runs for i from 1 to m-1, but '=' is at str[m-1]; however, sum is printed inside loop only when str[i]=='=', but sum was just computed using str[i-1], which may skip final term or misalign]
            printf("%d",sum);
        }
    }
    return 0;
}