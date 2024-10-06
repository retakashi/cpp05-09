#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char* infile)
    : infile(infile), i_rate(-1), d_rate(-1), ans(0) {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
  *this = other;
}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this != &other) {
    this->infile = other.infile;
    this->database = other.database;
    this->read_str = other.read_str;
    this->i_rate = other.i_rate;
    this->d_rate = other.d_rate;
    this->rate = other.rate;
    this->ans = other.ans;
  }
  return (*this);
}

void BitcoinExchange::startBitcoinExchanged() {
  std::fstream fs;
  fs.open(this->infile);
  if (!fs) throw std::runtime_error("Error: could not open file.");
  this->createDataMap();
  while (std::getline(fs, this->read_str)) {
    if (this->read_str == "date | value") continue;
    if (this->splitDateAndRate(this->read_str, this->rate, " | ") == -1) {
      std::cerr << "Error: bad input => " << this->read_str << std::endl;
      continue;
    }
    int id = this->getMapId(this->read_str);
    if (id == -1) {
      std::cerr << "Error: bad input2 => " << this->read_str << std::endl;
      continue;
    }
    if (this->isValidInputValue() == false) continue;
    this->d_rate = -1;
    this->i_rate = -1;
    int ret = this->convertInputStrToNum();
    if (ret == -1) continue;
    this->culculateFromMap(id);
    this->putBitcoinExchanged();
  }
}

void BitcoinExchange::createDataMap() {
  std::fstream fs;
  std::string str;
  std::string rate;
  int id = 0;
  double value = 0.0;

  fs.open("./data.csv");
  if (!fs) {
    throw std::runtime_error("Error: failed to open data.csv");
  }
  while (std::getline(fs, str)) {
    if (str == "date,exchange_rate") continue;
    if (splitDateAndRate(str, rate, ",") == -1)
      throw std::runtime_error("Invalid date");
    id = getMapId(str);
    if (id == -1) throw std::runtime_error("Invalid date");
    value = getMapValue(rate);
    if (id == -1) throw std::runtime_error("Invalid rate");
    this->database.insert(std::make_pair(id, value));
  }
  if (this->database.size() == 0)
    throw std::runtime_error("Error: data.csv is empty");
}

int BitcoinExchange::splitDateAndRate(std::string& date, std::string& rate,
                                      const std::string& split) {
  size_t pos = date.find(split);
  if (pos == std::string::npos) return (-1);
  if (pos != date_len) {
    date = date.substr(0, pos);
    return (-1);
  }
  rate = date.substr(pos + 1);
  date = date.substr(0, date_len);
  return (0);
}

// MapId: data's date
int BitcoinExchange::getMapId(std::string date) {
  std::string d[date_element];
  int i = year;
  int id = 0;
  std::stringstream ss;

  while (i < date_element) {
    size_t pos = date.find("-");
    if (i == year && pos == year_len)
      d[i] = date.substr(0, year_len);
    else if (i == month && pos == month_day_len)
      d[i] = date.substr(0, month_day_len);
    else if (i == day)
      d[i] = date.substr(0, month_day_len);
    else
      return (-1);
    i++;
    date = date.substr(pos + 1);
  }
  if (isValidDate(d) == false) return (-1);
  i = year - 1;
  while (++i < date_element) ss << d[i];
  ss >> id;
  return (id);
}

bool BitcoinExchange::isValidDate(std::string date[]) {
  int d[date_element];
  std::stringstream ss;
  int i = year;
  while (i < date_element) {
    for(int j = 0;date[i][j] != '\0';j++)
    {
      if (date[i][j] != '-' && !isdigit(date[i][j]))
        return (false);
    }
    ss << date[i];
    ss >> d[i];
    if (i == year && d[i] < 2009) return (false);
    if (i == month && (d[i] < 1 || d[i] > 12)) return (false);
    if (i == day && (d[i] < 1 || d[i] > 31)) return (false);
    ss.str("");
    ss.clear(std::stringstream::goodbit);
    i++;
  }
  return (true);
}

// MapValue: data's rate
double BitcoinExchange::getMapValue(std::string rate) {
  std::stringstream ss;
  double value;

  ss << rate;
  ss >> value;
  return (value);
}

bool BitcoinExchange::isValidInputValue() {
  if (this->rate.find("-") != std::string::npos) {
    std::cerr << "Error: not a positive number." << std::endl;
    return (false);
  }
  this->rate = this->rate.substr(2);  // rate == " | num" -> rate == "num"
  for (int i = 0; this->rate[i] != '\0'; i++) {
    if (this->rate[i] != '.' && isdigit(this->rate[i]) == false) {
      std::cerr << "Error: invalid number." << std::endl;
      return (false);
    }
  }
  return (true);
}

int BitcoinExchange::convertInputStrToNum() {
  std::stringstream ss;
  if (rate.find(".") != std::string::npos) {
    ss << this->rate;
    ss >> this->d_rate;
  } else {
    if (this->rate.size() > 4) {
      std::cerr << "Error: too large a number." << std::endl;
      return (-1);
    }
    ss << this->rate;
    ss >> this->i_rate;
  }
  if (this->d_rate > 1000 || this->i_rate > 1000) {
    std::cerr << "Error: too large a number." << std::endl;
    return (-1);
  }
  if (this->i_rate != -1) return (int_num);
  return (double_num);
}

void BitcoinExchange::culculateFromMap(int id) {
  std::map<int, double>::iterator datai;
  datai = this->database.find(id);
  if (datai == this->database.end()) {
    datai = this->database.lower_bound(id);  // datai->second > id
    if (datai != this->database.begin()) datai--;
  }
  if (this->i_rate != -1)
    this->ans = (double)this->i_rate * datai->second;
  else
    this->ans = this->d_rate * datai->second;
}

void BitcoinExchange::putBitcoinExchanged() const {
  std::cout << this->read_str << " => " << this->rate << " = " << this->ans
            << std::endl;
}
