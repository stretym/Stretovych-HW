#include <iostream>
#include <vector>
#include <string>

class Person {
public:
    std::string name;
    char gender;
    int age;

    Person(const std::string& name, char gender, int age)
        : name(name), gender(gender), age(age) {}

    virtual void input() {
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter gender (M/F): ";
        std::cin >> gender;
        std::cout << "Enter age: ";
        std::cin >> age;
    }

    virtual void output() const {
        std::cout << "Name: " << name << ", Gender: " << gender << ", Age: " << age << std::endl;
    }

    std::string getUniversity() {
        return NULL;
    }
};

class Student : virtual public Person {
public:
    int course;
    std::string group;
    std::string university;

    Student(const std::string& name, char gender, int age, int course, const std::string& group, const std::string& university)
        : Person(name, gender, age), course(course), group(group), university(university) {}

    void input() override {
        Person::input();
        std::cout << "Enter course: ";
        std::cin >> course;
        std::cout << "Enter group: ";
        std::cin >> group;
        std::cout << "Enter university: ";
        std::cin >> university;
    }

    void output() const override {
        Person::output();
        std::cout << "Course: " << course << ", Group: " << group << ", University: " << university << std::endl;
    }

    std::string getUniversity()  {
        return university;
    }
};

class Teacher : virtual public Person {
public:
    std::string university;
    std::string position;
    double salary;

    Teacher(const std::string& name, char gender, int age, const std::string& university, const std::string& position, double salary)
        : Person(name, gender, age), university(university), position(position), salary(salary) {}

    void input() override {
        Person::input();
        std::cout << "Enter university: ";
        std::cin >> university;
        std::cout << "Enter position: ";
        std::cin >> position;
        std::cout << "Enter salary: ";
        std::cin >> salary;
    }

    void output() const override {
        Person::output();
        std::cout << "University: " << university << ", Position: " << position << ", Salary: " << salary << std::endl;
    }

    std::string getUniversity() {
        return university;
    }
};

class Postgraduate : public Student, public Teacher {
public:
    Postgraduate(const std::string& name, char gender, int age, int course, const std::string& group,
        const std::string& university,
        const std::string& position, double salary)
        : Person(name, gender, age), Student(name, gender, age, course, group, university),
        Teacher(name, gender, age, university, position, salary) {}

    void output() const override {
        Student::output();
        Teacher::output();
    }
    void input() override {
        std::cin >> course;
        std::cin >> group;
        Teacher::input(); 
    }

    std::string getUniversity() {
        return Teacher::university;
    }
};

int main() {
    const int numPeople = 3;
    std::vector<Person*> people;

    for (int i = 0; i < numPeople; i++) {
        char personType;
        std::cout << "Enter person type (S/T/P): ";
        std::cin >> personType;

        if (personType == 'S') {
            people.push_back(new Student("", ' ', 0, 0, "", ""));
        } else if (personType == 'T') {
            people.push_back(new Teacher("", ' ', 0, "", "", 0.0));
        } else if (personType == 'P') {
            people.push_back(new Postgraduate("", ' ', 0, 0, "", "", "", 0.0));
        } else {
            std::cerr << "Invalid person type entered." << std::endl;
            i--;
        }

        people.back()->input();
    }

    for (const auto& person : people) {
      //  person->output();
        std::cout<<person->getUniversity() << std::endl;
    }

    for (const auto& person : people) {
        delete person;
    }

    return 0;
}