#include "tiro.h"
#define DISTANCIA_MAX 500

void Tiro::DesenhaCirc(GLfloat radius, GLfloat R, GLfloat G, GLfloat B)
{
    GLfloat materialEmission[] = { 0.00, 0.00, 0.00, 1.0};
    GLfloat materialColor[] = { R, G, B, 1.0};
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = { 128 };
    glMaterialfv(GL_FRONT, GL_EMISSION, materialEmission);
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialColor);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glColor3f(R,G,B);
    glutSolidSphere(radius, 100, 100);
}

void Tiro::DesenhaTiro(GLfloat x, GLfloat y, GLfloat z)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    DesenhaCirc(radiusTiro, 0.0, 0.0, 1.0);
    glPopMatrix();
}

void Tiro::Move(GLdouble gVel, GLdouble timeDiference)
{
    gY += gVel * timeDiference * sin(gDirectionAng);
    GLfloat A = gVel * timeDiference * cos(gDirectionAng);
    
    if (theta >= 0 && theta < 90){
        gX += A*cos((theta) * M_PI / 180.0);
        gZ += A*sin((theta) * M_PI / 180.0)*-1;
    }

    else if (theta >= 90 && theta < 180)
    {
        gX += A*cos((180-theta) * M_PI / 180.0)*-1;
        gZ += A*sin((180-theta) * M_PI / 180.0)*-1;
    }

    else if (theta >= 180 && theta < 270)
    {
        gX += A*cos((theta-180) * M_PI / 180.0)*-1;
        gZ += A*sin((theta-180) * M_PI / 180.0);
    }

    else
    {
        gX += A*cos((360-theta) * M_PI / 180.0);
        gZ += A*sin((360-theta) * M_PI / 180.0);
    }
}

bool Tiro::Valido(GLfloat ViewingHeight)
{
    return ((DISTANCIA_MAX > sqrt(pow(gX-gXInit,2)+pow(gY-gYInit,2))) && (gZ < ViewingHeight/4 && gZ > -ViewingHeight/4));
}   

bool Tiro::DetectaColisao(Plataforma p)
{
    // Colisão no eixo X
    bool colisaoX = gX + radiusTiro >= p.ObtemX() && p.ObtemX() + p.ObtemLargura() >= gX - radiusTiro;
    // Colisão no eixo Y
    bool colisaoY = gY + radiusTiro >= p.ObtemY() && p.ObtemY() + p.ObtemAltura() >= gY - radiusTiro;
    
    
    // Colisão ocorreu
    return colisaoX && colisaoY;
}