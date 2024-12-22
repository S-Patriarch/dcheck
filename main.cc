/*
 * Copyright (C) 2024, S-Patriarch
 * DomainChecker - проверка доступности и отзывчивости доменов.
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include "dcheck.hh"

int main(int argc, char **argv)
{
  using std::cout;
  using std::endl;

  std::vector<std::string> args(argv, argv+argc);

  dcheck::DomainChecker dch;
  dch.logo();
  cout << endl;

  std::exit(0);
}
