#include <stdio.h>

int main(){
    int n[100000],m[100000]; // @@ Array m is uninitialized, leading to undefined behavior when m[1] is accessed later.
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
            else{ // @@ This else is incorrectly paired with if(f[j]=='/'), causing it to execute when f[j]=='*', incorrectly storing intermediate values in m.
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
                else{ // @@ Same logical error: executes when f[j]=='*', incorrectly adding values to m and disrupting the operand sequence.
                    m[k]=n[j];
                    k++;
        }
    }
}
    sum=m[1]; // @@ If the first operator is '*' or '/', the first if-block is skipped, leaving m[1] uninitialized with a garbage value.
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