#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"
#include <Users.h>
#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <QPixmap>
WelcomeWindow::WelcomeWindow(QString username, int age,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{

    ui->setupUi(this);
    QString Hello = "Hello, " + username + "! Your age is: " + QString::number(age);
    ui->NameLabel->setText(Hello);

    QPixmap pix("C:\\Users\\20109\\Desktop\\Qt assignment image.jpg");
    int w=ui->PictureLabel->width();
    int h=ui->PictureLabel->height();
    ui->PictureLabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

}


WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}
 // void WelcomeWindow::setText(QString username){

 //    ui->NameLabel->setText(“Hello” + username);
 // }

void WelcomeWindow::on_LogoutButton_clicked()
{
    hide();
    LoginWindow* login=new LoginWindow(this);
    // window->setText();
    login->show();

}

