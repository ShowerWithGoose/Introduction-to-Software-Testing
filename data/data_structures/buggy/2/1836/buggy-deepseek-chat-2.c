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
            if(x[i+1]==' '){ // @@ Error: This condition only handles spaces after numbers, but the input may have no spaces (e.g., "5-1*2*3+12/2/2="). Numbers can be followed directly by operators or '=', so numbers may not be stored correctly.
                y[t++]=s;
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i]; // @@ Error: Operators are stored as characters (e.g., '+') in the integer array y, but later they are compared with integer values like y[i]=='*'. This mixes character and integer types incorrectly.
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){ // @@ Error: y[i] is an integer, but '*' is a character constant. This comparison is invalid because y[i] stores the operator as an integer (e.g., 43 for '+'), not as a character.
            z[k-1]=z[k-1]*y[i+1];
            i++;
        }
        else if(y[i]=='/'){ // @@ Error: Same issue as above; y[i] is an integer, not a character.
            z[k-1]=z[k-1]/y[i+1];
            i++;
        }
        else z[k++]=y[i];
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1]; // @@ Error: z[i] is an integer, but '+' is a character constant. This comparison is invalid. Also, the logic for addition/subtraction is incorrect (e.g., z[i+1]+=z[i-1] modifies the wrong element).
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1]; // @@ Error: Same character comparison issue. Also, the subtraction logic is flawed.
    }
    printf("%d" , z[k-1]);
    return 0;
}