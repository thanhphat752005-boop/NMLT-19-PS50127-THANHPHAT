#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Nguyen mau ham
void demNguyenAmPhuAm();
void kiemTraDangNhap();
void sapXepChuoi();
void thapPhanSangNhiPhan();
void xoaBoNhoDem();

int main() {
    int luaChon;
    do {
        printf("\n+---------------------------------------------------+\n");
        printf("|             MENU CHUONG TRINH LAB 7               |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Dem Nguyen am va Phu am trong chuoi            |\n");
        printf("| 2. Dang nhap he thong (User & Password)           |\n");
        printf("| 3. Sap xep danh sach Chuoi theo thu tu Alphabet   |\n");
        printf("| 4. Chuyen doi so Thap phan sang Nhi phan (Chuoi)  |\n");
        printf("| 5. Thoat chuong trinh                             |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &luaChon);
        xoaBoNhoDem();

        switch (luaChon) {
            case 1: demNguyenAmPhuAm(); break;
            case 2: kiemTraDangNhap(); break;
            case 3: sapXepChuoi(); break;
            case 4: thapPhanSangNhiPhan(); break;
            case 5: printf("\nDa thoat chuong trinh.\n"); break;
            default: printf("\nLua chon khong hop le!\n");
        }
    } while (luaChon != 5);
    return 0;
}

void xoaBoNhoDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void demNguyenAmPhuAm() { printf("\n[Chuc nang 1 dang phat trien]\n"); }
void kiemTraDangNhap() { printf("\n[Chuc nang 2 dang phat trien]\n"); }
void sapXepChuoi() { printf("\n[Chuc nang 3 dang phat trien]\n"); }
void thapPhanSangNhiPhan() { printf("\n[Chuc nang 4 dang phat trien]\n"); }