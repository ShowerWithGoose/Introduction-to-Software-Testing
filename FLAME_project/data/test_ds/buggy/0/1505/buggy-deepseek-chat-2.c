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
    for(i=0;i<=strlen(str)-2;i++){ // @@ The loop condition i <= strlen(str)-2 causes the last character to be skipped when it is not part of a valid expansion, resulting in missing output (e.g., the final 'F' in "a-uB-F" is not printed). The loop should iterate over all characters, including the last one.
        if(str[i]=='-'&&str[i-1]<str[i+1]&&range(str[i-1],str[i+1])==1){ // @@ When i=0, str[i-1] accesses str[-1], which is out-of-bounds and leads to undefined behavior. This can cause incorrect results or crashes.
            for(j=str[i-1]+1;j<=str[i+1]-1;j++){
                printf("%c",j);
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
}