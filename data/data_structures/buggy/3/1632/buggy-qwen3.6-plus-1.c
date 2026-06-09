#include<stdio.h>
#include<string.h>
int main(){
    char str[110];
    gets(str); // @@ gets() is deprecated and removed in the C11 standard, which causes a compilation error on modern compilers. It should be replaced with fgets() or scanf().
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
            
            }printf("e%d",-end+point); // @@ The closing brace '}' prematurely terminates the 'else' block, causing this printf to execute unconditionally when point==1. This leads to using the uninitialized variable 'end' when str[point-1]!='0', resulting in undefined behavior and incorrect output.
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