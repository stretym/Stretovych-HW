#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Person {
    std::string name;
    unsigned byear;

public:
    int input() {
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter birth year: ";
        std::cin >> byear;
        return 0;
    }
    const std::string& getName() const {
        return name;
    }

    void show() {
        std::cout << "Name: " << name << ", Birth Year: " << byear << std::endl;
    }

    friend std::istream& operator>>(std::istream& is, Person& person) {
        is >> person.name >> person.byear;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << "Name: " << person.name << ", Birth Year: " << person.byear;
        return os;
    }
};

class Familiar : public Person {
    std::string phoneNumber;

public:
    int input() {
        Person::input();
        std::cout << "Enter phone number: ";
        std::cin >> phoneNumber;
        return 0;
    }

    void show() {
        Person::show();
        std::cout << "Phone Number: " << phoneNumber << std::endl;
    }

    friend std::istream& operator>>(std::istream& is, Familiar& familiar) {
        is >> static_cast<Person&>(familiar) >> familiar.phoneNumber;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Familiar& familiar) {
        os << static_cast<const Person&>(familiar) << ", Phone Number: " << familiar.phoneNumber;
        return os;
    }

    const std::string& getPhoneNumber() const {
        return phoneNumber;
    }

    void setPhoneNumber(const std::string& newNumber) {
        phoneNumber = newNumber;
    }
};

class PhoneDirectory {
    std::vector<Familiar> directory;

public:
    int createDirectory(const std::string& fileName) {
        std::ifstream file(fileName);

        if (!file.is_open()) {
            std::cerr << "Error: Unable to open the file.\n";
            return 1;
        }

        Familiar person;
        while (file >> person) {
            directory.push_back(person);
        }

        file.close();
        return 0;
    }

    int addRecord(const Familiar& person) {
        if (directory.size() >= 100) {
            std::cerr << "Error: Phone directory is full.\n";
            return 1;
        }

        directory.push_back(person);
        return 0;
    }

    std::string searchPhoneNumber(const std::string& name) const {
        for (const auto& person : directory) {
            if (person.getName() == name) {
                return person.getPhoneNumber();
            }
        }
        return "Not found";
    }

    int replacePhoneNumber(const std::string& name, const std::string& newNumber) {
        for (auto& person : directory) {
            if (person.getName() == name) {
                person.setPhoneNumber(newNumber);
                return 0;
            }
        }
        std::cerr << "Error: Person not found.\n";
        return 1;
    }

    void saveToFile(const std::string& fileName) const {
        std::ofstream file(fileName);

        if (!file.is_open()) {
            std::cerr << "Error: Unable to open the file.\n";
            return;
        }

        for (const auto& person : directory) {
            file << person << '\n';
        }

        file.close();
    }

    void printAllFamiliarNamesWithPhoneNumbers() const {
        std::cout << "\n#####################\nAll familiars phone numbers\n";
        for (const auto& person : directory) {
            std::cout << "Name: " << person.getName() << ", Phone Number: " << person.getPhoneNumber() << std::endl;
        }
        std::cout << "#####################\n";
    }
};

int main() {
    PhoneDirectory phoneBook;
    //phoneBook.createDirectory("input.txt");
    Familiar newPerson;
    newPerson.input();
    phoneBook.addRecord(newPerson);
    std::string searchName;
    std::cout << "Enter name to search for: ";
    std::cin >> searchName;
    std::cout << "Phone Number: " << phoneBook.searchPhoneNumber(searchName) << std::endl;
    std::string replaceName, newNumber;
    std::cout << "Enter name to replace phone number: ";
    std::cin >> replaceName;
    std::cout << "Enter new phone number: ";
    std::cin >> newNumber;
    phoneBook.replacePhoneNumber(replaceName, newNumber);
    phoneBook.printAllFamiliarNamesWithPhoneNumbers();
    phoneBook.saveToFile("phonebook.txt");

    return 0;
}