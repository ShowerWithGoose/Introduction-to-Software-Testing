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
    m=strlen(str); @@ [strlen(str) includes the '=' character, but the loop below uses m as if it's the number of operators excluding '=', leading to out-of-bound or incorrect indexing]
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ @@ [when i=0, str[i-1] accesses str[-1], which is undefined behavior]
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ @@ [same issue: i=0 leads to str[-1]]
            num1[i]=num[i]/num1[i-1]; @@ [division order is reversed; should be num1[i-1]/num[i], not num[i]/num1[i-1]]
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){
            str[0]='+'; @@ [assignment uses =, but original code has == (see next lines); however, this line is correct with =, but logic is flawed because it only changes first operator arbitrarily]
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='+'; @@ [should be assignment =, not comparison ==; this does nothing]
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='-'; @@ [same error: == instead of =]
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; @@ [sum is reset to num1[0] in every iteration, so previous operations are lost]
        if(str[i-1]=='+'){
            sum=sum+num1[i];    
        }
        else if(str[i-1]=='-'){
            sum=sum-num1[i];
        }
        if(str[i]=='='){ @@ [loop runs up to i < m, and str[m-1] is '=', but this check is inside loop that starts at i=1; may miss final output or trigger early]
            printf("%d",sum);
        }
    }
    return 0;
}