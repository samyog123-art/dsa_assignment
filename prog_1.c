#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1) {
        top++;
        stack[top] = ch;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int isBalanced(char exp[]) {
    int i = 0;
    char temp;

    while (exp[i] != '\0') {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }

        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1)
                return 0;

            temp = pop();

            if ((exp[i] == ')' && temp != '(') ||
                (exp[i] == '}' && temp != '{') ||
                (exp[i] == ']' && temp != '['))
                return 0;
        }
        i++;
    }

    if (top == -1)
        return 1;
    else
        return 0;
}

int main() {
    char expression[100];

    printf("Enter expression: ");
    gets(expression);

    if (isBalanced(expression))
        printf("Expression has balanced parentheses\n");
    else
        printf("Expression has unbalanced parentheses\n");

    return 0;
}
