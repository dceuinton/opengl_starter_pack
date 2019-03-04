
// A helloworld opengl example that I borrowed from anton gerdelan:
// https://github.com/capnramses/antons_opengl_tutorials_book/blob/master/00_hello_triangle/main.c

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>

using namespace std;

int main() {

	// start context and window using GLFW
	if (!glfwInit()) {
		cout << "glfwInit() failed" << endl;
		exit(1);
	}

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

	// stop gl context and other glfw resources
	glfwTerminate();

	return 0;
}