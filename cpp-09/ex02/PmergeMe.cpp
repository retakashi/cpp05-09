#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv) : arr_size(argc - 1), arr(&argv[1]) {
  if (arr_size < 1) {
    std::cout << "Error: No argument" << std::endl;
    throw std::exception();
  }
}

PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    this->arr_size = other.arr_size;
    this->arr = other.arr;
  }
  return (*this);
}

bool operator<(const pair_data &lhs, const pair_data &rhs) {
  return (lhs.pair.second.num < rhs.pair.second.num);
}

bool operator<(int num, const num_and_i &other) { return (num < other.num); }

bool operator>(int num, const num_and_i &other) { return (num > other.num); }

bool operator==(const pair_data &other, int num) {
  return (other.pair.second.num == num);
}

bool operator==(num_and_i &other, const int num) { return (other.num == num); }

bool operator!=(const pair_data &other, int num) {
  return (other.pair.second.num != num);
}

void PmergeMe::startSort() {
  // vector
  std::vector<pair_data> v;
  size_t csize = this->arr_size / 2;
  double start_ms = getStartTime();

  if (createPairData(v) == -1) {
    std::cout << "Error: Invalid number" << std::endl;
    throw std::exception();
  }
  sortPairData(v);
  static std::vector<num_and_i> sorted_v;
  sorted_v.clear();
  vStoreLarger(v, csize, sorted_v);
  double dif_ms = getTimeDiff(start_ms);
  vPrintAns(sorted_v, dif_ms);

  // list
  std::list<pair_data> l;
  start_ms = getStartTime();
  if (createPairData(l) == -1) {
    std::cout << "Error: Invalid number" << std::endl;
    throw std::exception();
  }
  sortPairData(l);
  static std::list<num_and_i> sorted_l;
  sorted_l.clear();
  lStoreLarger(l, csize, sorted_l);
  dif_ms = getTimeDiff(start_ms);
  lPrintAns(sorted_l, sorted_v, dif_ms);
}

double PmergeMe::getStartTime() { return (double)clock() / CLOCKS_PER_SEC; }

double PmergeMe::getTimeDiff(double start) {
  return ((double)clock() / CLOCKS_PER_SEC) - start;
}

int PmergeMe::isValidArgs(char *arg) {
  std::stringstream ss;
  std::stringstream ss2;
  std::string int_max_str;
  int ret = 0;

  if (static_cast<std::string>(arg).find("-") != std::string::npos) return (-1);
  ss << arg;
  ss >> ret;
  ss2 << INT_MAX;
  ss2 >> int_max_str;
  if (ret == INT_MAX && (static_cast<std::string>(arg) != int_max_str))
    return (-1);
  return (ret);
}

size_t PmergeMe::getJacob(size_t i) {
  if (i == 0) return (0);
  if (i == 1) return (1);
  return getJacob(i - 1) + 2 * getJacob(i - 2);
}

void PmergeMe::vStoreLarger(std::vector<pair_data> v, size_t vsize,
                            std::vector<num_and_i> &sorted_v) {
  if (v.size() == 1 || (v.size() == 2 && v[v.size() - 1] == -1)) {
    vMergeInsertionSort(v, sorted_v);
    return;
  } else if (vsize == (size_t)this->arr_size / 2)
    vStoreLarger(v, vsize - 1, sorted_v);
  else {
    vRerrangePairSecond(v);
    vStoreLarger(v, v.size(), sorted_v);
  }
  vMergeInsertionSort(v, sorted_v);
}

void PmergeMe::vRerrangePairSecond(std::vector<pair_data> &v) {
  size_t vsize = v.size();
  size_t newsize = 0;
  if (v[vsize - 1] == -1) vsize--;
  for (size_t i = 0; i < vsize; i++) {
    if (i % 2 != 0) {
      if (v[i - 1] < v[i])
        vSetNewPairValue(v, newsize, i - 1, i);
      else
        vSetNewPairValue(v, newsize, i, i - 1);
      newsize++;
    }
  }
  if (vsize % 2 != 0 && v[vsize - 1] != -1) {
    v[newsize].pair.first.num = v[vsize - 1].pair.second.num;
    v[newsize].pair.first.sorti = vsize - 1;
    v[newsize].pair.second.num = -1;
    v[newsize].pair.second.sorti = 0;
    newsize++;
  }
  v.resize(newsize);
}

void PmergeMe::vSetNewPairValue(std::vector<pair_data> &v, size_t newsize,
                                size_t small_i, size_t large_i) {
  v[newsize].pair.first.num = v[small_i].pair.second.num;
  v[newsize].pair.first.sorti = small_i;
  v[newsize].pair.second.num = v[large_i].pair.second.num;
  v[newsize].pair.second.sorti = large_i;
}

void PmergeMe::vMergeInsertionSort(std::vector<pair_data> v,
                                   std::vector<num_and_i> &sorted_v) {
  if (v.size() == 1 || (v.size() == 2 && v[v.size() - 1] == -1)) {
    if (!sorted_v.empty()) return;
    sorted_v.push_back(v[0].pair.second);
    sorted_v.insert(sorted_v.begin(), v[0].pair.first);
    if (v.size() == 2 && v[v.size() - 1] == -1)
      vInsertStraggler(v[v.size() - 1].pair.first, sorted_v);
  } else
    vInserSortedArray(v, sorted_v);
}

void PmergeMe::vInsertStraggler(num_and_i straggler,
                                std::vector<num_and_i> &sorted_v) {
  size_t pos = vBinarySearch(straggler.num, sorted_v, 0, sorted_v.size() - 1);
  if (pos > sorted_v.size() - 1)
    sorted_v.push_back(straggler);
  else
    sorted_v.insert(sorted_v.begin() + pos, straggler);
}

void PmergeMe::vInserSortedArray(const std::vector<pair_data> &v,
                                 std::vector<num_and_i> &sorted_v) {
  std::vector<num_and_i> pre_s = sorted_v;
  for (size_t i = 0; i < sorted_v.size(); i++)
    sorted_v[i].sorti = v[pre_s[i].sorti].pair.second.sorti;
  sorted_v.insert(sorted_v.begin(), v[pre_s[0].sorti].pair.first);

  size_t start_i = 0;
  size_t ja_i = 1;
  size_t vsize = v.size();
  bool has_straggler = false;
  if (v[vsize - 1] == -1) {
    vsize--;
    has_straggler = true;
  }
  while (sorted_v.size() < vsize * 2) {
    size_t ja = getJacob(ja_i) * 2;
    start_i += ja;
    size_t i = start_i;
    if (i >= vsize - 1) i = vsize - 1;
    while (ja > 0 && sorted_v.size() < vsize * 2) {
      num_and_i target = v[pre_s[i].sorti].pair.first;
      size_t max = std::find(sorted_v.begin(), sorted_v.end(),
                             v[pre_s[i].sorti].pair.second.num) -
                   sorted_v.begin();
      size_t pos = vBinarySearch(target.num, sorted_v, 0, max - 1);
      sorted_v.insert(sorted_v.begin() + pos, target);
      i--;
      ja--;
    }
    ja_i++;
  }
  if (has_straggler == true)
    vInsertStraggler(v[v.size() - 1].pair.first, sorted_v);
}

size_t PmergeMe::vBinarySearch(const int num, const std::vector<num_and_i> &arr,
                               size_t min, size_t max) {
  size_t mid = 0;
  while (min < max) {
    mid = (min + max) / 2;
    if (num < arr[mid])
      max = mid;
    else if (num > arr[mid])
      min = mid + 1;
    else
      return (mid);
  }
  if (num < arr[min])
    return (min);
  else
    return (max + 1);
}

void PmergeMe::vPrintAns(const std::vector<num_and_i> &v_ans, double dif_ms) {
  std::cout << "Before: ";
  for (size_t i = 0; this->arr[i] != NULL; i++)
    std::cout << this->arr[i] << " ";
  std::cout << std::endl;
  std::cout << "After: ";
  for (size_t i = 0; i < v_ans.size(); i++)
    if (v_ans[i].num != -1) std::cout << v_ans[i].num << " ";
  std::cout << std::endl;
  std::cout << "Time to process a range of " << this->arr_size
            << " elements with std::vector : " << std::fixed
            << dif_ms * (double)1000 << " ms" << std::endl;
}

// list

void PmergeMe::lStoreLarger(std::list<pair_data> l, size_t lsize,
                            std::list<num_and_i> &sorted_l) {
  if (l.size() == 1 || (l.size() == 2 && *(l.rbegin()) == -1)) {
    lMergeInsertionSort(l, sorted_l);
    return;
  } else if (lsize == (size_t)this->arr_size / 2)
    lStoreLarger(l, lsize - 1, sorted_l);
  else {
    lRerrangePairSecond(l);
    lStoreLarger(l, l.size(), sorted_l);
  }
  lMergeInsertionSort(l, sorted_l);
}

void PmergeMe::lRerrangePairSecond(std::list<pair_data> &l) {
  size_t lsize = l.size();
  size_t newsize = 0;
  if (*(l.rbegin()) == -1) lsize--;
  std::list<pair_data>::iterator it = l.begin();
  std::list<pair_data>::iterator preit = l.begin();
  std::list<pair_data>::iterator newit = l.begin();
  for (size_t i = 0; i < lsize; i++) {
    if (i % 2 != 0) {
      if (*preit < *it) {
        lSetNewPairValue(newit, it, i, true);
      } else {
        lSetNewPairValue(newit, it, i, false);
      }
      newsize++;
      newit++;
    }
    preit = it;
    it++;
  }
  std::list<pair_data>::reverse_iterator rit = l.rbegin();
  if (lsize % 2 != 0) {
    if (*(l.rbegin()) == -1) rit++;
    newit->pair.first.num = rit->pair.second.num;
    newit->pair.first.sorti = lsize - 1;
    newit->pair.second.num = -1;
    newit->pair.second.sorti = 0;
    newsize++;
  }
  l.resize(newsize);
}

void PmergeMe::lSetNewPairValue(std::list<pair_data>::iterator newit,
                                std::list<pair_data>::iterator cuit, size_t i,
                                bool is_cuit_larger) {
  std::list<pair_data>::iterator preit = cuit;
  preit--;
  if (is_cuit_larger == true) {
    newit->pair.first.num = preit->pair.second.num;
    newit->pair.first.sorti = i - 1;
    newit->pair.second.num = cuit->pair.second.num;
    newit->pair.second.sorti = i;
  } else {
    newit->pair.first.num = cuit->pair.second.num;
    newit->pair.first.sorti = i;
    newit->pair.second.num = preit->pair.second.num;
    newit->pair.second.sorti = i - 1;
  }
}

void PmergeMe::lMergeInsertionSort(std::list<pair_data> l,
                                   std::list<num_and_i> &sorted_l) {
  if (l.size() == 1 || (l.size() == 2 && *(l.rbegin()) == -1)) {
    if (!sorted_l.empty()) return;
    sorted_l.push_back(l.begin()->pair.second);
    sorted_l.insert(sorted_l.begin(), l.begin()->pair.first);
    if (l.size() == 2 && *(l.rbegin()) == -1)
      lInsertStraggler(l.rbegin()->pair.first, sorted_l);
  } else
    lInserSortedArray(l, sorted_l);
}

void PmergeMe::lInsertStraggler(num_and_i straggler,
                                std::list<num_and_i> &sorted_l) {
  size_t pos = lBinarySearch(straggler.num, sorted_l, 0, sorted_l.size() - 1);
  if (pos > sorted_l.size() - 1)
    sorted_l.push_back(straggler);
  else
    sorted_l.insert(getIterator(pos, sorted_l), straggler);
}

size_t PmergeMe::lBinarySearch(int num, const std::list<num_and_i> &arr,
                               size_t min, size_t max) {
  size_t mid = 0;
  std::list<num_and_i>::const_iterator it;
  while (min < max) {
    mid = (min + max) / 2;
    it = getConstIterator(mid, arr);
    if (num < *it)
      max = mid;
    else if (num > *it)
      min = mid + 1;
    else
      return (mid);
  }
  it = getConstIterator(min, arr);
  if (num < *it)
    return (min);
  else
    return (max + 1);
  if (min > max) return (max + 1);
}

void PmergeMe::lInserSortedArray(const std::list<pair_data> &l,
                                 std::list<num_and_i> &sorted_l) {
  std::list<num_and_i> pre_s = sorted_l;
  std::list<num_and_i>::iterator it = sorted_l.begin();
  std::list<num_and_i>::iterator preit = pre_s.begin();
  std::list<num_and_i>::iterator ite = sorted_l.end();
  while (it != ite) {
    it->sorti = getConstIterator(preit->sorti, l)->pair.second.sorti;
    it++;
    preit++;
  }
  sorted_l.insert(sorted_l.begin(),
                  getConstIterator(pre_s.begin()->sorti, l)->pair.first);
  size_t start_i = 0;
  size_t ja_i = 1;
  size_t lsize = l.size();
  size_t insert_cnt = 0;
  bool has_straggler = false;
  preit = pre_s.begin();

  if ((*l.rbegin()) == -1) {
    lsize--;
    has_straggler = true;
  }
  while (sorted_l.size() < lsize * 2) {
    insert_cnt = 0;
    size_t ja = getJacob(ja_i) * 2;
    start_i += ja;
    size_t i = start_i;
    if (i >= lsize - 1) i = lsize - 1;
    while (insert_cnt < ja && sorted_l.size() < lsize * 2) {
      preit = getIterator(i, pre_s);
      std::list<pair_data>::const_iterator targetit =
          getConstIterator(preit->sorti, l);
      num_and_i target = targetit->pair.first;
      size_t max = std::distance(sorted_l.begin(),
                                 std::find(sorted_l.begin(), sorted_l.end(),
                                           targetit->pair.second.num));
      size_t pos = lBinarySearch(target.num, sorted_l, 0, max - 1);
      sorted_l.insert(getIterator(pos, sorted_l), target);
      i--;
      insert_cnt++;
    }
    ja_i++;
  }
  if (has_straggler == true) lInsertStraggler(l.rbegin()->pair.first, sorted_l);
}

void PmergeMe::lPrintAns(const std::list<num_and_i> &ans_l,
                         const std::vector<num_and_i> &ans_v, double dif_ms) {
  size_t i = 0;
  std::list<num_and_i>::const_iterator it = ans_l.begin();
  while (it != ans_l.end()) {
    if (it->num != ans_v[i].num)
      std::cout << "error! li: " << it->num << std::endl;
    it++;
    i++;
  }
  std::cout << "Time to process a range of " << this->arr_size
            << " elements with std::list : " << std::fixed
            << dif_ms * (double)1000 << " ms" << std::endl;
}
