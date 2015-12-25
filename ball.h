
float VSpeed=0.0f;
float HSpeed=0.0f;

//const float friction = 0.0001f;

GLUquadricObj *quadBall;
GLuint ballTex;
void CreateBall()
{
    quadBall=gluNewQuadric();
    gluQuadricNormals(quadBall, GLU_SMOOTH);

}

void Jump();
#define SPEED 0.02
float SPEED_FACTOR = 1;
void DrawBall()
{
    // If FPS has not been calculated yet, don't provide control
    if (FPS!=1)
    {
        SPEED_FACTOR = 400.0f/FPS;
        float DISP;
        DISP = SPEED*SPEED_FACTOR;
        if (keys[VK_LEFT]) CamAngle += 0.005f;
        if (keys[VK_RIGHT]) CamAngle -= 0.005f;

        if (keys[0x41])
        {
            ballZ += DISP*sin(CamAngle);
            ballX -= DISP*cos(CamAngle);
        }
        if (keys[0x44])
        {
            ballZ -= DISP*sin(CamAngle);
            ballX += DISP*cos(CamAngle);
        }
        //if (keys[VK_LEFT]) ballX -= 0.01f;
        //if (keys[VK_RIGHT]) ballX += 0.01f;
        if (keys[VK_UP])
        {
            ballZ -= DISP*cos(CamAngle);
            ballX -= DISP*sin(CamAngle);
        }
        if (keys[VK_DOWN])
        {
            ballZ += DISP*cos(CamAngle);
            ballX += DISP*sin(CamAngle);
        }

        if (keys[VK_SPACE]) Jump();
    }

    ballY += VSpeed*SPEED_FACTOR;
    //ballX += HSpeed;
    //if (fabs(HSpeed-friction)<=friction) HSpeed=0;

    //if (HSpeed>0) HSpeed -= friction;
    //else if (HSpeed<0) HSpeed +=friction;

    glPushMatrix();
    glTranslatef(ballX, ballY, ballZ);

    glColor3f(0.2f,0.2f,0.8f);
    //GLfloat spc[]={1.0f,1.0f,1.0f,1.0f};
    //glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spc);
    gluSphere(quadBall, ballR, 32, 32);
    glPopMatrix();


    if (ballY < -10)
    {
        MessageBox(0,"YOU LOST THE GAME :(", "OH NO...",0);
        Sleep(500);
        PostQuitMessage(0);
    }
}

void DestroyBall()
{
    gluDeleteQuadric(quadBall);
}
