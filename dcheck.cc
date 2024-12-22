#include "pl/pl.system"
#include "dcheck.hh"

namespace dcheck {

  DomainChecker::DomainChecker()
  {
    pl::System sys;
    bool isLocaleRU = sys.is_locale_available("ru_RU");
    if (isLocaleRU) m_locale = "ru";
  }

  DomainChecker::~DomainChecker() {}

}
