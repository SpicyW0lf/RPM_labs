#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect( ui->pushButton,
             &QPushButton::clicked,
             this,
             &MainWindow::getID );
    connect( ui->pushButton,
             &QPushButton::clicked,
             this,
             &MainWindow::user_get );
    connect( ui->pushButton,
             &QPushButton::clicked,
             this,
             &MainWindow::friends_get );
    connect( ui->pushButton,
             &QPushButton::clicked,
             this,
             &MainWindow::photo_get );
    connect( ui->pushButton,
             &QPushButton::clicked,
             this,
             &MainWindow::Show );
    connect( ui->pushButton,
             &QPushButton::clicked,
             this,
             &MainWindow::Delete );
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::getID(){
    id = ui->lineEdit->text();
}

void MainWindow::user_get(){
    QJsonObject json;
    QJsonDocument jsonDoc(json);

    QUrl url = QUrl("https://api.vk.com/method/users.get?user_id=" + id + "&fields=bdate,nickname,photo_200&access_token=0746fd670746fd670746fd677f0732e76d007460746fd67582b249a2b2fa7c0f9aa58e5&v=5.124");
    QNetworkRequest request(url);
    QNetworkAccessManager manager;
    QByteArray sendData = jsonDoc.toJson();
    QNetworkReply *response = manager.post(request, sendData);
    QEventLoop event;

    connect(response,SIGNAL(finished()),&event,SLOT(quit()));
    event.exec();
    disconnect(response,SIGNAL(finished()),&event,SLOT(quit()));

    QJsonDocument reply = QJsonDocument::fromJson(response->readAll());
    QJsonObject jsonObject = reply.object();
    QJsonArray jsonArray = jsonObject["response"].toArray();

    foreach (const QJsonValue & value, jsonArray) {
        QJsonObject obj = value.toObject();
        dbate.append(obj["bdate"].toString());
        first_name.append(obj["first_name"].toString());
        check_id=obj["id"].toInt();
        last_name.append(obj["last_name"].toString());
        nickname.append(obj["nickname"].toString());
        photo.append(obj["photo_200"].toString());
    }

    if(dbate.isEmpty())
        dbate="не указана";
    if(nickname.isEmpty())
        nickname="не указан";
}

void MainWindow::friends_get(){
    QJsonObject json;
    QJsonDocument jsonDoc(json);

    QUrl url_friends = QUrl("https://api.vk.com/method/friends.get?user_id=" + id + "&access_token=0746fd670746fd670746fd677f0732e76d007460746fd67582b249a2b2fa7c0f9aa58e5&v=5.124");
    QNetworkRequest request(url_friends);
    QNetworkAccessManager manager;

    QByteArray sendData = jsonDoc.toJson();
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");

    QNetworkReply *response = manager.post(request, sendData);
    QEventLoop event;
    connect(response,SIGNAL(finished()),&event,SLOT(quit()));
    event.exec();
    disconnect(response,SIGNAL(finished()),&event,SLOT(quit()));

    QJsonDocument reply = QJsonDocument::fromJson(response->readAll());
    QJsonObject jsonObject = reply.object();
    QJsonObject s = reply["response"].toObject();
    QJsonArray jsonArray = s.value("items").toArray();
    QJsonDocument doc;
    doc.setArray(jsonArray);
    QString id(doc.toJson());
    id.remove('\n').remove('[').remove(']');
    if (id.isEmpty())
        id="Отсутствуют";
    id_friends=id;
}

void MainWindow::photo_get(){
    QNetworkAccessManager manager;
    QUrl url_photo = QUrl(photo);
    QNetworkRequest requestMy(url_photo);
    QNetworkReply *response = manager.get(requestMy);

    QEventLoop event;
    connect(response,SIGNAL(finished()),&event,SLOT(quit()));
    event.exec();
    disconnect(response,SIGNAL(finished()),&event,SLOT(quit()));

    if (response->error() != QNetworkReply::NoError) {
        QMessageBox msgBox;

           msgBox.setText("пользователя не существует или его аккаунт удален");

        msgBox.exec();
        msgBox.setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint);
        return;
    }
    filename = "image.jpg";
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    file.write(response->readAll());
    file.close();

}

void MainWindow::Show(){
    ui->label_text->setText("ФИО: "+first_name+" "+last_name+"\r\n"+"ник: "+nickname+"\r\n"+"дата рождения: "+dbate+"\r\n\n\n"+"фото: ");
    ui->label_friends->setText("список друзей:\r\n"+id_friends);
    if(check_id==-1){
        ui->label_text->clear();
        ui->label_friends->clear();
    }
    QPixmap img(filename);
    ui->label_photo->setPixmap(img);
    if(photo.isEmpty()){
        ui->label_photo->clear();
    }
}

void MainWindow::Delete(){
    check_id=-1;
    first_name.clear();
    last_name.clear();
    dbate.clear();
    nickname.clear();
    photo.clear();
    id_friends.clear();
}

