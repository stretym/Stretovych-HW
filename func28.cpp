#include "func28.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <nlohmann/json.hpp>

// file func28.cpp
// ��������� ������ ������ �� �������
// ������� ������� ��. ������� - 2
// �.�. ���������

// ����� ������

//����� ������������ ����
void Person::set_name(string name) { this->name = name; }

//��������� ����
void Person::print () {
    cout << "Name: " << name << "\t";
    //if (endline) out << endl;
}

//�������� ����
void Person::input() {
    cin >> name;
}

//��������� ���� � ������ json
void Person::ins() {
	j["name"] = name;
}


//����� �������

// ����� �������� ������
// ���������� ����������� ����������� ����� �� ����
vector<int> Student::input_vec() {
    vector<int> v;
    int a;
    while (1) {
        cin >> a;
        if (!a) {
            break;
        }
        v.push_back(a);
    }
    this->marks = v;
    return v;
}

// ����� ������������ ������䳿
void Student::set_stip(float _stip) {
    sch_sh = _stip;
}

// ����� ���������� ���������� ����
float Student::sr() {
    vector<int>::iterator it = marks.begin();
    int i = 0;
    float s = 0;
    while (!(it == marks.end())) {
        s += (*it);
        i++;
        it++;
    }
    this->sredn = (s / i);
    return sredn;
}

// ����� ����������� ������䳿
void Student::stipend() {
    if (sredn >= 4.0 && sredn < 5.0) {
        sch_sh = 30 * sredn;
    }
    else if (sredn == 5.0) {
        sch_sh = 200;
    }
    else {
        sch_sh = 0.0;
    }
}

// ����� �������� �����
void Student::input() {
    Person::input();
    cin >> course;
}

// ��������� � ������� 
void Student::print() {
    Person::print();
    cout << " Average: " << std::setprecision(3) << sr() << "\t" << " Course: " << course << "\t" << " Stipendia: " << std::setprecision(4) << sch_sh << "\t";
    //if (endline) out << endl;
}

// ��������� � ������ json
void Student::ins() {
    Person::ins();
    j["marks"] = marks;
    j["course"] = course;
    j["sredn"] = sredn;
    j["stipendia"] = sch_sh;
}

// �������� ����������
// ������ ����������� ����� �� 0
vector<string> Zachetka::input_prep() {
    vector<string> v;
    string a;
    while (1) {
        cin >> a;
        if (a == "0") {
            break;
        }
        v.push_back(a);
    }
    this->lecturers = v;
    return v;
}

// �������� ����������
// ������ ����������� ����� �� 0
vector<string> Zachetka::input_disc() {
    vector<string> v;
    string a;
    while (1) {
        cin >> a;
        if (a == "0") {
            break;
        }
        v.push_back(a);
    }
    this->discipl = v;
    return v;
}

// ��������� � ������ json
void Zachetka::ins() {
    Student::ins();
    j["disciplines"] = discipl;
    j["lecturers"] = lecturers;
}

// ����� ����������

// ��������� ������
void Employee::print() {
    Person::print();
    cout << ' ' << "Oklad " << oklad << "\t";
}

// �������� ������ � �����
void Employee::input() {
    Person::input();
    cin >> oklad >> stazh;
}

// ��������� � ������ json
void Employee::ins() {
    Person::ins();
    j["oklad"] = oklad;
    j["stazh"] = stazh;
}

// ���� ��������

// ���������� ��������
void Lecturer::cal_s() {
    double h;
    h = oklad + 0.4 * oklad * (double(stazh) / 100);

    if (step == "teacher") {
        this->salary = h * 1.2;
    }
    else if (step == "candidate") {
        this->salary = h * 1.4;
    }
    else if (step == "doctor") {
        this->salary = h * 1.6;
    }
    else
    {
        this->salary = h;
    }
}

// ������� ����. ������
void Lecturer::input() {
    Employee::input();
    cin >> step;
}

// ��������� ������ �� ��������
void Lecturer::print() {
     Employee::print();
     cout << ' ' << " Stepen " << step << "\t" << ' ' << " Salary " << salary << "\t";
 }

// ��������� � ������ json
void Lecturer::ins() {
     Employee::ins();
     j["step"] = step;
     j["salary"] = salary;
 }

// ����� ���������

// �������� ������������
void Specialist::input() {
     Lecturer::input();
     cin >> spec;
 }

// ��������� ������������
void Specialist::print() {
    Lecturer::print();
    cout << " Specialization: " << spec;
}

// // ��������� � ������ json
void Specialist::ins() {
    Lecturer::ins();
    j["specialization"] = spec;
}

// ����� ��� ������ � ������ ��������

//�������� ���������� ��� n ��������
void File_stud::input_stud_information() {
    int n;
    cout << "Input number of students: ";
    cin >> n;
    cout << endl;
    string name;
    vector<int> marks;
    vector<string> preps;
    vector<string> discip;
    int course;

    vector<Zachetka> z;
    nlohmann::json J{};
    for (int i = 0; i < n; i++) {
        Zachetka z0("A", { 1 }, { "i" }, { "y" }, 0);
        cout << "Name: ";
        cin >> name;
        z0.set_name(name);
        cout << endl << "Input marks: ";
        z0.input_vec();
        cout << endl << "Input disciplines: ";
        z0.input_disc();
        cout << endl << "Input lecturers: ";
        z0.input_prep();
        cout << endl << "Input course: ";
        cin >> course;
        z0.set_course(course);
        z0.sr();
        z0.stipend();
        z0.ins();
        //cout << endl << endl << z0.j << endl;
        J.push_back(z0.j);
        z.push_back(z0);
    }
    cout << J << endl;
    ofstream outj;
    outj.open(filename);
    outj << J; //������� json-���������� � ����
    outj.close();
}

// ��������� ������ ��������
void File_stud::add_stud_information() {
    string name;
    vector<int> marks;
    vector<string> preps;
    vector<string> discip;
    int course;

    vector<Zachetka> z;
    nlohmann::json J{};
    ifstream inj;
    inj.open(filename);
    inj >> J; // ���������� � json
    inj.close();

    for (int i = 0; i < 1; i++) {
        Zachetka z0("A", { 1 }, { "i" }, { "y" }, 0);
        cout << "Name: ";
        cin >> name;
        z0.set_name(name);
        cout << endl << "Input marks: ";
        z0.input_vec();
        cout << endl << "Input disciplines: ";
        z0.input_disc();
        cout << endl << "Input lecturers: ";
        z0.input_prep();
        cout << endl << "Input course: ";
        cin >> course;
        z0.set_course(course);
        z0.sr();
        z0.stipend();
        z0.ins();
        //cout << endl << endl << z0.j << endl;
        J.push_back(z0.j);
        z.push_back(z0);
    }
    //cout << J << endl;
    ofstream outj;
    outj.open(filename);
    outj << J; //������� json-���������� � ���� � ����� ���������
    outj.close();
}

// ��������� ��������
// ��� �� �������� �����, ������ �������� �����
void File_stud::del_stud(string name) {
    nlohmann::json J{};
    ifstream inj;
    inj.open(filename);
    inj >> J;
    inj.close();
    nlohmann::json::iterator it = J.begin();
    //cout << J[2] << endl;
    nlohmann::json J1{};
    while (!(it == J.end())) {
        if (!((*it)["name"] == name)) {
            J1.push_back(*it);
        }
        it++;
    }
    ofstream outj;
    outj.open(filename);
    outj << J1; // ��������� � json ��� ��� ��������
    outj.close();
}

// ��������� ������� ��'���� �������� � ����� ��� �������� ������
vector<Zachetka> File_stud::get_stud() {
    nlohmann::json J{};
    ifstream inj;
    inj.open(filename);
    inj >> J;
    inj.close();
    vector<Zachetka> Z;
    nlohmann::json::iterator it = J.begin();

    while (!(it == J.end())) {
        Zachetka z{ (*it)["name"], (*it)["marks"], (*it)["disciplines"], (*it)["lecturers"], (*it)["course"] };
        z.set_stip((*it)["stipendia"]);
        //cout << z.get_course() << endl;
        Z.push_back(z);
        it++;
    }
    return Z;
}


// ����� ��� ������ � ������ ����������

// ����� �������� ���������� ��� n ����������
void File_lect::input_lect() {
    int n;
    cout << "Input number of lecturers: ";
    cin >> n;
    cout << endl;
    nlohmann::json J{};

    string name;
    string step;
    for (int i = 0; i < n; i++) {
        Specialist s0("", 0, 0, "", "");
        cout << "Name: ";
        cin >> name;
        s0.set_name(name);
        cout << endl << "Input oklad: ";
        cin >> s0.oklad;
        cout << endl << "Input time of work: ";
        cin >> s0.stazh;
        cout << endl << "Input specialization: ";
        cin >> s0.spec;
        cout << endl << "Input stepen: ";
        cin >> step;
        s0.set_step(step);
        s0.cal_s();
        s0.ins();
        //cout << endl << endl << s0.j << endl;
        J.push_back(s0.j);
    }
    ofstream outj;
    outj.open(filename);
    outj << J << endl;
    outj.close();
}

// ��������� ������ ���������
void File_lect::add_lect_info() {
    nlohmann::json J{};
    ifstream inj;
    inj.open(filename);
    inj >> J;
    inj.close();

    string name;
    string step;
    for (int i = 0; i < 1; i++) {
        Specialist s0("", 0, 0, "", "");
        cout << "Name: ";
        cin >> name;
        s0.set_name(name);
        cout << endl << "Input oklad: ";
        cin >> s0.oklad;
        cout << endl << "Input time of work: ";
        cin >> s0.stazh;
        cout << endl << "Input specialization: ";
        cin >> s0.spec;
        cout << endl << "Input stepen: ";
        cin >> step;
        s0.set_step(step);
        s0.cal_s();
        s0.ins();
        //cout << endl << endl << s0.j << endl;
        J.push_back(s0.j);
    }
    //cout << J << endl;
    ofstream outj;
    outj.open(filename);
    outj << J;
    outj.close();
}

// ��������� ���������
void File_lect::del_lect(string name) {
    nlohmann::json J{};
    ifstream inj;
    inj.open(filename);
    inj >> J;
    inj.close();
    nlohmann::json::iterator it = J.begin();
    //cout << J[2] << endl;
    nlohmann::json J1{};
    while (!(it == J.end())) {
        if (!((*it)["name"] == name)) {
            J1.push_back(*it);
        }
        it++;
    }
    ofstream outj;
    outj.open(filename);
    outj << J1;
    outj.close();
}

// ��������� ������� ��'���� ��������� � ����� ��� �������� ������
vector<Specialist> File_lect::get_lect() {
    nlohmann::json J{};
    ifstream inj;
    inj.open(filename);
    inj >> J;
    inj.close();
    vector<Specialist> Z;
    nlohmann::json::iterator it = J.begin();

    while (!(it == J.end())) {
        Specialist z{ (*it)["name"], (*it)["oklad"], 50, (*it)["step"], (*it)["specialization"] };
        //cout << z.get_course() << endl;
        Z.push_back(z);
        it++;
    }
    return Z;
}

// ������� �������� ����� � ������ � �����
bool poisk(std::vector<std::string> N, std::string prep) {
    std::vector<std::string>::iterator it = N.begin();
    bool result = false;
    while (it != N.end()) {
        if ((*it) == prep) {
            result = true;
        }
        it++;
    }
    return result;
}

// ��������� ����� ��� ��������, � ���� ���� ����� ��������
void st() {
    std::string prepod;
    std::cout << "Input name of lecturer: ";
    std::cin >> prepod;
    std::cout << std::endl;

    std::vector<Zachetka> Z;
    File_stud Fs{ "stud_info_28.txt" };
    Z = Fs.get_stud();

    std::vector<Zachetka>::iterator it = Z.begin();
    while (it != Z.end()) {

        if (poisk((*it).lecturers, prepod)) {
            std::cout << "Name: " << (*it).get_name() << "\t" << std::setprecision(3) << "  Sredn: " << (*it).get_sredn() << endl;
        }

        it++;
    }
}

