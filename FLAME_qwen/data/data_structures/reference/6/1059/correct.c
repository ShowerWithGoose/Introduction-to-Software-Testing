#include <stdio.h>
#include <stdlib.h>

#define TYPE_IN_DEQUE int
#define N 101
typedef struct _Deque
{
    TYPE_IN_DEQUE _num[N];
    int head, tail;
} Deque;
inline int push_back(Deque* dq, TYPE_IN_DEQUE x);
inline int push_front(Deque* dq, TYPE_IN_DEQUE x);
inline int pop_back(Deque* dq);
inline int pop_front(Deque* dq);
inline TYPE_IN_DEQUE front(Deque* dq);
inline TYPE_IN_DEQUE back(Deque* dq);
inline int size(Deque* dq);
inline int empty(Deque* dq);
inline int getint();
inline void putint(int r);

Deque stack;

int main()
{
#ifdef VSCODE
    freopen("1.data.in", "r", stdin);
#endif
    int op, val;
    while((op = getint()) != -1)
    {
        if(op == 0)
        {
            if(!empty(&stack))
                printf("%d ", back(&stack));
            if(pop_back(&stack) == -1)
                printf("error ");
        }
        else
        {
            val = getint();
            if(push_back(&stack, val) == -1)
                printf("error");
        }
    }
    return 0;
}


int push_back(Deque* dq, TYPE_IN_DEQUE x)
{
    if(size(dq) == N-1) return -1;
    dq->_num[dq->tail++] = x;
    dq->tail == N ? (dq->tail = 0) : 0;
    return 0;
}
int push_front(Deque* dq, TYPE_IN_DEQUE x)
{
    if(size(dq) == N-1) return -1;
    dq->head == 0 ? (dq->tail = N) : 0;
    dq->_num[--dq->head] = x;
    return 0;
}
int pop_back(Deque* dq)
{
    if(empty(dq)) return -1;
    dq->tail == 0 ? (dq->tail = N) : 0;
    dq->tail--;
    return 0;
}
int pop_front(Deque* dq)
{
    if(empty(dq)) return -1;
    dq->head++;
    dq->head == N ? (dq->tail = 0) : 0;
    return 0;
}
TYPE_IN_DEQUE front(Deque* dq)
{
    return dq->_num[dq->head];
}
TYPE_IN_DEQUE back(Deque* dq)
{
    return dq->_num[dq->tail == 0 ? N - 1 : dq->tail - 1];
}
int size(Deque* dq)
{
    return (dq->tail - dq->head + N) % N;
}
int empty(Deque* dq)
{
    return dq->tail == dq->head;
}

int getint()
{
    char c;int flag=0;int num=0;
    while((c=getchar())<'0'||c>'9')if(c=='-')flag=1;
    while(c>='0'&&c<='9'){num=(num<<1)+(num<<3)+(c&15);c=getchar();}
    return flag?-num:num;
}

void putint(int r)
{
    if(r==0){putchar('0');return;}
    if(r<0){putchar('-');r=-r;}
    char s[14]; int cnt = 0;
    while(r){s[cnt++]=48|r%10;r/=10;}
    while(cnt--)putchar(s[cnt]);
}
