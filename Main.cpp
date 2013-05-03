#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <GL/glut.h>

#include "Main.hpp"
#include "Config.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    glutInit(&argc, argv);


    Main::init();

    static MainWindow mainWindow;
    mainWindow.show();
    


    return a.exec();
}

void Main::reportError(std::string error)
{
    std::cout << "Error: " << error << std::endl;
}

void Main::die(const std::string& reason)
{
    std::cout << "Error! Program execution impossible:" << std::endl;
    std::cout << reason << std::endl;

    exit(1);
}

void Main::init(void)
{
	Config::init();
}

void Main::uninit(void)
{
	std::cout << "Program is being uninitialized."	<< std::endl;
	exit(0);	
}
