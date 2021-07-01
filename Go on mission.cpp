#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class BigInt
{
private:
    constexpr static int N = 150;
    constexpr static int WIDTH = 8, BASE = 100000000;
    bool sign;
    int bigInt[N];
public:
    // constructor
    BigInt();
    BigInt(char*);
    BigInt(const BigInt&);
    
    // copy assignment operator
    BigInt &operator = (const BigInt&);
    
    // comparison operator
    bool operator < (BigInt);
    bool operator > (BigInt);
    bool operator == (BigInt);
    bool operator >= (BigInt);
    bool operator <= (BigInt);
    
    // arithmetic operator
    BigInt operator + (BigInt);
    BigInt operator - (BigInt);
    
    // insertion & extraction operator
    friend istream& operator >> (istream&, BigInt&);
    friend ostream& operator << (ostream&, BigInt&);
};

void solution(BigInt& tanjiro, BigInt& zenitsu, BigInt& inosuke, int n);

int main()
{
    int n;
	cin >> n;
	
    // initialize health condition
    BigInt hi, kaminari, kedamono;
    
    cin >> hi;
	kaminari = kedamono = hi;
	
    // go on mission
    solution(hi, kaminari, kedamono, n);
    
    // output result
    cout << hi << endl;
    cout << kaminari << endl;
    cout << kedamono << endl;
}
