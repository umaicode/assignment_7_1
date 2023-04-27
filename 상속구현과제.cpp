//7장 클래스 상속 과제
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
    // string getEno(); // 사용금지
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

    // 교수님 설명
    Coder(string language, double workYears, string id, string dname, string city, string pid, string pname) {
        Employee(eno, dname, city)
    }
    // 교수님 설명 끝
    
	Coder(char* language, double workYears, char* eno, Dept* dname, string pid, string pname);
	ostream& operator<<(Coder&);

};
class PartTimeStudent : private Employee, private Student {
private:
    double salary;
    double grade;

public:
    int operator>(PartTimeStudent&); // eno 와 sid로 정렬 해야함.
};
int main() {
    while (1)
    {
        Coder *codings[10];
        PartTimeStudent* workStudents[10];

        int select;
        //생성자 사용에 의한 입력은 new Coder("이름", ...)으로 값을 지정하여 입력
        //객체 출력은 cout<<*codings[i]만을 사용한다.
        cout << "\n선택 1: Coder 객체 10개 입력과 출력, 2. PartTimeStudent 객체 10개 입력과 출력, 3: Coder객체 정렬(Dept 이름> 도시 순서로 정렬)과 출력,4. partTimeStudents 객체 정렬(eno > sid 순서로 정렬)과 출력, 5. 종료" << endl;

        cin >> select;
        switch (select) {
        case 1://1: Coder 객체 10개 입력과 출력
            codings[0] = new Coder("C++", 2, "");
            codings[1] = new Coder("java", 2, ""); // 10개 다 만들기
            
            for () {
                cout << codings[i];
            }

            break;
        case 2://2. PartTimeStudent 객체 10개 입력과 출력

            break;

        case 3://3: Coder객체 정렬(Dept 이름과 도시)과 출력

            break;
        case 4://4. partTimeStudents 객체 정렬(eno > sid)과 출력

            break;

        default:
            exit(0);
            break;
        }
    }
    system("pause");
    return 1;
}