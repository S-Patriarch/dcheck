#include <iostream>
#include "dcheck.hh"

namespace dcheck {

  auto DomainChecker::mout(int status, const std::string& s)
    -> void const
  {
    std::string message_status {};

    switch (status) {
    case 0:  message_status = "W: "; break;
    case 1:  message_status = "E: "; break;
    default: message_status = "";    break;
    }

    std::cout
      << message_status
      << s
      << '\n'
      << std::endl;
  }

}
