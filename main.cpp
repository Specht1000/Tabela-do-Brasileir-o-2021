// appCSV.cpp (Roland Teodorowitsch; 11 nov. 2021)

#include <iostream>
#include "Aplicacao.hpp"

int main() {
    Aplicacao app;

    if (!app.leClubesCSV("2021-clubes.csv"))
        return 1;
    app.mostraClubes();
    cout << endl;

    if (!app.leEstadiosCSV("2021-estadios.csv"))
        return 1;
    app.mostraEstadios();
    cout << endl;

    if (!app.leJogosCSV("2021-jogos.csv"))
        return 1;
    app.mostraJogos();
    cout << endl;

    app.mostraClassificacao();
    cout << endl;

    app.mostraPartidasPorEstadio();
    cout << endl;
    
    return 0;
}
