#include<stdio.h>
#include<string.h>
char str[100000];
//int main(){
//    int i;
//    gets(str);
//    int len=strlen(str);
//    printf("%c",str[0]);
//    for(i=1;i<len;i++){
//        if(str[i]=='-'){
//            if(str[i-1]>='0'&&str[i-1]<'9'&&str[i+1]>str[i-1]&&str[i+1]<='9'){
//                for(int j=1;j<str[i+1]-str[i-1];j++)
//                    printf("%c",str[i-1]+j);
//            }
//           else if(str[i-1]>='a'&&str[i-1]<'z'&&str[i+1]>str[i-1]&&str[i+1]<='z'){
//                for(int j=1;j<str[i+1]-str[i-1];j++)
//                    printf("%c",str[i-1]+j);
//            }
//           else if(str[i-1]>='A'&&str[i-1]<'Z'&&str[i+1]>str[i-1]&&str[i+1]<='Z'){
//                for(int j=1;j<str[i+1]-str[i-1];j++)
//                    printf("%c",str[i-1]+j);
//            }
//            else
//                printf("-");
//        }
//        else
//            printf("%c",str[i]);
//    }
//    return 0;
//}
char str[100000];
int main(){
    gets(str);
    int i,j;
    for(i=j=0;str[i]!='\0';i++){
        if(str[i]!=' ')
            str[j++]=str[i];
    }
    int num=0,pre='+',temp=0,ret=0,count=0;
    for(i=0;str[i]!='=';i++){
        if(str[i]>='0'&&str[i]<='9'){
            sscanf(str+i,"%d",&num);
            count++;
            while(str[i]>='0'&&str[i]<='9')
                i++;
            i--;
            switch(pre){
                case '+':ret+=temp;temp=num;break;
                case '-':ret+=temp;temp=-num;break;
                case '*':temp*=num;break;
                case '/':temp/=num;break;
            }
        }
        else
            pre=str[i];
    }
    if(pre=='*'||pre=='/')
       ret+=temp; // @@ [This condition is incorrect: it only adds temp when the last operator is * or /, but temp should always be added to ret at the end regardless of the last operator. In cases where the expression ends with + or -, temp already holds the correct signed value and must be added.]
    if(count<=1)
        ret+=num; // @@ [This condition is flawed: when there's only one number (count == 1), 'num' was already assigned to 'temp' in the loop, and 'ret' remains 0. However, 'ret += num' duplicates the value because 'temp' was never added. Also, if count==0 (empty input), this causes undefined behavior. More critically, in multi-term expressions, this line incorrectly adds 'num' again even when it was already processed via 'temp'.]
    printf("%d",ret);
    return 0;
}