#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student
{
public:
    int id;
    string name, grade;
    Student() {};
    Student(int id, string name, string grade);
    bool operator < (const Student & s) const
    {
        return id < s.id;
    }
};

istream & operator >> (istream & in, Student & s)
{
    return in >> s.id >> s.name >> s.grade;
}

ostream & operator << (ostream & out, Student & s)
{
    return out << s.id << " " << s.name << " " << s.grade << endl;
}


int main()
{
    vector<Student> sv;
    Student temp;
    while (cin >> temp)
    {
        sv.push_back(temp);
    }
    sort(sv.begin(), sv.end());
    for (int i = 0; i < sv.size(); ++i)
        cout << sv[i];
    return 0;
}