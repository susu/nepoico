#ifndef PARSER_HPP_INC
#define PARSER_HPP_INC

#include <string>

namespace parser
{
  class Parser
  {
    public:
      virtual bool parseAndAdd( std::string const & bytes ) = 0;
  };
}

#endif
