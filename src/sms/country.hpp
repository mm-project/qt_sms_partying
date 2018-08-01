#ifndef COUNTRY_HPP
#define COUNTRY_HPP

#include "autogen_country_enum.hpp"

#include <QString>
#include <QIcon>
#include <QStringList>

#include <iostream>



//FIXME issue with quotes in macro
//#define MACRO_ICONS_DIR_STR(icon) QString(QString(MACRO_ICONS_DIR)+"\"" #icon "\"")

#define MACRO1_ICONS_DIR "C:\\Users\\levons\\Desktop\\git\\mm_project\\qt_sms_partying\\etc\\icons\\"
namespace {
QString ICONS_DIR_STR(const QString& name) { return QString(MACRO1_ICONS_DIR)+name; }
}


//class CountryInfoManager;

class GenericCountry 
{
	public:
		//GenericCountry() {
		//	m_manager->add_to_list(this);
		//}
		
		virtual QString get_country_name() = 0;
		virtual QString get_phone_code() = 0;
		virtual QIcon get_flag_icon()  = 0;
		virtual QStringList get_mobile_operator_codes() = 0;
			
	//private:
		//CountryInfoManager* m_manager;
};


class CountryInfoManager 
{
	
	public: 
		CountryInfoManager() { 
			
			//CountryInfo a(Armenia);	
			//m_countries.push_back(new CountryInfo<a>());
		}
		
		/*
		static void  create() {
			for(auto i=0; i<CountryName::Size; ++i) {
				const int j=  i;
				 CountryInfo<(static_cast<CountryName>(j))>();
				//new CountryInfo<(static_cast<CountryName>(j))>();
			}
		}
		*/
		
		//static add_to_list(GenericCountry* c) {
			//m_countries.push_back(c);
		//}
		
		static QList<GenericCountry*> get_list() {
			new CountryInfo<Armenia>();
			new CountryInfo<Russia>();

			return m_countries;
		}
		
	public:
		static QList<GenericCountry*> m_countries;
		
};







#endif 

