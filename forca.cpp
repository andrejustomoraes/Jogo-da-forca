#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "imprime_cabecalho.hpp"
#include "le_arquivo.hpp"
#include "sorteia_palavra.hpp"
#include "chuta.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "adiciona_palavra.hpp"
#include "nao_acertou.hpp"

using namespace std;


static string palavra_secreta;
static map<char, bool> chutou;
static vector<char> chutes_errados;

int main()
{
    
    Forca::imprime_cabecalho();

    palavra_secreta = Forca::sorteia_palavra();

    while(Forca::nao_acertou(palavra_secreta, chutou) && chutes_errados.size() < 5) {
        Forca::imprime_erros(chutes_errados);

        Forca::imprime_palavra(palavra_secreta, chutou);

        Forca::chuta(chutou, chutes_errados, palavra_secreta);
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;

    if(Forca::nao_acertou(palavra_secreta, chutou)){
        cout << "Você perdeu! Tente novamente!" << endl;
    }
    else{
        cout << "Parabéns! Você acertou a palavra secreta!" << endl;

        cout << "Você deseja adicionar uma nova palavra ao banco? (S/N) ";
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            Forca::adiciona_palavra();
        }
    }

    cin.get();
}