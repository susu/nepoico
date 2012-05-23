#include "cxxtest_ext.hpp"

#include <Parser.hpp>

class TestParser : public CxxTest::TestSuite
{
  public:
    void test_ctor()
    {
      TCH;
      Parser p;
    }

    void test_parseAndAdd_should_store_data_in_map_in_case_of_proper_input()
    {
      TCH;
      // Arrange
      std::string bytes( "00" );
      bytes[0] = char(255);
      bytes[1] = 3;
      bytes.append("bab");

      Parser p;

      // Act
      bool result = p.parseAndAdd( bytes );

      // Assert
      TS_ASSERT_EQUALS( true, result );
      TS_ASSERT_EQUALS( "bab", p[255] );
    }

    void test_parseAndAdd_should_store_data_in_map_in_case_of_proper_input_unsigned_char_issue()
    {
      TCH;
      // Arrange
      std::string bytes( "00" );
      bytes[0] = char(55);
      bytes[1] = 5;
      bytes.append("hello");

      Parser p;

      // Act
      bool result = p.parseAndAdd( bytes );

      // Assert
      TS_ASSERT_EQUALS( true, result );
      TS_ASSERT_EQUALS( "hello", p[55] );
    }

    void xtest_parseAndAdd_should_not_store_data_in_map_in_case_of_wrong_input()
    {
      TCH;
      // Arrange
      std::string bytes( "00" );
      bytes[0] = char(255);
      bytes[1] = 3;
      bytes.append("babaaa");

      Parser p;

      // Act
      bool result = p.parseAndAdd( bytes );

      // Assert
      TS_ASSERT_EQUALS( false, result );
      TS_ASSERT_DIFFERS( "bab", p[255] );
      TS_ASSERT_DIFFERS( "babaaa", p[255] );
    }
};

