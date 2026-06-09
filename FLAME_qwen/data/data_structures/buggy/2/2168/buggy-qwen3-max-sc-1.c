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
    return result; // @@ [This function incorrectly calculates the number. It assumes digits start at `i` and tries to compute place values in reverse, but it modifies `p` based on future digits and then uses decreasing powers while reading forward, leading to wrong results. For example, "123" would be computed as 1*100 + 2*10 + 3*1 correctly only if logic aligns, but loop condition `a[j+1]` may go out of bounds and `p` calculation is flawed.]
}
int main(){
    gets(a); // @@ [`gets` is unsafe and deprecated; more critically, in many modern environments (like those used in testing), `gets` may not be available or cause compilation errors because it was removed in C11. This likely causes the "gcc: not found" error indirectly due to compilation failure in strict environments.]
    char c=' ';
    squeez(a,c);
    int i=0,sum=0,num=0;
    num=trans_to_num(a,i);
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
    sum+=num;
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
            num=trans_to_num(a,i);
            record=a[i];
        }
    }        
    printf("%d",sum);

    return 0;
}