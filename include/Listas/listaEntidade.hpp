#pragma once

#include "../Entidades/entidade.hpp"
#include "Lista.hpp"

namespace SpaceHunt
{
    namespace Listas
    {
        class ListaEntidades
        {
        private:
            Lista<Entidade> lista;

        public:
            ListaEntidades();
            ~ListaEntidades();

            void inserir(Entidade *ent);
            void remover(int pos);
            void remover(Entidade *ent);
            Entidade* operator[](int pos);
            void inicializar();
            void executar();
            void limpar();
            const int getTamanho() const;
        };
    }
    using namespace Listas;
}
using namespace SpaceHunt;