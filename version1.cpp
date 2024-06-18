#include<iostream>
#include<string.h>
using namespace std;
class MatHang{
private:
	string ten;
	int maso;
	int soluong;
	int gianhap;
	int giaban;
public:
	MatHang(){};
	MatHang(string _ten, int _maso, int _soluong, int _gianhap, int _giaban);
	void suaHang(int _maso);
	int get_maso(){
		return maso;
	}
	int get_soluong(){
		return soluong;
	}
	int get_giaban(){
		return giaban;
	}
	int get_gianhap(){
		return gianhap;
	}
	void hienThi(){
		cout<<ten<<endl;
		cout<<maso<<endl;
		cout<<soluong<<endl;
		cout<<gianhap<<endl;
		cout<<giaban<<endl;
	}
    
};

MatHang::MatHang(string _ten, int _maso, int _soluong, int _gianhap, int _giaban){
	ten=_ten;
	maso=_maso;
	soluong=_soluong;
	gianhap=_gianhap;
	giaban=_giaban;
}

class Kho{
private:
	int count;
	MatHang* Hang;
public:
	Kho(int _count=2){
		count=_count;
		Hang = new MatHang[count];
	    Hang[0]= MatHang("Tivi", 1000, 100, 25000000, 30000000);
	    Hang[1]= MatHang("Laptop", 1001, 100, 15000000, 20000000);
	}
	~Kho(){
		delete []Hang;
	}
	void hienThi(){
		for(int i=0; i<count; i++){
			cout<<"Mat hang "<<i+1<<" :\n";
			Hang[i].hienThi();
		}
	}
};

int main(){
	Kho a1;
	a1.hienThi();
	return 0;
}









