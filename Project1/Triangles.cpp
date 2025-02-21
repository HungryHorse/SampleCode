//////////////////////////////////////////////////////////////////////////////
//
//  Triangles.cpp
//
//////////////////////////////////////////////////////////////////////////////

#include "GL/glew.h"
#include "GL/freeglut.h"
#include "GLFW/glfw3.h"
#include "LoadShaders.h"






enum VAO_IDs { Triangles, NumVAOs };
enum Buffer_IDs { ArrayBuffer, NumBuffers };
enum Attrib_IDs { vPosition = 0 };

GLuint  VAOs[NumVAOs];
GLuint  Buffers[NumBuffers];

const GLuint  NumVertices = 24;

//----------------------------------------------------------------------------
//
// init
//
#define BUFFER_OFFSET(a) ((void*)(a))


void
init(void)
{
	glGenVertexArrays(NumVAOs, VAOs);
	glBindVertexArray(VAOs[Triangles]);

	GLfloat  vertices[NumVertices][2] = {
		{ -0.99f,  0.40f }, {  -0.99f, 0.39f }, { 0.99f,  0.40f },  // Triangle 1
		{ -0.99f,  0.39f }, {   0.99,   0.39f }, { 0.99f,  0.40f }, // Triangle 2
		{ -0.99f,  -0.40f }, {  -0.99f, -0.39f }, { 0.99f,  -0.40f },  // Triangle 3
		{ -0.99f,  -0.39f }, {   0.99,   -0.39f }, { 0.99f,  -0.40f }, // Triangle 4
		{ 0.40f, -0.99f }, {  0.39f, -0.99f}, { 0.40f, 0.99f },  // Triangle 5
		{ 0.39f, -0.99f }, {  0.39f, 0.99 }, { 0.40f, 0.99f }, // Triangle 6
		{ -0.40f, -0.99f }, {  -0.39f, -0.99f }, { -0.40f, 0.99f },  // Triangle 7
		{  -0.39f, -0.99f }, {   -0.39f, 0.99 }, { -0.40f, 0.99f }, // Triangle 8
	};

	glGenBuffers(NumBuffers, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
	glBufferStorage(GL_ARRAY_BUFFER, sizeof(vertices), vertices, 0);

	ShaderInfo  shaders[] =
	{
		{ GL_VERTEX_SHADER, "media/triangles.vert" },
		{ GL_FRAGMENT_SHADER, "media/triangles.frag" },
		{ GL_NONE, NULL }
	};

	GLuint program = LoadShaders(shaders);
	glUseProgram(program);

	glVertexAttribPointer(vPosition, 2, GL_FLOAT,
		GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vPosition);
}

//----------------------------------------------------------------------------
//
// display
//

void
display(void)
{
	static const float black[] = { 0.0f, 0.0f, 0.0f, 0.0f };

	glClearBufferfv(GL_COLOR, 0, black);

	glBindVertexArray(VAOs[Triangles]);
	glDrawArrays(GL_TRIANGLES, 0, NumVertices);
}

//----------------------------------------------------------------------------
//
// main
//


int
main(int argc, char** argv)
{
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(800, 600, "Triangles", NULL, NULL);

	glfwMakeContextCurrent(window);
	glewInit();

	init();

	while (!glfwWindowShouldClose(window))
	{
		display();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
}
