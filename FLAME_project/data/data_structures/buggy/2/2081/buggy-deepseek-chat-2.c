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
       ret+=temp; // @@ Error: When the last operator is '*' or '/', the final temp should be added to ret, but the logic for handling the first number is incorrect. For example, with "100*200*0*300*400*500+500/600+12000=", after processing the multiplication chain, temp becomes 0, then ret is updated incorrectly. The initial ret+=temp for the first '+' case adds 0, and subsequent operations don't correctly accumulate the addition part.
    if(count<=1)
        ret+=num; // @@ Error: This condition is flawed. For expressions with multiple numbers, count>1, so this line is skipped, but the final addition result (like +12000) is not added to ret. The logic for handling '+' and '-' operators does not properly accumulate the last term.
    printf("%d",ret);
    return 0;
}