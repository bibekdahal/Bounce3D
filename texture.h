#include "SOIL.h"

#include "math.h"
GLuint LoadTexture(const char * filename,int wrap)
{
    unsigned char* txt;
    int w,h,c;
    txt = SOIL_load_image(filename,&w,&h,&c,4);
    if (txt==NULL)
        return 0;
    int os = w*h*4;
    w = pow(2, floor(log(w)/log(2)+0.5));
    h = pow(2, floor(log(h)/log(2)+0.5));
    unsigned char* data = (unsigned char*)malloc(w*h*4);
    memset(data,0,w*h*4);
    if (os<w*h*4)
        memcpy(data,txt,os);
    else
        memcpy(data,txt,w*h*4);

    GLuint Texture;
    glGenTextures(1,&Texture);
    glBindTexture(GL_TEXTURE_2D,Texture);

    // select modulate to mix texture with color for shading
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
    // when texture area is small, bilinear filter the closest mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );
    // when texture area is large, bilinear filter the first mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    //wrapping?
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap ? GL_REPEAT : GL_CLAMP );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap ? GL_REPEAT : GL_CLAMP );

    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,w,h,0, GL_RGBA,GL_UNSIGNED_BYTE,data);
    // build our texture mipmaps
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, w, h, GL_RGBA, GL_UNSIGNED_BYTE, data );

    free(data);
    SOIL_free_image_data(txt);
    return Texture;
}
