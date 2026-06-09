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
    gets(str); // @@ [Using gets() is unsafe and deprecated; however, the immediate error is that when '-' appears at the start or end, the code accesses str[-1] or beyond the string, causing undefined behavior. Also, if input has consecutive '-' like "a--b", it may access invalid indices. But more critically, in the loop, when str[i]=='-' and i==0, the condition `str[0]!='-'` prevents processing, but if i>0, it accesses str[i-1] and str[i+1] without checking if i+1 is within bounds. This leads to out-of-bound access when '-' is the last character.]
    int lenth = strlen(str);
    for(int i=0;i<lenth;i++){
        //TODO
        if(str[i] == '-'&&str[0] != '-'){ // @@ [This condition `str[0] != '-'` is incorrect. It should check that the current '-' is not at the beginning (i>0) and not at the end (i < lenth-1). Instead, it only skips processing if the very first character is '-', which is wrong logic. For example, in "a-b-c", the second '-' would be processed even if it's valid, but if input starts with '-', it skips all '-', even valid ones later. Also, no check for i+1 being valid.]
            //TODO
            if(isok(i,str)){ // @@ [isok accesses s[place-1] and s[place+1] without ensuring place>0 and place < strlen(s)-1. If '-' is at the start (i=0) or end (i=lenth-1), this causes buffer underflow/overflow. Although the condition above tries to prevent i=0 by checking str[0]!='-', it doesn't prevent i=lenth-1. So if input ends with '-', e.g., "a-", then i=lenth-1, and isok accesses s[lenth], which is '\0', leading to invalid comparison and potential crash or wrong output.]
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
    }else if(s[place - 1] <= '9'&&s[place - 1]>='0'&&s[place + 1] <= '9'&&s[place + 1]>='0'&&s[place + 1] > s[place - 1]){ // @@ [The condition `s[place - 1] <= '9'` is always true for any char <= '9', including non-digit characters like ':' or '/'. The correct check is `s[place - 1] >= '0' && s[place - 1] <= '9'`, which is done, but the order of conditions may lead to misinterpretation. However, the real issue is lack of bounds checking before accessing s[place-1] and s[place+1].]
        //TODO
        return 1;
    }
    return 0;
}

void put(char start,char end){
    for(int i=start+1;i<=end-1;i++){ // @@ [This loop prints characters from start+1 to end-1, but the problem requires expanding a-d to abcd, meaning it should include both endpoints. However, note that in the main loop, when a valid '-' is found, the code does NOT print the '-' itself, and instead calls put() which prints the middle characters. But the character before '-' (start) was already printed in the else clause of the main loop? Actually, no: in the main loop, when str[i]=='-', it does NOT go to the else, so the character before '-' was printed in a previous iteration. Then put() should print from start+1 to end, because the end character hasn't been printed yet. But the current put() prints up to end-1, so the end character is never printed. For example, a-d: 'a' is printed when i=0 (not '-'), then at i=1 ('-'), it calls put('a','d') which prints 'b','c', then when i=2 ('d'), since it's not '-', it prints 'd'. So actually 'd' is printed later. But what if the string is "a-d"? Then: i=0: print 'a'; i=1: '-' -> call put('a','d') -> prints 'b','c'; i=2: print 'd'. So output is "abcd", which is correct. However, if the string is "a-d-e", then after expanding a-d to abcd, then at i=3 ('-'), it will process d-e. But 'd' was already printed at i=2, so put('d','e') prints nothing (since d+1=101, e-1=100, loop doesn't run), then i=4 prints 'e', so output is "abcde", which is correct. But wait: what if the expansion is at the end? Like "x-y"? Then: i=0: 'x' printed; i=1: '-' -> put('x','y') prints nothing (x+1=121, y-1=120 -> no loop); i=2: 'y' printed. So "xy" is output, which is correct. However, the problem says expand a-d to abcd, which includes both ends. The current method relies on the left char being printed before the '-' and the right char being printed after the '-'. But what if there are consecutive expansions? Like "a-c-e": a printed, then at i=1: put('a','c') prints 'b', then i=2: 'c' printed, then i=3: '-', put('c','e') prints 'd', then i=4: 'e' printed -> "abcde", correct. So the put function is actually correct as is. The real errors are in bounds checking and handling of edge cases like '-' at start/end.]
        //TODO
        printf("%c",i);
    }
}