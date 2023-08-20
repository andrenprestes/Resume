#ifndef TIRO_H
#define	TIRO_H
#include <GL/gl.h>
#include <GL/glu.h>
#include "plataforma.h"

#include <math.h>
#include <stdio.h>

#define radiusT 0.5

class Tiro {
    GLfloat gXInit; 
    GLfloat gYInit; 
    GLfloat gZInit; 
    GLfloat gX; 
    GLfloat gY; 
    GLfloat gZ; 
    GLfloat gDirectionAng;
    GLdouble theta;
    GLfloat gVel;
    GLfloat radiusTiro;
private:
    void DesenhaCirc(GLfloat radius, GLfloat R, GLfloat G, GLfloat B);
    void DesenhaTiro(GLfloat x, GLfloat y, GLfloat z);
public:
    Tiro(GLfloat x, GLfloat y, GLfloat z, GLfloat directionAng, GLdouble Theta, GLfloat radius){
        gXInit = x; 
        gYInit = y; 
        gZInit = z; 
        gX = x; 
        gY = y; 
        gZ = z; 
        gDirectionAng = directionAng; 
        theta = Theta;
        gVel = 0.1;
        radiusTiro = radiusT;
    };
    void Desenha(){ 
        DesenhaTiro(gX, gY, gZ);
    };

    bool DetectaColisao(Plataforma p);
    void Move(GLdouble gVel, GLdouble timeDiference);
    bool Valido(GLfloat ViewingHeight);
    void GetRadius(GLfloat &radiusOut){
        radiusOut = radiusTiro;
    };
    void GetPos(GLfloat &xOut, GLfloat &yOut, GLfloat &zOut){
        xOut = gX;
        yOut = gY;
        zOut = gZ;
    };
};

#endif	/* TIRO_H */

