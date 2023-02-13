#include <string>
#include <vector>
#include "Aplicacao.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

#define MAX_CLUBES 20
#define MAX_ESTADIOS 30
#define MAX_JOGOS 380

using namespace std;

   void Aplicacao::ordenaJogos(){  
	  Jogo *aux = nullptr;
    DiaEHora *dh = nullptr;
    for(int i = 0; i < jogos.size(); i++){
      for(int j = 0; j < jogos.size(); j++){
        if(jogos[i]->obtemDiaHora().obtemAno() < jogos[i+1]->obtemDiaHora().obtemAno()){
          aux = jogos[i];
          jogos[i] = jogos[j];
          jogos[j] = aux;
        }
        if(jogos[i]->obtemDiaHora().obtemAno() == jogos[i+1]->obtemDiaHora().obtemAno()){
            if(jogos[i]->obtemDiaHora().obtemMes() < jogos[i+1]->obtemDiaHora().obtemMes()){
              aux = jogos[i];
              jogos[i] = jogos[j];
              jogos[j] = aux;
            }
        if(jogos[i]->obtemDiaHora().obtemMes() == jogos[i+1]->obtemDiaHora().obtemMes()){
            if(jogos[i]->obtemDiaHora().obtemDia() < jogos[i+1]->obtemDiaHora().obtemDia()){
              aux = jogos[i];
              jogos[i] = jogos[j];
              jogos[j] = aux;
            }
        if(jogos[i]->obtemDiaHora().obtemDia() == jogos[i+1]->obtemDiaHora().obtemDia()){
            if(jogos[i]->obtemDiaHora().obtemHoras() < jogos[i+1]->obtemDiaHora().obtemHoras()){
              aux = jogos[i];
              jogos[i] = jogos[j];
              jogos[j] = aux;
            }
        if(jogos[i]->obtemDiaHora().obtemHoras() == jogos[i+1]->obtemDiaHora().obtemHoras()){
            if(jogos[i]->obtemDiaHora().obtemMinutos() < jogos[i+1]->obtemDiaHora().obtemMinutos()){
              aux = jogos[i];
              jogos[i] = jogos[j];
              jogos[j] = aux;
            }
        }
        }
        }
        }
      }
    }
	}
   
    Equipe* Aplicacao::obtemEquipe(Clube *c){
      for(int i = 0; i < clubes.size(); i++){
 		    if(equipes[i]->obtemClube() == c){
 			    return equipes[i];
 		    }
 	    }
 	    return nullptr;
    }
    
    void Aplicacao::calculaClassificacao(){
    for (int i = 0; i < clubes.size()-1; i++)
    equipes[i]->limpa();
    for(int i=0;i<jogos.size();i++){
		if(jogos[i]->obtemGolsMandante()!=-1 || jogos[i]->obtemGolsVisitante()!=-1){
		obtemEquipe(jogos[i]->obtemMandante())->registraPartida(jogos[i]->obtemGolsMandante(),jogos[i]->obtemGolsVisitante());
		obtemEquipe(jogos[i]->obtemVisitante())->registraPartida(jogos[i]->obtemGolsVisitante(),jogos[i]->obtemGolsMandante());
		}
	}
}
    void Aplicacao::ordenaEquipes(){ 
	  Equipe *aux = nullptr;
    for(int i = 0; i < clubes.size(); i++){
      for(int j = 0; j < clubes.size(); j++){
        if(*equipes[j] < *equipes[i]){
          aux = equipes[i];
          equipes[i] = equipes[j];
          equipes[j] = aux;
        }
      }
    }
    }
    int Aplicacao::indiceEstadio(Estadio *e){
      for(int i = 0; i < estadios.size(); i++){ 
	 	    if(estadios[i] == e){
	 		    return i;
	 	    }
    	}
 		  return 0;
    }
    
    vector<string> Aplicacao::splitCSV(string linhaCSV, char separador){
      vector<string> res;
      string campo = "";
      for(int i = 0; i < linhaCSV.size(); i++){
        char c = linhaCSV.at(i);
        if(c == separador){
          res.push_back(campo);
          campo = "";
        }
        else
          campo.append(1,c);
      }
      res.push_back(campo);
      return res;
    } 
          
    Aplicacao::Aplicacao(){
      clubes.clear();
      estadios.clear();
      jogos.clear();
    }
    Aplicacao::~Aplicacao(){
      clubes.clear();
      estadios.clear();
      jogos.clear();
    }

    // CLUBES
    
    bool Aplicacao::leClubes(string arquivo){
      ifstream arq;
        arq.open(arquivo, ios::in);
        if(!arq.is_open())
            return false;
        for(int i = 0; i < MAX_CLUBES; i++){
            Clube *c = new Clube();
            arq >> *c;
            if(c->obtemNome() == ""){
                break;
            }
            clubes.push_back(c);
            Equipe *e = new Equipe(c);
            equipes.push_back(e);
        }
        arq.close();
        return true;
    }
    bool Aplicacao::leClubesCSV(string arquivo){ 
      ifstream arq(arquivo);
      string linha;
      if(!arq.is_open()){
        return false;
      }
      while(getline(arq, linha)){
        vector<string> clubeCSV = splitCSV(linha);
        Clube *c = new Clube();
        c->defineAbreviatura(clubeCSV[0]);
        c->defineNome(clubeCSV[1]);
        c->defineNomeCompleto(clubeCSV[2]);
        c->defineCidade(clubeCSV[3]);
        c->defineEstado(clubeCSV[4]);
        clubes.push_back(c);
        Equipe *e = new Equipe(c);
        equipes.push_back(e); 
      }
      arq.close();
      return true;
    }
    
    int Aplicacao::obtemNumClubes(){
      return clubes.size();
    }
    
    Clube* Aplicacao::obtemClube(string abrev){
      for(int i=0; i<clubes.size(); i++){
            if(clubes[i]->obtemAbreviatura() == abrev){
                return clubes[i];
            }
        }
        return nullptr;
    }
    
    void Aplicacao::mostraClubes(){
      stringstream ss;
        for (int i=0; i<clubes.size(); i++){
                ss << *clubes[i] << endl;
        }
        cout << "----- CLUBES -----" << endl;
        cout << ss.str();
        }

    // ESTADIOS

    bool Aplicacao::leEstadios(string arquivo){
     ifstream arq(arquivo);
        if(!arq.is_open())
            return false;
        for(int i = 0; i < MAX_ESTADIOS; i++){
            Estadio *e = new Estadio();
            arq >> *e;
            estadios.push_back(e);
        }
        arq.close();
        return true;
 		} 
    bool Aplicacao::leEstadiosCSV(string arquivo){ 
     ifstream arq(arquivo);
      string linha;
      if(!arq.is_open()){
        return false;
      }
      while(getline(arq, linha)){
        vector<string> estadioCSV = splitCSV(linha);
        Estadio *e = new Estadio();
        e->defineCodigo(stoi(estadioCSV[0]));
        e->defineNome(estadioCSV[1]);
        e->defineCidade(estadioCSV[2]);
        e->defineEstado(estadioCSV[3]);
        estadios.push_back(e);
      }
      arq.close();
      return true;
    }
    
    
    int Aplicacao::obtemNumEstadios(){
      return estadios.size();
    }
    
    Estadio* Aplicacao::obtemEstadio(int cod){
      for(int i=0; i<MAX_ESTADIOS; i++){
            if(estadios[i]->obtemCodigo() == cod){
                return estadios[i];
            }
        }
        return nullptr;
    }
    
    void Aplicacao::mostraEstadios()
    {
      cout << "----- ESTÁDIOS -----" << endl;
      for (int i = 0; i < estadios.size() && estadios[i]->obtemCodigo() != -1; i++)
      {
        cout << estadios[i]->str() << endl;
      }
    }

    //JOGOS

    bool Aplicacao::leJogos(string arquivo){  
 	  int cont = 0;
 	  int numero = 0;
    int golsMandante = 0;
	  int golsVisitante = 0;
	  DiaEHora diahora;
    string linha = "";
	  string dia = "", mes = "", ano = "";
	  string hora = "", mins = "";
	  Clube *mandante = new Clube();
    Clube *visitante = new Clube();
	  Estadio *estadio = new Estadio();
 	
 	  ifstream arq; 
 	  arq.open(arquivo);
 	
 	  if(!arq.is_open())
     return false; 
 	
 	  while(arq >> linha){ 
 		   cont++;
 		  if(cont == 1){
 		  	numero = stoi(linha); 
 		  }
      else if(cont == 2){  
 		 	  if(linha != "*"){
	 		 	  dia = string(1,linha[0]) + linha[1];
	 		 	  mes = string(1,linha[3]) + linha[4];
	 		 	  ano = string(1,linha[6]) + string(1,linha[7]) + linha[8] + linha[9]; 
	 		 	  diahora.defineDia(stoi(dia));
	 		 	  diahora.defineMes(stoi(mes));
	 		 	  diahora.defineAno(stoi(ano));
 		 	  }
        else{
 		 		  diahora.defineDia(-1);
 		 		  diahora.defineMes(-1);
 		 		  diahora.defineAno(-1);
 		 	  } 
 		  }
       else if(cont == 3){
 		 	  if(linha != "*"){
	 		 	  hora = string(1,linha[0])+linha[1];
	 		 	  mins = string(1,linha[3])+linha[4];
	 		 	  diahora.defineHoras(stoi(hora));
	 		 	  diahora.defineMinutos(stoi(mins));
 		 	  }
        else{
 		 		  diahora.defineHoras(-1);
 		 		  diahora.defineMinutos(-1); 
 		 	  }
 		    }
         else if(cont == 4){
 		 	  mandante = obtemClube(linha);
 		    }
        else if(cont == 5){
 		 	  if(linha != "*"){ 
 		 		  golsMandante = stoi(linha);
 		 	  }
        else{
 		 		  golsMandante = -1;
 		 	  }

 		    } 
        else if(cont == 6){
 		 	  if(linha != "*"){
          golsVisitante = stoi(linha);
          }
        else{
 		 		  golsVisitante = -1;
 		 	  }
 		    }
        else if(cont == 7){
 		 	  visitante = obtemClube(linha);
 		  }
        else if(cont == 8){
 		 	  if(linha != "*"){
 		 		  estadio = obtemEstadio(stoi(linha));
 		 	  }
        else{
 		 		  estadio = nullptr;
 		 	  }   
 		 	  cont = 0;
        Jogo *j = new Jogo(numero,diahora,mandante,golsMandante,golsVisitante,visitante,estadio);
 		 	  jogos.push_back(j);  
 		 }
 	  }  
 	  return true; 
 	} 
 	  

    bool Aplicacao::leJogosCSV(string arquivo){
      fstream arq;
      int i, j, cod;
      string codigo,linha; 
      string data, dia, mes, ano, horas, min;
      string mandante,visitante;
      int golsM,golsV;
      int codigoEstadio;
      arq.open(arquivo, ios::in);
      if(!arq.is_open())
        return false; 
      
      while(getline(arq,linha)){
      	vector<string> line= splitCSV(linha,';');
      	cod = stoi(line[0]);
      	data = line[1];
      	DiaEHora diahora;
      	if(data.size()>3){ 
	 	      dia = string(1,data[0]) + data[1];
	 	      mes = string(1,data[3]) + data[4];
	 	      ano = string(1,data[6]) + string(1,data[7]) + data[8] + data[9]; 
	 	      horas = string(1,data[11]) + data[12];
	 	      min = string(1,data[14]) + data[15]; 
	 	      diahora.defineDia(stoi(dia));
	 	      diahora.defineMes(stoi(mes));
	 	      diahora.defineAno(stoi(ano));
	 	      diahora.defineHorario(stoi(horas),stoi(min));
 	      } 	 
      	mandante = line[2]; 
      	if(line[3] == "*"){
      		golsM = -1;
      	}
        else{
      		golsM = stoi(line[3]);
      	}
      	 
      	if(line[4] == "*"){
      		golsV = -1;
      	}
        else{
      		golsV = stoi(line[4]);
      	}
      	
      	visitante = line[5];
      	codigoEstadio = stoi(line[6]);
      	jogos.push_back(new Jogo(cod,diahora,obtemClube(mandante),golsM,golsV,obtemClube(visitante),obtemEstadio(codigoEstadio)));
      }
      arq.close();
      return true;
    }
      

    void Aplicacao::mostraJogos(){  
        cout << "----- JOGOS -----" << endl;
        for (int i = 0; i < jogos.size(); i++){
            cout << jogos[i]->str();
        }
    }

    //RESTO
    
   void Aplicacao::mostraClassificacao()
   {
    calculaClassificacao();
    ordenaEquipes();
    stringstream ss;

    ss << "----- TABELA DO CAMPEONATO BRASILEIRO DE FUTEBOL 2021" << endl;
    ss << " N. Clube                 Pt  Jg  Vi  Em  De  GP  GC  GS  Aprov" << endl;
    for(int i = 0; i < clubes.size(); i++){
    ss << setfill(' ') << setw(2) << right << i+1 << ". ";
    ss << equipes[i]->str();
    ss << endl;
    }
    cout << ss.str();
    }
    
void Aplicacao::mostraPartidasPorEstadio(){
    cout << "----- ESTÁDIOS / JOGOS REALIZADOS -----" << endl;    
    Estadio *est = nullptr;

    int jogoPorEstadio[estadios.size()];
    
    for(int i = 0; i < estadios.size() && estadios[i]->obtemCodigo() != -1; i++){
      jogoPorEstadio[i]=0;
    }
  
    for(int i = 0; i < estadios.size() && estadios[i]->obtemCodigo() != -1;i++){
      for(int j = 0; j < MAX_JOGOS; j++){
         if(jogos[j]->obtemEstadio() != nullptr && jogos[j]->obtemGolsMandante() != -1){   
            if(estadios[i]->obtemNome() == jogos[j]->obtemEstadio()->obtemNome()){   
              jogoPorEstadio[i]++; 
            } 
          } 
      }   
    }
    for(int i = 0; i < estadios.size() && estadios[i]->obtemCodigo() != -1;i++){
      cout << estadios[i]->obtemNome() << " ("<<estadios[i]->obtemCidade() << "/"<<estadios[i]->obtemEstado() << "): " << jogoPorEstadio[i] << endl;
    }
}