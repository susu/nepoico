#ifndef TEST_HELPER_HPP_INC
#define TEST_HELPER_HPP_INC

namespace testhelper
{
  std::string createTlv( char tag, char length, std::string value );
}

std::string testhelper::createTlv( char tag, char length, std::string value )
{
  std::string retVal("00");
  retVal[0] = tag;
  retVal[1] = length;
  retVal.append( value );
  return retVal;
}


#endif
