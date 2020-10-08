#include "piaint.h"
#include "ui_piaint.h"
#include <QInputDialog>
#include <QFileDialog>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include "photo.h"
piaint::piaint(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::piaint)
{
    ui->setupUi(this);
    ui->Scene->setScene(scene);

    actions[3]->setSeparator(true);
    for(const auto& item : actions){
     menu->addAction(item);
    }
    connect(actions[0],&QAction::triggered,[&](){
        scene->setBrush(Qt::blue);
    });
    connect(actions[1],&QAction::triggered,[&](){
        scene->setBrush(Qt::red);
    });
    connect(actions[2],&QAction::triggered,[&](){
        scene->setBrush(Qt::green);
    });
    connect(actions[4],&QAction::triggered,[&](){
        QString fileName = QFileDialog::getSaveFileName(this, "Select Photo", "", "*.jpg *.png");
        QImage image(scene->width(), scene->height(), QImage::Format_ARGB32_Premultiplied);
          image.fill(QColor(Qt::white).rgb());
          QPainter painter(&image);
          scene->render(&painter);
          image.save(fileName);
    }
    );
    connect(actions[5],&QAction::triggered,[&](){
    QString str = QFileDialog::getOpenFileName(this, "Select Photo", "", "*.jpg *.png");
    auto smth = new photo(scene,QPixmap(str));
    scene->addItem(smth);
    });
    connect(actions[6],&QAction::triggered,[&](){
    scene->clear();
    });
    connect(actions[7],&QAction::triggered,[&](){
    scene->setBrush(Qt::white);
    });
    scene->setSceneRect(0,0, ui->Scene->width() + 1600, ui->Scene->height() + 900);
}

piaint::~piaint()
{
    delete ui;
}

void piaint::mousePressEvent(QMouseEvent * event){
    if (event->button() == Qt::RightButton){
        menu->exec(event->globalPos());
    }
}
