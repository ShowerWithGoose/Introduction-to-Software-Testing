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
    gets(str); // @@ [Using `gets()` is unsafe and may cause buffer overflow; more critically, the logic fails to skip printing the '-' when expansion is not performed, leading to incorrect output like "Be" instead of "B-e".]
    int lenth = strlen(str);
    for(int i=0;i<lenth;i++){
        //TODO
        if(str[i] == '-'&&str[0] != '-'){ // @@ [Condition `str[0] != '-'` is incorrect; it prevents processing any '-' if the string starts with '-', but more importantly, even when `isok` returns false, the code still prints the current character (including '-') via the `else` clause, but misses that when `isok` is true, it should NOT print the '-' nor the next character normally. However, the real bug is: when `isok` returns false, the '-' is printed by the `else`, which is correct, BUT when `isok` returns true, the code prints the expanded characters via `put()`, yet the loop will later also print the character AFTER the '-', because the loop continues normally. Also, the '-' itself is never printed in the `if` branch, which is good, but the next character (e.g., 'e') is printed in a future iteration, causing duplication or incorrect output. For example, in "a-d", after expanding to "abc", the loop will later print 'd' again, resulting in "abcd", which seems okay, but in non-expanding cases like "B-e", since `isok` returns 0, it goes to `else` and prints '-', so output becomes "B-e", which is correct. Wait—then why does the test case "B-e" produce "Be"? Because in the `if` condition, it checks `str[i] == '-' && str[0] != '-'`. For "B-e", str[0] is 'B', so condition passes. Then `isok(i,str)` is called. In `isok`, it checks: 'B' is uppercase, 'e' is lowercase → fails all conditions → returns 0. So it goes to `else` and prints str[i], which is '-'. So output should be "B-e". But the buggy output is "Be", meaning the '-' was NOT printed. That implies the `else` did not run. Why? Because the condition `str[i] == '-' && str[0] != '-'` is true, so it enters the `if`, `isok` returns 0, so it doesn't call `put`, and then... there is no `else` inside the `if`! Look: the structure is:
        if(condition) {
            if(isok(...)) { ... }
        } else {
            printf(...)
        }
So when `str[i] == '-'` is true, it enters the outer `if`, and if `isok` is false, it does NOTHING — it doesn't print the '-'. Then the loop moves on, and the '-' is never printed. That's the critical bug.
        ]
            //TODO
            if(isok(i,str)){
                //TODO
                put(str[i - 1],str[i + 1]);
            }
            // Missing else to print '-' when not expanding!
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