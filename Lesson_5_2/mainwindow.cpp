#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pressCounter = 0;

    connect (ui->b_test, &QPushButton::clicked, this, &MainWindow::updateLabel);
    connect (ui->b_test, &QPushButton::clicked, this, &MainWindow::updateCounter);
    connect (ui->horizontalSlider, &QSlider::sliderMoved, ui->verticalSlider, &QSlider::setValue);
    connect (ui->horizontalSlider, &QSlider::sliderMoved, ui->progressBar, &QProgressBar::setValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLabel()
{
    ui->l_buffer->setText("Привет!");
}

void MainWindow::updateCounter()
{
    m_pressCounter++;
    ui->lcdNumber->display(m_pressCounter);
}
