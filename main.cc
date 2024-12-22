/*
 * Copyright (C) 2024, S-Patriarch
 * DomainChecker - проверка доступности и отзывчивости доменов.
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
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

    std::string str {};
    std::fstream fs;
    fs.open(args[1], std::ios::in);
    if (!fs.is_open()) {
      if (dch.m_locale=="ru") str = "Файл "+args[1]+" не открыт.";
      if (dch.m_locale=="en") str = args[1]+" file is not open.";
      dch.mout(1, str);
    }
    else {
      fs.seekg(0, std::ios::end);
      if (fs.tellg()==0) {
        if (dch.m_locale=="ru") str = "Файл "+args[1]+" пуст.";
        if (dch.m_locale=="en") str = args[1]+" file is empty.";
        dch.mout(1, str);
      }
      else {
        // основная работа...
      }
      fs.close();
    }
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
