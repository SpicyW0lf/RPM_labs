
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTimer>
#include <QEventLoop>
#include <QUrl>
#include <QDebug>
#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QMessageBox>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QString id;
    QString photo;
    QString filename;
    QString dbate;
    QString first_name="";
    QString last_name;
    QString nickname;
    QString id_friends;
    int check_id=-1;

    Ui::MainWindow *ui;

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void getID();


    void user_get();


    void friends_get();


    void photo_get();


    void Show();


    void Delete();

};
#endif // MAINWINDOW_H
