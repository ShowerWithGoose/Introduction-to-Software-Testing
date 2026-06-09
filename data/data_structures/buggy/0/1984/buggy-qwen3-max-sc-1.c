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
    gets(str); // @@ [Using gets() is unsafe and may cause compilation errors or warnings in modern compilers; it was removed in C11. Should use fgets() instead.]
    int lenth = strlen(str);
    for(int i=0;i<lenth;i++){
        //TODO
        if(str[i] == '-'&&str[0] != '-'){ // @@ [Incorrect condition: checking str[0] != '-' doesn't ensure that current '-' is not at the start; should check i > 0 to avoid accessing str[-1]. Also fails when '-' appears at index 0.]
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
    }else if(s[place - 1] <= '9'&&s[place - 1]>='0'&&s[place + 1] <= '9'&&s[place + 1]>='0'&&s[place + 1] > s[place - 1]){ // @@ [Character comparison with '9' and '0' is okay, but logic assumes valid digits; however, combined with missing bounds checks (e.g., place+1 may be out of bounds), this can lead to undefined behavior.]
        //TODO
        return 1;
    }
    return 0;
}

void put(char start,char end){
    for(int i=start+1;i<=end-1;i++){ // @@ [This loop prints characters between start and end, but excludes both endpoints. According to problem, a-d should become abcd, meaning it should include all from 'a' to 'd'. However, the main function already prints the character before '-', so this function should print from start+1 to end inclusive. But here it stops at end-1, so final character is missing.]
        //TODO
        printf("%c",i);
    }
}