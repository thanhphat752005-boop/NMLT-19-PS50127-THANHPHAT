#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// ==========================================
// KHOẢNG KHAI BÁO NGUYÊN MẪU HÀM
// ==========================================
void demNguyenAmPhuAm();
void kiemTraDangNhap();
void sapXepChuoi();
void thapPhanSangNhiPhan();
void xoaBoNhoDem(); // Hàm hỗ trợ xóa bộ nhớ đệm tránh trôi lệnh

// ==========================================
// HÀM CHÍNH (MAIN)
// ==========================================
int main() {
    int luaChon;

    do {
        // Giao diện Menu
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
        
        // Xóa ký tự '\n' còn sót lại trong bộ nhớ đệm sau khi dùng scanf
        xoaBoNhoDem(); 

        switch (luaChon) {
            case 1:
                printf("\n--- CHUC NANG 1: Dem Nguyen am va Phu am ---\n");
                demNguyenAmPhuAm();
                break;
            case 2:
                printf("\n--- CHUC NANG 2: Dang nhap he thong ---\n");
                kiemTraDangNhap();
                break;
            case 3:
                printf("\n--- CHUC NANG 3: Sap xep chuoi Alphabet ---\n");
                sapXepChuoi();
                break;
            case 4:
                printf("\n--- CHUC NANG 4: Thap phan sang Nhi phan ---\n");
                thapPhanSangNhiPhan();
                break;
            case 5:
                printf("\nDa thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("\nLua chon khong hop le! Vui long chon tu 1 den 5.\n");
        }
    } while (luaChon != 5);

    return 0;
}

// ==========================================
// CHI TIẾT CÁC HÀM XỬ LÝ
// ==========================================

// Hàm hỗ trợ dọn dẹp bộ nhớ đệm
void xoaBoNhoDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Chức năng 1: Đếm Nguyên âm và Phụ âm trong Chuỗi
void demNguyenAmPhuAm() {
    char s[256];
    int demNA = 0, demPA = 0;

    printf("Nhap vao mot chuoi bat ky: ");
    fgets(s, sizeof(s), stdin);

    for (int i = 0; s[i] != '\0'; i++) {
        char c = tolower(s[i]); // Chuyển về chữ thường để dễ so sánh
        
        if (isalpha(c)) { // Kiểm tra xem có phải là chữ cái không
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                demNA++;
            } else {
                demPA++;
            }
        }
    }

    printf("-> So luong nguyen am: %d\n", demNA);
    printf("-> So luong phu am: %d\n", demPA);
}

// Chức năng 2: Chương trình Đăng nhập bằng User & Password
void kiemTraDangNhap() {
    char userSys[] = "admin";
    char passSys[] = "123456";
    char user[50], pass[50];

    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);

    // So sánh chuỗi nhập vào với tài khoản mặc định
    if (strcmp(user, userSys) == 0 && strcmp(pass, passSys) == 0) {
        printf("-> Dang nhap thanh cong!\n");
    } else {
        printf("-> Username hoac Password khong chinh xac!\n");
    }
}

// Chức năng 3: Sắp xếp Danh sách Chuỗi theo thứ tự Alphabet
void sapXepChuoi() {
    char s[5][50];
    char temp[50];

    printf("Nhap vao 5 chuoi bat ky:\n");
    for (int i = 0; i < 5; i++) {
        printf("Chuoi thu %d: ", i + 1);
        fgets(s[i], sizeof(s[i]), stdin);
        // Loại bỏ ký tự xuống dòng '\n' ở cuối chuỗi do fgets để lại
        s[i][strcspn(s[i], "\n")] = '\0'; 
    }

    // Thuật toán sắp xếp nổi bọt (Bubble Sort) áp dụng cho mảng chuỗi
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (strcmp(s[i], s[j]) > 0) {
                // Hoán vị 2 chuỗi bằng strcpy
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

// Chức năng 4: Chuyển đổi số Thập phân sang Nhị phân bằng Chuỗi
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
    // Chia lấy dư liên tục cho 2 và lưu vào chuỗi
    while (tempN > 0) {
        nhiPhan[i] = (tempN % 2) + '0'; // Cộng thêm '0' để chuyển int sang char
        tempN = tempN / 2;
        i++;
    }
    nhiPhan[i] = '\0'; // Kết thúc chuỗi

    printf("-> Ket qua Nhi phan cua %d la: ", n);
    // In ngược mảng nhiPhan để ra kết quả đúng
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", nhiPhan[j]);
    }
    printf("\n");
}