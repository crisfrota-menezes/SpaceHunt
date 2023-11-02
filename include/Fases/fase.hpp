#pragma once

#include "../Animacao/fundo.hpp"

//Personagens
#include "../Entidades/jogador.hpp"
#include "../Entidades/uraniano.hpp"
#include "../Entidades/verme.hpp"
#include "../Entidades/venusiano.hpp"
#include "../Entidades/projetil.hpp"

//Obstaculos
#include "../Entidades/arvore.hpp"
#include "../Entidades/rochas.hpp"
#include "../Entidades/plataforma.hpp"

//Gerenciadores
#include "../Gerenciadores/GerenciadorColisao.hpp"
#include "../Gerenciadores/GerenciadorEvento.hpp"

//Listas
#include "../Listas/listaEntidade.hpp"

#include <fstream>

namespace SpaceHunt {

    namespace Fases {

        class Fase : public Ente 
        {
        protected:
            ListaEntidades listaPersonagens;
            ListaEntidades listaObstaculos;
            GerenciadorColisao* pColisao;
           // Fundo fundo;
            
        public:
            Fase(const Identidade::IDs ID_Fase = Identidade::IDs::vazio, const Identidade::IDs ID_Fundo = Identidade::IDs::vazio);
            ~Fase();
            void criaUraniano(const sf::Vector2f pos);
            void criaVerme(const sf::Vector2f pos);
            void criaVenusiano(const sf::Vector2f pos);
            void criarJogador(const sf::Vector2f pos);
            void criarPlataforma(const sf::Vector2f pos);
            void criarArvore(const sf::Vector2f pos);
            void criarRochas(const sf::Vector2f pos);
            void criarProjetil(const sf::Vector2f pos);
            virtual void criarMapa() = 0;
            void criarEntidade(char letra, const sf::Vector2i pos);        
            virtual void executar() = 0;
            virtual void criarFundo() = 0;
        };
    }
    using namespace Fases;
}
using namespace SpaceHunt;