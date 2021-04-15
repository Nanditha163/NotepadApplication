#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QFileDialog>
#include<QFontDialog>
#include<QFontInfo>
#include<QFont>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include<QColor>
#include<QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}



void MainWindow::on_actionSave_triggered()
{
  QFile file(file_path);//mention file path
    if(!file.open(QFile::WriteOnly|QFile::Text))
      {
        QMessageBox::warning(this,"..","File not opened");
          return;
       }
       QTextStream out(&file);
       QString text=ui->textEdit->toPlainText();
       out<<text;
       file.flush();
       file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString f=QFileDialog::getSaveFileName(this,"Save the File");
        QFile file(f);
        //file_path=f;
        if(!file.open(QFile::WriteOnly|QFile::Text))
        {
            QMessageBox::warning(this,"..","File not open");
            return;
        }
        QTextStream out(&file);
        QString text=ui->textEdit->toPlainText();
        out<<text;
        file.flush();
        file.close();
}





void MainWindow::on_actionBold_triggered()
{
    ui->textEdit->setFontWeight(QFont::Bold);
}

void MainWindow::on_actionItalic_triggered()
{
    ui->textEdit->setFontItalic(true);
}

void MainWindow::on_actionAbout_Qt_triggered()
{
     QMessageBox::information(this,"ABOUT OUR QTCreator","Qt is used to create widget applications");
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter p;
        p.setPrinterName("HP 1515 printer");
        QPrintDialog pd(&p,this);
        if(pd.exec()==QDialog::Rejected)
        {
            QMessageBox::warning(this,"Error","unable to access printer");
            return;
        }
        ui->textEdit->print(&p);
}
