void evaluation(char expr[], char result[]) {
    convert(expr, result);
     i=0;
    char x = next_token(result);  

    while (x != '\0') {
        if (isdigit(x)) {
            push(x);
        } else {
            int val2 = pop() - '0';
            int val1 = pop() - '0';
            int eval_result = 0;

            switch (x) {
                case '+':
                    eval_result = val1 + val2;
                    break;
                case '-':
                    eval_result = val1 - val2;
                    break;
                case '*':
                    eval_result = val1 * val2;
                    break;
                case '/':
                    if (val2 == 0) {
                        printf("Division by zero not allowed\n");
                        return;
                    }
                    eval_result = val1 / val2;
                    break;
                case '^': {
                    int res = 1;
                    for (int j = 0; j < val2; j++) {
                        res *= val1;
                    }
                    eval_result = res;
                    break;
                }
                default:
                    printf("Unknown operator: %c\n", x);
                    return;
            }
            push(eval_result + '0'); 
        }
        x = next_token(result);
    }

    int postresult = pop() - '0';
    printf("Result of expression = %d\n", postresult);
}