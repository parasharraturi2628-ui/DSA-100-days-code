//Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    struct node *temp;
    int val;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return 0;
    }

    temp = top;
    val = temp->data;
    top = top->next;
    free(temp);

    return val;
}

int evaluate(char exp[])
{
    int i = 0;
    int op1, op2, result;

    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch(exp[i])
            {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            push(result);
        }
        i++;
    }

    return pop();
}

int main()
{
    char exp[100];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    int result = evaluate(exp);

    printf("Result = %d", result);

    return 0;
}
