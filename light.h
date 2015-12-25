
#define AMBIENT_FACTOR 0.2f

GLfloat LightPoint[]= {-5.0f,1.0f,1.0f, 1.0f}; // w=1 : point light

void CreateLight()
{
    GLfloat LightAmbient[]= { AMBIENT_FACTOR, AMBIENT_FACTOR, AMBIENT_FACTOR, 1.0f };
    GLfloat LightDiffuse[]= {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat LightPosition[]= {-1.0f,1.0f,1.0f, 0.0f}; // w=0 : directional
    //#define SPECULAR_FACTOR 1.0f
    //GLfloat LightSpecular[]= {SPECULAR_FACTOR, SPECULAR_FACTOR, SPECULAR_FACTOR, SPECULAR_FACTOR};


    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);

    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
    //glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
    glEnable(GL_LIGHT0);

    /*glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
    //glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
    glLightfv(GL_LIGHT1, GL_POSITION, LightPoint);
    glEnable(GL_LIGHT1);*/
}

void UpdateLight()
{
    //glLightfv(GL_LIGHT1, GL_POSITION, LightPoint);
}
