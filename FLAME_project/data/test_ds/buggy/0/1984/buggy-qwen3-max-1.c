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
    gets(str); // @@ [Using `gets()` is unsafe and may cause buffer overflow; more critically, the logic fails to handle non-expandable '-' correctly. When '-' is not expandable, it should be printed as-is, but current code skips printing '-' entirely in such cases.]
    int lenth = strlen(str);
    for(int i=0;i<lenth;i++){
        //TODO
        if(str[i] == '-'&&str[0] != '-'){ // @@ [Condition `str[0] != '-'` incorrectly excludes valid cases where string starts with '-', but more importantly, when `str[i] == '-'` and `isok` returns false, the code does not print the '-', leading to missing '-' in output (e.g., "B-e" becomes "Be").]
            //TODO
            if(isok(i,str)){
                //TODO
                put(str[i - 1],str[i + 1]);
            }
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