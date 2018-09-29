#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char student_id[5];
    char student_name[50];
    char student_phonenumber[15];
} students;

void addNewStudent() {
    students student[10];
    printf("vui lòng nhập mã của sinh viên: \n");
    fgetc(stdin);
    fgets(student->student_id, 5, stdin);

    if (!strchr(student->student_id, '\n')) {
        while (fgetc(stdin) != '\n');
    }
    while (student->student_id != 5) {
        printf("Nhập mã sinh viên: (nhập đủ 5 kí tự)\n");
        getchar();
        fgets(student->student_id, 5, stdin);
        if (!strchr(student->student_id, '\n')) {
            while (fgetc(stdin) != '\n');
        }
    }

    printf("Vui lòng nhập tên sinh viên: \n");
    fgetc(stdin);
    fgets(student->student_name, 50, stdin);
    if (!strchr(student->student_name, '\n')) {
        while (fgetc(stdin) != '\n');
    }

    printf("Vui lòng nhập số điện thoại sinh viên: \n");
    fgetc(stdin);
    fgets(student->student_phonenumber, 15, stdin);
    if (!strchr(student->student_phonenumber, '\n')) {
        while (fgetc(stdin) != '\n');
    }

}

void displayStudent(){
    students student[10];
    printf("%-10s%-20s%-10s%-20s%-10s%-20s", "Số thứ tự", "|" "Mã sinh viên", "|", "Tên sinh viên", "|", "Số điện thoại" "\n");
    for (int i = 0; i < 10; ++i) {
        printf("\n");
        printf("%-10d%-20s%-10s%-20s%-10s%-20s", i + 1, student->student_id, "|", student[i].student_name, "|", student[i].student_phonenumber);
    }
}

void readFile() {
    FILE *fp;
    printf("_______Read file data______\n");
    fp = fopen("danhsachsinhvien.txt", "r");
    int bufferSize = 10;
    char buffer[bufferSize];
    while (fgets(buffer, bufferSize, fp) != NULL) {
        printf("%s", buffer);
    }
}

void saveFile() {
    FILE *fp = fopen("danhsachsinhvien.txt", "w+");
    students sinhVienArray[10];
    fprintf(fp, "-%-20s|%-20s|%s", "Mã sinh viên ", "Tên sinh viên", "Điện thoại");
    while (1 == 1) {
        fgets(sinhVienArray, 10, stdin);
        if (strcmp(sinhVienArray, "exit\n") == 0) {
            break;
        }
        fprintf(fp, sinhVienArray);
    }
    fclose(fp);
}

void exitFile() {
    int choice;
    printf("Bạn muốn nhập tiếp không? (y/n)\n");
    scanf("%d", &choice);
    if (choice == 'n' || choice == 'N') {

    }
}

void menu(){
    int a;
    while (1==1) {
        printf("Vui lòng nhập lựa chọn của bạn:\n");
        printf("1.Thêm mới sinh viên.\n");
        printf("2.Hiển thị dánh sách sinh viên.\n");
        printf("3.Lưu danh sách sinh viên ra file.\n");
        printf("4.Đọc danh sách sinh viên từ file.\n");
        printf("5.Thoát chương trình\n");
        printf("Vui lòng nhập lựa chọn của bạn:\n");
        scanf("%d", &a);
        switch (a){
            case 1:
                addNewStudent();
                break;
            case 2:
                displayStudent();
                break;
            case 3:
                readFile();
                break;
            case 4:
                saveFile();
                break;
            case 5:
                exitFile();
                break;
            default:
                printf("Bạn đã nhập sai vui lòng nhập từ 1-5.\n");
        }
        break;
    }
}

int main(){
    int x;
    printf("Vui lòng nhập số lượng sinh viên: \n");
    scanf("%d", &x);
    if(x < 1 || x > 50){
        printf("vui lòng nhập lại: \n");
    }
    menu();
    return 0;
}


