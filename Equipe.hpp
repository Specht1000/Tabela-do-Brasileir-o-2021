#ifndef _EQUIPE_HPP
#define _EQUIPE_HPP

#include <string>
#include "Clube.hpp"

using namespace std;

class Equipe {
private:
    Clube *clube;
    int pontos;
    int jogos, vitorias, empates, derrotas;
    int golsPro, golsContra, saldoGols;
    double aproveitamento;
public:
    Equipe(Clube *c=nullptr);
    ~Equipe();
    
    Clube *obtemClube() const;
    int obtemPontos() const;
    int obtemJogos() const;
    int obtemVitorias() const;
    int obtemEmpates() const;
    int obtemDerrotas() const;
    int obtemGolsPro() const;
    int obtemGolsContra() const;
    int obtemSaldoGols() const;
    double obtemAproveitamento() const;
    
    void limpa();
    void defineClube(Clube *c);
    
    void registraPartida(int gP, int gC);
    
    string str() const;
    
    bool operator<(const Equipe &c) const;

    friend ostream& operator<<(ostream& out,const Equipe &e);
};

#endif
