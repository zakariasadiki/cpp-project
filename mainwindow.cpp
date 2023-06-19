#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <queue>

std::queue<char> ringBuffer;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setInputText(QString text)
{
    ui->textEdit->setText(text);

    // Speichern der Zeichen im Ringpuffer
    for (int i = 0; i < text.length(); i++)
    {
        char c = text.at(i).toLatin1();
        ringBuffer.push(c);
    }
}

void MainWindow::setOutputText(QString)
{
    QString outputText;
    bool foundNewLine = false;

    // Durchsuchen des Ringpuffers nach einem Zeilenumbruch
    while (!ringBuffer.empty())
    {
        char c = ringBuffer.front();
        ringBuffer.pop();

        // Überprüfen, ob Zeilenumbruch gefunden wurde
        if (c == '\n')
        {
            foundNewLine = true;
            outputText.append(c);
            break;
        }

        outputText.append(c);
    }

    // Ausgabe der Zeichen inklusive Zeilenumbruch
    if (foundNewLine)
    {
        ui->textEdit_2->setText(outputText);
    }
    else
    {
        ui->textEdit_2->setText("Zeilenumbruch nicht gefunden.");
    }
}
