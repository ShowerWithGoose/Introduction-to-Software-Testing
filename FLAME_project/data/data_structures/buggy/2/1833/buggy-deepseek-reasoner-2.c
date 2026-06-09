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
                n[j+1]*=n[j]; // @@ [Error: modifying n[j+1] but later the else will still push n[j] (the left operand) to m, causing duplication. The multiplication result is not properly isolated.]
            }
            if(f[j]=='/'){ // @@ [Error: should be 'else if' to form a proper if-else if-else chain; otherwise the else on line 22 attaches only to this if.]
                n[j+1]=n[j]/n[j+1]; // @@ [Error: same structural issue; the else for multiplication and other operators is misattached.]
            }
            else{ // @@ [Error: this else is attached only to the preceding 'if(f[j]=='/')', not to the first if. Consequently, when f[j]=='*', the else is executed, incorrectly pushing n[j] into m.]
                m[k]=n[j]; // @@ [Consequence of misattached else: left operand of '*' is pushed, leading to duplicate numbers in m.]
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
                    n[j+1]*=n[j]; // @@ [Same error as earlier: duplication due to misattached else in this block as well.]
                }
                if(f[j]=='/'){ // @@ [Same: should be else if.]
                    n[j+1]=n[j]/n[j+1];
                }
                else{ // @@ [Same: incorrectly attached else.]
                    m[k]=n[j]; // @@ [Consequence: pushes numbers that should not be pushed.]
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