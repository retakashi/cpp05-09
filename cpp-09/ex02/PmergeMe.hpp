#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <exception>
#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <climits>

struct num_and_i {
  int num;
  size_t sorti;  // pre index
};

struct pair_data {
  std::pair<num_and_i, num_and_i> pair;
};

class PmergeMe {
 private:
  PmergeMe();
  int arr_size;
  char **arr;

 public:
  PmergeMe(int argc, char **argv);
  ~PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);

  // common
  void startSort();
  double getStartTime();
  double getTimeDiff(double start);
  int isValidArgs(char *arg);
  size_t getJacob(size_t i);

  template <typename T>
  int createPairData(T &c) {
    size_t i = 0;
    int num = 0;
    num_and_i nst;
    num_and_i pre_nst;
    pair_data pdata;

    nst.sorti = 0;
    pre_nst.sorti = 0;
    while (this->arr[i] != NULL) {
      num = isValidArgs(this->arr[i]);
      if (num == -1) return (-1);
      nst.num = num;
      if (i % 2 != 0) {
        pdata.pair = std::make_pair(pre_nst, nst);
        c.push_back(pdata);
      }
      pre_nst = nst;
      i++;
    }
    if (this->arr_size % 2 != 0) {
      nst.num = -1;
      pdata.pair = std::make_pair(pre_nst, nst);
      c.push_back(pdata);
    }
    return (0);
  }

  template <typename T>
  void sortPairData(T &c) {
    typename T::iterator it = c.begin();
    typename T::iterator ite = c.end();
    size_t i = 0;
    while (it != ite) {
      if (it->pair.second.num != -1 && it->pair.first.num > it->pair.second.num)
        std::swap(it->pair.first, it->pair.second);
      it->pair.second.sorti = i;
      it++;
      i++;
    }
  }

  // vector
  void vStoreLarger(std::vector<pair_data> v, size_t vsize,
                    std::vector<num_and_i> &sorted_v);
  void vRerrangePairSecond(std::vector<pair_data> &v);
  void vSetNewPairValue(std::vector<pair_data> &v, size_t newsize,
                        size_t small_i, size_t large_i);
  void vMergeInsertionSort(std::vector<pair_data> v,
                           std::vector<num_and_i> &sorted_v);
  void vInsertStraggler(num_and_i straggler, std::vector<num_and_i> &sorted_v);
  size_t vBinarySearch(int num, const std::vector<num_and_i> &arr, size_t min,
                       size_t max);
  void vInserSortedArray(const std::vector<pair_data> &v,
                         std::vector<num_and_i> &sorted_v);
  void vPrintAns(const std::vector<num_and_i> &ans_v, double t_dif);

  // list
  void lStoreLarger(std::list<pair_data> l, size_t lsize,
                    std::list<num_and_i> &sorted_l);
  void lRerrangePairSecond(std::list<pair_data> &l);
  void lSetNewPairValue(std::list<pair_data>::iterator newit, std::list<pair_data>::iterator cuit,
                                size_t i,bool is_cuit_larger);
  void lSetNewPairValue(std::list<pair_data> &l, size_t newsize, size_t small_i,
                        size_t large_i);
  void lMergeInsertionSort(std::list<pair_data> l,
                           std::list<num_and_i> &sorted_l);
  void lInsertStraggler(num_and_i straggler, std::list<num_and_i> &sorted_l);
  size_t lBinarySearch(int num, const std::list<num_and_i> &arr, size_t min,
                       size_t max);
  void lInserSortedArray(const std::list<pair_data> &l,
                         std::list<num_and_i> &sorted_l);
  void lPrintAns(const std::list<num_and_i> &ans_l,
                 const std::vector<num_and_i> &ans_v, double t_dif);

  template <typename T>
  typename T::iterator getIterator(size_t max, T &list) {
    typename T::iterator it = list.begin();
    typename T::iterator ite = list.end();
    size_t i = 0;
    while (i < max && it != ite) {
      i++;
      it++;
    }
    return (it);
  }

  template <typename T>
  typename T::const_iterator getConstIterator(size_t max, T &list) {
    typename T::const_iterator it = list.begin();
    typename T::const_iterator ite = list.end();
    size_t i = 0;
    while (i < max && it != ite) {
      i++;
      it++;
    }
    return (it);
  }
};

#endif
