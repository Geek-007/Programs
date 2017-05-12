#include <iostream>
#include <string.h>
using namespace std;
 
template<class T, int MAX = 1000>
class Stack
{
private:
    T list[MAX + 1];
    int top;
public:
    Stack() {top = 0;}
    void push(const T &item)//将item压栈
    {
        list[top++] = item;
    }
    T pop()//将栈顶元素弹出栈
    {
        return list[--top];
    }
    const T & peek() const//访问栈顶元素
    {
        return list[top];
    }
    bool isEmpty() const//判断是否栈空
    {
        if (top == 0)  return true;
        else return false;
    }
};

bool judge(char a[])
{
    Stack<char> s;
    int len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        if (a[i] == '(')   s.push('(');
        else if (a[i] == ')')
        {
            if (s.isEmpty()) return false;
            else s.pop();
        }
        else continue;
    }
    if (s.isEmpty()) return true;
    else return false;
}

int main(int argc, char const *argv[])
{
    char a[1010];
    while (~scanf("%s", a))
    {
        if (judge(a))    cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
