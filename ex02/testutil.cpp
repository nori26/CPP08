#include <cstdlib>
#include <iostream>

#include "color.hpp"
namespace fortytwo {
const size_t g_max_width = 30;

void print_header(std::string funcname) {
  size_t len = funcname.size();

  if (len > g_max_width) {
    std::cerr << "header too long" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  size_t padding_size = g_max_width - len;
  size_t front_padding_size = padding_size / 2;
  size_t back_padding_size = padding_size - front_padding_size;

  std::cout << CYAN_BOLD_UNDELINE
            << "\n=============" << std::string(front_padding_size, ' ')
            << funcname << std::string(back_padding_size, ' ')
            << "=============\n"
            << RESET_COLOR << RESET_UNDERLINE << std::endl;
}

}  // namespace fortytwo
