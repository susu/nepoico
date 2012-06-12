#include <parser/ClassicParser.hpp>

#include <boost/spirit/include/classic.hpp>

parser::ClassicParser::ClassicParser()
  : m_state(DONE)
{
}

parser::ClassicParser::~ClassicParser()
{
}
namespace parser
{
  struct TlvFiller
  {
    TlvFiller( ClassicParser & parser) : m_parser(parser)
    {
    }

    void operator()(char v) const
    {
      m_parser.initStateMachine();
      m_parser.storeChar( v );
    }
    void operator()( const char* begin, const char* end ) const
    {
      int dist = std::distance(begin,end);
      std::string val(begin, dist);
      m_parser.storeValue( val );
    }
    ClassicParser & m_parser;
  };
}

bool parser::ClassicParser::parseAndAdd( std::string const & bytes )
{
  using namespace boost::spirit::classic;
  int length;
  std::string value;

  TlvFiller aa( *this );

  bool ret = parse( bytes.c_str(),
    *(
      (anychar_p)[ aa ] >>
      (anychar_p)[ assign_a(length) ] >>
      (repeat_p (boost::ref(length))[ anychar_p ])[ aa ]
    ) ).full;

  return ret && m_state == DONE;
}

std::string
parser::ClassicParser::getValue( int tag ) const
{
  DataMap::const_iterator it = m_map.find( tag );
  if (m_map.end() == it)
  {
    return "";
  }
  else
  {
    return it->second;
  }
}

void parser::ClassicParser::initStateMachine()
{
  m_state = NEXT_IS_CHAR;
}

void parser::ClassicParser::storeChar( char c )
{
  assert(NEXT_IS_CHAR == m_state);
  m_tmpChar = c;
  m_state = NEXT_IS_VALUE;
}

void parser::ClassicParser::storeValue( std::string const & value )
{
  assert(NEXT_IS_VALUE == m_state);
  int tag = ( int(m_tmpChar) & 0xff );
  m_map[ tag ] = value;
  m_state = DONE;
}

