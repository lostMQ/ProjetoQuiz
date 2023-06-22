#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstring>
#include <map>
#include <fstream>

using namespace std;

void bemVindo() {
    cout << "-------------------------------------" << endl;
    cout << "--------------BEM VINDO--------------" << endl;
    cout << "-------------------------------------" << endl;
    cout << "-----Vamos iniciar o seu registo-----" << endl;
    cout << "-------------------------------------" << endl;
}

void logIn() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ofstream file("login.txt");

    if (file.is_open()) {
        file << "Username: " << username << "\n";
        file << "Password: " << password << "\n";

        file.close();

        cout << "Login information saved to login.txt\n";
    } else {
        cout << "Error opening the file!\n";
    }
}

void deleteAccount() {
    ifstream file("login.txt");
    ofstream tempFile("temp.txt");
    string line;
    string username, password;

    cout << "Enter username to delete the account: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    bool found = false;

    if (file.is_open() && tempFile.is_open()) {
        while (getline(file, line)) {
            if (line == "Username: " + username) {
                getline(file, line);
                found = true;
            } else {
                tempFile << line << "\n";
            }
        }

        file.close();
        tempFile.close();

        if (found) {
            remove("login.txt");
            rename("temp.txt", "login.txt");
            cout << "Account deleted successfully!\n";
        } else {
            remove("temp.txt");
            cout << "Account not found.\n";
        }
    } else {
        cout << "Error opening the file!\n";
    }
}

















int main() {
    setlocale(LC_ALL, "");

    bemVindo();
    logIn();

    char choice;
    cout << "Do you want to delete your account? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        deleteAccount();
    }


    return 0;
}