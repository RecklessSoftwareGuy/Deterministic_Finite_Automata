#include<stdio.h>
#include<stdlib.h>

struct State
{
    int final;
    struct State* a_transition;
    struct State* b_transition;
};

struct State* head = NULL;

void CreateDFA(struct State** head)
{
    struct State* q0 = (struct State*)malloc(sizeof(struct State));
    struct State* q1 = (struct State*)malloc(sizeof(struct State));
    struct State* q2 = (struct State*)malloc(sizeof(struct State));
    struct State* q3 = (struct State*)malloc(sizeof(struct State));
    *head = q0;
    q0->final = 1;
    q0->a_transition=q1;
    q0->b_transition=q0;
    q1->final = 0;
    q1->a_transition=q3;
    q1->b_transition=q2;
    q2->final = 0;
    q2->a_transition=q3;
    q2->b_transition=q0;
    q3->final=0;
    q3->a_transition=q3;
    q3->b_transition=q3;
}

int TraverseDFA(struct State** head, char* ch, int n)
{
    struct State* current = *head;
    for(int i=0; i<=n;i++)
    {
        if(ch[i] == 'a')
        {
            current = current->a_transition;
        }
        else if(ch[i] == 'b')
        {
            current = current->b_transition;
        }
    }
    return current->final;
}

int main()
{
    CreateDFA(&head); int n;
    printf("Enter Length of Input String: ");
    scanf("%d", &n);
    char ch; char charr[n];
    int temp = n; int i=0;
    printf("Enter String: ");
    while(temp>=0)
    {
        ch = getchar();
        charr[i] = ch;
        temp--; i++;
    }
    int dfa = TraverseDFA(&head, charr, n);
    if(dfa==1)
    {
        printf("DFA ended in accepting state!\n");
    }
    else if(dfa==0)
    {
        printf("DFA ended in not accepting state!\n");
    }
}
