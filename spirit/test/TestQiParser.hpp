
#include "ParserCommonTests.hpp"

#include <parser/QiParser.hpp>

class TestQiParser : public CxxTest::TestSuite
{
    ParserCommonTests m_common;
  public:
    void test_parseAndAdd_should_store_data_in_map_in_case_of_proper_input()
    {
      TCH;
      parser::QiParser p;
      m_common.test_parseAndAdd_should_store_data_in_map_in_case_of_proper_input( p );
    }

    void test_parseAndAdd_should_store_data_in_map_in_case_of_proper_input_unsigned_char_issue()
    {
      TCH;
      parser::QiParser p;
      m_common.test_parseAndAdd_should_store_data_in_map_in_case_of_proper_input_unsigned_char_issue( p );
    }

    void test_parseAndAdd_should_indicate_error_in_case_of_longer_input()
    {
      TCH;
      parser::QiParser p;
      m_common.test_parseAndAdd_should_indicate_error_in_case_of_longer_input( p );
    }

    void test_parseAndAdd_should_store_multiple_tag_one_by_one()
    {
      TCH;
      parser::QiParser p;
      m_common.test_parseAndAdd_should_store_multiple_tag_one_by_one( p );
    }

    void test_parseAndAdd_should_process_multiple_TLV_in_one_string()
    {
      TCH;
      parser::QiParser p;
      m_common.test_parseAndAdd_should_process_multiple_TLV_in_one_string( p );
    }

    void test_getValue_should_return_empty_string_in_case_of_nonexistent_tag()
    {
      TCH;
      parser::QiParser p;
      m_common.test_getValue_should_return_empty_string_in_case_of_nonexistent_tag( p );
    }
};

