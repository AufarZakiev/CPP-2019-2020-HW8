#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <transfer.h>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Transfer *trf;
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:

  void on_FromComboBox_currentIndexChanged(int index);

  void on_TransportComboBox_currentIndexChanged(int index);

  void on_ToComboBox_currentIndexChanged(int index);

  void on_PricePushButton_clicked();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
