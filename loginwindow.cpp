#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "welcomewindow.h"
#include"registerwindow.h"
#include"ui_welcomewindow.h"
#include "Users.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->ErrorLabel->setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_LoginButton_clicked()
{
    QString username= ui->lineEdit_Username->text();
    QString password= ui->lineEdit_Password->text();


    for(int i=0;i<4;i++)
    {
        if(usernames[i]==username&&passwords[i]==password){
             hide();
            WelcomeWindow* window=new WelcomeWindow(username,ages[i],this);
           // window->setText();
            window->show();

        }
        ui->ErrorLabel->setVisible(true);
    }

}


void LoginWindow::on_RegisterButton_clicked()
{
        hide();
        RegisterWindow* register2= new RegisterWindow(this);
        register2->show();


}

