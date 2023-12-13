#include <iostream>
#include <vector>

struct Customer {
    int number;
    double serviceTime;
    double totalTimeInQueue;
};

void calculateQueueTimes(const std::vector<double>& serviceTimes, std::vector<Customer>& customers) {
    double totalTime = 0.0;
    double minTime = std::numeric_limits<double>::max();
    double maxTime = 0.0;
    int minCustomer = -1;
    int maxCustomer = -1;

    for (int i = 0; i < serviceTimes.size(); ++i) {
        totalTime += 1;
        customers[i].number = i + 1;
        customers[i].serviceTime = serviceTimes[i];
        customers[i].totalTimeInQueue = totalTime + serviceTimes[i];

        if (customers[i].totalTimeInQueue < minTime) {
            minTime = customers[i].totalTimeInQueue;
            minCustomer = i;
        }

        if (customers[i].totalTimeInQueue > maxTime) {
            maxTime = customers[i].totalTimeInQueue;
            maxCustomer = i;
        }
    }

    std::cout << "Customer with the least time in queue: C" << customers[minCustomer].number << " (" << minTime << " minutes)\n";
    std::cout << "Customer with the most time in queue: C" << customers[maxCustomer].number << " (" << maxTime << " minutes)\n";
}

int main() {
    int n;
    std::cout << "Enter the number of customers: ";
    std::cin >> n;

    std::vector<double> serviceTimes(n);
    std::cout << "Enter service times for each customer:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> serviceTimes[i];
    }

    std::vector<Customer> customers(n);
    calculateQueueTimes(serviceTimes, customers);

    return 0;
}