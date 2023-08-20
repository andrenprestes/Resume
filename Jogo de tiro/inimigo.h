#ifndef INIMIGO_H
#define	INIMIGO_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <iostream>
#include "plataforma.h"
#include "tiro.h"

# define M_PI           3.14159265358979323846  /* pi */

// Proporções
#define pernaHeight 0.2 // Os dois segmentos da perna correspondem a 40% da altura; o braço tem as mesmas proporções dos segmentos das pernas
#define pernaWidth 0.2 // 20% da largura do tronco
#define troncoHeight 0.40 // 30% da altura
#define troncoWidth 1.00 // Considerar o diâmetro da cabeça como largura do tronco
#define radiusHead 0.10 // 20% da altura = diâmetro da cabeça

class Inimigo {
    GLfloat gX; 
    GLfloat gY; 
    GLfloat gZ; 
    GLfloat altura;

    GLfloat safeX;
    GLfloat safeY;
    
    GLfloat bracoTheta; 
    GLfloat pernaTheta1; 
    GLfloat pernaTheta2; 
    GLfloat troncoTheta;
    
    int dir;
    GLfloat direction;

    GLfloat limLeft;
    GLfloat limRight;

    GLuint textureLeg;
    GLuint textureArm;
    GLuint textureHead;
    GLuint textureBody;
    GLuint textureGun;

private: 
    void DesenhaRect(  GLfloat width, GLfloat height, GLfloat length, 
                    GLfloat R, GLfloat G, GLfloat B, GLuint texture);
    void DesenhaRectOrigin(  GLfloat width, GLfloat height, 
                    GLfloat R, GLfloat G, GLfloat B);
    void DesenhaCirc(  GLfloat radius, GLfloat R, 
                    GLfloat G, GLfloat B);
    void DesenhaCabeca(GLfloat x, GLfloat y, GLfloat z,
                    GLfloat R, GLfloat G, GLfloat B);
    void DesenhaBraco(   GLfloat x, GLfloat y, GLfloat z, GLfloat bracoTheta, int lado);
    void DesenhaPerna(   GLfloat x, GLfloat y, GLfloat z, GLfloat pernaTheta1);
    void DesenhaInimigo( GLfloat x, GLfloat y, GLfloat z, GLfloat theta1, GLfloat theta2, GLfloat theta3);
    void DesenhaArma(double size);

public:
    Inimigo(GLfloat gX, GLfloat gY, GLfloat altura){
        this->gX = gX; 
        this->gY = gY; 
        this->gZ = 0; 
        this->altura = altura;

        safeX = gX;
        safeY = gY;

        bracoTheta = 0; 
        pernaTheta1 = -180; 
        pernaTheta2 = -180; 
        troncoTheta = 0;

        dir = 1;
        direction = 1;

        limLeft = -1;
        limRight = -1;
    };
    void Desenha(){ 
        DesenhaInimigo(gX, gY, gZ, bracoTheta, pernaTheta1, pernaTheta2);
    };
    void setTextures(GLuint textureLeg, GLuint textureArm, GLuint textureHead, GLuint textureBody, GLuint textureGun){
        this->textureLeg = textureLeg;
        this->textureArm = textureArm;
        this->textureHead = textureHead;
        this->textureBody = textureBody;
        this->textureGun = textureGun;
    };
    
    void ColisaoBordas();
    void RotatePoint(GLfloat x, GLfloat y, GLfloat angle, GLfloat &xOut, GLfloat &yOut);
    void Move(GLfloat dx, GLfloat dy);
    void Aiming(float x, float y, float z);
    Tiro* Atira(GLfloat jogadorX, GLfloat jogadorY, GLfloat jogadorZ);
    void DetectaColisao(Inimigo* i);
    void DetectaColisao( Plataforma p, float viewHeight);
    bool DetectaColisao(Tiro* t);
    void ChangeDir(){
        troncoTheta += 90;
    };
    void SafeX(){
        gX = safeX;
    };
    void SafeY(){
        gY = safeY;
    };
    GLfloat ObtemYBase(){
        return gY - (pernaHeight * altura * 2.0);
    };
    GLfloat ObtemAltura(){
        return altura;
    };
    GLfloat ObtemLargura(){
        return radiusHead*altura;
    };
    GLfloat ObtemX(){
        return gX;
    };
    GLfloat ObtemY(){
        return gY;
    };
    GLfloat ObtemZ(){
        return gZ;
    };
    void incAngulo(int inc){
        troncoTheta+=inc;
    };
};

#endif	/* INIMIGO_H */
