//
//  main.c
//  表达式计算（连续）
//
//  Created by  on 2022/3/3.
//

#include <stdio.h>
int cauculate(int comt,int what,char a)
{
    if(a=='*')
        return comt*what;
    else
        return comt/what;
}

int main(int argc, const char * argv[]) {
    long long int sum=0;
    int temp_num=0,store_num=0;
    char temp_not,store_not;
    int notation=1;//暂时（读入）的符号 和 这段的符号
    
    scanf("%d %c",&temp_num,&temp_not);
    
    for(;; scanf("%d %c",&temp_num,&temp_not)){
        if(temp_not=='+'||temp_not=='-'){
            sum+=notation*temp_num;
            if(temp_not=='+')
                notation=1;
            else if(temp_not=='-')
                notation=-1;
        }
        else if(temp_not=='*'||temp_not=='/'){
            store_num=temp_num;
            store_not=temp_not;
            scanf("%d %c",&temp_num,&temp_not);
            for(;temp_not=='*'||temp_not=='/';scanf("%d %c",&temp_num,&temp_not)){
                store_num=cauculate(store_num, temp_num, store_not);
                store_not=temp_not;
            }
            store_num=cauculate(store_num, temp_num, store_not);
            sum+=store_num*notation;
            if(temp_not=='+')
                notation=1;
            else if(temp_not=='-')
                notation=-1;
            else if(temp_not=='='){
                printf("%lld",sum);
                break;
            }
        }
        else if(temp_not=='='){
            sum+=temp_num*notation;
            printf("%lld",sum);
            break;
        }
    }
    return 0;
}


