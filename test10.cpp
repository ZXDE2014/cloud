#include<iostream>

using namespace std;

class Time {
		int m_hour;
		int m_minute;
	public:
		Time();
		~Time();
		Time(int hour,int minute=0):m_hour(hour),m_minute(minute){cout<<"human constructor\n";};
		Time operator+(const Time& t) const;  //Time+Time 或者 Time+int (会增加开销) 
		Time operator+(int t) const;		//Time+int 
		explicit operator int() const;   
	
		friend 
			Time operator+(int hour,const Time& t); //int+Time 
		friend 
			ostream& operator<<(ostream& os,const Time &t);	
}; 

inline
	Time::Time(){
		cout<<"default constructor\n";	
	}
inline
	Time::~Time(){
		cout<<"default destructor\n";	
	}

inline
	Time Time::operator+(const Time &t) const{
		Time sum;
		sum.m_minute=m_minute+t.m_minute;
		sum.m_hour=m_hour+t.m_hour+	sum.m_minute/60;
		sum.m_minute%=60;
	//	cout<<"yes"; 
		return sum;
	}
	
inline	
	Time::operator int() const{
		return m_minute+m_hour*60;		
	}	

   //提供友元函数1的版本 
	Time operator+(int hour,const Time &t){
		Time sum;
		sum.m_minute = t.m_minute;
		sum.m_hour = hour+t.m_hour;
		return sum;
	}	


	ostream& operator<<(ostream& os,const Time& t){
		os<<t.m_hour<<":"<<t.m_minute<<endl;
		return os;
	}


int main(){
	Time a(7);
	Time b;
//	int c=a;
//	cout<<c<<"\n";	
	b=2+a;
//	cout<<b;	
	int * p=nullptr; 
	
} 
