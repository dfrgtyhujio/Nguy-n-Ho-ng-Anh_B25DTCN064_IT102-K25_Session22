#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phoneNumber[15];
    char email[50];
};

void addContact(struct Contact contacts[], int *n) {
    printf("\nThem lien he moi:\n");
    getchar();

    printf("Nhap ten: ");
    fgets(contacts[*n].name, 50, stdin);
    contacts[*n].name[strcspn(contacts[*n].name, "\n")] = '\0';

    printf("Nhap so dien thoai: ");
    fgets(contacts[*n].phoneNumber, 15, stdin);
    contacts[*n].phoneNumber[strcspn(contacts[*n].phoneNumber, "\n")] = '\0';

    printf("Nhap email: ");
    fgets(contacts[*n].email, 50, stdin);
    contacts[*n].email[strcspn(contacts[*n].email, "\n")] = '\0';

    (*n)++;
    printf("Da them lien he thanh cong\n");
}

void showContacts(struct Contact contacts[], int n) {
    if (n == 0) {
        printf("\nChua co lien he nao\n");
        return;
    }

    printf("\nDANH SACH LIEN HE\n");
    for (int i = 0; i < n; i++) {
        printf("Lien he %d:\n", i + 1);
        printf("Ten: %s", contacts[i].name);
        printf("SDT: %s", contacts[i].phoneNumber);
        printf("Email: %s\n", contacts[i].email);
    }
}

void findContact(struct Contact contacts[], int n) {
    if (n == 0) {
        printf("\nChua co lien he nao\n");
        return;
    }

    char searchName[50];
    getchar();
    printf("\nNhap ten can tim: ");
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strstr(contacts[i].name, searchName) != NULL) { 
            printf("\nTim thay lien he:\n");
            printf("Ten: %s", contacts[i].name);
            printf("SDT: %s", contacts[i].phoneNumber);
            printf("Email: %s\n", contacts[i].email);
            return;
        }
    }

    printf("Khong tim thay lien he\n");
}


void deleteContact(struct Contact contacts[], int *n) {
    if (*n == 0) {
        printf("\nChua co lien he nao\n");
        return;
    }

    char deleteName[50];
    getchar();
    printf("\nNhap ten lien he muon xoa: ");
    fgets(deleteName, 50, stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0';

    for (int i = 0; i < *n; i++) {
        if (strstr(contacts[i].name, deleteName) != NULL) {
            for (int j = i; j < *n - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*n)--;
            printf("Da xoa lien he thanh cong\n");
            return;
        }
    }

    printf("Khong tim thay lien he\n");
}

int main() {
    struct Contact contacts[100];
    int n = 0;
    int choice;

    do {
        printf("\n====== MENU ======\n");
        printf("1. Them lien he moi\n");
        printf("2. Hien thi tat ca lien he\n");
        printf("3. Tim kiem theo ten\n");
        printf("4. Xoa lien he theo ten\n");
        printf("5. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &n);
                break;
            case 2:
                showContacts(contacts, n);
                break;
            case 3:
                findContact(contacts, n);
                break;
                
            case 4:
                deleteContact(contacts, &n);
                break;
                
            case 5:
                printf("Thoat chuong trinh\n");
                break;
                
            default:
                printf("Lua chon khong hop le\n");
        }
    } while(choice != 5);
    
    return 0; 
}

