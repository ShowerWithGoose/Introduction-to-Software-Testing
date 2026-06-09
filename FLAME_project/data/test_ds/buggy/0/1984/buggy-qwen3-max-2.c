#include<stdio.h>
#include<string.h>
/*思路 
问题拆分成三个函数
1、扩展符位置
2、扩展符前后是否满足题设条件
3、扩展输出*/
int isok(int place, char s[]);
void put(char start,char end);
int main(){
    char str[100];
    gets(str); // @@ [Using `gets()` is unsafe and may cause buffer overflow; more importantly, it's not the direct cause of WA here, but the main logic flaw is in output handling]
    int lenth = strlen(str);
    for(int i=0;i<lenth;i++){
        //TODO
        if(str[i] == '-'&&str[0] != '-'){ // @@ [Condition `str[0] != '-'` incorrectly skips processing if the string starts with '-', but more critically, when a '-' is not expanded, it should still be printed. However, in this code, non-expanded '-' characters are never printed because the `else` only prints non-'-' characters.]
            //TODO
            if(isok(i,str)){
                //TODO
                put(str[i - 1],str[i + 1]);
            }
            // @@ [Missing: if '-' is not expanded (i.e., isok returns 0), the '-' itself should still be printed, but this code does nothing in that case, so the '-' is omitted from output.]
        }
        else printf("%c",str[i]);
    }
}

int isok(int place,char s[]){
    if(s[place - 1] <= 'Z'&&s[place - 1]>='A'&&s[place + 1] <= 'Z'&&s[place + 1]>='A'&&s[place + 1] > s[place - 1]){
        //TODO
        return 1;
    }else if(s[place - 1] <= 'z'&&s[place - 1]>='a'&&s[place + 1] <= 'z'&&s[place + 1]>='a'&&s[place + 1] > s[place - 1]){
        //TODO
        return 1;
    }else if(s[place - 1] <= '9'&&s[place - 1]>='0'&&s[place + 1] <= '9'&&s[place + 1]>='0'&&s[place + 1] > s[place - 1]){
        //TODO
        return 1;
    }
    return 0;
}

void put(char start,char end){
    for(int i=start+1;i<=end-1;i++){
        //TODO
        printf("%c",i);
    }
}