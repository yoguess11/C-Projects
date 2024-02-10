#include <stdio.h>

int main() {
    
    //Allocate memory for input
    const int INPUT_SIZE = 1000;
    char op;
    double oper1, oper2, result;
    char *input = (char *) malloc(INPUT_SIZE);
    if (input == NULL) {
        fprintf(stderr, "Memory allocation failed. Please try again/free up memory");
    }
    printf("Definition: OPERATOR = [0-9], OPERAND=[+,-,*,/]");
    printf("Enter your prompt in the following order: OPERATOR OPERAND OPERATOR");

    //Get Input
    input = fgets(input, INPUT_SIZE, stdin);
    if (input == NULL) {
        fprintf(stderr, "Unable to read the user input");
    }
    printf("Enter the operation(+,-,/,*) to run: ");
    //space before %c to capture previous \r in stdin
    int input_2 = scanf("%c", &op);
    printf("input_2 is %d", input_2);
    if (input_2 != 1) {
        fprintf(stderr, "Error occured while getting the operation, please try again");
    }
    while (getchar() != '\n' && getchar() != EOF);

    printf("Enter the second operand: ");
    int input_3 = scanf("%lf", &oper2);
    while (getchar() != '\n' && getchar() != EOF);
    printf("input_3 is %d", input_3);
    if (input_3 != 1) {
        fprintf(stderr, "Error occured while getting the operation, please try again");
    }

    switch (op) {
        case '+':
            result = oper1 + oper2;
            break;
        case '-':
            result = oper1 - oper2;
            break;
        case '*':
            result = oper1 * oper2;
            break;
        case '/':
            result = oper1 / oper2;
            break;
        default:
            fprintf(stderr, "Unsupported Operation as of yet! Please try a valid operation (+,-,*,/)!\n");
            break;
    }
    printf("Answer is %lf.\n", result);
    return 0;

}

   