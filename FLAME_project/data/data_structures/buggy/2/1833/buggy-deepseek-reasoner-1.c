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
            if(f[j]=='/'){ // @@ should be "else if" to correctly chain with the previous if and else
                n[j+1]=n[j]/n[j+1];
            }
            else{ // @@ this else is attached to the wrong if; it should be part of an if-else if-else chain that handles '*', '/', and other operators
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
                if(f[j]=='/'){ // @@ should be "else if" for correct operator precedence grouping
                    n[j+1]=n[j]/n[j+1];
                }
                else{ // @@ this else is attached to the wrong if; it should be part of a proper if-else if-else structure
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