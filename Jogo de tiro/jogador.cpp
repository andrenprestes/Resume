#include "jogador.h"

void Jogador::DesenhaCirc(GLfloat radius, GLfloat R, GLfloat G, GLfloat B)
{
    GLfloat materialEmission[] = { 0.00, 0.00, 0.00, 1.0};
    GLfloat materialColor[] = { R, G, B, 1.0};
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 0.6};
    GLfloat mat_shininess[] = { 128 };
    glMaterialfv(GL_FRONT, GL_EMISSION, materialEmission);
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialColor);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glutSolidSphere(radius, 100, 100);
}

void Jogador::DesenhaRect(GLfloat width, GLfloat height, GLfloat length, GLfloat R, GLfloat G, GLfloat B, GLuint texture)
{
    GLfloat materialEmission[] = { 0.00, 0.00, 0.00, 1.0};
    GLfloat materialColor[] = { R, G, B, 1.0};
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 0.6};
    GLfloat mat_shininess[] = { 128 };
    glMaterialfv(GL_FRONT, GL_EMISSION, materialEmission);
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialColor);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT  );//X
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );//Y

    glBindTexture (GL_TEXTURE_2D, texture);
    double textureS = 1; // Bigger than 1, repeat

    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glNormal3f(0,1,0);
      glTexCoord2f (textureS, textureS);
      glVertex3f( width/2, height/2, -length/2);
      glNormal3f(0,1,0);
      glTexCoord2f (0, textureS);
      glVertex3f(-width/2, height/2, -length/2);
      glNormal3f(0,1,0);
      glTexCoord2f (0, 0);
      glVertex3f(-width/2, height/2,  length/2);
      glNormal3f(0,1,0);
      glTexCoord2f (textureS, 0);
      glVertex3f( width/2, height/2,  length/2);
      
 
      // Bottom face (y = -1.0f)
      glNormal3f(0,-1,0);
      glTexCoord2f (textureS, textureS);
      glVertex3f( width/2, -height/2,  length/2);
      glNormal3f(0,-1,0);
      glTexCoord2f (0, textureS);
      glVertex3f(-width/2, -height/2,  length/2);
      glNormal3f(0,-1,0);
      glTexCoord2f (0, 0);
      glVertex3f(-width/2, -height/2, -length/2);
      glNormal3f(0,-1,0);
      glTexCoord2f (textureS, 0);
      glVertex3f( width/2, -height/2, -length/2);
 
      // Front face  (z = 1.0f)
      glNormal3f(0,0,1);
      glTexCoord2f (textureS, textureS);
      glVertex3f( width/2,  height/2, length/2);
      glNormal3f(0,0,1);
      glTexCoord2f (0, textureS);
      glVertex3f(-width/2,  height/2, length/2);
      glNormal3f(0,0,1);
      glTexCoord2f (0, 0);
      glVertex3f(-width/2, -height/2, length/2);
      glNormal3f(0,0,1);
      glTexCoord2f (textureS, 0);
      glVertex3f( width/2, -height/2, length/2);
 
      // Back face (z = -1.0f)
      glNormal3f(0,0,-1);
      glTexCoord2f (textureS, textureS);
      glVertex3f( width/2, -height/2, -length/2);
      glNormal3f(0,0,-1);
      glTexCoord2f (0, textureS);
      glVertex3f(-width/2, -height/2, -length/2);
      glNormal3f(0,0,-1);
      glTexCoord2f (0, 0);
      glVertex3f(-width/2,  height/2, -length/2);
      glNormal3f(0,0,-1);
      glTexCoord2f (textureS, 0);
      glVertex3f( width/2,  height/2, -length/2);
 
      // Left face (x = -1.0f)
      glNormal3f(-1,0,0);
      glTexCoord2f (textureS, textureS);
      glVertex3f(-width/2,  height/2,  length/2);
      glNormal3f(-1,0,0);
      glTexCoord2f (0, textureS);
      glVertex3f(-width/2,  height/2, -length/2);
      glNormal3f(-1,0,0);
      glTexCoord2f (0, 0);
      glVertex3f(-width/2, -height/2, -length/2);
      glNormal3f(-1,0,0);
      glTexCoord2f (textureS, 0);
      glVertex3f(-width/2, -height/2,  length/2);
 
      // Right face (x = 1.0f)
      glNormal3f(1,0,0);
      glTexCoord2f (textureS, textureS);
      glVertex3f(width/2,  height/2, -length/2);
      glNormal3f(1,0,0);
      glTexCoord2f (0, textureS);
      glVertex3f(width/2,  height/2,  length/2);
      glNormal3f(1,0,0);
      glTexCoord2f (0, 0);
      glVertex3f(width/2, -height/2,  length/2);
      glNormal3f(1,0,0);
      glTexCoord2f (textureS, 0);
      glVertex3f(width/2, -height/2, -length/2);
   glEnd();  // End of drawing color-cube
}

void Jogador::DesenhaArma(double size)
{
    GLfloat mat_ambient_r[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient_g[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient_b[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, 
            no_mat);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_mat);

    //x axis red
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_EMISSION, 
                mat_ambient_r);
        glColor3fv(mat_ambient_r);
        //glScalef(size, 3*0.1, 3*0.1);
        glTranslatef(0.5, 0, 0); // put in one end
        DesenhaRect(size, 3*0.1, 3*0.1, 0.2, 0.2, 0.2, textureGun);
        //glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_ambient_g);
        glColor3fv(mat_ambient_g);
        glRotatef(-90,0,0,1);
        //glScalef(size/2, 3*0.1, 3*0.1);
        glTranslatef(0.5, 0, 0); // put in one end
        DesenhaRect(size/2, 3*0.1, 3*0.1, 0.2, 0.2, 0.2, textureGun);
    glPopMatrix();
}

void Jogador::DesenhaCabeca(GLfloat x, GLfloat y, GLfloat z, GLfloat R, GLfloat G, GLfloat B)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    DesenhaCirc(radiusHead*altura, R, G, B);
    glPopMatrix();
}

void Jogador::DesenhaBraco(GLfloat x, GLfloat y, GLfloat z, GLfloat bracoTheta, int lado)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(bracoTheta-(90), 0, 0, 1);
    glRotatef(22.5*lado, 1, 0, 0);
    glTranslatef(x, (pernaHeight*altura/2), z);
    DesenhaRect(radiusHead * altura, pernaHeight * altura*1.9, radiusHead * altura, 0.7, 0.5, 0.3, textureArm);
    glPopMatrix();
}

void Jogador::DesenhaPerna(GLfloat x, GLfloat y, GLfloat z, GLfloat pernaTheta)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(-pernaTheta, 0, 0, 1);
    glTranslatef(x, (pernaHeight*altura/2), 0);
    DesenhaRect(radiusHead * altura * 0.8, pernaHeight * altura, radiusHead * altura*0.8, 1.0, 1.0, 1.0, textureLeg);
    
    glTranslatef(x, (pernaHeight*altura/2), 0);
    pernaTheta > -180 ? glRotatef(pernaTheta + 155, 0, 0, 1) : glRotatef(pernaTheta + 180, 0, 0, 1); // Deixando mais normal quando parado

    glTranslatef(x, (pernaHeight*altura/2), 0);
    DesenhaRect(radiusHead * altura*0.8, pernaHeight * altura, radiusHead * altura*0.8, 1.0, 1.0, 1.0, textureLeg);
    glPopMatrix();
}

void Jogador::DesenhaJogador(GLfloat x, GLfloat y, GLfloat z, GLfloat bracoTheta, GLfloat pernaTheta1, GLfloat pernaTheta2, GLfloat troncoTheta)
{
    float eyeX, eyeZ, eyeY, centerX, centerZ, centerY, dirX, dirZ, dirY, RX, RZ, RY;
    double fator=1.1, angle;

    angle = atan2(1, pernaHeight * altura*1.9/4);
    dirX = sin(troncoTheta*M_PI/180 + M_PI/2)*cos(bracoTheta*M_PI/180 +M_PI/2);
    dirY = sin(bracoTheta*M_PI/180 +M_PI/2);
    dirZ = cos(troncoTheta*M_PI/180 + M_PI/2)*cos(bracoTheta*M_PI/180 +M_PI/2);

    RX = sin(troncoTheta*M_PI/180 + M_PI/2)*cos(bracoTheta*M_PI/180 );
    RY = sin(bracoTheta*M_PI/180);
    RZ = cos(troncoTheta*M_PI/180 + M_PI/2)*cos(bracoTheta*M_PI/180);

    eyeX = gX+dirX*pernaHeight * altura*1.9/4 +RX*pernaHeight * altura*1.9/1.5;
    eyeY = gY+(altura/3)+dirY*pernaHeight * altura*1.9/4+RY*pernaHeight * altura*1.9/1.5;
    eyeZ = gZ+dirZ*pernaHeight * altura*1.9/4+RZ*pernaHeight * altura*1.9/1.5;

    glPushMatrix();
    glTranslatef(x, y + troncoHeight * altura/2, z);
    glRotatef(troncoTheta, 0, 1, 0); //Rotacionar o jogador quando girar o boneco
    DesenhaRect(troncoWidth*(radiusHead*altura*2), troncoHeight * altura, troncoWidth*(radiusHead*altura*2)*1.2, 1.0, 1.0, 1.0, textureBody);
    DesenhaBraco(0, troncoHeight * altura/3, -(troncoWidth*(radiusHead*altura*2)/2)*0.8, bracoTheta, 1);
    DesenhaBraco(0, troncoHeight * altura/3, (troncoWidth*(radiusHead*altura*2)/2)*0.8, bracoTheta, -1);
    DesenhaCabeca(0.0, ((troncoHeight/2)+radiusHead)*altura, 0, 0.7, 0.5, 0.3);
    DesenhaPerna(0, -troncoHeight * altura/2, -(troncoWidth*(radiusHead*altura*2)/2)*0.8, pernaTheta1);
    DesenhaPerna(0, -troncoHeight * altura/2, (troncoWidth*(radiusHead*altura*2)/2)*0.8, pernaTheta2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(eyeX, eyeY, eyeZ);
    glRotatef(troncoTheta, 0, 1, 0);
    glRotatef(bracoTheta, 0, 0, 1);
    DesenhaArma(1.5);
    glPopMatrix();
}

void Jogador::Aiming(int x, int y)
{
    if (bracoTheta < -45) bracoTheta = -45;
    else if (bracoTheta > 45) bracoTheta = 45;
}

void Jogador::confInicial(GLfloat gX, GLfloat gY, GLfloat altura)
{
    this->gX = gX;
    safeX = gX;
    this->gY = gY;
    safeY = gY;
    this->altura = altura;
    bracoTheta = 0; 
    pernaTheta1 = -180; 
    pernaTheta2 = -180; 
    dir = 1;
    direction = 1;
    pulando = false;
    inicioPulo = -1;
}

void Jogador::Move(GLfloat dx)
{
    if (troncoTheta <= 0) troncoTheta = 360 + troncoTheta;
    if (troncoTheta > 360) troncoTheta = 0;

    if (troncoTheta >= 0 && troncoTheta < 90){
        gX += dx*cos((troncoTheta) * M_PI / 180.0);
        gZ += dx*sin((troncoTheta) * M_PI / 180.0)*-1;
    }

    else if (troncoTheta >= 90 && troncoTheta < 180)
    {
        gX += dx*cos((180-troncoTheta) * M_PI / 180.0)*-1;
        gZ += dx*sin((180-troncoTheta) * M_PI / 180.0)*-1;
    }

    else if (troncoTheta >= 180 && troncoTheta < 270)
    {
        gX += dx*cos((troncoTheta-180) * M_PI / 180.0)*-1;
        gZ += dx*sin((troncoTheta-180) * M_PI / 180.0);
    }

    else
    {
        gX += dx*cos((360-troncoTheta) * M_PI / 180.0);
        gZ += dx*sin((360-troncoTheta) * M_PI / 180.0);
    }

    safeX = gX;
    safeZ = gZ;
    
    if (pulando || !podePular)
    {
        pernaTheta1 = -156;
        pernaTheta2 = -204;
        return;
    }

    if (dx == 0) // Volta as pernas para a posição inicial, após soltar "a" ou "d"
    {
        pernaTheta1 = -180;
        pernaTheta2 = -180;
    }

    if (pernaTheta1 >= -155)
    { 
        direction *= -1;
        pernaTheta1 = -157;
    }

    else if (pernaTheta1 <= -205)
    {
        direction *= -1;
        pernaTheta1 = -203;
    }

    pernaTheta1 += dx*4*direction;
    pernaTheta2 -= dx*4*direction;
}

void Jogador::MoveEmY(GLfloat dy, int mouseDown, GLdouble currentTime)
{
    if (!pulando && mouseDown && podePular)
    {
        //podePular = false;
        pulando = true;
        inicioPulo = currentTime;
    }

    if (mouseDown && pulando && currentTime-inicioPulo <= 1000)
    {
        safeY = gY;
        gY += dy;
    }

    else
    {
        inicioPulo = -1;
        safeY = gY;
        gY -= dy;
    }
}

//Funcao auxiliar de rotacao
void Jogador::RotatePoint(GLfloat x, GLfloat y, GLfloat angle, GLfloat &xOut, GLfloat &yOut){ //x,y centro ; xOut, yOut a ser rotacionado
    double angleInRadians = angle * (M_PI / 180);
    double cosTheta = cos(angleInRadians);
    double sinTheta = sin(angleInRadians);

    float X = (cosTheta * (xOut - x) - sinTheta * (yOut - y) + x);
    float Y = (sinTheta * (xOut - x) + cosTheta * (yOut - y) + y);

    xOut = X;
    yOut = Y;
}

double calDistance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) +
                pow(y1 - y2, 2));
}

double calDistance3d(double x1, double y1, double z1, double x2, double y2, double z2)
{
    return sqrt(pow(x1 - x2, 2) +
                pow(y1 - y2, 2)+
                pow(z1 - z2, 2));
}

Tiro* Jogador::Atira()
{
    float eyeX, eyeZ, eyeY, centerX, centerZ, centerY, dirX, dirZ, dirY, RX, RZ, RY;
    double fator=1.1, angle;

    angle = atan2(1, pernaHeight * altura*1.9/4);
    dirX = sin(troncoTheta*M_PI/180 + M_PI/2)*cos(bracoTheta*M_PI/180 +M_PI/2);
    dirY = sin(bracoTheta*M_PI/180 +M_PI/2);
    dirZ = cos(troncoTheta*M_PI/180 + M_PI/2)*cos(bracoTheta*M_PI/180 +M_PI/2);

    RX = sin(troncoTheta*M_PI/180 + M_PI/2)*cos(bracoTheta*M_PI/180 );
    RY = sin(bracoTheta*M_PI/180);
    RZ = cos(troncoTheta*M_PI/180 + M_PI/2)*cos(bracoTheta*M_PI/180);

    eyeX = gX+dirX*pernaHeight * altura*1.9/4 +RX*(pernaHeight * altura*1.9+1.5);
    eyeY = gY+(altura/3)+dirY*pernaHeight * altura*1.9/4+RY*(pernaHeight * altura*1.9+1.5);
    eyeZ = gZ+dirZ*pernaHeight * altura*1.9/4+RZ*(pernaHeight * altura*1.9+1.5);

    Tiro *t = new Tiro(eyeX, eyeY, eyeZ, bracoTheta*M_PI/180, troncoTheta, radiusHead * altura * 2);
    return t;
}

// Jogador só pode pular novamente após uma colisão em cima de uma plataforma
bool Jogador::PodePular(Plataforma p)
{
    // Colisão no eixo X
    bool colisaoX = gX + (radiusHead*altura) >= p.ObtemX() && p.ObtemX() + p.ObtemLargura() >= gX - (radiusHead*altura);
    // Colisão no eixo Y
    bool colisaoY = (gY - pernaHeight * altura * 2) + altura >= p.ObtemY() && p.ObtemY() + p.ObtemAltura() >= (gY - pernaHeight * altura * 2);
    
    // Colisão ocorreu
    if (colisaoX && colisaoY)
        return ((safeY - pernaHeight * altura * 2) >= p.ObtemY() + p.ObtemAltura());

    return false;
}

// Jogador só pode pular novamente após uma colisão em cima de um inimigo
bool Jogador::PodePular(Inimigo* i)
{
    // Colisão no eixo X
    bool colisaoX = gX + (radiusHead*altura) >= i->ObtemX() - i->ObtemLargura() && i->ObtemX() + i->ObtemLargura() >= gX - (radiusHead*altura);
    // Colisão no eixo Y
    bool colisaoY = (gY - pernaHeight * altura * 2.0) + altura >= i->ObtemYBase() && i->ObtemYBase() + i->ObtemAltura() >= (gY - pernaHeight * altura * 2.0);
    // Colisão ocorreu
    if (colisaoX && colisaoY)
        return ((safeY - pernaHeight * altura * 2.0) >= i->ObtemYBase() + i->ObtemAltura() - 0.05 * abs(i->ObtemYBase() + i->ObtemAltura()));
        
    return false;
}


void Jogador::DetectaColisao(Inimigo* i)
{
    // Colisão no eixo X
    bool colisaoX = gX + (radiusHead*altura) >= i->ObtemX() - i->ObtemLargura() && i->ObtemX() + i->ObtemLargura() >= gX - (radiusHead*altura);
    // Colisão no eixo Y
    bool colisaoY = (gY - (pernaHeight * altura * 2.0)) + altura >= i->ObtemYBase() && i->ObtemYBase() + i->ObtemAltura() >= (gY - (pernaHeight * altura * 2.0));
    // Colisão no eixo Z
    bool colisaoZ = (gZ - (troncoWidth * radiusHead*altura*2*0.6) <= i->ObtemZ() + (troncoWidth * radiusHead*altura*2*0.6)) && (gZ + (troncoWidth * radiusHead*altura*2*0.6) >= i->ObtemZ() - (troncoWidth * radiusHead*altura*2*0.6));
    
    // Colisão ocorreu
    if (colisaoX && colisaoY && colisaoZ)
    {
        // Jogador só pode pular novamente após uma colisão
        if ((safeY - pernaHeight * altura * 2.0) >= i->ObtemYBase() + i->ObtemAltura())
            pulando = false;

        // Checa se continua colidindo após reposicionar no eixo Y (feito para evitar reposicionamentos em X após aplicação da "gravidade")
        colisaoX = gX + (radiusHead*altura) >= i->ObtemX() - i->ObtemLargura() && i->ObtemX() + i->ObtemLargura() >= gX - (radiusHead*altura);
        colisaoY = (safeY - pernaHeight * altura * 2.0) + altura >= i -> ObtemYBase() && i->ObtemYBase() + i->ObtemAltura() >= (safeY - pernaHeight * altura * 2.0);

        if (!colisaoY)
        {
            // Reposiciona o jogador em Y
            gY = safeY;
            //i->SafeY(); // Reposiciona o inimigo em Y
            //printf("PÓS = Jogador Y: %f        Inimigo Y: %f\n", safeY - (pernaHeight * altura * 2.0), i->ObtemYBase() + i->ObtemAltura());
        }

        if (colisaoX && colisaoY)
        {
            if (gX < i->ObtemX())
                gX = (i->ObtemX() - i->ObtemLargura())- (radiusHead*altura)*1.000001;

            else
                gX = (i->ObtemX() + i->ObtemLargura()) + (radiusHead*altura)*1.000001;

            safeX = gX;

            i->SafeX(); // Reposiciona o inimigo em X
            i->ChangeDir();
        }
    }    
}

// Detecta colisão com os tiros dos inimigos
bool Jogador::DetectaColisao(Tiro* t)
{
    GLfloat tiroX, tiroY, tiroZ, radiusTiro;
    t->GetPos(tiroX, tiroY, tiroZ);
    t->GetRadius(radiusTiro);

    // Colisão no eixo X
    bool colisaoX = gX + (radiusHead*altura) >= tiroX - radiusTiro && tiroX + radiusTiro >= gX - (radiusHead*altura);
    // Colisão no eixo Y
    bool colisaoY = (gY - pernaHeight * altura * 2) + altura >= tiroY - radiusTiro && tiroY + radiusTiro >= (gY - pernaHeight * altura * 2);
    // Colisão no eixo Z
    bool colisaoZ = (gZ - (troncoWidth * radiusHead*altura*2*0.6)  <= tiroZ + radiusTiro) && (gZ + (troncoWidth * radiusHead*altura*2*0.6)  >= tiroZ- radiusTiro);
    
    // Colisão ocorreu
    return colisaoX && colisaoY && colisaoZ;
}

// Detecta colisões com as plataformas
void Jogador::DetectaColisao(Plataforma p, float viewHeight)
{
    // Colisão no eixo X
    bool colisaoX = gX + (radiusHead*altura) >= p.ObtemX() && p.ObtemX() + p.ObtemLargura() >= gX - (radiusHead*altura);
    // Colisão no eixo Y
    bool colisaoY = (gY - pernaHeight * altura * 2.0) + altura >= p.ObtemY() && p.ObtemY() + p.ObtemAltura() >= (gY - pernaHeight * altura * 2.0);

    // Trata as colisões em Z
    if (gZ - (troncoWidth * radiusHead*altura*2*0.6) >= viewHeight/4)
        gZ = viewHeight/4 - (troncoWidth * radiusHead*altura);
    else if (gZ + (troncoWidth * radiusHead*altura*2*0.6)  <= -viewHeight/4)
        gZ = -viewHeight/4 + (troncoWidth * radiusHead*altura);

    
    // Colisão ocorreu
    if (colisaoX && colisaoY)
    {
        if ((safeY - pernaHeight * altura * 2.0) >= p.ObtemY() + p.ObtemAltura())
            pulando = false;

        // Checa se continua colidindo após reposicionar no eixo Y (feito para evitar reposicionamentos em X após aplicação da "gravidade")
        colisaoX = gX + (radiusHead*altura) >= p.ObtemX() && p.ObtemX() + p.ObtemLargura() >= gX - (radiusHead*altura);
        colisaoY = (safeY - pernaHeight * altura * 2.0) + altura >= p.ObtemY() && p.ObtemY() + p.ObtemAltura() >= (safeY - pernaHeight * altura * 2.0);

        if (!colisaoY) gY = safeY; // Reposiciona o jogador em Y
        
        if (colisaoX && colisaoY) 
        {
            if (gX < p.ObtemX())
                gX = p.ObtemX() - (radiusHead*altura)*1.000001;

            else
                gX = (p.ObtemX() + p.ObtemLargura()) + (radiusHead*altura)*1.000001;

            safeX = gX;
            gX = safeX;   
        }
    }
}