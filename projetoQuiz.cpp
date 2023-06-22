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
    cout << "-------------------------------------" << endl;
    cout << "--------------BEM VINDO--------------" << endl;
    cout << "-------------------------------------" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Escolha uma opção:" << endl;
    cout << "1 Sign In" << endl;
    cout << "2 Log In" << endl;
    cout << "3 Começar quiz" << endl;
    cout << "4 Apagar conta" << endl;
    cout << "5 Sair" << endl;
    cout << "> ";
}

void signIn() {
    system("cls");
    string username;
    char c;
    char password[20];
    int i = 0;

    cout << "Digite o username: ";
    cin >> username;

    cout << "Digite a password: ";
    while ((c = _getch()) != '\r') {
        if (c == '\b' && i > 0) {
            cout << "\b \b";
            i--;
        } else if (c != '\b') {
            password[i] = c;
            cout << '*';
            i++;
        }
    }

    password[i] = '\0';

    cout << endl;

    ofstream file("login.txt", ios::app);

    if (file.is_open()) {
        file << "Username: " << username << "\n";
        file << "Password: " << password << "\n";

        file.close();

        cout << "Conta guardada com sucesso\n";
    } else {
        cout << "Erro ao abrir ficheiro!\n";
    }
}

void deleteAccount() {
    system("cls");
    ifstream file("login.txt");
    ofstream tempFile("temp.txt");
    string line;
    string username;
    char c;
    char password[20];
    int i = 0;

    cout << "Digite o username para apagar a conta: ";
    cin >> username;

    cout << "Digite a password: ";
    while ((c = _getch()) != '\r') {
        if (c == '\b' && i > 0) {
            cout << "\b \b";
            i--;
        } else if (c != '\b') {
            password[i] = c;
            cout << '*';
            i++;
        }
    }

    password[i] = '\0';

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
            cout << "Conta apagada com sucesso!\n";
        } else {
            remove("temp.txt");
            cout << "Conta não encontrada.\n";
        }
    } else {
        cout << "Erro ao abrir o ficheiro!\n";
    }
}

void logIn() {
    system("cls");
    ifstream file("login.txt");
    string line;
    string username;
    char c;
    char password[20];
    int i = 0;
    

    cout << "Digite o username: ";
    cin >> username;

    cout << "Digite a password: ";
    while ((c = _getch()) != '\r') {
        if (c == '\b' && i > 0) {
            cout << "\b \b";
            i--;
        } else if (c != '\b') {
            password[i] = c;
            cout << '*';
            i++;
        }
    }

    password[i] = '\0';

    bool found = false;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find("Username: " + username) != string::npos) {
                getline(file, line);
                if (line.find("Password: " + string(password)) != string::npos) {
                    found = true;
                    break;
                }
            }
        }

        file.close();

        if (found) {
            cout << "Login bem sucedido!\n";
        } else {
            cout << "Credenciais inválidas.\n";
        }
    } else {
        cout << "Erro ao abrir o ficheiro!\n";
    }
}

void despedida(){
    system("cls");

    cout << "Obrigado por realizar o nosso quiz!";
}

void quiz() {
    system("cls");

}

int lerOpcao(){
    int a;
    cin >> a;
    return a;
}
















int main() {
    setlocale(LC_ALL, "");

    int opcao;

    do{
        bemVindo();

        opcao = lerOpcao();

        switch(opcao){
            case 1: signIn();
            break;
            case 2: logIn();
            break;
            case 3: quiz();
            break;
            case 4: deleteAccount();
            break;
            case 5: despedida();
            break;
            default: cout << "Opção inválida, tente novamente." << endl;
        }
    }while(opcao != 5);


    return 0;
}