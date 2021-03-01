#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
    int size;
    char *arr;
    int top;
};

struct stack *createstack(int size)
{
    struct stack *stack;
    stack = (struct stack *)malloc(sizeof(struct stack));

    if (!stack)
        return NULL;
    stack->size = size;
    stack->top = -1;
    stack->arr = (char *)malloc(size * sizeof(char));
    return stack;
}

int isEmpty(struct stack *stack)
{
    if (stack->top == -1)
        return 1;
    else
        return 0;
}

void pop(struct stack *stack)
{
    if (!isEmpty(stack))
        stack->top--;
}

void push(char value, struct stack *stack)
{

    stack->top++;
    stack->arr[stack->top] = value;
}

char peek(struct stack *stack)
{
    return stack->arr[stack->top];
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return -1;
}
int operand(char ch)
{
    if ((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A'))
        return 1;
    else
        return 0;
}
int in_post(char* array, int len)
{
    int i_new = 0;
    struct stack *stacks;
    stacks = createstack(len);
    for (int i = 0; i <len; i++)
    {
        if (operand(array[i]) == 1)
        {
            array[i_new] = array[i];
            i_new++;
        }
        else if (array[i] == '(')
            push(array[i], stacks);
        else if (array[i] == ')')
        {
            while (!isEmpty(stacks) && peek(stacks) != '(')
            {
                array[i_new] = peek(stacks);
                pop(stacks);
                i_new++;
            }
            if (!isEmpty(stacks) && peek(stacks) != '(')
                return -1;
            else
            {
                pop(stacks);
            }
        }
        else // an operator is encountered

        {
            while (!isEmpty(stacks) && precedence(array[i]) <= precedence(peek(stacks)))
            {
                array[i_new] = peek(stacks);
                i_new++;
                pop(stacks);
                
            }
            push(array[i], stacks);
        }
    }
    while (!isEmpty(stacks))
    {
        array[i_new] = peek(stacks);
        pop(stacks);
        i_new++;
    }

    array[i_new] = '\0';
    printf("The prefix of the infix is :\n");
    printf("%s", strrev(array));
}

int main()
{
    char xprsn[100];
    char *ptr;
    
    printf("Enter the expression :\n");
    scanf("%s", &xprsn);
    ptr=xprsn;
    for(int i=0;i<strlen(xprsn);i++)
    {
        if(ptr[i]=='(')
        ptr[i]=')';
        else if(ptr[i]==')')
        {
            ptr[i]='(';
        }
    }


    in_post(strrev(ptr), strlen(xprsn));
}
