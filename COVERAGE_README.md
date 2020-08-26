# Code coverage

_"There are two ways to write error-free programs and only the third one works."_ - **Alan J. Perlis**

## **Motivation**

Test coverage is a measure used to describe the degree to which the source code of a program is executed when a particular test suite runs. A program with high test coverage, measured as a percentage, has had more of its source code executed during testing, which suggests it has a lower chance of containing undetected software bugs compared to a program with low test coverage.

## **GCOV & LCOV**

**GCOV** is a tool you can use in conjunction with GCC to test code coverage in your programs.

**LCOV** is a graphical front-end for GCC's coverage testing tool gcov. It collects gcov data for multiple source files and creates HTML pages containing the source code annotated with coverage information. It also adds overview pages for easy navigation within the file structure. LCOV supports statement, function and branch coverage measurement.

## **Instalation**

`sudo apt install lcov`

### **Using lcov with Bazel**

```bash
bazel coverage --build_tests_only --compilation_mode=opt --combined_report=lcov --coverage_report_generator=@bazel_tools//tools/test/CoverageOutputGenerator/java/com/google/devtools/coverageoutputgenerator:Main --instrument_test_targets=true --javabase=@bazel_tools//tools/jdk:remote_jdk11 --noremote_accept_cached --spawn_strategy=sandboxed //PATH/TO:TARGET
```

* `--combined_report` Specifies lcov as desired cumulative coverage report type.
* `--coverage_report_generator` Location of the binary that is used to generate coverage reports.
* `--instrument_test_targets` When coverage is enabled, specifies whether to consider instrumenting test rules. When set, test rules included by `--instrumentation_filter` are instrumented.
* `--javabase` JAVABASE used for the JDK invoked by Bazel. This is the java_runtime which will be used to execute external Java commands.
* `--noremote_accept_cached` If set to true, `--noremote_upload_local_results` and `--noremote_accept_cached` will not apply to the disk cache. If a combined cache is used: `--noremote_upload_local_results` will cause results to be written to the disk cache, but not uploaded to the remote cache

```bash
lcov --summary /PATH/TO/coverage.dat

genhtml -o /PATH/TO/dustom/output_dir /PATH/TO/coverage.dat

firefox /PATH/TO/CUSTOM/OUTPUT_DIR/index.html
```
