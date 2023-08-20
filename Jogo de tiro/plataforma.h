#ifndef PLATAFORMA_H
#define	PLATAFORMA_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

class Plataforma {
    GLfloat gX; 
    GLfloat gY; 
    GLfloat gZ;
    GLfloat height;
    GLfloat width;
    GLfloat length;
    GLuint texture;

private: 
    void DesenhaRect(  GLfloat width, GLfloat height, int numX, int numY, int numZ, 
                    GLfloat R, GLfloat G, GLfloat B);
    void DesenhaPlataforma( GLfloat x, GLfloat y);

public:
    bool colisao;
    Plataforma(){
        gX = 0; 
        gY = 0; 
        gZ = 0; 
        height = 0;
        width = 0; 
        length = 0;
        colisao = true;
    };
    void confInicial(GLfloat gX, GLfloat gY, GLfloat gZ, GLfloat height, GLfloat width, GLuint texture);
    void Desenha(){ 
        DesenhaPlataforma(gX, gY);
    };
    GLfloat ObtemX(){
        return gX;
    };
    GLfloat ObtemY(){
        return gY;
    };
    GLfloat ObtemLargura(){
        return width;
    };
    GLfloat ObtemAltura(){
        return height;
    };
    void setLength(GLfloat Length){
        length = Length;
    };
    void disableColisao(){
        colisao = false;
    };
};

#endif	/* PLATAFORMA_H */