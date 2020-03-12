#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "freight.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();
  Options freight;

private slots:
  void on_CalcPushButton_clicked();
  void on_FreightPushButton_clicked();

private:
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
