#include <stdio.h>

int atoi(char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}



void reverse(char str[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void itoa(int num, char* str) {
    int base = 10;
    int i = 0;
    int isNegative = 0;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    if (num < 0 && base == 10) {
        isNegative = 1;
        num = -num;
    }

    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    reverse(str, i);


}


double atof( char *str) {
    double result = 0.0;
    double sign = 1.0;
    double decimalPlace = 1.0;
    int i = 0;

    if (str[i] == '-') {
        sign = -1.0;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10.0 + (str[i] - '0');
        i++;
    }

    if (str[i] == '.') {
        i++;
        while (str[i] >= '0' && str[i] <= '9') {
            decimalPlace /= 10.0;
            result += (str[i] - '0') * decimalPlace;
            i++;
        }
    }

    return result * sign;
}


// void ftoa(float num, char* str, int decimalPlaces) {
//     int intPart = (int)num;
//     float fracPart = num - intPart;

//     int i = 0;
//     int isNegative = 0;

//     if (num < 0) {
//         isNegative = 1;
//         num = -num;
//         intPart = -intPart;
//     }

//     if (isNegative) {
//         str[i++] = '-';
//     }

//     // Convert integer part to string
//     int intPartCopy = intPart;
//     char intBuffer[20];
//     int intLength = 0;

//     if (intPart == 0) {
//         intBuffer[intLength++] = '0';
//     } else {
//         while (intPartCopy > 0) {
//             intBuffer[intLength++] = (intPartCopy % 10) + '0';
//             intPartCopy /= 10;
//         }
//     }

//     reverse(intBuffer, intLength);
//     for (int j = 0; j < intLength; j++) {
//         str[i++] = intBuffer[j];
//     }

//     // Process fractional part
//     if (decimalPlaces > 0) {
//         str[i++] = '.';
//         while (decimalPlaces-- > 0) {
//             fracPart *= 10;
//             int digit = (int)fracPart;
//             printf("%d",(int)digit + '0');
//             str[i++] = digit + '0';
//             fracPart -= digit;
//         }
//     } else if (decimalPlaces == 0 && fracPart > 0) {
//         str[i++] = '.';
//     }


//     str[i] = '\0'; // Null-terminate the string
// }



int main() {
    char *numStr = "1";
    int num = atoi(numStr);
    printf("char to int: %d\n", num);
    
    
 
    // char str[20];
    // itoa(num, str);
    // printf("int to char: %s\n", str);


    //  char *strfloatNum = "-123.456";
    // double flaotNum = atof(strfloatNum);
    // printf("The converted number is: %f\n", flaotNum);

    // char floatStr[50];
    // float ftoinum = -123.456789;
    // ftoa(ftoinum, floatStr, 2);
    // printf("The converted string is: %s\n", floatStr);


    return 0;
}
