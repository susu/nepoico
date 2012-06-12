#ifndef PARSER_HPP_INC
#define PARSER_HPP_INC

#include <string>

namespace parser
{
  class Parser
  {
    public:
      virtual bool
      parseAndAdd( std::string const & bytes ) = 0;

      virtual std::string
      getValue( int tag ) const = 0;

      std::string operator[](int tag) const
      {
        return getValue( tag );
      }
  };
}

#endif
