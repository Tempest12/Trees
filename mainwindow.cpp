#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QKeyEvent>

#include "Main.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    installEventFilter(this);
}

void MainWindow::keyPressEvent(QKeyEvent* e)
{
	switch(e->key())
	{
		case Qt::Key_Escape:
			Main::uninit();
			break;

		/*default:
			std::cout << e->key() << std::endl;
			break;*/
	}
}

MainWindow::~MainWindow()
{
    //delete ui;
}
