#include "plataforma.h"
#include <iostream>

void Plataforma::confInicial(GLfloat gX, GLfloat gY, GLfloat gZ, GLfloat height, GLfloat width, GLuint texture)
{
    this->gX = gX;
    this->gY = gY;
    this->gZ = gZ;
    this->height = height;
    this->width = width;
    this->texture = texture;
}

void Plataforma::DesenhaRect(GLfloat width, GLfloat height, int numX, int numY, int numZ, GLfloat R, GLfloat G, GLfloat B)
{
    GLfloat materialEmission[] = { 0.00, 0.00, 0.00, 1.0};
    GLfloat materialColor[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 0.6};
    GLfloat mat_shininess[] = { 128 };
    glMaterialfv(GL_FRONT, GL_EMISSION, materialEmission);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT  );//X
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );//Y

    glBindTexture (GL_TEXTURE_2D, texture);
    double textureS = 1; // Bigger than 1, repeat

    if (texture == 1)
        textureS = 0.5; 

    if (texture == 2)
        textureS = 1; 

    if (texture == 3)
        textureS = 1.5; 

    float sizex = width/numX;
    float sizey = height/numY;
    float sizez = length/numZ;

    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
        // Top face 
        for (int i = 0; i < numX; i++){
            for (int j = 0; j < numZ; j++){
                glNormal3f(0,1,0);
                glTexCoord2f (textureS, textureS);
                glVertex3f(-width/2+sizex*i, height/2, -length/2+sizez*j);
                glNormal3f(0,1,0);
                glTexCoord2f (0, textureS);
                glVertex3f(-width/2+sizex*i, height/2, -length/2+sizez*(j+1));
                glNormal3f(0,1,0);
                glTexCoord2f (0, 0);
                glVertex3f(-width/2+sizex*(i+1), height/2, -length/2+sizez*(j+1));
                glNormal3f(0,1,0);
                glTexCoord2f (textureS, 0);
                glVertex3f(-width/2+sizex*(i+1), height/2, -length/2+sizez*j);
            }
        }
        
        //Bottom face
        for (int i = 0; i < numX; i++){
            for (int j = 0; j < numZ; j++){
                glNormal3f(0,-1,0);
                glTexCoord2f (textureS, textureS);
                glVertex3f(-width/2+sizex*i, -height/2, -length/2+sizez*j);
                glNormal3f(0,-1,0);
                glTexCoord2f (0, textureS);
                glVertex3f(-width/2+sizex*(i+1), -height/2, -length/2+sizez*j);
                glNormal3f(0,-1,0);
                glTexCoord2f (0, 0);
                glVertex3f(-width/2+sizex*(i+1), -height/2, -length/2+sizez*(j+1));
                glNormal3f(0,-1,0);
                glTexCoord2f (textureS, 0);
                glVertex3f(-width/2+sizex*i, -height/2, -length/2+sizez*(j+1));
            }
        }

        // Left face
        for (int i = 0; i < numY; i++){
            for (int j = 0; j < numZ; j++){
                glNormal3f(-1,0,0);
                glTexCoord2f (textureS, textureS);
                glVertex3f(-width/2, height/2-sizey*i, -length/2+sizez*j);
                glNormal3f(-1,0,0);
                glTexCoord2f (0, textureS);
                glVertex3f(-width/2, height/2-sizey*(i+1), -length/2+sizez*j);
                glNormal3f(-1,0,0);
                glTexCoord2f (0, 0);
                glVertex3f(-width/2, height/2-sizey*(i+1), -length/2+sizez*(j+1));
                glNormal3f(-1,0,0);
                glTexCoord2f (textureS, 0);
                glVertex3f(-width/2, height/2-sizey*i, -length/2+sizez*(j+1));
            }
        }

        // Right face
        for (int i = 0; i < numY; i++){
            for (int j = 0; j < numZ; j++){
                glNormal3f(1,0,0);
                glTexCoord2f (textureS, textureS);
                glVertex3f(width/2, height/2-sizey*i, -length/2+sizez*j);
                glNormal3f(1,0,0);
                glTexCoord2f (0, textureS);
                glVertex3f(width/2, height/2-sizey*i, -length/2+sizez*(j+1));
                glNormal3f(1,0,0);
                glTexCoord2f (0, 0);
                glVertex3f(width/2, height/2-sizey*(i+1), -length/2+sizez*(j+1));
                glNormal3f(1,0,0);
                glTexCoord2f (textureS, 0);
                glVertex3f(width/2, height/2-sizey*(i+1), -length/2+sizez*j);
            }
        }

        // Front face
        for (int i = 0; i < numY; i++){
            for (int j = 0; j < numX; j++){
                glNormal3f(0,0,-1);
                glTexCoord2f (textureS, textureS);
                glVertex3f(-width/2+sizex*j, height/2-sizey*i, length/2);
                glNormal3f(0,0,-1);
                glTexCoord2f (0, textureS);
                glVertex3f(-width/2+sizex*(j+1), height/2-sizey*i, length/2);
                glNormal3f(0,0,-1);
                glTexCoord2f (0, 0);
                glVertex3f(-width/2+sizex*(j+1), height/2-sizey*(i+1), length/2);
                glNormal3f(0,0,-1);
                glTexCoord2f (textureS, 0);
                glVertex3f(-width/2+sizex*j, height/2-sizey*(i+1), length/2);
            }
        }
    
        // Back face
        for (int i = 0; i < numY; i++){
            for (int j = 0; j < numX; j++){
                glNormal3f(0,0,1);
                glTexCoord2f (textureS, textureS);
                glVertex3f(-width/2+sizex*j, height/2-sizey*i, -length/2);
                glNormal3f(0,0,1);
                glTexCoord2f (0, textureS);
                glVertex3f(-width/2+sizex*j, height/2-sizey*(i+1), -length/2);
                glNormal3f(0,0,1);
                glTexCoord2f (0, 0);
                glVertex3f(-width/2+sizex*(j+1), height/2-sizey*(i+1), -length/2);
                glNormal3f(0,0,1);
                glTexCoord2f (textureS, 0);
                glVertex3f(-width/2+sizex*(j+1), height/2-sizey*i, -length/2);
            }
        }
 
   glEnd();  // End of drawing color-cube

}


void Plataforma::DesenhaPlataforma(GLfloat gX, GLfloat gY)
{
    glPushMatrix();
    glTranslatef(gX+width/2, gY+height/2, gZ);
    gZ == 0 ? DesenhaRect(width, height, 6,6,6, 0.0, 0.0, 0.0) : DesenhaRect(width, height, 20,20,1, 0.0, 0.0, 0.0);
    
    glPopMatrix();
}
