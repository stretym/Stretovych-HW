#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Sigmoid function: f(x) = (1 + e^(-x))^-1
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Derivative of the sigmoid function: f'(x) = sigmoid(x) * (1 - sigmoid(x))
double sigmoidDerivative(double x) {
    double sig = sigmoid(x);
    return sig * (1.0 - sig);
}

int main(void) {
    double inputValue;

    printf("Enter a value for x: ");
    scanf("%lf", &inputValue);

    // Calculate the value of the sigmoid function
    double result = sigmoid(inputValue);

    // Calculate the derivative of the sigmoid function
    double derivativeResult = sigmoidDerivative(inputValue);

    // Display the results
    printf("sigmoid(%lf) = %lf\n", inputValue, result);
    printf("sigmoid_derivative(%lf) = %lf\n", inputValue, derivativeResult);

    return 0;
}

