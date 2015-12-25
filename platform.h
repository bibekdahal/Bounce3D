
#define BoxXZR 2.0f
#define BoxYR 0.2f
typedef struct
{
    float x,y,z;
} box;

int curBox;
int nBox;
box *boxes;


float BoxY;

char pMap[] =
"11111"
"01010"
"11011"
"10101"
"10101"
"11101"
"01110"
"00100";

int score = 0;
char* visible;

GLuint PlatTex, PlatTex2, ballList, platList;
void CreatePlatform()
{
    unsigned i;
    nBox=0;
    for (i=0;i<5*8;i++)
        if (pMap[i]=='1') nBox++;

    boxes = malloc(sizeof(box)*nBox);
    visible = malloc(sizeof(char)*nBox);
    unsigned j=0;
    for (i=0;i<5*8;i++)
    {
        if (pMap[i]=='1')
        {
            boxes[j].x = i%5 * 8.0f - 8.0f;
            boxes[j].y = -2.0f ;//+ (i%6==0)?2.0f : 0;
            boxes[j].z = i/5 * 8.0f;
            visible[j]=1;
            j++;
        }
    }
    ballX = boxes[j-1].x;
    ballZ = boxes[j-1].z;
    //ballY = boxes[j-1].y -


    PlatTex = LoadTexture("stone.jpg",TRUE);
    PlatTex2 = LoadTexture("stone2.jpg",TRUE);

    ballList = glGenLists(1);
    glNewList(ballList, GL_COMPILE);
        glBindTexture(GL_TEXTURE_2D, 0);
        glColor3f(0.0f,1.0f,1.0f);
        glTranslatef(0,1.0,0);
        //DrawBox(0.1,0.1,0.1);
        gluSphere(quadBall, 0.1,12,12);
    glEndList();

    platList = glGenLists(1);
    glNewList (platList, GL_COMPILE);
        glColor3f(1.0f,1.0f,1.0f);
        DrawBox(BoxXZR,BoxYR,BoxXZR);
    glEndList();
}

void Jump()
{
    if (ballY-ballR <= BoxY && ballY>BoxY) VSpeed = 0.028f/SPEED_FACTOR;
}

int TestCurBox(unsigned i)
{
    box* bx = &boxes[i];
    if (bx->x-BoxXZR >= ballX+ballR) return 0;
    if (ballX-ballR >= bx->x+BoxXZR) return 0;
    if (bx->z-BoxXZR >= ballZ+ballR) return 0;
    if (ballZ-ballR >= bx->z+BoxXZR) return 0;
    return 1;
}

void DrawPlatform()
{
    unsigned i;
    curBox = -1;
    for (i=0;i<nBox;i++)
    {
        if (i==20) glBindTexture(GL_TEXTURE_2D, PlatTex2);
        else glBindTexture(GL_TEXTURE_2D, PlatTex);
        glPushMatrix();
        glTranslatef(boxes[i].x,boxes[i].y,boxes[i].z);
        glCallList(platList);
        if (visible[i])
            glCallList(ballList);
        glPopMatrix();

        if (TestCurBox(i)) curBox = i;

        // boxes[i].z += 0.002f;
    }

    if (curBox==-1) BoxY = 10.0f;
    else BoxY = boxes[curBox].y + BoxYR;

    if (visible[curBox] && ColBox(boxes[curBox].x, boxes[curBox].y+1.0, boxes[curBox].z, 0.1))
    {
        visible[curBox]=0;
        score++;
    }
    if (ballY-ballR > BoxY || ballY<BoxY) VSpeed-=0.00028;
    else
    {
        VSpeed = 0.0f;
        ballY = BoxY+ballR;

        if (curBox == 20 && score==nBox)
        {
            Sleep(500);
            MessageBox(0, "YOU WON!","GREAT JOB", 0);
            Sleep(500);
            PostQuitMessage(0);
        }
    }
    if (VSpeed<-0.01/SPEED_FACTOR) VSpeed = -0.01/SPEED_FACTOR;
}

void DestroyPlatform()
{
    free(boxes);
    free(visible);
}
