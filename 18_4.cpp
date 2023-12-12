#include <iostream>
#include <stdexcept>

template <typename T>
class Mediana {
public:
    Mediana() : size(0) {}

    Mediana(const T* array, int arraySize) : size(0) {
        for (int i = 0; i < arraySize; ++i) {
            push(array[i]);
        }
    }

    void push(const T& element) {
        if (size >= 100) {
            throw std::overflow_error("Перевищено обмеження кількості елементів (100)");
        }

        int i = size - 1;
        while (i >= 0 && element < data[i]) {
            data[i + 1] = data[i];
            --i;
        }

        data[i + 1] = element;
        ++size;
    }

    T pop(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Невірний індекс");
        }

        T element = data[index];

        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }

        --size;
        return element;
    }

    T median() const {
        if (size % 2 == 0) {
            return (data[size / 2 - 1] + data[size / 2]) / 2;
        } else {
            return data[size / 2];
        }
    }

private:
    T data[100];
    int size;
};

int main() {
    try {
        Mediana<int> medianInt;
        medianInt.push(5);
        medianInt.push(2);
        medianInt.push(8);

        std::cout << "Медіана для цілих чисел: " << medianInt.median() << std::endl;

        Mediana<double> medianDouble;
        medianDouble.push(3.5);
        medianDouble.push(1.7);
        medianDouble.push(6.2);

        std::cout << "Медіана для дійсних чисел: " << medianDouble.median() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}
