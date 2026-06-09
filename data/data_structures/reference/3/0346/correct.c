#include<stdio.h>
#include<string.h>
int loc(char s[]){
    int i,j=strlen(s);
    for (i = 0; i < j;i++){
        if(s[i]=='.'){
            return i;
        }
    }
    return 0;
}
int num_0(char s[]){
    int i, j = strlen(s);
    for (i = 0; i < j;i++){
        if(s[i]!='0'&&s[i]!='.'){
            return i;
        }
    }
    return 0;
}
char input[101];
char output[200];
int main(){
    scanf("%s", input);
    int p=loc(input),n=num_0(input);
    int len = strlen(input);
    if(p==1&&n!=0){
        if(n==len-1){
            printf("%ce-%d", input[n], n - 1);
        }else{
            printf("%c.", input[n]);
            int j;
            for (j = n + 1; j < len;j++){
                printf("%c", input[j]);
            }
            printf("e-%d", n - 1);
        }
    }else if(p==1&&n==0){
        printf("%s", input);
        printf("e0");
    }else if(p>1){
        printf("%c.", input[0]);
        int j;
        for (j = 1; j < len;j++){
            if(input[j]!='.'){
                printf("%c", input[j]);
            }
        }
        printf("e%d", p - 1);
    }else if(p==0){
        if(len==1){
            printf("%ce0", input[0]);
        }else{
            printf("%c", input[0]);
            int j;
            int num=0;
            for (j = len - 1; j >= 1;j--){
                if(input[j]!='0')
                    break;
                num++;
            }
            if(num!=(len-1))
                printf(".");
            for (j = 1; j < len - num;j--){
                printf("%c", input[j]);
            }
            printf("e%d", len - 1);
        }
    }

    return 0;
}


