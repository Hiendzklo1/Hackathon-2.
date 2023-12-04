#include <stdio.h>
#include <string.h>
// Khai báo cau trúc SinhVien
struct SinhVien {
    int id;
    char name[50];
    char birthday[50];
    char address[50];
    int status;
};
// Khai báo mang studentList và so luong sinh viên
struct SinhVien studentList[100];
int soLuongSinhVien = 2; // Gia su có san 2 sinh viên trong mang
// Hàm in toàn bo danh sách sinh viên
void inDanhSachSinhVien() {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < soLuongSinhVien; ++i) {
        printf("%-5d %-20s %-15s %-20s %-5d\n", studentList[i].id, studentList[i].name, studentList[i].birthday, studentList[i].address, studentList[i].status);
    }
}
// Hàm thêm moi sinh viên
void themMoiSinhVien() {
    printf("Nhap thong tin sinh vien moi:\n");
    printf("Nhap ID: ");
    scanf("%d", &studentList[soLuongSinhVien].id);
    fflush(stdin);
    printf("Nhap ten: ");
    fgets(studentList[soLuongSinhVien].name, sizeof(studentList[soLuongSinhVien].name), stdin);
    studentList[soLuongSinhVien].name[strcspn(studentList[soLuongSinhVien].name, "\n")] = '\0';
    printf("Nhap ngay sinh: ");
    fgets(studentList[soLuongSinhVien].birthday, sizeof(studentList[soLuongSinhVien].birthday), stdin);
    studentList[soLuongSinhVien].birthday[strcspn(studentList[soLuongSinhVien].birthday, "\n")] = '\0';
    printf("Nhap dia chi: ");
    fgets(studentList[soLuongSinhVien].address, sizeof(studentList[soLuongSinhVien].address), stdin);
    studentList[soLuongSinhVien].address[strcspn(studentList[soLuongSinhVien].address, "\n")] = '\0';
    printf("Nhap status: ");
    scanf("%d", &studentList[soLuongSinhVien].status);
    soLuongSinhVien++;
}
// Hàm cap nhat thông tin sinh viên
void capNhatThongTinSinhVien() {
    char tenCanCapNhat[50];
    int timThay = 0;
    printf("Nhap ten sinh vien can cap nhat: ");
    fgets(tenCanCapNhat, sizeof(tenCanCapNhat), stdin);
    tenCanCapNhat[strcspn(tenCanCapNhat, "\n")] = '\0'; 
    for (int i = 0; i < soLuongSinhVien; ++i) {
        if (strstr(studentList[i].name, tenCanCapNhat) != NULL) {
            printf("Nhap thong tin moi cho sinh vien:\n");
            printf("Nhap ten: ");
            fgets(studentList[i].name, sizeof(studentList[i].name), stdin);
            studentList[i].name[strcspn(studentList[i].name, "\n")] = '\0';
            printf("Nhap ngay sinh: ");
            fgets(studentList[i].birthday, sizeof(studentList[i].birthday), stdin);
            studentList[i].birthday[strcspn(studentList[i].birthday, "\n")] = '\0';
            printf("Nhap dia chi: ");
            fgets(studentList[i].address, sizeof(studentList[i].address), stdin);
            studentList[i].address[strcspn(studentList[i].address, "\n")] = '\0';
            printf("Nhap status: ");
            scanf("%d", &studentList[i].status);
            timThay = 1;
            break;
        }
    }
    if (!timThay) {
        printf("Khong tim thay sinh vien co ten %s!\n", tenCanCapNhat);
    }
}
// Hàm xóa sinh viên
void xoaSinhVien() {
    char tenCanXoa[50];
    int timThay = 0;
    printf("Nhap ten sinh vien can xoa: ");
    fgets(tenCanXoa, sizeof(tenCanXoa), stdin);
    tenCanXoa[strcspn(tenCanXoa, "\n")] = '\0';
    for (int i = 0; i < soLuongSinhVien; ++i) {
        if (strstr(studentList[i].name, tenCanXoa) != NULL) {
            for (int j = i; j < soLuongSinhVien - 1; ++j) {
                studentList[j] = studentList[j + 1];
            }
            soLuongSinhVien--;
            timThay = 1;
            break;
        }
    }
    if (!timThay) {
        printf("Khong tim thay sinh vien co ten %s!\n", tenCanXoa);
    }
}
// Hàm sap xep danh sách sinh viên (sap xep noi bot)
void sapXepSinhVien() {
    for (int i = 0; i < soLuongSinhVien - 1; ++i) {
        for (int j = 0; j < soLuongSinhVien - i - 1; ++j) {
            if (strcmp(studentList[j].name, studentList[j + 1].name) > 0) {
                // Hoán doi vi trí
                struct SinhVien temp = studentList[j];
                studentList[j] = studentList[j + 1];
                studentList[j + 1] = temp;
            }
        }
    }
}
// Hàm tim kiem sinh viên theo tên (Tim kiem nhi phân)
void timKiemSinhVien() {
    char tenCanTim[50];
    int timThay = 0;
    printf("Nhap ten sinh vien can tim kiem: ");
    fgets(tenCanTim, sizeof(tenCanTim), stdin);
    // Loai bo ki tu '\n' thua tu fgets
    tenCanTim[strcspn(tenCanTim, "\n")] = '\0';
    for (int i = 0; i < soLuongSinhVien; ++i) {
        if (strstr(studentList[i].name, tenCanTim) != NULL) {
            printf("%-5d %-20s %-15s %-20s %-5d\n", studentList[i].id, studentList[i].name, studentList[i].birthday, studentList[i].address, studentList[i].status);
            timThay = 1;
            break;
        }
    }
    if (!timThay) {
        printf("Khong tim thay sinh vien co ten %s!\n", tenCanTim);
    }
}
// Hàm tim kiem sinh viên theo status
void timKiemTheoStatus() {
    int statusCanTim;
    printf("Nhap status can tim kiem: ");
    scanf("%d", &statusCanTim);
    printf("\nDanh sach sinh vien co status %d:\n", statusCanTim);
    for (int i = 0; i < soLuongSinhVien; ++i) {
        if (studentList[i].status == statusCanTim) {
            printf("%-5d %-20s %-15s %-20s %-5d\n", studentList[i].id, studentList[i].name, studentList[i].birthday, studentList[i].address, studentList[i].status);
        }
    }
}
int main() {
    // Khoi tao san 2 sinh viên trong mang
    studentList[0] = (struct SinhVien){1, "Nguyen Van Doan", "01/01/2005", "Hanoi", 1};
    studentList[1] = (struct SinhVien){2, "Tran Thi Huong", "02/08/2005", "HaiPhong", 0};
    int luaChon;
    do {
        printf("\n************************MENU**************************\n");
        printf("1. In toan bo danh sach sinh vien\n");
        printf("2. Them moi sinh vien\n");
        printf("3. Cap nhat thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Sap xep va in danh sach sinh vien\n");
        printf("6. Tim kiem sinh vien\n");
        printf("7. Tim kiem va in sinh vien theo status\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);
        fflush(stdin);
        switch (luaChon) {
            case 1:
                inDanhSachSinhVien();
                break;
            case 2:
                themMoiSinhVien();
                break;
            case 3:
                capNhatThongTinSinhVien();
                break;
            case 4:
                xoaSinhVien();
                break;
            case 5:
                sapXepSinhVien();
                inDanhSachSinhVien();
                break;
            case 6:
                timKiemSinhVien();
                break;
            case 7:
                timKiemTheoStatus();
                break;
            case 0:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (luaChon != 0);
    return 0;
}

