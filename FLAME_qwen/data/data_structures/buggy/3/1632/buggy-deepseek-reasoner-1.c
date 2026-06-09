#include<stdio.h>
#include<string.h>
int main(){
    char str[110];
    gets(str);
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
            
            }printf("e%d",-end+point);
            flag=0;
        }
    else{ // @@ [Unmatched else: the preceding if block is already closed at line 34, so this else does not have a corresponding if, causing a compilation error.]
        printf("%c.",str[0]);
        for(i=1;i<length;i++){
            if(i==point){
                continue;
            }printf("%c",str[i]);
        }printf("e%d",point-1);
    }
        
        
    
    
    return 0;
}