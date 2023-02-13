#include "Clube.hpp"
#include <sstream>


Clube::Clube(string a,string n, string nC, string c, string e){
    abreviatura = a;
    nome = n;
    nomeCompleto = nC;
    cidade = c;
    estado = e;
}
Clube::~Clube(){
}

string Clube::obtemAbreviatura() const{
    return abreviatura;
}

string Clube::obtemNome() const{
    return nome;
}

string Clube::obtemNomeCompleto() const{
    return nomeCompleto;
}

string Clube::obtemCidade() const{
    return cidade;
}

string Clube::obtemEstado() const{
    return estado;
}

void Clube::defineAbreviatura(string a){
    abreviatura = a;
}

void Clube::defineNome(string n){
    nome = n;
}

void Clube::defineNomeCompleto(string nC){
    nomeCompleto = nC;
}

void Clube::defineCidade(string c){
    cidade = c;
}

void Clube::defineEstado(string e){
    estado = e;
}

string Clube::str() const{
    stringstream ss;

    ss << "[" << abreviatura << "] ";
    ss << nome << " / ";
    ss << nomeCompleto << " (";
    ss << cidade << " - " << estado << ")";

    return ss.str();
}

bool Clube::operator<(const Clube &c) const{
    if(nome < c.obtemNome())
        return true;
    return false;
}

istream& operator>>(istream& in,Clube &c){
    string a, n, nC, city, e;

    getline(in,a);
    if(a=="" || !in.good()) return in;
    getline(in,n);
    if(n=="" || !in.good()) return in;
    getline(in,nC);
    if(nC=="" || !in.good()) return in;
    getline(in,city);
    if(city=="" || !in.good()) return in;
    getline(in,e);
    if(e=="" || !in.good()) return in;

    c.abreviatura = a;
    c.nome = n;
    c.nomeCompleto = nC;
    c.cidade = city;
    c.estado = e;

    return in;
}

ostream& operator<<(ostream& out,const Clube &c){
    out << c.str();
    return out;
}
