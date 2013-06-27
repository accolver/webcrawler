Instructions for building the CrawlerGUI:

1. You must have a valid installation of Qt, version 4.5.3 or higher.  If you are on the CS lab machines, they already have this
	installation.  If you are running from your home computer, you can get an installation file from http://qt.nokia.com/products.
	With a little navigating, you should be able to find the SDK for your linux computer.
	
2. With a terminal/command-prompt, navigate to the folder where the WebcrawlerGUI source code is.  For the purposes of this
	document, I will call mine WebcrawlerGUI.  When you reach the source folder, enter the following three commands:
	
	qmake -project
	qmake WebcrawlerGUI.pro
	make
	
	Note: If your folder is not WebcrawlerGUI, then replace WebcrawlerGUI in the second command with whatever the folder is named.
		This means the direct folder, not the path.  If this doesn't make any sense, after making the first call to qmake, there should
		now be a "pro" file in your source directory that you simply pass to qmake as an argument.  That's all I'm doing on the
		second step.

3. After step 2, you should have an executable file that you can run.  Have fun crawling!
