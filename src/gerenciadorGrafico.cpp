#include "../include/Gerenciadores/gerenciadorGrafico.hpp"

GerenciadorGrafico *GerenciadorGrafico::pGrafico = nullptr;

GerenciadorGrafico::GerenciadorGrafico() : window(new sf::RenderWindow(sf::VideoMode(LARGURA_TELA, ALTURA_TELA), "Space Hunt")), camera(sf::Vector2f(LARGURA_TELA / 2.0f, ALTURA_TELA / 2.0f), sf::Vector2f(LARGURA_TELA, ALTURA_TELA))
{
    CarregarImagens();
    if (window == nullptr)
    {
        cout << "Erro ao criar janela" << endl;
        exit(1);
    }
}

GerenciadorGrafico::~GerenciadorGrafico()
{
    if (window)
    {
        delete window;
        window = nullptr;
    }
}

GerenciadorGrafico *GerenciadorGrafico::getGerenciadorGrafico()
{
    if (pGrafico == nullptr)
    {
        pGrafico = new GerenciadorGrafico();
        return pGrafico;
    }
    else
    {
        return pGrafico;
    }
}

sf::RenderWindow *GerenciadorGrafico::getWindow()
{
    return window;
}

void GerenciadorGrafico::limpar()
{
    window->clear();
}

void GerenciadorGrafico::desenhaElemento(sf::Sprite corpo)
{
    window->draw(corpo);
}

void GerenciadorGrafico::mostraElementos()
{
    window->display();
}

void GerenciadorGrafico::desenhaTexto(sf::Text texto)
{
    texto.setCharacterSize(50);
    texto.setFillColor(sf::Color::Blue);
    texto.setPosition(100.0f, 100.0f);
    window->draw(texto);
}

void GerenciadorGrafico::mostraTextos()
{
    window->display();
}

void GerenciadorGrafico::setFonte(sf::Text &texto, sf::Font &fonte)
{
    fonte.loadFromFile("C:/Users/crisn/Downloads/jogo_cristiano_frota_S73/SpaceHunt/Midia/PressStart2P-Regular.ttf");
    texto.setFont(fonte);
}

void GerenciadorGrafico::fechaJanela()
{
    window->close();
}

const bool GerenciadorGrafico::janelaAberta()
{
    return window->isOpen();
}

void GerenciadorGrafico::atualizarCamera(const sf::Vector2f posJogador)
{
    camera.setCenter(posJogador.x, 540.0f);

    window->setView(camera);
}

const sf::View GerenciadorGrafico::getCamera()
{
    return camera;
}

const sf::Image GerenciadorGrafico::CarregaTextura(Identidade::IDs iden)
{

    switch (iden)
    {
    case Identidade::IDs::jogador:
        return Jogador;
        break;
    case Identidade::IDs::Arvore:
        return Arvore;
        break;
    case Identidade::IDs::plataforma:
        return Plataforma;
        break;
    case Identidade::IDs::Verme:
        return Verme;
        break;
    case Identidade::IDs::Venusiano:
        return Venusiano;
        break;
    case Identidade::IDs::Uraniano:
        return Uraniano;
        break;
    case Identidade::IDs::Rochas:
        return Rocha;
        break;
    case Identidade::IDs::Projetil:
        return Projetil;
        break;
    case Identidade::IDs::Menu:
        return Menu;
        break;
    default:
        cout << "Identificador invalido" << endl;
        break;
    }
}

void Gerenciadores::GerenciadorGrafico::CarregarImagens()
{
    Jogador.loadFromFile("C:/Users/crisn/Downloads/jogo_cristiano_frota_S73/SpaceHunt/Midia/AndaJ.png");
    Arvore.loadFromFile("C:/Users/rbben/Documents/Faculdade/2023-2/Tec_Prog/APS/SpaceHunt/Midia/arvore.png");
    Plataforma.loadFromFile("C:/Users/rbben/Documents/Faculdade/2023-2/Tec_Prog/APS/SpaceHunt/Midia/plataforma.png");
    Verme.loadFromFile("C:/Users/rbben/Documents/Faculdade/2023-2/Tec_Prog/APS/SpaceHunt/Midia/ParadoA1.png");
    Venusiano.loadFromFile("C:/Users/rbben/Documents/Faculdade/2023-2/Tec_Prog/APS/SpaceHunt/Midia/ParadoA2.png");
    Uraniano.loadFromFile("C:/Users/rbben/Documents/Faculdade/2023-2/Tec_Prog/APS/SpaceHunt/Midia/ParadoA3.png");
    Rocha.loadFromFile("C:/Users/rbben/Documents/Faculdade/2023-2/Tec_Prog/APS/SpaceHunt/Midia/Rochas.png");
    Menu.loadFromFile("C:/Users/crisn/Downloads/jogo_cristiano_frota_S73/SpaceHunt/Midia/background.jpg");
}