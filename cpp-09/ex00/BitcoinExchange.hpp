#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

class BitcoinExchange {
 private:
  BitcoinExchange();
  char *infile;
  std::map<int, double> database;
  std::string read_str;
  std::string rate;
  int i_rate;
  double d_rate;
  double ans;

 public:
  BitcoinExchange(char *infile);
  BitcoinExchange(const BitcoinExchange& other);
  ~BitcoinExchange();
  BitcoinExchange& operator=(const BitcoinExchange& other);
  void createDataMap();
  int splitDateAndRate(std::string& date, std::string& rate,
                       const std::string& split);
  int getMapId(std::string date);
  bool isValidDate(std::string date[]);
  double getMapValue(std::string rate);
  void startBitcoinExchanged();
  bool isValidInputValue();
  int convertInputStrToNum();
  void culculateFromMap(int id);
  void putBitcoinExchanged() const;
};

enum {
  year,
  month,
  day,
  date_element = 3,
  year_len = 4,
  month_day_len = 2,
  date_len = 10,
  int_num = 1,
  double_num = 2
};

#endif
