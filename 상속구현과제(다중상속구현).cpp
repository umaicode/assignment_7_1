//7장 클래스 상속 과제
// 1) dynamic_cast <> : 사용해야 한다.
// 2) virtual : 사용해야 한다.
// => 동적바인딩
#include <iostream>
#include <string>
using namespace std;
class Dept {
    string dname;
    string city;
    friend ostream& operator<<(ostream&, Dept&);
public:
    Dept(string dname, string city) : dname(dname), city(city) {}
    string getDname() {
        return dname;
    }
    string getCity() {
        return city;
    }
};

ostream& operator<<(ostream& os, Dept& dept) {
    os << dept.dname << ", " << dept.city;
    return os;
}

class Person {
private:
    string pid;
    string pname;
    friend ostream& operator<<(ostream&, Person&);
public:
    Person() {}
    Person(string pid, string pname) : pid(pid), pname(pname) {}
    // virtual 사용
    virtual ~Person() {}
};

ostream& operator<<(ostream& os, Person& p) {
    os << p.pid << ", " << p.pname << endl;
    return os;
}

class Employee : protected Person {
private:
    string eno;
    Dept* dname;
    friend ostream& operator<<(ostream&, Employee&);
public:
    Employee(string eno, Dept* dept, string pid, string pname) : eno(eno), dname(dept), Person(pid, pname) {}
    virtual ~Employee() {}
    virtual string getDname() {
        return dname->getDname();
    }
    virtual string getCity() {
        return dname->getCity();
    }
    virtual string getEno() {
        return eno;
    }
};

ostream& operator<<(ostream& os, Employee& e) {
    os << e.eno << ", " << *e.dname << ", " << dynamic_cast<Person&>(e);
    return os;
}

class Student : virtual private Person {
private:
    string sid;
    Dept* dname;
    friend ostream& operator<<(ostream&, Student&);
public:
    Student(string sid, Dept* dept, string pid, string pname) : sid(sid), dname(dept), Person(pid, pname) {}
    virtual ~Student() {}
    virtual string getSid() {
        return sid;
    }
};

ostream& operator<<(ostream& os, Student& s) {
    os << s.sid << ", " << *s.dname << ", " << dynamic_cast<Person&>(s);
    return os;
}

class Coder : private Employee {
private:
    string language;
    double workYears;
public:
    int operator > (Coder&);//
    Coder(string language, double workYears, string eno, string dname, string city, string pid, string pname) : language(language), workYears(workYears), Employee(eno, new Dept(dname, city), pid, pname) {}
    friend ostream& operator<<(ostream&, Coder&);
    virtual ~Coder() {}
};

int Coder::operator>(Coder& c) {
    if (this->getDname() == c.getDname()) {
        if (this->getCity() == c.getCity()) {
            return dynamic_cast<Employee*>(this) > dynamic_cast<Employee*>(&c);
        }
        else {
            return this->getCity() > c.getCity();
        }
    }
    else {
        return this->getDname() > c.getDname();
    }
}

ostream& operator<<(ostream& os, Coder& c) {
    os << c.language << ", " << c.workYears << ", " << dynamic_cast<Employee&>(c);
    return os;
}


class PartTimeStudent : private Employee, virtual private Student {
private:
    double salary;
    double grade;
    friend ostream& operator<<(ostream&, PartTimeStudent&);
public:
    int operator>(PartTimeStudent&);
    PartTimeStudent(double salary, double grade, string eno, string dname, string city, string sid, string pid, string pname) : salary(salary), grade(grade), Employee(eno, new Dept(dname, city), pid, pname), Student(sid, new Dept(dname, city), pid, pname) {}
    virtual ~PartTimeStudent() {}
};

int PartTimeStudent::operator>(PartTimeStudent& pts) {
    if (this->getEno() == pts.getEno()) {
        if (this->getSid() == pts.getSid()) {
            return dynamic_cast<Employee*>(this) > dynamic_cast<Employee*>(&pts);
        }
        else {
            return this->getSid() > pts.getSid();
        }
    }
    else {
        return this->getEno() > pts.getEno();
    }
}

ostream& operator<<(ostream& os, PartTimeStudent& pts) {
    os << pts.salary << ", " << pts.grade << ", " << pts.getSid() << ", " << dynamic_cast<Employee&>(pts);
    return os;
}

void swap(Coder* c[], int i, int j) {
    Coder* temp;
    temp = c[i];
    c[i] = c[j];
    c[j] = temp;
}

void swapPts(PartTimeStudent* pts[], int i, int j) {
    PartTimeStudent* temp;
    temp = pts[i];
    pts[i] = pts[j];
    pts[j] = temp;
}

int main() {
    Coder* codings[10];
    PartTimeStudent* workStudents[10];
    while (1)
    {
        /* Coder *codings[10];
         PartTimeStudent* workStudents[10];*/
        Coder* c;
        PartTimeStudent* pts;
        int select;
        //생성자 사용에 의한 입력은 new Coder("이름", ...)으로 값을 지정하여 입력
        //객체 출력은 cout<<*codings[i]만을 사용한다.
        cout << "\n선택 1: Coder 객체 10개 입력과 출력, 2. PartTimeStudent 객체 10개 입력과 출력, 3: Coder객체 정렬(Dept 이름> 도시 순서로 정렬)과 출력,4. partTimeStudents 객체 정렬(eno > sid 순서로 정렬)과 출력, 5. 종료" << endl;

        cin >> select;
        switch (select) {
        case 1://1: Coder 객체 10개 입력과 출력
        {
            codings[0] = new Coder("python", 1, "E01", "computer", "seoul", "P01", "PARK");
            codings[1] = new Coder("java", 3, "E02", "design", "suwon", "P02", "KIM");
            codings[2] = new Coder("C", 5, "E03", "architect", "busan", "P03", "LEE");
            codings[3] = new Coder("C++", 7, "E04", "chemistry", "daegu", "P04", "JO");
            codings[4] = new Coder("javascript", 9, "E05", "physics", "ulsan", "P05", "OH");
            codings[5] = new Coder("Dart", 2, "E06", "medical", "yongin", "P06", "JUNG");
            codings[6] = new Coder("C#", 4, "E07", "biology", "seongnam", "P07", "HWANG");
            codings[7] = new Coder("Kotlin", 6, "E08", "computer", "incheon", "P08", "LIM");
            codings[8] = new Coder("Swift", 8, "E09", "geology", "gwangju", "P09", "KANG");
            codings[9] = new Coder("typescript", 10, "E10", "design", "daejeon", "P10", "YU");
            for (int i = 0; i < 10; i++) {
                cout << *codings[i];
            }
            break;
        }

        case 2://2. PartTimeStudent 객체 10개 입력과 출력
        {
            workStudents[0] = new PartTimeStudent(1000, 3, "E01", "computer", "seoul", "S01", "P01", "KIM");
            workStudents[1] = new PartTimeStudent(3000, 2, "E02", "economics", "london", "S02", "P02", "LEE");
            workStudents[2] = new PartTimeStudent(5000, 3, "E03", "mathematics", "paris", "S03", "P03", "PARK");
            workStudents[3] = new PartTimeStudent(7000, 1, "E04", "design", "newyork", "S05", "P04", "CHOI");
            workStudents[4] = new PartTimeStudent(9000, 4, "E05", "laws", "tokyo", "S04", "P05", "JUNG");
            workStudents[5] = new PartTimeStudent(8000, 4, "E07", "psychology", "barcelona", "S04", "P06", "KANG");
            workStudents[6] = new PartTimeStudent(6000, 3, "E07", "mechanical engineering", "moscow", "S07", "P07", "JO");
            workStudents[7] = new PartTimeStudent(4000, 2, "E04", "philosophy", "chicago", "S04", "P08", "YOON");
            workStudents[8] = new PartTimeStudent(2000, 1, "E09", "archeology", "singapore", "S09", "P09", "JANG");
            workStudents[9] = new PartTimeStudent(10000, 3, "E10", "politics", "dubai", "S10", "P10", "LIM");
            for (int i = 0; i < 10; i++) {
                cout << *workStudents[i];
            }
            break;
        }

        case 3://3: Coder객체 정렬(Dept 이름과 도시)과 출력
        {
            for (int i = 0; i < 10; i++)
                for (int j = i + 1; j < 10; j++)
                {
                    Coder* c1 = dynamic_cast<Coder*>(codings[i]);
                    Coder* c2 = dynamic_cast<Coder*>(codings[j]);

                    if (*c1 > *c2) {
                        swap(codings, i, j);
                    }
                }
            for (int i = 0; i < 10; i++)
            {
                cout << i + 1 << ". " << *(codings[i]) << endl;
            }
            break;
        }

        case 4://4. partTimeStudents 객체 정렬(eno > sid)과 출력
        {
            for (int i = 0; i < 10; i++)
                for (int j = i + 1; j < 10; j++)
                {
                    PartTimeStudent* pts1 = dynamic_cast<PartTimeStudent*>(workStudents[i]);
                    PartTimeStudent* pts2 = dynamic_cast<PartTimeStudent*>(workStudents[j]);

                    if (*pts1 > *pts2) {
                        swapPts(workStudents, i, j);
                    }
                }
            for (int i = 0; i < 10; i++)
            {
                cout << i + 1 << ". " << *(workStudents[i]) << endl;
            }

            break;
        }

        default:
            exit(0);
            break;
        }
    }
    system("pause");
    return 1;
}