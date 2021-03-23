#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QDebug>
#include <QSqlError>
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //检查数据库是否打开
    dbconn=QSqlDatabase::addDatabase("QSQLITE");
    dbconn.setDatabaseName("D:\\sqlitestudio\\database1.db");
    if(!dbconn.open())
    {
        dbconn.close();
    }
    else
    {
        qDebug() << "success";
    }
    //检查是否 表格存在
    QSqlQuery query(dbconn);
    QString tableName = "rtlsdata";
    bool isTableExist = dbconn.tables().contains(tableName);

    if(isTableExist)
    {
        qDebug() << "table success";
    }
    else
    {
        qDebug() << "table error";
    }
    }







MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}

void MainWindow::on_read_clicked()
{
    //加载表格
    QSqlQuery query(dbconn);
    if(true == dbconn.open())

    {

    if(query.exec("select * from rtlsdata"))

    {

            ui->table->clearContents();


          ui->table->setRowCount(0);
          ui->table->setRowCount(0);

   while(query.next())

   {

    int rowCount = ui->table->rowCount();



    ui->table->insertRow(rowCount);



    QTableWidgetItem *columnItem0 = new QTableWidgetItem(query.value(0).toString());

    QTableWidgetItem *columnItem1 = new QTableWidgetItem(query.value(1).toString());

    QTableWidgetItem *columnItem2 = new QTableWidgetItem(query.value(2).toString());

    QTableWidgetItem *columnItem3 = new QTableWidgetItem(query.value(3).toString());

    QTableWidgetItem *columnItem4 = new QTableWidgetItem(query.value(4).toString());

    QTableWidgetItem *columnItem5 = new QTableWidgetItem(query.value(5).toString());
    QTableWidgetItem *columnItem6 = new QTableWidgetItem(query.value(6).toString());

    QTableWidgetItem *columnItem7 = new QTableWidgetItem(query.value(7).toString());
    QTableWidgetItem *columnItem8 = new QTableWidgetItem(query.value(8).toString());



    ui->table->setItem(rowCount,0, columnItem0);
    ui->table->setItem(rowCount,1, columnItem1);
    ui->table->setItem(rowCount,2, columnItem2);

    ui->table->setItem(rowCount,3, columnItem3);
    ui->table->setItem(rowCount,4, columnItem4);
    ui->table->setItem(rowCount,5, columnItem5);
    ui->table->setItem(rowCount,6, columnItem6);
    ui->table->setItem(rowCount,7, columnItem7);
    ui->table->setItem(rowCount,8, columnItem8);

    }
    }

   }
}
