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
            if(x[i+1]==' '){ // @@ Error: The condition only checks for space, but the input may have no space between number and operator (e.g., "5+3") or the number may be at the end before '='. This causes numbers not to be stored properly.
                y[t++]=s;
                s=0;
            } 
        }
        else if(x[i]=='+' || x[i]=='-' || x[i]=='*' || x[i]=='/'){
            y[t++]=x[i]; // @@ Error: Operators are stored as integers (ASCII values) in y array, but later they are compared with character literals like '*' which works because of integer promotion. However, the main issue is that numbers are not stored when there is no space after them.
        }
    }
    int k=0;
    for(int i=0;i<t;i++){
        if(y[i]=='*'){
            z[k-1]=z[k-1]*y[i+1]; // @@ Error: y[i+1] is an integer (ASCII value of digit or operator), not the actual numeric value. Also, the array z is uninitialized, so z[k-1] contains garbage.
            i++;
        }
        else if(y[i]=='/'){
            z[k-1]=z[k-1]/y[i+1]; // @@ Error: Same issue as above - using ASCII value instead of numeric value, and uninitialized z array.
            i++;
        }
        else z[k++]=y[i]; // @@ Error: This stores the ASCII value of operators and digits into z, but digits should be stored as their numeric values, and operators should be handled differently.
    }
    for(int i=0;i<k;i++){
        if(z[i]=='+') z[i+1]+=z[i-1]; // @@ Error: This incorrectly modifies z[i+1] and uses z[i-1] which may be out of bounds or incorrect. The logic for addition/subtraction is flawed.
        else if(z[i]=='-') z[i+1]=z[i-1]-z[i+1]; // @@ Error: Same issue as above - incorrect logic for subtraction.
    }
    printf("%d" , z[k-1]); // @@ Error: z[k-1] may not contain the correct result due to all the previous errors.
    return 0;
}