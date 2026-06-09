#include <stdio.h>
#include <ctype.h>

int chtype(char);
int main(){
    char str[10005],ans[10005];
    int type ;
    gets(str);
    int j = 0;
    for(int i=0;str[i] != '\0';i++){
        
        if(str[i] == '-'){
            type = chtype(str[i-1]);
            if(type == chtype(str[i+1])){
                char t;
                t = str[i-1] + 1;
                while(t != str[i+1]){
                    ans[j++] = t; 
                    t+=1;
                }
            }
            else
            ans[j++] = str[i];
                
        }
        else
        ans[j++] = str[i];
    }
    ans[j] = '\0';
    puts(ans);
    return 0;

}
int chtype(char c){
    int type = 4;
    if(islower(c))
    type = 1;
    else if(isupper(c))
    type = 2;
    else
    type = 0;

    return type;

}

