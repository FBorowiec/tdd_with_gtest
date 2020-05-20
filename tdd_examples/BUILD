load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
  name = "fizzbuzz_test",
  srcs = glob(["*.cpp",]),
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
