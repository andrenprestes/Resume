#ifndef JOGADOR_H
#define	JOGADOR_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "plataforma.h"
#include "tiro.h"
#include "inimigo.h"

# define M_PI           3.14159265358979323846  /* pi */

// Proporções
#define pernaHeight 0.2 // Os dois segmentos da perna correspondem a 40% da altura; o braço tem as mesmas proporções dos segmentos das pernas
#define pernaWidth 0.2 // 20% da largura do tronco
#define troncoHeight 0.40 // 40% da altura
#define troncoWidth 1.00 // Considerar o diâmetro da cabeça como largura do tronco
#define radiusHead 0.10 // 20% da altura = diâmetro da cabeça

class Jogador {
    GLfloat gX; 
    GLfloat gY; 
    GLfloat gZ; 
    GLfloat safeX;
    GLfloat safeY;
    GLfloat safeZ; 
    GLfloat altura;

    GLfloat bracoTheta; 
    GLfloat pernaTheta1; 
    GLfloat pernaTheta2;
    GLfloat troncoTheta;

    int dir;
    GLfloat direction;
    GLdouble inicioPulo;
    bool pulando;
    bool podePular;

    GLuint textureLeg;
    GLuint textureArm;
    GLuint textureHead;
    GLuint textureBody;
    GLuint textureGun;

private: 
    void DesenhaRectOrigin(  GLfloat width, GLfloat height, 
                    GLfloat R, GLfloat G, GLfloat B);
    void DesenhaCirc(  GLfloat radius, GLfloat R, 
                    GLfloat G, GLfloat B);
    void DesenhaRect(  GLfloat width, GLfloat height, GLfloat length, 
                    GLfloat R, GLfloat G, GLfloat B, GLuint texture);
    void DesenhaCabeca(GLfloat x, GLfloat y, GLfloat z,
                    GLfloat R, GLfloat G, GLfloat B);
    void DesenhaBraco(   GLfloat x, GLfloat y, GLfloat z, GLfloat bracoTheta, int lado);
    void DesenhaPerna(   GLfloat x, GLfloat y, GLfloat z, GLfloat pernaTheta1);
    void DesenhaJogador( GLfloat x, GLfloat y, GLfloat z, GLfloat theta1, GLfloat theta2, GLfloat theta3, GLfloat troncoTheta);

public:
    Jogador(){
        gX = 0; 
        gY = -200; 
        gZ = 0;
        safeX = 0;
        safeY = - 200;
        safeZ = 0;

        bracoTheta = 0; 
        pernaTheta1 = -180; 
        pernaTheta2 = -180; 
        troncoTheta = 0;

        dir = 1;
        direction = 1;
        pulando = false;
        inicioPulo = -1;
        podePular = false;
    };
    void Desenha(){ 
        DesenhaJogador(gX, gY, gZ, bracoTheta, 
                pernaTheta1, pernaTheta2, troncoTheta);
    };
    void setTextures(GLuint textureLeg, GLuint textureArm, GLuint textureHead, GLuint textureBody, GLuint textureGun){
        this->textureLeg = textureLeg;
        this->textureArm = textureArm;
        this->textureHead = textureHead;
        this->textureBody = textureBody;
        this->textureGun = textureGun;
    };

    void confInicial(GLfloat gX, GLfloat gY, GLfloat altura);
    void Move(GLfloat dx);
    void MoveEmY(GLfloat dy, int mouseDownm, GLdouble currentTime);
    void Aiming( int x, int y );
    Tiro* Atira();
    bool PodePular(Plataforma p);
    bool PodePular(Inimigo* i);
    void DetectaColisao( Plataforma p , float viewHeight);
    bool DetectaColisao( Tiro* t );
    void DetectaColisao( Inimigo* i );
    void RotatePoint(GLfloat x, GLfloat y, GLfloat angle, GLfloat &xOut, GLfloat &yOut);
    void DesenhaArma(double size);
    bool Venceu(GLfloat xArena){
        return gX + radiusHead*altura*2 >= xArena;
    };
    bool getPodePular(){
        return this->podePular;
    };
    bool getPulando(){
        return this->pulando;
    };
    GLfloat getAnguloBraco(){
        return this->bracoTheta;
    };
    void setPodePular(bool podePular){
        this->podePular = podePular;
    }
    void setPulando(bool pulando){
        this->pulando = pulando;
    }
    GLfloat ObtemX(){
        return gX;
    };
    GLfloat ObtemY(){
        return gY;
    };
    GLfloat ObtemZ(){
        return gZ;
    };
    GLfloat ObtemDirection(){
        return direction;
    };
    GLfloat ObtemOlhar(){
        return pernaHeight*this->altura;
    };
    GLfloat ObtemAlturaTronco(){
        return 0.2*this->altura;
    };
    GLfloat ObteOmbroDireito(){
        return (troncoWidth*(radiusHead*this->altura*2)/2)*0.8;
    };
    GLfloat ObteTamanhoBraco(){
        return pernaHeight * this->altura*1.9;
    };
    GLfloat ObtemAnguloTronco(){
        return this->troncoTheta;
    };
    GLfloat ObtemAltura(){
        return this->altura;
    };
    GLfloat ObtemRaioCabeca(){
        return radiusHead*this->altura;
    };
    void incAngulo(int inc){
        troncoTheta+=inc;
    };
    void incAnguloBraco(int inc){
        bracoTheta+=inc;
    };
};

#endif	/* JOGADOR_H */
