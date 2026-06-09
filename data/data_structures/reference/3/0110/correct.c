#include<stdio.h>
#include<string.h>
#define SCALE 150

/* Delete the suffixal zero*/

int delete_zero(char *a,int end){ // a = string,end = the position of the last character
    int sum = 0;
    while (a[end] == '0' || a[end] == '.'){  //to skip the punctual "."
        if(a[end] == '0') sum++;
        end--;
    }
    return sum;  //return the quantity of suffixal zeroes
}

int main(){
    char num[SCALE];
    int k=0,start=0;

    fgets(num,SCALE,stdin);
    int l = strlen(num);
    num[l-1] = '\0';

    while (num[++k] != '.') ;
    if (num[0] == '-'){
        printf("-");
        start = 1;
    }
    int q = delete_zero(num,l-2);

    if (num[start] != '0'){
        printf("%c",num[start]);
        if ((q+start-l+4) > 0){
            printf("e%d",k-start-1);
        }
        else{
            printf(".");
            int m = l-q-3,i = start+1;
            while(m){
                if (num[i] == '.'){
                    i++;
                    continue;
                }
                printf("%c",num[i]);
                i++;
                m--;
            }
            printf("e%d",k-start-1);
        }
    } 
    else {
            while (num[++k] == '0') ;
            printf("%c",num[k]);
            int m = l-k-q-2;
            if (m > 0){
                printf(".");
                for (int i=k+1;i<=k+m;i++)
                  printf("%c",num[i]);
            }
            printf("e%d",-(k-start-1));
        }

    return 0;
}
