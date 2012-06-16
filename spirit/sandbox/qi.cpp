#include <iostream>
#include <boost/spirit/include/qi.hpp>

void print(int const& i)
{
  std::cout << i << std::endl;
}

namespace qi = boost::spirit::qi;

int main()
{
  using qi::int_;
  std::string input = "{45,67,345,564,121}";
  qi::parse(input.begin(), input.end(), 
    '{' >> int_[&print] >> *( ',' >> int_[&print] ) >> '}' );
  return 0;
}

