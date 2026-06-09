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
            if(f[j]=='/'){ // @@ The logic for handling '*' and '/' is flawed. It uses 'if' instead of 'else if', causing both blocks to potentially execute or fall through incorrectly. More importantly, when f[j] is '*' or '/', it modifies n[j+1] but does NOT add the current operand to the m array correctly for later summation, nor does it skip the addition to m. The 'else' block adds n[j] to m, but if f[j] is '*' or '/', n[j] has already been consumed/merged into n[j+1]. The value added to m should be the result of the multiplication/division chain, not the intermediate n[j]. Also, the initial operand n[1] is handled, but subsequent operands involved in * / are not properly accumulated into the 'm' array which holds terms for +/-.
                n[j+1]=n[j]/n[j+1];
            }
            else{
                m[k]=n[j]; // @@ This adds the operand n[j] to the list of terms to be summed. However, if the previous operator was * or /, n[j] was already used to update n[j+1]. If the current operator is + or -, n[j] is a standalone term. But the logic fails to carry forward the result of a * or / sequence into the m array correctly. For example, in 10 + 20 * 30, when j=2 (f[2]='*'), n[3] becomes 600. The code does nothing to m. When j=3 (f[3]='-'), it goes to else, adding n[3] (which is 600) to m. This part seems okay for the second operand of the *, but what about the first? The logic is fundamentally broken for chaining operations and separating terms for addition/subtraction.
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
                if(f[j]=='/'){ // @@ Same logical error as above: using 'if' instead of 'else if' and incorrect management of operands into the 'm' array.
                    n[j+1]=n[j]/n[j+1];
                }
                else{
                    m[k]=n[j]; // @@ Incorrectly adds operands to the sum terms array. It fails to account for the fact that n[j] might have been modified by a previous * or / operation, or that the result of a * / chain needs to be stored in m exactly once.
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