#include<Windows.h>
#include<GL.h>
#include<glut.h>
#include<math.h> 
void myInit(void);
void myMouse(int, int, int, int);
void myDisplay(void);
void keyboard(unsigned char, int , int );
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//argc= arg count, specifies no. of arguments
	//argv=arg values, specifies values of those arguments
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  //glut_single means 2d view use glut_double for 3d
	glutInitWindowSize(600, 600);    //size of the main window
	glutInitWindowPosition(100, 100);   //position of the main window
	glutCreateWindow("triangle striping");  //to create the tilte of window
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(myMouse);
	myInit();   //function call  a function which contain all initializations 
	glutMainLoop();  //hold output just like getch() in c
}
float r=-0.1, g=0.2, b=0.3;
void myMouse(int button, int state, int x, int y)
{
	
	if (button == GLUT_LEFT_BUTTON)
	{
		if (r <1 && g<1 && b<1)
		{
			r += 0.1;
			b += 0.1;
			g += 0.1;
			//float r = (rand() % 10)*0.3;
			//float g = (rand() % 10)*0.3;
			//float b = (rand() % 10)*0.3;
			//glColor3f(0.1, 0.2, 0.3);
			glBegin(GL_POINTS);
			glColor3f(r, g, b);
			glVertex2f(x, 600 - y);
			glEnd();
			glFlush();
		}
		else {
			r = 0;
			g = 0.1;
			b = 0.1;
		}
	}
}
void keyboard(unsigned char key, int x, int y)
{
	if (key == 69||key==101)    // 'q'
	{
		exit(0);
	}
}
void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(15.0);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	gluOrtho2D(0, 600, 0, 600);
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
