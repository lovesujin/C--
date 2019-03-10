#include <iostream>
#include <iomanip>
#include <ctime>
#include <windows.h>

using namespace std;

void gotoxy(int x,int y){
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void textcolor(int color_number){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}
///////////////////////////////////////////// Date class ///////////////////////////////////////////// 
class Date:public tm{ //time.h, ctime에 있는 tm 구조체를 가져옴 
//	friend class CalInterface; 최종인터페이스 CalIntaerface class에 friend 

protected:
	unsigned int tdays; //1년 1월 1일을 1일로 하여 저장된 날짜의 전체 일 수를 저장 
	int mfday; // 저장된 달의 1일의 위치 저장(2015년 3월을 예를 들면 1일이 일요일이므로 mfday는 0) 달력을 만들때 필요함 
	int year; // tm_year는 1900년부터 시작하므로 1일부터 시작하는 변수를 따로 저장 

	static const int ldays[12]; //각 달의 마지막 날짜를 저장하고 있는 상수배열 

	bool leapCheck(int ayear); //윤년인지 아닌지를 판단하는 함수 

	void arrByMDY(void); // 년원일을 기준으로 나머지 정보를 계산 
	void arrByTdays(void); // tdays를 기준으로 나머지 정보를 계산 
		void arrRest(void); // 년월일, tdays를 기준으로 나머지 정보를 계산
			void getDayName(void);	// tm_wday를 기준으로 요일이름을 만듦 
			char day_name[4]; // 요일 이름이 저장되는 문자열 

public:
	int color; //글자색을 저장하는 함수 
	
	Date(void); //생성자 
	void setDate(int amon, int amday, int ayear); //년월일을 받아 데이터를 만듦 
	void setDate(int atdays); //tdays를 받아 데이터를 만듦 
	void showDate(void); // 데이터를 출력 
	const Date operator +(const int a) const; //+연사자함수 
	const Date operator -(const int a) const; //-연산하 함수 
	const int operator -(const Date &A) const; //-연산자 함수 
};
const int Date::ldays[12]={31,28,31,30,31,30,31,31,30,31,30,31}; //각 달의 마지막 날짜들 

bool Date::leapCheck(int ayear){
	if(ayear%4==0 && ayear%100!=0 || ayear%400==0) return 1;
	return 0;
}
void Date::arrRest(void){
	tm_yday=-1;
	tm_yday+=tm_mday;	
	for(int i=0;i<tm_mon;i++){
		if(leapCheck(year)&&i==1) tm_yday+=ldays[1]+1;
		else tm_yday+=ldays[i];
	}
	tm_year=year-1900;
	tm_wday=tdays%7;
	getDayName();
	mfday=(tdays-tm_mday+1)%7;
}
void Date::arrByMDY(void){
	int i;
	tdays=0;
	
	tdays+=tm_mday;	
	for(i=0;i<tm_mon;i++){
		if(leapCheck(year)&&i==1) tdays+=ldays[1]+1;
		else tdays+=ldays[i];
	}
	for(i=1;i<year;i++){
		if(leapCheck(i)) tdays+=366;
		else tdays+=365;
	}
	arrRest();
}
void Date::arrByTdays(void){
	int i, temp;
	
	tm_mon=0;
	tm_mday=0;
	year=0;
	
	temp=tdays;
	for(i=0;;i++){
		if(i==0) year++;
		else if(leapCheck(i)){
			if(temp<=366) break;
			temp-=366;
			year++;
		} 
		else{
			if(temp<=365) break;
			temp-=365;
			year++;
		} 
	}
	for(i=0;i<12;i++){
		if(leapCheck(year)&&i==1){
			if(temp-(ldays[1]+1)<=0) break;	
			else temp-=(ldays[1]+1);
		}
		else{
			if(temp-ldays[i]<=0) break;	
			else temp-=ldays[i];
		}
		tm_mon++;
	}
	tm_mday=temp;
	arrRest();
}
void Date::getDayName(void){
	switch(tm_wday){
	case 0: memcpy(day_name,"SUN", 4); break;
	case 1: memcpy(day_name,"MON", 4); break;
	case 2: memcpy(day_name,"TUE", 4); break;
	case 3: memcpy(day_name,"WED", 4); break;
	case 4: memcpy(day_name,"THU", 4); break;
	case 5: memcpy(day_name,"FRI", 4); break;
	case 6: memcpy(day_name,"SAT", 4); break;
	}
}
Date::Date(void){
	time_t raw;
	time(&raw);
	struct tm* curtime;
	curtime=localtime(&raw);
	tm_mon=curtime->tm_mon;
	tm_mday=curtime->tm_mday;
	year=curtime->tm_year+1900;	
	arrByMDY();
	color=0x0007;
}
void Date::setDate(int amon, int amday, int ayear){
	tm_mon=amon-1;
	tm_mday=amday;
	year=ayear;
	arrByMDY();
}
void Date::setDate(int atdays){
	tdays=atdays;
	arrByTdays();
}
void Date::showDate(void){
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color);
	cout<<setw(2)<<setfill('0')<<tm_mon+1<<'/'<<setw(2)<<tm_mday<<'/'<<setw(4)<<year<<'('<<day_name<<')';
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0007);
}
const Date Date::operator +(const int a) const{
	Date B;
	B.tdays=tdays+a;
	B.arrByTdays();
	return B;
}
const Date Date::operator -(const int a) const{
	Date B;
	B.tdays=tdays-a;
	B.arrByTdays();
	return B;
}
const int Date::operator -(const Date &A) const{
	int B;
	B=tdays-A.tdays;
	return B;
}
///////////////////////////////////////////// Calendar class ///////////////////////////////////////////// 

class Calendar:public Date{
//	friend class CalInterface;

protected:
	int cal_x; //달력 출력 x좌표 저장 변수 
	int cal_y; //달력 출력 y좌표 저장 변수 

	Date saved; //표시되는 달력과 별개로 날짜값을 저장할 수 있는 class CalInterface에서 필요함 

	void makeCalData(void); //달력값을 구하는 함수 
		int caldata[6][7]; //달력값이 저장되는 2차원 배열 

public:
	Calendar(void){ //생성자. 생성후 초기화 
		memset(this,0,sizeof(Calendar));
	}
	void setCalendar(const Date &A){ //Date 타입을 받아 달력을 만듦 
		memcpy(this,&A,sizeof(Date));
		makeCalData();
	}
	void showCalendar(int ax,int ay); //x,y좌표를 업데이트하고 달력 출력 
	void showCalendar(void); // 저장된 좌표에 달력 출력(초기값은 0,0) 
};
void Calendar::makeCalData(void){
	int leap_adj_this_mon=0; //이번달의 윤달보정값을 저장하는 변수 
	int leap_adj_last_mon=0; //지난달의 윤달보정값을 저장하는 변수 
	if(leapCheck(year)&&tm_mon==1) leap_adj_this_mon=1; //이달이 2월이면 값을 보정 
	if(leapCheck(year)&&tm_mon==2) leap_adj_last_mon=1; //지난달이 2월이면 값을 보정 
	
	int this_mday=1; //이번달의 시작날짜 
	int next_mday=1; //다음달의 시작날짜 
	
	int last_mday; //지난달이 시작날짜를 저장하는 변수                      /* 지난달의 시작날짜를 구함                                           */
	if(mfday==0) last_mday=ldays[(tm_mon+11)%12]-7    +1+leap_adj_last_mon; /* 이부분은 달의 시작이 일요일일때, 지난달의 마지막주를 보여주기 위함 */
	else         last_mday=ldays[(tm_mon+11)%12]-mfday+1+leap_adj_last_mon; /* 달의 시작이 일요일이 아닐때 빈칸만큼                               */
	
	for(int i=0;i<6;i++){
		for(int j=0;j<7;j++){
			if(last_mday<=ldays[(tm_mon+11)%12]+leap_adj_last_mon) caldata[i][j]=100+last_mday++; //지난달의 날짜들은 100을 더해서 저장 
			else if(this_mday<=ldays[tm_mon%12]+leap_adj_this_mon) caldata[i][j]=this_mday++;
			else caldata[i][j]=200+next_mday++; //다음 달의 날짜들은 200을 더해서 저장 
		}
	}
}
void Calendar::showCalendar(void){
	gotoxy(cal_x,cal_y);
	cout<<"      << < "<<setw(2)<<setfill('0')<<tm_mon+1<<'/'<<setw(4)<<year<<" > >> ";
	gotoxy(cal_x,cal_y+1);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x00c0);
	cout<<" SUN";
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0070);
	cout<<" MON TUE WED THU FRI";
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x00F0);
	cout<<" SAT"<<endl;
	gotoxy(cal_x,cal_y+2);
	for(int i=0;i<6;i++){
		gotoxy(cal_x,cal_y+2+i);
		for(int j=0;j<7;j++){
			switch(j){
				case 0:
					SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0c);
					break;
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
					SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07);
					break;
				case 6:
					SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0F);
					break;		
			}
			if(caldata[i][j]>200){
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0008);
				cout<<setw(4)<<setfill(' ')<<caldata[i][j]-200;
			} 
			else if(caldata[i][j]>100){
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0008);
				cout<<setw(4)<<setfill(' ')<<caldata[i][j]-100;
			} 
			else if(caldata[i][j]!=0) cout<<setw(4)<<setfill(' ')<<caldata[i][j];
			else cout<<"    ";
		}
	}
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07);
}
void Calendar::showCalendar(int ax,int ay){
	cal_x=ax;
	cal_y=ay;
	showCalendar();
}


int main(void){
	
	int num;
	
	Date A; //날짜 생성-오늘날짜로 자동 초기화 
	Calendar B; // 달력생성 
	B.setCalendar(A); //달력에 날짜 A를 적용 
	
	B.showCalendar(); //A달의 달력을 출력 
	B.showDate(); //Calendar는 Date를 상속받았으므로 Date의 함수 호출 가능 
	
	B.showCalendar(20,10); // 지정된 좌표에 달력 출력 
	
	getchar(); 
}
