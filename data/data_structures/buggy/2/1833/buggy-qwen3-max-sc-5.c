#include <stdio.h>

int main(){
    int n[100000],m[100000];
    char f[100000]={0};
    int i=1,j,k=1,sum,z=1;
    do{
        scanf("%d",&n[i]);
        scanf(" %c",&f[i]);
        i++;
    }while(f[i-1]!='=');
    if(f[1]=='+'||f[1]=='-'||f[1]=='='){
            m[k]=n[1];
            k++;
        for(j=2;j<i;j++){
            if(f[j]=='*'){
                n[j+1]*=n[j];
            }
            if(f[j]=='/'){
                n[j+1]=n[j]/n[j+1];
            }
            else{
                m[k]=n[j];
                k++;
            }
        }
    }
    if(f[1]=='*'||f[1]=='/'){
        if(f[1]=='*'){
            n[2]*=n[1];
            }
        if(f[1]=='/'){
        n[2]=n[1]/n[2];
            }
        for(j=2;j<i;j++){
                if(f[j]=='*'){
                    n[j+1]*=n[j];
                }
                if(f[j]=='/'){
                    n[j+1]=n[j]/n[j+1];
                }
                else{
                    m[k]=n[j];
                    k++;
        }
    }
}
    sum=m[1];
    z=1;
    for(j=1;j<=i-2;j++){
        if(f[j]=='+'){
            sum+=m[z+1];
            z++;
        }
        if(f[j]=='-'){
            sum-=m[z+1];
            z++;
        }
    }
    printf("%d",sum); @@ [The logic fails to correctly handle operator precedence and expression evaluation. It incorrectly assumes that all * and / operations can be resolved in a single forward pass without considering their position relative to + and -, and it mishandles the indexing of operands and operators, leading to incorrect results or undefined behavior (e.g., accessing n[j+1] when j+1 may be out of valid input range). Additionally, the program does not properly reduce the expression by replacing computed values, causing later stages to use stale or incorrect operand values.]
    return 0;
}