#include <stdio.h>
#include <string.h>

int range(int a,int b){
    if(a>='0'&&a<='9'&&b>='0'&&b<='9'){
        return 1;
    }
    else if(a>='a'&&a<='z'&&b>='a'&&b<='z'){
        return 1;
    }
    else if(a>='A'&&a<='Z'&&b>='A'&&b<='Z'){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char str[100];
    scanf("%s",str);
    int i;
    char j;
    for(i=0;i<=strlen(str)-2;i++){ // @@ Loop bound should be i < strlen(str) - 1 to process the last character and avoid out-of-bounds when i=0
        if(str[i]=='-'&&str[i-1]<str[i+1]&&range(str[i-1],str[i+1])==1){
            for(j=str[i-1]+1;j<=str[i+1]-1;j++){
                printf("%c",j);
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
}