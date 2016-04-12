#include "L1Trigger/L1TCommon/interface/setting.h"

namespace l1t{
	
setting::setting(std::string type, std::string id, std::string value, std::string procRole) : 
_type(type),
_id(id),
_value(value),
_procRole(procRole)
{
	if ( type.find("bool") != std::string::npos )
	{
		std::ostringstream convString;

		if ( type.find("vector") != std::string::npos )
		{
			std::string delim(","); //TODO: should be read dynamically
			std::vector<std::string> vals;
			if ( !parse ( std::string(_value+delim+" ").c_str(),
			(
				* ( ( boost::spirit::classic::anychar_p - delim.c_str() )[boost::spirit::classic::push_back_a ( vals ) ] >> *boost::spirit::classic::space_p )
			), boost::spirit::classic::nothing_p ).full )
			{ 	
				throw std::runtime_error ("Wrong value format: " + _value);
			}

			for(std::vector<std::string>::iterator it=vals.begin(); it!=vals.end(); it++)
			{
				if ( it->find("true") != std::string::npos )
					convString << "1, ";
				else
					convString << "0, ";
			}
		}
		else
		{
			if ( value.find("true") != std::string::npos )
				convString << "1";
			else
				convString << "0";
		}

		_value = convString.str();
	}
}

setting::~setting()
{
	;
}

template <typename varType> std::vector<varType> setting::getVector(std::string delim)
{
	if ( _type.find("vector") == std::string::npos )
		throw std::runtime_error("The registered type: " + _type + " is not vector so you need to call the getValue method");

	std::vector<varType> vals;

	if ( !parse ( std::string(_value+delim+" ").c_str(),
          (
          	* ( boost::spirit::classic::uint_p[boost::spirit::classic::push_back_a ( vals ) ] >> delim.c_str() >> *boost::spirit::classic::space_p )
          ), boost::spirit::classic::nothing_p ).full )
	{ 	
		throw std::runtime_error ("Wrong value format: " + _value);
	}

	return vals;
}

template <class varType> varType setting::getValue()
{
	if ( _type.find("vector") != std::string::npos )
		throw std::runtime_error("The registered type: " + _type + " is vector so you need to call the getVector method");
	
	return boost::lexical_cast<varType>(_value);
}

setting& setting::operator=(const setting& aSet)
{
	_value = aSet._value;
	_id = aSet._id;
	_type = aSet._type;
	_procRole = aSet._procRole;
	return *this;
}

}
