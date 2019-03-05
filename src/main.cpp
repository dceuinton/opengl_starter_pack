
// A helloworld opengl example that I borrowed from anton gerdelan:
// https://github.com/capnramses/antons_opengl_tutorials_book/blob/master/00_hello_triangle/main.c

#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include<glm/glm.hpp>

#include <iostream>
#include <vector>

using namespace std;

struct GLObject {
	vector<glm::vec4> vertices;
	vector<glm::ivec3> indices;
	GLuint vao;		// vertex array object
	GLuint vbo;		// vertex buffer object
	GLuint ebo;		// element buffer object
	GLuint sp;		// shader program
};

int main() {

	// start context and window using GLFW
	if (!glfwInit()) {
		cout << "glfwInit() failed" << endl;
		exit(1);
	}

	GLObject square;
	square.vertices.push_back(glm::vec4(-0.5f, 0.5f, 0.0f, 0.0f));
	square.vertices.push_back(glm::vec4(0.5f, 0.5f, 0.0f, 0.0f));
	square.vertices.push_back(glm::vec4(0.5f, -0.5f, 0.0f, 0.0f));
	square.vertices.push_back(glm::vec4(-0.5f, -0.5f, 0.0f, 0.0f));

	square.indices.push_back(glm::ivec3(0, 1, 2));
	square.indices.push_back(glm::ivec3(0, 2, 3));

	GLFWwindow* window = glfwCreateWindow(640, 480, "HelloWorld", nullptr, nullptr);

	if (!window) {
		fprintf(stderr, "ERROR: couldn't open window with GLFW3\n");
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);

	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	while(!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.5f, 0.5f, 0.5f, 0.0f);

		glfwPollEvents();
		glfwSwapBuffers(window);

		if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {	break; }
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) { break; }
	}

	// stop gl context and other glfw resources
	glfwTerminate();

	return 0;
}