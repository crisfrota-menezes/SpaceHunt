#pragma once

//Classe Base
#include "../ente.hpp"

#include "../Parallax/fundo.hpp"

//Personagens
#include "../Entidades/Personagens/inimigo.hpp"
#include "../Entidades/Personagens/personagem.hpp"
#include "../Entidades/Personagens/jogador.hpp"
#include "../Entidades/Personagens/uraniano.hpp"
#include "../Entidades/Personagens/verme.hpp"
#include "../Entidades/Personagens/venusiano.hpp"
#include "../Entidades/projetil.hpp"

//Obstaculos
#include "../Entidades/Obstaculo/arvore.hpp"
#include "../Entidades/Obstaculo/rochas.hpp"
#include "../Entidades/Obstaculo/plataforma.hpp"

//Gerenciadores
#include "../Gerenciadores/GerenciadorColisao.hpp"
#include "../Gerenciadores/GerenciadorEvento.hpp"

//Listas
#include "../Listas/listaEntidade.hpp"

#include <fstream>

namespace SpaceHunt {

    namespace Fases {

        class Fase : public Ente {
        protected:
            ListaEntidades listaPersonagens;
            ListaEntidades listaObstaculos;
            GerenciadorColisao* pColisao;
            Fundo fundo;
            
        public:
            Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo);
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
            void executar();
            void desenhar();
            virtual void criarFundo() = 0;
        };
    }
    using namespace Fases;
}
using namespace SpaceHunt;