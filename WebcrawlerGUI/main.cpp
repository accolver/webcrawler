#include <QApplication>

#include "CrawlerGUI.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	
	CrawlerGUI* gui = new CrawlerGUI();
	gui->show();
	
	return app.exec();
}

