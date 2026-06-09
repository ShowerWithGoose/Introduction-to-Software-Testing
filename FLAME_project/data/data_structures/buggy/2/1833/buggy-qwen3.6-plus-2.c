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
            if(f[j]=='/'){ // @@ The logic for handling '*' and '/' is flawed. It uses 'if' instead of 'else if', causing both blocks to potentially execute or fall through incorrectly. More importantly, when f[j] is '*' or '/', it modifies n[j+1] but does NOT add the current term to m[]. However, the 'else' block adds n[j] to m[] for ANY operator that isn't '/' (including '+', '-', and even '=' if it slips through, though '=' stops the loop). Crucially, if f[j] is '*', it updates n[j+1] but falls through to the else block because the second 'if' is not an 'else if'. Wait, looking closely: if f[j]=='*', the first if executes. Then the second if (f[j]=='/') is false. So it goes to else. This adds n[j] (the left operand) to m[], which is wrong because n[j] has already been consumed into n[j+1]. The term should only be added to m[] when the operator is +, -, or =.
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
                if(f[j]=='/'){ // @@ Same logical error as above. The use of separate 'if' statements instead of 'else if' chain causes incorrect flow. Specifically, if f[j] is '*', it updates n[j+1], then checks if f[j]=='/' (false), then goes to else, adding n[j] to m[k]. This is incorrect because n[j] was part of a multiplication/division chain and should not be added as a separate term to m[]. Only the final result of the * / chain should be added when a +, - or = is encountered.
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
    printf("%d",sum);
    return 0;
}