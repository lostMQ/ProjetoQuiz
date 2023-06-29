#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <random>
#include <chrono>

 

using namespace std;

 

struct perguntasFaceis{;

 


    string pergunta;
    string respostaCerta;
    string respostaErrada1;
    string respostaErrada2;
    string respostaErrada3;
    int indiceRespostaCorreta;

 

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
        cout << "Escolha uma opção (1-4): ";
        cin >> opcao;

 

        if (opcao == indiceRespostaCorreta){
            cout << "Resposta correta!"<< endl;
            }else{
                cout << "Resposta errada!"<< endl;}
        }
    };

 

struct perguntasMedias{

 

    string pergunta;
    string respostaCerta;
    string respostaErrada1;
    string respostaErrada2;
    string respostaErrada3;
    int indiceRespostaCorreta;

 

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
        cout << "Escolha uma opção (1-4): ";
        cin >> opcao;

 

        if (opcao == indiceRespostaCorreta){
            cout << "Resposta correta!"<< endl;
            }else{
                cout << "Resposta errada!"<< endl;}
        }
    };

 

struct perguntasDificeis{

 

    string pergunta;
    string respostaCerta;
    string respostaErrada1;
    string respostaErrada2;
    string respostaErrada3;
    int indiceRespostaCorreta;

 

 

 

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
        cout << "Escolha uma opção (1-4): ";
        cin >> opcao;

 

        if (opcao == indiceRespostaCorreta){
            cout << "Resposta correta!"<< endl;
            }else{
                cout << "Resposta errada!"<< endl;}
        }
    };

 

int main(){

 

    int opcao;

 




    perguntasFaceis questaoM1;

    questaoM1.pergunta = "Quem escreveu 'Orgulho e Preconceito'?";

    questaoM1.respostaErrada2 = "Emily Brontë";

    questaoM1.respostaErrada1 = "Charlotte Brontë";

    questaoM1.respostaCerta = "Jane Austen";

    questaoM1.respostaErrada3 = "Virginia Woolf";



    questaoM1.mostrarPergunta(opcao);






    perguntasFaceis questaoM2;

    questaoM2.pergunta = "Qual é o maior deserto do mundo?";

    questaoM2.respostaErrada1 = "Deserto do Gobi";

    questaoM2.respostaCerta = "Deserto do Saara";

    questaoM2.respostaErrada2 = "Deserto da Arábia";

    questaoM2.respostaErrada3 = "Deserto do Atacama";





    questaoM2.mostrarPergunta(opcao);






    perguntasFaceis questaoM3;

    questaoM3.pergunta = "Quem foi o criador da teoria da relatividade restrita?";

    questaoM3.respostaErrada1 = "Isaac Newton";

    questaoM3.respostaCerta = "Albert Einstein";

    questaoM3.respostaErrada2 = "Galileu Galilei";

    questaoM3.respostaErrada3 = "Max Planck";




    questaoM3.mostrarPergunta(opcao);





    perguntasFaceis questaoM4;

    questaoM4.pergunta = "Qual a capital de Espanha?";

    questaoM4.respostaErrada3 = "Barcelona";

    questaoM4.respostaErrada1 = "Sevilha";

    questaoM4.respostaErrada2 = "Valencia";

    questaoM4.respostaCerta = "Madrid";



    questaoM4.mostrarPergunta(opcao);




      perguntasFaceis questaoM5;

    questaoM5.pergunta = "Qual é o autor do livro 'A Metamorfose?'" ;

    questaoM5.respostaCerta = "Franz Kafka";

    questaoM5.respostaErrada1 = "Leo Tolstoy";

    questaoM5.respostaErrada2 = "F. Scott Fitzgerald";

    questaoM5.respostaErrada3 = "Ernest Hemingway";



    questaoM5.mostrarPergunta(opcao);




     perguntasFaceis questaoM6;

    questaoM6.pergunta = "Em qual país está localizada a Torre Eiffel?";

    questaoM6.respostaErrada3 = "Itália";

    questaoM6.respostaCerta = "França";

    questaoM6.respostaErrada2 = "Alemanha";

    questaoM6.respostaErrada1 = "Alemanha";



    questaoM6.mostrarPergunta(opcao);




     perguntasFaceis questaoM7;

    questaoM7.pergunta = "Qual é o instrumento musical conhecido como 'rei dos instrumentos'?";

    questaoM7.respostaErrada3 = "Violino";

    questaoM7.respostaErrada1 = "Saxofone";

    questaoM7.respostaErrada2 = "Trompete";

    questaoM7.respostaCerta = "Piano";



    questaoM7.mostrarPergunta(opcao);





     perguntasFaceis questaoM8;

    questaoM8.pergunta = "Quem foi o presidente dos Estados Unidos durante a Segunda Guerra Mundial?";

    questaoM8.respostaCerta = "Franklin D. Roosevelt";

    questaoM8.respostaErrada1 = "Harry S. Truman";

    questaoM8.respostaErrada2 = "Dwight D. Eisenhower";

    questaoM8.respostaErrada3 = "John F. Kennedy";



    questaoM8.mostrarPergunta(opcao);





     perguntasFaceis questaoM9;

    questaoM9.pergunta = "Quem foi o líder político sul-africano que lutou contra o apartheid?";

    questaoM9.respostaErrada3 = "Nelson Mandela";

    questaoM9.respostaErrada1 = "Desmond Tutu";

    questaoM9.respostaErrada2 = "Jacob Zuma";

    questaoM9.respostaCerta = "Thabo Mbeki";



    questaoM9.mostrarPergunta(opcao);





     perguntasFaceis questaoM10;

    questaoM10.pergunta = "Em que ano acabou a segunda guerra mundial?";

    questaoM10.respostaErrada3 = "1928";

    questaoM10.respostaErrada1 = "1918";

    questaoM10.respostaErrada2 = "1941";

    questaoM10.respostaCerta = "1945";



    questaoM10.mostrarPergunta(opcao);





    perguntasFaceis questaoM11;

    questaoM11.pergunta = "Quem pintou a Mona Lisa?";

    questaoM11.respostaErrada3 = "Vincent van Gogh";

    questaoM11.respostaErrada1 = "Pablo Picasso";

    questaoM11.respostaCerta = "Leonardo da Vinci";

    questaoM11.respostaErrada2 = "Michelangelo";



    questaoM11.mostrarPergunta(opcao);




     perguntasFaceis questaoM12;

    questaoM12.pergunta = "Em que ano é que a mulher do George Bush, Laurs Bush cometeu homicidio classificado, e usou o 9/11 para o cobrir?";

    questaoM12.respostaCerta = "1963";

    questaoM12.respostaErrada1 = "1928";

    questaoM12.respostaErrada3 = "1918";

    questaoM12.respostaErrada2 = "1945";



    questaoM12.mostrarPergunta(opcao);




     perguntasFaceis questaoM13;

    questaoM13.pergunta = "Quem escreveu 'Dom Quixote'?";

    questaoM13.respostaErrada3 = "William Shakespeare";

    questaoM13.respostaCerta = "Miguel de Cervantes";

    questaoM13.respostaErrada1 = "Fyodor Dostoevsky";

    questaoM13.respostaErrada2 = "Jane Austen";



    questaoM13.mostrarPergunta(opcao);






     perguntasFaceis questaoM14;

    questaoM14.pergunta = "Qual é a maior cordilheira do mundo?";

    questaoM14.respostaErrada3 = "Montanhas Rochosas";

    questaoM14.respostaCerta = "Cordilheira dos Andes";

    questaoM14.respostaErrada1 = "Montanhas dos Himalaias";

    questaoM14.respostaErrada2 = "Alpes";



    questaoM14.mostrarPergunta(opcao);







     perguntasFaceis questaoM15;

    questaoM15.pergunta = "Qual é o maior planeta do sistema solar?";

    questaoM15.respostaErrada3 = "Terra";

    questaoM15.respostaCerta = "Júpiter";

    questaoM15.respostaErrada1 = "Marte";

    questaoM15.respostaErrada2 = "Vênus";



    questaoM15.mostrarPergunta(opcao);






     perguntasFaceis questaoM16;

    questaoM16.pergunta = "Quem foi o primeiro homem a pisar na Lua?";

    questaoM16.respostaCerta = "Neil Armstrong";

    questaoM16.respostaErrada1 = "Buzz Aldrin";

    questaoM16.respostaErrada3 = "Yuri Gagarin";

    questaoM16.respostaErrada2 = "John F. Kennedy";



    questaoM16.mostrarPergunta(opcao);






     perguntasFaceis questaoM17;

    questaoM17.pergunta = "Quem escreveu 'Romeu e Julieta'?";

    questaoM17.respostaCerta = "William Shakespeare";

    questaoM17.respostaErrada1 = "Charles Dickens";

    questaoM17.respostaErrada3 = "Jane Austen";

    questaoM17.respostaErrada2 = "Mark Twain";



    questaoM17.mostrarPergunta(opcao);







     perguntasFaceis questaoM18;

    questaoM18.pergunta = "Qual é o país com a maior população do mundo?";

    questaoM18.respostaErrada3 = "Brasil";

    questaoM18.respostaErrada1 = "Russia";

    questaoM18.respostaCerta = "China";

    questaoM18.respostaErrada2 = "India";



    questaoM18.mostrarPergunta(opcao);






     perguntasFaceis questaoM19;

    questaoM19.pergunta = "Quem foi o pintor do famoso quadro 'A Noite Estrelada'?";

    questaoM19.respostaErrada3 = "Claude Monet";

    questaoM19.respostaErrada1 = "Salvador Dal�";

    questaoM19.respostaCerta = "Vincent van Gog";

    questaoM19.respostaErrada2 = "Pablo Picasso";



    questaoM19.mostrarPergunta(opcao);







     perguntasFaceis questaoM20;

    questaoM20.pergunta = "Qual � a capital da Fran�a?";

    questaoM20.respostaErrada3 = "Roma";

    questaoM20.respostaCerta = "Paris";

    questaoM20.respostaErrada1 = "Berlim";

    questaoM20.respostaErrada2 = "Londres";



    questaoM20.mostrarPergunta(opcao);




    perguntasMedias questaoM1;
    questaoM1.pergunta = "Qual é o país com a maior área territorial do mundo?";
    questaoM1.respostaCerta = "Rússia";
    questaoM1.respostaErrada1 = "China";
    questaoM1.respostaErrada2 = "Estados Unidos";
    questaoM1.respostaErrada3 = "Brasil";

 

    questaoM1.mostrarPergunta(opcao);

 

    perguntasMedias questaoM2;
    questaoM2.pergunta = "Quem escreveu a obra 'O Pequeno Príncipe' ?";
    questaoM2.respostaCerta = " Antoine de Saint-Exupéry";
    questaoM2.respostaErrada1 = " F. Scott Fitzgerald";
    questaoM2.respostaErrada2 = "J.D. Salinger";
    questaoM2.respostaErrada3 = "Antoine de Saint-John Perse";

 


    questaoM2.mostrarPergunta(opcao);

 
perguntasMedias questaoM3;
    questaoM3.pergunta = "Qual é o símbolo químico do elemento cálcio?";
    questaoM3.respostaCerta = "Ca";
    questaoM3.respostaErrada1 = "Cl";
    questaoM3.respostaErrada2 = "Co";
    questaoM3.respostaErrada3 = "Ce";

    questaoM3.mostrarPergunta(opcao);

   
 perguntasMedias questaoM4;
    questaoM4.pergunta = "Quem foi o pintor do famoso quadro ´A Persistência da Memória´ ?";
    questaoM4.respostaCerta = "Salvador Dalí";
    questaoM4.respostaErrada1 = "Claude Monet";
    questaoM4.respostaErrada2 = "Pablo Picasso";
    questaoM4.respostaErrada3 = "Vincent van Gogh";

    questaoM4.mostrarPergunta(opcao);

 
perguntasMedias questaoM5;
    questaoM5.pergunta = "Qual é o país com a maior área florestal do mundo? ";
    questaoM5.respostaCerta = "Brasil";
    questaoM5.respostaErrada1 = "Canadá";
    questaoM5.respostaErrada2 = "Rússia";
    questaoM5.respostaErrada3 = "Estados Unidos";


    questaoM5.mostrarPergunta(opcao);
 
perguntasMedias questaoM6;
    questaoM6.pergunta = "Quem foi o autor da peça de teatro ´Romeu e Julieta´?";
    questaoM6.respostaCerta = "William Shakespeare";
    questaoM6.respostaErrada1 = "Christopher Marlowe";
    questaoM6.respostaErrada2 = " Oscar Wilde";
    questaoM6.respostaErrada3 = "Tennessee Williams";
    
    questaoM6.mostrarPergunta(opcao);


perguntasMedias questaoM7;
    questaoM7.pergunta = "Qual é o maior arquipélago do mundo?";
    questaoM7.respostaCerta = "Ilhas Maldivas";
    questaoM7.respostaErrada1 = "Havaí";
    questaoM7.respostaErrada2 = "Indonésia";
    questaoM7.respostaErrada3 = "Filipinas";


    questaoM7.mostrarPergunta(opcao);
 

 perguntasMedias questaoM8;
    questaoM8.pergunta = "Quem escreveu a obra ´A Divina Comédia´?";
    questaoM8.respostaCerta = "Dante Alighieri";
    questaoM8.respostaErrada1 = "Giovanni Boccaccio";
    questaoM8.respostaErrada2 = " Niccolò Machiavelli";
    questaoM8.respostaErrada3 = "Petrarch";
    questaoM8.mostrarPergunta(opcao);

    perguntasMedias questaoM9;
    questaoM9.pergunta = "Qual é o nome do cientista que desenvolveu a teoria da evolução das espécies por seleção natural?";
    questaoM9.respostaCerta = " Charles Darwin";
    questaoM9.respostaErrada1 = "Gregor Mendel";
    questaoM9.respostaErrada2 = "Alfred Russel Wallace";
    questaoM9.respostaErrada3 = "Louis Pasteur";
    questaoM9.mostrarPergunta(opcao);


    perguntasMedias questaoM10;
    questaoM10.pergunta = "Qual é a capital da Argentina?    ";
    questaoM10.respostaCerta = "Buenos Aires";
    questaoM10.respostaErrada1 = "Montevidéu";
    questaoM10.respostaErrada2 = "Santiago";
    questaoM10.respostaErrada3 = "Lima";
    questaoM10.mostrarPergunta(opcao);
    

    perguntasMedias questaoM11;
    questaoM11.pergunta = "Qual é o rio mais longo do mundo?   ";
    questaoM11.respostaCerta = "Rio Nilo";
    questaoM11.respostaErrada1 = "Rio Amazonas";
    questaoM11.respostaErrada2 = "Rio Yangtzé";
    questaoM11.respostaErrada3 = "Rio Mississipi";
    questaoM11.mostrarPergunta(opcao);
 

 perguntasMedias questaoM12;
    questaoM12.pergunta = "Quem escreveu a peça de teatro ´Hamlet´?";
    questaoM12.respostaCerta = "William Shakespeare";
    questaoM12.respostaErrada1 = "Henrik Ibsen";
    questaoM12.respostaErrada2 = "Tennessee Williams";
    questaoM12.respostaErrada3 = "Anton Chekhov";
    questaoM12.mostrarPergunta(opcao);
 

 perguntasMedias questaoM13;
    questaoM13.pergunta = "Quem foi o cientista que formulou a Teoria da Relatividade?";
    questaoM13.respostaCerta = "Isaac Newton";
    questaoM13.respostaErrada1 = "Albert Einstein";
    questaoM13.respostaErrada2 = "Galileu Galilei";
    questaoM13.respostaErrada3 = "Marie Curie";
    questaoM13.mostrarPergunta(opcao);
 

 perguntasMedias questaoM14;
    questaoM14.pergunta = "Qual é o maior oceano do mundo?  ";
    questaoM14.respostaCerta = "Oceano Pacífico";
    questaoM14.respostaErrada1 = "Oceano Índico";
    questaoM14.respostaErrada2 = "Oceano Atlântico";
    questaoM14.respostaErrada3 = "Oceano Ártico";
    questaoM14.mostrarPergunta(opcao);
 

 perguntasMedias questaoM15;
    questaoM15.pergunta = "Qual é o autor do livro ´1984´?";
    questaoM15.respostaCerta = "George Orwell";
    questaoM15.respostaErrada1 = "Aldous Huxley";
    questaoM15.respostaErrada2 = " Ray Bradbury";
    questaoM15.respostaErrada3 = "J.R.R. Tolkien";
    questaoM15.mostrarPergunta(opcao);
 

 perguntasMedias questaoM16;
    questaoM16.pergunta = "Quem foi o líder do movimento pelos direitos civis nos Estados Unidos na década de 1960?";
    questaoM16.respostaCerta = "Martin Luther King Jr.";
    questaoM16.respostaErrada1 = "Rosa Parks";
    questaoM16.respostaErrada2 = "Malcolm X";
    questaoM16.respostaErrada3 = "Nelson Mandela";
    questaoM16.mostrarPergunta(opcao);
 

 perguntasMedias questaoM17;
    questaoM17.pergunta = "Qual é o instrumento musical de cordas mais agudo? ";
    questaoM17.respostaCerta = "Harpa";
    questaoM17.respostaErrada1 = "Violino";
    questaoM17.respostaErrada2 = "Guitarra";
    questaoM17.respostaErrada3 = "Viola";
    questaoM17.mostrarPergunta(opcao);
 

 perguntasMedias questaoM18;
    questaoM18.pergunta = "Qual é o nome da maior cadeia montanhosa da América do Norte?  ";
    questaoM18.respostaCerta = "Montanhas Rochosas";
    questaoM18.respostaErrada1 = "Sierra Nevada";
    questaoM18.respostaErrada2 = " Montanhas dos Apalaches";
    questaoM18.respostaErrada3 = "Montanhas dos Andes";
    questaoM18.mostrarPergunta(opcao);
 

 perguntasMedias questaoM19;
    questaoM19.pergunta = "Quem escreveu ´Cem Anos de Solidão`? ";
    questaoM19.respostaCerta = "a) Gabriel García Márquez";
    questaoM19.respostaErrada1 = "b) Pablo Neruda";
    questaoM19.respostaErrada2 = "c) Isabel Allende";
    questaoM19.respostaErrada3 = "d) Jorge Luis Borges";
    questaoM19.mostrarPergunta(opcao);
 

 perguntasMedias questaoM20;
    questaoM20.pergunta = "Qual é o símbolo químico do elemento ouro?";
    questaoM20.respostaCerta = "Au";
    questaoM20.respostaErrada1 = "Ag";
    questaoM20.respostaErrada2 = "Hg";
    questaoM20.respostaErrada3 = "Fe";
    questaoM20.mostrarPergunta(opcao);


    perguntasDificeis questaoM1;

    questaoM1.pergunta = "Em qual cidade está localizada a sede da Organização das Nações Unidas (ONU)?";

    questaoM1.respostaErrada2 = "Paris";

    questaoM1.respostaErrada1 = "Genebra";

    questaoM1.respostaCerta = "Nova York";

    questaoM1.respostaErrada3 = "Londres";



    questaoM1.mostrarPergunta(opcao);






    perguntasDificeis questaoM2;

    questaoM2.pergunta = "Quem foi o primeiro presidente dos Estados Unidos?";

    questaoM2.respostaCerta = "George Washington";

    questaoM2.respostaErrada1 = "Thomas Jefferson";

    questaoM2.respostaErrada2 = "John Adams";

    questaoM2.respostaErrada3 = "Abraham Lincoln";







    questaoM2.mostrarPergunta(opcao);


    perguntasDificeis questaoM3;

    questaoM3.pergunta = "Qual é a capital do Canadá?";

    questaoM3.respostaErrada2 = "Toronto";

    questaoM3.respostaCerta = "Ottawa";

    questaoM3.respostaErrada3 = "Vancouver";

    questaoM3.respostaErrada3 = "Montreal";



    questaoM3.mostrarPergunta(opcao);

        perguntasDificeis questaoM4;

    questaoM4.pergunta = "Quem escreveu a obra 'A Origem das Espécies'?";

    questaoM4.respostaCerta = "Charles Darwin";

    questaoM4.respostaErrada1 = "Sigmund Freud";

    questaoM4.respostaErrada2 = "Karl Marx";

    questaoM4.respostaErrada3 = "Friedrich Nietzsche";



    questaoM4.mostrarPergunta(opcao);

        perguntasDificeis questaoM5;

    questaoM5.pergunta = "Qual é o monte mais alto do mundo?";

    questaoM5.respostaCerta = "Monte Everest";

    questaoM5.respostaErrada1 = "K2";

    questaoM5.respostaErrada2 = "Monte Kilimanjaro";

    questaoM5.respostaErrada3 = "Monte McKinley";



    questaoM5.mostrarPergunta(opcao);

        perguntasDificeis questaoM6;

    questaoM6.pergunta = "Quem foi o primeiro imperador romano?";

    questaoM6.respostaErrada2 = "Júlio César";

    questaoM6.respostaCerta = "Augusto";

    questaoM6.respostaErrada1 = "Tibério";

    questaoM6.respostaErrada3 = "Nero";



    questaoM6.mostrarPergunta(opcao);

    perguntasDificeis questaoM7;

    questaoM7.pergunta = "Qual é o autor da pintura 'Guernica'?";

    questaoM7.respostaCerta = "Pablo Picasso";

    questaoM7.respostaErrada1 = "Salvador Dalí";

    questaoM7.respostaErrada2 = "Vincent van Gogh";

    questaoM7.respostaErrada3 = "Claude Monet";



    questaoM7.mostrarPergunta(opcao);

    perguntasDificeis questaoM8;

    questaoM8.pergunta = "Quem foi o líder da Revolução Russa em 1917";

    questaoM8.respostaCerta = "Vladimir Lenin";

    questaoM8.respostaErrada1 = "Joseph Stalin";

    questaoM8.respostaErrada2 = "Leon Trotsky";

    questaoM8.respostaErrada3 = "Vladimir Putin";



    questaoM8.mostrarPergunta(opcao);

        perguntasDificeis questaoM9;

    questaoM9.pergunta = "Qual é o símbolo químico do elemento nitrogénio?";

    questaoM9.respostaCerta = "N";

    questaoM9.respostaErrada1 = "Ni";

    questaoM9.respostaErrada2 = "Na";

    questaoM9.respostaErrada3 = "Ne";



    questaoM9.mostrarPergunta(opcao);


        perguntasDificeis questaoM10;

    questaoM10.pergunta = "Qual é a maior estátua do mundo?";

    questaoM10.respostaErrada2 = "Estátua da Liberdade";

    questaoM10.respostaErrada1 = "Estátua de Cristo Redentor";

    questaoM10.respostaErrada3 = "Estátua de Buda no Templo de Primavera";

    questaoM10.respostaCerta = "Estátua da Unidade";



    questaoM10.mostrarPergunta(opcao);
 

 perguntasDificeis questaoM11;
    questaoM11.pergunta = "Quem escreveu a obra `Ulisses´ ?";
    questaoM11.respostaCerta = "James Joyce";
    questaoM11.respostaErrada1 = "Virginia Woolf";
    questaoM11.respostaErrada2 = "Ernest Hemingway";
    questaoM11.respostaErrada3 = "F. Scott Fitzgerald";
    questaoM11.mostrarPergunta(opcao);

    perguntasDificeis questaoM12;
    questaoM12.pergunta = "Qual é o maior lago do mundo em volume de água?";
    questaoM12.respostaCerta = "Lago Vitória";
    questaoM12.respostaErrada1 = "Lago Baikal";
    questaoM12.respostaErrada2 = "Lago Superior";
    questaoM12.respostaErrada3 = "Lago Titicaca";
    questaoM12.mostrarPergunta(opcao);

    perguntasDificeis questaoM13;
    questaoM13.pergunta = "Quem foi o autor do livro ´A Revolução dos Bichos´?  ";
    questaoM13.respostaCerta = "George Orwell";
    questaoM13.respostaErrada1 = "Aldous Huxley";
    questaoM13.respostaErrada2 = "Ray Bradbury";
    questaoM13.respostaErrada3 = "William Golding";
    questaoM13.mostrarPergunta(opcao);

    perguntasDificeis questaoM14;
    questaoM14.pergunta = "Qual é o nome do famoso físico teórico que propôs a teoria das cordas?";
    questaoM14.respostaCerta = "Brian Greene";
    questaoM14.respostaErrada1 = "Albert Einstein";
    questaoM14.respostaErrada2 = "Stephen Hawking";
    questaoM14.respostaErrada3 = "Michio Kaku";
    questaoM14.mostrarPergunta(opcao);

    perguntasDificeis questaoM15;
    questaoM15.pergunta = "Qual é o maior vulcão ativo da Europa?";
    questaoM15.respostaCerta = "Etna";
    questaoM15.respostaErrada1 = "Vesúvio";
    questaoM15.respostaErrada2 = "Stromboli";
    questaoM15.respostaErrada3 = "Hekla";
    questaoM15.mostrarPergunta(opcao);

    perguntasDificeis questaoM16;
    questaoM16.pergunta = "Quem foi o líder político cubano que governou o país por mais de 40 anos?";
    questaoM16.respostaCerta = "Fidel Castro";
    questaoM16.respostaErrada1 = "Che Guevara";
    questaoM16.respostaErrada2 = "Raúl Castro";
    questaoM16.respostaErrada3 = "José Martí";
    questaoM16.mostrarPergunta(opcao);

    perguntasDificeis questaoM17;
    questaoM17.pergunta = "Qual é o autor da obra ´Cem Anos de Solidão´?";
    questaoM17.respostaCerta = "Gabriel García Márquez";
    questaoM17.respostaErrada1 = "Isabel Allende";
    questaoM17.respostaErrada2 = "Jorge Luis Borges";
    questaoM17.respostaErrada3 = "Pablo Neruda";
    questaoM17.mostrarPergunta(opcao);

    perguntasDificeis questaoM18;
    questaoM18.pergunta = "Quem foi o físico alemão que desenvolveu a teoria da relatividade geral?";
    questaoM18.respostaCerta = "Albert Einstein";
    questaoM18.respostaErrada1 = "Max Planck";
    questaoM18.respostaErrada2 = "Erwin Schrödinger";
    questaoM18.respostaErrada3 = "Werner Heisenberg";
    questaoM18.mostrarPergunta(opcao);

    perguntasDificeis questaoM19;
    questaoM19.pergunta = "Qual é o símbolo químico do elemento mercúrio?";
    questaoM19.respostaCerta = "Hg";
    questaoM19.respostaErrada1 = "Me";
    questaoM19.respostaErrada2 = "Mc";
    questaoM19.respostaErrada3 = "Mo";
    questaoM19.mostrarPergunta(opcao);

    perguntasDificeis questaoM20;
    questaoM20.pergunta = "Qual é a capital da Índia?";
    questaoM20.respostaCerta = "Nova Deli";
    questaoM20.respostaErrada1 = "Chennai";
    questaoM20.respostaErrada2 = "Mumbai";
    questaoM20.respostaErrada3 = "Calcutá";
    questaoM20.mostrarPergunta(opcao);
 


    return 0;
}
 


    perguntasDificeis questaoM;
    questaoM.pergunta = "";
    questaoM.respostaCerta = "";
    questaoM.respostaErrada1 = "";
    questaoM.respostaErrada2 = "";
    questaoM.respostaErrada3 = "";
    questaoM.mostrarPergunta(opcao);