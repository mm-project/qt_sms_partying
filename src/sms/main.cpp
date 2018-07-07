#include "main_window.hpp"
#include "controller.hpp"

#include <QApplication>

Controller* Controller::m_instance = 0;

int main(int argc, char** argv)
{
        QApplication app(argc, argv);
        MainWindow window;
        window.show();
        return app.exec();
}
