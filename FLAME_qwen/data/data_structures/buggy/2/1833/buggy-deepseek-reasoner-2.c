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
                n[j+1]*=n[j]; // @@ Error: multiplication modifies n[j+1] but does not remove n[j] from consideration; also n[j] may still be used later.
            }
            if(f[j]=='/'){
                n[j+1]=n[j]/n[j+1]; // @@ Error: division modifies n[j+1] but does not remove n[j]; similar issue.
            }
            else{
                m[k]=n[j]; // @@ Error: this else attaches only to the second if (for '/'), so when f[j]=='*', n[j] is not added to m, leading to missing numbers.
                k++;
            }
        }
    }
    if(f[1]=='*'||f[1]=='/'){
        if(f[1]=='*'){
            n[2]*=n[1]; // @@ Error: first operator is * or /, but m[1] is never initialized (k still 1), so later sum uses uninitialized value.
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
                    m[k]=n[j]; // @@ Error: same as above, m[1] remains uninitialized if no else branch executed at start.
                    k++;
        }
    }
}
    sum=m[1]; // @@ Error: m[1] may be uninitialized when first operator is '*' or '/'.
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
        // @@ Errot: missing case when f[j]=='*' or '/', causing z not incremented and sum not updated, leading to wrong accumulation.
    }
    printf("%d",sum);
    return 0;
}