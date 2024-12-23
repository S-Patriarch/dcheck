/*
 * Copyright (C) 2024, S-Patriarch
 * DomainChecker - проверка доступности и отзывчивости доменов.
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cstring>
#include "pl/pl.conio"
#include "pl/pl.color"
#include "pl/pl.timer"
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

        std::string message {};

        std::fstream fs;
        fs.open(args[1], std::ios::in);

        if (!fs.is_open()) {
            if (dch.m_locale=="ru") message = "Файл "+args[1]+" не открыт.";
            if (dch.m_locale=="en") message = args[1]+" file is not open.";
            dch.mout(1, message);
        }
        else {
            fs.seekg(0, std::ios::end);
            if (fs.tellg()!=0) {
                fs.seekg(0, std::ios::beg);

                pl::Timer timer;
                pl::Color color;

                std::string sline {};
                timer.start();
                while (std::getline(fs, sline)) {
                    if (fs.eof()) break;
                    else {
                        bool is_res_check = dch.domain_checker(sline.c_str());
                        if (is_res_check) {
                            cout
                                << "[  "
                                << color.esc_tr(pl::Color::color::GREEN)
                                << "OK"
                                << color.esc_c()
                                << "  ] "
                                << sline
                                << endl;
                        }
                        else {
                            cout
                                << "["
                                << color.esc_tr(pl::Color::color::RED)
                                << "FAILED"
                                << color.esc_c()
                                << "] "
                                << sline
                                << endl;
                        }
                    }
                }
                timer.stop();
                cout
                    << "\nW: Время выполнения : "
                    << timer.duration_seconds()
                    << " секунд\n"
                    << endl;
            }
            else {
                if (dch.m_locale=="ru") message = "Файл "+args[1]+" пуст.";
                if (dch.m_locale=="en") message = args[1]+" file is empty.";
                dch.mout(1, message);
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
