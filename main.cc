/*
 * Copyright (C) 2024, S-Patriarch
 * DomainChecker - проверка доступности и отзывчивости доменов.
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include "pl/pl.conio"
#include "dcheck.hh"

int main(int argc, char **argv)
{
  using std::cout;
  using std::endl;

  std::vector<std::string> args(argv, argv+argc);
  dcheck::DomainChecker dch;

  if (args.size()==2) {
    cout << pl::mr::clrscr;
    dch.logo();
    cout << endl;

  }
  else {
    cout << pl::mr::clrscr;
    dch.logo();
    cout << endl;
    //dch.help();
    cout << endl;
  }

  std::exit(0);
}
