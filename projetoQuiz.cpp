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
#include <unistd.h>

using namespace std;

void bemVindo() {
    system("CLS");
    cout << "-------------------------------------" << endl;
    cout << "-------------------------------------" << endl;
    cout << "--------------BEM VINDO--------------" << endl;
    cout << "-------------------------------------" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Escolha uma opção:" << endl;
    cout << "1 Sign In" << endl;
    cout << "2 Log In" << endl;
    cout << "3 Apagar conta" << endl;
    cout << "4 Sair" << endl;
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
        sleep(2);
    } else {
        cout << "Erro ao abrir ficheiro!\n";
        sleep (2);
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

        system("cls");

        if (found) {
            remove("login.txt");
            rename("temp.txt", "login.txt");
            cout << "Conta apagada com sucesso!\n";
            sleep(2);
        } else {
            remove("temp.txt");
            cout << "Conta não encontrada.\n";
            sleep(2);
        }
    } else {
        cout << "Erro ao abrir o ficheiro!\n";
        sleep (2);
    }
}

bool logIn() {
    system("cls");
    ifstream file("login.txt");
    string line;
    string username;
    char c;
    char password[20];
    int i = 0;
    int failedAttempts = 0;
    bool loggedIn = false;

    cout << "Digite o username: ";
    cin >> username;

    ifstream blockedFile("blocked.txt");
    if (blockedFile.is_open()) {
        while (getline(blockedFile, line)) {
            if (line == username) {
                cout << "A conta está bloqueada. Entre em contato com o suporte.\n";
                blockedFile.close();
                sleep(2);
                return false;
            }
        }
        blockedFile.close();
    }

    map<string, string> credentials;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find("Username: ") != string::npos) {
                username = line.substr(10);
            } else if (line.find("Password: ") != string::npos) {
                string pass = line.substr(10);
                credentials[username] = pass;
            }
        }
        file.close();
    } else {
        cout << "Erro ao abrir o ficheiro!\n";
        sleep(2);
        return false;
    }

    do {
        cout << "Digite a password: ";
        i = 0;
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

        if (credentials.find(username) != credentials.end()) {
            if (credentials[username] == password) {
                cout << "Login bem sucedido!\n";
                sleep(2);
                loggedIn = true;
                break;
            }
        }

        cout << "Credenciais inválidas.\n";
        failedAttempts++;
        sleep(2);

        if (failedAttempts == 3) {
            cout << "Número máximo de tentativas excedido. A conta foi bloqueada.\n";
            sleep(2);

            ofstream blockedFile("blocked.txt", ios::app);
            if (blockedFile.is_open()) {
                blockedFile << username << "\n";
                blockedFile.close();
            } else {
                cout << "Erro ao bloquear a conta. Tente novamente.\n";
                sleep(2);
            }
        }
    } while (failedAttempts < 3);

    return loggedIn;
}

void despedida(){
    system("cls");

    cout << "Obrigado por realizar o nosso quiz!";
}

void quiz() {
    system("cls");

}

void quizMenu() {
    system("cls");
    cout << "Quiz" << endl;
    cout << "1 Começar quiz" << endl;
    cout << "2 Sair" << endl;
    cout << "> ";

    int option;
    cin >> option;

    switch (option) {
        case 1:
            // quiz();
            break;
        case 2:
            despedida();
            break;
        default:
            cout << "Opção inválida, tente novamente." << endl;
            sleep(2);
    }
}

int lerOpcao(){
    int a;
    cin >> a;
    return a;
}
















int main() {
    setlocale(LC_ALL, "");

    int opcao;
    bool loggedIn = false;

    do {
        bemVindo();

        opcao = lerOpcao();

        switch(opcao) {
            case 1:
                signIn();
                break;
            case 2:
                loggedIn = logIn();
                if (loggedIn) {
                    quizMenu();
                }
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                despedida();
                break;
            default:
                cout << "Opção inválida, tente novamente." << endl;
        }
    } while(opcao != 4);

    return 0;
}
