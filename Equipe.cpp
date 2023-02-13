#include <sstream>
#include <iomanip>
#include <string>
#include "Equipe.hpp"

Equipe::Equipe(Clube *c){
    clube = c;
    pontos = 0;
    jogos = 0;
    vitorias = 0;
    empates = 0;
    derrotas = 0;
    golsPro = 0;
    golsContra = 0;
    saldoGols = 0;
    aproveitamento = 0.0;
}

Equipe::~Equipe(){
}

Clube* Equipe::obtemClube() const{
    return clube;
}

int Equipe::obtemPontos() const{
    return pontos;
}

int Equipe::obtemJogos() const{
    return jogos;
}
int Equipe::obtemVitorias() const{
    return vitorias;
}

int Equipe::obtemEmpates() const{
    return empates;
}

int Equipe::obtemDerrotas() const{
    return derrotas;
}

int Equipe::obtemGolsPro() const{
    return golsPro;
}

int Equipe::obtemGolsContra() const{
    return golsContra;
}

int Equipe::obtemSaldoGols() const{
    return saldoGols;
}

double Equipe::obtemAproveitamento() const{
    return aproveitamento;
}

void Equipe::limpa(){
    pontos = 0;
    jogos = 0;
    vitorias = 0;
    empates = 0;
    derrotas = 0;
    golsPro = 0;
    golsContra = 0;
    saldoGols = 0;
    aproveitamento = 0.0;
}

void Equipe::defineClube(Clube *c){
    clube = c;
}

void Equipe::registraPartida(int gP, int gC){

    if(gP > gC){
        vitorias++;
        pontos = pontos + 3;
        golsPro = golsPro + gP;
        golsContra = golsContra + gC;
    }
    else if(gP == gC){
        empates++;
        pontos = pontos + 1;
        golsPro = golsPro + gP;
        golsContra = golsContra + gC;
    }
    else{
        derrotas++;
        pontos = pontos + 0;
        golsPro = golsPro + gP;
        golsContra = golsContra + gC;
    }
    saldoGols = gP - gC; 
    aproveitamento = ((pontos*(1.0))/(3.0*jogos))*100.0; 
    jogos++;
}


string Equipe::str() const{   
  stringstream ss;
  ss << setfill(' ') << setw(20) << left << clube->obtemNome();
  ss << "  " << setfill(' ') << setw(2) << right << pontos;
  ss << "  " << setfill(' ') << setw(2) << right << jogos;
  ss << "  " << setfill(' ') << setw(2) << right << vitorias;
  ss << "  " << setfill(' ') << setw(2) << right << empates;
  ss << "  " << setfill(' ') << setw(2) << right << derrotas;
  ss << "  " << setfill(' ') << setw(2) << right << golsPro;
  ss << "  " << setfill(' ') << setw(2) << right << golsContra;
  ss << " " << setfill(' ') << setw(3) << right << saldoGols;
  ss << "  " << setprecision(2) << fixed << aproveitamento;

return ss.str();   
}

bool Equipe::operator<(const Equipe &c) const{
    if(pontos < c.obtemPontos())
     return true;
    if(pontos == c.obtemPontos()){
      if(vitorias < c.obtemVitorias())
        return true;
        if(vitorias == c.obtemVitorias()){
          if(saldoGols < c.obtemSaldoGols())
          return true;
          if(saldoGols == c.obtemSaldoGols()){
            if(golsPro < c.obtemGolsPro())
            return true;
          }
        }
    }
    return false;
}


ostream& operator<<(ostream& out,const Equipe &e){
    out << e.str();
    return out;
}