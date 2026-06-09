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
    gets(str); // @@ [Using `gets()` is unsafe and may cause buffer overflow; more importantly, the logic fails to skip printing the '-' when expansion is not performed. In the test case "B-e", since isok returns 0, the else branch prints every character including '-', but the current loop prints all non-'-' characters unconditionally and only handles expansion inside the if-block, thus omitting the '-' in output when it shouldn't be expanded. However, the real issue is that when str[i]=='-', and isok returns false, the code does NOT print the '-', because the else clause only prints str[i] when it's not '-', so the '-' itself is never printed in the non-expansion case.]
    int lenth = strlen(str);
    for(int i=0;i<lenth;i++){
        //TODO
        if(str[i] == '-'&&str[0] != '-'){ // @@ [The condition `str[0] != '-'` is incorrect. It prevents processing any '-' if the string starts with '-', but more critically, it doesn't address the core issue: when a '-' is encountered and isok() returns false, the '-' should still be printed as-is. However, in this code, if str[i]=='-' and isok() is false, the loop skips printing anything for that '-', because the else clause only runs when str[i]!='-'. Thus, the '-' disappears from output in cases like "B-e", leading to "Be" instead of "B-e".]
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