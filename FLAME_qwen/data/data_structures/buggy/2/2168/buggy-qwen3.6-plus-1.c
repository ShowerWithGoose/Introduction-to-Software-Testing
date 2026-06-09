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
    for(int j=i;a[j+1]>='0'&&a[j+1]<='9';j++){ // @@ Declaring a loop variable inside the for() initializer is a C99 feature and will cause a compilation error in strict C89 environments.
        p*=10;
    }
    for(;a[i]>='0'&&a[i]<='9';i++){
        result+=(a[i]-'0')*p;
        p/=10;
    }
    return result;
}
int main(){
    gets(a); // @@ gets() was officially removed in the C11 standard and causes a compilation error in modern compilers. Use fgets() instead.
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
    char record=a[i]; // @@ Declaring a variable after executable statements is a C99 feature and will cause a compilation error in strict C89 environments.
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