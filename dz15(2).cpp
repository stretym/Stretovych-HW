#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

class Goods {
public:
    Goods() {}
    Goods(const std::string& name, const std::string& article, const std::string& unit,
          double price, const std::string& supplyDate)
        : name(name), article(article), unit(unit), price(price), supplyDate(supplyDate) {}

    virtual ~Goods() {}

    virtual void displayDetails() const {
        std::cout << "Назва: " << name << "\n"
                  << "Артикул: " << article << "\n"
                  << "Одиниця виміру: " << unit << "\n"
                  << "Вартість: " << price << "\n"
                  << "Дата постачання: " << supplyDate << "\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const Goods& goods) {
        goods.displayDetails();
        return os;
    }

    const std::string& getName() const {
        return name;
    }

    virtual double getDiscount() const {
        return 0.0;  // Базовий клас не надає знижки
    }

private:
    std::string name;
    std::string article;
    std::string unit;
    double price;
    std::string supplyDate;
};

class Toys : public Goods {
public:
    Toys(const std::string& name, const std::string& article, const std::string& unit,
         double price, const std::string& supplyDate, int ageLimit)
        : Goods(name, article, unit, price, supplyDate), ageLimit(ageLimit) {}

    void displayDetails() const override {
        Goods::displayDetails();
        std::cout << "Вікові обмеження: " << ageLimit << "\n";
    }

private:
    int ageLimit;
};

class Food : public Goods {
public:
    Food(const std::string& name, const std::string& article, const std::string& unit,
         double price, const std::string& supplyDate, const std::string& expirationDate)
        : Goods(name, article, unit, price, supplyDate), expirationDate(expirationDate) {}

    void displayDetails() const override {
        Goods::displayDetails();
        std::cout << "Термін придатності: " << expirationDate << "\n";
    }

    double getDiscount() const override {
        // Знижка 20% для товарів, термін придатності яких менше 5 днів
        if (calculateDaysRemaining() < 5) {
            return 0.2;
        }
        return 0.0;
    }

private:
    std::string expirationDate;

    int calculateDaysRemaining() const {
        // Простий приклад для обчислення різниці між поточною датою та терміном придатності
        // Реальна реалізація може знадобитися для роботи з реальними датами
        return 5;  // В цьому прикладі завжди повертаємо 5 днів
    }
};

class Electronics : public Goods {
public:
    Electronics(const std::string& name, const std::string& article, const std::string& unit,
                double price, const std::string& supplyDate, bool warranty, int warrantyPeriod)
        : Goods(name, article, unit, price, supplyDate), warranty(warranty), warrantyPeriod(warrantyPeriod) {}

    void displayDetails() const override {
        Goods::displayDetails();
        std::cout << "Гарантія: " << (warranty ? "Так" : "Ні") << "\n";
        if (warranty) {
            std::cout << "Термін гарантії: " << warrantyPeriod << " міс.\n";
        }
    }

    double getDiscount() const override {
        // Знижка 20% для товарів, термін гарантії на які менше 5 місяців
        if (warranty && warrantyPeriod < 5) {
            return 0.2;
        }
        return 0.0;
    }

private:
    bool warranty;
    int warrantyPeriod;
};

class Inventory {
public:
    void addGoods(const Goods& goods) {
        goodsList.push_back(goods);
    }

    void saveToFile(const std::string& fileName) const {
        std::ofstream outFile(fileName, std::ios::binary);

        if (!outFile.is_open()) {
            std::cerr << "Не вдалося відкрити файл для запису." << std::endl;
            return;
        }

        for (const auto& goods : goodsList) {
            outFile.write(reinterpret_cast<const char*>(&goods), sizeof(Goods));
        }

        outFile.close();
    }

    void searchByName(const std::string& name) const {
        std::cout << "Пошук за назвою \"" << name << "\":\n";

        for (const auto& goods : goodsList) {
            if (goods.getName() == name) {
                std::cout << goods << "\n";
            }
        }
    }

    template <typename T>
    void searchByType() const {
        std::cout << "Пошук за типом \"" << typeid(T).name() << "\":\n";

        for (const auto& goods : goodsList) {
            if (dynamic_cast<const T*>(&goods) != nullptr) {
                std::cout << goods << "\n";
            }
        }
    }

    void displayAllGoods() const {
        std::cout << "Список всіх товарів:\n";

        for (const auto& goods : goodsList) {
            std::cout << goods << "\n";
        }
    }

    void makeOrder(const std::vector<std::string>& orderedItems) {
        double totalCost = 0.0;
        std::vector<Goods> remainingGoods;

        for (const auto& goods : goodsList) {
            auto it = std::find(orderedItems.begin(), orderedItems.end(), goods.getName());
            if (it != orderedItems.end()) {
                totalCost += goods.getPrice() * (1.0 - goods.getDiscount());
            } else {
                remainingGoods.push_back(goods);
            }
        }

        std::cout << "Сумарна вартість замовлення: " << totalCost << " грн\n";

        goodsList = remainingGoods;  // Видалення замовлених товарів
    }

    void applyDiscounts() {
        for (auto& goods : goodsList) {
            goods.setPrice(goods.getPrice() * (1.0 - goods.getDiscount()));
        }
    }

private:
    std::vector<Goods> goodsList;
};

int main() {
    // Створюємо екземпляр класу Inventory
    Inventory inventory;

    // Додаємо товари до інвентарю
    inventory.addGoods(Toys("Лялька", "A123", "шт", 100.0, "01.01.2023", 3));
    inventory.addGoods(Food("Молоко", "B456", "л", 30.0, "01.01.2023", "05.01.2023"));
    inventory.addGoods(Electronics("Смартфон", "C789", "шт", 5000.0, "01.01.2023", true, 6));
    inventory.addGoods(Toys("Машинка", "D321", "шт", 50.0, "01.01.2023", 5));
    inventory.addGoods(Food("Хліб", "E654", "шт", 10.0, "01.01.2023", "10.01.2023"));
    inventory.addGoods(Electronics("Ноутбук", "F987", "шт", 2000.0, "01.01.2023", true, 3));

    // Зберігаємо товари у бінарний файл
    inventory.saveToFile("inventory.dat");

    // Пошук товару за назвою
    inventory.searchByName("Молоко");

    // Пошук товару за типом (Іграшки)
    inventory.searchByType<Toys>();

    // Виведення всіх товарів
    inventory.displayAllGoods();

    // Оформлення замовлення
    std::vector<std::string> orderItems = {"Лялька", "Молоко", "Смартфон"};
    inventory.makeOrder(orderItems);

    // Застосування знижок
