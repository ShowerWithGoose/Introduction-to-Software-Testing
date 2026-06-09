#include <stdio.h>

int main(){
    int n[100000],m[100000];
    char f[100000]={0};
    int i=1,j,k=1,sum,z=1;
    do{
        scanf("%d",&n[i]);
        scanf(" %c",&f[i]);
        i++;
    }while(f[i-1]!='='); @@ [The loop reads one extra character beyond '=' into f[i], and the index i becomes larger than intended, causing out-of-bound access in later loops. Also, the first number is stored at n[1], leaving n[0] unused, which complicates indexing.]
    if(f[1]=='+'||f[1]=='-'||f[1]=='='){
            m[k]=n[1];
            k++;
        for(j=2;j<i;j++){
            if(f[j]=='*'){
                n[j+1]*=n[j]; @@ [This modifies n[j+1] in place but doesn't handle operator precedence correctly across the entire expression; also accesses n[j+1] which may be uninitialized or beyond valid input range when j = i-1.]
            }
            if(f[j]=='/'){
                n[j+1]=n[j]/n[j+1]; @@ [Same issue: accesses n[j+1] which may be invalid when j = i-1 (since last valid number index is i-1, and f[i-1] is '='). Also, integer division is used correctly, but logic flow is broken.]
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
                    n[j+1]*=n[j]; @@ [Again, accesses n[j+1] which is out of bounds when j = i-1 because the last valid number is at index i-1, and f[i-1] is '=', so n[i] was never read.]
                }
                if(f[j]=='/'){
                    n[j+1]=n[j]/n[j+1]; @@ [Same out-of-bounds access and incorrect handling of operator precedence.]
                }
                else{
                    m[k]=n[j];
                    k++;
        }
    }
}
    sum=m[1];
    z=1;
    for(j=1;j<=i-2;j++){ @@ [Loop condition uses i-2, but f array indices and m array usage are inconsistent due to earlier indexing errors. Also, this loop assumes all '+'/'-' operations apply to m array, but m may not have been fully or correctly populated.]
        if(f[j]=='+'){
            sum+=m[z+1]; @@ [Accesses m[z+1] without ensuring it exists; z starts at 1, so m[2] is accessed on first '+', but m may only have one element.]
            z++;
        }
        if(f[j]=='-'){
            sum-=m[z+1]; @@ [Same issue: potential out-of-bounds access to m array.]
            z++;
        }
    }
    printf("%d",sum); @@ [May print incorrect or garbage result due to all the above logical and indexing errors.]
    return 0;
}