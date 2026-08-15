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
void sapXepChuoi() {
    char s[5][50];
    char temp[50];

    printf("Nhap vao 5 chuoi bat ky:\n");
    for (int i = 0; i < 5; i++) {
        printf("Chuoi thu %d: ", i + 1);
        fgets(s[i], sizeof(s[i]), stdin);
        s[i][strcspn(s[i], "\n")] = '\0';
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (strcmp(s[i], s[j]) > 0) {
                strcpy(temp, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], temp);
            }
        }
    }

    printf("\n-> Danh sach chuoi sau khi sap xep Alphabet:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, s[i]);
    }
}
void thapPhanSangNhiPhan() {
    int n, tempN;
    char nhiPhan[50];
    int i = 0;

    printf("Nhap mot so nguyen duong thap phan: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("-> Ket qua Nhi phan: 0\n");
        return;
    }
    if (n < 0) {
        printf("-> Vui long nhap so nguyen DUONG!\n");
        return;
    }

    tempN = n;
    while (tempN > 0) {
        nhiPhan[i] = (tempN % 2) + '0';
        tempN /= 2;
        i++;
    }
    nhiPhan[i] = '\0';

    printf("-> Ket qua Nhi phan cua %d la: ", n);
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", nhiPhan[j]);
    }
    printf("\n");
}
void demNguyenAmPhuAm() {
    char s[256];
    int demNA = 0, demPA = 0;

    printf("Nhap vao mot chuoi bat ky: ");
    fgets(s, sizeof(s), stdin);

    for (int i = 0; s[i] != '\0'; i++) {
        char c = tolower(s[i]);
        if (isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                demNA++;
            } else {
                demPA++;
            }
        }
    }

    printf("-> So luong nguyen am: %d\n", demNA);
    printf("-> So luong phu am: %d\n", demPA);
}void kiemTraDangNhap() {
    char userSys[] = "admin";
    char passSys[] = "123456";
    char user[50], pass[50];

    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);

    if (strcmp(user, userSys) == 0 && strcmp(pass, passSys) == 0) {
        printf("-> Dang nhap thanh cong!\n");
    } else {
        printf("-> Username hoac Password khong chinh xac!\n");
    }
}