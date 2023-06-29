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
#include <vector>
#include <limits>

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

struct User {
    string username;
    string password;
    int points;

    User(const string& u, const string& p) : username(u), password(p), points(0) {}
};

bool logIn() {
    system("cls");
    ifstream file("login.txt");
    string line;
    string username;
    string password;
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

    do {
        cout << "Digite a password: ";
        password = "";
        char c;

        while ((c = _getch()) != '\r') {
            if (c == '\b') {
                if (!password.empty()) {
                    password.pop_back();
                    cout << "\b \b";
                }
            } else {
                password.push_back(c);
                cout << '*';
            }
        }

        cout << endl;

        if (password.empty()) {
            cout << "Senha vazia. Tente novamente.\n";
            continue;
        }

        file.clear();
        file.seekg(0, ios::beg);

        bool found = false;
        bool passwordMatched = false;

        while (getline(file, line)) {
            if (line.find("Username: " + username) != string::npos) {
                found = true;
                getline(file, line);

                if (line.find("Password: " + password) != string::npos) {
                    cout << "Log In bem sucedido!\n";
                    sleep(2);
                    loggedIn = true;
                    passwordMatched = true;
                    break;
                }
            }
        }

        if (loggedIn) {
            break;
        }

        if (found) {
            if (passwordMatched) {
                cout << "Credenciais inválidas.\n";
            } else {
                cout << "Senha incorreta.\n";
            }
        } else {
            cout << "Usuário não encontrado.\n";
        }

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

    file.close();
    return loggedIn;
}

void despedida() {
    system("cls");
    cout << "Obrigado por realizar o nosso quiz!";
}

void quiz() {
    system("cls");
    // Implement your quiz logic here
}

void pontuacao() {

}

void scoreboard() {

}

int lerOpcao() {
    int a;
    while (!(cin >> a)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Opção inválida, tente novamente: ";
    }
    return a;
}

void quizMenu() {
    system("cls");
    cout << "Quiz" << endl;
    cout << "1 Começar quiz" << endl;
    cout << "2 A sua pontuação" << endl;
    cout << "3 Scoreboard" << endl;
    cout << "4 Sair" << endl;
    cout << "> ";

    int option;
    cin >> option;

    switch (option) {
        case 1:
            quiz();
            break;
        case 2:
            pontuacao();
            break;
        case 3:
            scoreboard();
            break;
        case 4:
            despedida();
            break;
        default:
            cout << "Opção inválida, tente novamente." << endl;
            sleep(2);
    }
}

int main() {
    setlocale(LC_ALL, "");

    int opcao;

    do {
        bemVindo();
        opcao = lerOpcao();

        switch (opcao) {
            case 1:
                signIn();
                break;
            case 2:
                if (logIn()) {
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
                sleep(2);
        }
    } while (opcao != 4);

    return 0;
}