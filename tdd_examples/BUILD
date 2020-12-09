load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "tests",
    srcs = glob(["*.cpp"]),
    deps = [
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_test(
    name = "fizzbuzz_example_test",
    srcs = ["fizzbuzz_example_test.cpp"],
    deps = [
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_test(
    name = "test_fixtures_and_assertions",
    srcs = ["test_fixtures_and_assertions.cpp"],
    deps = [
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_test(
    name = "exception_asserts_test",
    srcs = ["exception_asserts_test.cpp"],
    deps = [
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_test(
    name = "isolation_with_doubles_test",
    srcs = ["isolation_with_doubles_test.cpp"],
    deps = [
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_test(
    name = "mock_example_test",
    srcs = ["mock_example_test.cpp"],
    copts = [
        "-std=c++17",
        "-ggdb",
        "-O0",
    ],
    deps = [
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
