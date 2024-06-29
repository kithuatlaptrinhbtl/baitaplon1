#include <iostream>

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

	std::string get_name() const
	{
	    return ten ;
	}

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

	void set_soluong(int _soluong)
	{
	    soluong = _soluong ;
	}

	void hienThi(){
		cout<<"Ten mat hang: "<<ten<<endl;
		cout<<"Ma so mat hang: "<<maso<<endl;
		cout<<"So luong mat hang: "<<soluong<<endl;
		cout<<"Gia nhap mat hang: "<<gianhap<<endl;
		cout<<"Gia ban mat hang: "<<giaban<<endl;
		cout<<"\n";
	}
	void suaHang(string _ten, int _soluong, int _gianhap, int _giaban) {
        ten = _ten;
        soluong = _soluong;
        gianhap = _gianhap;
        giaban = _giaban;
    }

    void Show()
	{
	    std::cout<<"Ten mat hang : "<<ten<<std::endl ;
	    std::cout<<"Ma so mat hang : "<<maso<<std::endl ;
	    std::cout<<"So luong mat hang la : "<<soluong<<std::endl ;
	    std::cout<<"Gia nhap mat hang la : "<<gianhap<<std::endl ;
	    std::cout<<"Gia ban mat hang la : "<<giaban<<std::endl ;
	    std::cout<<std::endl ;
	}
};

MatHang::MatHang(string _ten, int _maso, int _soluong, int _gianhap, int _giaban){
	ten=_ten;
	maso=_maso;
	soluong=_soluong;
	gianhap=_gianhap;
	giaban=_giaban;
}

class CuaHang{
private :
    std::string name ;
    long distance ;

public :
    CuaHang(std::string _name="" , long _distance=0)
    {
        name = _name ;
        distance = _distance ;
    }

    std::string get_name() const
    {
        return name ;
    }

    long get_distance() const
    {
        return distance ;
    }

    void Show()
    {
        std::cout<<"\nTen cua hang : "<<name<<std::endl ;
        std::cout<<"Khoang cach tu kho den cua hang "<<name<<" la : "<<distance<<std::endl ;
    }
} ;

class Stores{
private :
    CuaHang *store ;
    int quantity_stores ;
    static int counts ;

public :
    Stores(int _quantity_stores=3)
    {
        quantity_stores  = _quantity_stores ;
        store = new CuaHang [quantity_stores] ;

        store[0] = CuaHang("Tap hoa Trieu Minh" , 40) ;
        store[1] = CuaHang("Thao bach hoa" , 200) ;
        store[2] = CuaHang("Viet Truong store", 100);
    }

    int getQuantity_Stores(){
    	return quantity_stores;
	}
    void Add_New_Store()
    {
        char c ;
        std::string _name ;
        long _distance ;

        do{
            quantity_stores++ ;
            counts++ ;

            CuaHang *newStore = new CuaHang [quantity_stores] ;
            for(int i=0 ; i<quantity_stores-1 ; i++)
            {
                newStore[i] = store[i] ;
            }

            delete [] store ;
            store = newStore ;

            fflush(stdin) ;
            std::cout<<"Nhap ten cua hang ban muon them : " ;
            std::getline(std::cin , _name) ;
            std::cout<<"Nhap khoang cach tu kho cua ban den cua hang "<<_name<<" : " ;
            std::cin>>_distance ;

            store[quantity_stores-1] = CuaHang(_name , _distance) ;

            std::cout<<"Da them cua hang thanh cong !!!\n" ;
            std::cout<<"Ban co muon them cua hang khong? (y/n) : " ;
            std::cin>>c ;

        }while(c == 'y') ;
    }

    void Delete_Store()
    {
        fflush(stdin) ;
        char letter ;
        std::string name_store ;
        int Count = 0 ;

        do{
           std::cout<<"Nhap ten cua hang ma ban muon xoa : " ;
           std::getline(std::cin , name_store) ;

           for(int i=0 ; i<quantity_stores ; i++)
           {
                if(name_store == store[i].get_name())
                {
                    Count++ ;
                }

           }
           if(Count == 0)
                std::cout<<"Cua hang khong ton tai. Ban co muon them cua hang khong?\n" ;
           else
           {
                    quantity_stores-- ;
                    counts-- ;

                    CuaHang *Del_Store = new CuaHang [quantity_stores] ;

                    for(int i=0,j=0 ; i<quantity_stores ; i++)
                    {
                        Del_Store[j++] = store[i] ;
                    }

                    delete [] store ;
                    store = Del_Store ;

                    std::cout<<"Xoa cua hang "<<name_store<<" thanh cong !!!\n" ;
           }
           std::cout<<"Ban co muon tiep tuc xoa cua hang khong? (y/n) : " ;
           std::cin>>letter ;
        }while(letter == 'y') ;
    }

    void Show_Store()
    {
        std::cout<<"======== Cac cua hang doi tac ========\n" ;

        for(int i=0 ; i<quantity_stores ; i++)
        {
            std::cout<<"\nCua hang thu "<<i+1<<" la :" ;
            store[i].Show() ;
        }
    }

    bool Find_Store(std::string &_name)
    {
        int dem = 0 ;

        for(int i=0 ; i<quantity_stores ; i++)
        {
            if(_name.compare(store[i].get_name()) == 0)
            {
                dem++ ;
            }
        }

        if(dem != 0)
            return true ;
        else
            return false ;
    }
    void thongKeStores(){
    	int max=store[0].get_distance(), tmax=0;
    	for(int i=1; i<quantity_stores; i++){
    	if(max<store[i].get_distance()){
    		max=store[i].get_distance();
    		tmax=i;
	    }
	}
        cout<<"\nThong tin cua hang xa kho nhat la: ";
		store[tmax].Show();
		
		int min=store[0].get_distance(), tmin=0;
    	for(int i=1; i<quantity_stores; i++){
    	if(min>store[i].get_distance()){
    		min=store[i].get_distance();
    		tmin=i;
	    }
	}
        cout<<"\nThong tin cua hang gan kho nhat la: ";
		store[tmin].Show();
	}
    ~Stores()
    {
        delete [] store ;
    }
};

int Stores::counts = 0 ;

class Kho : public Stores{
private:
	int count;
	MatHang* Hang;
	static int dem , demXuat;
public:
	Kho(int _count=3){
		count=_count;
		Hang = new MatHang[count];
	    Hang[0]= MatHang("Tivi", 1, 100, 2500, 3000);
	    Hang[1]= MatHang("Laptop", 2, 100, 1500, 2000);
	    Hang[2]= MatHang("Den hoc", 3, 150, 1000, 1500);
	}
	~Kho(){
		delete []Hang;
	}
	void hienThi(){
		cout<<"========Mat hang co trong kho=======\n";
		for(int i=0; i<count; i++){
			cout<<"\nMat hang "<<i+1<<" :\n";
			Hang[i].hienThi();
		}
	}

	 void hoaDonNhapKho(){
    	int tongtien=0;
    	cout<<"\n==================BILL==================\n";
    	cout<<"Thong tin hang hoa da nhap them vao kho la: "<<endl;
    	for(int i=count-dem, j=1;i<count, j<=dem; i++, j++ ){
    		cout<<"Mat hang "<<j<<" :"<<endl;
    		Hang[i].hienThi();
    		int c= Hang[i].get_soluong(), d=Hang[i].get_gianhap();
    		tongtien+=c*d;
		}
		cout<<"=====>Tong tien nhap hang la: "<< tongtien<<std::endl ;
		dem=0;
	}

	void nhapKho(){
		char c;
		do{
			count++;
			dem++;
       		MatHang* newHang = new MatHang[count];
        	for (int i = 0; i < count - 1; i++) {
            newHang[i] = Hang[i];
        }
        delete[] Hang;
        Hang = newHang;

        string _ten;
        int _maso, _soluong, _gianhap, _giaban;
        cout << "Nhap ten san pham muon them: ";fflush(stdin); getline(cin, _ten);
        cout << "Nhap ma so san pham: "; cin >> _maso;
        cout << "Nhap so luong: "; cin >> _soluong;
        cout << "Nhap gia nhap kho: "; cin >> _gianhap;
        cout << "Nhap gia xuat kho: "; cin >> _giaban;
        Hang[count - 1] = MatHang(_ten, _maso, _soluong, _gianhap, _giaban);
        cout<<"Hang da duoc nhap kho thanh cong !"<<endl;
        cout<<"\nBan co muon nhap kho nua khong ?(y/n)"; cin >>c;
		cin.ignore();
        } while (c=='y');

        hoaDonNhapKho() ;
    }

	void timKiemHang(){
		int _maso;
		int t=count;
		do{
			cout<<"Nhap ma so mat hang can tim kiem: ";cin>>_maso;
        for (int i = 0; i < count; i++)
            if (Hang[i].get_maso() == _maso){
            t=i;
            break;
            }
            if(t==count)
            cout<<"Mat hang voi ma so "<<_maso<<" khong ton tai, vui long nhap lai!\n";
        } while(t==count);
        cout<<"Thong tin hang hoa dang tim kiem la: \n";
        Hang[t].hienThi();
	}
	void suaHang() {
		int _maso;
		int t=count;
		do{
			cout<<"Nhap ma so mat hang can sua: ";cin>>_maso;
        for (int i = 0; i < count; i++)
            if (Hang[i].get_maso() == _maso){
            t=i;
            break;
            }
            if(t==count)
            cout<<"Mat hang voi ma so "<<_maso<<" khong ton tai, vui long nhap lai!\n";
        } while(t==count);
                string ten;
                int soluong, gianhap, giaban;
                cout << "Nhap ten moi: ";
                cin.ignore();
                getline(cin, ten);
                cout << "Nhap so luong moi: ";
                cin >> soluong;
                cout << "Nhap gia nhap moi: ";
                cin >> gianhap;
                cout << "Nhap gia ban moi: ";
                cin >> giaban;
                Hang[t].suaHang(ten, soluong, gianhap, giaban);
                cout << "Thong tin mat hang da duoc cap nhat." << endl;
                return;
            }
    void xoaHang(){
    	int _maso;
		int t=count;
		do{
			cout<<"Nhap ma so mat hang can xoa: ";cin>>_maso;
        for (int i = 0; i < count; i++)
            if (Hang[i].get_maso() == _maso){
            t=i;
            break;
            }
            if(t==count)
            cout<<"Mat hang voi ma so "<<_maso<<" khong ton tai, vui long nhap lai!\n";
        } while(t==count);
        MatHang* newHang = new MatHang[count-1];
        for(int i=0; i<count-1; i++){
        	if(i<t) newHang[i]=Hang[i];
        	else newHang[i]=Hang[i+1];
		}
		delete[]Hang;
		count=count-1;
		Hang = new MatHang[count];
		for(int i=0; i<count; i++)
		Hang[i]=newHang[i];
		delete[]newHang;
		cout<<"Da xoa thanh cong mat hang khoi kho!";
	}

	void XuatKho()
	{
	    int indexStore = 1 ;
	    string name_item , store_name ;
        double sum_money=0.0 ;
        char c ;
        MatHang* HangXuat = new MatHang[20];
        std::cout<<"\n" ;

        do {
        fflush(stdin);
        std::cout << "Nhap ten san pham can xuat: ";
        std::getline(std::cin, name_item);
        double quantity;
        std::cout << "Nhap so luong can xuat: ";
        std::cin >> quantity;
        fflush(stdin) ;
        std::cout<<"Nhap cua hang ban muon xuat : " ;
        std::getline(std::cin , store_name) ;

        bool found = false;

        for (int i = 0; i < count; i++) {
            if (name_item == Hang[i].get_name() && quantity <= Hang[i].get_soluong()) {
                if(Find_Store(store_name))
                {
                    demXuat++;
                    sum_money += quantity * Hang[i].get_giaban();
                    HangXuat[demXuat - 1] = MatHang(Hang[i].get_name(),
                                                    Hang[i].get_maso(),
                                                    quantity,
                                                    Hang[i].get_gianhap(),
                                                    Hang[i].get_giaban());
                    Hang[i].set_soluong(Hang[i].get_soluong()-quantity);
                    std::cout << "Xuat hang " << name_item << " thanh cong den cua hang "<<store_name<<" !!!" << std::endl;
                    found = true;
                    break;
                }
                else
                    std::cout<<"Cua hang khong ton tai !!!\n" ;
            }
        }
        if (!found) {
            std::cout << "San pham khong ton tai hoac so luong khong du.\n";
        }

        std::cout << "Ban co muon xuat tiep khong? (y/n): ";
        std::cin >> c;
    } while (c == 'y');

        cout<<"\n==================BILL==================\n";
        cout<<"Thong tin hang hoa da xuat di la: "<<endl;
        for(int i=0; i<demXuat; i++){
        cout<<"Mat hang "<<i+1<<": "<<endl;
        cout<<"Ten mat hang: "<<HangXuat[i].get_name()<<endl;
        cout<<"So luong xuat kho: "<<HangXuat[i].get_soluong()<<endl;
        cout<<"Xuat den cua hang : "<<store_name<<std::endl ;
        }
        cout<<"=====>Tong tien thu duoc sau khi xuat hang la: "<<sum_money<<std::endl ;
        demXuat=0;
        delete[]HangXuat;
    }
    void thongKeKho(){
    	int max=Hang[0].get_giaban(), tmax=0;
    	for(int i=1; i<count; i++){
    	if(max<Hang[i].get_giaban()){
		    max=Hang[i].get_giaban();
    		tmax=i;
        }
    }
        cout<<"Thong tin hang co gia ban cao nhat la: \n";
		Hang[tmax].hienThi();
		int min=Hang[0].get_giaban(), tmin=0;
    	for(int i=1; i<count; i++){
    	if(min>Hang[i].get_giaban()){
		    min=Hang[i].get_giaban();
    		tmin=i;
        }
    }
		cout<<"Thong tin hang co gia ban thap nhat la: \n";
		Hang[tmin].hienThi();
	}
};

int Kho::dem=0;
int Kho::demXuat=0;

int main()
{
	string name, pass;
	cout<<"Vui long dang nhap vao he thong.\n";
	do{
	cout<<"Nhap ten nhan vien: "; fflush(stdin); getline(cin, name);
	cout<<"Nhap mat khau: "; fflush(stdin); getline(cin, pass);
	if(name!="admin"||pass!="admin") cout<<"Ten hoac mat khau khong dung, vui long thu lai !!\n";
	else cout<<"Dang nhap thanh cong !!";
	}while(name!="admin"||pass!="admin");
    int n ;
    Kho a1 ;
    Stores b1 ;

    do{
        std::cout<<"\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" ;
        std::cout<<"\t|\t1. Hien thi.                            |\n" ;
        std::cout<<"\t|\t2. Nhap.\t\t\t\t|\n" ;
        std::cout<<"\t|\t3. Xuat hang.\t\t\t\t|\n" ;
        std::cout<<"\t|\t4. Sua hang.\t\t\t\t|\n" ;
        std::cout<<"\t|\t5. Xoa.\t\t\t\t\t|\n" ;
        std::cout<<"\t|\t6. Tim kiem thong tin hang hoa.\t\t|\n" ;
        std::cout<<"\t|\t7. Thong ke.                            |\n" ;
        std::cout<<"\t|\t8. Thoat chuong trinh.\t\t\t|\n" ;
        std::cout<<"\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n" ;

        std::cout<<"\nNhap lua chon cua ban > " ;
        std::cin>>n ;

        switch(n)
        {
            case 1 :
                int c ;

                std::cout<<"1. Hien thi tat ca cac mat hang trong kho.\n" ;
                std::cout<<"2. Hien thi tat ca cua hang.\n" ;

                std::cout<<"Nhap lua chon cua ban > " ;
                std::cin>>c ;

                if(c == 1)
                    a1.hienThi() ;
                else if(c == 2)
                    b1.Show_Store() ;

                break ;
            case 2 :
                int a ;

                std::cout<<"1. Nhap hang.\n" ;
                std::cout<<"2. Nhap them cua hang.\n" ;

                std::cout<<"Nhap lua chon cua ban > " ;
                std::cin>>a ;

                if(a == 1)
                    a1.nhapKho() ;
                else if(a == 2)
                    b1.Add_New_Store() ;

                break ;
            case 3 :
            	a1.hienThi();
            	b1.Show_Store();
                a1.XuatKho() ;
                break ;
            case 4 :
                a1.suaHang() ;
                break ;
            case 5 :
                int b ;

                std::cout<<"1. Xoa hang.\n" ;
                std::cout<<"2. Xoa cua hang.\n" ;

                std::cout<<"Nhap lua chon cua ban > " ;
                std::cin>>b ;

                if(b == 1)
                    a1.xoaHang() ;
                else if(b == 2)
                    b1.Delete_Store() ;

                break ;
            case 6 :
                a1.timKiemHang() ;
                break ;
            case 7 :
                int t ;

                std::cout<<"1. Thong ke hang hoa.\n" ;
                std::cout<<"2. Thong ke kho.\n" ;

                std::cout<<"Nhap lua chon cua ban > " ;
                std::cin>>t ;
                if(t==1)
                    a1.thongKeKho();
                else if(t==2)
                    b1.thongKeStores();
                break;
            case 8 :
                break ;
            default :
                std::cout<<"Nhap sai. Vui long nhap lai !!!\n" ;
        }
    }while(n != 8) ;

    return 0;
}
