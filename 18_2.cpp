#include <iostream>
#include <vector>

template <typename T>
class MyStack {
private:
    std::vector<T> elements;

public:
    void push(const T& value) {
        elements.push_back(value);
    }

    T pop() {
        if (!elements.empty()) {
            T value = elements.back();
            elements.pop_back();
            return value;
        }
        else {
            throw std::out_of_range("Stack is empty");
        }
    }

    bool isEmpty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

template <typename T>
size_t inputArrayAndReturnSum(MyStack<T>& resultStack) {
    T number;
    size_t count = 0;

    std::cout << "Enter integers (enter 0 to stop):" << std::endl;

    do {
        std::cin >> number;
        if (number != 0) {
            resultStack.push(number);
            count++;
        }
    } while (number != 0);

    return count;
}

int main() {
    MyStack<int> resultStack;

    size_t count = inputArrayAndReturnSum(resultStack);

    std::cout << "Number of elements: " << count << std::endl;
    std::cout << "Result Stack Contents:" << std::endl;

    while (!resultStack.isEmpty()) {
        std::cout << resultStack.pop() << " ";
    }

    return 0;
}