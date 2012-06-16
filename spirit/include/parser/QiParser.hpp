#ifndef QIPARSER_HPP_INC
#define QIPARSER_HPP_INC

#include <parser/Parser.hpp>
namespace parser
{
  class QiParser : public Parser
  {
    public:
      QiParser();
      virtual ~QiParser();

      bool parseAndAdd( std::string const & bytes );

      std::string getValue( int tag ) const;
    private:
  };
}

#endif
