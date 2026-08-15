#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// ================= HÀM HỖ TRỢ =================
int UCLN(int a, int b) {
    a = abs(a); b = abs(b);
    if (a == 0 || b == 0) return a + b;
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

// ================= CHỨC NĂNG 1 =================
void chuc_nang_1() {
    float n;
    printf("--- 1. Kiem tra so nguyen ---\n");
    printf("Nhap vao 1 so: ");
    scanf("%f", &n);

    if (n == (int)n) {
        int x = (int)n;
        printf("%.0f la so nguyen.\n", n);
        
        // Kiem tra nguyen to
        int isPrime = 1;
        if (x < 2) isPrime = 0;
        else {
            for (int i = 2; i <= sqrt(x); i++) {
                if (x % i == 0) { isPrime = 0; break; }
            }
        }
        if (isPrime) printf("%d la so nguyen to.\n", x);
        else printf("%d khong phai la so nguyen to.\n", x);

        // Kiem tra chinh phuong
        int sq = sqrt(x);
        if (sq * sq == x) printf("%d la so chinh phuong.\n", x);
        else printf("%d khong phai la so chinh phuong.\n", x);
    } else {
        printf("%f khong phai la so nguyen.\n", n);
    }
}

// ================= CHỨC NĂNG 2 =================
void chuc_nang_2() {
    int a, b;
    printf("--- 2. Tim UCLN va BCNN ---\n");
    printf("Nhap 2 so nguyen a va b: ");
    scanf("%d %d", &a, &b);
    
    if (a == 0 && b == 0) {
        printf("Khong co UCLN va BCNN.\n");
    } else {
        int ucln = UCLN(a, b);
        int bcnn = (abs(a * b)) / ucln;
        printf("Uoc so chung lon nhat: %d\n", ucln);
        printf("Boi so chung nho nhat: %d\n", bcnn);
    }
}

// ================= CHỨC NĂNG 3 =================
void chuc_nang_3() {
    int start, end;
    printf("--- 3. Tinh tien Karaoke ---\n");
    do {
        printf("Nhap gio bat dau (12 - 23): "); scanf("%d", &start);
        printf("Nhap gio ket thuc (12 - 23): "); scanf("%d", &end);
        if (start < 12 || start > 23 || end < 12 || end > 23 || start >= end) {
            printf("Gio khong hop le, vui long nhap lai!\n");
        }
    } while (start < 12 || start > 23 || end < 12 || end > 23 || start >= end);

    int hours = end - start;
    float total = 0;

    if (hours <= 3) {
        total = hours * 150000;
    } else {
        total = 3 * 150000 + (hours - 3) * 150000 * 0.7; // Giam 30% tu gio thu 4
    }

    if (start >= 14 && start <= 17) {
        total = total * 0.9; // Giam them 10%
    }
    printf("Tong tien can thanh toan: %.0f VND\n", total);
}

// ================= CHỨC NĂNG 4 =================
void chuc_nang_4() {
    float kwh, tien = 0;
    printf("--- 4. Tinh tien dien ---\n");
    printf("Nhap so kWh dien su dung: ");
    scanf("%f", &kwh);

    if (kwh < 0) {
        printf("So kWh khong hop le.\n");
        return;
    }
    
    if (kwh <= 50) tien = kwh * 1.678;
    else if (kwh <= 100) tien = 50 * 1.678 + (kwh - 50) * 1.734;
    else if (kwh <= 200) tien = 50 * 1.678 + 50 * 1.734 + (kwh - 100) * 2.014;
    else if (kwh <= 300) tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + (kwh - 200) * 2.536;
    else if (kwh <= 400) tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + (kwh - 300) * 2.834;
    else tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + 100 * 2.834 + (kwh - 400) * 2.927;

    printf("So tien can phai tra: %.3f\n", tien);
}

// ================= CHỨC NĂNG 5 =================
void chuc_nang_5() {
    int tien;
    int menh_gia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    printf("--- 5. Chuc nang doi tien ---\n");
    printf("Nhap so tien can doi: ");
    scanf("%d", &tien);

    printf("Menh gia tien duoc doi ra:\n");
    for (int i = 0; i < 9; i++) {
        int so_to = tien / menh_gia[i];
        if (so_to > 0) {
            printf("%d to %d\n", so_to, menh_gia[i]);
            tien %= menh_gia[i];
        }
    }
}

// ================= CHỨC NĂNG 6 =================
void chuc_nang_6() {
    float tien_vay;
    printf("--- 6. Tinh lai suat vay ngan hang tra gop ---\n");
    printf("Nhap so tien muon vay: ");
    scanf("%f", &tien_vay);

    float goc_phai_tra = tien_vay / 12;
    float tien_con_lai = tien_vay;

    printf("%-10s %-15s %-15s %-15s %-15s\n", "Ky han", "Lai phai tra", "Goc phai tra", "Tien phai tra", "Tien con lai");
    for (int i = 1; i <= 12; i++) {
        float lai_phai_tra = tien_con_lai * 0.05; // 5% lai tren du no giam dan
        float so_tien_phai_tra = goc_phai_tra + lai_phai_tra;
        tien_con_lai -= goc_phai_tra;
        if(tien_con_lai < 0) tien_con_lai = 0; // Tranh sai so

        printf("%-10d %-15.0f %-15.0f %-15.0f %-15.0f\n", i, lai_phai_tra, goc_phai_tra, so_tien_phai_tra, tien_con_lai);
    }
}

// ================= CHỨC NĂNG 7 =================
void chuc_nang_7() {
    float phan_tram_vay;
    float gia_xe = 500000000; // 500 trieu
    printf("--- 7. Vay tien mua xe ---\n");
    printf("Nhap so phan tram vay toi da (VD: 80): ");
    scanf("%f", &phan_tram_vay);

    float tien_vay = gia_xe * (phan_tram_vay / 100);
    float tra_truoc = gia_xe - tien_vay;
    
    int thoi_han_thang = 24 * 12; // 24 nam
    float lai_suat_thang = 0.072 / 12; // 7.2% / nam
    
    float goc_hang_thang = tien_vay / thoi_han_thang;
    float lai_hang_thang = tien_vay * lai_suat_thang; // Lai co dinh
    float phai_tra_hang_thang = goc_hang_thang + lai_hang_thang;

    printf("Gia tri xe: %.0f VND\n", gia_xe);
    printf("So tien phai tra lan dau (Tra truoc): %.0f VND\n", tra_truoc);
    printf("So tien phai tra hang thang: %.0f VND\n", phai_tra_hang_thang);
}

// ================= CHỨC NĂNG 8 =================
struct SinhVien {
    char hoTen[50];
    float diem;
    char hocLuc[20];
};

void chuc_nang_8() {
    int n;
    printf("--- 8. Sap xep thong tin sinh vien ---\n");
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    struct SinhVien sv[100];

    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Ho ten: ");
        while (getchar() != '\n'); // Xoa buffer
        gets(sv[i].hoTen); // Trong C moi co the dung fgets(sv[i].hoTen, 50, stdin) cho an toan
        printf("Diem: ");
        scanf("%f", &sv[i].diem);

        if (sv[i].diem >= 9.0) strcpy(sv[i].hocLuc, "Xuat sac");
        else if (sv[i].diem >= 8.0) strcpy(sv[i].hocLuc, "Gioi");
        else if (sv[i].diem >= 6.5) strcpy(sv[i].hocLuc, "Kha");
        else if (sv[i].diem >= 5.0) strcpy(sv[i].hocLuc, "Trung binh");
        else strcpy(sv[i].hocLuc, "Yeu");
    }

    // Sap xep giam dan
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diem < sv[j].diem) {
                struct SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }

    printf("\n--- Danh sach sau khi sap xep ---\n");
    for (int i = 0; i < n; i++) {
        printf("Ten: %-20s | Diem: %.1f | Hoc luc: %s\n", sv[i].hoTen, sv[i].diem, sv[i].hocLuc);
    }
}

// ================= CHỨC NĂNG 9 =================
void chuc_nang_9() {
    int so1, so2;
    printf("--- 9. Game FPOLY-LOTT ---\n");
    printf("Nhap vao so thu nhat (01 - 15): "); scanf("%d", &so1);
    printf("Nhap vao so thu hai (01 - 15): "); scanf("%d", &so2);

    srand(time(0));
    int rand1 = rand() % 15 + 1;
    int rand2 = rand() % 15 + 1;

    printf("Ket qua quay so: %02d va %02d\n", rand1, rand2);

    int count = 0;
    if (so1 == rand1 || so1 == rand2) count++;
    if (so2 == rand1 || so2 == rand2) count++;

    if (count == 2) printf("Chuc mung ban da trung GIAI NHAT!\n");
    else if (count == 1) printf("Chuc mung ban da trung GIAI NHI!\n");
    else printf("Chuc ban may man lan sau!\n");
}

// ================= CHỨC NĂNG 10 =================
struct PhanSo {
    int tu, mau;
};

void rut_gon(struct PhanSo *ps) {
    int ucln = UCLN(ps->tu, ps->mau);
    ps->tu /= ucln;
    ps->mau /= ucln;
}

void chuc_nang_10() {
    struct PhanSo ps1, ps2, tong, hieu, tich, thuong;
    printf("--- 10. Tinh toan phan so ---\n");
    printf("Nhap phan so 1 (tu mau): "); scanf("%d %d", &ps1.tu, &ps1.mau);
    printf("Nhap phan so 2 (tu mau): "); scanf("%d %d", &ps2.tu, &ps2.mau);

    if (ps1.mau == 0 || ps2.mau == 0) {
        printf("Mau so phai khac 0!\n"); return;
    }

    tong.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    tong.mau = ps1.mau * ps2.mau;
    rut_gon(&tong);

    hieu.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    hieu.mau = ps1.mau * ps2.mau;
    rut_gon(&hieu);

    tich.tu = ps1.tu * ps2.tu;
    tich.mau = ps1.mau * ps2.mau;
    rut_gon(&tich);

    thuong.tu = ps1.tu * ps2.mau;
    thuong.mau = ps1.mau * ps2.tu;
    rut_gon(&thuong);

    printf("Tong: %d/%d\n", tong.tu, tong.mau);
    printf("Hieu: %d/%d\n", hieu.tu, hieu.mau);
    printf("Tich: %d/%d\n", tich.tu, tich.mau);
    printf("Thuong: %d/%d\n", thuong.tu, thuong.mau);
}

// ================= HÀM MAIN (MENU) =================
int main() {
    int choice;
    do {
        printf("\n================= MENU =================\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim UCLN va BCNN cua 2 so\n");
        printf("3. Chuong trinh tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT (2/15)\n");
        printf("10. Chuong trinh tinh toan phan so\n");
        printf("0. Thoat chuong trinh\n");
        printf("========================================\n");
        printf("Chon chuc nang (0-10): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: chuc_nang_1(); break;
            case 2: chuc_nang_2(); break;
            case 3: chuc_nang_3(); break;
            case 4: chuc_nang_4(); break;
            case 5: chuc_nang_5(); break;
            case 6: chuc_nang_6(); break;
            case 7: chuc_nang_7(); break;
            case 8: chuc_nang_8(); break;
            case 9: chuc_nang_9(); break;
            case 10: chuc_nang_10(); break;
            case 0: printf("Thoat chuong trinh...\n"); break;
            default: printf("Chon sai, vui long chon lai!\n");
        }
    } while (choice != 0);

    return 0;
}