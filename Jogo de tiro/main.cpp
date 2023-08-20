#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "tinyxml2.h"
#include "jogador.h"
#include "plataforma.h"
#include "inimigo.h"
#include "imageloader.h"
#define INC_KEY 1
#define INC_KEYIDLE 0.025

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return eResult;}
#endif

using namespace tinyxml2;
using namespace std;

//Key status
int keyStatus[256];

// Window dimensions
const GLint Width = 500;
const GLint Height = 500;

float auxY= Height/2;
float auxX= Width/2;

// Arena
GLfloat ViewingWidth = 0;
GLfloat ViewingHeight = 0;
GLfloat arenaX = 0;
GLfloat arenaY = 0;
GLfloat arenaWidth = 0;
GLfloat arena_light_position[4];
GLfloat flashlight_position[4];
GLfloat flashlight_direction[3];
bool night = false;

//Componentes do mundo virtual sendo modelado
Jogador jogador;
std::vector <Plataforma> plataformas;
std::vector <Tiro*> tirosJogador;
std::vector <Tiro*> tirosInimigos;
std::vector <Inimigo*> inimigos;

//Camera
float cameraPOSX = 0;
float cameraPOSY = 0;
float cameraPOSZ = 0;

float cameraFRONTX = 1;
float cameraFRONTY = 0;
float cameraFRONTZ = 0;

float cameraUPX = 0;
float cameraUPY = 1;
float cameraUPZ = 0;

// Trapaças
bool estatua = false;
bool desarmamento = false;

int direcao = 1;

char* path;
bool waitInput = false;
bool perdeu = false;
bool spaceDown = false;
static char str[1000];
void * font = GLUT_BITMAP_9_BY_15;

// Camera
int cameraPosition = 3;
int zoom = 15;
double camXYAngle=30;
double camXZAngle=-90;
int lastX = 0;
int lastY = 0;
bool rotateMouse = false; // x presionado
int previousCam = cameraPosition;

//Texturas
GLuint textureGround = 0;
GLuint textureWall = 0;
GLuint textureLegPlayer = 0;
GLuint textureBodyPlayer = 0;
GLuint textureBodyEnemy = 0;
GLuint textureSide = 0;
GLuint textureGun = 0;

void ResetKeyStatus()
{
    spaceDown = false;
    jogador.setPulando(false);

    //Initialize keyStatus
    for(int i = 0; i < 256; i++)
       keyStatus[i] = 0; 
}

XMLError parseXML(char* path)
{
    plataformas.clear();
    tirosJogador.clear();
    tirosInimigos.clear();
    inimigos.clear();

    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(path);
    XMLCheckResult(eResult);
    printf("%s \n", path);
    const XMLNode * pRoot = xmlDoc.FirstChild();
    if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;

    // Percorre todos os nós no arquivo .svg
    for (pRoot = pRoot->FirstChildElement(); pRoot; pRoot=pRoot->NextSibling())
    {
        const XMLElement * xmlElem = pRoot->ToElement();
        const char * fill;
        xmlElem->QueryStringAttribute("fill", &fill);
        
        // Retângulo
        if (strcmp("rect", pRoot -> Value()) == 0)
        {
            GLfloat width;
            GLfloat height;
            GLfloat x;
            GLfloat y;
            xmlElem->QueryFloatAttribute("width", &width);
            xmlElem->QueryFloatAttribute("height", &height);
            xmlElem->QueryFloatAttribute("x", &x);
            xmlElem->QueryFloatAttribute("y", &y);

            // Arena
            if (strcmp("blue", fill) == 0)
            {   
                ViewingWidth = height; 
                ViewingHeight = int(height); 
                arenaX = x;
                arenaY = -(y+ViewingHeight);
                arenaWidth = width;

                Plataforma e;
                e.confInicial(arenaX, arenaY, 0, ViewingHeight, 0, textureWall);
                e.setLength(ViewingHeight/2);
                plataformas.push_back(e);

                Plataforma d;
                d.confInicial(arenaX + arenaWidth, arenaY, 0, ViewingHeight, 0, textureWall);
                d.setLength(ViewingHeight/2);
                plataformas.push_back(d);

                Plataforma b;
                b.confInicial(arenaX, arenaY, 0, 0, arenaWidth, textureGround);
                b.setLength(ViewingHeight/2);
                plataformas.push_back(b);

                Plataforma c;
                c.confInicial(arenaX, arenaY + ViewingHeight, 0, 0, arenaWidth, textureWall);
                c.setLength(ViewingHeight/2);
                plataformas.push_back(c);
                
                
                Plataforma f;
                f.confInicial(arenaX, arenaY, ViewingHeight/4, ViewingHeight, arenaWidth, textureSide);
                f.setLength(0.0);
                f.disableColisao();
                plataformas.push_back(f);

                Plataforma t;
                t.confInicial(arenaX, arenaY, -ViewingHeight/4, ViewingHeight, arenaWidth, textureSide);
                t.setLength(0.0);
                t.disableColisao();
                plataformas.push_back(t);
                

                arena_light_position[0] = x + arenaWidth/2; arena_light_position[1] = arenaY + ViewingHeight; arena_light_position[2] = 0; arena_light_position[3] = 1.0;
            }

            // Plataformas
            else
            {
                Plataforma p;
                p.confInicial(x, -(y+height), 0, height, width, textureWall);
                p.setLength(ViewingHeight/2);
                plataformas.push_back(p);
            }
        }

        // Círculo
        else 
        {
            GLfloat cx;
            GLfloat cy;
            GLfloat radius;
            xmlElem->QueryFloatAttribute("cx", &cx);
            xmlElem->QueryFloatAttribute("cy", &cy);
            xmlElem->QueryFloatAttribute("r", &radius);

            // Jogador
            if (strcmp("green", fill) == 0)
            {
                jogador.confInicial(cx, -cy, 2*radius);
                jogador.setTextures(textureLegPlayer, 0, 0, textureBodyPlayer, textureGun);
            }

            // Inimigo
            else
            {
                inimigos.push_back(new Inimigo(cx, -cy, 2*radius));
                inimigos[inimigos.size()-1]->setTextures(textureLegPlayer, textureBodyEnemy, 0, textureBodyEnemy, textureGun);
            }
        }
    }

    waitInput = false;
    perdeu = false;
    ResetKeyStatus();
    return eResult;
}

void ImprimeMensagem(GLfloat x, GLfloat y, bool perdeu)
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-(ViewingWidth/2),     // X coordinate of left edge             
            (ViewingWidth/2),     // X coordinate of right edge            
            -(ViewingHeight/2),     // Y coordinate of bottom edge             
            (ViewingHeight/2),     // Y coordinate of top edge             
            -100,     // Z coordinate of the “near” plane            
            100);    // Z coordinate of the “far” plane
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    glDisable(GL_LIGHTING);
    glColor3f(1.0, 0.0, 0.0);
    //Cria a string a ser impressa
    char *tmpStr;
    const unsigned char strWin[] = "Voce venceu! Pressione 'r' para jogar novamente";
    const unsigned char strLose[] = "Voce perdeu! Pressione 'r' para jogar novamente";
    const unsigned char aim[] = "(+)";

    if (perdeu || jogador.Venceu(arenaX + arenaWidth))
    {
        waitInput = true;
    
        if (perdeu)
        {
            float pos = Width/2.0 - (float) glutBitmapLength(font,  strLose)/2.0;
            pos = -(ViewingWidth/2) + ((pos / (Width)) * ViewingWidth);
            glRasterPos2f(pos, 0); //Define a posicao onde vai comecar a imprimir (centro da tela)
            sprintf(str, "Voce perdeu! Pressione 'r' para jogar novamente");
        }

        else
        {
            float pos = Width/2.0 - (float) glutBitmapLength(font,  strWin)/2.0;
            pos = -(ViewingWidth/2) + ((pos / (Width)) * ViewingWidth);
            glRasterPos2f(pos, 0); //Define a posicao onde vai comecar a imprimir (centro da tela)
            sprintf(str, "Voce venceu! Pressione 'r' para jogar novamente");
        }

        //Imprime um caractere por vez
        tmpStr = str;

        while( *tmpStr ){
            glutBitmapCharacter(font, *tmpStr);
            tmpStr++;
        }
    }

    else if (cameraPosition == 2)
    {
        float pos = Width/2.0 - (float) glutBitmapLength(font,  aim)/2.0;
        pos = -(ViewingWidth/2) + ((pos / (Width)) * ViewingWidth);
        glRasterPos2f(pos, -2.2); //Define a posicao onde vai comecar a imprimir (centro da tela)
        sprintf(str, "(+)");

        //Imprime um caractere por vez
        tmpStr = str;

        while( *tmpStr ){
            glutBitmapCharacter(font, *tmpStr);
            tmpStr++;
        }
    }
    
    

    glEnable(GL_LIGHTING);
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
}

void DesenhaArena()
{
    glPushMatrix();
    glTranslatef(arenaX, arenaY, ViewingHeight/4);

    /* Define cor dos vértices com os valores R, G e B variando de 0.0 a 1.0 */
    glColor3f (0.0, 0.0, 1.0);

    /* Desenhar o retângulo */
    glRectf(0,0,arenaWidth,ViewingHeight);

    glPopMatrix();
}

double calculateDistance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) +
                pow(y1 - y2, 2));
}

double calculateDistance3d(double x1, double y1, double z1, double x2, double y2, double z2)
{
    return sqrt(pow(x1 - x2, 2) +
                pow(y1 - y2, 2)+
                pow(z1 - z2, 2));
}

//Funcao auxiliar de rotacao
void RotatePoint(GLfloat x, GLfloat y, GLfloat angle, GLfloat &xOut, GLfloat &yOut){ //x,y centro ; xOut, yOut a ser rotacionado
    double angleInRadians = angle * (M_PI / 180);
    double cosTheta = cos(angleInRadians);
    double sinTheta = sin(angleInRadians);

    float X = (cosTheta * (xOut - x) - sinTheta * (yOut - y) + x);
    float Y = (sinTheta * (xOut - x) + cosTheta * (yOut - y) + y);

    xOut = X;
    yOut = Y;
}

void renderScene(void)
{   
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (90, ViewingWidth/ ViewingHeight, 0.1, 500.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    night ? glClearColor (0.0,0.0,0.2, 1.0) : glClearColor (0.4,0.3,1.0, 1.0);

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float eyeX, eyeZ, eyeY, centerX, centerZ, centerY, dirX, dirZ, dirY, RX, RZ, RY;
    double fator=1.01, angle;

    //Controla camera
    switch (cameraPosition)
    {
        case 1:
            // Clear the screen.
            glRotatef(-jogador.ObtemAnguloTronco()+90,0.0,1.0,0.0);
            glTranslatef(-jogador.ObtemX(),-(jogador.ObtemY()+jogador.ObtemAltura()/2),-jogador.ObtemZ());
            break;
        
        case 2:
            angle = atan2(1, jogador.ObteTamanhoBraco()/4);
            dirX = sin(jogador.ObtemAnguloTronco()*M_PI/180 + M_PI/2)*cos(jogador.getAnguloBraco()*M_PI/180 +M_PI/2);
            dirY = sin(jogador.getAnguloBraco()*M_PI/180 +M_PI/2);
            dirZ = cos(jogador.ObtemAnguloTronco()*M_PI/180 + M_PI/2)*cos(jogador.getAnguloBraco()*M_PI/180 +M_PI/2);

            RX = sin(jogador.ObtemAnguloTronco()*M_PI/180 + M_PI/2)*cos(jogador.getAnguloBraco()*M_PI/180 );
            RY = sin(jogador.getAnguloBraco()*M_PI/180);
            RZ = cos(jogador.ObtemAnguloTronco()*M_PI/180 + M_PI/2)*cos(jogador.getAnguloBraco()*M_PI/180);

            eyeX = jogador.ObtemX()+dirX*jogador.ObteTamanhoBraco()/3 +RX*jogador.ObteTamanhoBraco()/2;
            eyeY = jogador.ObtemY()+(jogador.ObtemAltura()/3)+dirY*jogador.ObteTamanhoBraco()/3+RY*jogador.ObteTamanhoBraco()/2;
            eyeZ = jogador.ObtemZ()+dirZ*jogador.ObteTamanhoBraco()/3+RZ*jogador.ObteTamanhoBraco()/2;

            centerX = jogador.ObtemX()+dirX*jogador.ObteTamanhoBraco()/3+RX*fator*jogador.ObteTamanhoBraco()/2;
            centerY = jogador.ObtemY()+(jogador.ObtemAltura()/3)+dirY*jogador.ObteTamanhoBraco()/3+RY*fator*jogador.ObteTamanhoBraco()/2;
            centerZ = jogador.ObtemZ()+dirZ*jogador.ObteTamanhoBraco()/3+RZ*fator*jogador.ObteTamanhoBraco()/2;

            gluLookAt(eyeX,
                      eyeY,
                      eyeZ,
                      centerX,
                      centerY,
                      centerZ,
                      0, 1, 0);

            break;
        
        case 3:
            //Utiliza uma esfera de raio zoom para guiar a posicao da camera
            //baseada em dois angulos (do plano XZ e do plano XY)
            gluLookAt(  zoom*sin(camXZAngle*M_PI/180)*cos((camXYAngle*M_PI/180)),
                    zoom*                         sin((camXYAngle*M_PI/180)),
                    zoom*cos(camXZAngle*M_PI/180)*cos((camXYAngle*M_PI/180)),
                    0, 0, 0,
                    0, 1, 0);
            glTranslatef(-jogador.ObtemX(),-jogador.ObtemY(),-jogador.ObtemZ());
            
            break;
    }

    if (!night)
    {
        glDisable(GL_LIGHT1);
        glEnable(GL_LIGHT0);
        glLightfv(GL_LIGHT0, GL_POSITION, arena_light_position); 
        GLfloat ambient_light[4] = {0.6,0.4,0.1,1.0};
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light); 
        GLfloat specular_light[4] = {1.0,1.0,1.0,0.6};
        glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light); 
        GLfloat diffuse_light[4] = {0.95,0.7,0.2,1.0};
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    }

    if (night)
    {
        float eyeX, eyeZ, eyeY, centerX, centerZ, centerY, dirX, dirZ, dirY, RX, RZ, RY;
        double fator=1.1, angle;

        angle = atan2(1, jogador.ObteTamanhoBraco()/4);
        dirX = sin(jogador.ObtemAnguloTronco()*M_PI/180 + M_PI/2)*cos(jogador.getAnguloBraco()*M_PI/180 +M_PI/2);
        dirY = sin(jogador.getAnguloBraco()*M_PI/180 +M_PI/2);
        dirZ = cos(jogador.ObtemAnguloTronco()*M_PI/180 + M_PI/2)*cos(jogador.getAnguloBraco()*M_PI/180 +M_PI/2);

        RX = sin(jogador.ObtemAnguloTronco()*M_PI/180 + M_PI/2)*cos(jogador.getAnguloBraco()*M_PI/180);
        RY = sin(jogador.getAnguloBraco()*M_PI/180);
        RZ = cos(jogador.ObtemAnguloTronco()*M_PI/180 + M_PI/2)*cos(jogador.getAnguloBraco()*M_PI/180);

        flashlight_position[0] = jogador.ObtemX()+RX*jogador.ObteTamanhoBraco()/2;
        flashlight_position[1] = jogador.ObtemY()+(jogador.ObtemAltura()/3)+RY*jogador.ObteTamanhoBraco()/2;
        flashlight_position[2] = jogador.ObtemZ()+RZ*jogador.ObteTamanhoBraco()/2;
        flashlight_position[3] = 1.0;

        flashlight_direction[0] = RX*0.5;
        flashlight_direction[1] = RY*0.5;
        flashlight_direction[2] = RZ*0.5;

        GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
        GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        
        glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT1, GL_POSITION, flashlight_position);
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, flashlight_direction);
        glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.001);
        glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
    }

    // Desenhando os elementos
    //DesenhaArena();
    for (Plataforma p : plataformas) p.Desenha();
    jogador.Desenha();
    for (Inimigo* i : inimigos) i->Desenha();
    for (Tiro* t : tirosJogador) t->Desenha();
    for (Tiro* t : tirosInimigos) t->Desenha();

    ImprimeMensagem(jogador.ObtemX(), jogador.ObtemY(), perdeu);
    glutSwapBuffers(); // Desenha the new frame of the game.
    glutPostRedisplay();
}

void keyPress(unsigned char key, int x, int y)
{
    if (waitInput)
    {
        if (key == 'r' || key == 'R')
            parseXML(path);
    }

    else 
    {
        switch (key)
        {
            case ' ':
                keyStatus[(int)(' ')] = 1;
                break;
            case 'n':
            case 'N':
                night = !night;
                
                break;
            case '1':
                cameraPosition = 1;
                previousCam = 1;
                rotateMouse = false;
                break;
            case '2':
                cameraPosition = 2;
                previousCam = 2;
                rotateMouse = false;
                break;
            case '3':
                cameraPosition = 3;
                previousCam = 3;
                rotateMouse = false;
                break;
            case 'x':
            case 'X':
                if(cameraPosition == 3)
                    rotateMouse = !rotateMouse;
                break;
            case '+':
            case '=':
                zoom++;
                break;
            case '-':
                zoom--;
                break;
            case '9':
                estatua = !estatua;
                estatua ? printf("Trapaça ativada: Estátua\n") : printf("Trapaça desativada: Estátua\n");
                break;
            case '0':
                desarmamento = !desarmamento;
                desarmamento ? printf("Trapaça ativada: Desarmamento\n") : printf("Trapaça desativada: Desarmamento\n");
                break;
            case 'a':
            case 'A':
                keyStatus[(int)('a')] = 1; //Using keyStatus trick
                direcao = -1;
                break;
            case 'd':
            case 'D':
                keyStatus[(int)('d')] = 1; //Using keyStatus trick
                direcao = 1;
                break;
            case 'w':
            case 'W':
                keyStatus[(int)('w')] = 1; //Using keyStatus trick
                
                direcao = -1;
                break;
            case 's':
            case 'S':
                keyStatus[(int)('s')] = 1; //Using keyStatus trick
                direcao = 1;
                break;
            case 27 :
                exit(0);
        }

        glutPostRedisplay();
    }
}

void idle(void)
{
    static GLdouble previousTime = glutGet(GLUT_ELAPSED_TIME);
    GLdouble currentTime, timeDifference;
    //Pega o tempo que passou do inicio da aplicacao
    currentTime = glutGet(GLUT_ELAPSED_TIME);
    // Calcula o tempo decorrido desde de a ultima frame.
    timeDifference = currentTime - previousTime;
    //Atualiza o tempo do ultimo frame ocorrido
    previousTime = currentTime;

    if (!waitInput)
    {
        double inc = 0;
        double incY = 0.018*timeDifference;

        // Teclas de movimento
        if(keyStatus[(int)('s')])
            inc = -INC_KEYIDLE*timeDifference;

        if(keyStatus[(int)(' ')])
            spaceDown = true;

        if(keyStatus[(int)('w')])
            inc = INC_KEYIDLE*timeDifference;

        if(keyStatus[(int)('a')] && !jogador.getPulando())
            jogador.incAngulo(0.2*timeDifference);

        if(keyStatus[(int)('d')] && !jogador.getPulando())
            jogador.incAngulo(-0.2*timeDifference);
        
        jogador.Move(inc); // Voltar as pernas para a posição inicial quando o jogador estiver parado
        jogador.MoveEmY(incY, spaceDown, currentTime);
        jogador.setPodePular(false);

        for (Inimigo* i : inimigos)
            if (jogador.PodePular(i))
            {
                jogador.setPodePular(true);
                break;
            }

        for (Inimigo* i : inimigos) // Movimenta os inimigos
        {
            if (!estatua)
            {
                // Gira os inimigos
                i->incAngulo((rand() % 3 + (-1))*0.5*timeDifference);
                i->Move(INC_KEYIDLE*timeDifference, incY);
            }

            if (!desarmamento)
                if (10 > rand() % 1000 + 1 && abs(i->ObtemX() - jogador.ObtemX()) < ViewingWidth/2) // Chance aleatória de atirar quando o jogador é avistado
                    tirosInimigos.push_back(i->Atira(jogador.ObtemX(), jogador.ObtemY(), jogador.ObtemZ()));
            
            i->ColisaoBordas();
            jogador.DetectaColisao(i);
            
            for (Inimigo* j : inimigos)
                if (i != j)
                    i->DetectaColisao(j);
            
        }

        for (Tiro* t : tirosJogador) // Move os tiros do jogador
        {
            t->Move(INC_KEYIDLE*2, timeDifference);
            for (int i = 0; i < inimigos.size(); i++)
                if (inimigos[i]->DetectaColisao(t))
                    inimigos.erase(inimigos.begin() + i);
        }

        for (Tiro* t : tirosInimigos) // Move os tiros dos inimigos
        {
            t->Move(INC_KEYIDLE*2, timeDifference);
            if (jogador.DetectaColisao(t))
                perdeu = true;
        }

        for (Plataforma p : plataformas)
            if (jogador.PodePular(p) && p.colisao)
            {
                jogador.setPodePular(true);
                break;
            }

        for (Plataforma p : plataformas)
        {
            if (p.colisao)
            {
                jogador.DetectaColisao(p, ViewingHeight); // Detecta colisão do jogador com as plataformas

                for (Inimigo* i : inimigos) // Detecta colisão dos inimigos com as plataformas
                    i->DetectaColisao(p, ViewingHeight);

                for (int i = 0; i < tirosJogador.size(); i++) // Detecta colisão dos tiros do jogador com as plataformas
                    if (tirosJogador[i]->DetectaColisao(p) || !tirosJogador[i]->Valido(ViewingHeight))
                        tirosJogador.erase(tirosJogador.begin() + i);

                for (int i = 0; i < tirosInimigos.size(); i++) // Detecta colisão dos tiros dos inimigos com as plataformas
                    if (tirosInimigos[i]->DetectaColisao(p) || !tirosInimigos[i]->Valido(ViewingHeight))
                        tirosInimigos.erase(tirosInimigos.begin() + i);
            }
        } 

        cameraPOSX = jogador.ObtemX();
        cameraPOSY = jogador.ObtemY();
        cameraPOSZ = jogador.ObtemZ();
        
        glutPostRedisplay();
    }
}

void keyup(unsigned char key, int x, int y)
{
    if (waitInput)
        return;

    if (key == ' ')
        spaceDown = false;

    keyStatus[(int)(key)] = 0;
    glutPostRedisplay();
}

GLuint LoadTextureRAW( const char * filename )
{

    GLuint texture;
    
    Image* image = loadBMP(filename);

    glGenTextures( 1, &texture );
    glBindTexture( GL_TEXTURE_2D, texture );
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
//    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
                             0,                            //0 for now
                             GL_RGB,                       //Format OpenGL uses for image
                             image->width, image->height,  //Width and height
                             0,                            //The border of the image
                             GL_RGB, //GL_RGB, because pixels are stored in RGB format
                             GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
                                               //as unsigned numbers
                             image->pixels);               //The actual pixel data
    delete image;

    return texture;
}

void init(void)
{
    ResetKeyStatus();
    // The color the windows will redraw. Its done to erase the previous frame.
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black, no opacity(alpha).
    
    //glShadeModel (GL_FLAT);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);  
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
}

void mouseMove(int x, int y){
    //if(!stop){
          if (auxY - y > 0 ){// && jogador.getAnguloBraco() < -45
               jogador.incAnguloBraco(2.8);
          }else if (auxY - y < 0 ){//&& jogador.getAnguloBraco()  > -135
               jogador.incAnguloBraco(-2.8);
          }
          auxY = y;
          jogador.Aiming(x,y);
    //}
}

void mouseMovement(int x, int y)
{
    if (!rotateMouse)
    {
        mouseMove( x, y);
        return;
    }
    
    camXZAngle -= x - lastX;
    camXYAngle += y - lastY;

    if (camXYAngle > 60) camXYAngle = 60;
    if (camXYAngle < -60) camXYAngle = -60;

    lastX = x;
    lastY = y;
    glutPostRedisplay();
}

void mouseClicks(int button, int state, int x, int y) 
{
    if (waitInput)
        return;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        tirosJogador.push_back(jogador.Atira());
    
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN)
        {
            cameraPosition = 2;
            rotateMouse = false;
        }
        else
            cameraPosition = previousCam;
    }
}

int main(int argc, char *argv[])
{
    path = argv[1];
    srand (time(NULL));

    // Initialize openGL with Double buffer and RGB color without transparency.
    // Its interesting to try GLUT_SINGLE instead of GLUT_DOUBLE.
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
 
    // Create the window.
    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(150,50);
    glutCreateWindow("Trabalho CG");
 
    // Define callbacks.
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(keyPress);
    glutIdleFunc(idle);
    glutKeyboardUpFunc(keyup);
    glutPassiveMotionFunc(mouseMovement);
    glutMotionFunc(mouseMovement);
    glutMouseFunc(mouseClicks);

    // Loading textures
    textureGround = LoadTextureRAW( "ground.bmp" );
    textureWall = LoadTextureRAW( "stone.bmp" ); 
    textureSide = LoadTextureRAW( "jungle.bmp" ); 
    textureLegPlayer = LoadTextureRAW( "leg.bmp" );
    textureBodyPlayer = LoadTextureRAW( "body.bmp" );
    textureBodyEnemy = LoadTextureRAW( "bodyE.bmp" );
    textureGun = LoadTextureRAW( "gun.bmp" );

    parseXML(path);
    init();
 
    glutMainLoop();
 
    return 0;
}