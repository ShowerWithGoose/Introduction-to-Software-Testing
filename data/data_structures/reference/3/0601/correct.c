#include<stdio.h>
#include<string.h>
char A[100000];

int main(){

    int tab = 0,count = 0,loc = 0,temp;
    scanf("%s",A);
    int l = strlen(A);
    for(int i = 0;i < l;i ++){
        if(A[i] == '.'){
            tab = 1;
            break;
        }
        count ++;
    }
    if(tab == 0){
        if(l == 1){
            printf("%de0\n",A[0] - '0');
        }else{
            printf("%d.%se%d\n",A[0] - '0',&A[1],l - 1);
        }
    }else{
        if(A[0] != '0'){
            printf("%c",A[0]);
            printf(".");
            for(int i = 1;i < l;i ++){
                if(A[i] != '.'){
                    printf("%c",A[i]);
                }
            }
            printf("e%d\n",count - 1);
        }else{
            while(A[loc] == '0' || A[loc] == '.'){
                loc ++;
            }
            temp = loc;
            printf("%c",A[loc]);
            if(loc == l - 1){

            }else{
                printf(".");
            }
            loc ++;
            while(A[loc] != '\0'){
                if(A[loc] != '.'){
                    printf("%c",A[loc]);
                }
                loc ++;
            }
            printf("e%d\n",-temp + 1);
        }
    }
}
