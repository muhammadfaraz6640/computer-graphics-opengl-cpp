#include<Windows.h>
#include<GL.h>
#include<glut.h>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
/*GLfloat xRotated, yRotated, zRotated;
float tx, ty ,tz;
void display(void);
void transformation(void);
void reshape_obj(GLsizei , GLsizei );
void idle(void)
{
	xRotated = xRotated + 0.03;
	yRotated += 0.03;
	zRotated += 0.03;
	display();
}
void myinit()
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}
int choice;
void display(void)
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1, 1.0, 0.0);
		cout << "enter your choice of object : " << endl;
		cout << "press '1' for cube : " << endl;
		cout << "press '2' for sphere : " << endl;
		cout << "press '3' for exit : " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			glutSolidCube(0.6);
			transformation();
			glutSolidCube(0.6);
			break;
		}
		case 2:
		{
			glutSolidSphere(0.3, 10, 12);
			transformation();
			glutSolidSphere(0.3, 10, 12);
			break;
		}
		case 3:
		{
			exit(0);
			break;
		}
		default:
			break;
		}
	glFlush();
}

void reshape_obj(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.5, 1.5, -1.5*(GLfloat)480 / (GLfloat)640,1.5*(GLfloat)480 / (GLfloat)640, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	zRotated = 30.0;
	xRotated = 43;
	yRotated = 50;
	glutCreateWindow("CUBE_LIGHT");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape_obj);
	myinit();
	glutIdleFunc(idle);
	glutMainLoop();
}
int choice_t;
char dir_rot;
float sx, sy, sz;
void transformation(void)
{
	cout << "enter your choice of transformation : " << endl;
	cout << "press '1' for translation : " << endl;
	cout << "press '2' for rotation : " << endl;
	cout << "press '3' for scaling : " << endl;
	cout << "press '4' for exit : " << endl;
	cin >> choice_t;
	switch (choice_t)
	{
	case 1:
	{
		cout << "enter translation factor : " << endl;
		cin >> tx;
		cin >> ty;
		cin >> tz;
		glTranslatef(tx, ty, tz);
		break;
	}
	case 2:
	{
		cout << "enter rotation direction : " << endl;
		cin >> dir_rot;
		if (dir_rot == 'x' || dir_rot == 'X')
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glLoadIdentity();
			glRotatef(xRotated, 1.0, 0.0, 0.0);  // rotation about X axis
			glRotatef(yRotated, 0.0, 1.0, 0.0);
			glRotatef(zRotated, 0.0, 0.0, 1.0);
		}
		else if (dir_rot == 'y' || dir_rot == 'Y')
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glLoadIdentity();
			glRotatef(yRotated, 0.0, 1.0, 0.0);  // rotation about Y axis
			glRotatef(xRotated, 1.0, 0.0, 0.0);
			glRotatef(zRotated, 0.0, 0.0, 1.0);	
		}
		else if (dir_rot == 'z' || dir_rot == 'Z')
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
			glLoadIdentity();
			glRotatef(zRotated, 0.0, 0.0, 1.0);  // rotation about Z axis
			glRotatef(yRotated, 0.0, 1.0, 0.0);
			glRotatef(xRotated, 1.0, 0.0, 0.0);
		}
		break;
	}
	case 3:
	{
		cout << "enter scaling factors : " << endl;
		cin >> sx;
		cin >> sy;
		cin >> sz;
		glScalef(sx, sy, sz);
		break;
	}
	case 4:
	{
		exit(0);
	}
	default:
		break;
	}
}*/
#include<vector>

vector<int> X_Points;
vector<int> Y_Points;
int X1_Points, Y1_Points, choice = 0, edges;
int translate_X, translate_Y;
double scale_X, scale_Y;
double angle, angle_Radian;
char reflectionAxis, shearingAxis;
int shearing_X, shearing_Y;

double round(double d)
{
	return floor(d + 0.5);
}

void create_Polygon()
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.7, 0.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(X_Points[i], Y_Points[i]);
	}
	glEnd();
}


void Translate_Polygon(int x, int y)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(X_Points[i] + x, Y_Points[i] + y);
	}
	glEnd();
}

void Scale_Polygon(double x, double y)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(round(X_Points[i] * x), round(Y_Points[i] * y));
	}
	glEnd();
}

void Rotate_Polygon(double angleRad)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(round((X_Points[i] * cos(angleRad)) - (Y_Points[i] * sin(angleRad))), round((X_Points[i] * sin(angleRad)) + (Y_Points[i] * cos(angleRad))));
	}
	glEnd();
}

void Reflect_Polygon(char reflectionAxis)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);

	if (reflectionAxis == 'x' || reflectionAxis == 'X')
	{
		for (int i = 0; i < edges; i++)
		{
			glVertex2i(round(X_Points[i]), round(Y_Points[i] * -1));

		}
	}
	else if (reflectionAxis == 'y' || reflectionAxis == 'Y')
	{
		for (int i = 0; i < edges; i++)
		{
			glVertex2i(round(X_Points[i] * -1), round(Y_Points[i]));
		}
	}
	glEnd();
}

void Shear_Polygon()
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);

	if (shearingAxis == 'x' || shearingAxis == 'X')
	{
		glVertex2i(X_Points[0], Y_Points[0]);

		glVertex2i(X_Points[1], Y_Points[1]);
		glVertex2i(X_Points[2] + shearing_X, Y_Points[2]);

		glVertex2i(X_Points[3] + shearing_X, Y_Points[3]);
	}
	else if (shearingAxis == 'y' || shearingAxis == 'Y')
	{
		glVertex2i(X_Points[0], Y_Points[0]);
		glVertex2i(X_Points[1], Y_Points[1] + shearing_Y);

		glVertex2i(X_Points[2], Y_Points[2] + shearing_Y);
		glVertex2i(X_Points[3], Y_Points[3]);
	}
	glEnd();
}




void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}


void myDisplay(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(-640, 0);
	glVertex2i(640, 0);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(0, 480);
	glVertex2i(0, -480);
	glEnd();
	glFlush();


	if (choice == 1)
	{
		create_Polygon();
		Translate_Polygon(translate_X, translate_Y);
	}
	else if (choice == 2)
	{
		create_Polygon();
		Scale_Polygon(scale_X, scale_Y);
	}
	else if (choice == 3)
	{
		create_Polygon();
		Rotate_Polygon(angle_Radian);
	}
	else if (choice == 4)
	{
		create_Polygon();
		Reflect_Polygon(reflectionAxis);
	}
	else if (choice == 5)
	{
		create_Polygon();
		Shear_Polygon();
	}
	glFlush();
}

void main(int argc, char** argv)
{
	system("color f4");
	cout << "\t\t\t\t\t\tWELCOME TO 2D TRANSFORMATIONS\n\n" << endl;
	cout << "Please Choose what type of transformation you want to perform:\n" << endl;

	cout << "1. Translation" << endl;
	cout << "2. Scaling" << endl;
	cout << "3. Rotation" << endl;
	cout << "4. Mirror Reflection" << endl;
	cout << "5. Shearing" << endl;
	cout << "6. Exit" << endl;

	cin >> choice;

	if (choice == 6) {
		return;
	}

	cout << "\n\nLET'S DRAW POLYGON FIRST:\n" << endl;

a:
	cout << "Enter no of edges of polygon: "; cin >> edges;

	if (choice == 5) {
		if (edges <= 3) {
			cout << "For shearing the polygon should be of atleast 4 edges. Enter again.\n\n";
			goto a;
		}
	}

	if (edges <= 2) {
		cout << "A polygon has atleast 3 edges. Enter again.\n\n";
		goto a;
	}
	else if (edges > 2) {
		for (int i = 0; i < edges; i++)
		{
			cout << "Enter co-ordinates for vertex  " << i + 1 << " : "; cin >> X1_Points >> Y1_Points;
			X_Points.push_back(X1_Points);
			Y_Points.push_back(Y1_Points);
		}

		if (choice == 1)
		{
			cout << "\nEnter the translation factor for X and Y axis: "; cin >> translate_X >> translate_Y;
		}
		else if (choice == 2)
		{
			cout << "\nEnter the scaling factor for X and Y axis: "; cin >> scale_X >> scale_Y;
		}
		else if (choice == 3)
		{
			cout << "\nEnter the angle for rotation: "; cin >> angle;
			angle_Radian = angle * 3.1416 / 180;
		}
		else if (choice == 4)
		{
			cout << "\nEnter reflection axis ( x or y ): "; cin >> reflectionAxis;
		}
		else if (choice == 5)
		{
			cout << "Enter shearing axis ( x or y ): "; cin >> shearingAxis;
			if (shearingAxis == 'x' || shearingAxis == 'X')
			{
				cout << "Enter the shearing factor for X: "; cin >> shearing_X;
			}
			else
			{
				cout << "Enter the shearing factor for Y: "; cin >> shearing_Y;
			}
		}
	}




	cout << endl << endl;
	for (int i = 0; i < edges; i++) {
		cout << "Points:(" << X_Points[i] << ", " << Y_Points[i] << ")" << endl;
	}
	if (choice == 1) {
		cout << "Translation factors:(" << translate_X << ", " << translate_Y << ")" << endl;
	}
	else if (choice == 2) {
		cout << "Scaling factors:(" << scale_X << ", " << scale_Y << ")" << endl;
	}
	else if (choice == 3) {
		cout << "Angle:" << angle;
	}
	else if (choice == 4) {
		cout << "Reflection axis: " << reflectionAxis << endl;
	}
	else if (choice == 5) {
		cout << "\nShearing axis: " << shearingAxis << endl;
		if (shearingAxis == 'x' || shearingAxis == 'X') {
			cout << "Shearing factor: " << shearing_X << endl;
		}
		else {
			cout << "Shearing factor: " << shearing_Y << endl;
		}
	}


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(300, 50);
	glutCreateWindow("2D TRANSFORMATIONS");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();

}