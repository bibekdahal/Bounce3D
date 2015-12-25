BOOL keys[256];

void DrawBox(float xMax, float yMax, float zMax)
{
    glBegin(GL_QUADS);          // Start Drawing Quads
        // Front Face
        glNormal3f( 0.0f, 0.0f, 1.0f);      // Normal Facing Forward
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-xMax, -yMax,  zMax);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f( xMax, -yMax,  zMax);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( xMax,  yMax,  zMax);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-xMax,  yMax,  zMax);  // Top Left Of The Texture and Quad
        // Back Face
        glNormal3f( 0.0f, 0.0f,-1.0f);      // Normal Facing Away
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-xMax, -yMax, -zMax);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-xMax,  yMax, -zMax);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( xMax,  yMax, -zMax);  // Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( xMax, -yMax, -zMax);  // Bottom Left Of The Texture and Quad
        // Top Face
        glNormal3f( 0.0f, 1.0f, 0.0f);      // Normal Facing Up
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-xMax,  yMax, -zMax);  // Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-xMax,  yMax,  zMax);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f( xMax,  yMax,  zMax);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( xMax,  yMax, -zMax);  // Top Right Of The Texture and Quad
        // Bottom Face
        glNormal3f( 0.0f,-1.0f, 0.0f);      // Normal Facing Down
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-xMax, -yMax, -zMax);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( xMax, -yMax, -zMax);  // Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( xMax, -yMax,  zMax);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-xMax, -yMax,  zMax);  // Bottom Right Of The Texture and Quad
        // Right face
        glNormal3f( 1.0f, 0.0f, 0.0f);      // Normal Facing Right
        glTexCoord2f(1.0f, 0.0f); glVertex3f( xMax, -yMax, -zMax);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( xMax,  yMax, -zMax);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( xMax,  yMax,  zMax);  // Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( xMax, -yMax,  zMax);  // Bottom Left Of The Texture and Quad
        // Left Face
        glNormal3f(-1.0f, 0.0f, 0.0f);      // Normal Facing Left
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-xMax, -yMax, -zMax);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-xMax, -yMax,  zMax);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-xMax,  yMax,  zMax);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-xMax,  yMax, -zMax);  // Top Left Of The Texture and Quad
    glEnd();                    // Done Drawing Quads
}


float ballX=0.0f, ballY=0.0f, ballZ=-5.0f;
const float ballR = 0.5f;
BOOL ColBox(float x, float y, float z, float r)
{
    if (((ballX-x)*(ballX-x) + (ballY-y)*(ballY-y) + (ballZ-z)*(ballZ-z)) <= (ballR+r)*(ballR+r)) return 1;
    return 0;
}
