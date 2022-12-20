#include "s21_smart_calc_test.h"

START_TEST(s21_test_0) {
  double x = 0;
  double orig = 10;

  char str[255] = "5 + 5";
  x = s21_smart_calc(str, x);
  ck_assert_double_eq(x, orig);
}
END_TEST

START_TEST(s21_test_1) {
  double x = 0;
  double orig = 162;
  // int error = 0;

  char str[255] = "   4 * 5 * 2 * 2 * 2 + 2";
  x = s21_smart_calc(str, x);
  ck_assert_double_eq(x, orig);
}
END_TEST

START_TEST(s21_test_2) {
  double x = 0;
  double orig = 20;
  // int error = 0;

  char str[255] = "  150 / 10 + 5 * 2 / 2";
  x = s21_smart_calc(str, x);
  ck_assert_double_eq(x, orig);
}
END_TEST

START_TEST(s21_test_3) {
  double x = 0;
  double orig = 9;
  // int error = 0;

  char str[255] = "  5 + 5 - 2 * 3 / 6";
  x = s21_smart_calc(str, x);
  ck_assert_double_eq(x, orig);
}
END_TEST
START_TEST(calc_test) {
  {
    char src[100] = "4^acos(x/4)/tan(2*x)";
    double x_text = 1.2;
    double result = s21_smart_calc(src, x_text);
    double real_result = -6.31492;
    ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001, "test-1 failed");
  }
  {
    char src[100] = "x+x";
    double x_text = 2;
    double result = s21_smart_calc(src, x_text);
    double real_result = 4;
    ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001, "test-2 failed");
  }
  {
    char src[100] = "123+0.456";
    double result = s21_smart_calc(src, 0);
    double real_result = 123.456;
    ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001, "test-3 failed");
  }
  {
    char src[100] = "log(x)";
    double x_text = -2;
    double result = s21_smart_calc(src, x_text);
    double real_result = NAN;
    ck_assert_msg(result != result && real_result != real_result,
                  "test-4 failed");
  }
  {
    char src[100] = "-(-1)";
    double result = s21_smart_calc(src, 0);
    double real_result = 1;
    ck_assert_msg(result == real_result, "test-5 failed");
  }
  {
    char src[100] = "cos(10mod2.2)";
    double result = s21_smart_calc(src, 0);
    double real_result = 0.362358;
    ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001, "test-6 failed");
  }
  {
    char src[100] = "sqrt(ln(10))";
    double result = s21_smart_calc(src, 0);
    double real_result = 1.517427;
    ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001, "test-7 failed");
  }
  {
    char src[100] = "atan(10)+sin(10)";
    double result = s21_smart_calc(src, 0);
    double real_result = 1.644775;
    ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001, "test-8 failed");
  }
  {
    char src[100] = "asin(1)";
    double result = s21_smart_calc(src, 0);
    double real_result = 1.570796;
    ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001, "test-9 failed");
  }
  {
    char src[100] = "10-20*(-10)";
    double result = s21_smart_calc(src, 0);
    double real_result = -210;
    ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001,
                  "test-10 failed");
  }
  {
    char src[100] = "-(o(i(a(10.01)*n(2))/10m2))^q(5)";
    int result = s21_validator(src);
    ck_assert_msg(result, "test-10 failed");
  }
  {
    char src[100] = ")(s(x)";
    int result = s21_validator(src);
    ck_assert_msg(!result, "test-10 failed");
  }
  {
    char src[100] = ".+m)";
    int result = s21_validator(src);
    ck_assert_msg(!result, "test-10 failed");
  }
}
END_TEST
START_TEST(s21_test_4) {
  double x = 0;
  double orig = 69;
  // int error = 0;

  char str[255] = "2+(5 * 5 * 5 + 5 + 2 * 2) / (2)";

  x = s21_smart_calc(str, x);
  ck_assert_double_eq(x, orig);
}
END_TEST

START_TEST(s21_test_5) {
  double x = 0;
  double orig = 11.958851;
  // int error = 0;

  char str[255] = "5 + (3 + sin(8/2 - 3.5)) *2";

  x = s21_smart_calc(str, x);
  ck_assert_double_eq_tol(x, orig, 1e-7);
}
END_TEST

START_TEST(s21_test_6) {
  double x = 0.0;
  char *str = "24*4 -3 * 2";
  double orig = 90;
  double value = s21_smart_calc(str, x);

  ck_assert_int_eq(value, orig);
}
END_TEST

START_TEST(s21_test_7) {
  double orig = 4;
  char *str = "2 - (-2)";
  double x = 0.0;
  double value = s21_smart_calc(str, x);

  ck_assert_int_eq(value, orig);
}
END_TEST

START_TEST(s21_test_8) {
  double orig = -0.41211848524;
  char *str = "-sin(9)";
  double x = 0.0;
  double value = s21_smart_calc(str, x);

  ck_assert_int_eq(value, orig);
}
END_TEST
START_TEST(s21_test_9) {
  double orig = 2.41211848524;
  char *str = "sin(9)-(-2)";
  double x = 0.0;
  double value = s21_smart_calc(str, x);

  ck_assert_int_eq(value, orig);
}
END_TEST
START_TEST(s21_test_10) {
  double orig = 0.91113026188;
  char *str = "-cos(9)";
  double x = 0.0;
  double value = s21_smart_calc(str, x);

  ck_assert_int_eq(value, orig);
}
END_TEST
START_TEST(plus_t) {
  double x = 0.0;
  double my = s21_smart_calc("(-2)+2", x);
  ck_assert_float_eq(my, 0);
}
END_TEST

START_TEST(minus_t) {
  double x = 0.0;
  double my = s21_smart_calc("(-2.2)-2.2", x);
  ck_assert_float_eq(my, -4.4);
}
END_TEST

START_TEST(mult_t) {
  double x = 0.0;
  double my = s21_smart_calc("(-2.2)*(+2.2)", x);
  ck_assert_float_eq(my, -4.84);
}
END_TEST

START_TEST(division_t) {
  double x = 0.0;
  double my = s21_smart_calc("(-2.2)/2.2", x);
  ck_assert_float_eq(my, -1);
}
END_TEST

START_TEST(degr_t) {
  double x = 0.0;
  double my = s21_smart_calc("(2.2)^(-2.2)", x);
  ck_assert_double_eq_tol(my, 0.17647, 0.17647);
}
END_TEST

START_TEST(sin_t) {
  double x = 0.0;
  double my = s21_smart_calc("sin(+2)", x);
  ck_assert_double_eq(my, sin(2));
}
END_TEST

START_TEST(cos_t) {
  double x = 0.0;
  long double my = s21_smart_calc("cos(2)", x);
  ck_assert_double_eq_tol(my, cos(2), 1e-7);
}
END_TEST

START_TEST(tan_t) {
  double x = 0.0;
  long double my = s21_smart_calc("tan(2)", x);
  ck_assert_ldouble_eq(my, tan(2));
}
END_TEST

START_TEST(asin_t) {
  double x = 0.0;
  long double my = s21_smart_calc("asin(1)", x);
  ck_assert_ldouble_eq(my, asin(1));
}
END_TEST

START_TEST(acos_t) {
  double x = 0.0;
  long double my = s21_smart_calc("acos(1)", x);
  ck_assert_ldouble_eq(my, acos(1));
}
END_TEST

START_TEST(atan_t) {
  double x = 0.0;
  long double my = s21_smart_calc("atan(1)", x);
  ck_assert_ldouble_eq(my, atan(1));
}
END_TEST

START_TEST(ln_t) {
  double x = 0.0;
  long double my = s21_smart_calc("log(1)", x);
  ck_assert_ldouble_eq(my, log(1));
}
END_TEST

START_TEST(log_t) {
  double x = 0.0;
  long double my = s21_smart_calc("log(1)", x);
  ck_assert_ldouble_eq(my, log10(1));
}
END_TEST

START_TEST(sqrt_t) {
  double x = 0.0;
  long double my = s21_smart_calc("sqrt(1)", x);
  ck_assert_ldouble_eq(my, sqrt(1));
}
END_TEST

START_TEST(mod_t) {
  double x = 0.0;
  long double my = s21_smart_calc("4mod8", x);
  ck_assert_ldouble_eq(my, 4);
}
END_TEST
Suite *suite_smart_calc(void) {
  Suite *s = suite_create("suite_smart_calc");
  TCase *tc = tcase_create("suite_smart_calc");

  tcase_add_test(tc, s21_test_0);
  tcase_add_test(tc, s21_test_1);
  tcase_add_test(tc, s21_test_2);
  tcase_add_test(tc, s21_test_3);
  tcase_add_test(tc, calc_test);
  tcase_add_test(tc, s21_test_4);
  tcase_add_test(tc, s21_test_5);
  tcase_add_test(tc, s21_test_6);
  tcase_add_test(tc, s21_test_7);
  tcase_add_test(tc, s21_test_8);
  tcase_add_test(tc, s21_test_9);
  tcase_add_test(tc, s21_test_10);

  tcase_add_test(tc, plus_t);
  tcase_add_test(tc, minus_t);
  tcase_add_test(tc, division_t);
  tcase_add_test(tc, mult_t);
  tcase_add_test(tc, degr_t);
  tcase_add_test(tc, sin_t);
  tcase_add_test(tc, cos_t);
  tcase_add_test(tc, tan_t);
  tcase_add_test(tc, asin_t);
  tcase_add_test(tc, acos_t);
  tcase_add_test(tc, atan_t);
  tcase_add_test(tc, ln_t);
  tcase_add_test(tc, log_t);
  tcase_add_test(tc, sqrt_t);
  tcase_add_test(tc, mod_t);
  suite_add_tcase(s, tc);
  return s;
}