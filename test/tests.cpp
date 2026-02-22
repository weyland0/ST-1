// Copyright 2025 UNN-CS

#include "alg.h"
#include <cstdint>
#include <gtest/gtest.h>

TEST(st1, checkPrimeTrue) { EXPECT_TRUE(checkPrime(23)); }

TEST(st1, checkPrimeFalse) { EXPECT_FALSE(checkPrime(12)); }

TEST(st1, checkLargePrimeTrue) { EXPECT_TRUE(checkPrime(999983)); }

TEST(st1, checkLargePrimeFalse) { EXPECT_FALSE(checkPrime(99999998)); }

TEST(st1, nextPrime1) { EXPECT_EQ(nextPrime(20), 23); }

TEST(st1, nextPrime2) { EXPECT_EQ(nextPrime(500), 503); }

TEST(st1, nPrime) { EXPECT_EQ(nPrime(185), 1103); }

TEST(st1, nPrimeLarge) { EXPECT_EQ(nPrime(1000000), 15485863); }

TEST(st1, sumPrime1) {
  uint64_t res = sumPrime(2000000);
  uint64_t expected = 142913828922;
  EXPECT_EQ(expected, res);
}

TEST(st1, sumPrime2) {
  uint64_t res = sumPrime(10);
  uint64_t expected = 17;
  EXPECT_EQ(expected, res);
}
