#ifndef __ASKER_DOT__
#define __ASKER_DOT__

#include "gHeader.h"
#include <iostream>

inline const int LOG = 0;
inline const int WARNING = 1;
inline const int ERROR = 2;

inline bool promt(int type, std::string text, bool ask=true)
{
  if (type == ERROR)
    std::cout << "\033[1;31m" << text << "\033[0m";
  else if (type == WARNING)
    std::cout << "\033[1;33m" << text << "\033[0m";
  else if (type == LOG)
    std::cout << text;

  if (ask)
  {
    std::cout << " Continue? (Y/n): ";

    if (g_SKIP_PROMT)
    {
        std::cout << 'Y';
    }
    else
    {
      char ans;
      std::cin >> ans;

      if (ans == 'N' || ans == 'n')
      {
        std::cout << std::endl;
        return false;
      }
    }
  }

  std::cout << std::endl;
  return true;
}


#endif
