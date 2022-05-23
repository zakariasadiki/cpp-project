#include "mainwindow.h"
#include "ui_mainwindow.h"

char ringbuffer[512];
int head = 0;
int tail = 0;
void rinbuffer_add(char zeichen){
    ringbuffer[head] = zeichen;
}

int rinbuffer_get(char *zeichen){
//    if(head == tail)
//        return -1;
//    else {
//        *zeichen = ringbuffer[tail];
//    }
    return 0;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    memset(ringbuffer, 0, sizeof(ringbuffer));
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setInputText(QString text){
    ui->textEdit->setText(text);
}

void MainWindow::setOutputText(QString text){
    /*
     * Aufgabe: Nehmen Sie bitte den Input (text) engegen und
     * speichern Sie alle einzelnen Zeichen in einem Ringpuffer ab.
     * anschließend gehen Sien den Rinpuffer von Beginn an durch und
     * suchen sie nach einem Zeilenumbruch. Wenn Sie den Zeilenumbruch
     * gefunden haben, entnehmen sie alle zeichen inklusive dem umbruch
     * und geben ssie diese im unteren textfeld aus.
     */
    //ui->textEdit_2->setText(text);
}

