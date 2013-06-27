#include "CrawlerGUI.h"

#include <QScrollBar>
#include <QFileDialog>
#include <QTextStream>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QWebPage>
#include <QWebFrame>

CrawlerGUI::CrawlerGUI(QWidget* parent) : QMainWindow(parent)
{
	setupUi(this);
	
	// Hide the URL Column
	wordSearchTable->setColumnHidden(2, true);
	
	// Crawler Tab
	connect(browseExePath, SIGNAL(clicked()), this, SLOT(selectCrawlerExePath()));
	connect(browseOutputXMLPath, SIGNAL(clicked()), this, SLOT(selectXMLOutputPath()));
	connect(browseStopwordsPath, SIGNAL(clicked()), this, SLOT(selectStopwordsPath()));
	
	connect(crawlButton, SIGNAL(clicked()), this, SLOT(crawlURL()));
	connect(stopButton, SIGNAL(clicked()), this, SLOT(stopCrawl()));
	
	// BYoogle Tab
	connect(byoogleBrowseOutputXMLPath, SIGNAL(clicked()), this, SLOT(selectBYoogleXMLOutputPath()));
	
	connect(&model, SIGNAL(modelChanged()), this, SLOT(performSearch()));
	connect(searchButton, SIGNAL(clicked()), this, SLOT(performSearch()));
	connect(searchWordLineEdit, SIGNAL(returnPressed()), this, SLOT(performSearch()));
	
	connect(wordSearchTable, SIGNAL(itemSelectionChanged()), this, SLOT(updateWebView()));
	
	
	loadValues();
	
	crawlProcess = 0;
	
	if(QFile::exists(byoogleXMLOutputPath->text()))
	{
		model.LoadFromFile(byoogleXMLOutputPath->text());
	}
}

void CrawlerGUI::sayHello()
{
	QMessageBox::warning(this, "Hello!", "Hello!");
}

CrawlerGUI::~CrawlerGUI()
{
}

// Crawler Tab
void CrawlerGUI::selectCrawlerExePath()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Select Crawler Executable"));
	if(!fileName.isEmpty())
	{
		crawlerExePath->setText(fileName);
	}
}
	
void CrawlerGUI::selectXMLOutputPath()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Select a File to Save the XML Output to"));
	if(!fileName.isEmpty())
	{
		xmlOutputPath->setText(fileName);
	}
}

void CrawlerGUI::selectStopwordsPath()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Select Stopwords File"));
	if(!fileName.isEmpty())
	{
		stopwordsPath->setText(fileName);
	}
}

void CrawlerGUI::crawlURL()
{
	crawlerOutput->setPlainText("");
	
	if(QFile::exists(crawlerExePath->text()) == false)
	{
		QMessageBox::warning(this, "Invalid Crawl", "A valid crawler executable must be selected before crawling.");
		return;
	}
	
	if(xmlOutputPath->text().isEmpty())
	{
		QMessageBox::warning(this, "Invalid Crawl", "A valid location for the output of the crawler executable must be selected.");
		return;
	}
	
	if(QFile::exists(stopwordsPath->text()) == false)
	{
		QMessageBox::warning(this, "Invalid Crawl", "A valid stopwords file must be selected before crawling.");
		return;
	}
	
	if(urlToCrawl->currentText().isEmpty())
	{
		QMessageBox::warning(this, "Invalid Crawl", "A URL must be entered before a crawl can occur.");
		return;
	}
	
	
	
	QStringList arguments;
	arguments += urlToCrawl->currentText();
	arguments += xmlOutputPath->text();
	arguments += stopwordsPath->text();
	
	addToCrawledUrls(urlToCrawl->currentText());	
	
	if(crawlProcess == 0)
	{
		crawlerOutput->setPlainText("Crawler Started...\n\n");
		stopButton->setEnabled(true);
		
		crawlProcess = new QProcess(this);
		
		connect(crawlProcess, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(crawlerDone(int, QProcess::ExitStatus)));
		connect(crawlProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(readCrawlerOutput()));
		
		crawlProcess->start(crawlerExePath->text(), arguments);
	}
}

void CrawlerGUI::stopCrawl()
{
	if(crawlProcess != 0)
	{
		crawlProcess->kill();
		appendCrawlerOutput("\nCrawler Terminated...\n\n");
	}
}

void CrawlerGUI::crawlerDone(int exitCode, QProcess::ExitStatus status)
{
	if(crawlProcess != 0)
	{
		appendCrawlerOutput("\nCrawler finished with exitCode ");
		appendCrawlerOutput(QString::number(exitCode));
		appendCrawlerOutput(" and exit status: ");
		if(status == QProcess::NormalExit)
		{
			appendCrawlerOutput("NormalExit");
		}
		else
		{
			appendCrawlerOutput("CrashExit");
		}
		appendCrawlerOutput("...\n\n");
		
		delete crawlProcess;
		crawlProcess = 0;
		stopButton->setEnabled(false);
	}
	
	if(status == QProcess::NormalExit)
	{
		byoogleXMLOutputPath->setText(xmlOutputPath->text());
		model.LoadFromFile(byoogleXMLOutputPath->text());
	}
}

void CrawlerGUI::readCrawlerOutput()
{
	if(crawlProcess != 0)
	{
		QString output(crawlProcess->readAllStandardOutput());
		appendCrawlerOutput(output);
	}
}


// BYoogle Tab
void CrawlerGUI::selectBYoogleXMLOutputPath()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Select a File to open the XML Output from"));
	if(!fileName.isEmpty())
	{
		byoogleXMLOutputPath->setText(fileName);
		model.LoadFromFile(fileName);
	}
}
void CrawlerGUI::performSearch()
{
	QStringList searchList = getSearchWords();
	QList<PageWithCount> result;
	
	if(searchList.length() == 0)
	{
		result = model.GetAllPagesWithNullCount();
	}
	else
	{
		result = model.GetPagesContainingWords(searchList);
	}
	
	wordSearchTable->clearContents();
	wordSearchTable->setRowCount(0);
	for(int i = 0; i < result.length(); i++)
	{
		const PageWithCount& p = result[i];
		
		QTableWidgetItem* rating = new QTableWidgetItem(QString::number(p.GetOccurrenceCount()));
		QTableWidgetItem* description = new QTableWidgetItem(p.GetDescription());
		QTableWidgetItem* url = new QTableWidgetItem(p.GetURL());
		
		rating->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		description->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		url->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		
		wordSearchTable->insertRow(i);
		wordSearchTable->setItem(i, 0, rating);
		wordSearchTable->setItem(i, 1, description);
		wordSearchTable->setItem(i, 2, url);
	}
	
	if(result.length() > 0)
	{
		// Select the first row available.
		wordSearchTable->setCurrentCell(0, 0);
	}
}

void CrawlerGUI::updateWebView()
{
	QList<QTableWidgetItem*> selectedCells = wordSearchTable->selectedItems();
	
	if(selectedCells.length() > 0)
	{
		int selectedRow = selectedCells[0]->row();
		QString selectedUrl = wordSearchTable->item(selectedRow, 2)->text();
	
		webView->load(selectedUrl);
		currentURL->setText(selectedUrl);
	}
	else
	{
		webView->setHtml("");
		currentURL->setText("");
	}
}

void CrawlerGUI::addToCrawledUrls(const QString& url)
{
	if(urlToCrawl->findText(url, Qt::MatchExactly) == -1)
	{
		urlToCrawl->addItem(url);
	}
}

QStringList CrawlerGUI::getSearchWords() const
{
	QStringList result = searchWordLineEdit->text().split(QRegExp("\\W+"), QString::SkipEmptyParts);
	return result;
}
	

void CrawlerGUI::loadValues()
{
	QFile valuesFile("values.dat");
	
	if(valuesFile.open(QIODevice::ReadOnly))
	{
		QTextStream in(&valuesFile);
		
		crawlerExePath->setText(in.readLine().trimmed());
		xmlOutputPath->setText(in.readLine().trimmed());
		stopwordsPath->setText(in.readLine().trimmed());
		urlToCrawl->addItem(in.readLine().trimmed());
		urlToCrawl->setCurrentIndex(0);
		byoogleXMLOutputPath->setText(in.readLine().trimmed());
		
		while(in.atEnd() == false)
		{
			while(in.atEnd() == false)
			{
				QString toAdd = in.readLine().trimmed();
				if(toAdd.isEmpty() == false)
				{
					addToCrawledUrls(toAdd);
				}
			}
		}
	}
}
void CrawlerGUI::saveValues()
{
	QFile valuesFile("values.dat");
	
	if(valuesFile.open(QIODevice::WriteOnly))
	{
		QTextStream out(&valuesFile);
	
		out << crawlerExePath->text() << "\n";
		out << xmlOutputPath->text() << "\n";
		out << stopwordsPath->text() << "\n";
		out << urlToCrawl->currentText() << "\n";
		out << byoogleXMLOutputPath->text() << "\n";
		
		for(int i = 0; i < urlToCrawl->count(); i++)
		{
			out << urlToCrawl->itemText(i) << "\n";
		}
	}
}

void CrawlerGUI::closeEvent(QCloseEvent* event)
{
	saveValues();
	
	QMainWindow::closeEvent(event);
}

void CrawlerGUI::appendCrawlerOutput(const QString& output)
{
	QTextCursor temp = crawlerOutput->textCursor();
	temp.movePosition(QTextCursor::End);
	crawlerOutput->setTextCursor(temp);
	
	crawlerOutput->insertPlainText(output);

	temp.movePosition(QTextCursor::End);
	crawlerOutput->setTextCursor(temp);
}
	






