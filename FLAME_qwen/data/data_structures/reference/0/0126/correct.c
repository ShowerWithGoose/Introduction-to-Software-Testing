#include <stdio.h>
#include<string.h>
int main(){
    char str[1000],str_cpy[1000];
    int j=0;//str_cpy的位数
    memset(str_cpy,'0',sizeof(char));
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++){
        if(str[i]!='-'){
            str_cpy[j++]=str[i];
            continue;
        }
        else{
            if(i==0){
                str_cpy[j++]=str[i];
                continue;
            }
            else if (str[i-1]>='a'&&str[i-1]<='z'&&str[i+1]>='a'&&str[i+1]<='z'&&str[i-1]<str[i+1]){
                for(int k=str[i-1]+1;k<str[i+1];k++){
                    str_cpy[j++]=k;
                }
                
            }
            else if (str[i-1]>='A'&&str[i-1]<='Z'&&str[i+1]>='A'&&str[i+1]<='Z'&&str[i-1]<str[i+1]){
                for(int k=str[i-1]+1;k<str[i+1];k++){
                    str_cpy[j++]=k;
                }
            }
            else if (str[i-1]>='0'&&str[i-1]<='9'&&str[i+1]>='0'&&str[i+1]<='9'&&str[i-1]<str[i+1]){
                for(int k=str[i-1]+1;k<str[i+1];k++){
                    str_cpy[j++]=k;
                }
            }
            else
                str_cpy[j++]=str[i];
        }
    }
    str_cpy[j+1]='\0';
    printf("%s",str_cpy);
    return 0;
}



