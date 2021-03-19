#include "leftmap.h"
#include "ui_leftmap.h"
#include "QSqlDatabase"
#include "QMessageBox"
#include "QSqlError"
#include <QSqlQuery>
#include <QtDebug>


LeftMap::LeftMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeftMap)
{
    ui->setupUi(this);
    QObject::connect(ui->stopPro, SIGNAL(clicked()), SLOT(closeLetMap()));
    QObject::connect(ui->startPro, SIGNAL(clicked()), SLOT(showData()));
}

LeftMap::~LeftMap()
{
    delete ui;
}

void LeftMap::closeLetMap(){
   this->close();
}

//连接数据库
void LeftMap::connectDB(){
    //添加mysql数据库
    QSqlDatabase db =QSqlDatabase::addDatabase("QMYSQL");
    //连接数据库
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("rtls");//使用的数据库
    //打开数据库
    if(!db.open()){
        QMessageBox::warning(this,"错误",db.lastError().text());
        return;
    }else{
        QMessageBox::warning(this,"成功","success!");
        return;
    }

}

void LeftMap::showData(){
    ui->tableView->setRowCount(0);
    QSqlQuery query;
    query.exec("select * from location_data");
    while(query.next()){
        ui->tableView->insertRow(ui->tableView->rowCount());
        int curRow = ui->tableView->rowCount()-1;//当前行号
        int id= query.value(0).toInt();
        double x =query.value(1).toDouble();
        double y = query.value(2).toDouble();
        double theta =query.value(3).toDouble();
        double inf_x = query.value(4).toDouble();
        double inf_y =query.value(5).toDouble();
        double uwb_x = query.value(6).toDouble();
        double uwb_y =query.value(7).toDouble();
        int landmark_id = query.value(8).toInt();
        createRowData(curRow,id, x, y, theta, inf_x, inf_y, uwb_x, uwb_y, landmark_id);
    }
}

void LeftMap::createRowData(int rowNo,int id,double x,double y,double theta,double inf_x,double inf_y,double uwb_x,double uwb_y,int landmark_id)
{
    //为一行的单元格创建 Items
    QTableWidgetItem *item0 = new QTableWidgetItem(QString::number(id));
    QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(x));
    QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(y));
    QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(theta));
    QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(inf_x));
    QTableWidgetItem *item5 = new QTableWidgetItem(QString::number(inf_y));
    QTableWidgetItem *item6 = new QTableWidgetItem(QString::number(uwb_x));
    QTableWidgetItem *item7 = new QTableWidgetItem(QString::number(uwb_y));
    QTableWidgetItem *item8 = new QTableWidgetItem(QString::number(landmark_id));
    ui->tableView->setItem(rowNo,0,item0); //为单元格设置Item
    ui->tableView->setItem(rowNo,1,item1);
    ui->tableView->setItem(rowNo,2,item2);
    ui->tableView->setItem(rowNo,3,item3);
    ui->tableView->setItem(rowNo,4,item4);
    ui->tableView->setItem(rowNo,5,item5);
    ui->tableView->setItem(rowNo,6,item6);
    ui->tableView->setItem(rowNo,7,item7);
    ui->tableView->setItem(rowNo,8,item8);
}
