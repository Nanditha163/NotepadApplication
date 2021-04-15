#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionQuit_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionFont_triggered();

    void on_actionPrint_triggered();

    void on_actionBold_triggered();

    void on_actionItalic_triggered();

    void on_actionAbout_Qt_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
