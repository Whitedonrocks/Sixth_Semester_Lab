#include <stdio.h>

int main()
{
    char result[20], op1[20], op2[20], op;
    char equal;
    
    printf("Enter intermediate code (x=y+z): ");
    scanf("%[^=]=%[^+*/-]%c%s", result, op1, &op, op2);

    printf("\nTarget Code:\n");

    printf("MOV R0, %s\n", op1);

    switch(op)
    {
        case '+':
            printf("ADD R0, %s\n", op2);
            break;

        case '-':
            printf("SUB R0, %s\n", op2);
            break;

        case '*':
            printf("MUL R0, %s\n", op2);
            break;

        case '/':
            printf("DIV R0, %s\n", op2);
            break;

        default:
            printf("Invalid operator.\n");
            return 1;
    }

    printf("MOV %s, R0\n", result);

    return 0;
}