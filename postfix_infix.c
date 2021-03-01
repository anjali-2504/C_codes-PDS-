#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100
struct stack
{
    int top;
    char *arr[100];
    int size;
};

struct stack *createstack(int size)
{
    struct stack *stack;
    stack = (struct stack *)malloc(sizeof(struct stack));

    if (!stack)
        return NULL;
    stack->size = size;
    stack->top = -1;
    for (int i = 0; i < size; i++)
        stack->arr[i] = (char *)malloc(100 * sizeof(char));
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
    if (isEmpty(stack)==0) 
        --stack->top;
}

void push(char value[], struct stack *stack)
{
    char *ptr;
    ptr=value;
    stack->top++;
  // printf("%s ",value);
    strcpy(stack->arr[stack->top],ptr);
}
char *ptr;
char *peek(struct stack *stack)
{
ptr=stack->arr[stack->top];
    return ptr;
} 
int oper(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}
void in_post(char array[], int len)
{
 
    struct stack *stacks;

    stacks = createstack(len);
    
    for (int i = 0; i< len; i++)
    {char arrtemp[2];
       arrtemp[0]=array[i];
       arrtemp[1]='\0';
        if (oper(array[i]) == 0)
        { 
            push(arrtemp, stacks);

        }
        else if (oper(array[i])!= 0)
        {

            char temp1[15];
            char temp2[15];
            char temp[30];
            char *op1;
            op1=peek(stacks);
            pop(stacks);
            char *op2;
            op2=peek(stacks);
            pop(stacks);
            sprintf(temp1, "%c%s%s", '{', op2, arrtemp);
            sprintf(temp2, "%s%c", op1, '}');
            sprintf(temp,"%s%s",temp1,temp2);
            push(temp, stacks);
        }
    }
 printf("%s ",peek(stacks)); 
}
int main()
{
    char xprsn[300];
    printf("Enter the expression :\n");
    scanf("%s", &xprsn);
    int size=strlen(xprsn);
    in_post(xprsn,size);
}
