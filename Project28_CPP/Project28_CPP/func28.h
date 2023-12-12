#pragma once
#ifndef FUNC28_H
#define FUNC28_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <nlohmann/json.hpp>

// file func28.cpp
// ��������� ������ ������ �� �������
// ������� ������� ��. ������� - 2
// �.�. ���������


using namespace std;

// ����� ������ - �������
class Person {

private:

    string name; //��'� ������

public:

    nlohmann::json j{}; //��'��� ��� ������ � json

    //�����������
    Person(string _name) : name(_name) {}

    //�������� ��'�
    string get_name() { return name; }

    //���������� ��'�
    void set_name(string name);

    //��������
    virtual void input();

    //���������
    virtual void print();

    //��������� � json
    void ins();

    // ��������� ���������� <<
    friend ostream& operator<<(ostream& out, Person& p) {
        p.print();
        return out;
    }

};

// ����� �������
class Student : public Person {
private:
    float sredn = 0.0;
    int course;
    vector<int> marks;

public:
    float sch_sh = 0.0;
     // ����������� 
    Student(string _name, vector<int> _marks, int _course = 1) :
        Person(_name), marks(_marks), course(_course) {}

    //�������� ������
    vector<int> input_vec();

    //���������� ���������� ����
    float sr();

    //���������� ������䳿
    void stipend();

    // �������� ������� ���
    float get_sredn() { return sr(); }
    //void set_marks(float _sredn) {this->sredn = sredn;}
    
    // �������� ����� �����
    int& get_course() { return course; }

    // ���������� ����
    void set_course(int course) { this->course = course; }

    // ���������� �������� (��� �������� � �����)
    void set_stip(float _stip);

    // ��������� ����
    virtual void input();

    //��������
    virtual void print();

    // ��������� json
    void ins();
};

// ����� ��������

class Zachetka : public Student {

public:
    vector<string> discipl; //���������
    vector<string> lecturers; //���������

    //�����������
    Zachetka(string _name, vector<int> _marks, vector<string> _discipl, vector<string> _lecturers, int _course = 1) :
        Student(_name, _marks, _course), lecturers(_lecturers), discipl(_discipl) {}

    //�������� ����������
    //���������� ����������� ����� �� 0
    vector<string> input_prep();

    //�������� ������ � �����������
    vector<string> get_lect() { return lecturers; }

    //�������� ��������
    //���������� ����������� ����� �� 0
    vector<string> input_disc();

    // ��������� json
    void ins();
};

//������� ������ ��� �����������/����������

class Employee : public Person {
public:
    double oklad;
    int stazh;

    //�����������
    Employee(string _name, double _oklad = 1000, int _stazh = 0) :
        Person(_name), oklad(_oklad), stazh(_stazh) {}

    // �������� �����
    double get_oklad() { return oklad; }

    //���������� �����
    void set_oklad(double oklad) { this->oklad = oklad; }

    //�������� ����
    double get_stazh() { return stazh; }

    //���������� ����
    void set_stazh(double _stazh) { this->stazh = _stazh; }

    //�������� ������� ��� ���� 
    virtual void input();

    //�������� ����
    virtual void print();

    // ��������� json
    void ins();
};

// ��������� json

class Lecturer : public Employee {
private:
    //float koef;
    string step;
    float salary = 0.0;
public:
    //�����������
    Lecturer(string _name, double _oklad = 1000, int _stazh = 0, string _step = "") :
        Employee(_name, _oklad, _stazh), step(_step) {}

    //�������� ������
    string get_step() { return step; }

    //�������� ��������
    float get_salary() { return salary; }
    
    //���������� ������
    void set_step(string step) { this->step = step; }

    //���������� ��������
    void cal_s();

    //��������
    virtual void input();

    //��������� ��������� �� ���������
    virtual void print();

    // ��������� json
    void ins();
};

//����� ���������

class Specialist : public Lecturer {
public:
    string spec;

    //�����������
    Specialist(string _name, double _oklad = 1000, int _stazh = 0, string _step = "employee", string _spec = "none") :
        Lecturer(_name, _oklad, _stazh, _step), spec(_spec) {}

    //�������� ������������
    virtual void input();

    //��������� ������������
    virtual void print();

    // ��������� json
    void ins();
};

//����� ��� ������ � �������� �������� �� ������

class File_stud {

private:
    string filename; //��'� �����

public:
    //�����������
    File_stud(string _filename) :
        filename(_filename) {}

    //�������� ���������� ��� n �������� � ���� � json
    void input_stud_information();

    //��������� ������ �������� � json
    void add_stud_information(); 

    //��������� ������ ��������
    void del_stud(string name);

    //�������� ������ ��������
    vector<Zachetka> get_stud();
};

//����� ��� ������ � �������� ����������

class File_lect {
private:
    string filename; 
public:
    //�����������
    File_lect(string _filename) :
        filename(_filename) {}

    //�������� ���������� ��� n ���������� � ���� � json
    void input_lect();

    //��������� ������ ��������� � json
    void add_lect_info();

    //��������� ������ ���������
    void del_lect(string name);

    //�������� ������ ����������
    vector<Specialist> get_lect();
};

// ������� �������� ����� � ������ � �����
bool poisk(std::vector<std::string> N, std::string prep);

// ��������� ����� ��� ��������, � ���� ���� ����� ��������
void st();




#endif