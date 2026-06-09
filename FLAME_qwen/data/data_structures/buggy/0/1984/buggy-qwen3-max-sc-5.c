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
    gets(str); // @@ [Using gets() is unsafe and may cause buffer overflow; however, the immediate error is that the program does not handle cases where '-' appears at the beginning or end of the string, leading to out-of-bounds access in isok(). Also, when a valid expansion occurs, the code prints the expanded characters but still prints the '-' and surrounding characters again in the main loop, causing duplication.]
    int lenth = strlen(str);
    for(int i=0;i<lenth;i++){
        //TODO
        if(str[i] == '-'&&str[0] != '-'){ // @@ [This condition str[0] != '-' only prevents processing if the first character is '-', but doesn't handle cases where '-' appears at the end (i.e., i == lenth-1), which would cause str[i+1] to be out of bounds in isok() and put(). Also, even if expansion is done, the '-' and the next character are still printed by the else clause later, leading to incorrect output.]
            //TODO
            if(isok(i,str)){
                //TODO
                put(str[i - 1],str[i + 1]); // @@ [This prints the characters between start and end, but the main loop will still print the '-' (at str[i]) and the next character (str[i+1]) in subsequent iterations, causing duplication. The design fails to skip the processed part of the string.]
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
    for(int i=start+1;i<=end-1;i++){ // @@ [This loop prints characters from start+1 to end-1, but the problem requires expanding a-d to abcd, meaning it should include both endpoints. However, note: the main loop already printed the character before '-', and this function is meant to print the intermediate characters. But the specification says "expand a-d to abcd", so if 'a' was already printed, then we need to print 'b','c','d'. But here, if start='a', end='d', it prints 'b','c' only — missing 'd'. So the loop condition should be i <= end, not i <= end-1. Alternatively, the logic of what has already been printed is flawed.]
        //TODO
        printf("%c",i);
    }
}