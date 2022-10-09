#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QWebChannel>

#include "document.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void test2_clicked();
    void test3_clicked();
    void onBtnSend_clicked();
    void onReceiveData(const QString &jsonString);

private:
    Ui::MainWindow *ui;
    bool isLoaded;
    QWebEngineView* view;
    QWebChannel* channel;
    Document document;      // QT和Html通信的中间商

    QJsonObject setUniqueJson(const QString &key, const QString &value);

};
#endif // MAINWINDOW_H
