#include <iostream>
#include "Estadio.hpp"
#include <sstream>

Estadio::Estadio(int cod,string n,string c, string e){
    codigo = cod;
    nome = n;
    cidade = c;
    estado = e;
}

Estadio::~Estadio(){
}

int Estadio::obtemCodigo() const{
    return codigo;
}

string Estadio::obtemNome() const{
    return nome;
}

string Estadio::obtemCidade() const{
    return cidade;
}
string Estadio::obtemEstado() const{
    return estado;
}

void Estadio::defineCodigo(int cod){
    codigo = cod;
}
void Estadio::defineNome(string n){
    nome = n;
}

void Estadio::defineCidade(string c){
    cidade = c;
}
void Estadio::defineEstado(string e){
    estado = e;
}

string Estadio::str() const{
    stringstream ss;
    //[1] Arena Pantanal (Cuiabá - MT)
    ss << "[" << codigo << "] " << nome << " (" << cidade << " - " << estado << ")";
    return ss.str();
}

bool Estadio::operator<(const Estadio &e) const{
    return sizeof(nome)<sizeof(e.nome);
}

istream& operator>>(istream& in,Estadio &e){
  string co, n, c, es;

  getline(in,co);
  if (co=="" || !in.good())
    return in;
  getline(in,n);
  if (n=="" || !in.good())
    return in;
  getline(in,c);
  if (c=="" || !in.good())
    return in;
  getline(in,es);
  if (es=="" || !in.good())
    return in;
  
  e.codigo = stoi(co);
  e.nome = n;
  e.cidade = c;
  e.estado = es;

  return in;
  }

ostream& operator<<(ostream& out,const Estadio &e){
    return out << e.str();
}
