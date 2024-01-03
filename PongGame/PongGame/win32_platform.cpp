/**
 * @brief this file will hold all the platform specific code for the window platform layer
 * @read more at: winmain msdn
 */

#include <Windows.h>

bool running = true;

LRESULT CALLBACK WindowCallback(	HWND hwnd,
									UINT uMsg,
									WPARAM wParam,
									LPARAM lParam)
{
	LRESULT result = 0;

	switch (uMsg)
	{

		case WM_CLOSE: 
		case WM_DESTROY:
			running = false;
			break;
		default: 
			result = DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return result;
}

int WinMain(				HINSTANCE hInstance,
							HINSTANCE hPrevInstance,
							LPSTR     lpCmdLine,
							int       nShowCmd		)
{
	//	DRAW WINDOW ON WINDOW
	// Create Window Class
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = "Game Window Class";
	window_class.lpfnWndProc = WindowCallback; //Passes message information to the specified window procedure.

	// Register Class
	RegisterClass(&window_class); //Registers a window class for subsequent use in calls to the CreateWindow or CreateWindowEx function.

	//Create Window
	HWND window = CreateWindow(			window_class.lpszClassName,
							"Pong Game",
							WS_OVERLAPPEDWINDOW | WS_VISIBLE,
							CW_USEDEFAULT,
							CW_USEDEFAULT,
							1280,
							720,
							0,
							0,
							hInstance,
							0);
	while (running)
	{
		//Input
		MSG message;
		while (PeekMessage(&message, window, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		//Simulate

		//Render
	}
}