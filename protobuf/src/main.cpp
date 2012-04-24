#include <person_proto.hpp>
#include <iostream>
#include <fstream>

static const std::string FNAME = "test.message";

void writePerson()
{
  tutorial::Person p;
  p.set_name( "Test Alec" );
  p.set_id( 95 );
  p.set_email( "alec.test@example.com" );

  tutorial::Person::PhoneNumber * n1 = p.add_phone();
  n1->set_type( tutorial::Person::MOBILE );
  n1->set_number( "+2983461827" );
  
  tutorial::Person::PhoneNumber * n2 = p.add_phone();
  n2->set_type( tutorial::Person::WORK );
  n2->set_number( "+102834701927" );

  std::ofstream ofs( FNAME.c_str(), std::ios::binary );
  p.SerializeToOstream( &ofs );

  std::cout << "write done!" << std::endl;
}

std::string phoneNumberToStr( tutorial::Person::PhoneType type )
{
  switch( type )
  {
    case tutorial::Person::MOBILE: return "MOBILE";
    case tutorial::Person::HOME:   return "HOME";
    case tutorial::Person::WORK: return "WORK";
    default: return "undef";
  }

}

void readPerson()
{
  std::ifstream ifs( FNAME.c_str(), std::ios::binary);

  tutorial::Person p;
  p.ParseFromIstream( &ifs );

  std::cout << "=============== PERSON ===============" << std::endl <<
               "  NAME ............... " << p.name() << std::endl <<
               "  EMAIL .............. " << p.email() << std::endl <<
               "  ID ................. " << p.id()   << std::endl <<
               "  #PHONES ............ " << p.phone_size() << std::endl;
  for (int i = 0; i < p.phone_size(); ++i)
  {
    const tutorial::Person::PhoneNumber & num = p.phone(i);
    std::cout <<
               "  ------------------------ " << std::endl <<
               "    TYPE ............. " << phoneNumberToStr(num.type()) << 
               " (" << num.type() << ")" << std::endl <<
               "    PHONE NUMBER ..... " << num.number() << std::endl;
  }
  std::cout << "=============== PERSON END ===========" << std::endl;
}


int main()
{
  writePerson();
  readPerson();

  return 0;
}

