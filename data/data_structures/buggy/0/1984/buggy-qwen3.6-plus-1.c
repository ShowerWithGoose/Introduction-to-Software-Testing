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
    gets(str);
    int lenth = strlen(str);
    for(int i=0;i<lenth;i++){
        //TODO
        if(str[i] == '-'&&str[0] != '-'){ // @@ `str[0] != '-'` incorrectly checks the first character of the entire string instead of `i > 0`, which fails to prevent out-of-bounds access when '-' is at index 0 and incorrectly handles valid expansion positions.
            //TODO
            if(isok(i,str)){ // @@ When expansion is valid, the code does not skip `str[i+1]` in the loop, causing it to be printed again in the next iteration and resulting in duplicate characters. Additionally, if `isok` returns false, the '-' character is never printed.
                //TODO
                put(str[i - 1],str[i + 1]); // @@ `put` only prints intermediate characters. Combined with the main loop printing `str[i-1]` and `str[i+1]` separately, this causes the character immediately after '-' to be duplicated. The loop should skip `str[i+1]` or `put` should handle the full range.
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
    for(int i=start+1;i<=end-1;i++){ // @@ The loop range `start+1` to `end-1` excludes the boundary characters. Since the main loop prints them separately, this leads to the character after '-' being printed twice. It should iterate from `start` to `end` and the main loop should skip `str[i+1]` upon expansion.
        //TODO
        printf("%c",i);
    }
}