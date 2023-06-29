#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <random>
#include <chrono>
#include <conio.h>
#include <unistd.h>

using namespace std;

struct perguntasFaceis{


    string pergunta;
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



        cout << pergunta << endl;
        for(int i = 0; i < 4; i++) {
            cout << i+1 << ". " << respostasAleatorias[i] << endl;
            if (respostasAleatorias[i] == respostaCerta){
                    indiceRespostaCorreta = i + 1;
            }
        }
        cout << "Tem 10s para escolher uma opcao (1-4): " << endl;

        int endTime = 5;
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

struct perguntasMedias{

    string pergunta;
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



        cout << pergunta << endl;
        for(int i = 0; i < 4; i++) {
            cout << i+1 << ". " << respostasAleatorias[i] << endl;
            if (respostasAleatorias[i] == respostaCerta){
                    indiceRespostaCorreta = i + 1;
            }
        }
        cout << "Tem 10s para escolher uma opcao (1-4): " << endl;

        int endTime = 5;
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

struct perguntasDificeis{

    string pergunta;
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



        cout << pergunta << endl;
        for(int i = 0; i < 4; i++) {
            cout << i+1 << ". " << respostasAleatorias[i] << endl;
            if (respostasAleatorias[i] == respostaCerta){
                    indiceRespostaCorreta = i + 1;
            }
        }
        cout << "Tem 10s para escolher uma opcao (1-4): " << endl;

       int endTime = 5;
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


int main(){
    setlocale(LC_ALL,"");

    int opcao;

    perguntasMedias questaoM1;
    questaoM1.pergunta = "Qual é o tipo de dado em C++ que armazena números inteiros de tamanho maior que o tipo int?";
    questaoM1.respostaCerta = "long";
    questaoM1.respostaErrada1 = "short";
    questaoM1.respostaErrada2 = "float";
    questaoM1.respostaErrada3 = "doble";

    questaoM1.mostrarPergunta(opcao);

    perguntasMedias questaoM2;
    questaoM2.pergunta = "Qual é o operador lógico usado para verificar se duas condições são verdadeiras em C++?";
    questaoM2.respostaCerta = "D. Afonso Henriques";
    questaoM2.respostaErrada1 = "Mickey";
    questaoM2.respostaErrada2 = "Pluto";
    questaoM2.respostaErrada3 = "Pateta";


    questaoM2.mostrarPergunta(opcao);


    perguntasMedias questaoM3;
    questaoM3.pergunta = "Quem foi o primeiro Rei de Portugal?";
    questaoM3.respostaCerta = "D. Afonso Henriques";
    questaoM3.respostaErrada1 = "Mickey";
    questaoM3.respostaErrada2 = "Pluto";
    questaoM3.respostaErrada3 = "Pateta";

    questaoM3.mostrarPergunta(opcao);

    perguntasMedias questaoM4;
    questaoM4.pergunta = "Quem foi o primeiro Rei de Portugal?";
    questaoM4.respostaCerta = "D. Afonso Henriques";
    questaoM4.respostaErrada1 = "Mickey";
    questaoM4.respostaErrada2 = "Pluto";
    questaoM4.respostaErrada3 = "Pateta";

    questaoM4.mostrarPergunta(opcao);


    return 0;
}