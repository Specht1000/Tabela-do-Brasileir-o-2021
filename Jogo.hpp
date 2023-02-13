#ifndef _JOGO_HPP
#define _JOGO_HPP

#include <string>
#include "Clube.hpp"
#include "DiaEHora.hpp"
#include "Estadio.hpp"

using namespace std;

class Jogo {
private:
    int numero;
    DiaEHora diahora;
    Clube *mandante;
    int golsMandante;
    int golsVisitante;
    Clube *visitante;
    Estadio *estadio;
public:
    Jogo(int n, DiaEHora &dh, Clube *m, int gM, int gV, Clube *v, Estadio *e);
    ~Jogo();
    
    int obtemNumero() const;
    DiaEHora obtemDiaHora() const;
    Clube *obtemMandante() const;
    int obtemGolsMandante() const;
    int obtemGolsVisitante() const;
    Clube *obtemVisitante() const;
    Estadio *obtemEstadio() const;
    
    void defineNumero(int n);
    void defineDiaHora(DiaEHora &dh);
    void defineMandante(Clube *m);
    void defineGolsMandante(int gM);
    void defineGolsVisitante(int gV);
    void defineVisitante(Clube *v);
    void defineEstadio(Estadio *e);
    
    string str() const;
    
    bool operator<(const Jogo &j) const;

    friend ostream& operator<<(ostream& out,const Jogo &j);
};

#endif
