#include "Cartas.h"

//ok
//Vai para a posiçao x(horizontal) e y(vertical) no terminal sendo o canto superior esquerdo o ponto 0,0
void gotoxy(int x,int y)
{
    printf("\033[%d;%dH",y+1,x+1);
}

//ok
//Verifica quais dos pontos (x1 ou x2, y1 ou y2) são maiores e deleta(preenche com ' ') a partir do menor ate o maior
void DeletaIntervalo(int x1, int y1, int x2, int y2)
{
    int i, j;

    if (x1 > x2)
    {
        if (y1 > y2)
        {
            for (i=y2; i<=y1; i++)
            {
                for (j=x2; j<=x1; j++)
                {
                    gotoxy(j, i);
                    printf(" ");
                }
            }
        } 
        
        else
        {
            for (i=y1; i<=y2; i++)
            {
                for (j=x2; j<=x1; j++)
                {
                    gotoxy(j, i);
                    printf(" ");
                }
            }
        }
    } 
    
    else if (y1 > y2)
    {
        for (i=y2; i<=y1; i++)
        {
            for (j=x1; j<=x2; j++)
            {
                gotoxy(j, i);
                printf(" ");
            }
        }
    } 
    
    else
    {
        gotoxy(x1, y1);

        for (i=y1; i<=y2; i++)
        {
            for (j=x1; j<=x2; j++)
            {
                gotoxy(j, i);
                printf(" ");
            }
        }
    }
}

//ok
//Deleta um caracter na posição x, y
void DeletaCaracter(int x, int y)
{
    gotoxy(x, y);
    printf(" ");
}

//ok
//Deleta uma linha y a partir do maior x ate alcançar o outro
void DeletaLinha(int x, int y, int x1)
{
    int i;

    if (x>x1)
    {
        for(i = x1; i<=x; i++)
        {
            DeletaCaracter(i, y);
        }
    } 

    else
    {
        for(i = x; i<=x1; i++)
        {
            DeletaCaracter(i, y);
        }
    }  
}

//***********************************************************FUNÇÕES FOCADAS NAS CARTAS ***************************************************************************//

//*************************FUNÇOES DE PRINTAR CARTAS ********************************//

//ok
//Printa o verso da carta tanto no sentido horizontal quanto no vertical a partir da posição x, y
void PrintVerso( char sentido, int x, int y)
{
    int i, j, topo, lado;

    gotoxy(x, y);

    switch (sentido)
    {
        case 'v':
            topo = 10;
            lado = 6;
            break;
        
        case 'h':
            topo = 14;
            lado = 4;
            break;
    }

    gotoxy(x, y);
    printf("\u250C");//Quina esquerda superior

    for( i = 0; i < topo; i++)
    {
        printf("\u2500");//Meio
    }

    printf("\u2510\n");//Quina direita superior
    gotoxy(x, y+1);

    for(j = 0; j < lado; j++)
    {
        printf("\u2502");//Lado

        for( i = 0; i < topo; i++)
        {
            printf("\u28FF");//Verso
        }

        printf("\u2502\n");//Lado
        gotoxy(x, y+2+j);
    }

    printf("\u2514");//Quina esquerda baixo

    for( i = 0; i < topo; i++)
    {
        printf("\u2500");//Meio
    }

    printf("\u2518\n");//Quina direita baixo
}

//ok
//Printa a carta de frente no sentido vertical a partir da posição x, y 
void PrintCartaFrente(TipoCarta Carta ,int x, int y)
{
    int i, j;
    gotoxy(x, y);
    printf("\u250C");//Quina esquerda superior

    for( i = 0; i < 10; i++)
    {
        printf("\u2500");//Meio
    }

    printf("\u2510\n");//Quina direita superior
    gotoxy(x, y+1);

    for(j = 0; j < 6; j++)
    {
        printf("\u2502");//Lado
        switch (j)
        {
            case 0:
                printf(" %c", Carta.id);
                for( i = 0; i < 8; i++)
                {
                    printf(" ");
                }
                break;

            case 1:
                switch (Carta.naipe){                  
                    case 'e':
                        printf(" \u2660");//Espada
                        for( i = 0; i < 8; i++)
                        {
                            printf(" ");
                        }
                        break;
                
                    case 'p':
                        printf(" \u2663");//Paus
                        for( i = 0; i < 8; i++)
                        {
                            printf(" ");
                        }
                        break;

                    case 'o':
                        printf(" \u2662");//Ouro
                        for( i = 0; i < 8; i++)
                        {
                            printf(" ");
                        }
                        break;

                    case 'c':
                        printf(" \u2661");//Copas
                        for( i = 0; i < 8; i++)
                        {
                            printf(" ");
                        }
                        break;
                }
                break;

            case 4:
                switch (Carta.naipe){                   
                    case 'e':
                        for( i = 0; i < 8; i++)
                        {
                            printf(" ");
                        }
                        printf("\u2660 ");//Espada
                        break;
                
                    case 'p':
                        for( i = 0; i < 8; i++)
                        {
                            printf(" ");
                        }
                        printf("\u2663 ");//Paus
                        break;

                    case 'o':
                        for( i = 0; i < 8; i++)
                        {
                            printf(" ");
                        }
                        printf("\u2662 ");//Ouro
                        break;

                    case 'c':
                        for( i = 0; i < 8; i++)
                        {
                            printf(" ");
                        }
                        printf("\u2661 ");//Copas
                        break;
                }
                break;

            case 5:
                for( i = 0; i < 8; i++)
                {
                    printf(" ");
                }
                printf("%c ", Carta.id);
                break;
        
            default:
                for( i = 0; i < 10; i++)
                {
                    printf(" ");
                }
                break;
        }
        printf("\u2502\n");//Lado
        gotoxy(x, y+2+j);
    }

    printf("\u2514");//Quina esquerda baixo

    for( i = 0; i < 10; i++)
    {
        printf("\u2500");//Meio
    }

    printf("\u2518\n");//Quina direita baixo
}

//*************************FUNÇOES BARALHO*******************************************//

//ok
//Printa as cartas do baralho usando a funçao PrintCartaFrente, sendo que a primeira carta é printada na posição x, y
void MostrarBaralho(int x, int y, TipoBaralho Baralho)
{
    int i = 0;
    TipoApontador aux;
    gotoxy(x-8, y+3);
    printf("Comeco!");
    
    for(aux = Baralho.Primeiro; aux -> Prox != NULL; aux = aux->Prox)
    {
        if (i<20)
        {
            PrintCartaFrente(aux -> Carta, x+5*i, y);
        }
        
        else
        {
            PrintCartaFrente(aux -> Carta, x+5*i-100, y+9);
        }

        i++;
    }

    gotoxy(x+5*i-92, y+12);
    printf("Fim!");
}

//ok
//Imprime as cartas do baralho na forma id: %c, naipe: %c, para ser usado quando o modo debug esta ativado
void imprimeBaralho (TipoBaralho Baralho, int x, int y){
    //Declaração de auxiliar para percorrer o baralho
    TipoApontador p;
    int i = 0;

    for (p = Baralho.Primeiro; p -> Prox != NULL; p = p -> Prox)
    {
        gotoxy(x, y + i);
        printf ("id: %c, naipe: %c\n", p -> Carta.id, p -> Carta.naipe);
        i++;
    }
}

//ok
//Faz um baralho vazio
void FLVazia(TipoBaralho *Baralho)
{
    Baralho -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Baralho -> Ultimo = Baralho -> Primeiro;
    Baralho -> Primeiro -> Prox = NULL;
}

//ok
//Verifica se o baralho é vazio
int Vazia(TipoBaralho Baralho)
{
    return (Baralho.Primeiro == Baralho.Ultimo);
}

//ok
//Insere uma carta na ultima posição do baralho
void InsereBaralho(TipoCarta x, TipoBaralho *Baralho)
{
    Baralho -> Ultimo -> Carta = x;
    Baralho -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Baralho -> Ultimo = Baralho -> Ultimo -> Prox;   
    Baralho -> Ultimo -> Prox = NULL; 
}

//ok
//Cria um baralho ordenado usando a função InsereBaralho
void criaBaralho (TipoBaralho *Baralho)
{
    //Fazendo o Baralho vazio
    FLVazia(Baralho);

    //Variável usada para o switch, visando atribuir as características às cartas
    int i;

    //Variável usada para percorrer a lista de naipes, avançando a cada 10 cartas para inserir o naipe correspondente
    int posNaipes;

    //Vetores contendo os naipes, ids e valores das cartas
    char naipes[] = {'o', 'e', 'c', 'p'};
    char id[] = {'2', '3', '4', '5', '6', 'J', 'Q', 'K', '7', 'A'};
    int valores[] = { 0, 0, 0, 0, 0, 2, 3, 4, 10, 11};
    int posicao[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Criando TipoCarta auxiliar, para atribuir as cartas à lista
    TipoCarta aux;

    for (posNaipes = 0; posNaipes<4; posNaipes++)
    {
        for (i = 0; i < 10; i++)
        {
            aux.id = id[i];
            aux.naipe = naipes[posNaipes];
            aux.valor = valores[i];
            aux.posicao = posicao[i];
            InsereBaralho( aux, Baralho);
        }
    } 
}

//ok
//Retira uma carta da posição "posicao" do baralho, retorna tal carta e da free na original do baralho
TipoCarta retiraBaralho (TipoBaralho *Baralho, int posicao){
    //Declaração de variáveis auxiliares para percorrer e realizar substituições na lista encadeada
    int i = 0;
    TipoApontador p, aux;
    TipoCarta CartaAux;
    //Quando se deseja retirar a primeira Carta
    if (posicao == 0)
    {
        aux = Baralho -> Primeiro;
        Baralho -> Primeiro = aux -> Prox;
        CartaAux = aux -> Carta;
        free (aux);
        return (CartaAux);
    }

    else
    {
        //Retirando as Cartas das demais posições
        for (p = Baralho -> Primeiro; p -> Prox != NULL; p = p -> Prox)
        {
            if (posicao == i + 1)
            {
                aux = p -> Prox;
                CartaAux = aux -> Carta;
                p -> Prox = aux -> Prox;
                free (aux);
                return (CartaAux);
            }
            
            //Incrementando o valor de i para encontrar a posição desejada
            i++;
        }
    }  
}


//Da free no baralho todo, para usar apos o fim do jogo
void freeBaralho (TipoBaralho *Baralho)
{
    //Declaração de auxiliares para percorrer e dar free no Baralho
    TipoApontador p, aux;

    for (p = Baralho -> Primeiro; p != NULL; p = aux)
    {
        aux = p -> Prox;
        free(p);
    }
}

//ok
//Embaralha o baralho usando a funçao srand, assim pegando uma carta com a função retiraBaralho na posição dada por rand e inserindo na ultima posição com a função InsereBaralho
void embaralha (TipoBaralho *Baralho)
{
    //Usando srand, para garantir a aleatoriedade a cada execução
    srand(time(NULL));

    //Declaração das variáveis auxiliares para realizar as trocas no Baralho
    TipoCarta aux;
    int posicao;

    for (int i = 0; i < 40; i++)
    {
        posicao = rand() % 40;
        aux = retiraBaralho(Baralho, posicao);
        InsereBaralho( aux, Baralho);
    }
}

//ok
//Pega a carta do meio com a função retiraBaralho, salva ela em trunfo e depois insere ela na ultima posição do baralho com InsereBaralho
void corta(TipoBaralho *Baralho, TipoCarta *trunfo)
{
    TipoCarta auxCarta;
    int i;

    for (i = 0; i < 20; i++)
    {
        auxCarta = retiraBaralho( Baralho, 0);
        *trunfo = auxCarta;
        InsereBaralho(auxCarta, Baralho);
    } 
}

//*************************FUNÇOES MAO **********************************************//

//ok
//Verifica se a mao esta vazia
int verificaVaziaMao (TipoMao Mao)
{
    return (Mao.Primeiro == Mao.ultimo);
}

//ok
//Torna a mao vazia
void tornaVaziaMao (TipoMao *Mao)
{
    Mao -> Primeiro = inicioLista;
    Mao -> ultimo = Mao -> Primeiro;
}

//ok
//Retira uma carta do baralho com a função retiraBaralho e adiciona tal carta na ultima posição da mao
void compraCarta (TipoMao *mao, TipoBaralho *Baralho)
{
    //Insere a carta que foi comprada e incrementa o último do TipoMao para "confirmar" o espaço que a carta ocupa
    mao -> cartasJogador[mao -> ultimo - 1] = retiraBaralho(Baralho, 0);
    mao -> ultimo++;
}

//ok
//Retira uma carta da posição "Mesa" da mao, muda todas as posições posteriores a "Mesa" para a esquerda e retorna a carta escolhida
TipoCarta retiraCartaMao (TipoMao *Mao, int Mesa)
{
    int Aux;
    TipoCarta CartaEscolhida = Mao -> cartasJogador[Mesa];
    Mao -> ultimo--;

    for(Aux = Mesa; Aux <  Mao -> ultimo; Aux++)
    {
        Mao -> cartasJogador[Aux] = Mao -> cartasJogador[Aux + 1];
    }

    return CartaEscolhida;
}

//ok
//Imprime as cartas da mao na forma Carta -> id: %c, naipe: %c, para ser usado quando o modo debug esta ativado
void imprimeMao(TipoMao mao, int x, int y)
{
    int i;

    for (i = 0; i < mao.ultimo-1; i++)
    {
        gotoxy(x, y + i);
        printf("id: %c, naipe: %c", mao.cartasJogador[i].id, mao.cartasJogador[i].naipe);
    }
}

//*************************FUNÇOES MESA GERAL *******************************************//

//ok
//Tira uma carta da mao do jogador com a função retiraCartaMao, printa essa carta na mesa usando PrintCartaFrente e printas as cartas que sobraram na mao do jogador na 
//mao(posição mais perto do jogador) com PrintCartaFrente
TipoCarta TiraCartaEPrinta(TipoMao *Mao, int mesa, int x, int y, int numeroDeCartasMao, int jogador)
{
    TipoCarta CartaEscolhida;
    CartaEscolhida = retiraCartaMao (Mao, mesa);

    switch(jogador)
    {
        //Jogador
        case 0:
        DeletaIntervalo(69, 31, 91, 39);
        switch(numeroDeCartasMao)
        {
            case 3:
            PrintCartaFrente(Mao -> cartasJogador[0], 69, 31);
            PrintCartaFrente(Mao -> cartasJogador[1], 74, 31);
            gotoxy(71, 39);
            printf("1     2      ");
            break;

            case 2:
            PrintCartaFrente(Mao -> cartasJogador[0], 69, 31);
            gotoxy(71, 39);
            printf("1            ");
            break;

            case 1:
            gotoxy(71, 39);
            printf("             ");
            break;
        }
        break;

        //CPU1
        case 1:
        DeletaIntervalo(130, 8, 145, 25);
        switch(numeroDeCartasMao)
        {
            case 3:
            PrintVerso( 'h', 130, 20);
            PrintVerso( 'h', 130, 18);
            break;

            case 2:
            PrintVerso( 'h', 130, 20);
            break;
        }
        break;

        //CPU2
        case 2:
        DeletaIntervalo(69, 5, 91, 12);
        switch(numeroDeCartasMao)
        {
            case 3:
            PrintVerso( 'v', 79, 5);
            PrintVerso( 'v', 74, 5);
            break;

            case 2:
            PrintVerso( 'v', 79, 5);
            break;
        }
        break;

        //CPU3
        case 3:
        DeletaIntervalo(19, 8, 35, 25);
        switch(numeroDeCartasMao)
        {
            case 3:
            PrintVerso( 'h', 19, 16);
            PrintVerso( 'h', 19, 18);
            break;

            case 2:
            PrintVerso( 'h', 19, 16);
            break;
        }
        break;
    }

    PrintCartaFrente(CartaEscolhida, x, y);
    return CartaEscolhida;
}

//Dá a carta ao jogador e reduz o número de cartas do baralho
void RecebeCarta (TipoMao *Mao, TipoBaralho *Baralho, int *numeroDeCartasBaralho)
{
    compraCarta (Mao, Baralho);
    *numeroDeCartasBaralho = (*numeroDeCartasBaralho) - 1;
    gotoxy(85, 13);
    printf("     %i \n", *numeroDeCartasBaralho);
}

//*************************FUNÇOES MESA DE DOIS JOGADORES ******************************//

//ok
//Distribui as cartas do baralho para um jogador e um cpu sendo dada uma carta para cada por vez ate terem 3 cartas na mao dos dois
void DistribuiCartasPrimeiraRodadaDois(TipoMao *MaoJogador, TipoMao *MaoCPU2, TipoBaralho *Baralho, int *numeroDeCartasBaralho)
{
    int i;
    tornaVaziaMao (MaoJogador);
    tornaVaziaMao (MaoCPU2);

    for(i = 0; i<3; i++)
    {
        RecebeCarta(MaoJogador, Baralho, numeroDeCartasBaralho);
        PrintCartaFrente(MaoJogador -> cartasJogador[i] , 69+5*i, 31);
        usleep(500000);
        RecebeCarta(MaoCPU2, Baralho, numeroDeCartasBaralho);
        PrintVerso('v', 79-5*i, 5);
        usleep(500000);
    }
}

//ok
//Distribui uma carta primeiro para o jogador e depois para o cpu
void DarCartaPeloJogadorDois(TipoMao *MaoJogador, TipoMao *MaoCPU2, TipoBaralho *Baralho, int *numeroDeCartasBaralho, int aposZero)
{
    if (aposZero == 0)
    {
        RecebeCarta (MaoJogador, Baralho, numeroDeCartasBaralho);
        PrintCartaFrente(MaoJogador -> cartasJogador[MaoJogador -> ultimo - 2] , 79, 31);
        gotoxy(71, 39);
        printf("1     2     3");
        sleep(1);
        RecebeCarta (MaoCPU2, Baralho, numeroDeCartasBaralho);
        PrintVerso('v', 69, 5);
    }
}

//ok
//Distribui uma carta primeiro para o cpu e depois para o jogador
void DarCartaPeloCPUDois(TipoMao *MaoJogador, TipoMao *MaoCPU2, TipoBaralho *Baralho, int *numeroDeCartasBaralho, int aposZero)
{
    if (aposZero == 0)
    {
        RecebeCarta (MaoCPU2, Baralho, numeroDeCartasBaralho);
        PrintVerso('v', 69, 5);
        sleep(1);
        RecebeCarta (MaoJogador, Baralho, numeroDeCartasBaralho);
        PrintCartaFrente(MaoJogador -> cartasJogador[MaoJogador -> ultimo - 2] , 79, 31);
        gotoxy(71, 39);
        printf("1     2     3");       
    }
}

//*************************FUNÇOES MESA DE QUATRO JOGADORES ********************************//

//ok
//Distribui as cartas do baralho para um jogador e 3 cpu sendo dada uma carta para cada por vez ate terem 3 cartas na mao dos quatro
void DistribuiCartasPrimeiraRodadaQuatro(TipoMao *MaoJogador, TipoMao *MaoCPU1, TipoMao *MaoCPU2, TipoMao *MaoCPU3, TipoBaralho *Baralho, int *numeroDeCartasBaralho)
{
    int i;
    tornaVaziaMao (MaoJogador);
    tornaVaziaMao (MaoCPU1);
    tornaVaziaMao (MaoCPU2);
    tornaVaziaMao (MaoCPU3);

    for (i = 0; i < 3; i++)
    {
        RecebeCarta (MaoJogador, Baralho, numeroDeCartasBaralho);
        PrintCartaFrente(MaoJogador -> cartasJogador[i] , 69+5*i, 31);
        usleep(500000);
        RecebeCarta (MaoCPU1, Baralho, numeroDeCartasBaralho);
        PrintVerso('h', 130, 20-2*i);
        usleep(500000);
        RecebeCarta (MaoCPU2, Baralho, numeroDeCartasBaralho);
        PrintVerso('v', 79-5*i, 5);
        usleep(500000);
        RecebeCarta (MaoCPU3, Baralho, numeroDeCartasBaralho);
        PrintVerso('h', 19, 16+2*i);
        usleep(500000);
    }
}

//ok
//Distribui uma carta primeiro para o jogador e depois para o cpu1 e assim por diante
void DarCartaPeloJogadorQuatro(TipoMao *MaoJogador, TipoMao *MaoCPU1, TipoMao *MaoCPU2, TipoMao *MaoCPU3, TipoBaralho *Baralho, int *numeroDeCartasBaralho, int aposZero)
{
    if (aposZero == 0)
    {
        RecebeCarta (MaoJogador, Baralho, numeroDeCartasBaralho);
        PrintCartaFrente(MaoJogador -> cartasJogador[MaoJogador -> ultimo - 2] , 79, 31);
        gotoxy(71, 39);
        printf("1     2     3");
        sleep(1);
        RecebeCarta (MaoCPU1, Baralho, numeroDeCartasBaralho);
        PrintVerso('h', 130, 16);
        sleep(1);
        RecebeCarta (MaoCPU2, Baralho, numeroDeCartasBaralho);
        PrintVerso('v', 69, 5);
        sleep(1);
        RecebeCarta (MaoCPU3, Baralho, numeroDeCartasBaralho);
        PrintVerso('h', 19, 20);
    }
}

//ok
//Distribui uma carta primeiro para o cpu1 e depois para o cpu2 e assim por diante
void DarCartaPeloCPU1Quatro(TipoMao *MaoJogador, TipoMao *MaoCPU1, TipoMao *MaoCPU2, TipoMao *MaoCPU3, TipoBaralho *Baralho, int *numeroDeCartasBaralho, int aposZero)
{
    if (aposZero == 0)
    {
        RecebeCarta (MaoCPU1, Baralho, numeroDeCartasBaralho);        
        PrintVerso('h', 130, 16);
        sleep(1);
        RecebeCarta (MaoCPU2, Baralho, numeroDeCartasBaralho);
        PrintVerso('v', 69, 5);
        sleep(1);
        RecebeCarta (MaoCPU3, Baralho, numeroDeCartasBaralho);
        PrintVerso('h', 19, 20);
        sleep(1);
        RecebeCarta (MaoJogador, Baralho, numeroDeCartasBaralho);
        PrintCartaFrente(MaoJogador -> cartasJogador[MaoJogador -> ultimo - 2] , 79, 31);
        gotoxy(71, 39);
        printf("1     2     3");
    }
}

//ok
//Distribui uma carta primeiro para o cpu2 e depois para o cpu3 e assim por diante
void DarCartaPeloCPU2Quatro(TipoMao *MaoJogador, TipoMao *MaoCPU1, TipoMao *MaoCPU2, TipoMao *MaoCPU3, TipoBaralho *Baralho, int *numeroDeCartasBaralho, int aposZero)
{
    if (aposZero == 0)
    {
        RecebeCarta (MaoCPU2, Baralho, numeroDeCartasBaralho);        
        PrintVerso('v', 69, 5);
        sleep(1);
        RecebeCarta (MaoCPU3, Baralho, numeroDeCartasBaralho);
        PrintVerso('h', 19, 20);
        sleep(1);
        RecebeCarta (MaoJogador, Baralho, numeroDeCartasBaralho);
        PrintCartaFrente(MaoJogador -> cartasJogador[MaoJogador -> ultimo - 2] , 79, 31);
        gotoxy(71, 39);
        printf("1     2     3");
        sleep(1);
        RecebeCarta (MaoCPU1, Baralho, numeroDeCartasBaralho);
        PrintVerso('h', 130, 16);
    }
}

//ok
//Distribui uma carta primeiro para o cpu3 e depois para o jogador e assim por diante
void DarCartaPeloCPU3Quatro(TipoMao *MaoJogador, TipoMao *MaoCPU1, TipoMao *MaoCPU2, TipoMao *MaoCPU3, TipoBaralho *Baralho, int *numeroDeCartasBaralho, int aposZero)
{
    if (aposZero == 0)
    {
        RecebeCarta (MaoCPU3, Baralho, numeroDeCartasBaralho);               
        PrintVerso('h', 19, 20);
        sleep(1);
        RecebeCarta (MaoJogador, Baralho, numeroDeCartasBaralho);
        PrintCartaFrente(MaoJogador -> cartasJogador[MaoJogador -> ultimo - 2] , 79, 31);
        gotoxy(71, 39);
        printf("1     2     3");
        sleep(1);
        RecebeCarta (MaoCPU1, Baralho, numeroDeCartasBaralho);
        PrintVerso('h', 130, 16);
        sleep(1);
        RecebeCarta (MaoCPU2, Baralho, numeroDeCartasBaralho);
        PrintVerso('v', 69, 5);
    }
}

//*************************FUNÇOES DE COMPARAÇÃO ******************************************//

//ok
//Acha o maior numero em um vetor
int maior(TipoCarta *lista, int t, int *posi)
{
    int i, ganhou = 0;

    for (i = 1; i < t; i++)
    {
        if (lista[posi[ganhou]].posicao < lista[posi[i]].posicao)
        {
            ganhou = i;
        }
    }

    return posi[ganhou];
}

//ok
//Funçao para achar e comparar as cartas que tem o mesmo naipe do trunfo
int achaTrunfosECompara(TipoCarta *listaMesa, TipoCarta trunfo, int numeroDeJogadores)
{
    int i, t = 0, posi[numeroDeJogadores];

    //Obtendo as cartas com naipes iguais ao do trunfo
    for (i = 0; i < numeroDeJogadores; i++)
    {
        if (listaMesa[i].naipe == trunfo.naipe)
        {
            posi[t] = i;
            t++;
        }
    }

    switch (t)
    {
        //Caso não haja nenhuma carta com naipe igual ao do trunfo
        case 0:
            return -1;

        //Se houver apenas um naipe igual ao do trunfo, este já ganha
        case 1:
            return posi[0];

        //Se houver mais de um naipe igual ao do trunfo, utiliza-se a função maior para encontrar o com maior valor, 
        //que será o "vencedor"
        default:
            return maior(listaMesa, t, posi);
    }
}

//ok
//Funçao procura se ha naipes iguais ao primeiro a jogar
int naipesIguaisAoPrimeiro(TipoCarta *listaMesa, int numeroDeJogadores, int comeca)
{
    int i, t = 0, posi[numeroDeJogadores];

    for (i = 0; i < numeroDeJogadores; i++)
    {
        //Obtendo as cartas com naipes iguais à primeira jogada
        if (listaMesa[i].naipe == listaMesa[comeca].naipe)
        {
            posi[t] = i;
            t++;
        }
    }

    switch (t)
    {
        //Se não há nenhum outro naipe igual ao primeiro jogado, então retorna este, já que é o maior
        case 1:
            return comeca;

        //Se houver outra carta de naipe igual à primeira, acha a maior entre elas e retorna quem venceu
        default:
            return maior(listaMesa, t, posi);
    }
}

//ok
//Compara duas cartas, primeiro verifica se existe algum trunfo, se existir um ele ganha, dois ele compara e maior ganha, se nao existir ele ve que jogou primeiro e se o naipe 
//do primeiro for igual ao do segundo entao ele verifica o maior, se nao for igual o primeiro ganha
void funcComparaDois(TipoCarta *listaMesa, TipoCarta trunfo, int *comeca, int *pontosJogador, int *pontosCPU, int *monteJ, int *monteCPU)
{
    int ganhou;

    //Procura e compara as cartas com naipe igual ao do trunfo
    ganhou = achaTrunfosECompara(listaMesa, trunfo, 2);

    //Se nenhuma carta de naipe igual ao do trunfo foi encontrada (ganhou = -1)
    if (ganhou == -1)
    {
        //Procura a maior carta de naipe igual à primeira jogada
        ganhou = naipesIguaisAoPrimeiro(listaMesa, 2, *comeca);
    }

    switch(ganhou)
    {
        /*Incrementa o número de cartas do monte do vencedor em 2, sinalizando que duas cartas foram obtidas
          Define quem começa a próxima rodada baseado em quem ganhou
          Incrementa os pontos de acordo com o valor das cartas obtidas para o monte de cada jogador*/

        //Caso o jogador ganhe
        case 0:
            *pontosJogador = (*pontosJogador) + (listaMesa[0].valor) + (listaMesa[1].valor);
            *comeca = 0;
            *monteJ = (*monteJ) + 2;
        break;
        
        //Caso o CPU ganhe
        case 1:
            *pontosCPU = (*pontosCPU) + (listaMesa[0].valor) + (listaMesa[1].valor);
            *comeca = 1;
            *monteCPU = (*monteCPU) + 2;
        break;
    }
}

//ok
//Compara quatro cartas, primeiro verifica se existe algum trunfo, se existir um ele ganha, mas de um ele compara e maior ganha, se nao existir ele ve que jogou primeiro e se o naipe 
//do primeiro for igual ao algum dos outros entao ele verifica o maior, se nao for igual a nenhum deles o primeiro ganha
void funcComparaQuatro(TipoCarta *listaMesa, TipoCarta trunfo, int *comeca, int *pontosJogador, int *pontosCPU1, int *pontosCPU2, int *pontosCPU3, int *monteJ, int *monteCPU1, int *monteCPU2, int *monteCPU3)
{
    //Lógica idêntica à funcComparaDois, porém aplicada a quatro jogadores
    int ganhou;
    ganhou = achaTrunfosECompara(listaMesa, trunfo, 4);

    if (ganhou == -1)
    {
        ganhou = naipesIguaisAoPrimeiro(listaMesa, 4, *comeca);
    }

    switch(ganhou)
    {
        case 0:
            *pontosJogador = (*pontosJogador) + (listaMesa[0].valor) + (listaMesa[1].valor) + (listaMesa[2].valor) + (listaMesa[3].valor);
            *comeca = 0;
            *monteJ = (*monteJ) + 4;
            break;
        
        case 1:
            *pontosCPU1 = (*pontosCPU1) + (listaMesa[0].valor) + (listaMesa[1].valor) + (listaMesa[2].valor) + (listaMesa[3].valor);
            *comeca = 1;
            *monteCPU1 = (*monteCPU1) + 4;
            break;

        case 2:
            *pontosCPU2 = (*pontosCPU2) + (listaMesa[0].valor) + (listaMesa[1].valor) + (listaMesa[2].valor) + (listaMesa[3].valor);
            *comeca = 2;
            *monteCPU2 = (*monteCPU2) + 4;
            break;

        case 3:
            *pontosCPU3 = (*pontosCPU3) + (listaMesa[0].valor) + (listaMesa[1].valor) + (listaMesa[2].valor) + (listaMesa[3].valor);
            *comeca = 3;
            *monteCPU3 = (*monteCPU3) + 4;
            break;
    }
}