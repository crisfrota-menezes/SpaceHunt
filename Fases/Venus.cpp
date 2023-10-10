#include "Venus.hpp"

Venus::Venus() : Fase(Identidade::IDs::fase_Venus, Identidade::IDs::fundo_Venus)
{
}

Venus::~Venus()
{
}

void Venus::criarFundo()
{
    fundo.addCamada("C:/Users/crisn/Downloads/jogo_cristiano_frota_S73/SpaceHunt/Midia/camadaN1.jpg", 0.0f);
    fundo.addCamada("C:/Users/crisn/Downloads/jogo_cristiano_frota_S73/SpaceHunt/Midia/camadaN2.png", 0.1f);
    fundo.addCamada("C:/Users/crisn/Downloads/jogo_cristiano_frota_S73/SpaceHunt/Midia/camadaN3.png", 0.2f);
    fundo.addCamada("C:/Users/crisn/Downloads/jogo_cristiano_frota_S73/SpaceHunt/Midia/camadaN4.png", 0.3f);
    fundo.addCamada("C:/Users/crisn/Downloads/jogo_cristiano_frota_S73/SpaceHunt/Midia/camadaN5.png", 0.4f);
    fundo.addCamada("C:/Users/crisn/Downloads/jogo_cristiano_frota_S73/SpaceHunt/Midia/camadaN6.png", 0.5f);
    fundo.addCamada("C:/Users/crisn/Downloads/jogo_cristiano_frota_S73/SpaceHunt/Midia/camadaN7.png", 0.6f);
    fundo.addCamada("C:/Users/crisn/Downloads/jogo_cristiano_frota_S73/SpaceHunt/Midia/camadaN8.png", 0.7f);
}

void Venus::criarMapa()
{
    std::ifstream arquivo;
    std::string linha;
    arquivo.open("Fases/mapa_Venus.txt");
    if (!arquivo.is_open())
    {
        std::cout << "Venus::nao foi possivel abrir o arquivo" << std::endl;
        exit(1);
    }
    int j = 0;
    while (std::getline(arquivo, linha))
    {
        for (int i = 0; i < linha.size(); i++)
        {
            if (linha[i] != ' ')
            {
                criarEntidade(linha[i], sf::Vector2i(i, j));
            }
        }
        j++;
    }
    arquivo.close();
}