#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ActiveQt\QAxObject>

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
    Ui::MainWindow *ui;
    QAxObject *mExcel;
    QAxObject *workbook;
    QAxObject *StatSheet;
    QAxObject *cell;

private slots:
    void cellSelected(int nRow, int nCol);
};
#endif // MAINWINDOW_H
