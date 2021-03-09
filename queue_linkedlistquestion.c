#include <stdio.h>
#include <stdlib.h>
struct qnode
{
    struct qnode *next;
    int val;
};
struct queue
{
    struct qnode *front, *rear;
};
struct queue *initialise()
{
    struct queue *q = (struct queue *)
        malloc(sizeof(struct queue));

    if (!q)
        return NULL;

    q->front = (struct qnode *)malloc(sizeof(struct qnode));

    q->front = NULL;
    q->rear = (struct qnode *)malloc(sizeof(struct qnode));

    q->rear = NULL;

    return q;
}
void enqueue(int n, struct queue *q)
{
    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        struct qnode *q1;
        q1 = (struct qnode *)malloc(sizeof(struct
                                           qnode));
        q1->val = i;
        q1->next = q->front;
        q->front = q1;
        if (count == 0)
            q->rear = q1;
        ++count;

        // printf("%d ",q1->val);
    }
}
int dequeue(struct queue *q)
{
    int val;
    struct qnode *q1, *prev;
    //q1 = (struct qnode *)malloc(sizeof(struct qnode));
    q1 = q->front;
    while (q1->next != NULL)
    {
        prev = q1;
        q1 = q1->next;
    }
    val = q1->val;
    prev->next = NULL;
    free(q1);
    return (val);
}
int main()
{
    int n;
    scanf("%d", &n);
    struct queue *q = initialise();
    enqueue(n, q);
    while (n--)
    {
        int i = 0;
        int arr[10];
        int a = dequeue(q);
        //printf("%d ",a);
        while (a > 0)
        {
            arr[i] = a % 2;
            a = a / 2;
            i++;
        }
        i = i - 1;
        while (i >= 0)
        {
            printf("%d", arr[i]);
            i--;
        }
        // printf("yes");

        printf("\n");
    }
    return 0;
}
