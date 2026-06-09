#include <stdio.h>

int main(){
    int n[100000],m[100000];
    char f[100000]={0};
    int i=1,j,k=1,sum,z=1;
    do{
        scanf("%d",&n[i]);
        scanf(" %c",&f[i]);
        i++;
    }while(f[i-1]!='='); // @@ [The loop reads one extra character after '=', but more critically, the indexing starts at 1, causing misalignment between numbers and operators. Also, when '=' is read, the last number has already been read, but the logic assumes operator at f[j] corresponds to operation between n[j] and n[j+1], which breaks for the last term.]
    if(f[1]=='+'||f[1]=='-'||f[1]=='='){ // @@ [This condition assumes the first operator determines the whole parsing strategy, but expressions like "5 * 2 + 3 =" will fail because f[1] is '*', so this block is skipped incorrectly.]
            m[k]=n[1];
            k++;
        for(j=2;j<i;j++){
            if(f[j]=='*'){
                n[j+1]*=n[j]; // @@ [This modifies n[j+1] in place, but then later uses n[j] as a standalone term if not * or /, leading to double use or incorrect values. Also, when j = i-1 (last operator is '='), accessing n[j+1] is out of valid input range.]
            }
            if(f[j]=='/'){
                n[j+1]=n[j]/n[j+1]; // @@ [Same issue: accesses n[j+1] which may be uninitialized or beyond the actual input numbers; also integer division is correct per spec, but logic flow is broken.]
            }
            else{
                m[k]=n[j]; // @@ [This 'else' pairs only with the 'if(f[j]=='/')', not with both * and /, so if f[j]=='*', it does the multiplication AND adds n[j] to m[], causing duplication. Should be 'else if' or combined condition.]
                k++;
            }
        }
    }
    if(f[1]=='*'||f[1]=='/'){ // @@ [This block duplicates logic from above but only runs if first operator is * or /, leading to incomplete handling when expression starts with number followed by + or -, and missing cases where later operators are * or / but first isn't.]
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
                else{
                    m[k]=n[j]; // @@ [Same flaw: 'else' only excludes '/', so '*' case still falls through to add n[j] to m[], corrupting the term list.]
                    k++;
        }
    }
}
    sum=m[1]; // @@ [If no terms were added to m[] (e.g., single number "5="), m[1] is uninitialized, leading to undefined behavior. Also, m indexing starts at 1 but may not be filled correctly due to earlier logic errors.]
    z=1;
    for(j=1;j<=i-2;j++){ // @@ [Loop iterates over operators, but m[] may not have enough elements; also, z increments only on + or -, but m[z+1] may be uninitialized if fewer terms were stored.]
        if(f[j]=='+'){
            sum+=m[z+1]; // @@ [Accesses m[z+1] without ensuring it exists; z starts at 1, so first access is m[2], but m[1] was set as first term—off-by-one in term indexing.]
            z++;
        }
        if(f[j]=='-'){
            sum-=m[z+1]; // @@ [Same off-by-one error; should use m[z] and increment after, or adjust indexing. Also, consecutive * and / terms may not be collapsed properly into m[].]
            z++;
        }
    }
    printf("%d",sum); // @@ [May print garbage due to uninitialized variables or incorrect term aggregation.]
    return 0;
}