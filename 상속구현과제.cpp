//7�� Ŭ���� ��� ����
#include <iostream>
#include <string>
using namespace std;
class Dept {
	string dname[10];
	string city;
	ostream& operator<<(ostream&, Dept&);
    istream& operator>>(istream& is, Dept& d) {
        is >> d.dname >> d.city;
        return is;
    }
    int operator<(Dept&);
};
class Person {
private:
	string pid;
	string pname;
	ostream& operator<<(Person&);

};
class Employee : protected Person {
private:
	string eno;
	Dept* dname;

public:
    // string getEno(); // ������
    int operator>(Employee&);
    Employee(string eno, string danme, string city) {
        eno = eno;
        dname = new Dept();
    }

    ostream& operator<<(ostream&, Employee&);

    //istream& operator>>(istream& is, Employee& e) {
    //    is >> emp.eno >> (*emp.dname);
    //}

};
class Student : private Person {
private: 
    string sid;
    Dept* dname;

public:
    int operator>(Student&);
};
class Coder : private Employee {
private:
	string language;
	double workYears;
public:
	int operator > (Coder&);//

    // ������ ����
    Coder(string language, double workYears, string id, string dname, string city, string pid, string pname) {
        Employee(eno, dname, city)
    }
    // ������ ���� ��
    
	Coder(char* language, double workYears, char* eno, Dept* dname, string pid, string pname);
	ostream& operator<<(Coder&);

};
class PartTimeStudent : private Employee, private Student {
private:
    double salary;
    double grade;

public:
    int operator>(PartTimeStudent&); // eno �� sid�� ���� �ؾ���.
};
int main() {
    while (1)
    {
        Coder *codings[10];
        PartTimeStudent* workStudents[10];

        int select;
        //������ ��뿡 ���� �Է��� new Coder("�̸�", ...)���� ���� �����Ͽ� �Է�
        //��ü ����� cout<<*codings[i]���� ����Ѵ�.
        cout << "\n���� 1: Coder ��ü 10�� �Է°� ���, 2. PartTimeStudent ��ü 10�� �Է°� ���, 3: Coder��ü ����(Dept �̸�> ���� ������ ����)�� ���,4. partTimeStudents ��ü ����(eno > sid ������ ����)�� ���, 5. ����" << endl;

        cin >> select;
        switch (select) {
        case 1://1: Coder ��ü 10�� �Է°� ���
            codings[0] = new Coder("C++", 2, "");
            codings[1] = new Coder("java", 2, ""); // 10�� �� �����
            
            for () {
                cout << codings[i];
            }

            break;
        case 2://2. PartTimeStudent ��ü 10�� �Է°� ���

            break;

        case 3://3: Coder��ü ����(Dept �̸��� ����)�� ���

            break;
        case 4://4. partTimeStudents ��ü ����(eno > sid)�� ���

            break;

        default:
            exit(0);
            break;
        }
    }
    system("pause");
    return 1;
}