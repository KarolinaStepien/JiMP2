//
// Created by mwypych on 31.03.17.
//

#include <gtest/gtest.h>
#include <initializer_list>
#include <memory>
#include <complex>
#include <vector>
#include <utility>
#include <MemLeakTest.h>
#include <Matrix.h>

using ::algebra::Matrix;
using ::std::make_unique;
using ::std::move;
using ::std::swap;
using ::std::vector;
using ::std::unique_ptr;
using ::std::pair;

using Init = std::initializer_list<std::vector<std::complex<double>>>;

class MatrixTests : public ::testing::Test, MemLeakTest {
};

TEST_F(MatrixTests, IsAbleToCreateSingleMatrix) {
  {
    Matrix m1{0, 0};
    pair<size_t, size_t> expected_size{0, 0};
    EXPECT_EQ(expected_size, m1.Size());
  }
}

TEST_F(MatrixTests, IsAbleToCreateSingleMatrixFromInitlializerList) {
  {
    Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};
  }
}

TEST_F(MatrixTests, HasPrintingMethod) {
  {
    Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};
    EXPECT_EQ("[0i1, 0i0, 0i0; 0i0, 0i1, 0i0; 0i0, 0i0, 0i1]", m1.Print());
  }
}

TEST_F(MatrixTests, DoesNotHoldReferenceToExternalInitlization) {
  unique_ptr<Matrix> m;
  {
    m = make_unique<Matrix, Init>({{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}});
  }
  {
    const char *str = "111111111111111111111111111111111111111111111";
  }
  EXPECT_EQ("[0i1, 0i0, 0i0; 0i0, 0i1, 0i0; 0i0, 0i0, 0i1]", m->Print());
}

TEST_F(MatrixTests, IsAbleToAddMatrices) {
  Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};
  Matrix m2{{7. + 1.0i, 0., 0.}, {0., 1.0i, 8.}, {15. + 2.0i, 0. + 3.0i, 4. + 1.0i}};
  EXPECT_EQ("[7i2, 0i0, 0i0; 0i0, 0i2, 8i0; 15i2, 0i3, 4i2]", m1.Add(m2).Print());
  EXPECT_EQ("[0i1, 0i0, 0i0; 0i0, 0i1, 0i0; 0i0, 0i0, 0i1]", m1.Print());
  EXPECT_EQ("[7i1, 0i0, 0i0; 0i0, 0i1, 8i0; 15i2, 0i3, 4i1]", m2.Print());
}

TEST_F(MatrixTests, AdditionWorksWithConstMatrices) {
  const Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};
  const Matrix m2{{7. + 1.0i, 0., 0.}, {0., 1.0i, 8.}, {15. + 2.0i, 0. + 3.0i, 4. + 1.0i}};
  EXPECT_EQ("[7i2, 0i0, 0i0; 0i0, 0i2, 8i0; 15i2, 0i3, 4i2]", m1.Add(m2).Print());
  EXPECT_EQ("[0i1, 0i0, 0i0; 0i0, 0i1, 0i0; 0i0, 0i0, 0i1]", m1.Print());
  EXPECT_EQ("[7i1, 0i0, 0i0; 0i0, 0i1, 8i0; 15i2, 0i3, 4i1]", m2.Print());
}

TEST_F(MatrixTests, IsAbleToSubtractMatrices) {
  Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};
  Matrix m2{{7. + 1.0i, 0., 0.}, {0., 1.0i, 8.}, {15. + 2.0i, 0. + 3.0i, 4. + 1.0i}};
  EXPECT_EQ("[-7i0, 0i0, 0i0; 0i0, 0i0, -8i0; -15i-2, 0i-3, -4i0]", m1.Sub(m2).Print());
  EXPECT_EQ("[0i1, 0i0, 0i0; 0i0, 0i1, 0i0; 0i0, 0i0, 0i1]", m1.Print());
  EXPECT_EQ("[7i1, 0i0, 0i0; 0i0, 0i1, 8i0; 15i2, 0i3, 4i1]", m2.Print());
}

TEST_F(MatrixTests, IsAbleToMultiplyMatrices) {
  Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}};
  Matrix m2{{7. + 1.0i, 0.}, {0., 1.0i}, {15. + 2.0i, 0. + 3.0i}};
  EXPECT_EQ("[-1i7, 0i0; 0i0, -1i0]", m1.Mul(m2).Print());
  EXPECT_EQ("[0i1, 0i0, 0i0; 0i0, 0i1, 0i0]", m1.Print());
  EXPECT_EQ("[7i1, 0i0; 0i0, 0i1; 15i2, 0i3]", m2.Print());
}

TEST_F(MatrixTests, IsAbleToMultiplyMatrices2) {
  Matrix m1{{1. + 3.0i, 2. + 2.0i}, {3. + 1.0i, 4. + 6.0i}, {5. + 5.i, 6. + 4.0i}};
  Matrix m2{{7. + 1.0i, 12. + 1.3i, 1.5 + 3.7i, 1.0i}, {15. + 2.0i, 2. + 4.6i, 2.1 + 3.8i, 1.4 + 0.2i}};
  EXPECT_EQ("[30i56, 2.9i50.5, -13i20, -0.6i4.2; "
                "68i108, 15.1i46.3, -13.6i40.4, 3.4i12.2; "
                "112i112, 47.1i102.1, -13.6i57.2, 2.6i11.8]", m1.Mul(m2).Print());
  EXPECT_EQ("[1i3, 2i2; 3i1, 4i6; 5i5, 6i4]", m1.Print());
  EXPECT_EQ("[7i1, 12i1.3, 1.5i3.7, 0i1; 15i2, 2i4.6, 2.1i3.8, 1.4i0.2]", m2.Print());
}

TEST_F(MatrixTests, MatricesWithMismatchingSizesShouldResultWithEmptyMatrix) {
  Matrix m1{{1.0i}, {1.0i}};
  Matrix m2{{7. + 1.0i, 3.2}, {0. + 3.9i, 1.0i}, {1.6 + 2.11i, 0. + 3.5i}};
  pair<size_t, size_t> expected_size{0, 0};
  EXPECT_EQ("[]", m1.Mul(m2).Print());
  EXPECT_EQ(expected_size, m1.Mul(m2).Size());
  EXPECT_EQ("[0i1; 0i1]", m1.Print());
  EXPECT_EQ("[7i1, 3.2i0; 0i3.9, 0i1; 1.6i2.11, 0i3.5]", m2.Print());
}

TEST_F(MatrixTests, CanComputeZerothPowerOfSecondPualiMatrix) {
  Matrix pauli{{0.0, 0.0 - 1.0i}, {1.0i, 0.0}};
  EXPECT_EQ("[1i0, 0i0; 0i0, 1i0]", pauli.Pow(0).Print())
            << "Result of matrix^0 should be generlized 1 i.e. unit matrix with 0 everywhere "
                "but diagonal. Diagonal elements should be equal to 1.0";
  EXPECT_EQ("[0i0, 0i-1; 0i1, 0i0]", pauli.Print());
  pair<size_t, size_t> expected_size{2, 2};
  EXPECT_EQ(expected_size, pauli.Pow(0).Size());
}

TEST_F(MatrixTests, CanComputeFirstPowerOfSecondPualiMatrix) {
  Matrix pauli{{0.0, 0.0 - 1.0i}, {1.0i, 0.0}};
  EXPECT_EQ("[0i0, 0i-1; 0i1, 0i0]", pauli.Pow(1).Print());

  pair<size_t, size_t> expected_size{2, 2};
  EXPECT_EQ(expected_size, pauli.Pow(1).Size());
  EXPECT_EQ(pauli.Print(), pauli.Pow(1).Print());
}

TEST_F(MatrixTests, CanComputeSecondPowerOfSecondPualiMatrix) {
  Matrix pauli{{0.0, 0.0 - 1.0i}, {1.0i, 0.0}};
  EXPECT_EQ("[1i0, 0i0; 0i0, 1i0]", pauli.Pow(2).Print());

  pair<size_t, size_t> expected_size{2, 2};
  EXPECT_EQ(expected_size, pauli.Pow(2).Size());
  EXPECT_EQ(pauli.Mul(pauli).Print(), pauli.Pow(2).Print());
}

TEST_F(MatrixTests, CanComputeEleventhPowerOfRandomMatrix) {
  Matrix pauli{{0.0, 0.0 - 1.0i}, {1.0i, 0.0}};
  EXPECT_EQ("[0i0, 0i-1; 0i1, 0i0]", pauli.Pow(11).Print());

  pair<size_t, size_t> expected_size{2, 2};
  EXPECT_EQ(expected_size, pauli.Pow(11).Size());
  EXPECT_EQ(pauli.Print(), pauli.Pow(11).Print());
}

TEST_F(MatrixTests, PowReturnsEmptyMatrixWhenMatrixIsNotSquared) {
  Matrix not_pauli{{0.0, 0.0 - 1.0i}, {1.0i, 0.0}, {0.3, 4.1i}};
  EXPECT_EQ("[]", not_pauli.Pow(3).Print());
  pair<size_t, size_t> expected_size{0, 0};
  EXPECT_EQ(expected_size, not_pauli.Pow(3).Size());
}