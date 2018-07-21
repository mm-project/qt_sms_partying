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
		connect(m_stacked, SIGNAL(status_bar_changed(const QString&, bool, bool)), this, SLOT(update_status_bar(const QString&, bool, bool)));
        
		m_gif = new QMovie("C:\\Users\\elen\\Desktop\\qt_sms\\VisualStudio_qtsms\\x64\\Debug\\gg.gif");
		//assert(m_gif->isValid() != 0); // maybe need to check
		m_gif->setScaledSize(QSize(20, 20));
		m_gif_label = new QLabel(this);
		m_gif_label->setMovie(m_gif);		
		m_status_bar_label = new QLabel("Enter creditials to login.", this);
		statusBar()->addWidget(m_status_bar_label);
		setWindowIcon(QIcon("C:\\Users\\elen\\Desktop\\qt_sms\\main_window.png"));
}

void MainWindow::update_status_bar(const QString& s, bool err, bool processing)
{
		QStatusBar* s_bar = statusBar();
		!err ? s_bar->setStyleSheet("color : red")
               : s_bar->setStyleSheet("color : black");
        m_status_bar_label->setText(s);
		if (!m_processing) {
			m_gif->stop();
			s_bar->removeWidget(m_gif_label);
		}
}

void MainWindow::start_processing()
{
	m_processing = true;
	m_gif->start();
	statusBar()->addWidget(m_gif_label);
	m_timer->start();
	//statusBar()->clearMessage(); //change
}

void MainWindow::update_progress_state()
{
	if (!m_processing) {
		m_gif->stop();
		//hide widget
	}
}
