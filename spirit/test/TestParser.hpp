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
      std::string bytes( createTlv( char(255), 3, "bab" ) );
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
      std::string bytes( createTlv(char(55), 5, "hello") );
      Parser p;

      // Act
      bool result = p.parseAndAdd( bytes );

      // Assert
      TS_ASSERT_EQUALS( true, result );
      TS_ASSERT_EQUALS( "hello", p[55] );
    }

    void test_parseAndAdd_should_not_store_data_in_map_in_case_of_wrong_input()
    {
      TCH;
      // Arrange
      std::string bytes( createTlv( char(255), 3, "babaaa") );
      Parser p;

      // Act
      bool result = p.parseAndAdd( bytes );

      // Assert
      TS_ASSERT_EQUALS( false, result );
      TS_ASSERT_DIFFERS( "bab", p[255] );
      TS_ASSERT_DIFFERS( "babaaa", p[255] );
    }

    void test_parseAndAdd_should_store_multiple_tag()
    {
      TCH;
      // Arrange
      std::vector< std::string > tlvs;
      tlvs.push_back( createTlv( char(150), 2,    "ha" ) );
      tlvs.push_back( createTlv( char(20),  5, "hahah" ) );
      tlvs.push_back( createTlv( char(223), 1,     "x" ) );
      Parser p;

      // Act
      bool result = p.parseAndAdd( tlvs[0] );
      result &=     p.parseAndAdd( tlvs[1] );
      result &=     p.parseAndAdd( tlvs[2] );

      // Assert
      TS_ASSERT_EQUALS( true, result );
      TS_ASSERT_EQUALS( "ha",    p[150] );
      TS_ASSERT_EQUALS( "hahah", p[20] );
      TS_ASSERT_EQUALS( "x",     p[223] );
    }

  protected:
    std::string createTlv( char tag, char length, std::string value )
    {
      std::string retVal("00");
      retVal[0] = tag;
      retVal[1] = length;
      retVal.append( value );
      return retVal;
    }
};

