#ifndef LEFTMAP_H
#define LEFTMAP_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>

namespace Ui {
class LeftMap;
}

class LeftMap : public QWidget
{
    Q_OBJECT

public:
    explicit LeftMap(QWidget *parent = nullptr);
    ~LeftMap();
    void initSlots();
    void connectDB();
    void createRowData(int rowNo,int id,double x,double y,double theta,double inf_x,double inf_y,double uwb_x,double uwb_y,int landmark_id);

protected slots:
    void closeLetMap();
    void showData();
    void showMapPoints(double x, double y);
private:
    Ui::LeftMap *ui;
    QGraphicsScene *_scene;
};

#endif // LEFTMAP_H
