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
    gets(str); // @@ [Using 'gets' is unsafe and may cause buffer overflow; however, the immediate error is that when '-' appears at the beginning or end, the code accesses invalid indices like str[-1] or str[lenth], leading to undefined behavior. Also, if input has consecutive '-' or ends with '-', str[i+1] may be out of bounds.]
    int lenth = strlen(str);
    for(int i=0;i<lenth;i++){
        //TODO
        if(str[i] == '-'&&str[0] != '-'){ // @@ [This condition only excludes strings starting with '-', but does not check if '-' is at the last position (i == lenth-1), which would make str[i+1] access beyond the string. Also, it fails to handle cases where '-' is in the middle but adjacent characters are invalid (e.g., non-alphanumeric).]
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
    for(int i=start+1;i<=end-1;i++){ // @@ [This loop prints characters from start+1 to end-1, but the problem requires expanding a-d to abcd, meaning it should include both endpoints. However, note that in the main loop, the character before '-' (start) is already printed by the 'else' clause, and the '-' itself is skipped. But the current logic misses printing the 'end' character. More critically, if the expansion is a-b, this loop runs from 'a'+1 to 'b'-1, which is empty, so nothing is printed — but "ab" should be output. The correct expansion should print all characters from start+1 up to and including end. So the loop condition should be i <= end, not i <= end-1.]
        //TODO
        printf("%c",i);
    }
}