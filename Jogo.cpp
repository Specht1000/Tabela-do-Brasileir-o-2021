#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Jogo.hpp"

Jogo::Jogo(int n, DiaEHora &dh, Clube *m, int gM, int gV, Clube *v, Estadio *e){
    numero = n;
    diahora = dh;
    mandante = m;
    golsMandante = gM;
    golsVisitante = gV;
    visitante = v;
    estadio = e;
}
Jogo::~Jogo(){
}

int Jogo::obtemNumero() const{
    return numero;
}
DiaEHora Jogo::obtemDiaHora() const{
    return diahora;
}
Clube* Jogo::obtemMandante() const{
    return mandante;
}
int Jogo::obtemGolsMandante() const{
    return golsMandante;
}
int Jogo::obtemGolsVisitante() const{
    return golsVisitante;
}
Clube* Jogo::obtemVisitante() const{
    return visitante;
}
Estadio* Jogo::obtemEstadio() const{
    return estadio;
}

void Jogo::defineNumero(int n){
    numero = n;
}
void Jogo::defineDiaHora(DiaEHora &dh){
    diahora = dh;
}
void Jogo::defineMandante(Clube *m){
    mandante = m;
}
void Jogo::defineGolsMandante(int gM){
    golsMandante = gM;
}
void Jogo::defineGolsVisitante(int gV){
    golsVisitante = gV;
}
void Jogo::defineVisitante(Clube *v){
    visitante = v;
}
void Jogo::defineEstadio(Estadio *e){
    estadio = e;
}

string Jogo::str() const{ 
    string res="";

    	if(estadio != nullptr){
    		res += "[" + estadio->obtemNome() + "-"+estadio->obtemCidade() + "/"+estadio->obtemEstado() + "]\n";
    	}
      else{
    		res += "[*]\n";
    	}
    	
    	string num = "";
    	if(numero < 10){
    		num = "00" + to_string(numero);
    	}
      else if(numero < 100){
    		num = "0" + to_string(numero);
    	}
      else{
    		num = to_string(numero);
    	}
    	
    	string gM="";
    	string gV="";
    	if(golsMandante == -1){
    		gM = "*";
    	}
      else{
    		gM = to_string(golsMandante);
    	}
    	
    	if(golsVisitante == -1){
    		gV = "*";
    	}
      else{
    		gV = to_string(golsVisitante);
    	}
    	
    	return num + " ["+ diahora.str() + "] " + mandante->obtemNome() + " " + gM + " x " + gV + " " + visitante->obtemNome() + " " + res;
}

bool Jogo::operator<(const Jogo &j) const{  
    return j.diahora<diahora;
}

ostream& operator<<(ostream& out,const Jogo &j){
    out << j.str();
    return out;
}
