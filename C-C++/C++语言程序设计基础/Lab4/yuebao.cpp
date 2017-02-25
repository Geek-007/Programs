#include <iostream>
using namespace std;
  
class Yuebao
{
private:  
    static double profitRate;
    double dep;
public:
    static void setProfitRate(double rate){
        profitRate=rate;
    };
    Yuebao(int depo){
        this->dep = depo;
    };
    void addProfit(){
        this->dep = this->dep + dep*profitRate;
    };
    void deposit(double amount){
        this->dep = this->dep + amount;
    };
    void withdraw(double amount){
        this->dep = this->dep - amount;
    };
    double getBalance(){
        return this->dep;
    };
};

double Yuebao::profitRate = 0;  

int main()
{
    int n;
    while(cin >> n)
    {
        double profitRate;
        cin >> profitRate;
        Yuebao::setProfitRate(profitRate);
        Yuebao y(0); 
        int operation;
        double amount;
        for (int i = 0; i < n; ++i)
        {
            y.addProfit();
            cin >> operation >> amount;
            if (operation == 0)
                y.deposit(amount);
            else
                y.withdraw(amount);
        }
        cout << y.getBalance() << endl;
    }
    return 0;
}