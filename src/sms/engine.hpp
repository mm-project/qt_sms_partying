#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <QString>

class Engine   
{
		
	public:
		Engine(); 
		
		
	public:
		bool is_authorized();
		void set_authorized(const QString& u, const QString& p);
		void unset_authorized();

		
	private:
		QString m_username;
		QString m_password;
		bool is_auth;

};


#endif // ENGINE_HPP
