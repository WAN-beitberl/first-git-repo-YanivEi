#include <stdio.h>

double Calculator(double num1, double num2, char op){
    if (op == '+'){
        return (num1+num2);
    }
    else if (op == '-'){
        return (num1-num2);
    }
    else if (op == 'x'|| op == '*'){
        return (num1*num2);
    }
    else if (op == '/'){
        return (num1/num2);
    }
    return -1;
}

int main(){
    double num1,num2;
    char op;
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter operation: ");
    scanf(" %c", &op);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    double result = Calculator(num1,num2,op);
    if(result != -1){
        printf("Answer is: %f", result);
    }
    else{
        printf("Invalid operator");
    }

    return 0;
}

