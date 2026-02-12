#include <iostream>
#include <string>
using namespace std;

// Function to check Luhn Algorithm
bool luhnCheck(string cardNumber) {
    int sum = 0;
    bool doubleDigit = false;

    // Traverse from right to left
    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        int digit = cardNumber[i] - '0';

        if (doubleDigit) {
            digit = digit * 2;
            if (digit > 9)
                digit -= 9;
        }

        sum += digit;
        doubleDigit = !doubleDigit;
    }

    return (sum % 10 == 0);
}

int main() {
    string cardNumber;
    cin >> cardNumber;

    bool isValid = true;

    // Check length
    int len = cardNumber.length();
    if (len < 13 || len > 16)
        isValid = false;

    // Check prefix
    if (!(cardNumber[0] == '4' || 
          cardNumber[0] == '5' || 
          cardNumber[0] == '6' || 
          (cardNumber[0] == '3' && cardNumber[1] == '7')))
        isValid = false;

    // Check Luhn algorithm
    if (!luhnCheck(cardNumber))
        isValid = false;

    if (isValid)
        cout << cardNumber << " is valid ";
    else
        cout << cardNumber << " is invalid";

    return 0;
}
