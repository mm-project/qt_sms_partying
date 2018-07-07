#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "requester.hpp"

#include <QString>
class Requester;

class Request //:  public QObject
{
    public:
	//Q_OBJECT
		Request() {
		
		}
		
		Request(Requester::Type t, const QString& str, handleFunc errhnd, handleFunc okhnd);
		
	public:		
		QString get_str();
		Requester::Type get_type();
		handleFunc get_ok_handler();
		handleFunc get_err_handler();
		
		
	private:
		QString m_request_str;
		Requester::Type m_type;
		handleFunc m_err_hndl;
		handleFunc m_ok_hndl;
		
		
};


#endif // REQUEST_HPP
