#include "main_window.hpp"

#include "stacked_widget.hpp"
#include "controller.hpp"

#include <QStatusBar>
#include <QIcon>
#include <QLabel>
#include <QPixmap>
#include <QPicture>
#include <QMovie>

MainWindow::MainWindow(QWidget* p)
        :QMainWindow(p)
{
        m_stacked = new stacked_widget(this);
		m_controller = Controller::get_instance();
		
        setCentralWidget(m_stacked);
        resize(300, 200);
        setWindowTitle("SMS FUN");
        
		m_timer = new QTimer(this);
		m_timer->setSingleShot(true);
		m_timer->setInterval(100);
		connect(m_timer, SIGNAL(timeout()), this, SLOT(update_progress_state()));
		connect(m_stacked, SIGNAL(status_bar_changed(const QString&, bool)), this, SLOT(update_status_bar(const QString&, bool)));
        
		m_gif = new QMovie("C:\\Users\\elen\\Desktop\\qt_sms\\VisualStudio_qtsms\\x64\\Debug\\gg.gif");
		//assert(m_gif->isValid() != 0); // maybe need to check
		m_gif->setScaledSize(QSize(20, 20));
		QLabel* l = new QLabel();
		l->setMovie(m_gif);
		statusBar()->addWidget(l);
		statusBar()->showMessage("Enter creditials to login.");
		setWindowIcon(QIcon("C:\\Users\\elen\\Desktop\\qt_sms\\main_window.png"));

		statusBar()->showMessage("Enter creditials to login.");
}

void MainWindow::update_status_bar(const QString& s, bool err)
{
        !err ? statusBar()->setStyleSheet("color : red")
                : statusBar()->setStyleSheet("color : black");
        statusBar()->showMessage(s);
}

void MainWindow::start_processing()
{
	m_processing = true;
	m_gif->start();
	m_timer->start();
	statusBar()->clearMessage(); //change
}

void MainWindow::update_progress_state()
{
	if (!m_processing) {
		m_gif->stop();
		//hide widget
	}
}
