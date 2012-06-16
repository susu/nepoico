#ifndef CXXTEST_EXT_HPP_INC
#define CXXTEST_EXT_HPP_INC


#include <cxxtest/TestSuite.h>
#include <iostream>
#include <algorithm>

#define TCH tc_header(__PRETTY_FUNCTION__, __LINE__, __FILE__)

std::string strip( const std::string & );

std::string split_fname( std::string const & );

std::string underscore2space( std::string str );

void tc_header( std::string const & funcName,
                int line,
                std::string const & fname )
{
  std::string strippedFuncName = strip( funcName );
  std::string fname_only = split_fname( fname );
  std::cout << "\n=== " << strippedFuncName << " (" << fname_only << ":" << line << ") ===" << std::endl;
  // std::cout << "--- " << underscore2space( strippedFuncName ) << " ---" << std::endl;
}


std::string split_fname( std::string const & f )
{
  size_t pos = f.find_last_of('/');
  return f.substr( pos + 1 );
}

std::string
strip( const std::string & func ) 
{
  size_t pos = func.find( "test" );
  return func.substr( pos, func.length() - pos - 2 );
}

std::string underscore2space( std::string str )
{
  for ( size_t i = 0; i < str.length(); ++i )
  {
    if ( str[i] == '_' ) str[i] = ' ';
  }
  return str;
}
#endif
