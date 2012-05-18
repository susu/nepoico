#include <string>
#include <map>

typedef std::map<int, std::string> DataMap;

class Parser : public DataMap
{
  public:
    Parser();
    virtual ~Parser();

    bool parseAndAdd( std::string const & bytes );
  private:
};

