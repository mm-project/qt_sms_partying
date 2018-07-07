#include "main_window.hpp"

#include "stacked_widget.hpp"
#include "controller.hpp"

#include <QStatusBar>

MainWindow::MainWindow(QWidget* p)
        :QMainWindow(p)
{
        m_stacked = new stacked_widget(this);
		m_controller = Controller::get_instance();
		
        setCentralWidget(m_stacked);
        resize(300, 200);
        setWindowTitle("SMS FUN");
        
		connect(m_stacked, SIGNAL(status_bar_changed(const QString&, bool)), this, SLOT(update_status_bar(const QString&, bool)));
        
		statusBar()->showMessage("Enter creditials to login");
}

void MainWindow::update_status_bar(const QString& s, bool err)
{
        !err ? statusBar()->setStyleSheet("color : red")
                : statusBar()->setStyleSheet("color : black");
        statusBar()->showMessage(s);
}
