#############################################################################
# Makefile for building: WebcrawlerGUI
# Generated by qmake (2.01a) (Qt 4.5.3) on: Tue May 18 10:53:08 2010
# Project:  WebcrawlerGUI.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -unix -o Makefile WebcrawlerGUI.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_WEBKIT_LIB -DQT_XML_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fstack-protector --param=ssp-buffer-size=4 -m64 -mtune=generic -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fstack-protector --param=ssp-buffer-size=4 -m64 -mtune=generic -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/lib64/qt4/mkspecs/linux-g++ -I. -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include/QtXml -I/usr/include/QtWebKit -I/usr/include -I. -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)   -lQtWebKit -lQtXml -lQtGui -lQtCore -lpthread
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = CrawlerGUI.cpp \
		CrawlerModel.cpp \
		main.cpp \
		Page.cpp \
		PageWithCount.cpp \
		Word.cpp moc_CrawlerGUI.cpp \
		moc_CrawlerModel.cpp
OBJECTS       = CrawlerGUI.o \
		CrawlerModel.o \
		main.o \
		Page.o \
		PageWithCount.o \
		Word.o \
		moc_CrawlerGUI.o \
		moc_CrawlerModel.o
DIST          = /usr/lib64/qt4/mkspecs/common/g++-multilib.conf \
		/usr/lib64/qt4/mkspecs/common/unix.conf \
		/usr/lib64/qt4/mkspecs/common/linux.conf \
		/usr/lib64/qt4/mkspecs/qconfig.pri \
		/usr/lib64/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt4/mkspecs/features/qt_config.prf \
		/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt4/mkspecs/features/default_pre.prf \
		/usr/lib64/qt4/mkspecs/features/release.prf \
		/usr/lib64/qt4/mkspecs/features/default_post.prf \
		/usr/lib64/qt4/mkspecs/features/warn_on.prf \
		/usr/lib64/qt4/mkspecs/features/qt.prf \
		/usr/lib64/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt4/mkspecs/features/moc.prf \
		/usr/lib64/qt4/mkspecs/features/resources.prf \
		/usr/lib64/qt4/mkspecs/features/uic.prf \
		/usr/lib64/qt4/mkspecs/features/yacc.prf \
		/usr/lib64/qt4/mkspecs/features/lex.prf \
		/usr/lib64/qt4/mkspecs/features/include_source_dir.prf \
		WebcrawlerGUI.pro
QMAKE_TARGET  = WebcrawlerGUI
DESTDIR       = 
TARGET        = WebcrawlerGUI

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_CrawlerGUI.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: WebcrawlerGUI.pro  /usr/lib64/qt4/mkspecs/linux-g++/qmake.conf /usr/lib64/qt4/mkspecs/common/g++-multilib.conf \
		/usr/lib64/qt4/mkspecs/common/unix.conf \
		/usr/lib64/qt4/mkspecs/common/linux.conf \
		/usr/lib64/qt4/mkspecs/qconfig.pri \
		/usr/lib64/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt4/mkspecs/features/qt_config.prf \
		/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt4/mkspecs/features/default_pre.prf \
		/usr/lib64/qt4/mkspecs/features/release.prf \
		/usr/lib64/qt4/mkspecs/features/default_post.prf \
		/usr/lib64/qt4/mkspecs/features/warn_on.prf \
		/usr/lib64/qt4/mkspecs/features/qt.prf \
		/usr/lib64/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt4/mkspecs/features/moc.prf \
		/usr/lib64/qt4/mkspecs/features/resources.prf \
		/usr/lib64/qt4/mkspecs/features/uic.prf \
		/usr/lib64/qt4/mkspecs/features/yacc.prf \
		/usr/lib64/qt4/mkspecs/features/lex.prf \
		/usr/lib64/qt4/mkspecs/features/include_source_dir.prf
	$(QMAKE) -unix -o Makefile WebcrawlerGUI.pro
/usr/lib64/qt4/mkspecs/common/g++-multilib.conf:
/usr/lib64/qt4/mkspecs/common/unix.conf:
/usr/lib64/qt4/mkspecs/common/linux.conf:
/usr/lib64/qt4/mkspecs/qconfig.pri:
/usr/lib64/qt4/mkspecs/features/qt_functions.prf:
/usr/lib64/qt4/mkspecs/features/qt_config.prf:
/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf:
/usr/lib64/qt4/mkspecs/features/default_pre.prf:
/usr/lib64/qt4/mkspecs/features/release.prf:
/usr/lib64/qt4/mkspecs/features/default_post.prf:
/usr/lib64/qt4/mkspecs/features/warn_on.prf:
/usr/lib64/qt4/mkspecs/features/qt.prf:
/usr/lib64/qt4/mkspecs/features/unix/thread.prf:
/usr/lib64/qt4/mkspecs/features/moc.prf:
/usr/lib64/qt4/mkspecs/features/resources.prf:
/usr/lib64/qt4/mkspecs/features/uic.prf:
/usr/lib64/qt4/mkspecs/features/yacc.prf:
/usr/lib64/qt4/mkspecs/features/lex.prf:
/usr/lib64/qt4/mkspecs/features/include_source_dir.prf:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile WebcrawlerGUI.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/WebcrawlerGUI1.0.0 || $(MKDIR) .tmp/WebcrawlerGUI1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/WebcrawlerGUI1.0.0/ && $(COPY_FILE) --parents CrawlerGUI.h CrawlerModel.h Page.h PageWithCount.h Word.h .tmp/WebcrawlerGUI1.0.0/ && $(COPY_FILE) --parents CrawlerGUI.cpp CrawlerModel.cpp main.cpp Page.cpp PageWithCount.cpp Word.cpp .tmp/WebcrawlerGUI1.0.0/ && $(COPY_FILE) --parents CrawlerGUI.ui .tmp/WebcrawlerGUI1.0.0/ && (cd `dirname .tmp/WebcrawlerGUI1.0.0` && $(TAR) WebcrawlerGUI1.0.0.tar WebcrawlerGUI1.0.0 && $(COMPRESS) WebcrawlerGUI1.0.0.tar) && $(MOVE) `dirname .tmp/WebcrawlerGUI1.0.0`/WebcrawlerGUI1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/WebcrawlerGUI1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_CrawlerGUI.cpp moc_CrawlerModel.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_CrawlerGUI.cpp moc_CrawlerModel.cpp
moc_CrawlerGUI.cpp: ui_CrawlerGUI.h \
		CrawlerModel.h \
		Page.h \
		PageWithCount.h \
		Word.h \
		CrawlerGUI.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) CrawlerGUI.h -o moc_CrawlerGUI.cpp

moc_CrawlerModel.cpp: Page.h \
		PageWithCount.h \
		Word.h \
		CrawlerModel.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) CrawlerModel.h -o moc_CrawlerModel.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_CrawlerGUI.h
compiler_uic_clean:
	-$(DEL_FILE) ui_CrawlerGUI.h
ui_CrawlerGUI.h: CrawlerGUI.ui
	/usr/lib64/qt4/bin/uic CrawlerGUI.ui -o ui_CrawlerGUI.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

CrawlerGUI.o: CrawlerGUI.cpp CrawlerGUI.h \
		ui_CrawlerGUI.h \
		CrawlerModel.h \
		Page.h \
		PageWithCount.h \
		Word.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CrawlerGUI.o CrawlerGUI.cpp

CrawlerModel.o: CrawlerModel.cpp CrawlerModel.h \
		Page.h \
		PageWithCount.h \
		Word.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CrawlerModel.o CrawlerModel.cpp

main.o: main.cpp CrawlerGUI.h \
		ui_CrawlerGUI.h \
		CrawlerModel.h \
		Page.h \
		PageWithCount.h \
		Word.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

Page.o: Page.cpp Page.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Page.o Page.cpp

PageWithCount.o: PageWithCount.cpp PageWithCount.h \
		Page.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PageWithCount.o PageWithCount.cpp

Word.o: Word.cpp Word.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Word.o Word.cpp

moc_CrawlerGUI.o: moc_CrawlerGUI.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_CrawlerGUI.o moc_CrawlerGUI.cpp

moc_CrawlerModel.o: moc_CrawlerModel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_CrawlerModel.o moc_CrawlerModel.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

