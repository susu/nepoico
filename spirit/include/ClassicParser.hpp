#ifndef CLASSIC_PARSER_HPP_INC
#define CLASSIC_PARSER_HPP_INC

#include <Parser.hpp>

#include <string>
#include <map>

typedef std::map<int, std::string> DataMap;

class ClassicParser : public DataMap, Parser
{
  public:
    ClassicParser();
    virtual ~ClassicParser();

    bool parseAndAdd( std::string const & bytes );

    void initStateMachine();
    void storeChar( char c );
    void storeValue( std::string const & value );
  private:
    int m_state;
    char m_tmpChar;

    enum State
    {
      NEXT_IS_CHAR,
      NEXT_IS_VALUE,
      DONE
    };
};

#endif

