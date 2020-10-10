#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>
#include <QStandardItem>
#include <QDebug>
#include <QBrush>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      road(NULL)
{
    bool s1 = false, s2 = true;
    QString c1 = "            11", c2 = "          _     _    ", c3 = "          0     0    ";
    QString m1 = "              |0|", m2 = "               |", m3 = "              | |";
     tmr = new QTimer();
     tmr -> setInterval(1000);
     road = new QTableWidget(this);
     road->setRowCount(40);
     road->setColumnCount(80);
     //road->verticalHeader()->setVisible(false);
     road->setEditTriggers(QAbstractItemView::NoEditTriggers);
     road->setSelectionBehavior(QAbstractItemView::SelectRows);
     road->setSelectionMode(QAbstractItemView::SingleSelection);
     road->setShowGrid(false);
     road->setGeometry(QApplication::desktop()->screenGeometry());
     QBrush b(Qt::black, Qt::SolidPattern);
     QTableWidgetItem cell;
     cell.setBackground(b);
     cell.setForeground(b);
     for (int i = 0; i < 7; i++) {
         road->setItem(9, i, new QTableWidgetItem("               ___"));
         road->setItem(13, i - 1, new QTableWidgetItem("               ___"));
     }
     for (int i = 0; i < 10; i++) {
     road->setItem(i, 6, new QTableWidgetItem("               |"));
     road->setItem(i, 9, new QTableWidgetItem("               |"));
     }
     for (int i = 15; i < 25; i++) {
     road->setItem(i, 6, new QTableWidgetItem("               |"));
     road->setItem(i, 9, new QTableWidgetItem("               |"));
     }
     for (int i = 10; i < 16; i++) {
         road->setItem(9, i, new QTableWidgetItem("               ___"));
         road->setItem(13, i, new QTableWidgetItem("               ___"));
     }
     //road->setItem()
    road->setItem(0, 1, new QTableWidgetItem(m1));
    road->setItem(1, 1, new QTableWidgetItem(m2));
    road->setItem(2, 1, new QTableWidgetItem(m3));
    road->setItem(0, 2, new QTableWidgetItem(c1));
    road->setItem(1, 2, new QTableWidgetItem(c2));
    road->setItem(2, 2, new QTableWidgetItem(c3));

}
MainWindow::~MainWindow()
{
    delete tmr;
}

void MainWindow::moveM(QString m1,QString m2,QString m3, QVector<QVector<int>> men) {

}

void MainWindow::moveC(QString c1,QString c2,QString c3, QVector<QVector<int>> car) {

}
