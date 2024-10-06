#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
 private:
  unsigned int n;
  T *t;

 public:
  Array() : n(0), t(new T[n]()){};

  Array(const unsigned int n) : n(n), t(new T[n]()){};

  ~Array() { delete[] t; };

  Array(const Array &other) : n(other.n), t(new T[other.n]()) {
    for (size_t i = 0; i < this->n; i++) this->t[i] = other.t[i];
  };

  Array &operator=(const Array &other) {
    if (this != &other) {
      delete[] this->t;
      this->t = NULL;
      this->n = 0;
      this->t = new T[other.n]();
      this->n = other.n;
      for (size_t i = 0; i < this->n; i++) this->t[i] = other.t[i];
    }
    return (*this);
  };

  size_t size() const { return (this->n); };

  T &operator[](const size_t i) {
    if (i >= this->n)
      throw std::out_of_range("Invalid index");
    else
      return (this->t[i]);
  };

  const T &operator[](const size_t i) const {
    if (i >= this->n)
      throw std::out_of_range("Invalid index");
    else
      return (this->t[i]);
  }
};
#endif
