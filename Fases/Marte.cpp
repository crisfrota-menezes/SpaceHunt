#include "Marte.hpp"

Marte::Marte() : Fase(Identidade::IDs::fase_Marte, Identidade::IDs::fundo_Marte){
}

Marte::~Marte()
{
}

void Marte::criarFundo()
{
    /*fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada1.png", 0.0f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada2.png", 0.0f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada3.png", 0.1f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada4.png", 0.2f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada5.png", 0.3f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada6.png", 0.5f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada7.png", 0.75f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada8.png", 1.5f);
    */
}

void Marte::criarMapa()
{
    std::ifstream arquivo;
    std::string linha;
    arquivo.open("C:/Users/rbben/Documents/Faculdade/2023-2/Tec_Prog/APS/SpaceHunt/Fases/mapa_Marte.txt");
    if (!arquivo.is_open())
    {
        std::cout << "Marte::nao foi possivel abrir o arquivo" << std::endl;
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

void Marte::executar(){
    
}