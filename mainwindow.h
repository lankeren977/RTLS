#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSql>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
    QString hostName;
    QString dbName;
    QString userName;
    QString password;
    QSqlDatabase dbconn;


private slots:
    void on_pushButton_4_clicked();

    void on_read_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
