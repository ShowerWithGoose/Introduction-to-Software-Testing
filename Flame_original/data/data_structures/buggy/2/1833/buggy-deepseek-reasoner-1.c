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
        for(j=2;j<i;j++){ // @@ error: loop condition should be j < i-1 to exclude the '=' operator at f[i-1]
            if(f[j]=='*'){
                n[j+1]*=n[j];
            }
            if(f[j]=='/'){
                n[j+1]=n[j]/n[j+1];
            }
            else{ // @@ error: this else is attached to the second if (f[j]=='/') but should be part of an else-if chain; it incorrectly stores n[j] even when multiplication or division was performed
                m[k]=n[j];
                k++;
            }
        }
    }
    if(f[1]=='*'||f[1]=='/'){ // @@ error: missing initialization of m[1] (the first number) before entering this branch, leading to uninitialized memory later
        if(f[1]=='*'){
            n[2]*=n[1];
            }
        if(f[1]=='/'){
        n[2]=n[1]/n[2];
            }
        for(j=2;j<i;j++){ // @@ error: same loop condition issue as above
                if(f[j]=='*'){
                    n[j+1]*=n[j];
                }
                if(f[j]=='/'){
                    n[j+1]=n[j]/n[j+1];
                }
                else{ // @@ error: same else problem as above
                    m[k]=n[j];
                    k++;
        }
    }
}
    sum=m[1]; // @@ error: m[1] may be uninitialized if first operator was '*' or '/'
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