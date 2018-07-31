#include "engine.hpp"
#include "country.hpp"

#include <QString>
#include <QVariantMap>

#include <iostream>

Engine::Engine() {
	is_auth = false;

	//new CountryInfo<Armenia>;
	//GenericCountry* zahrmar = new CountryInfo<Armenia>;
	
	//m_countries.append(new CountryInfo<Armenia>());
	//m_countries.append(new CountryInfo<Russia>());
	//m_countries.append(new CountryInfo<Georgia>());
	
	//m_info_manager
	m_countries = m_info_manager.get_list();
	//std::cout << m_countries.size() << std::endl;
	
	
	
}

bool Engine::is_authorized() {
	return is_auth;
}

void Engine::set_authorized(const QString& u, const QString& p) {
	is_auth = true;
	m_username = u;
	m_password = p;
}

void Engine::unset_authorized() {
	is_auth = false;
}

QString Engine::get_password() {
	//if(!is_authorized()) throw error?
	return m_password;
}

QString Engine::get_username() {
	//if(!is_authorized()) throw error?
	return m_username;
}


QVariantMap Engine::create_qvariant_for_sms(const QString& f,const QString& t ,const QString& txt) {
	// //if(!is_authorized()) throw error?
	
	QVariantMap v;
    QVariant key(m_username);
	QVariant secret(m_password);
	QVariant to(t); 
	QVariant from(f); 
	QVariant text(txt); 
	
    v.insert("api_key", key);
	v.insert("api_secret", secret);
	v.insert("to", to);
	v.insert("from", from);
	v.insert("text", text);
	

return v;
}


QList<GenericCountry*> Engine::get_country_infos() {
	return m_countries;
}

