#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coe;
    int pow;
    struct Node *next;
};

int main()
{
    int a,n;
    char c;
    struct Node *head,*p,*q,*p0;
    struct Node *head2,*p2,*q2,*p02;
    head=p=head2=p2=NULL;
    do{
        scanf("%d%d%c",&a,&n,&c);
        q=(struct Node*)malloc(sizeof(struct Node));
        q->coe=a;q->pow=n;q->next=NULL;
        if(head==NULL)
        {
            head=p=q;
        }
        else
        {
            p->next=q;
            p=p->next;
        }
    }while(c!='\n');
    
    
        scanf("%d%d%c",&a,&n,&c);
        ; // @@ [This semicolon creates an empty statement, and the following block is executed only once regardless of input. This incorrectly assumes the second polynomial has exactly one term. The loop for reading the second polynomial is missing here.]
        //q->coe=a;q->pow=n;q->next=NULL;
        for(p=head;p!=NULL;p0=p,p=p->next)
        {
            q2=(struct Node*)malloc(sizeof(struct Node));
            q2->next=NULL;
            q2->coe=(p->coe)*a;
            q2->pow=(p->pow)+n;
            if(head2==NULL)
            {
                head2=p2=q2;
            }
            else
            {
                p2->next=q2;
                p2=p2->next;
            }
        }
        
    do{
        scanf("%d%d%c",&a,&n,&c);
        
        for(p=head;p!=NULL;p0=p,p=p->next)
        {
            q2=(struct Node*)malloc(sizeof(struct Node));
            q2->next=NULL;
            q2->coe=(p->coe)*a;
            q2->pow=(p->pow)+n;
            for(p2=head2;p2!=NULL;p02=p2,p2=p2->next)
            {
                if(q2->pow>p2->pow)
                {
                    q2->next=p2;
                    p02->next=q2; // @@ [p02 may be uninitialized when head2 is not NULL but the insertion happens at the head. This leads to undefined behavior. Also, inserting in descending order requires handling head insertion separately.]
                    break;
                }
                else if(q2->pow==p2->pow){
                    p2->coe+=q2->coe;
                    free(q2);
                    break;
                }
                
            }
            if(p2==NULL){
                p02->next=q2; // @@ [p02 may be uninitialized if head2 was NULL initially, leading to undefined behavior.]
            }
        
        
        }
    }while(c!='\n'); // @@ [The logic for reading the second polynomial is flawed: the first term is read outside the loop, and subsequent terms are processed in a separate loop. This causes the first term of the second polynomial to be multiplied twice: once before the loop and once inside the loop if there are more terms. In the given test case, both polynomials have one term, so the first multiplication happens in the isolated block, and then the do-while loop reads again (but there's no more input), leading to undefined behavior or incorrect processing. However, in the provided test input, after reading "15 1000000000\n", the first isolated scanf reads it, then the do-while tries to read again — but there's no more input, so scanf fails, c is not '\n', and the loop may not behave as expected. But more critically, the program multiplies the first polynomial by the first term of the second polynomial twice: once in the isolated block and once if the do-while runs (which it shouldn't on valid input). However, in this specific test case, the do-while condition fails immediately because after the first isolated scanf, c is '\n', so the do-while doesn't run. But then why output is 240? Because 8*15=120, but output is 240. Wait: actually, the isolated block runs once (correctly computing 8*15=120), but then the do-while loop starts by reading again — but there is no more input! So scanf may fail, leaving a, n, c unchanged. If c was '\n' from before, the loop doesn't run. So why 240? Let's reexamine: the test input is two lines: "8 1000000000" and "15 1000000000". The first do-while reads the first line correctly. Then the isolated scanf reads the second line: a=15, n=1000000000, c='\n'. Then the for-loop multiplies first poly by (15,1e9) → creates term 120, 2e9. Then the do-while starts: it does scanf again — but there's no third line! So scanf fails, and c remains '\n' (or maybe undefined). But assuming it reads nothing, c might still be '\n', so the loop body doesn't execute. Then it prints head2 which has 120 2e9. But expected is 120, yet output is 240. So where does 240 come from? Ah! Look: the isolated block runs, creating head2 with 120. Then the do-while loop condition is checked: it does scanf — but if stdin is at EOF, scanf returns less than 3, so a,n,c are not updated. If c was '\n' from previous, then c!='\n' is false, so loop doesn't run. So output should be 120. But the buggy output is 240. Therefore, the real issue is that the program actually processes the second polynomial's first term TWICE. How? Because after the first do-while (reading poly1), the code does: 
        scanf("%d%d%c",&a,&n,&c);   // reads first term of poly2
        ; 
        // then multiplies poly1 by (a,n) → correct
        then enters a do-while that starts by reading AGAIN → but if the input only has one term for poly2, this second scanf fails or reads garbage. However, in many environments, if you try to read beyond input, the variables retain old values. So if the second scanf fails, a,n,c remain 15,1e9,'\n'. Then c!='\n' is false, so the loop body doesn't run. So only one multiplication. Then why 240?

Wait, another possibility: the test input is provided as:
8 1000000000\n
15 1000000000\n

But the first do-while reads until c=='\n', so it reads "8 1000000000\n" → c='\n', stops.

Then the next scanf: reads "15 1000000000\n" → a=15, n=1e9, c='\n'.

Then the for-loop runs: multiplies poly1 (8x^1e9) by 15x^1e9 → 120x^2e9 → head2 = [120,2e9].

Then the do-while starts: 
   scanf("%d%d%c", ...) → now at EOF. Suppose it returns 0, so a,n,c unchanged → c is still '\n'.
   so while(c!='\n') → false → loop body skipped.

Then print head2 → "120 2000000000 "

But expected is 120, and buggy output is 240. So contradiction.

Unless... the program actually runs the isolated block AND the first iteration of the do-while.

How? Because after the isolated scanf, c='\n', so the do-while condition is checked: do { ... } while(c!='\n'). Since c=='\n', the loop body is NOT executed. So only one multiplication.

But the output is 240, which is 8*15*2. So it did the multiplication twice.

Ah! Look at the structure:

After reading poly1, the code does:

        scanf(...);   // reads first term of poly2
        ; 
        for(...) { ... }   // multiplies poly1 by that term → head2 created

        do {
            scanf(...);   // tries to read next term of poly2
            for(...) { ... }  // multiplies poly1 by that term and merges
        } while(...);

But if the second polynomial has only one term, then after the initial scanf, we've read the whole poly2. The do-while should not run. But what if the input does NOT end with a newline? The problem says: "There is no space after the last exponent, and the input ends with a newline character." So it does end with '\n'.

But here's the catch: the initial isolated scanf reads the entire second polynomial's first (and only) line, including the '\n'. So c='\n'.

Then the do-while: 
   It executes the body AT LEAST ONCE (because it's do-while), then checks condition.

Wait! That's the bug! It's a **do-while** loop, so the body runs once BEFORE checking the condition.

So even if the second polynomial has only one term, the do-while body runs once, trying to read a second term (which doesn't exist), but then proceeds to multiply using whatever values are in a,n,c.

But after the isolated scanf, c='\n'. Then the do-while starts:

   Body:
      scanf("%d%d%c", &a,&n,&c);  // Now, since input is exhausted, this scanf may fail.
      // If it fails, a,n,c are unchanged → so a=15, n=1e9, c='\n' (from previous)
      Then it goes into the for-loop and multiplies poly1 by (15,1e9) AGAIN.
      So now head2 gets another 120x^2e9 added → total 240.

That's why output is 240.

So the critical errors are:

1. The second polynomial is read incorrectly: the first term is processed outside a loop, and then a do-while loop forces at least one more read and processing, even if there's only one term.

2. The do-while loop should not be used here; instead, the second polynomial should be read in a loop similar to the first.

3. Additionally, the merging logic during insertion has bugs (uninitialized p02), but the primary cause of the wrong answer in this test case is the double multiplication due to flawed input reading structure.

Thus, the key error lines are:

- The isolated scanf and following multiplication block: it handles the first term of poly2, but then the do-while runs at least once, reusing the same values if scanf fails, causing duplicate multiplication.

- The do-while loop itself is fundamentally wrong for reading the rest of poly2 because it runs unconditionally once.

Therefore, annotations:
    
        scanf("%d%d%c",&a,&n,&c); // @@ [This reads the first term of the second polynomial, but the subsequent do-while loop will read again and process at least one more term (even if none exists), leading to duplicate processing of the same term when the second polynomial has only one term.]
        ; // @@ [This empty statement is part of a flawed structure that separates the first term of the second polynomial from the rest, causing incorrect input handling.]
        //q->coe=a;q->pow=n;q->next=NULL;
        for(p=head;p!=NULL;p0=p,p=p->next)
        {
            q2=(struct Node*)malloc(sizeof(struct Node));
            q2->next=NULL;
            q2->coe=(p->coe)*a;
            q2->pow=(p->pow)+n;
            if(head2==NULL)
            {
                head2=p2=q2;
            }
            else
            {
                p2->next=q2;
                p2=p2->next;
            }
        }
        
    do{ // @@ [This do-while loop runs at least once, even if the second polynomial has only one term. After the initial term is processed above, this loop attempts to read another term. If input is exhausted, scanf may leave 'a', 'n', and 'c' unchanged (retaining the previous term's values), causing the same term to be multiplied again, doubling the coefficient. In the test case, this results in 8*15 + 8*15 = 240 instead of 120.]
        scanf("%d%d%c",&a,&n,&c);
        
        for(p=head;p!=NULL;p0=p,p=p->next)
        {
            q2=(struct Node*)malloc(sizeof(struct Node));
            q2->next=NULL;
            q2->coe=(p->coe)*a;
            q2->pow=(p->pow)+n;
            for(p2=head2;p2!=NULL;p02=p2,p2=p2->next)
            {
                if(q2->pow>p2->pow)
                {
                    q2->next=p2;
                    p02->next=q2; // @@ [When inserting at the beginning of head2, p02 is uninitialized (since the loop starts with p2=head2 and p02 is only set inside the loop), leading to undefined behavior. This may corrupt the list or crash, though in this specific test case the duplicate multiplication is the dominant error.]
                    break;
                }
                else if(q2->pow==p2->pow){
                    p2->coe+=q2->coe;
                    free(q2);
                    break;
                }
                
            }
            if(p2==NULL){
                p02->next=q2; // @@ [If head2 was empty before this insertion, p02 is uninitialized, causing undefined behavior. Even if head2 is not empty, if the loop didn't run (e.g., head2 had one element and we're appending), p02 might not be properly set.]
            }
        
        
        }
    }while(c!='\n');
    
    for(p2=head2;p2!=NULL;p2=p2->next)
    {
        printf("%d %d ",p2->coe,p2->pow);
    }
    
    
    
    
    
    return 0;
}