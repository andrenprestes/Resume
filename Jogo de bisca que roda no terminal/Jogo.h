#include "Cartas.h"

void PrintMesaFora();

void defaultMesa(char *comando, int numeroDeCartasMao);

TipoCarta SeletorMesa(TipoMao *MaoJogador, char *comando, int numeroDeCartasMao, int x, int y, TipoBaralho *Baralho);

void PrintYOUWIN(int *fim, TipoBaralho *Baralho);

void PrintYOULOSE(int *fim, TipoBaralho *Baralho);

void MaiorMao(TipoMao Mao, TipoCarta trunfo, TipoCarta *listaMesa, int comeca, int *maiorCarta, int numeroDeCartasMao);

void MenorMao(TipoMao Mao, TipoCarta trunfo, int *menorCarta, int numeroDeCartasMao);

void ModoFacil(int *mesaCPU, int numeroDeCartasMao);

void ModoDificil(int *mesaCPU, TipoMao MaoCPU, TipoCarta *listaMesa, TipoCarta trunfo, int comeca, int Jogando, int numeroDeCartasMao);

void ModoDeEscolhaCPU(int *mesaCPU, char modoDeJogo, TipoMao MaoCPU, TipoCarta *listaMesa, TipoCarta trunfo, int comeca, int Jogando, int numeroDeCartasMao);

void NumeroCartasComecoEFimDeJogoDois(int numeroDeCartasBaralho, int *numeroDeCartasMao, int *aposZero, int pontosCPU, int pontosJogador, int *fim, TipoBaralho *Baralho);

void MudaValoresDois(int numeroDeCartasBaralho, int pontosJogador, int pontosCPU, int monteJ, int monteCPU);

void PrimeiraMesaDois(TipoCarta *trunfo, TipoMao *MaoJogador, TipoMao *MaoCPU2, TipoBaralho *Baralho, int *numeroDeCartasBaralho);

void ProximaRodadaDois(char *comando, char modoDebug, TipoBaralho *Baralho, TipoMao *MaoJogador, TipoMao *MaoCPU2, int comeca, int *numeroDeCartasBaralho, int *numeroDeCartasMao, int *aposZero, int pontosJogador, int pontosCPU, int *fim);

void LogicaMesaDois(char modoDeJogo, char *comando, TipoBaralho *Baralho, char modoDebug);

void NumeroCartasComecoEFimDeJogoQuatro(int numeroDeCartasBaralho, int *numeroDeCartasMao, int *aposZero, int pontosCPU1, int pontosCPU2, int pontosCPU3, int pontosJogador, int *fim, TipoBaralho *Baralho);

void MudaValoresQuatro(int numeroDeCartasBaralho, int pontosJogador, int pontosCPU1, int pontosCPU2, int pontosCPU3, int monteJ, int monteCPU1, int monteCPU2, int monteCPU3);

void PrimeiraMesaQuatro(TipoCarta *trunfo, TipoMao *MaoJogador, TipoMao *MaoCPU1, TipoMao *MaoCPU2, TipoMao *MaoCPU3, TipoBaralho *Baralho, int *numeroDeCartasBaralho);

void ProximaRodadaQuatro(char *comando, char modoDebug, TipoBaralho *Baralho, TipoMao *MaoJogador, TipoMao *MaoCPU1, TipoMao *MaoCPU2, TipoMao *MaoCPU3, int comeca, int *numeroDeCartasBaralho, int *numeroDeCartasMao, int *aposZero, int pontosJogador, int pontosCPU1, int pontosCPU2, int pontosCPU3, int *fim);

void LogicaMesaQuatro(char modoDeJogo, char *comando, TipoBaralho *Baralho, char modoDebug);

void defaultMenu(char *comando);

void menuQuantidadeDeJogadores(char *comando);

void PrintVoltarEDeletaCaracter(char *comando);

void PrintMenuFora();

void PrintMenuConteudoPrincipal();

void SeletorMenuPrincipal();