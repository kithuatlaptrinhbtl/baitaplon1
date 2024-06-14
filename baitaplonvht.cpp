#include <iostream>
#include <string>
using namespace std;

class MatHang {
private:
    string ten;
    int maso;
    int soluong;
    int gianhap;
    int giaban;
public:
    MatHang() {};
    MatHang(string _ten, int _maso, int _soluong, int _gianhap, int _giaban) 
        : ten(_ten), maso(_maso), soluong(_soluong), gianhap(_gianhap), giaban(_giaban) {}
    int get_maso(){
        return maso;
    }
    int get_soluong() {
        return soluong;
    }
    int get_giaban() {
        return giaban;
    }
    int get_gianhap() {
        return gianhap;
    }
    //Hiển thị thông tin mặt hàng
    void hienThi() const{
        cout << "Ten mat hang: " << ten << endl;
        cout << "Ma so mat hang: " << maso << endl;
        cout << "So luong mat hang: " << soluong << endl;
        cout << "Gia nhap mat hang: " << gianhap << endl;
        cout << "Gia ban mat hang: " << giaban << endl;
    }
    //Sửa thông tin mặt hàng
    void suaThongTin(string _ten, int _soluong, int _gianhap, int _giaban) {
        ten = _ten;
        soluong = _soluong;
        gianhap = _gianhap;
        giaban = _giaban;
    }
};

MatHang* listMatHang = nullptr; // Mảng động lưu trữ các đối tượng Mặt hàng
int size = 0; // Kích thước hiện tại của mảng
int capacity = 2; // Sức chứa của mảng (ban đầu là 2)

void resizeArray() {
    capacity *= 2;
    MatHang* newArray = new MatHang[capacity];
    for (int i = 0; i < size; i++) {
        newArray[i] = listMatHang[i];
    }
    delete[] listMatHang;
    listMatHang = newArray;
}

void themHang(const MatHang& hang) {
    if (size == capacity) {
        resizeArray();
    }
    listMatHang[size++] = hang;
}

void suaHang(int _maso) {
    for (int i = 0; i < size; i++) {
        if (listMatHang[i].get_maso() == _maso) {
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
            listMatHang[i].suaThongTin(ten, soluong, gianhap, giaban);
            cout << "Thong tin mat hang da duoc cap nhat." << endl;
            return;
        }
    }
    cout << "Khong tim thay mat hang voi ma so " << _maso << "." << endl;
}

void deleteHang(int _maso) {
    for (int i = 0; i < size; i++) {
        if (listMatHang[i].get_maso() == _maso) {
            for (int j = i; j < size - 1; j++) {
                listMatHang[j] = listMatHang[j + 1];
            }
            size--;
            cout << "Mat hang da duoc xoa." << endl;
            return;
        }
    }
    cout << "Khong tim thay mat hang voi ma so " << _maso << "." << endl;
}

void timKiem(string query) {
    int maso = stoi(query);
    for (int i = 0; i < size; i++) {
        if (listMatHang[i].get_maso() == maso) {
            listMatHang[i].hienThi();
            return;
        }
    }
    cout << "Khong tim thay mat hang voi ma so " << query << "." << endl;
}

int main() {
    listMatHang = new MatHang[capacity];
    themHang(MatHang("Tivi", 1000, 100, 25000000, 30000000));
    themHang(MatHang("Laptop", 1001, 100, 15000000, 20000000));

    int choice;
    do {
        cout << "\nChon chuc nang:\n";
        cout << "1. Hien thi cac mat hang\n";
        cout << "2. Sua mat hang\n";
        cout << "3. Xoa mat hang\n";
        cout << "4. Tim kiem mat hang\n";
        cout << "5. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < size; i++) {
                    listMatHang[i].hienThi();
                }
                break;
            case 2: {
                int maso;
                cout << "Nhap ma so mat hang can sua: ";
                cin >> maso;
                suaHang(maso);
                break;
            }
            case 3: {
                int maso;
                cout << "Nhap ma so mat hang can xoa: ";
                cin >> maso;
                deleteHang(maso);
                break;
            }
            case 4: {
                string query;
                cout << "Nhap ma so mat hang can tim: ";
                cin >> query;
                timKiem(query);
                break;
            }
            case 5:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while (choice != 5);

    delete[] listMatHang;
    return 0;
}
