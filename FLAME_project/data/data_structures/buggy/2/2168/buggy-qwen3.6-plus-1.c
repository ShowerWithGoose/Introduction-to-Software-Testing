#include <stdio.h>
#include <string.h>
char a[10000];
void squeez(char s[], char c) /*删除某个字符c*/{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c){
            s[j++] = s[i];
        }
    s[j] = '\0';
}
int trans_to_num(char* a,int i){
    int p=1,result=0;
    for(int j=i;a[j+1]>='0'&&a[j+1]<='9';j++){
        p*=10;
    }
    for(;a[i]>='0'&&a[i]<='9';i++){
        result+=(a[i]-'0')*p;
        p/=10;
    }
    return result;
}
int main(){
    gets(a);
    char c=' ';
    squeez(a,c);
    int i=0,sum=0,num=0;
    num=trans_to_num(a,i); // @@ The logic fails to correctly handle the precedence and associativity of mixed operators (+, -, *, /) in a single pass or structured two-pass manner. Specifically, when encountering + or -, it breaks the first loop but doesn't properly accumulate the previous 'num' into 'sum' before processing the next term if that term involves * or /. The state management of 'record' and 'num' is flawed for complex expressions like A * B / C + D - E * F.
    while(1){
        while (a[i]!='='&&a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/'){
            i++;
        }
        if(a[i]=='='){
            sum=num;
            break;
        }
        else if(a[i]=='*'){
            i++;
            num*=trans_to_num(a,i);
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i);
        }
        else{
            break;
        }
    }
    if(a[i]=='='){
        printf("%d",sum);
        return 0;
    }
    sum+=num; // @@ This line adds the initial term to sum. However, the subsequent logic for handling the rest of the expression is incorrect.
    num=0;
    char record=a[i];
    i++;
    num=trans_to_num(a,i);
    while(1){
        while(a[i]!='='&&a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/'){
            i++;
        }
        if(a[i]=='='){
            if(record=='+'){
                sum+=num;
            }
            else{
                sum-=num;
            }
            break;
        }
        else if(a[i]=='*'){
            i++;
            num*=trans_to_num(a,i);
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i);
        }
        else{
            if(record=='+'){
                sum+=num;
                i++;
            }
            else{
                sum-=num;
                i++;
            }
            num=trans_to_num(a,i); // @@ Error: After updating sum, we read the next number. But then we update record=a[i] below. If a[i] is an operator, this is correct for the next iteration, BUT we haven't advanced 'i' past the operator yet in this branch? No, wait. In the 'else' branch (operator is + or -), we just finished processing a term. We add/subtract 'num'. Then we need to start reading the NEXT term. The next character at a[i] is the operator (+ or -). We should record THIS operator as the 'record' for the NEXT term. But the code does: num=trans_to_num(a,i). At this point a[i] is '+' or '-'. trans_to_num will likely return 0 or behave incorrectly because a[i] is not a digit. Then record=a[i] reads the operator. Then the loop continues. The inner while loop advances i past digits. But 'num' was set incorrectly.
            record=a[i]; // @@ Logic error: The flow here is broken. When we hit a + or -, we should finalize the current 'num' into 'sum', then read the NEXT operator to determine the sign of the following term, then read the following term. Here, it tries to read a number starting at the operator position.
        }
    }        
    printf("%d",sum);

    return 0;
}