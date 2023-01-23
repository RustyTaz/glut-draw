#include <GL/gl.h> 
#include <GL/glu.h>
#include <GL/glut.h>

void display(void) { 
 GLfloat lp[4] = {1.0, 0.2, 0, 1}; 
 glEnable(GL_DEPTH_TEST);
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
 glEnable(GL_DEPTH_TEST);               
 glLightfv(GL_LIGHT0, GL_POSITION, lp); 
 glEnable(GL_LIGHT0);                   
 glEnable(GL_LIGHTING);                 
 glEnable(GL_COLOR_MATERIAL);           
 glEnable(GL_NORMALIZE);
	
 GLUquadricObj* QuadrObj;
 QuadrObj=gluNewQuadric();

 // Стол с ножками	
 glLoadIdentity();			
 glTranslatef (0.4,-0.2,0.3);						
 glRotatef(90.0,1.0,0.0,0.0);
 glColor3f(0.7f, 0.35f, 0.1f);    
 gluCylinder(QuadrObj,0.1,0.1,1,30,30);	
 
 glLoadIdentity();			
 glTranslatef (-0.4,-0.2,0.3);						
 glRotatef(90.0,1.0,0.0,0.0);
 glColor3f(0.7f, 0.35f, 0.1f);    
 gluCylinder(QuadrObj,0.1,0.1,1,30,30);
 
 glLoadIdentity();			
 glTranslatef (0.0,-0.2,0.0);						
 glRotatef(90.0,1.0,0.0,0.0);
 glColor3f(0.7f, 0.35f, 0.1f);    
 gluCylinder(QuadrObj,0.8,0.8,0.2,30,30);
 
 //Бутылка
 //midle
 glLoadIdentity();			
 glTranslatef (-0.2,0.2,0.2);						
 glRotatef(90.0,1.0,0.0,0.0);
 glColor3f(0.0f, 255, 255);    
 gluCylinder(QuadrObj,0.08,0.08,0.4,30,30);
 //lower
 glLoadIdentity();			
 glTranslatef (-0.2,0.0,0.19);						
 glRotatef(90.0,1.0,0.0,0.0);
 glColor3f(0, 255, 255);    
 gluCylinder(QuadrObj,0.08,0.08,0.2,30,30);
 //sign
 glLoadIdentity();			
 glTranslatef (-0.2,0.15,0.19);						
 glRotatef(90.0,1.0,0.0,0.0);
 glColor3f(0, 0, 205);    
 gluCylinder(QuadrObj,0.08,0.08,0.11,30,30);
 //2nd sign
 glLoadIdentity();			
 glTranslatef (-0.2,0.12,0.09);						
 glRotatef(90.0,1.0,0.0,0.0);
 glColor3f(255, 250, 250);    
 gluCylinder(QuadrObj,0.08,0.08,0.05,30,30);


 /////
 glLoadIdentity(); 
 glTranslatef (-0.2,0.2,0.2);
 glRotatef(90.0,1.0,0.0,0.0);
 glColor3f(0.0, 255, 255); 
 glutSolidSphere(0.08, 30, 30);
 //cap
 glLoadIdentity();			
 glTranslatef (-0.2,0.37,0.2);						
 glRotatef(90.0,1.0,0.0,0.0);
 glColor3f(0, 0, 205);    
 gluCylinder(QuadrObj,0.02,0.02,0.1,30,30);
 
 //Рюмки
 
 glLoadIdentity();			
 glTranslatef (-0.5,-0.1,0.2);						
 glRotatef(90.0,1.0,0.0,0.0);
 glColor3f(0.0f, 255, 255);    
 gluCylinder(QuadrObj,0.06,0.04,0.1,30,30);
 
 //glLoadIdentity();			
 //glTranslatef (0.2,-0.15,0.19);						
 //glRotatef(90.0,1.0,0.0,0.0);
 //glColor3f(240.0f, 0, 0);    
 //gluCylinder(QuadrObj,0.054,0.04,0.05,30,30);
 
 glLoadIdentity();			
 glTranslatef (0.1,-0.1,0.2);						
 glRotatef(90.0,1.0,0.0,0.0);
 glColor3f(0.0f, 255, 255);    
 gluCylinder(QuadrObj,0.06,0.04,0.1,30,30);
 

	
 glutSwapBuffers();  
 glFlush(); 
} 

void reshape(int w, int h) 
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void main (int argc, char** argv) {  
glutInit (&argc, argv);
glutReshapeFunc(reshape);
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowPosition (50, 50); 
glutInitWindowSize (600, 600);
glutCreateWindow ("Bottle on the table");
glClearColor (0., 0.225, 0.225, 0.);
glutDisplayFunc(display); 
glutMainLoop (); 
} 
