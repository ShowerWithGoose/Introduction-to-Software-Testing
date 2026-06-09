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
                n[j+1]*=n[j]; // @@ [Incorrectly modifies n[j+1] by multiplying with n[j], but n[j] may have been overwritten or is not the correct left operand; should process multiplication/division in a separate pass without altering original operands prematurely]
            }
            if(f[j]=='/'){
                n[j+1]=n[j]/n[j+1]; // @@ [Division logic is inverted: it computes n[j]/n[j+1] but stores in n[j+1], which breaks subsequent operations; also, integer division order is wrong—should be previous accumulated value divided by next number]
            }
            else{
                m[k]=n[j]; // @@ [This 'else' only pairs with the 'if(f[j]=='/')', so when f[j]=='*', it still executes this block, causing duplicate or incorrect storage into m[]]
                k++;
            }
        }
    }
    if(f[1]=='*'||f[1]=='/'){
        if(f[1]=='*'){
            n[2]*=n[1];
            }
        if(f[1]=='/'){
        n[2]=n[1]/n[2]; // @@ [Same inversion issue: should be n[1]/n[2], but storing result in n[2] is okay here, but later logic assumes m[] holds terms, yet this path doesn't properly populate m[] for all cases]
            }
        for(j=2;j<i;j++){
                if(f[j]=='*'){
                    n[j+1]*=n[j]; // @@ [Again, modifies n[j+1] using possibly already-modified n[j], leading to incorrect chaining of multiplications]
                }
                if(f[j]=='/'){
                    n[j+1]=n[j]/n[j+1]; // @@ [Inverted division and destructive update]
                }
                else{
                    m[k]=n[j]; // @@ [Same issue: 'else' only applies to division check, so after handling '*', this still runs, incorrectly adding intermediate values to m[]]
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
        if(f[j]=='-'){ // @@ [Should be 'else if' to avoid double processing when operator is both not '+' and not '-', but more critically, m[] array is not correctly populated due to earlier logic errors, so even correct control flow wouldn't fix the core issue]
            sum-=m[z+1];
            z++;
        }
    }
    printf("%d",sum);
    return 0;
}