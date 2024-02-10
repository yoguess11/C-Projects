#include <stdio.h>
#include <stdlib.h>


void parse_input(char *input, double *oper1, double *oper2, char *op) {
    int index = -1;
    uint8_t third_place = 0;
    for (int i = 0; *(input+i) != '\0'; i++) {
        char chr = *(input+i);
        int is_digit = (chr - '0' >= 0 && chr - '0' <= 9);

        if (is_digit && index == -1) {
            *oper1 = *oper1 * 10 + (chr - '0');
        } else if (chr == '+' || chr == '-' || chr == '*' || chr == '/') {
            if (index == -1) {
                *op = chr;
                index = i;
            } else {
                fprintf(stderr, "Multiple operands exist. Ensure that you follow the syntax\n");
                exit(1);
            }
        } else if (is_digit && index != -1) {
            *oper2 = *oper2 * 10 + (chr - '0');
            third_place = 1;
        } else if (((chr == '\t' || chr == ' ') && index == -1 && third_place == 0) || //First place space(s)
                ((chr == '\t' || chr == ' ') && index != -1 && third_place == 0) ||  //Second place space(s)
                ((chr == '\t' || chr == ' ' || chr == '\n' || chr == '\r') && index != -1 && third_place == 1)) {  //Third place space(s)
            //Fine if this is the case 
        } else {
            printf("At i=%d, char %d", i, (int)chr);
            fprintf(stderr, "Sorry some syntax error occured, please try again!");
            exit(1);
        }
    }

}

double compute_results(double oper1, char op, double oper2) {
    double result;
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
            result = -1;
            fprintf(stderr, "Unsupported Operation as of yet! Please try a valid operation (+,-,*,/)!\n");
            exit(1);
    }
    return result;
 
}

int main() {
    
    //Allocate memory for input
    const int INPUT_SIZE = 1000;
    char op;
    double oper1 = 0, oper2 = 0, result = 0;
    char *input = (char *) malloc(INPUT_SIZE);
    if (input == NULL) {
        fprintf(stderr, "Memory allocation failed. Please try again/free up memory\n");
        exit(1);
    }
    printf("Definition: OPERATOR = [0-9], OPERAND=[+,-,*,/]\n");
    printf("Enter your prompt in the following order: OPERATOR OPERAND OPERATOR\n");

    //Get Input
    input = fgets(input, INPUT_SIZE, stdin);
    if (input == NULL) {
        fprintf(stderr, "Unable to read the user input\n");
        exit(1);
    }
    printf("Your input is: %s\n", input);
    parse_input(input, &oper1, &oper2, &op);
    result = compute_results(oper1, op, oper2);
    
    printf("(*************************************************************)\n");
    printf("Your oper1: %.2lf , op: %c , opr2: %.2lf\n", oper1, op, oper2);
    
    printf("Answer is %.2lf.\n", result);
    return 0;

}

   