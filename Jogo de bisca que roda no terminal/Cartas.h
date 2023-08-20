#ifndef LISTAENC_H_
#define LISTAENC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define inicioLista 1
#define maxTamMao 3
#define maxTamMesa 4

typedef struct 
{
    char id;
    char naipe;
    int valor;
    int posicao;

} TipoCarta;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula{
  TipoCarta Carta;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;
} TipoBaralho;

typedef struct
{
    TipoCarta cartasJogador[maxTamMao];
    int Primeiro, ultimo;

} TipoMao;

void gotoxy(int x,int y);

void DeletaIntervalo(int x1, int y1, int x2, int y2);

void DeletaCaracter(int x, int y);

void DeletaLinha(int x, int y, int x1);

void PrintVerso( char sentido, int x, int y);

void PrintCartaFrente(TipoCarta Carta ,int x, int y);

void MostrarBaralho(int x, int y, TipoBaralho Baralho);

void FLVazia(TipoBaralho *Baralho);

int Vazia(TipoBaralho Baralho);

void InsereBaralho(TipoCarta x, TipoBaralho *Baralho);

void criaBaralho (TipoBaralho *Baralho);

TipoCarta retiraBaralho (TipoBaralho *Baralho, int posicao);

void embaralha (TipoBaralho *Baralho);

void corta(TipoBaralho *Baralho, TipoCarta *trunfo);

void imprimeBaralho (TipoBaralho Baralho, int x, int y);

void freeBaralho (TipoBaralho *Baralho);

int verificaVaziaMao (TipoMao Mao);

void tornaVaziaMao (TipoMao *Mao);

void compraCarta (TipoMao *mao, TipoBaralho *Baralho);

TipoCarta retiraCartaMao (TipoMao *Mao, int Mesa);

void imprimeMao(TipoMao mao, int x, int y);

TipoCarta TiraCartaEPrinta(TipoMao *Mao, int mesa, int x, int y, int numeroDeCartasMao, int jogador);

void RecebeCarta (TipoMao *Mao, TipoBaralho *Baralho, int *numeroDeCartasBaralho);

void DistribuiCartasPrimeiraRodadaDois(TipoMao *MaoJogador, TipoMao *MaoCPU2, TipoBaralho *Baralho, int *numeroDeCartasBaralho);

void DarCartaPeloJogadorDois(TipoMao *MaoJogador, TipoMao *MaoCPU2, TipoBaralho *Baralho, int *numeroDeCartasBaralho, int aposZero);

void DarCartaPeloCPUDois(TipoMao *MaoJogador, TipoMao *MaoCPU2, TipoBaralho *Baralho, int *numeroDeCartasBaralho, int aposZero);

int maior(TipoCarta *lista, int t, int *posi);

int achaTrunfosECompara(TipoCarta *listaMesa, TipoCarta trunfo, int numeroDeJogadores);

int naipesIguaisAoPrimeiro(TipoCarta *listaMesa, int numeroDeJogadores, int comeca);

void funcComparaDois(TipoCarta *listaMesa, TipoCarta trunfo, int *comeca, int *pontosJogador, int *pontosCPU, int *monteJ, int *monteCPU);

void funcComparaQuatro(TipoCarta *listaMesa, TipoCarta trunfo, int *comeca, int *pontosJogador, int *pontosCPU1, int *pontosCPU2, int *pontosCPU3, int *monteJ, int *monteCPU1, int *monteCPU2, int *monteCPU3);

void DistribuiCartasPrimeiraRodadaQuatro(TipoMao *MaoJogador, TipoMao *MaoCPU1, TipoMao *MaoCPU2, TipoMao *MaoCPU3, TipoBaralho *Baralho, int *numeroDeCartasBaralho);

void DarCartaPeloJogadorQuatro(TipoMao *MaoJogador, TipoMao *MaoCPU1, TipoMao *MaoCPU2, TipoMao *MaoCPU3, TipoBaralho *Baralho, int *numeroDeCartasBaralho, int aposZero);

void DarCartaPeloCPU1Quatro(TipoMao *MaoJogador, TipoMao *MaoCPU1, TipoMao *MaoCPU2, TipoMao *MaoCPU3, TipoBaralho *Baralho, int *numeroDeCartasBaralho, int aposZero);

void DarCartaPeloCPU2Quatro(TipoMao *MaoJogador, TipoMao *MaoCPU1, TipoMao *MaoCPU2, TipoMao *MaoCPU3, TipoBaralho *Baralho, int *numeroDeCartasBaralho, int aposZero);

void DarCartaPeloCPU3Quatro(TipoMao *MaoJogador, TipoMao *MaoCPU1, TipoMao *MaoCPU2, TipoMao *MaoCPU3, TipoBaralho *Baralho, int *numeroDeCartasBaralho, int aposZero);

#endif /* LISTAENC_H_ */