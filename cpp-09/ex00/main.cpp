#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
  try {
    if (argc < 1) return 0;
    BitcoinExchange b(argv[1]);
    b.startBitcoinExchanged();
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}

// Error: could not open file.
// $> ./btc input.txt
// 2011-01-03 => 3 = 0.9
// 2011-01-03 => 2 = 0.6
// 2011-01-03 => 1 = 0.3
// 2011-01-03 => 1.2 = 0.36
// 2011-01-09 => 1 = 0.32
// Error: not a positive number.
// Error: bad input => 2001-42-42
// 2012-01-11 => 1 = 7.1
// Error: too large a number.