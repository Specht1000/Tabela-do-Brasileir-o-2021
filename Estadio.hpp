#ifndef _ESTADIO_HPP
#define _ESTADIO_HPP

#include <string>

using namespace std;

class Estadio {
private:
    int codigo;
    string nome;
    string cidade;
    string estado;
public:
    Estadio(int cod=-1,string n="",string c="", string e="");
    ~Estadio();
    
    int obtemCodigo() const;
    string obtemNome() const;
    string obtemCidade() const;
    string obtemEstado() const;
    
    void defineCodigo(int cod);
    void defineNome(string n);
    void defineCidade(string c);
    void defineEstado(string e);
    
    string str() const;
    
    bool operator<(const Estadio &e) const;

    friend istream& operator>>(istream& in,Estadio &e);
    friend ostream& operator<<(ostream& out,const Estadio &e);
};

#endif