#include <iostream>
#include <vector>
#include <string>

class Person {
public:
    Person() {}

    Person(const std::string& name, const std::string& gender, int age)
        : name(name), gender(gender), age(age) {}

    virtual ~Person() {}

    virtual void displayDetails() const {
        std::cout << "ПІБ: " << name << "\n"
                  << "Стать: " << gender << "\n"
                  << "Вік: " << age << "\n";
    }

    const std::string& getUniversity() const {
        return university;
    }

    virtual void setUniversity(const std::string& university) {
        this->university = university;
    }

protected:
    std::string name;
    std::string gender;
    int age;
    std::string university;
};

class Student : public Person {
public:
    Student() {}

    Student(const std::string& name, const std::string& gender, int age,
            int course, const std::string& group, const std::string& university)
        : Person(name, gender, age), course(course), group(group) {
        setUniversity(university);
    }

    void displayDetails() const override {
        Person::displayDetails();
        std::cout << "Курс: " << course << "\n"
                  << "Група: " << group << "\n"
                  << "ВУЗ: " << getUniversity() << "\n";
    }

private:
    int course;
    std::string group;
};

class Teacher : public Person {
public:
    Teacher() {}

    Teacher(const std::string& name, const std::string& gender, int age,
            const std::string& university, const std::string& position, double salary)
        : Person(name, gender, age), position(position), salary(salary) {
        setUniversity(university);
    }

    void displayDetails() const override {
        Person::displayDetails();
        std::cout << "Посада: " << position << "\n"
                  << "Заробітня плата: " << salary << "\n"
                  << "ВУЗ: " << getUniversity() << "\n";
    }

private:
    std::string position;
    double salary;
};

class GraduateStudent : public Student, public Teacher {
public:
    GraduateStudent(const std::string& name, const std::string& gender, int age,
                    int course, const std::string& group, const std::string& university,
                    const std::string& position, double salary, const std::string& researchTopic)
        : Student(name, gender, age, course, group, university),
          Teacher(name, gender, age, university, position, salary),
          researchTopic(researchTopic) {}

    void displayDetails() const override {
        Student::displayDetails();
        std::cout << "Тема дослідження: " << researchTopic << "\n";
    }

private:
    std::string researchTopic;
};

int main() {
    std::vector<Person*> people;

    try {
        people.push_back(new Student("Іван Іванов", "Чоловіча", 20, 2, "Група 101", "Університет 1"));
        people.push_back(new Teacher("Марія Петренко", "Жіноча", 35, "Університет 2", "Доцент", 3000.0));
        people.push_back(new GraduateStudent("Петро Сидоров", "Чоловіча", 28, 3, "Група 201",
                                            "Університет 3", "Асистент", 2500.0, "Тема 1"));
    } catch (const std::exception& e) {
        std::cerr << "Помилка при створенні об'єкта: " << e.what() << std::endl;
        // Обробка помилок при створенні об'єкта
    }

    for (const auto& person : people) {
        person->displayDetails();
        std::cout << "\n-----------------\n";
    }

    // Очистка пам'яті
    for (const auto& person : people) {
        delete person;
    }

    return 0;
}
