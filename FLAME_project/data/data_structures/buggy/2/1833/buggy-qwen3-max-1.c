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
                n[j+1]*=n[j]; // @@ [Incorrectly modifies n[j+1] by multiplying with n[j], but n[j] may have been overwritten in previous operations; also, logic fails to handle operator precedence correctly across segments]
            }
            if(f[j]=='/'){
                n[j+1]=n[j]/n[j+1]; // @@ [Division operands are reversed: should be n[j] / n[j+1] but stored as n[j+1] = n[j]/n[j+1], which corrupts future references; also integer division is correct but operand order and storage is wrong]
            }
            else{
                m[k]=n[j]; // @@ [This 'else' pairs only with the 'if(f[j]=='/')', not with both '*' and '/'; so for '*', it does the multiplication AND falls through to store n[j] incorrectly]
                k++;
            }
        }
    }
    if(f[1]=='*'||f[1]=='/'){
        if(f[1]=='*'){
            n[2]*=n[1];
            }
        if(f[1]=='/'){
        n[2]=n[1]/n[2]; // @@ [Same operand reversal issue: should compute n[1]/n[2] but then assign to n[2], which is okay for first step, but later steps reuse corrupted values]
            }
        for(j=2;j<i;j++){
                if(f[j]=='*'){
                    n[j+1]*=n[j]; // @@ [Again, modifies n[j+1] using possibly already-modified n[j]; fails to isolate multiplication/division groups properly]
                }
                if(f[j]=='/'){
                    n[j+1]=n[j]/n[j+1]; // @@ [Operand order and overwriting leads to incorrect intermediate values]
                }
                else{
                    m[k]=n[j]; // @@ [Same control flow error: 'else' only applies to division, so after handling '*', it still executes this block, duplicating or misassigning terms]
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
    printf("%d",sum);
    return 0;
}