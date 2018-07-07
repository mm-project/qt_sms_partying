#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "controller.hpp"

class stacked_widget;

class MainWindow : public QMainWindow
{
        Q_OBJECT

public:
        MainWindow(QWidget* = 0);

public slots:
        void update_status_bar(const QString&, bool);

private:
        stacked_widget* m_stacked;
		Controller* m_controller;
};

#endif
