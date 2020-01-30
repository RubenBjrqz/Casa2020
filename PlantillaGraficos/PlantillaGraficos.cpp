// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

using namespace std;

void dibujar()
{
	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.1f, 0.0f);

	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, 0.5f, 0.0f);
	glVertex3f(1.0f, -0.5f, 0.0f);

	glEnd();

	//Fondo
	glBegin(GL_QUADS);

	glColor3f(0.5f, 1.0f, 1.0f);

	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -0.5f, 0.0f);
	glVertex3f(-1.0f, -0.5f, 0.0f);

	glEnd();

	//Casa
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex3f(-0.5f, 0.1f, 0.0f);
	glVertex3f(0.5f, 0.1f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);

	glEnd();

	//Puerta
	glBegin(GL_QUADS);

	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex3f(-0.09f, -0.2f, 0.0f);
	glVertex3f(0.09f, -0.2f, 0.0f);
	glVertex3f(0.09f, -0.5f, 0.0f);;
	glVertex3f(-0.09f, -0.5f, 0.0f);

	glEnd();

	//Ventana
	glBegin(GL_QUADS);

	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex3f(0.4f, -0.1f, 0.0f);
	glVertex3f(0.2f, -0.1f, 0.0f);
	glVertex3f(0.2f, -0.3f, 0.0f);
	glVertex3f(0.4f, -0.3f, 0.0f);

	glEnd();

	//Techo
	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);

	glVertex3f(-0.7f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.7f, 0.0f);
	glVertex3f(0.7f, 0.0f, 0.7f);

	glEnd();

	//Sol
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.5f, 0.0f);
	for (float i = 0; i < 360; i++)
	{
		glVertex3f(0.3 * cos(i) + -1.0, 0.3 * sin(i) + 0.9, 0.0f);
	}
	glEnd();

	//Ventana circulo
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 1.0f);
	for (float i = 0; i < 360; i++)
	{
		glVertex3f(0.2 * cos(i) + 0.005, 0.15 * sin(i) + 0.3, 0.3f);
	}
	glEnd();

}

int main()
{
	//Declarar una ventana
	GLFWwindow* window;

	//Si no se pudo iniciar GLFW terminamos ejecucion
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW inicializamos la ventana
	window = glfwCreateWindow(600, 600, "Colors", NULL, NULL);

	//Si no se pudo crear la ventana terminamos la ejecucion
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto se activan las funciones "modernas" (gpu)
	glewExperimental = true;

	GLenum errores = glewInit();
	if (errores != GLEW_OK)
	{
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL =
		glGetString(GL_VERSION);
	cout << "Version OPENGL: " << versionGL;

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window))
	{
		//Establecer region de dibujo
		glViewport(0, 0, 600, 600);
		//Establecemos el color de borrado
		//Valores RGBA
		glClearColor(0.1,0.1,0.1,1);
		//Borrar!
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Actualizar valores y dibujar
		dibujar();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	//Despues del ciclo de dibujo eliminamos venta y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}
