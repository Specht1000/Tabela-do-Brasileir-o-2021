#ifndef _APLICACAO_HPP
#define _APLICACAO_HPP

#include <string>
#include <vector>
#include "Clube.hpp"
#include "Equipe.hpp"
#include "Estadio.hpp"
#include "Jogo.hpp"
#include "DiaEHora.hpp"

using namespace std;

class Aplicacao {
private:
    vector<Clube *> clubes;
    vector<Equipe *> equipes;
    vector<Estadio *> estadios;
    vector<Jogo *> jogos;
    void ordenaJogos();
    Equipe *obtemEquipe(Clube *c);
    void calculaClassificacao();
    void ordenaEquipes();
    int indiceEstadio(Estadio *e);
    static vector<string> splitCSV(string linhaCSV, char separador=';');        
public:
    Aplicacao();
    ~Aplicacao();
    
    bool leClubes(string arquivo);
    bool leClubesCSV(string arquivo);
    int obtemNumClubes();
    Clube *obtemClube(string abrev);
    void mostraClubes();

    bool leEstadios(string arquivo);
    bool leEstadiosCSV(string arquivo);
    int obtemNumEstadios();
    Estadio *obtemEstadio(int cod);
    void mostraEstadios();

    bool leJogos(string arquivo);
    bool leJogosCSV(string arquivo);
    int obtemNumJogos();
    Jogo *obtemJogo(int cod);
    void mostraJogos();
    
    void mostraClassificacao();
    void mostraPartidasPorEstadio();
};

#endif
