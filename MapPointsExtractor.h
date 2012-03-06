#ifndef MapPointsExtractor_H
#define MapPointsExtractor_H

#include <QtGui/QMainWindow>
#include <QtWebKit>
#include <QTcpSocket>
class MapPointsExtractor : public QMainWindow
{
Q_OBJECT
public:
    MapPointsExtractor();
    virtual ~MapPointsExtractor();
    
public slots:
    void positionChanged(double latitude,double longitude);
    
private:
    
    void buildGUI();
    
    QWebView *webView; // webview
    QTcpSocket *_tcpSocket;
    
private slots:
    void insertJavaScriptObjects();
    void readStatus();
    void errorOccured(QAbstractSocket::SocketError error);
};

#endif // MapPointsExtractor_H
