#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


void drawPoint(float x, float y)
{
	x = (x / SCR_WIDTH) * 2 - 1;
	y = (y / SCR_HEIGHT) * 2 - 1;

	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void drawPoint(float x, float y, float r, float g, float b)
{
	x = (x / SCR_WIDTH) * 2 - 1;
	y = (y / SCR_HEIGHT) * 2 - 1;

	glBegin(GL_POINTS);
	glColor3f(r, g, b);
	glVertex2f(x, y);
	glColor3f(1.f, 1.f, 1.f);
	glEnd();
}



int main()
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();

	// hint the version required: OpenGL 2.0
	constexpr int version = 20;
	glfwWindowHint(GLFW_OPENGL_API, GLFW_OPENGL_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, version / 10);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, version % 10);
	if (version >= 33)
	{
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	}

	// glfw window creation
	// --------------------
	GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// input
		// -----
		processInput(window);

		// glPointSize(2.0f);
		drawPoint(400, 300);
		drawPoint(100, 100, 1.f, 0.f, 0.f);

		// drawPoint(1/(float)SCR_WIDTH, 1/(float)SCR_WIDTH);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}