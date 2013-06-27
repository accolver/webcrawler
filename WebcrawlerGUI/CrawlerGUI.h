#ifndef CRAWLER_GUI_H
#define CRAWLER_GUI_H

#include "ui_CrawlerGUI.h"

#include "CrawlerModel.h"

#include <QProcess>
class QMainWindow;

class CrawlerGUI : public QMainWindow, public Ui::CrawlerGUI
{
	Q_OBJECT
	
public:
	CrawlerGUI(QWidget* parent = 0);
	virtual ~CrawlerGUI();
	
private slots:
	// Crawler Tab slots
	void selectCrawlerExePath();
	void selectXMLOutputPath();
	void selectStopwordsPath();
	
	// These are the two buttons on the Crawler tab.
	void crawlURL();
	void stopCrawl();
	void crawlerDone(int exitCode, QProcess::ExitStatus status);
	void readCrawlerOutput();
	
	// BYoogle Tab slots
	void selectBYoogleXMLOutputPath();
	void performSearch();
	void updateWebView();
	
	void sayHello();
	
private:
	void addToCrawledUrls(const QString& url);
	
	QStringList getSearchWords() const;
	
	void loadValues();
	void saveValues();
	
	
	virtual void closeEvent(QCloseEvent* event);
	
	void appendCrawlerOutput(const QString& output);
	
	QProcess* crawlProcess;
	
	CrawlerModel model;

};

#endif

