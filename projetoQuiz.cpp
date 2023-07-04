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

using namespace std;

struct User {
    string username;
    string password;
    int score;

    User(const string& u, const string& p) : username(u), password(p), score(0) {}};

struct Perguntas {
    string questao;
    string respostaCerta;
    string respostaErrada1;
    string respostaErrada2;
    string respostaErrada3;
    int indiceRespostaCorreta;
    int pontuacao = 0;

    void mostrarPergunta(User& user, int& opcao) {
        string respostasAleatorias[4] = {respostaCerta, respostaErrada1, respostaErrada2, respostaErrada3};

        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(begin(respostasAleatorias), end(respostasAleatorias), default_random_engine(seed));

        cout << questao << endl;
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << respostasAleatorias[i] << endl;
            if (respostasAleatorias[i] == respostaCerta) {
                indiceRespostaCorreta = i + 1;}
        }
        cout << "Voc� tem 15 segundos para escolher uma op��o (1-4): " << endl;

        int endTime = 15;
        int i = 0;
        while (i < endTime) {
            if (kbhit()) {
                cin >> opcao;
                break;}
            cout <<'\r'<< endTime - i << "s...   " << flush;
            usleep(1000000);
            i++;}

        cout << "Score: " << user.score << endl;

        if (i == endTime) {
            cout << "Tempo esgotado!" << endl;
            opcao = 0;
        } else {
            if (opcao == indiceRespostaCorreta) {
                cout << "Resposta correta!" << endl;
                pontuacao += 5;
                user.score += pontuacao;
            } else {
                cout << "Resposta errada!" << endl;
                cout << "Resposta certa: " << respostaCerta << endl;}
        }
        cout << endl;
        cout << "Digite qualquer tecla para continuar" << endl;
        getch();
        system("cls");
    }
    };
    void bemVindo() {
        system("CLS");
        cout << "-------------------------------------" << endl;
        cout << "-------------------------------------" << endl;
        cout << "--------------BEM VINDO--------------" << endl;
        cout << "-------------------------------------" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Escolha uma op��o:" << endl;
        cout << "1 Sign In" << endl;
        cout << "2 Log In" << endl;
        cout << "3 Apagar conta" << endl;
        cout << "4 Sair" << endl;
        cout << "> ";}

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
                i++;}
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
            sleep (2);}
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
                i++;}
        }
        password[i] = '\0';

        bool found = false;

        if (file.is_open() && tempFile.is_open()) {
            while (getline(file, line)) {
                if (line == "Username: " + username) {
                    getline(file, line);
                    found = true;
                } else {
                    tempFile << line << "\n";}
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
                cout << "Conta n�o encontrada.\n";
                sleep(2);
            }
        } else {
            cout << "Erro ao abrir o ficheiro!\n";
            sleep (2);}
    }

bool logIn() {
    system("cls");
    ifstream file("login.txt");
    string line;
    string username;
    string password;
    int failedAttempts = 0;
    bool loggedIn = false;
    User user("", ""); // Declara��o do objeto User

    cout << "Digite o username: ";
    cin >> username;

    ifstream blockedFile("blocked.txt");
    if (blockedFile.is_open()) {
        while (getline(blockedFile, line)) {
            if (line == username) {
                cout << "A conta est� bloqueada. Entre em contato com o suporte.\n";
                blockedFile.close();
                sleep(2);
                return false;}
        }
        blockedFile.close();}

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
                cout << '*';}
        }
        cout << endl;

        if (password.empty()) {
            cout << "Senha vazia. Tente novamente.\n";
            continue;}

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
                    break;}}}

        if (loggedIn) {
            ifstream scoreFile("score.txt");
            string line;
            while (getline(scoreFile, line)) {
                if (line.find("Username: " + username) != string::npos) {
                    getline(scoreFile, line);
                    user.score = stoi(line.substr(7));
                    break;}}
            scoreFile.close();
            break;}
        if (found) {
            if (passwordMatched) {
                cout << "Credenciais inv�lidas.\n";
            } else {
                cout << "Senha incorreta.\n";}
        } else {
            cout << "Usu�rio n�o encontrado.\n";}

        failedAttempts++;
        sleep(2);

        if (failedAttempts == 3) {
            cout << "N�mero m�ximo de tentativas excedido. A conta foi bloqueada.\n";
            sleep(2);

            ofstream blockedFile("blocked.txt", ios::app);
            if (blockedFile.is_open()) {
                blockedFile << username << "\n";
                blockedFile.close();
            } else {
                cout << "Erro ao bloquear a conta. Tente novamente.\n";
                sleep(2);}
        }
    }while (failedAttempts < 3);

    file.close();
    return loggedIn;
}

    void despedida(const User& user) {
    system("cls");

    ofstream scoreFile("score.txt", ios::app);

    if (scoreFile.is_open()) {
        scoreFile << "Username: " << user.username << "\n";
        scoreFile << "Score: " << user.score << "\n";

        scoreFile.close();

        cout << "Obrigado por realizar o nosso quiz! Sua pontua��o foi salva.\n";
        cout << "Pontua��o final: " << user.score << "\n";
    } else {
        cout << "Erro ao abrir o arquivo de pontua��o.";}
}
    int quizcg(User& user) {
        system("cls");

        int opcao;

        Perguntas questao1;
        questao1.questao = "Quem foi o primeiro presidente dos Estados Unidos?";
        questao1.respostaCerta = "Abraham Lincoln";
        questao1.respostaErrada1 = "Thomas Jefferson";
        questao1.respostaErrada2 = "John Adams";
        questao1.respostaErrada3 = "George Washington";

        Perguntas questao2;
        questao2.questao = "Qual � a capital do Canad�?";
        questao2.respostaCerta = "Toronto";
        questao2.respostaErrada1 = "Ottawa";
        questao2.respostaErrada2 = "Vancouver";
        questao2.respostaErrada3 = "Montreal";

        Perguntas questao3;
        questao3.questao = "Em qual cidade est� localizada a sede da Organiza��o das Na��es Unidas (ONU)?";
        questao3.respostaCerta = "Nova York";
        questao3.respostaErrada1 = "Paris";
        questao3.respostaErrada2 = "Genebra";
        questao3.respostaErrada3 = "Londres";

        Perguntas questao4;
        questao4.questao = "Quem escreveu 'Orgulho e Preconceito'?";
        questao4.respostaCerta = "Jane Austen";
        questao4.respostaErrada1 = "Charlotte Bront�";
        questao4.respostaErrada2 = "Emily Bront�";
        questao4.respostaErrada3 = "Virginia Woolf";

        Perguntas questao5;
        questao5.questao = "Qual � o maior deserto do mundo?";
        questao5.respostaCerta = "Deserto do Saara";
        questao5.respostaErrada1 = "Deserto do Gobi";
        questao5.respostaErrada2 = "Deserto da Ar�bia";
        questao5.respostaErrada3 = "Deserto do Atacama";

        Perguntas questao6;
        questao6.questao = "Quem foi o criador da teoria da relatividade restrita?";
        questao6.respostaCerta = "Albert Einstein";
        questao6.respostaErrada1 = "Isaac Newton";
        questao6.respostaErrada2 = "Galileu Galilei";
        questao6.respostaErrada3 = "Max Planck";

        Perguntas questao7;
        questao7.questao = "Quem foi o l�der pol�tico sul-africano que lutou contra o apartheid?";
        questao7.respostaCerta = "Nelson Mandela";
        questao7.respostaErrada1 = "Desmond Tutu";
        questao7.respostaErrada2 = "Jacob Zuma";
        questao7.respostaErrada3 = "Thabo Mbeki";

        Perguntas questao8;
        questao8.questao = "Em que ano acabou a segunda guerra mundial?";
        questao8.respostaCerta = "1945";
        questao8.respostaErrada1 = "1941";
        questao8.respostaErrada2 = "1918";
        questao8.respostaErrada3 = "1928";

        Perguntas questao9;
        questao9.questao = "Qual � o maior arquip�lago do mundo?";
        questao9.respostaCerta = "Ilhas Maldivas";
        questao9.respostaErrada1 = "Hava�";
        questao9.respostaErrada2 = "Indon�sia";
        questao9.respostaErrada3 = "Filipinas";

        Perguntas questao10;
        questao10.questao = "Quem escreveu a obra �A Divina Com�dia�?";
        questao10.respostaCerta = "Dante Alighieri";
        questao10.respostaErrada1 = "Giovanni Boccaccio";
        questao10.respostaErrada2 = "Niccol� Machiavelli";
        questao10.respostaErrada3 = "Petrarch";

        questao1.mostrarPergunta(user, opcao);
        questao2.mostrarPergunta(user, opcao);
        questao3.mostrarPergunta(user, opcao);
        questao4.mostrarPergunta(user, opcao);
        questao5.mostrarPergunta(user, opcao);
        questao6.mostrarPergunta(user, opcao);
        questao7.mostrarPergunta(user, opcao);
        questao8.mostrarPergunta(user, opcao);
        questao9.mostrarPergunta(user, opcao);
        questao10.mostrarPergunta(user, opcao);
    }
    int quizcpp(User& user) {
        system("cls");

        int opcao;

        Perguntas questao1;
        questao1.questao = "Qual � o s�mbolo usado para a atribui��o de valor em C++?";
        questao1.respostaCerta = "=";
        questao1.respostaErrada1 = "==";
        questao1.respostaErrada2 = ":=";
        questao1.respostaErrada3 = "-";

        Perguntas questao2;
        questao2.questao = "Qual � o operador usado para acessar o valor de um ponteiro em C++?";
        questao2.respostaCerta = "*";
        questao2.respostaErrada1 = "&";
        questao2.respostaErrada2 = "%";
        questao2.respostaErrada3 = "/";

        Perguntas questao3;
        questao3.questao = "Qual � a biblioteca padr�o em C++ para entrada e sa�da de dados?";
        questao3.respostaCerta = "iostream";
        questao3.respostaErrada1 = "stdio";
        questao3.respostaErrada2 = "cmath";
        questao3.respostaErrada3 = "string";

        Perguntas questao4;
        questao4.questao = "Qual � o resultado da opera��o 5 / 2 em C++?";
        questao4.respostaCerta = "2";
        questao4.respostaErrada1 = "2.5";
        questao4.respostaErrada2 = "3";
        questao4.respostaErrada3 = "Erro de compila��o";

        Perguntas questao5;
        questao5.questao = "Qual � o tipo de dado em C++ que pode armazenar um �nico caractere?";
        questao5.respostaCerta = "char";
        questao5.respostaErrada1 = "string";
        questao5.respostaErrada2 = "int";
        questao5.respostaErrada3 = "float";

        Perguntas questao6;
        questao6.questao = "Qual � o operador l�gico usado para nega��o em C++?";
        questao6.respostaCerta = "!";
        questao6.respostaErrada1 = "&&";
        questao6.respostaErrada2 = "||";
        questao6.respostaErrada3 = "^";

        Perguntas questao7;
        questao7.questao = "Qual � o resultado da express�o 2 + 3 * 4 em C++?";
        questao7.respostaCerta = "14";
        questao7.respostaErrada1 = "20";
        questao7.respostaErrada2 = "15";
        questao7.respostaErrada3 = "9";

        Perguntas questao8;
        questao8.questao = "Qual � o tipo de dado em C++ que pode armazenar valores verdadeiro ou falso?";
        questao8.respostaCerta = "bool";
        questao8.respostaErrada1 = "double";
        questao8.respostaErrada2 = "int";
        questao8.respostaErrada3 = "float";

        Perguntas questao9;
        questao9.questao = "Qual � a fun��o usada para imprimir na sa�da padr�o em C++";
        questao9.respostaCerta = "cout";
        questao9.respostaErrada1 = "cin";
        questao9.respostaErrada2 = "printf";
        questao9.respostaErrada3 = "scanf";

        Perguntas questao10;
        questao10.questao = "Qual � o tipo de dado em C++ que armazena valores inteiros?";
        questao10.respostaCerta = "int";
        questao10.respostaErrada1 = "double";
        questao10.respostaErrada2 = "float";
        questao10.respostaErrada3 = "char";

        questao1.mostrarPergunta(user, opcao);
        questao2.mostrarPergunta(user, opcao);
        questao3.mostrarPergunta(user, opcao);
        questao4.mostrarPergunta(user, opcao);
        questao5.mostrarPergunta(user, opcao);
        questao6.mostrarPergunta(user, opcao);
        questao7.mostrarPergunta(user, opcao);
        questao8.mostrarPergunta(user, opcao);
        questao9.mostrarPergunta(user, opcao);
        questao10.mostrarPergunta(user, opcao);
    }
    int quizcien(User& user) {
        system("cls");

        int opcao;

        Perguntas questao1;
        questao1.questao = "Qual � a menor part�cula conhecida do universo?";
        questao1.respostaCerta = "Quark";
        questao1.respostaErrada1 = "El�tron";
        questao1.respostaErrada2 = "Pr�ton";
        questao1.respostaErrada3 = "N�utron";

        Perguntas questao2;
        questao2.questao = "Qual � a velocidade da luz no v�cuo?";
        questao2.respostaCerta = "299.792.458 metros por segundo";
        questao2.respostaErrada1 = "300.000 metros por segundo";
        questao2.respostaErrada2 = "200.000 metros por segundo";
        questao2.respostaErrada3 = "250.000 metros por segundo";

        Perguntas questao3;
        questao3.questao = "O que � um buraco negro?";
        questao3.respostaCerta = "Uma regi�o do espa�o onde a gravidade � t�o forte que nada pode escapar dela, nem mesmo a luz.";
        questao3.respostaErrada1 = "Um fen�meno luminoso no c�u noturno.";
        questao3.respostaErrada2 = "Uma explos�o estelar.";
        questao3.respostaErrada3 = "Um tipo de asteroide.";

        Perguntas questao4;
        questao4.questao = "Qual � a f�rmula qu�mica da �gua?";
        questao4.respostaCerta = "H2O";
        questao4.respostaErrada1 = "CO2";
        questao4.respostaErrada2 = "O2";
        questao4.respostaErrada3 = "N2";

        Perguntas questao5;
        questao5.questao = "Porque que � que as folhas s�o verdes";
        questao5.respostaCerta = "Clorofila";
        questao5.respostaErrada1 = "Fotoss�ntese";
        questao5.respostaErrada2 = "Refletem a luz";
        questao5.respostaErrada3 = "� a cor de todos os vegetais";

        Perguntas questao6;
        questao6.questao = "Qual � a unidade b�sica de tempo no Sistema Internacional de Unidades (SI)?";
        questao6.respostaCerta = "Segundo";
        questao6.respostaErrada1 = "Minuto";
        questao6.respostaErrada2 = "Hora";
        questao6.respostaErrada3 = "Dia";

        Perguntas questao7;
        questao7.questao = "Qual � o maior planeta do sistema solar?";
        questao7.respostaCerta = "J�piter";
        questao7.respostaErrada1 = "Saturno";
        questao7.respostaErrada2 = "Marte";
        questao7.respostaErrada3 = "Urano";

        Perguntas questao8;
        questao8.questao = "Qual � a principal fun��o do DNA?";
        questao8.respostaCerta = "Armazenar informa��es gen�ticas";
        questao8.respostaErrada1 = "Produzir prote�nas";
        questao8.respostaErrada2 = "Controlar o crescimento das c�lulas";
        questao8.respostaErrada3 = "Transportar oxig�nio no sangue";

        Perguntas questao9;
        questao9.questao = "Qual � a f�rmula qu�mica do oxig�nio?";
        questao9.respostaCerta = "O2";
        questao9.respostaErrada1 = "H2O";
        questao9.respostaErrada2 = "CO2";
        questao9.respostaErrada3 = "N2";

        Perguntas questao10;
        questao10.questao = "Qual � a primeira lei de Newton?";
        questao10.respostaCerta = "Lei da in�rcia";
        questao10.respostaErrada1 = "Lei da gravidade";
        questao10.respostaErrada2 = "Lei da a��o e rea��o";
        questao10.respostaErrada3 = "Lei da conserva��o da energia";

        questao1.mostrarPergunta(user, opcao);
        questao2.mostrarPergunta(user, opcao);
        questao3.mostrarPergunta(user, opcao);
        questao4.mostrarPergunta(user, opcao);
        questao5.mostrarPergunta(user, opcao);
        questao6.mostrarPergunta(user, opcao);
        questao7.mostrarPergunta(user, opcao);
        questao8.mostrarPergunta(user, opcao);
        questao9.mostrarPergunta(user, opcao);
        questao10.mostrarPergunta(user, opcao);
    }
    void themeMenu(User& user) {
        system("cls");
        cout << "Escolha o tema do Quiz:" << endl;
        cout << "[1] => Cultura Geral" << endl;
        cout << "[2] => C++" << endl;
        cout << "[3] => Ci�ncia" << endl;
        cout << "[4] => Voltar Atr�s" << endl;
        cout << "> ";

        int option;
        cin >> option;

        switch (option) {
            case 1:
                quizcg(user);
                break;
            case 2:
                quizcpp(user);
                break;
            case 3:
                quizcien(user);
                break;
            case 4:
                bemVindo();
                break;
            default:
                cout << "Op��o inv�lida, tente novamente." << endl;
                sleep(2);
                themeMenu(user);}
    }
    int lerOpcao() {
        int a;
        while (!(cin >> a)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Op��o inv�lida, tente novamente: ";}
        return a;}

    void pontuacao(const User& user) {
    system("cls");

    ifstream scoreFile("score.txt");
    string line;
    string username;
    int score;

    cout << "Pontua��es:\n\n";

    if (scoreFile.is_open()) {
        while (getline(scoreFile, line)) {
            if (line.find("Username: " + user.username) != string::npos) {
                cout << "Voc�: " << user.score << "\n";
                break;
            } else if (line.find("Username: ") != string::npos) {
                username = line.substr(10);
                getline(scoreFile, line);
                score = stoi(line.substr(7));
                cout << username << ": " << score << "\n";}
        }
        scoreFile.close();
    } else {
        cout << "Erro ao abrir o arquivo de pontua��es.\n";}
    cout << "\nDigite qualquer tecla para continuar";
    getch();
}
    void quizMenu(User& user) {
        system("cls");
        cout << "Quiz" << endl;
        cout << "1 Come�ar Quiz" << endl;
        cout << "2 Pontua��o" << endl;
        cout << "3 Voltar Atr�s" << endl;
        cout << "> ";

        int option;
        cin >> option;

        switch (option) {
            case 1:
                themeMenu(user);
                despedida(user);
                break;
            case 2:
                pontuacao(user);
                break;
            case 3:
                bemVindo();
                break;
            default:
                cout << "Op��o inv�lida, tente novamente." << endl;
                sleep(2);
                quizMenu(user);}
    }
int main() {
    setlocale(LC_ALL, "");

    int opcao;
    User user("", "");

    do {
        bemVindo();
        opcao = lerOpcao();
        switch (opcao) {
            case 1:
                signIn();
                break;
            case 2:
                if (logIn()) {
                    quizMenu(user);}
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                despedida(user);
                break;
            default:
                cout << "Op��o inv�lida, tente novamente." << endl;
                sleep(2);}
    } while (opcao != 4);
    return 0;
    }
