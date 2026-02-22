// Copyright 2025 UNN-CS
#include <cmath>
#include <cstdint>
#include <vector>

#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value == 1 || value == 2) {
    return true;
  }

  if (value % 2 == 0) {
    return false;
  }

  uint64_t divider = 3;
  while (divider * divider <= value) {
    if (value % divider == 0) {
      return false;
    }

    divider += 2;
  }

  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 1) {
    return 2;
  }

  double ln_n = std::log(n);
  double bound = static_cast<double>(n) * (ln_n + std::log(ln_n)) + 10.0;
  std::uint64_t limit = static_cast<std::uint64_t>(bound);

  std::vector<bool> sieve(limit + 1, true);
  sieve[0] = sieve[1] = false;

  for (std::uint64_t i = 2; i * i <= limit; ++i) {
    if (sieve[i]) {
      for (std::uint64_t j = i * i; j <= limit; j += i) {
        sieve[j] = false;
      }
    }
  }

  std::vector<std::uint64_t> primes;
  primes.reserve(n);
  for (std::uint64_t i = 2; i <= limit; ++i) {
    if (sieve[i]) {
      primes.push_back(i);
      if (primes.size() == n)
        return i;
    }
  }

  return nPrime(n);
}

uint64_t nextPrime(uint64_t value) {
  if (value < 2) {
    return 2;
  }

  uint64_t candidate = value + (value % 2 == 0 ? 1 : 2);
  while (!checkPrime(candidate)) {
    candidate += 2;
  }
  return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound == 1) {
    return 0;
  }

  if (hbound == 2) {
    return 1;
  }

  std::vector<bool> sieve(hbound, true);
  sieve[0] = sieve[1] = false;

  for (uint64_t i = 2; i * i < hbound; ++i) {
    if (sieve[i]) {
      for (uint64_t j = i * i; j < hbound; j += i) {
        sieve[j] = false;
      }
    }
  }

  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; ++i) {
    if (sieve[i])
      sum += i;
  }
  return sum;
}
