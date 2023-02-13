// DiaEHora.hpp (Roland Teodorowitsch; 21 set. 2021)

#ifndef _DIAEHORA_HPP
#define _DIAEHORA_HPP

#include <string>

using namespace std;

class DiaEHora {
private:
    int dia, mes, ano;
    int horas, minutos;
public:
    DiaEHora(int d, int m, int a, int h, int mn);
    DiaEHora(int d, int m, int a);
    DiaEHora();
    ~DiaEHora();
    
    unsigned obtemDia() const;
    unsigned obtemMes() const;
    unsigned obtemAno() const;
    unsigned obtemHoras() const;
    unsigned obtemMinutos() const;

    void defineDia(int d);
    void defineMes(int m);
    void defineAno(int a);
    void defineData(int d, int m, int a);
    void defineHoras(int h);
    void defineMinutos(int mn);
    void defineHorario(int h, int mn);

    string str() const;

    bool operator<(const DiaEHora &dh) const;
    bool operator>(const DiaEHora &dh) const;
    bool operator==(const DiaEHora &dh) const;
    bool operator<=(const DiaEHora &dh) const;
    bool operator>=(const DiaEHora &dh) const;
    bool operator!=(const DiaEHora &dh) const;
    
    friend istream& operator>>(istream& in,DiaEHora &dh);
    friend ostream& operator<<(ostream& out,const DiaEHora &dh);
};

#endif
