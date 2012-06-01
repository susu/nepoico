#ifndef CLASSIC_PARSER_HPP_INC
#define CLASSIC_PARSER_HPP_INC

#include <string>
#include <map>

typedef std::map<int, std::string> DataMap;

class ClassicParser : public DataMap
{
  public:
    ClassicParser();
    virtual ~ClassicParser();

    bool parseAndAdd( std::string const & bytes );
  private:
};

#endif

