#include <ClassicParser.hpp>

#include <boost/spirit/include/classic.hpp>

ClassicParser::ClassicParser()
{
}

ClassicParser::~ClassicParser()
{
}

bool ClassicParser::parseAndAdd( std::string const & bytes )
{
  using namespace boost::spirit::classic;
  char type;
  int length;
  std::string value;

  bool ret = parse( bytes.c_str(),
    (anychar_p)[ assign_a(type) ] >>
    (anychar_p)[ assign_a(length) ] >>
    (repeat_p (boost::ref(length))[ anychar_p ])[ assign_a(value) ]
    ,space_p).full;

  if (ret)
  {
    // hacky way
    // TODO test on different platform/compiler than Linux/GCC
    int t = (int(type) & 0xff);

    (*this)[ t ] = value;
  }
  return ret;
}

