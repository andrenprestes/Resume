#include "inimigo.h"

void Inimigo::DesenhaCirc(GLfloat radius, GLfloat R, GLfloat G, GLfloat B)
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

void Inimigo::DesenhaRect(GLfloat width, GLfloat height, GLfloat length, GLfloat R, GLfloat G, GLfloat B, GLuint texture)
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


void Inimigo::DesenhaCabeca(GLfloat x, GLfloat y, GLfloat z, GLfloat R, GLfloat G, GLfloat B)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    DesenhaCirc(radiusHead*altura, R, G, B);
    glPopMatrix();
}

void Inimigo::DesenhaBraco(GLfloat x, GLfloat y, GLfloat z, GLfloat bracoTheta, int lado)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(bracoTheta-(90), 0, 0, 1);
    glRotatef(45*lado, 1, 0, 0);
    glTranslatef(x, (pernaHeight*altura/2), z);
    DesenhaRect(radiusHead * altura, pernaHeight * altura*1.5, radiusHead * altura, 1.0, 0.9, 0.75, 0);
    glPopMatrix();
}

void Inimigo::DesenhaPerna(GLfloat x, GLfloat y, GLfloat z, GLfloat pernaTheta)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(-pernaTheta, 0, 0, 1);
    glTranslatef(x, (pernaHeight*altura/2), 0);
    DesenhaRect(radiusHead * altura * 0.8, pernaHeight * altura, radiusHead * altura*0.8, 0.0, 0.0, 0.7, textureLeg);
    
    glTranslatef(x, (pernaHeight*altura/2), 0);
    pernaTheta > -180 ? glRotatef(pernaTheta + 155, 0, 0, 1) : glRotatef(pernaTheta + 180, 0, 0, 1); // Deixando mais normal quando parado

    glTranslatef(x, (pernaHeight*altura/2), 0);
    DesenhaRect(radiusHead * altura*0.8, pernaHeight * altura, radiusHead * altura*0.8, 0.0, 0.0, 0.7, textureLeg);
    glPopMatrix();
}

void Inimigo::DesenhaArma(double size)
{
    GLfloat mat_ambient_r[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient_g[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient_b[] = { 0.0, 0.0, 0.0, 1.0 };
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
        glTranslatef(0.5, 0, 0); // put in one end
        DesenhaRect(size, 3*0.1, 3*0.1, 0.2, 0.2, 0.2, 0);
    glPopMatrix();

    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_ambient_g);
        glColor3fv(mat_ambient_g);
        glRotatef(-90,0,0,1);
        glTranslatef(0.5, 0, 0); // put in one end
        DesenhaRect(size/2, 3*0.1, 3*0.1, 0.2, 0.2, 0.2, 0);
    glPopMatrix();
}

void Inimigo::DesenhaInimigo(GLfloat x, GLfloat y, GLfloat z, GLfloat bracoTheta, GLfloat pernaTheta1, GLfloat pernaTheta2)
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
    DesenhaCabeca(0.0, ((troncoHeight/2)+radiusHead)*altura, 0, 1.0, 0.9, 0.75);
    DesenhaPerna(0, -troncoHeight * altura/2, -(troncoWidth*(radiusHead*altura*2)/2)*0.8, pernaTheta1);
    DesenhaPerna(0, -troncoHeight * altura/2, (troncoWidth*(radiusHead*altura*2)/2)*0.8, pernaTheta2);

    //DesenhaRect(troncoWidth*(radiusHead*altura*2)*1.2, altura, troncoWidth*(radiusHead*altura*2)*1.2, 1.0, 0.0, 0.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(eyeX, eyeY, eyeZ);
    glRotatef(troncoTheta, 0, 1, 0);
    glRotatef(bracoTheta, 0, 0, 1);
    DesenhaArma(1.5);
    glPopMatrix();
}

float dot(float ax, float ay, float az, float bx, float by, float bz)  //calculates dot product of a and b
{
    return ax * bx + ay * by + az * bz;
}

float mag(float x, float y, float z)  //calculates magnitude of a
{
    return std::sqrt(x * x + y * y + z * z);
}

float getAngle (float x1,float y1,float z1,float x2,float y2,float z2)
{
    float theta = atan2(z1-z2,x1-x2);
    return -theta*180/3.1415926;
}
float getAngle2 (float x1,float y1,float z1,float x2,float y2,float z2)
{
    float dist=sqrt(pow(x1 - x2,2) + pow(y1 - y2,2) + pow(z1 - z2,2));
    float dist2=sqrt(pow(x1 - x2,2) + pow(z1 - z2,2));
    return acos(dist2/dist)*180/3.1415926;
}

void Inimigo::Aiming(float x, float y, float z)
{
    GLfloat baseX = gX;
    GLfloat baseY = gY +(altura/3);
    GLfloat baseZ = gZ;
    double angleZ, angleY;

    angleZ = getAngle(x,y+(altura/3),z,gX,gY+(altura/3),gZ);
    angleY = getAngle2(x,y+(altura/3),z,gX,gY+(altura/3),gZ);
    
    if (y+(altura/3) < baseY)
        angleY *= -1;

    if (angleY > 45) angleY = 45;
    if (angleY < -45) angleY = -45;

    bracoTheta = angleY;
    troncoTheta = angleZ;
}

Tiro* Inimigo::Atira(GLfloat jogadorX, GLfloat jogadorY, GLfloat jogadorZ)
{
    Aiming(jogadorX, jogadorY, jogadorZ);

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

void Inimigo::Move(GLfloat dx, GLfloat dy)
{
    safeY = gY;
    gY -= dy * (limRight == -1 && limRight == limLeft);
    
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
    
    if (dx == 0) // Volta as pernas para a posição inicial, após soltar "a" ou "d"
    {
        pernaTheta1 = -180;
        pernaTheta2 = -180;
    }

    if (pernaTheta1 >= -155)          //
    {                                 //
        pernaTheta1 = -156;           //
        pernaTheta2 = -204;           // Evitando bug em que as pernas
        direction *= -1;              // dos inimigos ficaram sempre
    }                                 // abertas, independente do
                                      // movimento. Ocorria após minutos
    else if (pernaTheta1 <= -205)     // de jogo.
    {                                 //
        pernaTheta1 = -204;           //
        pernaTheta2 = -156;           //
        direction *= -1;              //
    }                                 //

    pernaTheta1 += dx*4*direction;
    pernaTheta2 -= dx*4*direction;
}

//Funcao auxiliar de rotacao
void Inimigo::RotatePoint(GLfloat x, GLfloat y, GLfloat angle, GLfloat &xOut, GLfloat &yOut){ //x,y centro ; xOut, yOut a ser rotacionado
    double angleInRadians = angle * (M_PI / 180);
    double cosTheta = cos(angleInRadians);
    double sinTheta = sin(angleInRadians);

    float X = (cosTheta * (xOut - x) - sinTheta * (yOut - y) + x);
    float Y = (sinTheta * (xOut - x) + cosTheta * (yOut - y) + y);

    xOut = X;
    yOut = Y;
}

void Inimigo::ColisaoBordas()
{
    if (limRight == -1 && limRight == limLeft)
        return;

    if (gX <= limLeft)
    {
        gX = limLeft + (troncoWidth * radiusHead*altura*2*0.6);
        ChangeDir();
    }

    else if (gX >= limRight)
    {
        gX = limRight - (troncoWidth * radiusHead*altura*2*0.6);
        ChangeDir();
    }
}

// Detecta colisão com outros inimigos
void Inimigo::DetectaColisao(Inimigo* i)
{
    // Colisão no eixo X
    bool colisaoX = gX + (radiusHead*altura) >= i->ObtemX() - i->ObtemLargura() && i->ObtemX() + i->ObtemLargura() >= gX - (radiusHead*altura);
    // Colisão no eixo Y
    bool colisaoY = (gY - pernaHeight * altura * 2.0) + altura >= i->ObtemYBase() && i->ObtemYBase() + i->ObtemAltura() >= (gY - pernaHeight * altura * 2.0);
    // Colisão no eixo Z
    bool colisaoZ = (gZ - (troncoWidth * radiusHead*altura*2*0.6) <= i->ObtemZ() + (troncoWidth * radiusHead*altura*2*0.6)) && (gZ + (troncoWidth * radiusHead*altura*2*0.6) >= i->ObtemZ() - (troncoWidth * radiusHead*altura*2*0.6));
    
    
    // Colisão ocorreu
    if (colisaoX && colisaoY && colisaoZ)
    {
        // Checa se continua colidindo após reposicionar no eixo Y (feito para evitar reposicionamentos em X após aplicação da "gravidade")
        colisaoX = gX + (radiusHead*altura) >= i->ObtemX() - i->ObtemLargura() && i->ObtemX() + i->ObtemLargura() >= gX - (radiusHead*altura);
        colisaoY = (safeY - pernaHeight * altura * 2.0) + altura >= i -> ObtemYBase() && i->ObtemYBase() + i->ObtemAltura() >= (safeY - pernaHeight * altura * 2.0);

        if (colisaoX && colisaoY)
        {
            gX = safeX; // Reposiciona o inimigo em Y
            ChangeDir();
            i->SafeX(); // Reposiciona o outro inimigo em X
            i->ChangeDir();
        }
        else
        {
            // Reposiciona o inimigo em Y
            gY = safeY;
            i->SafeY(); // Reposiciona o outro inimigo em Y
        }
    }    
}

// Detecta colisão com os tiros do jogador
bool Inimigo::DetectaColisao(Tiro* t)
{
    GLfloat tiroX, tiroY, tiroZ, radiusTiro;
    t->GetPos(tiroX, tiroY, tiroZ);
    t->GetRadius(radiusTiro);

    // Colisão no eixo X
    bool colisaoX = gX + (radiusHead*altura) >= tiroX - radiusTiro && tiroX + radiusTiro >= gX - (radiusHead*altura);
    // Colisão no eixo Y
    bool colisaoY = (gY - pernaHeight * altura * 2.0) + altura >= tiroY - radiusTiro && tiroY + radiusTiro >= (gY - pernaHeight * altura * 2.0);
    // Colisão no eixo Z
    bool colisaoZ = (gZ - (troncoWidth * radiusHead*altura*2*0.6)  <= tiroZ + radiusTiro) && (gZ + (troncoWidth * radiusHead*altura*2*0.6)  >= tiroZ- radiusTiro);
    
    
    // Colisão ocorreu
    return colisaoX && colisaoY && colisaoZ;
}

// Detecta colisões com as plataformas
void Inimigo::DetectaColisao(Plataforma p, float viewHeight)
{
    // Colisão no eixo X
    bool colisaoX = gX + (radiusHead*altura*2*0.6) >= p.ObtemX() && p.ObtemX() + p.ObtemLargura() >= gX - (radiusHead*altura*2*0.6);
    // Colisão no eixo Y
    bool colisaoY = (gY - pernaHeight * altura * 2.0) + altura >= p.ObtemY() && p.ObtemY() + p.ObtemAltura() >= (gY - pernaHeight * altura * 2.0);
    
    // Trata as colisões em Z
    if (gZ - (radiusHead*altura*2*0.6) >= viewHeight/4)
    {
        gZ = viewHeight/4 - (radiusHead*altura*2*0.6);
        ChangeDir();
        ChangeDir();
    }
    else if (gZ + (radiusHead*altura*2*0.6) <= -viewHeight/4)
    {
        gZ = -viewHeight/4 + (radiusHead*altura*2*0.6);
        ChangeDir();
        ChangeDir();
    }

    // Colisão ocorreu
    if (colisaoX && colisaoY)
    {
        // Primeira colisão com uma plataforma, para obter os limites de onde pode andar
        if (limRight == -1 && limRight == limLeft)
        {
            limLeft = p.ObtemX();
            limRight = p.ObtemX() + p.ObtemLargura();
            gY = p.ObtemY() + p.ObtemAltura() + (pernaHeight * altura * 2.0)*1.000001;
            safeY = gY;
        }

        // Checa se continua colidindo após reposicionar no eixo Y (feito para evitar reposicionamentos em X após aplicação da "gravidade")
        //colisaoX = gX + (radiusHead*altura*2*0.6) >= p.ObtemX() && p.ObtemX() + p.ObtemLargura() >= gX - (radiusHead*altura*2*0.6);
        colisaoY = (safeY - pernaHeight * altura * 2.0) + altura >= p.ObtemY() && p.ObtemY() + p.ObtemAltura() >= (safeY - pernaHeight * altura * 2.0);

        if (!colisaoY)
        {
            if (safeY > p.ObtemY() + p.ObtemAltura())
                gY = p.ObtemY() + p.ObtemAltura() + (pernaHeight * altura * 2.0)*1.000001;
            else
                gY = p.ObtemY() - altura + (safeY - pernaHeight * altura * 2.0);
        }

            //gY = safeY; // Reposiciona o inimigo em Y

        if (colisaoX && colisaoY)
        {
            if (safeX <= p.ObtemX())
                gX = p.ObtemX() - (radiusHead*altura*2*0.6)*1.2;
        
            else if (safeX >= p.ObtemX() + p.ObtemLargura())
                gX = p.ObtemX() + p.ObtemLargura() + (radiusHead*altura*2*0.6)*1.2;

            ChangeDir();
        } 
    }
}