#include<stdio.h>
#include<string.h>
int main(){
    char str[110];
    gets(str); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in modern C standards (C11 onwards), 'gets' has been removed, leading to compilation error if compiler enforces standard compliance]
    int length=strlen(str),i,point,flag=0;int end;int record;
    for(i=0;i<length;i++){
        if(str[i]=='.'){
            point=i;
        }
    }if(point==1){
        if(str[point-1]!='0'){
            printf("%s",str);
            printf("e0");
            
        }else{
            for(i=point+1;i<length;i++){
                if(str[i]!='0'){
                record=i;
                break;}
                }
                for(i=record;i<length;i++){
                    printf("%c",str[i]);
                if(i==record){
                    if(i!=length-1){
                    printf(".");
                    }
                end=i;    
                }
            }
            
            }printf("e%d",-end+point); // @@ [Variable 'end' may be used uninitialized if the inner loop doesn't execute (e.g., input like "0.0" with no non-zero digit after decimal), leading to undefined behavior; however, problem states there are no trailing zeros and all digits are significant, so this might not occur per spec, but code logic still risky]
            flag=0;
        }
    else{
        printf("%c.",str[0]);
        for(i=1;i<length;i++){
            if(i==point){
                continue;
            }printf("%c",str[i]);
        }printf("e%d",point-1);
    }
        
        
    
    
    return 0;
} 
//0.1324001 1.324001e
//1324355.1
//12.354
//8.12
//0.0012 1.2e-3