#include<stdio.h>
#include<stdlib.h>

struct Student {
    int rollNo;
    char *name;
};


int length(char str[]){
    
    int length = 0, index=0;
    while(str[index] != '\0'){
        length++;
        index++;
    }
    return length;
}


int strCmp(char str1[], char str2[]){
    int i=0;
    while(str1[i] == str2[i]){
        if(str1[i] == '\0'){
            return 0;
        }
        i++;
    }
    return (str1[i] - str2[i]);
}



int Sort(struct Student *BtechCSE24[], int totalStudents) {
    int i = 0;
    while (i < totalStudents) {
        int j = i + 1;
        int minIndex = i;
        while (j < totalStudents) {
            int res = strCmp(BtechCSE24[minIndex]->name, BtechCSE24[j]->name);
            // printf("comp result--->%s %s %d \t %d %d \n ",BtechCSE24[i]->name, BtechCSE24[j]->name, res, i,j);
            if (res > 0) {
                minIndex = j;
            }
            j++;
        }
        // printf("loop end\n");
        if (minIndex != i) {
            printf("swap\n");
            struct Student *temp = BtechCSE24[i];
            BtechCSE24[i] = BtechCSE24[minIndex];
            BtechCSE24[minIndex] = temp;
        }
        i++;
    }
    return 0;
}



void Insert(struct Student *data, struct Student *BtechCSE24[], int index) {
    int name_length = length(data->name);

    BtechCSE24[index] = (struct Student *)malloc(sizeof(struct Student));
    BtechCSE24[index]->name = (char *)malloc((name_length + 1) * sizeof(char)); 
   
    if (BtechCSE24[index] == NULL || BtechCSE24[index]->name == NULL) {
            printf("Failed to allocate memory");
            return;
    }
    
    for (int j = 0; j < name_length; j++) {
        BtechCSE24[index]->name[j] = data->name[j];
    }
    BtechCSE24[index]->name[name_length] = '\0'; 

    BtechCSE24[index]->rollNo = data->rollNo;

}




int main() {
    int totalStudents;

    printf("Enter total number of Students: ");
    scanf("%d", &totalStudents);
    getchar();

    struct Student *BtechCSE24[totalStudents];
   
    for (int i = 0; i < totalStudents; i++) {
        char buffer[100]; 
        int rollNo;

        printf("Enter Roll no: ");
        scanf("%d", &rollNo);
        getchar(); 

        printf("Enter the name: ");
        fgets(buffer, sizeof(buffer), stdin);

        int name_length = length(buffer);
        if (buffer[name_length - 1] == '\n') {
            buffer[name_length - 1] = '\0';
        }

        struct Student *temp = (struct Student *)malloc(sizeof(struct Student));
        if (temp == NULL) {
            printf("Failed to allocate memory");
            return 0;
        }

        temp->name = (char *)malloc((name_length + 1) * sizeof(char)); 
        for (int j = 0; j < name_length; j++) {
            temp->name[j] = buffer[j];
        }
        temp->name[name_length] = '\0';

        temp->rollNo = rollNo;

        Insert(temp, BtechCSE24, i);

        free(temp->name);
        free(temp);
    }

    Sort(BtechCSE24, totalStudents);

    printf("\nStored Student Data:\n");
    for (int i = 0; i < totalStudents; i++) {
        printf("Roll No: %d, Name: %s\n", BtechCSE24[i]->rollNo, BtechCSE24[i]->name);
        free(BtechCSE24[i]->name); 
        free(BtechCSE24[i]);       
    }
    free(BtechCSE24);

    return 0;
}