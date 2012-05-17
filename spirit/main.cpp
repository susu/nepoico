#include <boost/spirit/include/classic.hpp>

#include <iostream>

using namespace boost::spirit::classic;


int main()
{
  //       type: one byte
  //       length: one byte
  //       value: 'length' bytes
  std::string seq("\x10\x04xyza"); // example byte-seq
  char type, length=0;
  std::string value;

  bool ret = parse( seq.c_str(),
    (anychar_p)[ assign_a(type) ] >> 
    (anychar_p)[ assign_a(length) ] >>
    (repeat_p (boost::ref(length))[ anychar_p ])[ assign_a(value) ] >>
    //(repeat_p (int(length))[ anychar_p ])[ assign_a(value) ] >>
    (*anychar_p)
    ,space_p).full;
  if (!ret) std::cout << "error during parse\n";
  else
  {
    std::cout << "Message type: " << int(type) << std::endl <<
                 "      length: " << int(length) << std::endl <<
                 "       value: " << value << std::endl;
  }


}
