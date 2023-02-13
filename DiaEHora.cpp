#include <iostream>
#include <string>
#include <sstream>
#include "DiaEHora.hpp"

DiaEHora::DiaEHora(int d, int m, int a, int h, int mn){
    dia = d;
    mes = m;
    ano = a;
    horas = h;
    minutos = mn;
}
DiaEHora::DiaEHora(int d, int m, int a){
    dia = d;
    mes = m;
    ano = a;
}
DiaEHora::DiaEHora(){
    dia = -1;
    mes = -1;
    ano = -1;
    horas = -1; 
    minutos = -1; 
}

DiaEHora::~DiaEHora(){
}

unsigned DiaEHora::obtemDia() const{
    return dia;
}
unsigned DiaEHora::obtemMes() const{
    return mes;
}
unsigned DiaEHora::obtemAno() const{
    return ano;
}
unsigned DiaEHora::obtemHoras() const{
    return horas;
}
unsigned DiaEHora::obtemMinutos() const{
    return minutos;
}

void DiaEHora::defineDia(int d){
    dia = d;
}
void DiaEHora::defineMes(int m){
    mes = m;
}
void DiaEHora::defineAno(int a){
    ano = a;
}
void DiaEHora::defineData(int d, int m, int a){
    dia = d;
    mes = m;
    ano = a;
}
void DiaEHora::defineHoras(int h){
    horas = h;
}
void DiaEHora::defineMinutos(int mn){
    minutos = mn;
}
void DiaEHora::defineHorario(int h, int mn){
    horas = h;
    minutos = mn;
}

string DiaEHora::str() const{
    string d = "";
    string m = "";
    string h = "";
    string mn="";
    string a="";

    if(dia > 0 && dia < 10){
    	d = "0" + to_string(dia);
    }
    else{
    	d = to_string(dia);
    } 
    	
    if(mes > 0 && mes < 10){
    	m = "0" + to_string(mes);
    }
    else{
    	m = to_string(mes);
    } 
  
  	if(horas > 0 && horas < 10){
  		h = "0" + to_string(horas);
  	}
    else{
  		h = to_string(horas);
  	} 
  	
  	if(minutos >= 0 && minutos < 10){
  		mn = "0" + to_string(minutos);
  	}
    else if(minutos > 10){
  		mn = to_string(minutos);
  	} 
  	 
  	a = to_string(ano); 
    	
    string data = "";
    string horario = "";

    if(dia < 0 || mes < 0 || ano < 0){
    	data = "*";
    }
    else{
    	data = d + "/" + m + "/" + a;
    }
    	
    if(horas<0 || minutos<0){
    	horario = "*";
    }
    else{
    	horario = h + ":" + mn;
    }
    return data + " " + horario;
}

bool DiaEHora::operator<(const DiaEHora &dh) const{  
    if(ano < dh.obtemAno())
     return true;
    if(ano == dh.obtemAno()){
      if(mes < dh.obtemMes())
        return true;
        if(mes == dh.obtemMes()){
          if(dia < dh.obtemDia())
          return true;
          if(dia == dh.obtemDia()){
            if(horas < dh.obtemHoras())
            return true;
              if(horas == dh.obtemHoras()){
                if(minutos < dh.obtemMinutos())
                return true;
              }
          }
        }
    }
    return false;
}
bool DiaEHora::operator>(const DiaEHora &dh) const{
    if(ano > dh.ano){
    	return true;
  	}
    else if(mes > dh.mes && ano == dh.ano){
    	return true;
    }
    else if(dia > dh.dia && mes == dh.mes && ano == dh.ano){
    	return true;
    }
    else if(horas > dh.horas && dia == dh.dia && mes == dh.mes && ano == dh.ano ){
  		return true;  	
    }
    else if(minutos > dh.minutos && horas == dh.horas && dia == dh.dia && mes==dh.mes && ano == dh.ano){
    	return true;
  	}
  	return false;
}

bool DiaEHora::operator<=(const DiaEHora &dh) const{ 
    if(ano <= dh.ano){
    		return true;
    }
  	else if(mes <= dh.mes && ano == dh.ano){
    		return true;
    }
    else if(dia <= dh.dia && mes == dh.mes && ano == dh.ano){
    	return true;
    }
    else if(horas <= dh.horas && dia == dh.dia && mes==dh.mes && ano == dh.ano ){
    	return true;	
    }
    else if(minutos <= dh.minutos && horas == dh.horas && dia == dh.dia && mes == dh.mes && ano == dh.ano){
  		return true;
    }
    return false; 
}
bool DiaEHora::operator>=(const DiaEHora &dh) const{ 
    if(ano >= dh.ano){
    		return true;
    }
  	else if(mes >= dh.mes && ano == dh.ano){
  		return true;
  	}
    else if(dia >= dh.dia && mes == dh.mes && ano == dh.ano){
    	return true;
    }
    else if(horas >= dh.horas && dia == dh.dia && mes == dh.mes && ano == dh.ano ){
    	return true;	
    }
    else if(minutos >= dh.minutos && horas == dh.horas && dia == dh.dia && mes==dh.mes && ano == dh.ano){
   		return true;
   	}
  	return false;
}
bool DiaEHora::operator==(const DiaEHora &dh) const{
    return (dia == dh.dia) && (mes == dh.mes) && (ano == dh.ano) && (horas == dh.horas) && (minutos==dh.minutos);
  }

bool DiaEHora::operator!=(const DiaEHora &dh) const{ 
    return (dia != dh.dia) && (mes != dh.mes) && (ano != dh.ano) && (horas != dh.horas) && (minutos!=dh.minutos);
}

istream& operator>>(istream& in,DiaEHora &dh){
    int campo = 0;
    int i;
    string c;
    string dado = "";
    string aux;
    in >> aux;

    if(aux == "" || !in.good()){
      return in;
    }

    for(i = 0; i < aux.length(); i++){
      c = aux.at(i);
      if((c == "/") || (c == " ") || (c == ";")){
        switch(campo){
          case 0:
            dh.dia = stoi(dado);
            dado = "";
            break;
          case 1:
            dh.mes = stoi(dado);
            dado = "";
            break;
          case 2:
            dh.ano = stoi(dado);
            dado = "";
            break;
          case 3:
            dh.horas = stoi(dado);
            dado = "";
            break;
          case 4:
            dh.minutos = stoi(dado);
            dado = "";
            break;
          default:
            break;
        }
        campo++;
      }
      else dado.append(c);
    }
  return in;
}


ostream& operator<<(ostream& out,const DiaEHora &dh){
    out << dh.str();
    return out;
}