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
    m=strlen(str); @@ [strlen(str) counts the entire buffer, but str may contain uninitialized characters beyond the '='; also, the loop reads i+1 numbers but m is based on string length which includes the '=' and possibly garbage]
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ @@ [when i=0, str[i-1] accesses str[-1], which is out-of-bounds undefined behavior]
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ @@ [same out-of-bounds access when i=0]
            num1[i]=num[i]/num1[i-1]; @@ [division order is reversed: should be num1[i-1]/num[i], not num[i]/num1[i-1]; also num1[i-1] might be 0]
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){
            str[0]='+'; @@ [this assignment is meaningless because str[0] is an operator after the first number, but logic doesn't handle expression structure correctly]
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='+'; @@ [this is a comparison (==), not assignment (=); typo causes no change to str[i]]
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='-'; @@ [same typo: == instead of =]
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; @@ [sum is reset to num1[0] in every iteration, so previous accumulations are lost]
        if(str[i-1]=='+'){
            sum=sum+num1[i];    
        }
        else if(str[i-1]=='-'){
            sum=sum-num1[i];
        }
        if(str[i]=='='){ @@ [loop runs up to m-1, but str[m-1] is '=', so this condition triggers only at last iteration; however, sum may not include all terms due to earlier errors]
            printf("%d",sum);
        }
    }
    return 0;
}