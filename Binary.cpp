#include <iostream>
#include <string>
using namespace std;

string decimalToBinary(int decimal) {
    if (decimal == 0) return "0";
    string binary = "";
    while (decimal > 0) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}

string decimalToOctal(int decimal) {
    if (decimal == 0) return "0";
    string octal = "";
    while (decimal > 0) {
        octal = to_string(decimal % 8) + octal;
        decimal /= 8;
    }
    return octal;
}

string decimalToHexadecimal(int decimal) {
    if (decimal == 0) return "0";
    string hex = "";
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex = to_string(remainder) + hex;
        } else {
            hex = char(remainder - 10 + 'A') + hex;
        }
        decimal /= 16;
    }
    return hex;
}

int main() {
    int n;
    string num;

    cout << "\033[1;34;32mWhat is your Binary base? \033[0m";
    cin >> n;

    if (n == 2 || n == 8 || n == 10 || n == 16) {
        cout << "\033[1;34mEnter Your Numbers\033[0m \033[1;3;4;5;31m(press Ctrl+C and Enter to finish)\033[0m\033[1;34m: \033[0m";
        while (cin >> num) {
            bool valid = true;
            int decimal = 0;

            if (n == 2) {
                for (char c : num) {
                    if (c != '0' && c != '1') {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    for (char c : num) {
                        decimal = decimal * 2 + (c - '0');
                    }
                }
            } else if (n == 8) {
                for (char c : num) {
                    if (c < '0' || c > '7') {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    for (char c : num) {
                        decimal = decimal * 8 + (c - '0');
                    }
                }
            } else if (n == 10) {
                for (char c : num) {
                    if (c < '0' || c > '9') {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    decimal = stoi(num);
                }
            } else if (n == 16) {
                for (char c : num) {
                    if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    for (char c : num) {
                        if (c >= '0' && c <= '9') {
                            decimal = decimal * 16 + (c - '0');
                        } else if (c >= 'A' && c <= 'F') {
                            decimal = decimal * 16 + (c - 'A' + 10);
                        } else {
                            decimal = decimal * 16 + (c - 'a' + 10);
                        }
                    }
                }
            }

            if (!valid) {
                cout << "\033[1;31mInvalid number for base " << n << "\033[0m" << endl;
                cout << "\033[1;34mEnter Your Number: \033[0m";
            } else {
                cout << "\n\033[1;36mResult: \033[0m\n" << endl;
                cout << "\033[1;32m○ Decimal: \033[0m" << decimal << endl;
                cout << "\033[1;32m○ Binary: \033[0m" << decimalToBinary(decimal) << endl;
                cout << "\033[1;32m○ Octal: \033[0m" << decimalToOctal(decimal) << endl;
                cout << "\033[1;32m○ Hexadecimal: \033[0m" << decimalToHexadecimal(decimal) << endl;
                cout << "\n\033[1;36mTry Another Number: \033[0m";
            }
        }
    } else {
        cout << "\033[1;91mInvalid base. Please enter a valid base \033[1;3;4;5;31m(2, 8, 10, 16)\033[0m\033[1;91m.\033[0m" << endl;
    }

    return 0;
}