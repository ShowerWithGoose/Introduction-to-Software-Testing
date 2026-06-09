#include<stdio.h>
#include<string.h>
int main()
{
    char x[101];
    int y[101] , z[101];
    gets(x);
    int l=strlen(x) , t=0 , ans=0 , s=0;
    for(int i=0;i<l;i++){
        if(x[i]>='0' && x[i]<='9'){
            s=s*10+x[i]-48;
            if(x[i+1]==' '){ // @@ The logic for parsing numbers is flawed. It only stores a number if followed by a space. It fails for numbers at the end of the string, before operators, or if multiple spaces exist. Also, it doesn't handle the case where the next character is an operator directly without space.
                y[t++]=s;
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i]; // @@ Storing char operators into an int array `y` mixes data types. While ASCII values are stored, this complicates later processing and distinguishes poorly from small integers if not handled carefully. More critically, the previous block failed to store the number preceding this operator if it wasn't followed by a space.
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){
            z[k-1]=z[k-1]*y[i+1]; // @@ `y[i+1]` contains the ASCII value of the next token if it's an operator, or the integer value if it's a number. However, since `y` mixes chars and ints, and the parsing was flawed, this index access is unsafe. More importantly, `y` holds the raw tokens. If `y[i]` is '*', `y[i+1]` should be the next number. But `z` is being built separately. The logic assumes `z` has the previous number at `k-1`. This part attempts to evaluate * on the fly but accesses `y` incorrectly for the operand. It should use the parsed number from `y`, but `y` structure is broken.
            i++;
        }
        else if(y[i]=='/'){
            z[k-1]=z[k-1]/y[i+1]; // @@ Same error as above. Division uses incorrect operand source and mixed type array.
            i++;
        }
        else z[k++]=y[i]; // @@ This copies both numbers and remaining operators (if any passed through) to `z`. Since `*` and `/` are skipped in `y` iteration effectively by `i++` but not removed from `y`, and `z` is populated conditionally, the resulting `z` array structure is unpredictable due to the initial parsing errors.
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1];
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1]; // @@ This evaluation logic assumes `z` contains alternating numbers and operators starting with a number. Due to previous errors, `z` does not reliably contain this structure. Additionally, modifying `z[i+1]` while iterating can lead to using updated values incorrectly if not strictly sequential, though here it looks like standard left-to-right reduction. The primary issue remains the corrupted data in `z`.
    }
    printf("%d" , z[k-1]);
    return 0;
}