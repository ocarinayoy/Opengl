////******* Modified and upload by: Magaña Abarca Sergio De Jesus.            Graficación 5 Semestre
////******* Author: Moreno Avila Jazmín.

#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <gl\glut.h>
using namespace std;
/**VARIABLES*****************************/
float w = 600, h = 600;
double EyeX = 0.0, EyeY = 0.0, EyeZ = 0.0, CenterX, CenterY = 12, CenterZ, UpX, UpY = 1, UpZ;
//figuras
float angulolento = 0.0; //ANGULO DE ROTACIÓN
float s = 0.1; //SUMADOR DEL ANGULO DE ROTACIÓN
float na = 10.0; //NUMERO DE ALAMBRES

/**INICIALIZA****************************/
void Inicializar(void) {
    glMatrixMode(GL_PROJECTION);
    glClearColor(0, 0, 1, 0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);//Profundidad
    glOrtho(-15, 18, 0, 15, -15, 15);
}
/**TEXTO********************************/
void Texto(int tipoletra, int PosX, int PosY, char *s) {
    unsigned int i;
    glRasterPos2i(PosX, PosY);
    for ( i = 0; i < strlen(s); i++)
        switch ( tipoletra ) {
        case 1:
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s[i]);
            break;
        case 2:
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, s[i]);
            break;
        case 3:
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
            break;
        case 4:
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, s[i]);
            break;
        case 5:
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
            break;
        case 6:
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
            break;
        }
}
/***FIGURAS DE ALAMBRE**********************************/
void Dibuja() {
    glColor3f(0.7, 0.0, 0.9);
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    Texto(6, -6, 14, "FUNCIONES PRECARGADAS EN OPENGL");
    //FIGURA DEL CONO
    glColor3f(0.7, 0.0, 0.9);
    Texto(1, -14, 12, "Cono");
    glColor3f(0.7, 0.0, 0.9);
    glPushMatrix();
    glTranslatef(-13.0, 9.0, 0.0);
    glRotatef(angulolento, 1.0, 1.0, 1.0);
    glutWireCone(1.5, 2.5, na, 20.0);
    glPopMatrix();

    //FIGURA DE LA ESFERA
    glColor3f(0.7, 0.0, 0.9);
    Texto(1, -8, 12, "Esfera");
    glColor3f(0.7, 0.0, 0.9);
    glPushMatrix();
    glTranslatef(-7.0, 9.0, 0.0);
    glScalef(1.6, 1.6, 1.6);
    glRotatef(angulolento, 1.0, 1.0, 1.0);
    glutWireSphere(1.0, na, 20.);
    glPopMatrix();

    //FIGURA DEL TOROIDE
    glColor3f(0.7, 0.0, 0.9);
    Texto(1, -2, 12, "Toroide");
    glColor3f(0.7, 0.0, 0.9);
    glPushMatrix();
    glTranslatef(-1.0, 9.0, 0.0);
    glRotatef(angulolento, 1.0, 1.0, 1.0);
    glutWireTorus(0.7, 1.4, na, 15.0);
    glPopMatrix();
    angulolento += s;
    if (angulolento > 360)
        angulolento = 0.01;
    glutPostRedisplay();
}
/**PROYECCION****************************/
void Redimencionar(int w, int h) {
    glLoadIdentity();
    gluPerspective(90, (GLfloat)h / (GLfloat)w, 1, 300); //Campo de visión//perspectiva
    glMatrixMode(GL_MODELVIEW);
}
/**PLANO********************************/
void Plano(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    /**< Camara */
    gluLookAt(-30 + EyeX, 12 + EyeY, 15 + EyeZ, CenterX, CenterY, CenterZ, UpX, UpY, UpZ); //posición de la camara :3
    glPushMatrix();

    /**CUADRICULA*/
    for(float i = -100; i < 100; i += 1.1) {
        glColor3f(1.0f, 0.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex3f(i, 0, -100);
        glVertex3f(i, 0, 100);
        glEnd();
    }
    for(float i = -100; i < 100; i += 1.1) {
        glColor3f(1.0f, 0.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        glVertex3f(-100, 0, i);
        glVertex3f(100, 0, i);
        glEnd();
    }

    /**ejes**/
    //y
    glColor3f(0.0f, 1.0f, 0.0f); //Verde
    glBegin(GL_LINE_STRIP);
    glVertex3f(0, -100, 0);
    glVertex3f(0, 100, 0);
    glEnd();
    //x
    glColor3f(1.0f, 0.0f, 0.0f); //ROJO
    glBegin(GL_LINE_STRIP);
    glVertex3f(-100, 0, 0);
    glVertex3f(100, 0, 0);
    glEnd();
    //z
    glColor3f(0.0f, 0.0f, 1.0f); //Azul
    glBegin(GL_LINE_STRIP);
    glVertex3f(0, 0, -100);
    glVertex3f(0, 0, 100);
    glEnd();
    Dibuja();
    glPopMatrix();
    glutSwapBuffers();
}
void Teclado(unsigned char key, int EyeX, int EyeY) {
    switch(key) {
    /**Rotacion - Eje XZ*/
    case 'a':
        //CenterX -=5;
        //Primer movimiento
        if (CenterX > -50 && CenterZ <= 0) {
            CenterX -= 5;
        }
        //Segundo movimiento
        if(CenterZ < 50 && CenterX <= -50) {
            CenterZ += 5;
        }
        //Tercer movimiento
        if(CenterX < 50 && CenterZ >= 50) {
            CenterX += 5;
        }
        //Cuarto movimiento
        if(CenterZ > -50 && CenterX >= 0) {
            CenterZ -= 5;
        }

        cout << CenterX << endl;
        break;
    /**Rotacion + Eje XZ*/
    case 'd':


        if(CenterZ <  50 && CenterX >= 0) {
            CenterZ += 5;
        }
        if(CenterX > -50 && CenterZ >= 50) {
            CenterX -= 5;
        }
        if(CenterZ > -50 && CenterX <= -50) {
            CenterZ -= 5;
        }
        if(CenterX <  50 && CenterZ <= 0) {
            CenterX += 5;
        }

        cout << CenterX << endl;
        break;
    /**Y*/
    case 'w':
        CenterY = CenterY + 5;

        break;
    case 's':
        CenterY = CenterY - 5;
        break;
        }
    glutPostRedisplay();
}

void Flechas(int key, int EyeX, int EyeY) {
    switch(key) {
    case GLUT_KEY_RIGHT:
        EyeZ = EyeZ + 5;
        CenterZ = CenterZ + 5;

        break;
    case GLUT_KEY_LEFT:
        EyeZ = EyeZ - 5;
        CenterZ = CenterZ - 5;

        break;
    case GLUT_KEY_UP:
        EyeX = EyeX + 5;
        CenterX = CenterX + 5;

        break;
    case GLUT_KEY_DOWN:
        EyeX = EyeX - 5;
        CenterX = CenterX - 5;
        break;
    }
    glutPostRedisplay();
}
int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition (50, 100);
    glutInitWindowSize (800, 600); // Establece alto y ancho de la pantalla
    glutCreateWindow ("Lookat XZ rotation");
    Inicializar();
    glutDisplayFunc(Plano);
    glutKeyboardFunc(Teclado);
    glutSpecialFunc(Flechas);
    glutReshapeFunc(Redimencionar);
    glutMainLoop();
    system("PAUSE");
    return EXIT_SUCCESS;
}
