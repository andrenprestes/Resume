#include "Jogo.h"

//*****************************************************FEITO EM FONTE UBUNTO CONDENSED TAMANHO 9 *********************************************************************//

//*************************FUNÇOES MESA GERAL ******************************//

//ok
//Printa a parte de fora da mesa
void PrintMesaFora(){
    int i, j;
    system("clear");
    for(i = 0; i < 3; i++){
        printf("\n");
    }

    //Desenha a mesa
    printf("                \u250C");//Quina esquerda superior
    for(i = 0; i<=130; i++){
        printf("\u2500");//Meio
    }
    printf("\u2510\n");//Quina direita superior
    for(j = 0; j <= 35; j++){
        switch(j){
            case 34:
                printf("                \u2554");//Quina esquerda superior duplo
                for(i = 0; i<=11; i++){
                    printf("\u2550");//Meio duplo
                }
                printf("\u2557");//Quinadireita superior duplo
                for(i = 0; i<=117; i++){
                    printf(" ");
                }
                break;

            case 35:
                printf("                \u2551");//Lado duplo
                printf("  v \u25BA MENU  \u2551");//Lado duplo
                for(i = 0; i<=117; i++){
                    printf(" ");
                }
                break;

            default:
                printf("                \u2502");//Lado
                for(i = 0; i<=130; i++){
                    printf(" ");
                }
                break;
        }
        
        
        
        //Desenha a parte superior do placar
        if(j == 25){
            printf("\u251C");//Lado com saida
            for(int k = 0; k<=25; k++){
            printf("\u2500");//Meio
            }
            printf("\u2510\n");//Quina direita superior
        } else{
            //Desenha a parte lateral do placar
            if(j > 25){
                printf("\u2502");//Lado
                if(j == 26){
                    printf("       P L A C A R ");
                    for(int l = 0; l<=6; l++){
                        printf(" ");
                    }
                } else{
                    for(int l = 0; l<=25; l++){
                        printf(" ");
                    }
                }
            }
            printf("\u2502\n");//Lado
        }
    }
    printf("                \u255A");//Quina esquerda baixo dupla
    for(i = 0; i<=129; i++){
        if (i < 12) {
            printf("\u2550");//Meio duplo
        } else{
            if (i == 12) {
                printf("\u255D");//Quina direita baixo dupla
            }
            printf("\u2500");//Meio
        }
    }
    printf("\u2534");//Meio com saida 
    //Desenha a parte inferior do placar
    for(i = 0; i<=25; i++){
        printf("\u2500");//Meio        
    }
    printf("\u2518\n");//Quina direita baixo 
    //Escreve o nome do jogador
    for(i = 0 ; i<=54; i++){
        printf(" ");
    }
    printf("                        Jogador\n");
    for(i = 0; i < 4; i++){
        printf("\n");
    }
}

//ok
//Quando nenhuma das opições possiveis é selecionada
void defaultMesa(char *comando, int numeroDeCartasMao)
{   
    char aux = '0' + numeroDeCartasMao;

    while(*comando != 'v' && (*comando < '1' || *comando > aux))
    {
        gotoxy(40, 43);
        printf("Nao e possivel executar tal comando!\n");
        gotoxy(40, 44);
        printf("Escolha outra opcao : ");
        scanf(" %c", comando);
        DeletaIntervalo(40, 43, 115, 44);
    } 
}

//ok
//Switch de seleção do jogador quando ele esta jogando
TipoCarta SeletorMesa(TipoMao *MaoJogador, char *comando, int numeroDeCartasMao, int x, int y, TipoBaralho *Baralho){
    switch(*comando){
        case '1':
            return TiraCartaEPrinta(MaoJogador, 0, x, y, numeroDeCartasMao, 0);

        case '2':
            return TiraCartaEPrinta(MaoJogador, 1, x, y, numeroDeCartasMao, 0);

        case '3':
            return TiraCartaEPrinta(MaoJogador, 2, x, y, numeroDeCartasMao, 0);

        case 'v':
            freeBaralho (Baralho);
            criaBaralho (Baralho);     
            break;
    }
}

//ok
//Printa you win, da free no baralho e muda a variavel fim para acabar o jogo
void PrintYOUWIN(int *fim, TipoBaralho *Baralho)
{
    DeletaIntervalo(69, 31, 91, 39);
    DeletaIntervalo(19, 5, 145, 25);
    gotoxy(18, 14);
    printf("`8.`8888.      ,8'     ,o888888o.     8 8888      88                     `8.`888b                 ,8'  8 8888    b.             8\n"); 
    gotoxy(18, 15);
    printf(" `8.`8888.    ,8'   . 8888     `88.   8 8888      88                      `8.`888b               ,8'   8 8888    888o.          8\n"); 
    gotoxy(18, 16);
    printf("  `8.`8888.  ,8'   ,8 8888       `8b  8 8888      88                       `8.`888b             ,8'    8 8888    Y88888o.       8\n"); 
    gotoxy(18, 17);
    printf("   `8.`8888.,8'    88 8888        `8b 8 8888      88                        `8.`888b     .b    ,8'     8 8888    .`Y888888o.    8\n"); 
    gotoxy(18, 18);
    printf("    `8.`88888'     88 8888         88 8 8888      88                         `8.`888b    88b  ,8'      8 8888    8o. `Y888888o. 8\n");
    gotoxy(18, 19);
    printf("     `8. 8888      88 8888         88 8 8888      88                          `8.`888b .`888b,8'       8 8888    8`Y8o. `Y88888o8\n"); 
    gotoxy(18, 20);
    printf("      `8 8888      88 8888        ,8P 8 8888      88                           `8.`888b8.`8888'        8 8888    8   `Y8o. `Y8888\n"); 
    gotoxy(18, 21);
    printf("       8 8888      `8 8888       ,8P  ` 8888     ,8P                            `8.`888`8.`88'         8 8888    8      `Y8o. `Y8\n"); 
    gotoxy(18, 22);
    printf("       8 8888       ` 8888     ,88'     8888   ,d8P                              `8.`8' `8,`'          8 8888    8         `Y8o.`\n"); 
    gotoxy(18, 23);
    printf("       8 8888          `8888888P'        `Y88888P'                                `8.`   `8'           8 8888    8            `Yo\n");

    *fim = 1;
    freeBaralho (Baralho);
    criaBaralho (Baralho);
}

//ok
//Printa you lose, da free no baralho e muda a variavel fim para acabar o jogo
void PrintYOULOSE(int *fim, TipoBaralho *Baralho)
{
    DeletaIntervalo(69, 31, 91, 39);
    DeletaIntervalo(19, 5, 145, 25);
    gotoxy(18, 14);
    printf("8.`8888.      ,8'     ,o888888o.     8 8888      88        8 8888             ,o888888o.        d888888o.   8 888888888888\n");   
    gotoxy(18, 15);         
    printf("`8.`8888.    ,8'   . 8888     `88.   8 8888      88        8 8888          . 8888     `88.    .`8888:' `88. 8 8888        \n");
    gotoxy(18, 16);           
    printf(" `8.`8888.  ,8'   ,8 8888       `8b  8 8888      88        8 8888         ,8 8888       `8b   8.`8888.   Y8 8 8888        \n");   
    gotoxy(18, 17);        
    printf("  `8.`8888.,8'    88 8888        `8b 8 8888      88        8 8888         88 8888        `8b  `8.`8888.     8 8888        \n"); 
    gotoxy(18, 18);          
    printf("   `8.`88888'     88 8888         88 8 8888      88        8 8888         88 8888         88   `8.`8888.    8 888888888888\n");     
    gotoxy(18, 19);      
    printf("    `8. 8888      88 8888         88 8 8888      88        8 8888         88 8888         88    `8.`8888.   8 8888        \n");      
    gotoxy(18, 20);     
    printf("     `8 8888      88 8888        ,8P 8 8888      88        8 8888         88 8888        ,8P     `8.`8888.  8 8888        \n"); 
    gotoxy(18, 21);          
    printf("      8 8888      `8 8888       ,8P  ` 8888     ,8P        8 8888         `8 8888       ,8P  8b   `8.`8888. 8 8888        \n");
    gotoxy(18, 22);           
    printf("      8 8888       ` 8888     ,88'     8888   ,d8P         8 8888          ` 8888     ,88'   `8b.  ;8.`8888 8 8888        \n"); 
    gotoxy(18, 23);          
    printf("      8 8888          `8888888P'        `Y88888P'          8 888888888888     `8888888P'      `Y8888P ,88P' 8 888888888888\n");

    *fim = 1;
    freeBaralho (Baralho);
    criaBaralho (Baralho);
}

//ok
//Acha a maior carta na mao
void MaiorMao(TipoMao Mao, TipoCarta trunfo, TipoCarta *listaMesa, int comeca, int *maiorCarta, int numeroDeCartasMao)
{
    int i, posi[numeroDeCartasMao], t = 0;

    *maiorCarta = achaTrunfosECompara(Mao.cartasJogador, trunfo, numeroDeCartasMao);

    //Se não há nenhuma carta com naipe igual ao trunfo, procura as com naipes iguais à primeira jogada
    if (*maiorCarta < 0)
    {
        *maiorCarta = 0;

        for (i = 0; i < numeroDeCartasMao; i++)
        {
            if (Mao.cartasJogador[i].naipe == listaMesa[comeca].naipe)
            {
                posi[t] = i;
                t++;
            }
        }

        switch(t)
        {
            //Nenhuma
            case 0:
            *maiorCarta = 0;
            break;

            //Apenas uma
            case 1:
            *maiorCarta = posi[0];
            break;

            //Mais de uma
            default:
            *maiorCarta = maior(Mao.cartasJogador, t, posi);
            break;
        }
    }
}

//ok
//Acha a menor carta na mao
void MenorMao(TipoMao Mao, TipoCarta trunfo, int *menorCarta, int numeroDeCartasMao)
{
    int posi[3], i, t = 0, men = 0;

    //Acha quantas cartas tem naipe diferente do trunfo
    for (i = 0; i < numeroDeCartasMao; i++)
    {
        if (Mao.cartasJogador[i].naipe != trunfo.naipe)
        {
                posi[t] = i;
                t++;
        }
    }

    switch (t)
    {
        //Se nenhuma carta tiver naipe diferente
        case 0:
        for (i = 1; i < numeroDeCartasMao; i++)
        {
            //Encontra a carta com menor valor
            if (Mao.cartasJogador[i].posicao < Mao.cartasJogador[men].posicao)
            {
                men = i;
            }
        }

        *menorCarta = men;
        break;

        default:
        for(i = 1; i < t; i++)
        {
            //Acha a menor entre elas
            if (Mao.cartasJogador[posi[men]].posicao > Mao.cartasJogador[posi[i]].posicao)
            {
                men = i;
            }
        }

        *menorCarta = posi[men];
        break;
    }
}

//ok
//Modo de jogo facil o cpu escolhe as cartas com a função rand
void ModoFacil(int *mesaCPU, int numeroDeCartasMao)
{
    srand(time(NULL));
    *mesaCPU = rand() % numeroDeCartasMao;
}

//ok
//Modo de jogo dificil
void ModoDificil(int *mesaCPU, TipoMao MaoCPU, TipoCarta *listaMesa, TipoCarta trunfo, int comeca, int Jogando, int numeroDeCartasMao)
{
    int i, tamanho, maiorCarta;

    *mesaCPU = 0;

    //Se tiver apenas uma carta na mão
    if (numeroDeCartasMao == 1)
    {
        *mesaCPU = 0;
    }

    //Caso seja a primeira jogada da rodada, joga sua menor carta
    else if (comeca == Jogando)
    {
        MenorMao(MaoCPU, trunfo, mesaCPU, numeroDeCartasMao);
    } 
    
    else
    {
        //Descobre quantas pessoas jogaram
        if (comeca < Jogando)
        {
            tamanho = Jogando - comeca;
        } 
        
        else if (comeca == (Jogando + 1))
        {
            tamanho = 3;
        } 
        
        else if (comeca == (Jogando + 2))
        {
            tamanho = 2;
        }

        int Ordem[tamanho], t, j = 0, posiTrunfo[tamanho], posiNaipe[tamanho], MaiorMesa = 0, ganhou;

        t = comeca;

        //Ordena um vetor na ordem em que as cartas foram jogadas
        for (i = 0; i < tamanho; i++)
        {
            if((t + i) > 3)
            {
                Ordem[i] = j;
                j++;
            } 
            
            else
            {
                Ordem[i] = t + i;
            }
        }

        t = 0;

        for (i = 0; i < tamanho; i++)
        {
            //Procura os trunfos na mesa
            if(listaMesa[Ordem[i]].naipe == trunfo.naipe)
            {
                posiTrunfo[t] = Ordem[i];
                t++;
            }
        }

        switch(t)
        {
            //Nenhuma carta com naipe igual ao trunfo
            case 0:
                ganhou = -1;
                break;

            //Apenas uma carta com naipe igual ao trunfo
            case 1:
                ganhou = comeca;
                break;

            //Mais de uma carta com naipe igual ao trunfo
            default:
                ganhou = maior(listaMesa, t, posiTrunfo);
                break;
        }
        
        //Se não há nenhuma carta com naipe igual ao trunfo
        if (ganhou < 0)
        {
            t = 0;

            //Procura as cartas da mesa com naipe igual à primeira jogada
            for (i = 0; i < tamanho; i++)
            {
                if (listaMesa[Ordem[i]].naipe == listaMesa[Ordem[0]].naipe)
                {
                    posiNaipe[t] = Ordem[i];
                    t++;
                }
            }

            switch(t)
            {
                //Caso haja apenas uma carta na mesa igual ao naipe da primeira jogada
                case 1:
                    ganhou = posiNaipe[0];
                    break;

                //Mais de uma carta na mesa igual ao naipe da primeira jogada
                default:
                    ganhou = maior(listaMesa, t, posiNaipe);
                    break;
            }

            MaiorMesa = ganhou;

            //Encontra a maior carta da mão
            MaiorMao(MaoCPU, trunfo, listaMesa, comeca, &maiorCarta, numeroDeCartasMao);

            //Verifica se o naipe é igual ao do trunfo
            if (MaoCPU.cartasJogador[maiorCarta].naipe == trunfo.naipe)
            {
                //Caso seja, joga a carta
                *mesaCPU = maiorCarta;
            } 
            
            //Verifica se o naipe da maior carta encontrada é igual ao da primeira carta jogada
            else if (MaoCPU.cartasJogador[maiorCarta].naipe == listaMesa[MaiorMesa].naipe)
            {
                //Caso o valor seja maior, joga a carta
                if (MaoCPU.cartasJogador[maiorCarta].posicao > listaMesa[MaiorMesa].posicao)
                {
                    *mesaCPU = maiorCarta;
                }

                //Do contrário, joga a menor carta da mão
                else
                {
                    MenorMao(MaoCPU, trunfo, mesaCPU, numeroDeCartasMao);
                }        
            }

            //Procura a primeira cartas com naipe igual à primeira jogada e com valor maior
            else
            {
                for (i = 0; i < numeroDeCartasMao; i++)
                {
                    if (MaoCPU.cartasJogador[i].naipe == listaMesa[MaiorMesa].naipe)
                    {
                        if (MaoCPU.cartasJogador[i].posicao > listaMesa[MaiorMesa].posicao)
                        {
                            *mesaCPU = i;
                            i = numeroDeCartasMao;
                        }

                        //Caso não encontre, joga a menor carta
                        else if (i == numeroDeCartasMao - 1)
                        {
                            MenorMao(MaoCPU, trunfo, mesaCPU, numeroDeCartasMao);
                        }
                    }
                }
            } 
        }

        //Caso a maior carta da mesa tenha o naipe igual ao trunfo
        else
        {
            MaiorMesa = ganhou;

            //Encontra a maior carta da mão
            MaiorMao(MaoCPU, trunfo, listaMesa, comeca, &maiorCarta, numeroDeCartasMao);

            //Verifica se a maior carta tem naipe igual ao do trunfo
            if (MaoCPU.cartasJogador[maiorCarta].naipe == trunfo.naipe)
            {
                //Se a carta com naipe igual ao do trunfo tiver valor maior que a maior da mesa
                if (MaoCPU.cartasJogador[maiorCarta].posicao > listaMesa[MaiorMesa].posicao)
                {
                    //Joga a carta
                    *mesaCPU = maiorCarta;
                } 
                
                //Do contrário, joga a menor carta da mão
                else
                {
                    MenorMao(MaoCPU, trunfo, mesaCPU, numeroDeCartasMao);
                }
            } 
            
            //Do contrário, joga a menor carta da mão
            else
            {
                MenorMao(MaoCPU, trunfo, mesaCPU, numeroDeCartasMao);
            }
        }
    }
}

//ok
//Modos de escolha de carta do cpu
void ModoDeEscolhaCPU(int *mesaCPU, char modoDeJogo, TipoMao MaoCPU, TipoCarta *listaMesa, TipoCarta trunfo, int comeca, int Jogando, int numeroDeCartasMao)
{
    switch (modoDeJogo)
    {
        case 'e':
            ModoFacil(mesaCPU, numeroDeCartasMao);
            break;

        case 'h':
            ModoDificil(mesaCPU, MaoCPU, listaMesa, trunfo, comeca, Jogando, numeroDeCartasMao);
            break;
    }
}

//*************************FUNÇOES MESA DOIS JOGADORES ************************//

//ok
//Verifica se o numero de cartas no baralho é igual a zero, se ele for igual muda a variavel numeroDeCartasMao assim desabilitando a função de dar cartas e verifica se quem ganhou
void NumeroCartasComecoEFimDeJogoDois(int numeroDeCartasBaralho, int *numeroDeCartasMao, int *aposZero, int pontosCPU, int pontosJogador, int *fim, TipoBaralho *Baralho){
    if (numeroDeCartasBaralho == 0) 
    {
        switch (*aposZero)
        {
            case 0:
                *aposZero = (*aposZero) + 1;
                break;
            
            default:
                *numeroDeCartasMao = (*numeroDeCartasMao) - 1;
                *aposZero = (*aposZero) + 1;
                break;
        }
    }

    if (pontosCPU >= 60 || pontosJogador >= 60)
    {
        DeletaIntervalo(20, 5, 130, 30);
        
        if(pontosCPU > pontosJogador)
        {
            PrintYOULOSE(fim, Baralho);
        } 
        
        else
        {
            PrintYOUWIN(fim, Baralho);
        }
    }

    if (*aposZero == 4)
    {
        DeletaIntervalo(20, 5, 130, 30);

        if(pontosCPU > pontosJogador)
        {
            PrintYOULOSE(fim, Baralho);
        }
        
        else
        {
            PrintYOUWIN(fim, Baralho);
        }
    }
}

//ok
//Muda os valores da mesa
void MudaValoresDois(int numeroDeCartasBaralho, int pontosJogador, int pontosCPU, int monteJ, int monteCPU){
    sleep(2);
    DeletaIntervalo(54, 22, 70, 30);
    if (monteJ == 0){   
    } else{
        gotoxy(155, 3);
        printf("     %i \n", monteJ);
        PrintVerso( 'v', 155, 4);
    }
    if (monteCPU == 0){   
    } else{
        gotoxy(167, 3);
        printf("     %i \n", monteCPU);
        PrintVerso( 'v', 167, 4);
    }
    gotoxy(85, 13);
    printf("     %i ", numeroDeCartasBaralho);
    PrintVerso('v', 85, 14);
    gotoxy(160, 32);
    printf("%i", pontosJogador);
    gotoxy(156, 34);
    printf("%i", pontosCPU);
}

//ok
//Printa a mesa da primeira rodada quando tem so dois jogadores
void PrimeiraMesaDois(TipoCarta *trunfo, TipoMao *MaoJogador, TipoMao *MaoCPU2, TipoBaralho *Baralho, int *numeroDeCartasBaralho){
    
    PrintMesaFora();
    gotoxy(80, 1);
    printf("CPU");
    gotoxy(157, 1);
    printf("Jogador");
    gotoxy(170, 1);
    printf(" CPU");
    gotoxy(150, 32);
    printf("Jogador : 0");
    gotoxy(150, 34);
    printf("CPU : 0");
    embaralha (Baralho);
    corta(Baralho, trunfo); 
    PrintCartaFrente(*trunfo, 73, 14);
    gotoxy(85, 13);
    printf("     %i \n", *numeroDeCartasBaralho);
    PrintVerso( 'v', 85, 14);
    sleep(1);
    DistribuiCartasPrimeiraRodadaDois(MaoJogador, MaoCPU2, Baralho, numeroDeCartasBaralho);
    gotoxy(55, 39);
    printf("Sua vez!   ");
    gotoxy(71, 39);
    printf("1     2     3");
    gotoxy(40, 42);
    printf("Escolha sua opcao : ");
}

//ok
//Começo da proxima rodada
void ProximaRodadaDois(char *comando, char modoDebug, TipoBaralho *Baralho, TipoMao *MaoJogador, TipoMao *MaoCPU2, int comeca, int *numeroDeCartasBaralho, int *numeroDeCartasMao, int *aposZero, int pontosJogador, int pontosCPU, int *fim){
    if(comeca == 0){
        DarCartaPeloJogadorDois(MaoJogador, MaoCPU2, Baralho, numeroDeCartasBaralho, *aposZero);
        if(modoDebug == 'q'){
            DeletaIntervalo(0, 3, 14, 40);
            imprimeBaralho (*Baralho, 0, 3);
            DeletaIntervalo(14, 0, 43, 2);
            imprimeMao(*MaoCPU2, 20, 0);
        }
        NumeroCartasComecoEFimDeJogoDois(*numeroDeCartasBaralho, numeroDeCartasMao, aposZero, pontosCPU, pontosJogador, fim, Baralho);
        gotoxy(20, 45);
        gotoxy(55, 39);
        printf("Sua vez!   ");
        DeletaCaracter(60, 42);
        gotoxy(60, 42);
        scanf(" %c", comando);
    } else{
        DarCartaPeloCPUDois(MaoJogador, MaoCPU2, Baralho, numeroDeCartasBaralho, *aposZero);
        if(modoDebug == 'q'){
            DeletaIntervalo(0, 3, 14, 40);
            imprimeBaralho (*Baralho, 0, 3);
            DeletaIntervalo(14, 0, 43, 2);
            imprimeMao(*MaoCPU2, 20, 0);
        }
        NumeroCartasComecoEFimDeJogoDois(*numeroDeCartasBaralho, numeroDeCartasMao, aposZero, pontosCPU, pontosJogador, fim, Baralho);
        gotoxy(20, 45);
        gotoxy(55, 39);
        printf("Vez do CPU!");
        sleep(1);
    }
}

//ok
//Logica de jogo para mesa de dois jogadores
void LogicaMesaDois(char modoDeJogo, char *comando, TipoBaralho *Baralho, char modoDebug){
    int pontosJogador = 0, pontosCPU = 0, numeroDeCartasBaralho = 40, numeroDeCartasMao = 3, comeca = 0, monteJ = 0, monteCPU2 = 0, mesaCPU2, aposZero = 0, fim = 0, Jogando = 0;
    TipoCarta trunfo, listaMesa[2];
    TipoMao MaoJogador, MaoCPU2;

    PrimeiraMesaDois(&trunfo, &MaoJogador, &MaoCPU2, Baralho, &numeroDeCartasBaralho);
    if(modoDebug == 'q'){
        imprimeBaralho (*Baralho, 0, 3);
        imprimeMao(MaoCPU2, 20, 0);
    }
    gotoxy(60, 42);
    scanf(" %c", comando);
    while (fim != 1 && *comando != 'v'){
        switch(comeca){
            case 0:
                defaultMesa(comando, numeroDeCartasMao);
                Jogando = 0;
                listaMesa[0] = SeletorMesa(&MaoJogador, comando, numeroDeCartasMao, 54, 22, Baralho);
                gotoxy(55, 39);
                printf("Vez do CPU!");
                sleep(1);
                Jogando = 1;
                ModoDeEscolhaCPU(&mesaCPU2, modoDeJogo, MaoCPU2, listaMesa, trunfo, comeca, Jogando, numeroDeCartasMao);
                listaMesa[1] = TiraCartaEPrinta(&MaoCPU2, mesaCPU2, 59, 22, numeroDeCartasMao, 2);
                funcComparaDois(listaMesa, trunfo, &comeca, &pontosJogador, &pontosCPU, &monteJ, &monteCPU2);
                sleep(1);
                MudaValoresDois(numeroDeCartasBaralho, pontosJogador, pontosCPU, monteJ, monteCPU2);
                sleep(1);
                ProximaRodadaDois(comando, modoDebug, Baralho, &MaoJogador, &MaoCPU2, comeca, &numeroDeCartasBaralho, &numeroDeCartasMao, &aposZero, pontosJogador, pontosCPU, &fim);
                break;

            case 1:
                Jogando = 1;
                ModoDeEscolhaCPU(&mesaCPU2, modoDeJogo, MaoCPU2, listaMesa, trunfo, comeca, Jogando, numeroDeCartasMao);
                listaMesa[1] = TiraCartaEPrinta(&MaoCPU2, mesaCPU2, 54, 22, numeroDeCartasMao, 2);
                gotoxy(55, 39);
                printf("Sua vez!   ");
                DeletaCaracter(60, 42);
                gotoxy(60, 42);
                scanf(" %c", comando);
                defaultMesa(comando, numeroDeCartasMao);
                if(*comando == 'v'){
                    freeBaralho (Baralho);
                    criaBaralho (Baralho);     
                    break;
                }
                Jogando = 0;
                listaMesa[0] = SeletorMesa(&MaoJogador, comando, numeroDeCartasMao, 59, 22, Baralho);
                funcComparaDois(listaMesa, trunfo, &comeca, &pontosJogador, &pontosCPU, &monteJ, &monteCPU2);
                sleep(1);
                MudaValoresDois(numeroDeCartasBaralho, pontosJogador, pontosCPU, monteJ, monteCPU2);
                sleep(1);
                ProximaRodadaDois(comando, modoDebug, Baralho, &MaoJogador, &MaoCPU2, comeca, &numeroDeCartasBaralho, &numeroDeCartasMao, &aposZero, pontosJogador, pontosCPU, &fim);
                break;
            }    
    }
    if(fim == 1){
        gotoxy(40, 42);
        printf("Escolha 'v' para ir para o menu : ");
        scanf(" %c", comando);
    } 
}

//*************************FUNÇOES MESA QUATRO JOGADORES **********************//

//ok
//Verifica se o numero de cartas no baralho é igual a zero, se ele for igual muda a variavel numeroDeCartasMao assim desabilitando a função de dar cartas e verifica se quem ganhou
void NumeroCartasComecoEFimDeJogoQuatro(int numeroDeCartasBaralho, int *numeroDeCartasMao, int *aposZero, int pontosCPU1, int pontosCPU2, int pontosCPU3, int pontosJogador, int *fim, TipoBaralho *Baralho){
    int Pontos[4], i, ganhou = 0;

    if(numeroDeCartasBaralho == 0){
        switch (*aposZero){
            case 0:
                *aposZero = (*aposZero) + 1;
                break;
            
            default:
                *numeroDeCartasMao = (*numeroDeCartasMao) - 1;
                *aposZero = (*aposZero) + 1;
                break;
        }
    }
    if(pontosCPU1 >= 60 || pontosCPU2 >= 60 || pontosCPU3 >= 60 || pontosJogador >= 60){
        DeletaIntervalo(20, 5, 130, 30);
        if(pontosJogador >= 60){
            PrintYOUWIN(fim, Baralho);
        } else{
            PrintYOULOSE(fim, Baralho);
        }
    }
    if(*aposZero == 4){
        DeletaIntervalo(20, 5, 130, 30);
        Pontos[0] = pontosJogador;
        Pontos[1] = pontosCPU1;
        Pontos[2] = pontosCPU2;
        Pontos[3] = pontosCPU3;

        for(i = 0; i < 4 - 1; i++){
            if(Pontos[ganhou] < Pontos[i + 1]){
                ganhou = i + 1;
            }
        }

        switch(ganhou){
            case 0:
                PrintYOUWIN(fim, Baralho);
                break;

            default:
                PrintYOULOSE(fim, Baralho);
                break;
        }
    }
}

//ok
//Muda os valores da mesa
void MudaValoresQuatro(int numeroDeCartasBaralho, int pontosJogador, int pontosCPU1, int pontosCPU2, int pontosCPU3, int monteJ, int monteCPU1, int monteCPU2, int monteCPU3){
    sleep(2);
    DeletaIntervalo(54, 22, 80, 30);

    if (monteJ != 0)
    {
        gotoxy(155, 3);
        printf("     %i \n", monteJ);
        PrintVerso( 'v', 155, 4);   
    } 

    if (monteCPU1 != 0)
    {
        gotoxy(167, 3);
        printf("     %i \n", monteCPU1);
        PrintVerso( 'v', 167, 4);   
    } 

    if (monteCPU2 != 0)
    {
        gotoxy(179, 3);
        printf("     %i \n", monteCPU2);
        PrintVerso( 'v', 179, 4);   
    } 

    if (monteCPU3 != 0)
    {
        gotoxy(191, 3);
        printf("     %i \n", monteCPU3);
        PrintVerso( 'v', 191, 4);   
    } 

    gotoxy(85, 13);
    printf("     %i ", numeroDeCartasBaralho);
    PrintVerso('v', 85, 14);
    gotoxy(160, 32);
    printf(" %i", pontosJogador);
    gotoxy(156, 34);
    printf(" %i", pontosCPU1);
    gotoxy(156, 36);
    printf(" %i", pontosCPU2);
    gotoxy(156, 38);
    printf(" %i", pontosCPU3);
}

//ok
//Printa a mesa da primeira rodada quando tem so dois jogadores
void PrimeiraMesaQuatro(TipoCarta *trunfo, TipoMao *MaoJogador, TipoMao *MaoCPU1, TipoMao *MaoCPU2, TipoMao *MaoCPU3, TipoBaralho *Baralho, int *numeroDeCartasBaralho)
{
    PrintMesaFora();
    gotoxy(151, 20);
    printf("CPU1");
    gotoxy(80, 1);
    printf("CPU2");
    gotoxy(10, 20);
    printf("CPU3");
    gotoxy(157, 1);
    printf("Jogador");
    gotoxy(170, 1);
    printf(" CPU1");
    gotoxy(180, 1);
    printf("   CPU2");
    gotoxy(190, 1);
    printf("     CPU3");
    gotoxy(150, 32);
    printf("Jogador : 0");
    gotoxy(150, 34);
    printf("CPU1 : 0");
    gotoxy(150, 36);
    printf("CPU2 : 0");
    gotoxy(150, 38);
    printf("CPU3 : 0");
    embaralha (Baralho);
    corta(Baralho, trunfo); 
    PrintCartaFrente(*trunfo, 73, 14);
    gotoxy(85, 13);
    printf("     %i \n", *numeroDeCartasBaralho);
    PrintVerso( 'v', 85, 14);
    sleep(1);
    DistribuiCartasPrimeiraRodadaQuatro(MaoJogador, MaoCPU1, MaoCPU2, MaoCPU3, Baralho, numeroDeCartasBaralho);
    gotoxy(55, 39);
    printf("Sua vez!    ");
    gotoxy(71, 39);
    printf("1     2     3");
    gotoxy(40, 42);
    printf("Escolha sua opcao : ");
}

//ok
//Switch do começo da proxima rodada
void ProximaRodadaQuatro(char *comando, char modoDebug, TipoBaralho *Baralho, TipoMao *MaoJogador, TipoMao *MaoCPU1, TipoMao *MaoCPU2, TipoMao *MaoCPU3, int comeca, int *numeroDeCartasBaralho, int *numeroDeCartasMao, int *aposZero, int pontosJogador, int pontosCPU1, int pontosCPU2, int pontosCPU3, int *fim)
{
    switch(comeca)
    {
        case 0:
            DarCartaPeloJogadorQuatro(MaoJogador, MaoCPU1, MaoCPU2, MaoCPU3, Baralho, numeroDeCartasBaralho, *aposZero);
            if(modoDebug == 'q')
            {
                DeletaIntervalo(177, 13, 193, 53);
                imprimeBaralho (*Baralho, 177, 13);
                DeletaIntervalo(150, 25, 165, 28);
                imprimeMao(*MaoCPU1, 150, 25);
                DeletaIntervalo(20, 0, 35, 2);
                imprimeMao(*MaoCPU2, 20, 0);
                DeletaIntervalo(0, 25, 15, 28);
                imprimeMao(*MaoCPU3, 0, 25);
            }
            NumeroCartasComecoEFimDeJogoQuatro(*numeroDeCartasBaralho, numeroDeCartasMao, aposZero, pontosCPU1, pontosCPU2, pontosCPU3, pontosJogador, fim, Baralho);
            gotoxy(20, 45);
            gotoxy(55, 39);
            printf("Sua vez!      ");
            DeletaCaracter(60, 42);
            gotoxy(60, 42);
            scanf(" %c", comando);
            break;

        case 1:
            DarCartaPeloCPU1Quatro(MaoJogador, MaoCPU1, MaoCPU2, MaoCPU3, Baralho, numeroDeCartasBaralho, *aposZero);
            if(modoDebug == 'q')
            {
                DeletaIntervalo(177, 13, 193, 53);
                imprimeBaralho (*Baralho, 177, 13);
                DeletaIntervalo(150, 25, 165, 28);
                imprimeMao(*MaoCPU1, 150, 25);
                DeletaIntervalo(20, 0, 35, 2);
                imprimeMao(*MaoCPU2, 20, 0);
                DeletaIntervalo(0, 25, 15, 28);
                imprimeMao(*MaoCPU3, 0, 25);
            }
            NumeroCartasComecoEFimDeJogoQuatro(*numeroDeCartasBaralho, numeroDeCartasMao, aposZero, pontosCPU1, pontosCPU2, pontosCPU3, pontosJogador, fim, Baralho);
            gotoxy(20, 45);
            gotoxy(55, 39);
            printf("Vez do CPU1!");
            sleep(1);
            break;

        case 2:
            DarCartaPeloCPU2Quatro(MaoJogador, MaoCPU1, MaoCPU2, MaoCPU3, Baralho, numeroDeCartasBaralho, *aposZero);
            if(modoDebug == 'q')
            {
                DeletaIntervalo(177, 13, 193, 53);
                imprimeBaralho (*Baralho, 177, 13);
                DeletaIntervalo(150, 25, 165, 28);
                imprimeMao(*MaoCPU1, 150, 25);
                DeletaIntervalo(20, 0, 35, 2);
                imprimeMao(*MaoCPU2, 20, 0);
                DeletaIntervalo(0, 25, 15, 28);
                imprimeMao(*MaoCPU3, 0, 25);
            }
            NumeroCartasComecoEFimDeJogoQuatro(*numeroDeCartasBaralho, numeroDeCartasMao, aposZero, pontosCPU1, pontosCPU2, pontosCPU3, pontosJogador, fim, Baralho);
            gotoxy(20, 45);
            gotoxy(55, 39);
            printf("Vez do CPU2!");
            sleep(1);
            break;

        case 3:
            DarCartaPeloCPU3Quatro(MaoJogador, MaoCPU1, MaoCPU2, MaoCPU3, Baralho, numeroDeCartasBaralho, *aposZero);
            if(modoDebug == 'q')
            {
                DeletaIntervalo(177, 13, 193, 53);
                imprimeBaralho (*Baralho, 177, 13);
                DeletaIntervalo(150, 25, 165, 28);
                imprimeMao(*MaoCPU1, 150, 25);
                DeletaIntervalo(20, 0, 35, 2);
                imprimeMao(*MaoCPU2, 20, 0);
                DeletaIntervalo(0, 25, 15, 28);
                imprimeMao(*MaoCPU3, 0, 25);
            }
            NumeroCartasComecoEFimDeJogoQuatro(*numeroDeCartasBaralho, numeroDeCartasMao, aposZero, pontosCPU1, pontosCPU2, pontosCPU3, pontosJogador, fim, Baralho);
            gotoxy(20, 45);
            gotoxy(55, 39);
            printf("Vez do CPU3!");
            sleep(1);
            break;
    }
}

//ok
//Logica de jogo para mesa de quatro jogadores
void LogicaMesaQuatro(char modoDeJogo, char *comando, TipoBaralho *Baralho, char modoDebug)
{
    int pontosJogador = 0, pontosCPU1 = 0, pontosCPU2 = 0, pontosCPU3 = 0, numeroDeCartasBaralho = 40, numeroDeCartasMao = 3, comeca = 0, monteJ = 0, monteCPU1 = 0, monteCPU2 = 0, monteCPU3 = 0, mesaCPU1, mesaCPU2, mesaCPU3, aposZero = 0, fim = 0, Jogando = 0;
    TipoCarta trunfo, listaMesa[4];
    TipoMao MaoJogador, MaoCPU1, MaoCPU2, MaoCPU3;

    PrimeiraMesaQuatro(&trunfo, &MaoJogador, &MaoCPU1, &MaoCPU2, &MaoCPU3, Baralho, &numeroDeCartasBaralho);

    if(modoDebug == 'q')
    {
        imprimeBaralho (*Baralho, 177, 13);
        imprimeMao(MaoCPU1, 150, 25);
        imprimeMao(MaoCPU2, 20, 0);
        imprimeMao(MaoCPU3, 0, 25);
    }

    gotoxy(60, 42);
    scanf(" %c", comando);

    while (fim != 1 && *comando != 'v')
    {
        switch(comeca)
        {
            case 0:
                defaultMesa(comando, numeroDeCartasMao);
                Jogando = 0;
                listaMesa[0] = SeletorMesa(&MaoJogador, comando, numeroDeCartasMao, 54, 22, Baralho);
                gotoxy(55, 39);
                printf("Vez do CPU1!");
                sleep(1);
                Jogando = 1;
                ModoDeEscolhaCPU(&mesaCPU1, modoDeJogo, MaoCPU1, listaMesa, trunfo, comeca, Jogando, numeroDeCartasMao);
                listaMesa[1] = TiraCartaEPrinta(&MaoCPU1, mesaCPU1, 59, 22, numeroDeCartasMao, 1);
                gotoxy(55, 39);
                printf("Vez do CPU2!");
                sleep(1);
                Jogando = 2;
                ModoDeEscolhaCPU(&mesaCPU2, modoDeJogo, MaoCPU2, listaMesa, trunfo, comeca, Jogando, numeroDeCartasMao);
                listaMesa[2] = TiraCartaEPrinta(&MaoCPU2, mesaCPU2, 64, 22, numeroDeCartasMao, 2);
                gotoxy(55, 39);
                printf("Vez do CPU3!");
                sleep(1);
                Jogando = 3;
                ModoDeEscolhaCPU(&mesaCPU3, modoDeJogo, MaoCPU3, listaMesa, trunfo, comeca, Jogando, numeroDeCartasMao);
                listaMesa[3] = TiraCartaEPrinta(&MaoCPU3, mesaCPU3, 69, 22, numeroDeCartasMao, 3);
                funcComparaQuatro(listaMesa, trunfo, &comeca, &pontosJogador, &pontosCPU1, &pontosCPU2, &pontosCPU3, &monteJ, &monteCPU1, &monteCPU2, &monteCPU3);
                MudaValoresQuatro(numeroDeCartasBaralho, pontosJogador, pontosCPU1, pontosCPU2, pontosCPU3, monteJ, monteCPU1, monteCPU2, monteCPU3);
                sleep(1);
                ProximaRodadaQuatro(comando, modoDebug, Baralho, &MaoJogador, &MaoCPU1, &MaoCPU2, &MaoCPU3, comeca, &numeroDeCartasBaralho, &numeroDeCartasMao, &aposZero, pontosJogador, pontosCPU1, pontosCPU2, pontosCPU3, &fim);
                break;

            case 1:
                Jogando = 1;
                ModoDeEscolhaCPU(&mesaCPU1, modoDeJogo, MaoCPU1, listaMesa, trunfo, comeca, Jogando, numeroDeCartasMao);
                listaMesa[1] = TiraCartaEPrinta(&MaoCPU1, mesaCPU1, 54, 22, numeroDeCartasMao, 1);
                gotoxy(55, 39);
                printf("Vez do CPU2!");
                sleep(1);
                Jogando = 2;
                ModoDeEscolhaCPU(&mesaCPU2, modoDeJogo, MaoCPU2, listaMesa, trunfo, comeca, Jogando, numeroDeCartasMao);
                listaMesa[2] = TiraCartaEPrinta(&MaoCPU2, mesaCPU2, 59, 22, numeroDeCartasMao, 2);
                gotoxy(55, 39);
                printf("Vez do CPU3!");
                sleep(1);
                Jogando = 3;
                ModoDeEscolhaCPU(&mesaCPU3, modoDeJogo, MaoCPU3, listaMesa, trunfo, comeca, Jogando, numeroDeCartasMao);
                listaMesa[3] = TiraCartaEPrinta(&MaoCPU3, mesaCPU3, 64, 22, numeroDeCartasMao, 3);
                gotoxy(55, 39);
                printf("Sua vez!     ");
                DeletaCaracter(60, 42);
                gotoxy(60, 42);
                scanf(" %c", comando);
                defaultMesa(comando, numeroDeCartasMao);
                if(*comando == 'v'){
                    freeBaralho (Baralho);
                    criaBaralho (Baralho);     
                    break;
                }
                Jogando = 0;
                listaMesa[0] = SeletorMesa(&MaoJogador, comando, numeroDeCartasMao, 69, 22, Baralho);
                funcComparaQuatro(listaMesa, trunfo, &comeca, &pontosJogador, &pontosCPU1, &pontosCPU2, &pontosCPU3, &monteJ, &monteCPU1, &monteCPU2, &monteCPU3);
                MudaValoresQuatro(numeroDeCartasBaralho, pontosJogador, pontosCPU1, pontosCPU2, pontosCPU3, monteJ, monteCPU1, monteCPU2, monteCPU3);
                sleep(1);
                ProximaRodadaQuatro(comando, modoDebug, Baralho, &MaoJogador, &MaoCPU1, &MaoCPU2, &MaoCPU3, comeca, &numeroDeCartasBaralho, &numeroDeCartasMao, &aposZero, pontosJogador, pontosCPU1, pontosCPU2, pontosCPU3, &fim);
                break;

            case 2:
                Jogando = 2;
                ModoDeEscolhaCPU(&mesaCPU2, modoDeJogo, MaoCPU2, listaMesa, trunfo, comeca, Jogando, numeroDeCartasMao);
                listaMesa[2] = TiraCartaEPrinta(&MaoCPU2, mesaCPU2, 54, 22, numeroDeCartasMao, 2);
                gotoxy(55, 39);
                printf("Vez do CPU3!");
                sleep(1);
                Jogando = 3;
                ModoDeEscolhaCPU(&mesaCPU3, modoDeJogo, MaoCPU3, listaMesa, trunfo, comeca, Jogando, numeroDeCartasMao);
                listaMesa[3] = TiraCartaEPrinta(&MaoCPU3, mesaCPU3, 59, 22, numeroDeCartasMao, 3);
                gotoxy(55, 39);
                printf("Sua vez!      ");
                DeletaCaracter(60, 42);
                gotoxy(60, 42);
                scanf(" %c", comando);
                defaultMesa(comando, numeroDeCartasMao);
                if(*comando == 'v'){
                    freeBaralho (Baralho);
                    criaBaralho (Baralho);     
                    break;
                }
                Jogando = 0;
                listaMesa[0] = SeletorMesa(&MaoJogador, comando, numeroDeCartasMao, 64, 22, Baralho);
                gotoxy(55, 39);
                printf("Vez do CPU1!");
                sleep(1);
                Jogando = 1;
                ModoDeEscolhaCPU(&mesaCPU1, modoDeJogo, MaoCPU1, listaMesa, trunfo, comeca, Jogando, numeroDeCartasMao);
                listaMesa[1] = TiraCartaEPrinta(&MaoCPU1, mesaCPU1, 69, 22, numeroDeCartasMao, 1);
                funcComparaQuatro(listaMesa, trunfo, &comeca, &pontosJogador, &pontosCPU1, &pontosCPU2, &pontosCPU3, &monteJ, &monteCPU1, &monteCPU2, &monteCPU3);
                MudaValoresQuatro(numeroDeCartasBaralho, pontosJogador, pontosCPU1, pontosCPU2, pontosCPU3, monteJ, monteCPU1, monteCPU2, monteCPU3);
                sleep(1);
                ProximaRodadaQuatro(comando, modoDebug, Baralho, &MaoJogador, &MaoCPU1, &MaoCPU2, &MaoCPU3, comeca, &numeroDeCartasBaralho, &numeroDeCartasMao, &aposZero, pontosJogador, pontosCPU1, pontosCPU2, pontosCPU3, &fim);
                break;

            case 3:
                Jogando = 3;
                ModoDeEscolhaCPU(&mesaCPU3, modoDeJogo, MaoCPU3, listaMesa, trunfo, comeca, Jogando, numeroDeCartasMao);
                listaMesa[3] = TiraCartaEPrinta(&MaoCPU3, mesaCPU3, 54, 22, numeroDeCartasMao, 3);
                gotoxy(55, 39);
                printf("Sua vez!      ");
                DeletaCaracter(60, 42);
                gotoxy(60, 42);
                scanf(" %c", comando);
                defaultMesa(comando, numeroDeCartasMao);
                if(*comando == 'v'){
                    freeBaralho (Baralho);
                    criaBaralho (Baralho);     
                    break;
                }
                Jogando = 0;
                listaMesa[0] = SeletorMesa(&MaoJogador, comando, numeroDeCartasMao, 59, 22, Baralho);
                gotoxy(55, 39);
                printf("Vez do CPU1!");
                sleep(1);
                Jogando = 1;
                ModoDeEscolhaCPU(&mesaCPU1, modoDeJogo, MaoCPU1, listaMesa, trunfo, comeca, Jogando, numeroDeCartasMao);
                listaMesa[1] = TiraCartaEPrinta(&MaoCPU1, mesaCPU1, 64, 22, numeroDeCartasMao, 1);
                gotoxy(55, 39);
                printf("Vez do CPU2!");
                sleep(1);
                Jogando = 2;
                ModoDeEscolhaCPU(&mesaCPU2, modoDeJogo, MaoCPU2, listaMesa, trunfo, comeca, Jogando, numeroDeCartasMao);
                listaMesa[2] = TiraCartaEPrinta(&MaoCPU2, mesaCPU2, 69, 22, numeroDeCartasMao, 2);
                funcComparaQuatro(listaMesa, trunfo, &comeca, &pontosJogador, &pontosCPU1, &pontosCPU2, &pontosCPU3, &monteJ, &monteCPU1, &monteCPU2, &monteCPU3);
                MudaValoresQuatro(numeroDeCartasBaralho, pontosJogador, pontosCPU1, pontosCPU2, pontosCPU3, monteJ, monteCPU1, monteCPU2, monteCPU3);
                sleep(1);
                ProximaRodadaQuatro(comando, modoDebug, Baralho, &MaoJogador, &MaoCPU1, &MaoCPU2, &MaoCPU3, comeca, &numeroDeCartasBaralho, &numeroDeCartasMao, &aposZero, pontosJogador, pontosCPU1, pontosCPU2, pontosCPU3, &fim);
                break;
            }    
    }

    if(fim == 1)
    {
        gotoxy(40, 42);
        printf("Escolha 'v' para ir para o menu : ");
        scanf(" %c", comando);
    } 
}

//*************************FUNÇOES MENU **************************************//

//ok
//Se o valor nao e uma das opcoes dadas no menu
void defaultMenu(char *comando){
    gotoxy(40, 40);
    printf("Nao e possivel executar tal comando!\n");
    gotoxy(40, 41);
    printf("Escolha outra opcao : ");
    scanf(" %c", comando);
    DeletaIntervalo(40, 40, 115, 41);
}

//ok
//Printa o menu de quntidade de jogadores
void menuQuantidadeDeJogadores(char *comando){
    DeletaIntervalo(26, 20, 132, 36);
    gotoxy(40,23);
    printf("                          o \u25BA 2\n ");
    gotoxy(40,24);
    printf("                          p \u25BA 4\n ");
    gotoxy(26, 38);
    printf("v \u25BA Voltar");
    gotoxy(40, 39);
    printf("Escolha sua opcao : ");
    scanf(" %c", comando);
}

//ok
//Printa v -> voltar e deleta o caracter escolhido antes
void PrintVoltarEDeletaCaracter(char *comando){
    gotoxy(26, 38);
    printf("v \u25BA Voltar");
    DeletaCaracter(60, 39);
    gotoxy(60, 39);
    scanf(" %c", comando);
}

//ok 
//Printa a parte de fora do menu principal
void PrintMenuFora(){

    int i, j;
    system("clear");
    gotoxy(0, 6);
    printf("                \u250C");//Quina esquerda superior
    for(i = 0; i<=130; i++){
        printf("\u2500");//Meio
    }
    printf("\u2510");//Quina direita superior
    gotoxy(0, 7);
    for(j = 0; j <= 30; j++){
        printf("                \u2502");//Lado
        for(i = 0; i<=130; i++){
            printf(" ");
        }
        printf("\u2502\n");//Lado
    }
    gotoxy(0, 37);
    printf("                \u2514");//Quina esquerda baixo
    for(i = 0; i<=130; i++){
        printf("\u2500");//Meio
    }
    printf("\u2518");//Quina direita baixo
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    gotoxy(0, 0);
    gotoxy(40,9);
    printf("    8 888888888o    8 8888    d888888o.       ,o888888o.             .8.\n");
    gotoxy(40,10);      
    printf("    8 8888    `88.  8 8888  .`8888:' `88.    8888     `88.          .888.\n");     
    gotoxy(40,11);    
    printf("    8 8888     `88  8 8888  8.`8888.   Y8 ,8 8888       `8.        :88888.\n");        
    gotoxy(40,12);
    printf("    8 8888     ,88  8 8888  `8.`8888.     88 8888                 . `88888.\n");  
    gotoxy(40,13);     
    printf("    8 8888.   ,88'  8 8888   `8.`8888.    88 8888                .8. `88888.\n");      
    gotoxy(40,14);
    printf("    8 8888888888    8 8888    `8.`8888.   88 8888               .8`8. `88888.\n");  
    gotoxy(40,15);   
    printf("    8 8888    `88.  8 8888     `8.`8888.  88 8888              .8' `8. `88888.\n");  
    gotoxy(40,16);  
    printf("    8 8888      88  8 8888 8b   `8.`8888. `8 8888       .8'   .8'   `8. `88888.\n");  
    gotoxy(40,17); 
    printf("    8 8888    ,88'  8 8888 `8b.  ;8.`8888    8888     ,88'   .888888888. `88888.\n");  
    gotoxy(40,18);
    printf("    8 888888888P    8 8888  `Y8888P ,88P'     `8888888P'    .8'       `8. `88888.\n");
    
}

//ok 
//Printa o menu principal
void PrintMenuConteudoPrincipal(){
    gotoxy(42,25);
    printf("                          a \u25BA Mostrar Cartas\n ");
    gotoxy(42,26);
    printf("                          b \u25BA Embaralhar\n ");
    gotoxy(42,27);
    printf("                          c \u25BA Cortar\n ");
    gotoxy(42,28);
    printf("                          d \u25BA Modo de Jogo\n ");
    gotoxy(42,29);
    printf("                          s \u25BA Sair\n ");
}

//ok
//Switch do menu principal
void SeletorMenuPrincipal(){
    TipoBaralho Baralho;
    TipoCarta trunfo1;
    char modoDebug, escolha, *comando;
    comando = &escolha;

    PrintMenuFora();
    criaBaralho (&Baralho);
    PrintMenuConteudoPrincipal();
    gotoxy(40, 39);
    printf("Escolha sua opcao : ");
    scanf(" %c", comando);
    while(*comando != 's'){
        switch (*comando){
            //Mostrar Cartas
            case 'a':
                DeletaIntervalo(26, 20, 132, 36);
                MostrarBaralho(26, 20, Baralho);
                PrintVoltarEDeletaCaracter(comando);
                while (*comando != 'v' && *comando != 's'){
                    defaultMenu( comando);
                }
                
                break;
            //Funcao Embaralhar
            case 'b':
                DeletaIntervalo(26, 20, 132, 36);
                MostrarBaralho(26, 20, Baralho);
                sleep(3);
                DeletaIntervalo(18, 20, 137, 36);
                sleep(2);
                embaralha (&Baralho);
                MostrarBaralho(26, 20, Baralho);
                PrintVoltarEDeletaCaracter(comando);
                while (*comando != 'v' && *comando != 's'){
                    defaultMenu( comando);
                }
                break;
            //Funcao Cortar
            case 'c':
                DeletaIntervalo(26, 20, 132, 36);
                MostrarBaralho(26, 20, Baralho);
                sleep(3);
                DeletaIntervalo(18, 20, 137, 36);
                sleep(2);
                corta(&Baralho, &trunfo1);
                MostrarBaralho(26, 20, Baralho);
                PrintVoltarEDeletaCaracter(comando);
                while (*comando != 'v' && *comando != 's'){
                    defaultMenu( comando);
                }
                break;
            //Modo de Jogo
            case 'd':
                DeletaIntervalo(26, 20, 132, 36);
                gotoxy(40,23);
                printf("                          Modo Debug ? (q/n)\n ");
                PrintVoltarEDeletaCaracter(&modoDebug);
                if(modoDebug == 'v'){     
                    break;
                }
                DeletaIntervalo(26, 20, 132, 36);
                gotoxy(40,23);
                printf("                          e \u25BA Burrice Artificial\n ");
                gotoxy(40,24);
                printf("                          h \u25BA Inteligencia Artificial\n ");
                PrintVoltarEDeletaCaracter(comando);
                while (*comando != 'v' && *comando != 's'){
                    switch (*comando){
                        //Nivel Facil
                        case 'e':
                            menuQuantidadeDeJogadores(comando);
                            while(*comando != 's' && *comando != 'v'){
                                switch (*comando){
                                    //Dois Jogadores
                                    case 'o':
                                        LogicaMesaDois('e', comando, &Baralho, modoDebug);
                                        DeletaIntervalo(0, 0, 250, 50);
                                        if(*comando == 'v'){     
                                            break;
                                        }
                                        break;
                                    //Quatro Jogadores
                                    case 'p':
                                        LogicaMesaQuatro('e', comando, &Baralho, modoDebug);
                                        DeletaIntervalo(0, 0, 250, 50);
                                        if(*comando == 'v'){     
                                            break;
                                        }
                                        break;
                                                                        
                                    default:
                                        defaultMenu( comando);
                                        break;
                                }
                            }
                            break;
                        //Nivel Dificil
                        case 'h':
                            menuQuantidadeDeJogadores(comando);
                            while(*comando != 's' && *comando != 'v'){
                                switch (*comando){
                                    //Dois Jogadores
                                    case 'o':
                                        LogicaMesaDois('h', comando, &Baralho, modoDebug);
                                        DeletaIntervalo(0, 0, 250, 50);
                                        if(*comando == 'v'){     
                                            break;
                                        }
                                        break;
                                    //Quatro Jogadores
                                    case 'p':
                                        LogicaMesaQuatro('h', comando, &Baralho, modoDebug);
                                        DeletaIntervalo(0, 0, 250, 50);
                                        if(*comando == 'v'){     
                                            break;
                                        }
                                        break;
                                                                        
                                    default:
                                        defaultMenu( comando);
                                        break;
                                }
                            }
                            break;
                        
                        default:
                            defaultMenu( comando);
                            break;
                    }
                }
                break;
            //Voltar
            case 'v':
                DeletaLinha(26, 38, 36);
                DeletaIntervalo(18, 20, 137, 36);
                PrintMenuFora();
                PrintMenuConteudoPrincipal();
                DeletaCaracter(60, 39);
                gotoxy(40, 39);
                printf("Escolha sua opcao : ");
                scanf(" %c", comando);
                break;
            //Sair
            case 's':
                freeBaralho (&Baralho);
                break;          

            default:
                defaultMenu( comando);
                break;
        }
    }
    freeBaralho (&Baralho);
}