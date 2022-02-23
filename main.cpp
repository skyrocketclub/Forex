#include <iostream>
#include <vector>
#include <sstream>
#include <limits>


//using namespace std;

using std::cout;
using std::cin;
using std::string;
using std::endl;

int base_currency();
int data_validation(int,int);

std::vector<std::pair<string,int>> currency{
    {"United States Dollar (USD)",1},{"Swiss Franc (CHF)",2},
    {"Euro (EUR)",3},{"Japanese Yen (JPY)",4},
    {"British Pound (GBP",5},{"Naira (NRA)",6},
    {"Canadian Dollar (CAD)",7},{"New Zealand Dollar (NZD)",8},
    {"South Arican Rand (ZAR)",9}
} ;

int main()
{
    cout<<"\t\tChoose Your Base Currency\n";
    int base = base_currency();
    return 0;
}

int base_currency(){
    int base{};

    for(auto c: currency){
        cout<<c.second<<" - "<<c.first<<endl;
    }
    base = data_validation(1,9);
    cout<<"\nBASE CURRENCY: "<<currency.at(base-1).first<<endl;
    return base;
}

int data_validation(int min, int max){
    string entry{};
    int choice{};

    bool done{false};
    cout<<"OPTION: ";
    cin>>entry;

    while(!done){
        std::istringstream validator{entry};
        if(validator>>choice && (choice >= min && choice <= max)){
            done = true;
        }
        else{
            cout<<"KINDLY ENTER A VALID OPTION\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
    return choice;
}
