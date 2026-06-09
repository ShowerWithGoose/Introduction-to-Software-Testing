//
//  main.c
//  数据结构class1
//
//  Created by  on 2022/3/3.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char a,string[10000];
    scanf("%s",&string);
    int i=0,j=0;
    char store;
    for(i=0;i<strlen(string)&&string[i]!='\0';i++){
        if(string[i]!='-'){
            printf("%c",string[i]);
        }
        else{
            if(string[i-1]>='a'&&string[i-1]<='z'&&string[i+1]>='a'&&string[i+1]<='z'&&string[i-1]<string[i+1]){
                for(j=1;j<string[i+1]-string[i-1];j++)
                    printf("%c",string[i-1]+j);
            }
            else if(string[i-1]>='A'&&string[i-1]<='Z'&&string[i+1]>='A'&&string[i+1]<='Z'&&string[i-1]<string[i+1]){
                for(j=1;j<string[i+1]-string[i-1];j++)
                    printf("%c",string[i-1]+j);
            }
            else if(string[i-1]>='0'&&string[i-1]<='9'&&string[i+1]>='0'&&string[i+1]<='9'&&string[i-1]<string[i+1]){
                for(j=1;j<string[i+1]-string[i-1];j++)
                    printf("%c",string[i-1]+j);
            }
            else{
                printf("-");
            }
        }
        
    }
    

    return 0;
}

