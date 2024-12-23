#ifndef DOMAINCHECKER_HH
#define DOMAINCHECKER_HH 3

#include <string>

namespace dcheck {

    class DomainChecker {
    public:
        DomainChecker();
        ~DomainChecker();

        auto logo() -> void const;
        auto help() -> void const;

        auto domain_checker(const char*) -> bool;
        auto mout(int, const std::string&) -> void const;

        std::string m_locale {"en"};
    };

}

#endif
