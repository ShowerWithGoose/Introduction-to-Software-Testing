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
    m=strlen(str); @@ [strlen(str) includes the '=' character, but the logic assumes m corresponds only to operators between numbers; also, num and str may be out of sync because i counts numbers, but str has one extra element for '=']
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ @@ [when i=0, str[i-1] accesses str[-1], which is invalid memory access (undefined behavior)]
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ @@ [same issue: i=0 leads to str[-1]; also division order is reversed: should be num1[i-1]/num[i], not num[i]/num1[i-1]]
            num1[i]=num[i]/num1[i-1];
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){
            str[0]='+'; @@ [this assignment doesn't fix the underlying parsing issue and is logically misplaced]
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='+'; @@ [this is a comparison (==), not assignment (=); typo causes no change to str[i]]
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='-'; @@ [same error: == instead of =, so no assignment occurs]
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
        if(str[i]=='='){ @@ [loop runs up to i < m, and str[m-1] is '=', but sum is printed only when str[i]=='=', yet the loop may not reach correct final state due to earlier logic errors]
            printf("%d",sum);
        }
    }
    return 0;
}