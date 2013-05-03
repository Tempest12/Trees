#ifndef MAIN_CPP
#define MAIN_CPP

#include <QApplication>
#include "mainwindow.h"

namespace Main
{
	extern MainWindow mainwindow;

	void reportError(std::string error);

	void die(const std::string& reason);

	void init(void);

    void uninit(void);
}

void test(void);

#endif
