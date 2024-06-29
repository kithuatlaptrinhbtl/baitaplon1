#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dinh nghia cau truc mat hang
typedef struct {
    char ten[100];
    int maso;
    int soluong;
    int gianhap;
    int giaban;
} MatHang;

// Dinh nghia cac ham cho mat hang
void MatHang_init(MatHang* hang, const char* ten, int maso, int soluong, int gianhap, int giaban) {
    strcpy(hang->ten, ten);
    hang->maso = maso;
    hang->soluong = soluong;
    hang->gianhap = gianhap;
    hang->giaban = giaban;
}

void MatHang_hienThi(const MatHang* hang) {
    printf("Ten mat hang: %s\n", hang->ten);
    printf("Ma so mat hang: %d\n", hang->maso);
    printf("So luong mat hang: %d\n", hang->soluong);
    printf("Gia nhap mat hang: %d\n", hang->gianhap);
    printf("Gia ban mat hang: %d\n", hang->giaban);
    printf("\n");
}

// Ding nghia cau truc cua hang
typedef struct {
    char name[100];
    long distance;
} CuaHang;

// Dinh nghia cac ham cho CuaHang
void CuaHang_init(CuaHang* store, const char* name, long distance) {
    strcpy(store->name, name);
    store->distance = distance;
}

void CuaHang_Show(const CuaHang* store) {
    printf("Ten cua hang: %s\n", store->name);
    printf("Khoang cach tu kho den cua hang %s la: %ld\n", store->name, store->distance);
}

// DInh nghia cau truc Stores
typedef struct {
    CuaHang* store;
    int quantity_stores;
} Stores;

// Dinh nghia cac ham cho Stores
void Stores_init(Stores* stores, int quantity_stores) {
    stores->quantity_stores = quantity_stores;
    stores->store = (CuaHang*)malloc(quantity_stores * sizeof(CuaHang));

    CuaHang_init(&stores->store[0], "Tap hoa Trieu Minh", 40);
    CuaHang_init(&stores->store[1], "Thao bach hoa", 200);
    CuaHang_init(&stores->store[2], "Viet Truong store", 100);
}

void Stores_Add_New_Store(Stores* stores) {
    char c;
    char name[100];
    long distance;

    do {
        stores->quantity_stores++;
        stores->store = (CuaHang*)realloc(stores->store, stores->quantity_stores * sizeof(CuaHang));

        fflush(stdin);
        printf("Nhap ten cua hang ban muon them: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;

        printf("Nhap khoang cach tu kho cua ban den cua hang %s: ", name);
        scanf("%ld", &distance);

        CuaHang_init(&stores->store[stores->quantity_stores - 1], name, distance);

        printf("Da them cua hang thanh cong !!!\n");
        printf("Ban co muon them cua hang khong? (y/n): ");
        fflush(stdin);
        scanf(" %c", &c);

    } while (c == 'y');
}

void Stores_Delete_Store(Stores* stores) {
    char letter;
    char name_store[100];
    int found = 0;

    do {
        fflush(stdin);
        printf("Nhap ten cua hang ma ban muon xoa: ");
        fgets(name_store, sizeof(name_store), stdin);
        name_store[strcspn(name_store, "\n")] = 0;

        for (int i = 0; i < stores->quantity_stores; i++) {
            if (strcmp(name_store, stores->store[i].name) == 0) {
                found = 1;
                for (int j = i; j < stores->quantity_stores - 1; j++) {
                    stores->store[j] = stores->store[j + 1];
                }
                stores->quantity_stores--;
                stores->store = (CuaHang*)realloc(stores->store, stores->quantity_stores * sizeof(CuaHang));
                printf("Xoa cua hang %s thanh cong !!!\n", name_store);
                break;
            }
        }

        if (!found) {
            printf("Cua hang khong ton tai. Ban co muon tiep tuc xoa cua hang khong? (y/n): ");
        } else {
            printf("Ban co muon tiep tuc xoa cua hang khong? (y/n): ");
        }
        fflush(stdin);
        scanf(" %c", &letter);
    } while (letter == 'y');
}

void Stores_Show_Store(const Stores* stores) {
    printf("======== Cac cua hang doi tac ========\n");

    for (int i = 0; i < stores->quantity_stores; i++) {
        printf("Cua hang thu %d la:\n", i + 1);
        CuaHang_Show(&stores->store[i]);
    }
}

int Stores_Find_Store(const Stores* stores, const char* name) {
    for (int i = 0; i < stores->quantity_stores; i++) {
        if (strcmp(name, stores->store[i].name) == 0) {
            return 1;
        }
    }
    return 0;
}

void Stores_thongKeStores(const Stores* stores) {
    if (stores->quantity_stores == 0) {
        printf("Khong co cua hang nao!\n");
        return;
    }

    int max = stores->store[0].distance, tmax = 0;
    for (int i = 1; i < stores->quantity_stores; i++) {
        if (max < stores->store[i].distance) {
            max = stores->store[i].distance;
            tmax = i;
        }
    }
    printf("Thong tin cua hang xa kho nhat la: \n");
    CuaHang_Show(&stores->store[tmax]);

    int min = stores->store[0].distance, tmin = 0;
    for (int i = 1; i < stores->quantity_stores; i++) {
        if (min > stores->store[i].distance) {
            min = stores->store[i].distance;
            tmin = i;
        }
    }
    printf("Thong tin cua hang gan kho nhat la: \n");
    CuaHang_Show(&stores->store[tmin]);
}

void Stores_free(Stores* stores) {
    free(stores->store);
}

// Dinh nghia cau truc Kho
typedef struct {
    Stores stores;
    int count;
    MatHang* Hang;
    int dem;
    int demXuat;
} Kho;

// Dinh nghia cac ham cho Kho
void Kho_init(Kho* kho, int count) {
    kho->count = count;
    kho->Hang = (MatHang*)malloc(count * sizeof(MatHang));
    MatHang_init(&kho->Hang[0], "Tivi", 1, 100, 2500, 3000);
    MatHang_init(&kho->Hang[1], "Laptop", 2, 100, 1500, 2000);
    MatHang_init(&kho->Hang[2], "Den hoc", 3, 150, 1000, 1500);
    kho->dem = 0;
    kho->demXuat = 0;
    Stores_init(&kho->stores, 3);
}

void Kho_free(Kho* kho) {
    free(kho->Hang);
    Stores_free(&kho->stores);
}

void Kho_hienThi(const Kho* kho) {
    printf("========Mat hang co trong kho=======\n");
    for (int i = 0; i < kho->count; i++) {
        printf("Mat hang %d :\n", i + 1);
        MatHang_hienThi(&kho->Hang[i]);
    }
}

void Kho_hoaDonNhapKho(Kho* kho) {
    int tongtien = 0;
    printf("\n==================BILL==================\n");
    printf("Thong tin hang hoa da nhap them vao kho la: \n");
    for (int i = kho->count - kho->dem, j = 1; i < kho->count && j <= kho->dem; i++, j++) {
        printf("Mat hang %d :\n", j);
        MatHang_hienThi(&kho->Hang[i]);
        tongtien += kho->Hang[i].soluong * kho->Hang[i].gianhap;
    }
    printf("=====>Tong tien nhap hang la: %d\n", tongtien);
    kho->dem = 0;
}

void Kho_nhapKho(Kho* kho) {
    char c;
    do {
        kho->count++;
        kho->dem++;
        kho->Hang = (MatHang*)realloc(kho->Hang, kho->count * sizeof(MatHang));

        char ten[100];
        int maso, soluong, gianhap, giaban;
        fflush(stdin);
        printf("Nhap ten san pham muon them: ");
        fgets(ten, sizeof(ten), stdin);
        ten[strcspn(ten, "\n")] = 0;

        printf("Nhap ma so san pham: ");
        scanf("%d", &maso);
        printf("Nhap so luong: ");
        scanf("%d", &soluong);
        printf("Nhap gia nhap kho: ");
        scanf("%d", &gianhap);
        printf("Nhap gia xuat kho: ");
        scanf("%d", &giaban);

        MatHang_init(&kho->Hang[kho->count - 1], ten, maso, soluong, gianhap, giaban);
        printf("Hang da duoc nhap kho thanh cong !\n");
        printf("Ban co muon nhap kho nua khong? (y/n): ");
        fflush(stdin);
        scanf(" %c", &c);
    } while (c == 'y');

    Kho_hoaDonNhapKho(kho);
}

void Kho_timKiemHang(const Kho* kho) {
    int maso;
    int t = kho->count;
    do {
        printf("Nhap ma so mat hang can tim kiem: ");
        scanf("%d", &maso);
        for (int i = 0; i < kho->count; i++) {
            if (kho->Hang[i].maso == maso) {
                t = i;
                break;
            }
        }
        if (t == kho->count) {
            printf("Mat hang voi ma so %d khong ton tai, vui long nhap lai!\n", maso);
        }
    } while (t == kho->count);

    printf("Thong tin hang hoa dang tim kiem la: \n");
    MatHang_hienThi(&kho->Hang[t]);
}

void Kho_suaHang(Kho* kho) {
    int maso;
    int t = kho->count;
    do {
        printf("Nhap ma so mat hang can sua: ");
        scanf("%d", &maso);
        for (int i = 0; i < kho->count; i++) {
            if (kho->Hang[i].maso == maso) {
                t = i;
                break;
            }
        }
        if (t == kho->count) {
            printf("Mat hang voi ma so %d khong ton tai, vui long nhap lai!\n", maso);
        }
    } while (t == kho->count);

    char ten[100];
    int soluong, gianhap, giaban;
    printf("Nhap ten moi: ");
    fflush(stdin);
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = 0;
    printf("Nhap so luong moi: ");
    scanf("%d", &soluong);
    printf("Nhap gia nhap moi: ");
    scanf("%d", &gianhap);
    printf("Nhap gia ban moi: ");
    scanf("%d", &giaban);

    MatHang_init(&kho->Hang[t], ten, kho->Hang[t].maso, soluong, gianhap, giaban);
    printf("Thong tin mat hang da duoc cap nhat.\n");
}

void Kho_xoaHang(Kho* kho) {
    int maso;
    int t = kho->count;
    do {
        printf("Nhap ma so mat hang can xoa: ");
        scanf("%d", &maso);
        for (int i = 0; i < kho->count; i++) {
            if (kho->Hang[i].maso == maso) {
                t = i;
                break;
            }
        }
        if (t == kho->count) {
            printf("Mat hang voi ma so %d khong ton tai, vui long nhap lai!\n", maso);
        }
    } while (t == kho->count);

    for (int i = t; i < kho->count - 1; i++) {
        kho->Hang[i] = kho->Hang[i + 1];
    }
    kho->count--;
    kho->Hang = (MatHang*)realloc(kho->Hang, kho->count * sizeof(MatHang));
    printf("Da xoa thanh cong mat hang khoi kho!\n");
}

void Kho_XuatKho(Kho* kho) {
    char name_item[100];
    char store_name[100];
    double sum_money = 0.0;
    char c;
    MatHang* HangXuat = (MatHang*)malloc(20 * sizeof(MatHang));

    do {
        fflush(stdin);
        printf("Nhap ten san pham can xuat: ");
        fgets(name_item, sizeof(name_item), stdin);
        name_item[strcspn(name_item, "\n")] = 0;

        double quantity;
        printf("Nhap so luong can xuat: ");
        scanf("%lf", &quantity);

        fflush(stdin);
        printf("Nhap cua hang ban muon xuat: ");
        fgets(store_name, sizeof(store_name), stdin);
        store_name[strcspn(store_name, "\n")] = 0;

        int found = 0;

        for (int i = 0; i < kho->count; i++) {
            if (strcmp(name_item, kho->Hang[i].ten) == 0 && quantity <= kho->Hang[i].soluong) {
                if (Stores_Find_Store(&kho->stores, store_name)) {
                    kho->demXuat++;
                    sum_money += quantity * kho->Hang[i].giaban;
                    MatHang_init(&HangXuat[kho->demXuat - 1], kho->Hang[i].ten, kho->Hang[i].maso, quantity, kho->Hang[i].gianhap, kho->Hang[i].giaban);
                    kho->Hang[i].soluong -= quantity;
                    printf("Xuat hang %s thanh cong den cua hang %s!!!\n", name_item, store_name);
                    found = 1;
                    break;
                } else {
                    printf("Cua hang khong ton tai!!!\n");
                }
            }
        }

        if (!found) {
            printf("San pham khong ton tai hoac so luong khong du.\n");
        }

        printf("Ban co muon xuat tiep khong? (y/n): ");
        fflush(stdin);
        scanf(" %c", &c);
    } while (c == 'y');

    printf("\n==================BILL==================\n");
    printf("Thong tin hang hoa da xuat di la: \n");
    for (int i = 0; i < kho->demXuat; i++) {
        printf("Mat hang %d:\n", i + 1);
        printf("Ten mat hang: %s\n", HangXuat[i].ten);
        printf("So luong xuat kho: %d\n", HangXuat[i].soluong);
        printf("Xuat den cua hang: %s\n", store_name);
    }
    printf("=====>Tong tien thu duoc sau khi xuat hang la: %.2f\n", sum_money);
    kho->demXuat = 0;
    free(HangXuat);
}

void Kho_thongKeKho(const Kho* kho) {
    int max = kho->Hang[0].giaban, tmax = 0;
    for (int i = 1; i < kho->count; i++) {
        if (max < kho->Hang[i].giaban) {
            max = kho->Hang[i].giaban;
            tmax = i;
        }
    }
    printf("Thong tin hang co gia ban cao nhat la: \n");
    MatHang_hienThi(&kho->Hang[tmax]);

    int min = kho->Hang[0].giaban, tmin = 0;
    for (int i = 1; i < kho->count; i++) {
        if (min > kho->Hang[i].giaban) {
            min = kho->Hang[i].giaban;
            tmin = i;
        }
    }
    printf("Thong tin hang co gia ban thap nhat la: \n");
    MatHang_hienThi(&kho->Hang[tmin]);
}

void clear_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    char name[100], pass[100];
    printf("Vui long dang nhap vao he thong.\n");
    do {
        printf("Nhap ten nhan vien: "); fflush(stdin); fgets(name, sizeof(name), stdin); name[strcspn(name, "\n")] = 0;
        printf("Nhap mat khau: "); fflush(stdin); fgets(pass, sizeof(pass), stdin); pass[strcspn(pass, "\n")] = 0;
        if (strcmp(name, "admin") != 0 || strcmp(pass, "admin") != 0) {
            printf("Ten hoac mat khau khong dung, vui long thu lai !!\n");
        } else {
            printf("Dang nhap thanh cong !!\n");
        }
    } while (strcmp(name, "admin") != 0 || strcmp(pass, "admin") != 0);

    int n;
    Kho a1;
    Kho_init(&a1, 3);
    Stores b1;
    Stores_init(&b1, 3);

    do {
        printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t|\t1. Hien thi.                            |\n");
        printf("\t|\t2. Nhap.\t\t\t\t|\n");
        printf("\t|\t3. Xuat hang.\t\t\t\t|\n");
        printf("\t|\t4. Sua hang.\t\t\t\t|\n");
        printf("\t|\t5. Xoa.\t\t\t\t\t|\n");
        printf("\t|\t6. Tim kiem thong tin hang hoa.\t\t|\n");
        printf("\t|\t7. Thong ke.                            |\n");
        printf("\t|\t8. Thoat chuong trinh.\t\t\t|\n");
        printf("\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

        printf("\nNhap lua chon cua ban > ");
        scanf("%d", &n);

        switch (n) {
            case 1: {
                int c;
                printf("1. Hien thi tat ca cac mat hang trong kho.\n");
                printf("2. Hien thi tat ca cua hang.\n");
                printf("Nhap lua chon cua ban > ");
                scanf("%d", &c);

                if (c == 1)
                    Kho_hienThi(&a1);
                else if (c == 2)
                    Stores_Show_Store(&b1);
                break;
            }
            case 2: {
                int a;
                printf("1. Nhap hang.\n");
                printf("2. Nhap them cua hang.\n");
                printf("Nhap lua chon cua ban > ");
                scanf("%d", &a);

                if (a == 1)
                    Kho_nhapKho(&a1);
                else if (a == 2)
                    Stores_Add_New_Store(&b1);
                break;
            }
            case 3:
                Kho_hienThi(&a1);
                Stores_Show_Store(&b1);
                Kho_XuatKho(&a1);
                break;
            case 4:
                Kho_suaHang(&a1);
                break;
            case 5: {
                int b;
                printf("1. Xoa hang.\n");
                printf("2. Xoa cua hang.\n");
                printf("Nhap lua chon cua ban > ");
                scanf("%d", &b);

                if (b == 1)
                    Kho_xoaHang(&a1);
                else if (b == 2)
                    Stores_Delete_Store(&b1);
                break;
            }
            case 6:
                Kho_timKiemHang(&a1);
                break;
            case 7: {
                int t;
                printf("1. Thong ke hang hoa.\n");
                printf("2. Thong ke kho.\n");
                printf("Nhap lua chon cua ban > ");
                scanf("%d", &t);

                if (t == 1)
                    Kho_thongKeKho(&a1);
                else if (t == 2)
                    Stores_thongKeStores(&b1);
                break;
            }
            case 8:
                break;
            default:
                printf("Nhap sai. Vui long nhap lai !!!\n");
        }
    } while (n != 8);

    Kho_free(&a1);
    Stores_free(&b1);

    return 0;
}

