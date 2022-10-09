#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QWebChannel>

#include "document.h"

QT_BEGIN_NAMESPACE
namespace Ui { class bmapWindow; }
QT_END_NAMESPACE

class bmapWindow : public QMainWindow
{
    Q_OBJECT

public:
    bmapWindow(QWidget *parent = nullptr);
    ~bmapWindow();

private slots:
    void test2_clicked();
    void test3_clicked();
    void onBtnSend_clicked();
    void onReceiveData(const QString &jsonString);

private:
    Ui::bmapWindow *ui;
    bool isLoaded;
    QWebEngineView* view;
    QWebChannel* channel;
    Document document;      // QT和Html通信的中间商

    void onResizeEcharts();
    QJsonObject setUniqueJson(const QString &key, const QString &value);

};
#endif // MAINWINDOW_H
