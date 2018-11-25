#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// window dimensions
const GLint width = 800;
const GLint height = 600;

int main()
{
	// Initialize GLFW
	if (!glfwInit())
	{
		printf("GLFW initialization failed");
		glfwTerminate();
		return 1;
	}

	// Setup GLFW window properties
	// OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core profile = no backwards compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Allow forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// DW fun1, must be setup before glfwCreateWindow
	glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

	GLFWwindow *mainWindow = glfwCreateWindow(width, height, "Cool Window", NULL, NULL);
	if (!mainWindow)
	{
		printf("GLFW window creation failed");
		glfwTerminate();
		return 1;
	}

	// DW fun2, must be setup after glfwCreateWindow
	glfwSetWindowPos(mainWindow, 100, 100);

	// Get buffer size information
	int bufferWidth;
	int bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set the context for GLEW to use
	glfwMakeContextCurrent(mainWindow);

	// Allow modern extenstion features
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("GLEW initialization failed");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	// Setup viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);

	// Loop until window closed
	while (!glfwWindowShouldClose(mainWindow))
	{
		// get + handle user input events
		glfwPollEvents();

		// clear the window
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
	}

	return 0;
}