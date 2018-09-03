#include <iostream>
#include <string>

using namespace std;

string encrypt(string input, char key) {
    for(int i = 0; i < input.length(); i++) {
        input[i] ^= key;
    }
    return(input);
}

int main() {
    char key = 'k';
    string encrypt_this = "this string is legable and should not be used to store any secret information! But I can XOR encrypt it relatively easily...";

    // output the raw string
    cout << encrypt_this << endl;

    // call encryption function
    string encrypted = encrypt(encrypt_this, key);
    cout << encrypted << endl;

    // decrypt the string from above
    string decrypted = encrypt(encrypted, key);
    cout << decrypted << endl;

    // return 0
    return 0;
}
