#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_counter = 0;

    connect (ui->b_doSomethin, &QPushButton::clicked, this, &MainWindow::changeText);
    connect (ui->horizontalSlider, &QSlider::valueChanged, ui->horizontalSlider_2, &QSlider::setValue);
    connect (ui->horizontalSlider, &QSlider::valueChanged, ui->progressBar, &QProgressBar::setValue);
    connect (ui->horizontalSlider, &QSlider::valueChanged, ui->verticalSlider, &QSlider::setValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeText()
{
    m_counter++;
    QString msg = "Кнопка нажата " + QString::number(m_counter) + " раз!";
    ui->l_text->setText(msg);
}
