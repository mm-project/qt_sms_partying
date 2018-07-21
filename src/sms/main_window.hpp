#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "controller.hpp"

class stacked_widget;
class QMovie;
class QTimer;

class MainWindow : public QMainWindow
{
        Q_OBJECT

public:
        MainWindow(QWidget* = 0);

public slots:
		void start_processing();
		void end_processing() { m_processing = false; }

        void update_status_bar(const QString&, bool);

private slots:
		void update_progress_state();

private:
        stacked_widget* m_stacked;
		Controller* m_controller;
		bool m_processing;
		// For Status gif
		QMovie* m_gif;
		QTimer* m_timer;
};

#endif
