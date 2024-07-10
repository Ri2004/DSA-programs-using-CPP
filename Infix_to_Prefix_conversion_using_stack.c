// infix to prefix using stack
#include <stdio.h>
#include <string.h>
#define MAX 50

char infix_exp[MAX], prefix_exp[MAX], stack[MAX];
int top = -1;

int isempty()
{
    return top == -1;
}

int isfull()
{
    return top == MAX - 1;
}

int precedence(char op)
{
    if (op == '^')
    {
        return 3;
    }

    else if (op == '*' || op == '/')
    {
        return 2;
    }

    else if (op == '+' || op == '-')
    {
        return 1;
    }

    else
    {
        return -1;
    }
}

void infixToPrefix(char infix[])
{
    int i, j;
    char prefix_rev[MAX];

    for (i = 0, j = 0; i < strlen(infix); i++)
    {
        if (!isfull() && infix[i] == ')')
        {
            stack[++top] = infix[i];
        }

        else if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
        {
            prefix_exp[j++] = infix[i];
        }

        else if (infix[i] == '(')
        {
            while (!isempty() && stack[top] != ')')
            {
                prefix_exp[j++] = stack[top--];
            }
            top--;
        }

        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            while (!isempty() && precedence(stack[top]) > precedence(infix[i]))
            {
                prefix_exp[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }
    while (top > -1)
    {
        prefix_exp[j++] = stack[top--];
    }
    strrev(prefix_exp);

    puts(prefix_exp);
}

int main()
{
    int i, j;

    printf("Enter an Infix Expression.\n");
    gets(infix_exp);

    infixToPrefix(strrev(infix_exp));
}