#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;

bool hasRepeatedNumbers(const string& inputString) {
    int count[10] = {0}; // Array to count occurrences of digits (0-9)

    for (char ch : inputString) {
        if (isdigit(ch)) {
            int digit = ch - '0'; // Convert character to digit value
            if (count[digit] > 0) {
                return true; // If the digit is already seen, return true indicating repetition
            }
            count[digit]++; // Otherwise, increment count for this digit
        }
    }
    return false; // If no repetitions found, return false
}

bool isNumber(const string& input) {
    int digits = 0;
    for (char c : input) {
        if (isdigit(c) || isspace(c)) {
            // Check if the digit is between 1 and 5
            if (isdigit(c) && (c < '1' || c > '5')) {
                return false;
            }
            // Count digits
            if (isdigit(c)) {
                digits++;
            }
        } else {
            return false; // If any character is not a digit or a space, return false
        }
    }
    // Check if the number of digits is even
    return digits % 2 == 0;
}

bool isString(const string &input) {
    for (char c : input) {
        if (!isalpha(c) && !isspace(c)) {
            return false; // If any character is not alphabetic, return false
        }
    }
    return true; // All characters are alphabetic or spaces, so return true
}

bool isValidSystem(char c) {
    return c >= '1' && c <= '5';
}

int main() {
    cout << "Polybius Square Cipher\n";
    cout << "You should enter five numbers from 1 to 5 without any spaces.\n";
    string input;
    stringstream ss;
    while (true) {
        cout << "Enter the system: ";
        getline(cin, input);

        // Check if the input has exactly 5 characters
        if (input.length() != 5) {
            cout << "The input string is invalid.\n";
            continue;
        }

        // Check each character individually
        bool validInput = true;
        for (char c : input) {
            if (!isdigit(c) || !isValidSystem(c)) {
                validInput = false;
                break;
            }
        }
        if (!validInput) {
            cout << "The input system is invalid.\n";
            continue;
        }

        if (!hasRepeatedNumbers(input)) {
            break;
        } else {
            cout << "The input system is invalid.\n";
            continue;
        }
    }

    string a, b, c, d, e;
    a = input[0];
    b = input[1];
    c = input[2];
    d = input[3];
    e = input[4];
    char alpha[5][5] = {
        {'A', 'B', 'C', 'D', 'E'},
        {'F', 'G', 'H', 'I', 'K'},
        {'L', 'M', 'N', 'O', 'P'},
        {'Q', 'R', 'S', 'T', 'U'},
        {'V', 'W', 'X', 'Y', 'Z'}
    };

    string numbers[5][5] = {
        {(a + a), (a + b), (a + c), (a + d), (a + e)},
        {(b + a), (b + b), (b + c), (b + d), (b + e)},
        {(c + a), (c + b), (c + c), (c + d), (c + e)},
        {(d + a), (d + b), (d + c), (d + d), (d + e)},
        {(e + a), (e + b), (e + c), (e + d), (e + e)}
    };

    int x;
    while (true) {
        cout << "1) Cypher\n";
        cout << "2) Decypher\n";
        cout << "3) Exit\n";
        cout << "Enter the choice: ";
        cin >> x;
        if (x == 1 || x == 2 || x == 3) {
            break;
        } else {
            cout << "Please enter a valid choice.\n";
            continue;
        }
    }

    if (x == 1) {
        string plain_text;
        while (true) {
            cout << "Enter Plain text: ";
            cin.ignore();
            getline(cin, plain_text);
            if (isString(plain_text)) {
                break;
            } else {
                cout << "Please enter a valid string." << endl;
            }
        }
        for (char &c : plain_text) {
            c = toupper(c);
        }
        string result = "";
        for (char c : plain_text) {
            // Adding space between each number
            if (isspace(c)) {
                result += "  ";
            }
            if (c == 'J') {
                c = 'I'; // J and I are  the same in Square Cipher
            }
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (c == alpha[i][j]) {
                        result += (numbers[i][j]);
                    }
                }
            }
        }
        cout << "Cipher text: " << result << endl;
    }

    if (x == 2) {
        string cyphered_message;
        cin.ignore(); // Clear input buffer
        while (true){
        cout << "Enter cyphered message which has just numbers or spaces and number of numbers is even and numbers between 1 and 5: ";
        getline(cin, cyphered_message);

        if (isNumber(cyphered_message)) {
            break;  
        }
        else{cout << "Invalid cyphered message.\n";
        continue;}
        }

        string result_2;
        for (int i = 0; i < cyphered_message.length(); ++i) {
            if (cyphered_message[i] == ' ') {
                result_2 += " ";
            } else {
                string sum = cyphered_message.substr(i, 2); // Extract two characters at a time
                for (int p = 0; p < 5; ++p) {
                    for (int j = 0; j < 5; ++j) {
                        if (sum == numbers[p][j]) {
                            result_2 += alpha[p][j];
                        }
                    }
                }
                // Skip the next character
                ++i;
            }
        }
        cout << "Deciphered message: " << result_2 << endl;
    }

    if (x == 3) {
        cout << "Good day.\n";
        exit(0);
    }

    return 0;
}



