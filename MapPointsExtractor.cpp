#include "MapPointsExtractor.h"

#include <QtGui/QLabel>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <sstream>
#include <boost/scoped_array.hpp>

class myWebPage : public QWebPage
{
    virtual QString userAgentForUrl(const QUrl& url) const {
        return "Chrome/1.0";
    }
};

MapPointsExtractor::MapPointsExtractor()
{
    buildGUI();
    _tcpSocket = new QTcpSocket(this);
    connect(_tcpSocket,SIGNAL(readyRead()),this,SLOT(readStatus()));
    connect(_tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(errorOccured(QAbstractSocket::SocketError)));

    // connect to the emulator
    QString host("localhost");
    quint16 portNum = 5554;
    _tcpSocket->abort();
    _tcpSocket->connectToHost(host,portNum);
   // _tcpSocket->write("help\n");
}

MapPointsExtractor::~MapPointsExtractor()
{}

void MapPointsExtractor::buildGUI()
{
    QString address("file:///home/mikolaj/projects/MapPointsExtractor/html/googleMap.html");
    QString adb_path("/mnt/main_drive/downloads/android/android-sdk-linux_x86/platform-tools/adb");
    //QWidget *centralW = new QWidget(this);
    webView = new QWebView(this);
    webView->setPage(new myWebPage);        
    
    webView->setUrl(QUrl(QString(address)));
    connect(webView->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
             this, SLOT(insertJavaScriptObjects()));
    this->setCentralWidget(webView);
    
    
}

void MapPointsExtractor::positionChanged(double latitude, double longitude)
{
    std::stringstream ss;
    ss << "geo fix " << std::setprecision(10) << longitude << " " << latitude << "\n";
    
    std::cout << ss.str() << std::flush;
    _tcpSocket->write(ss.str().c_str());
    //printf("%.8f, %.8f\n",latitude, longitude);
}

void MapPointsExtractor::insertJavaScriptObjects()
{
    webView->page()->mainFrame()->addToJavaScriptWindowObject("cppBridge",this);
}

void MapPointsExtractor::readStatus()
{
    // just read it
    QByteArray a = _tcpSocket->readAll();
    std::cout << a.data() << std::endl;
}

void MapPointsExtractor::errorOccured(QAbstractSocket::SocketError error)
{
    //ignore
    std::cerr << "Connection failed";
    exit(1);
}
