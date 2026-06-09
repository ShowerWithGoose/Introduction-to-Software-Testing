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
                case '+':ret+=temp;temp=num;break; // @@ The logic for handling addition is flawed. It adds the previous 'temp' to 'ret' and sets 'temp' to the current number. However, 'temp' is initialized to 0. For the first number, ret becomes 0, temp becomes the first number. This part is okay for the start, but see below.
                case '-':ret+=temp;temp=-num;break; // @@ Similar logic for subtraction.
                case '*':temp*=num;break; // @@ Multiplication updates temp.
                case '/':temp/=num;break; // @@ Division updates temp.
            }
        }
        else
            pre=str[i];
    }
    if(pre=='*'||pre=='/') // @@ This condition checks if the LAST operator was * or /. If the expression ends with + or -, the final accumulated 'temp' is NOT added to 'ret'. In the test case "100*200*0*300*400*500+500/600+12000=", the last operator is '+'. The loop processes numbers. When it hits the final '+', it does ret+=temp (which is result of 500/600 = 0) and temp=12000. The loop ends. The condition pre=='*' is false. So ret (which is 0) is printed. The final temp (12000) is lost.
       ret+=temp;
    if(count<=1) // @@ This check is also problematic. If there is only one number, count is 1. The loop runs once. ret+=temp (temp is 0 initially? No, temp is 0. ret becomes 0. temp becomes num). Then pre is still '+'. The if(pre...) adds temp to ret. So ret becomes num. This works for single number. But the main issue is the missing accumulation of the last term when the last operator is + or -.
        ret+=num;
    printf("%d",ret);
    return 0;
}