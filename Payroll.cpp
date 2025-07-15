 #include <iostream>
#include <vector>
using namespace std;

class Employee {
public:
    string name;
    int id;
    string dept;
    double salary, hours, bonus;
    Employee(string n, int i, string d, double s, double b=0) : 
        name(n), id(i), dept(d), salary(s), bonus(b), hours(0) {}
    double calcPay() {
        double weekly = salary/4, rate = weekly/40;
        double reg = min(hours,40.0)*rate;
        double ot = max(hours-40,0.0)*rate*1.5;
        return reg + ot + (reg+ot)*bonus;
    }
    void show() {
        cout << "ID:" << id << "\nName:" << name << "\nDept:" << dept 
             << "\nSalary:" << salary << "\nHours:" << hours 
             << "\nPay:" << calcPay() << "\n\n";
    }
};

class Payroll {
    vector<Employee> emps;
public:
    void add(Employee e) { emps.push_back(e); }
    bool del(int id) {
        for(auto it=emps.begin(); it!=emps.end(); ++it)
            if(it->id==id) { emps.erase(it); return true; }
        return false;
    }
    bool setHours(int id, double h) {
        for(auto& e : emps)
            if(e.id==id) { e.hours=h; return true; }
        return false;
    }
    void showAll() {
        for(auto& e : emps) e.show();
        cout << "Total:" << emps.size() << "\n";
    }
    double totalPay() {
        double t=0; for(auto& e : emps) t+=e.calcPay(); return t;
    }
};

int main() {
    Payroll v;
    int c,id; string n,d; double s,b,h;
    while(cout << "1.Add 2.Del 3.Hours 4.Show 5.Total 6.Exit\nChoice: ",
          cin >> c, c!=6) {
        switch(c) {
            case 1: cout << "Name ID Dept Salary Bonus: ";
                    cin >> n >> id >> d >> s >> b;
                    v.add(Employee(n,id,d,s,b)); break;
        case 2: cout << "ID: "; cin >> id;
                    cout << (v.del(id)?"Done\n":"Fail\n"); break;
       case 3: cout << "ID Hours: "; cin >> id >> h;
                    cout << (v.setHours(id,h)?"Done\n":"Fail\n"); break;
      case 4: v.showAll(); break;
      case 5: cout << "Total: " << v.totalPay() << "\n"; break;
        }
    }
}