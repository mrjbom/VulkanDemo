#include <iostream>
#include <exception>
#include "MainWindow/MainWindow.h"
#include "ErrorInfo/ErrorInfo.h"

MainWindow mainWindow;

int main(int argc, char* argv[])
{
	try
	{
		mainWindow.initVulkan();
		mainWindow.renderLoop();
		if (mainWindow.minimizedWindowNeedClose == false) {
			mainWindow.finishVulkan();
		}
	}
	catch (std::exception ex)
	{
#ifdef _DEBUG
		std::cout << "MainWindow exception: " << ex.what() << std::endl;
#endif
		return EXIT_FAILURE;
	}
	catch (ErrorInfo errInfo)
	{
#ifdef _DEBUG
		std::string errInfoStr = "MainWindow exception\n"
			+ (std::string)"What: " + errInfo.what + "\n"
			+ (std::string)"File: " + errInfo.file + "\n"
			+ (std::string)"Line: " + errInfo.line + "\n";
		std::cout << errInfoStr;
#endif
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}