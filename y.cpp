#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glcorearb.h>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
float width = 1200.0;
float height = 800.0;
float xr=0,yr=0;
float zr=0;
bool start=false;
long long player1=0;
long long player2=0;
float xr2=0,yr2=0,z2r=0;
int counter=0;
void changeSize(int w,int h){
    if(h==0)
        h=1;
    width = w;
    height = h;
    GLdouble ratio = 1.0f*w/h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0,0,w,h);

    gluPerspective(45,ratio,1,1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,10,
              0,0,-1,
              0,1,0);
}

void eyeright()
{
    //function for the right eye
    glPushMatrix();
    glTranslatef(.17,1.1,.75);     //Specify the coordinates for the right eye
    glRotatef(-45,0,0,1);
    glScalef(.9,.7,.7);            //Specify the size of the right eye
    glColor3f(1.0,1.0,1.0);       //Specify the color of the eye
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}
void eyeleft()
{
    glPushMatrix();
    glTranslatef(-.17,1.1,.75);     //Specify the position for the left eye
    glRotatef(45,0,0,1);
    glScalef(.9,.7,.7);
    glColor3f(1.0,1.0,1.0);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}

void legleft()
{
    glPushMatrix();
    glTranslatef(.3,-.5,0);     //Specify the position for the left leg
    glRotatef(-90.0,1,0,0);
    glScalef(.8,.8,.8);
    gluCylinder(gluNewQuadric(),.5,.5,.5,30,6);
    glPopMatrix();
}

void legright()
{
    glPushMatrix();
    glTranslatef(-.3,-.5,0);     //Specify the position for the right leg
    glRotatef(-90.0,1,0,0);
    glScalef(.8,.8,.8);
    gluCylinder(gluNewQuadric(),.5,.5,.5,30,6);
    glPopMatrix();
}

void armleft()
{
    glPushMatrix();
    glTranslatef(-.82,0,.1);     //Specify the position for the left arm
    glRotatef(90,0,1,0);
    glRotatef(-50,1,0,0);
    gluCylinder(gluNewQuadric(),.15,.15,.48,30,6);
    glPopMatrix();
}

void armright()
{
    glPushMatrix();
    glTranslatef(.82,0,.1);      //Specify the position for the right arm
    glRotatef(90,0,1,0);
    glRotatef(-130,1,0,0);
    gluCylinder(gluNewQuadric(),.15,.15,.48,30,6);
    glPopMatrix();
}

void handleft()
{
    glPushMatrix();
    glTranslatef(.82,0,.1);     //Specify the position for the left hand
    glScalef(.4,.3,.3);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
}
void handright()
{
    glPushMatrix();
    glTranslatef(-.82,0,.1);    //Specify the position for the right hand
    glScalef(.4,.3,.3);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
}

void mouth()
{
    glPushMatrix();
    glTranslatef(0,.78,.74);
    glScalef(.4,.4,.1);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.4,100,100);
    glPopMatrix();
}

void teeth()
{
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-.08,.72,.76);
    glTranslatef(.055,0,.005 );
    glutSolidCube(.035);
    glTranslatef(.055,0,0 );
    glutSolidCube(.035);
    glPopMatrix();
}
void eyebrowleft()
{
    glPushMatrix();
    glTranslatef(-.3,1.5,.97);;
    glRotatef(90,0,1,0);
    glRotatef(45,1,0,0);
    glColor3f(0.0,0.0,0.0);
    gluCylinder(gluNewQuadric(),.05,.01,.3,4,6);
    glPopMatrix();
}

void eyebrowright()
{
    glPushMatrix();
    glTranslatef(.3,1.5,.97);
    glRotatef(270,0,1,0);
    glRotatef(45,1,0,0);
    gluCylinder(gluNewQuadric(),.05,.01,.3,4,6);
    glPopMatrix();
}

void neckring()
{
    glPushMatrix();
    glTranslatef(0,.5,0);
    glScalef(.59,.59,.59);
    glRotatef(90.0,1,0,0);
    glutSolidTorus(.1,1.0,20,20);
    glPopMatrix();
}


void head()
{
    glPushMatrix();
    glTranslatef(0,1.2,0);
    glScalef(.9 ,.9,.9 );
    glColor3f(1.0,0.8,0.6);
    gluSphere(gluNewQuadric(),1,100,100);
    glPopMatrix();
}

void maintopball()
{
    glPushMatrix();
    glTranslatef(0,2.2,0);
    glScalef(.9,.9,.9);
    glColor3f(1.0,0.8,0.6);
    gluSphere(gluNewQuadric(),.18,100,100);
    glPopMatrix() ;
}

void hatring()
{
    glPushMatrix();
    glTranslatef(0,1.4,0);
    glScalef(.84,.84,.84);
    glColor3f(1.0,0.8,0.6);
    glRotatef(90.0,1,0,0);
    glutSolidTorus(.1,1.0,20,20);
    glPopMatrix();
}

void footleft()
{
    glPushMatrix();
    glTranslatef(-.3,-.5,0);
    glScalef(1.5,.3,1.5);
     glColor3f(1.0,0.8,0.6);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}

void footright()
{
    glPushMatrix();
    glTranslatef(.3,-.5,0);
    glScalef(1.5,.3,1.5);
     glColor3f(1.0,0.8,0.6);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();
}

void bellyCoatbottom()
{
    glPushMatrix();
    glTranslatef(0,-.2,0);
    glScalef(1,.7,1);
     glColor3f(1.0,0.8,0.6);
    glRotatef(90.0,1,0,0);
    gluDisk(gluNewQuadric(),0,.8,30,30);
    glPopMatrix();
}

void BellyCoat()
{
    glPushMatrix();
    glTranslatef(0,.5,0);
    glScalef(1,.7,1);
     glColor3f(1.0,0.8,0.6);
    glRotatef(90.0,1,0,0);
    gluCylinder(gluNewQuadric(),.6,.8,1,100,100);
    glPopMatrix();
    
}

void pupilleft()
{
    glPushMatrix();
    glTranslatef(-.17,1.1,.88);
    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.1,100,100);
    glPopMatrix();
}

void pupilright()
{
    glPushMatrix();
    glTranslatef(.17,1.1,.88);
    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.1,100,100);
    glPopMatrix();
}

void topbutton()
{
    glPushMatrix();
    glTranslatef(-.1,.4,.85);
    glScalef(1.9,1.9,1.9);
    gluSphere(gluNewQuadric(),.04,100,100);
    glPopMatrix();
}
void middlebutton()
{
    glPushMatrix()  ;
    glTranslatef(-.1,.15,.98);
    glScalef(1.9,1.9,1.9);
    gluSphere(gluNewQuadric(),.04,100,100);
    glPopMatrix();
}
void bottombutton()
{
    glPushMatrix();
    glTranslatef(-.1,-.1,.92);
    glScalef(1.9,1.9,1.9);
    glColor3f(0.0,0.0,0.0);
    gluSphere(gluNewQuadric(),.04,100,100);
    glPopMatrix();
}

//------------------------------  reshapeFunc  ---------------------------------

void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (40.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}
/// INTRO CHAR

void char2(){
	
    neckring();
    legright();
    legleft();
    armleft();
    armright();
    BellyCoat();
    bellyCoatbottom();
    handleft();
    handright();   
    head();
    
    footleft();
    footright();
   
     
}
void drawtext(const char* text,int len, int x,int y){
    glMatrixMode(GL_PROJECTION);
    double *matrix= new double[16];
    glGetDoublev(GL_PROJECTION,matrix);
    glLoadIdentity();
  
    glOrtho(0,800,0,600,-5,5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glRasterPos2i(x,y);
    for(int i=0;i<len;++i)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int)text[i]);
    
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);

}
void arrow1(){

     glPushMatrix();
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex2d(2.5,-3);
    glVertex2d(2.5+xr ,-1); //
    glPopMatrix();
    glEnd();
}
void arrow2(){
     glPushMatrix();
    glBegin(GL_LINES);
    glColor3f(0,1,0);
    //glTranslated(-2.5,-4,0);
    glVertex2d(-2.5,-3);
    glVertex2d(-2.5+xr2 ,-1); ///
    glPopMatrix();
    glEnd();

}
void cGun(){
    glPushMatrix();
    //glTranslatef(4,-1,0);
    glScalef(1,.7,1);
    glColor3f(0,0,0);
    glRotatef(45.0,1,0,0);
    glTranslatef(3.5,-6,2);
    gluCylinder(gluNewQuadric(),.6,.8,1,100,100);
    glPopMatrix();
}
void cGun2(){
    glPushMatrix();
    //glTranslatef(4,-1,0);
    glScalef(1,.7,1);
    glColor3f(0,1,0);
    glRotatef(45.0,1,0,0);
    glTranslatef(-3.5,-6,2);
    //glScaled(1,2,2);
    gluCylinder(gluNewQuadric(),.6,.8,1,100,100);
    glPopMatrix();
}  
void renderScene(){
    glClearColor(0,0,0,1);
    glClearDepth(1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);


    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(5,-5,1);
    glVertex3f(-5,-5,1);
    glVertex3f(-1,3,3);
    glVertex3f(1,3,3);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5,0,-9);
    char2();
    glPopMatrix();
    
     glPushMatrix();
    //glTranslatef(-4,0,-4);
    char2();
    glPopMatrix(); 

    glPushMatrix();
    glTranslatef(2,0,-10);
    char2();
    glPopMatrix(); 
    

    glPushMatrix();
    glTranslatef(0,0,-10);
    char2();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(6,0,-9);
    char2();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(0,8,-7);
    char2();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(3,4,-16);
    char2();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(-3,4,-16);
    char2();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(0,4,-16);
    char2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,7,-16);
    char2();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(-5,7,-16);
    char2();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-3,9,-17);
    char2();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2,9,-17);
    char2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,9,-17);
    char2();
    glPopMatrix(); 
    
    cGun();
    cGun2();
    arrow1();
    arrow2();
    std::string play1;
    play1="PLAYER 1: ";
    //glTranslated(-5,5,0);
    //glColor3f(0,0,1);
    drawtext(play1.data(),play1.size(),70,500);
    
     

    /* if(player1>player2 && counter>10){
    std::string win1;
    win1="PLAYER 1 is WINNER";
     (play1.data(),play1.size(),70,300);
    cout<<"player1--";
    }
    else if(player2>player1 && counter>10){
    std::string win2;
    win2="PLAYER 2 is WINNER";
    drawtext(play1.data(),play1.size(),200,300);
    cout<<"player2 !!";
    }*/
    glutSwapBuffers();
    glEnd();

}

static void specialKey(unsigned char key,int x,int y){
    switch (key)
    {   
        case 'w':
            player1++;
            counter++;
            glutPostRedisplay();
            break;
        
        case 'a':
            xr-=.5;
            glutPostRedisplay();
            break;
        case 'd':
            xr+=.5;
            glutPostRedisplay();
            break;
            
        //PLAYER 2 
        case 'i':
            player2++;
            counter++;
            glutPostRedisplay();
            break;
        case 'j':
            xr2-=.5;
            glutPostRedisplay();
            break;
        case 'l':
            xr2+=.5;
            glutPostRedisplay();
            break;
    }
}

int main(int argc, char **argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,200);
    glutInitWindowSize(width,height);
    glutCreateWindow("17101330 - 17100492");
    system("/home/mohamed/Desktop/graphics");
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    
    glutKeyboardFunc(specialKey);
    glutReshapeFunc(changeSize);

    glutMainLoop();

    return(0);
}
