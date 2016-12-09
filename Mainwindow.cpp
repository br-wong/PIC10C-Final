#include "Mainwindow.h"
#include "ui_Mainwindow.h"

#include "Game.h"

Game *newGame;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    //Present game window
    newGame = new Game();
    newGame->show();
    this->hide();
}
