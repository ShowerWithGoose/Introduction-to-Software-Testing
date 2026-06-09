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
                end=i; // @@ This line incorrectly sets end to the index of the first non-zero digit, but it should be the index of the last digit (length-1) for calculating the exponent. The exponent calculation -end+point will be wrong.
                }
            }
            
            }printf("e%d",-end+point); // @@ The exponent calculation is incorrect because end is set to the first non-zero digit index instead of the last digit index. For input like "0.0012", end becomes 4 (index of '2'), point is 1, so exponent = -4+1 = -3, which is correct by coincidence, but for "0.1324001" it would fail. Also, the variable end may be uninitialized if the loop doesn't execute (e.g., input "0.0").
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