#ifndef QIPARSER_HPP_INC
#define QIPARSER_HPP_INC

#include <parser/Parser.hpp>

#include <map>

namespace parser
{
  typedef std::map<int, std::string> DataMap;
  class QiParser : public Parser
  {
    public:
      QiParser();
      virtual ~QiParser();

      bool parseAndAdd( std::string const & bytes );

      std::string getValue( int tag ) const;
    private:
      DataMap m_map;
  };
}

#endif
