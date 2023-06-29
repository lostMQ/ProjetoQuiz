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
#include <algorithm>
#include <random>
#include <chrono>
#include "perguntas.cpp"

using namespace std;

struct User {
    string username;
    string password;
    int score;

    User(const string& u, const string& p) : username(u), password(p), score(0) {}
};

struct Perguntas {
    string questao;
    string respostaCerta;
    string respostaErrada1;
    string respostaErrada2;
    string respostaErrada3;
    int indiceRespostaCorreta;
    int pontuacao = 0;

    void mostrarPergunta(int& opcao){
        string respostasAleatorias[4] = {respostaCerta, respostaErrada1, respostaErrada2, respostaErrada3};

        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(begin(respostasAleatorias), end(respostasAleatorias), default_random_engine(seed));

        cout << questao << endl;
        for(int i = 0; i < 4; i++) {
            cout << i+1 << ". " << respostasAleatorias[i] << endl;
            if (respostasAleatorias[i] == respostaCerta){
                    indiceRespostaCorreta = i + 1;
            }
        }
        cout << "Tem 10s para escolher uma opcao (1-4): " << endl;

        int endTime = 10;
        int i = 0;
            while (i < endTime) {
                cin >> opcao;
                i+=1;
                endTime-=1;
                if (endTime == 0){
                break;
            }
            }
        if (endTime == 0)
            cout << "Tempo expirado!" << endl;

                if (opcao == indiceRespostaCorreta){
                    cout << "Resposta correta!"<< endl;
                    pontuacao += 5;
                    cout << endl;
                    cout << "Digite qualquer tecla para continuar"<<endl;
                    getch();
                    system ("cls");
                }else{
                    cout << "Resposta errada!"<< endl;
                    cout << endl;
                    cout << "Resposta certa: "<< respostaCerta << endl;
                    cout << endl;
                    cout << "Digite qualquer tecla para continuar" << endl;
                    getch();
                    system ("cls");}
    }
};

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

int quiz() {
    system("cls");

    int opcao;

    Perguntas questao1;
    questao1.questao = "Quem foi o primeiro presidente dos Estados Unidos?";
    questao1.respostaCerta = "George Washington";
    questao1.respostaErrada1 = "Thomas Jefferson";
    questao1.respostaErrada2 = "John Adams";
    questao1.respostaErrada3 = "Abraham Lincoln";


    Perguntas questao2;
    questao2.questao = "Qual é a capital do Canadá?";
    questao2.respostaCerta = "Toronto";
    questao2.respostaErrada1 = "Ottawa";
    questao2.respostaErrada2 = "Vancouver";
    questao2.respostaErrada3 = "Montreal";

    questao1.mostrarPergunta(opcao);
    questao2.mostrarPergunta(opcao);
    /*
    int tema;
    int dificuldade;
    int pontuacao = 0;

    cout << "Escolha o tema que pretende jogar!" << endl;
    cout << "[1] -> Cultura Geral" << endl;
    cout << "[2] -> C++" << endl;

    cin >> tema;
    system("cls");

    cout << "Escolha a difilculdade!" << endl;
    cout << "[1] -> Nivel Facil" << endl;
    cout << "[2] -> Nivel Medio" << endl;
    cout << "[3] -> Nivel Dificil" << endl;

    cin >> dificuldade;

    if(tema == 1 && dificuldade == 1){
        perguntasFaceis(mostrarPergunta);}
        else if(tema == 1 && dificuldade == 2){
            perguntasMedias(pontuacao);}
            else if(tema == 1 && dificuldade == 3){
                perguntasDificeis(pontuacao);}

     if(tema == 2 && dificuldade == 1){
        perguntasFaceis(pontuacao);}
        else if(tema == 2 && dificuldade == 2){
            perguntasMedias(pontuacao);}
            else if(tema == 2 && dificuldade == 3){
                perguntasDificeis(pontuacao);}


    return pontuacao;*/
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

void pontuacao() {
}

void quizMenu() {
    system("cls");
    cout << "Quiz" << endl;
    cout << "1 Começar quiz" << endl;
    cout << "2 Pontuação" << endl;
    cout << "3 Voltar Atrás" << endl;
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
            bemVindo();
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