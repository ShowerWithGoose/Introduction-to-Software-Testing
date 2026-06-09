#include<stdio.h>
#include<string.h>
int main(){
    char str[110];
    gets(str); // @@ gets() is removed in the C11 standard and will cause a compilation error in modern compilers; use fgets() or scanf() instead.
    int length=strlen(str),i,point,flag=0;int end;int record; // @@ Variables 'point', 'end', and 'record' are uninitialized, which can lead to undefined behavior if the decimal point is missing or no non-zero digits exist after it.
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
            
            }printf("e%d",-end+point);
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