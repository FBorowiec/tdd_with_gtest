load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
  name = "fizzbuzz_example_test",
  srcs = ["fizzbuzz_example_test.cpp",],
  copts = [
    "-ggdb",
    "-O0",
    "-Werror",
  ],
  features = [
    "extra_warnings",
    "test_warnings",
    "treat_warnings_as_errors",
  ],
  deps = [
    "@gtest//:gtest",
    "@gtest//:gtest_main",
  ],
)

cc_test(
  name = "test_fixtures_and_assertions",
  srcs = ["test_fixtures.cpp",],
  copts = [
    "-ggdb",
    "-O0",
    "-Werror",
  ],
  features = [
    "extra_warnings",
    "test_warnings",
    "treat_warnings_as_errors",
  ],
  deps = [
    "@gtest//:gtest",
    "@gtest//:gtest_main",
  ],
)

cc_test(
  name = "exception_asserts_test",
  srcs = ["exception_asserts_test.cpp",],
  copts = [
    "-ggdb",
    "-O0",
    "-Werror",
  ],
  features = [
    "extra_warnings",
    "test_warnings",
    "treat_warnings_as_errors",
  ],
  deps = [
    "@gtest//:gtest",
    "@gtest//:gtest_main",
  ],
)
