#include "../include/Gerenciadores/gerenciadorColisao.hpp"

GerenciadorColisao::GerenciadorColisao(ListaEntidades *listaPersonagem, ListaEntidades *listaObstaculo) : listaPersonagem(listaPersonagem), listaObstaculo(listaObstaculo)
{
}

GerenciadorColisao::~GerenciadorColisao()
{
    if (listaPersonagem)
    {
        delete (listaPersonagem);
    }
    if (listaObstaculo)
    {
        delete (listaObstaculo);
    }
}

const sf::Vector2f GerenciadorColisao::calculaColisao(Entidade *ent1, Entidade *ent2)
{
    sf::Vector2f pos1 = ent1->getPos();
    sf::Vector2f pos2 = ent2->getPos();

    // Como solucionar o erro abaixo referente a não existÊncia de um getSize para intRect?
    const int tam1h = ent1->getSprite()->getTextureRect().height;
    const int tam1w = ent1->getSprite()->getTextureRect().width;
    const int tam2h = ent1->getSprite()->getTextureRect().height;
    const int tam2w = ent1->getSprite()->getTextureRect().width;

    sf::Vector2f distanciaEntreCentros(
        fabs((pos1.x + tam1h / 2.0f) - (pos2.x + tam1w / 2.0f)),
        fabs((pos1.y + tam2h / 2.0f) - (pos2.y + tam2w / 2.0f)));
    sf::Vector2f somaMetadeRectangulo(tam1h / 2.0f + tam2h / 2.0f, tam1w / 2.0f + tam2w / 2.0f);
    return sf::Vector2f(distanciaEntreCentros.x - somaMetadeRectangulo.x, distanciaEntreCentros.y - somaMetadeRectangulo.y);
}

void GerenciadorColisao::executar()
{
    for (int i = 0; i < listaPersonagem->getTamanho() - 1; i++)
    {
        Entidade *ent1 = listaPersonagem->operator[](i);
        for (int j = i + 1; j < listaPersonagem->getTamanho(); j++)
        {
            Entidade *ent2 = listaPersonagem->operator[](j);
            sf::Vector2f ds = calculaColisao(ent1, ent2);
            if (ds.x < 0.0f && ds.y < 0.0f)
            {
                ent1->colisao(ent2);
                ent2->colisao(ent1);
            }
        }
    }

    for (int i = 0; i < listaPersonagem->getTamanho(); i++)
    {
        Entidade *ent1 = listaPersonagem->operator[](i);
        for (int j = 0; j < listaObstaculo->getTamanho(); j++)
        {
            Entidade *ent2 = listaObstaculo->operator[](j);
            sf::Vector2f ds = calculaColisao(ent1, ent2);
            if (ds.x < 0.0f && ds.y < 0.0f)
            {
                if (ent2->getID() == Identidade::IDs::plataforma)
                {
                    ent2->colisao(ent1, ds);
                    ent1->colisao(ent2);
                }
                else if (ent2->getID() == Identidade::IDs::Rochas)
                {
                    ent2->colisao(ent1, ds);
                    ent1->colisao(ent2);
                }
                else if (ent2->getID() == Identidade::IDs::Arvore)
                {
                    ent2->colisao(ent1, ds);
                    ent1->colisao(ent2);
                }
            }
        }
    }
}
