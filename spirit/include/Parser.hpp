#ifndef PARSER_HPP_INC
#define PARSER_HPP_INC

#include <string>

class Parser
{
  public:
    virtual bool parseAndAdd( std::string const & bytes ) = 0;
};

#endif
