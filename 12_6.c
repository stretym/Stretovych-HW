#include <stdio.h>
#include <math.h>

double calculate_function_value(double x) {
    // Функція (о0)
    // Якщо значення виходить за межі області, повертаємо NaN (Not a Number)
    if (x < -709 || x > 709) {
        return NAN;
    }

    return exp(x) / (pow(x, 2) + 1);
}

int main() {
    char input[1000];
    printf("Введіть числа, розділені комою: ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, ",");
    while (token != NULL) {
        double x;
        sscanf(token, "%lf", &x);

        double function_value = calculate_function_value(x);

        if (isnan(function_value)) {
            printf("None\n");
        } else {
            printf("Decimal: %.5lf, Scientific: %.5e\n", function_value, function_value);
        }

        token = strtok(NULL, ",");
    }

    return 0;
}
