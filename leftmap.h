#ifndef LEFTMAP_H
#define LEFTMAP_H

#include <QWidget>

namespace Ui {
class LeftMap;
}

class LeftMap : public QWidget
{
    Q_OBJECT

public:
    explicit LeftMap(QWidget *parent = nullptr);
    ~LeftMap();
    void connectDB();
    void createRowData(int rowNo,int id,double x,double y,double theta,double inf_x,double inf_y,double uwb_x,double uwb_y,int landmark_id);


protected slots:
    void closeLetMap();
    void showData();

private:
    Ui::LeftMap *ui;
};

#endif // LEFTMAP_H
