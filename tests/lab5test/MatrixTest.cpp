//
// Created by mwypych on 31.03.17.
//

#include <gtest/gtest.h>
#include <memory>
#include <MemLeakTest.h>
#include <Matrix.h>

using ::algebra::Matrix;
using ::std::make_unique;
using ::std::move;
using ::std::fill;
using ::std::swap;
using ::std::vector;
using ::std::unique_ptr;
using ::std::pair;

using Init = std::initializer_list<std::vector<std::complex<double>>>;

class MemoryChunkTests : public ::testing::Test, MemLeakTest {
};

TEST_F(MemoryChunkTests, IsAbleToCreateSingleMatrix) {
  {
    Matrix m1{0,0};
    pair<size_t, size_t > expected_size {0,0};
    EXPECT_EQ(expected_size, m1.Size());
  }
}

TEST_F(MemoryChunkTests, IsAbleToCreateSingleMatrixFromInitlializerList) {
  {
    Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};
  }
}

TEST_F(MemoryChunkTests, HasPrintingMethod) {
  {
    Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};
    EXPECT_EQ("[0i1, 0i0, 0i0; 0i0, 0i1, 0i0; 0i0, 0i0, 0i1]", m1.Print());
  }
}

TEST_F(MemoryChunkTests, DoesNotHoldReferenceToExternalInitlization) {
  unique_ptr<Matrix> m;
  {
    m = make_unique<Matrix,Init>({{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}});
  }
  {
    const char *str = "111111111111111111111111111111111111111111111";
  }
  EXPECT_EQ("[0i1, 0i0, 0i0; 0i0, 0i1, 0i0; 0i0, 0i0, 0i1]", m->Print());
}

TEST_F(MemoryChunkTests, IsAbleToAddMatrices) {
  Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};
  Matrix m2{{7 + 1.0i, 0., 0.}, {0., 1.0i, 8.}, {15. + 2i, 0. + 3i, 4 + 1.0i}};
  EXPECT_EQ("[7i2, 0i0, 0i0; 0i0, 0i2, 8i0; 15i2, 0i3, 4i2]", m1.Add(m2).Print());
  EXPECT_EQ("[0i1, 0i0, 0i0; 0i0, 0i1, 0i0; 0i0, 0i0, 0i1]", m1.Print());
  EXPECT_EQ("[7i1, 0i0, 0i0; 0i0, 0i1, 8i0; 15i2, 0i3, 4i1]", m2.Print());
}

TEST_F(MemoryChunkTests, AdditionWorksWithConstMatrices) {
  const Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};
  const Matrix m2{{7 + 1.0i, 0., 0.}, {0., 1.0i, 8.}, {15. + 2i, 0. + 3i, 4 + 1.0i}};
  EXPECT_EQ("[7i2, 0i0, 0i0; 0i0, 0i2, 8i0; 15i2, 0i3, 4i2]", m1.Add(m2).Print());
  EXPECT_EQ("[0i1, 0i0, 0i0; 0i0, 0i1, 0i0; 0i0, 0i0, 0i1]", m1.Print());
  EXPECT_EQ("[7i1, 0i0, 0i0; 0i0, 0i1, 8i0; 15i2, 0i3, 4i1]", m2.Print());
}


TEST_F(MemoryChunkTests, IsAbleToMultiplyMatrices) {
  Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}};
  Matrix m2{{7 + 1.0i, 0.}, {0., 1.0i}, {15. + 2i, 0. + 3i}};
  EXPECT_EQ("[22i4, 0i5; 22i4, 0i5]", m1.Mul(m2).Print());
  EXPECT_EQ("[0i1, 0i0, 0i0; 0i0, 0i1, 0i0]", m1.Print());
  EXPECT_EQ("[7i1, 0i0; 0i0, 0i1; 15i2, 0i3]", m2.Print());
}