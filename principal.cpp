#include "principal.hpp"

Jogo::Jogo() : pGrafico(pGrafico->getGerenciadorGrafico()),pEvento(pEvento->getGerenciadorEvento()), Teste(),Fase_Marte()
{

    Teste.setGGrafico(pGrafico);
    if (pGrafico == nullptr)
    {
        cout << "Erro ao criar o gerenciador grafico" << endl;
        exit(1);
    }

    if (pEvento == nullptr)
    {
        cout << "Erro ao criar o gerenciador de eventos" << endl;
         exit(1);
    }
 
   // criarFase();
    Teste.inicializar();
    run();
}

Jogo::~Jogo(){

}


void Jogo::run()
{

    while (pGrafico->janelaAberta())
    {
       pEvento->executar();
       pGrafico->limpar();
       Fase_Marte.executar();
       Teste.executar();
       pGrafico->mostraElementos();
    }
}
