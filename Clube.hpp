// Clube.hpp (Roland Teodorowitsch; 9 set. 2021)

#ifndef _CLUBE_HPP
#define _CLUBE_HPP

#include <string>

using namespace std;

class Clube {
private:
    string abreviatura;
    string nome;
    string nomeCompleto;
    string cidade;
    string estado;
public:
    Clube(string a="",string n="", string nC="", string c="", string e="");
    ~Clube();
    
    string obtemAbreviatura() const;
    string obtemNome() const;
    string obtemNomeCompleto() const;
    string obtemCidade() const;
    string obtemEstado() const;
    
    void defineAbreviatura(string a);
    void defineNome(string n);
    void defineNomeCompleto(string nC);
    void defineCidade(string c);
    void defineEstado(string e);
    
    string str() const;
    
    bool operator<(const Clube &c) const;

    friend istream& operator>>(istream& in,Clube &c);
    friend ostream& operator<<(ostream& out,const Clube &c);
};

#endif