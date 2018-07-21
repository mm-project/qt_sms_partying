#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "controller.hpp"

class stacked_widget;
class QMovie;
class QTimer;
class QLabel;

class MainWindow : public QMainWindow
{
        Q_OBJECT

public:
        MainWindow(QWidget* = 0);

public slots:
		void update_status_bar(const QString&, bool = false, bool processing = false);

private:
        stacked_widget* m_stacked;
		Controller* m_controller;
		// For Status gif
		QMovie* m_gif;
		QLabel* m_status_bar_label;
		QLabel* m_gif_label;
};

#endif
