#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTimer>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QVector<QVector<int>> men = {{0, 5}, {14, 0}}; //men[2][2] = {{0, 5}, {14, 0}}, car[2][2] = {{7, 0}, {0, 11}};
     QVector<QVector<int>> car = {{7, 0}, {0, 11}};
    QTimer *tmr;
    QTableWidget *road;
    QStringList m_TableHeader;


private slots:
    void moveM(QString m1,QString m2,QString m3, QVector<QVector<int>> men);
    void moveC(QString c1,QString c2,QString c3, QVector<QVector<int>> car);
};
#endif // MAINWINDOW_H
