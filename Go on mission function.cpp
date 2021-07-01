#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
class BigInt
{
private:
    constexpr static int N = 150;
    constexpr static int WIDTH = 8, BASE = 100000000;
    bool sign;	//true代表+,false代表- 
    int bigInt[N];	//每一格裡面都放8位數，最多150格
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
// constructor
BigInt::BigInt():sign(true){
	int i;
	for(i=0;i<N;i++){
		bigInt[i]=0;
	}
}
BigInt::BigInt(char* str):sign(true){
	int i,j;
	for(i=0;i<N;i++){
		bigInt[i]=0;
	}
	
	int len=strlen(str);
	int bigint_idx=0;
	for(i=len-1;i>7;i-=8){	//先從比較小的位數、每8個數字開始處理
		int n=0;
		for(j=i-7;j<=i;j++){
			n=n*10+str[j]-'0';
		}
		bigInt[bigint_idx++]=n;
	}
	
	int n=0;	//再處理剩下不滿8位的數字
	for(j=0;j<=i;j++){
		n=n*10+str[j]-'0';
	}
	bigInt[bigint_idx]=n;
}
BigInt::BigInt(const BigInt& bi){
	*this=bi;
}
// copy assignment operator
BigInt& BigInt::operator = (const BigInt& bi){
	if(this == &bi){	//如果是同一個物件就直接return
		return *this;
	}
	
	int i;
	sign=bi.sign;
	for(i=0;i<N;i++){
		bigInt[i]=bi.bigInt[i];
	}
	return *this;
}
// comparison operator
bool BigInt::operator < (BigInt right){	//this < right(?)
	int i;
	if(sign==true && right.sign==false){	//+ < -
		return false;
	}else if(sign==false && right.sign==true){	//- < +
		return true;
	}else if(sign==true && right.sign==true){	//+ +
		for(i=N-1;i>=0;i--){	//從最高位數開始比
			if(bigInt[i] > right.bigInt[i]){	//this > right
				return false;
			}else if(bigInt[i] < right.bigInt[i]){	//this < right
				return true;
			}
		}
	}else if(sign==false && right.sign==false){	//- -
		for(i=N-1;i>=0;i--){	//從最高位數開始比
			if(bigInt[i] > right.bigInt[i]){	//注意負號:this < right
				return true;
			}else if(bigInt[i] < right.bigInt[i]){	//注意負號:this > right
				return false;
			}
		}
	}
	
	//完全相等
	return false;
}
bool BigInt::operator > (BigInt right){	//this > right(?)
	int i;
	if(sign==true && right.sign==false){	//+ > -
		return true;
	}else if(sign==false && right.sign==true){	//- > +
		return false;
	}else if(sign==true && right.sign==true){	//+ +
		for(i=N-1;i>=0;i--){	//從最高位數開始比
			if(bigInt[i] > right.bigInt[i]){	//this > right
				return true;
			}else if(bigInt[i] < right.bigInt[i]){	//this < right
				return false;
			}
		}
	}else if(sign==false && right.sign==false){	//- -
		for(i=N-1;i>=0;i--){	//從最高位數開始比
			if(bigInt[i] > right.bigInt[i]){	//注意負號:this < right
				return false;
			}else if(bigInt[i] < right.bigInt[i]){	//注意負號:this > right
				return true;
			}
		}
	}
	
	//完全相等
	return false;
}
bool BigInt::operator == (BigInt right){
	int i;
	if(sign!=right.sign){	//符號不一樣，絕對不一樣
		return false;
	}
	for(i=N-1;i>=0;i--){
		if(bigInt[i]!=right.bigInt[i]){
			return false;
		}
	}
	return true;
}
bool BigInt::operator >= (BigInt right){
	if(*this > right || *this == right){
		return true;
	}else{
		return false;
	}
}
bool BigInt::operator <= (BigInt right){
	if(*this < right || *this == right){
		return true;
	}else{
		return false;
	}
}
// arithmetic operator
BigInt BigInt::operator + (BigInt right){
	int i;
	BigInt ans;	//先建出一個bigint
	for(i=0;i<N;i++){	//從比較小的位數開始+
		ans.bigInt[i] = bigInt[i] + right.bigInt[i];
		if(ans.bigInt[i] >= BASE){	//進位
			ans.bigInt[i]-=BASE;
			bigInt[i+1]+=1;	//不能寫成ans.bigInt[i+1]+=1，因為下一圈迴圈會改掉這個1
		}
	}
	return ans;
}
BigInt BigInt::operator - (BigInt right){	//this - right(right>=0)
	int i;
	BigInt ans;
	if(sign==true){	//this > 0
		if(*this==right){
			ans.sign=true;
			for(i=0;i<N;i++){
				ans.bigInt[i]=0;
			}
		}else if(*this > right){
			ans.sign=true;
			for(i=0;i<N;i++){
				if(bigInt[i] > right.bigInt[i]){
					ans.bigInt[i] = bigInt[i] - right.bigInt[i];
				}else if(bigInt[i] < right.bigInt[i]){
					bigInt[i+1]-=1;
					ans.bigInt[i] = BASE + bigInt[i] - right.bigInt[i];
				}else{
					ans.bigInt[i]=0;
				}
			}
		}else if(*this < right){	//變成right - this
			ans.sign=false;
			for(i=0;i<N;i++){
				if(bigInt[i] > right.bigInt[i]){
					right.bigInt[i+1]-=1;
					ans.bigInt[i] = BASE + right.bigInt[i] - bigInt[i];
				}else if(bigInt[i] < right.bigInt[i]){
					ans.bigInt[i] = right.bigInt[i] - bigInt[i];
				}else{
					ans.bigInt[i]=0;
				}
			}
		}
	}else{	//-a-b=-(a+b)
		//注意這兩行的順序，因為+的時候會去呼叫default constructor，從而使得sign變為true就會WA
		ans = *this + right;
		ans.sign = false;
	}
	return ans;
}
// insertion & extraction operator
istream& operator >> (istream& input,BigInt& num){
	char str[1205];
	cin>>str;
	num=BigInt(str);	//用copy constructor
	return input;
}
ostream& operator << (ostream& output,BigInt& num){
	int i;
	if(num.sign==false){
		cout<<"-";
	}
	bool start=false;
	bool first=true;
	for(i=149;i>=0;i--){
		if(num.bigInt[i]!=0){	//遇到第一個非0的數字以後就可以開始印了
			start=true;
		}
		if(start){
			if(first){	//遇到第一個非0的數字可以直接印出來，不用管setwidth,setfill
				cout<<num.bigInt[i];
				first=false;
			}else{	//因為剩下的數字有可能不滿8位數，所以要setwidth,setfill
				cout<<setw(8)<<setfill('0')<<num.bigInt[i];
			}
		}
	}
	
	//如果bigInt陣列全部都是0要額外處理
	if(!start){
		cout<<"0";
	}
	
	return output;
}

void solution(BigInt &tanjiro, BigInt &zenitsu, BigInt &inosuke, int n){
	int i;
	for(i=0;i<n;i++){
		BigInt mission;
		cin>>mission;
		if(inosuke>=tanjiro && inosuke>=zenitsu){
			inosuke = inosuke - mission;
		}else if(tanjiro>=zenitsu && tanjiro>=inosuke){
			tanjiro = tanjiro - mission;
		}else if(zenitsu>=tanjiro && zenitsu>=inosuke){
			zenitsu = zenitsu - mission;
		}
	}
}
