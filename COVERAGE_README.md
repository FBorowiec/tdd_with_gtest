# Code coverage

## **Motivation**:
Test coverage is a measure used to describe the degree to which the source code of a program is executed when a particular test suite runs. A program with high test coverage, measured as a percentage, has had more of its source code executed during testing, which suggests it has a lower chance of containing undetected software bugs compared to a program with low test coverage.

## **GCOV & LCOV**:
**GCOV** is a tool you can use in conjunction with GCC to test code coverage in your programs.

**LCOV** is a graphical front-end for GCC's coverage testing tool gcov. It collects gcov data for multiple source files and creates HTML pages containing the source code annotated with coverage information. It also adds overview pages for easy navigation within the file structure. LCOV supports statement, function and branch coverage measurement.

## **Instalation**:
<code>sudo apt install lcov</code>


### **Using lcov with Bazel**:
```
bazel coverage --build_tests_only --compilation_mode=opt --combined_report=lcov --coverage_report_generator=@bazel_tools//tools/test/CoverageOutputGenerator/java/com/google/devtools/coverageoutputgenerator:Main --instrument_test_targets=true --javabase=@bazel_tools//tools/jdk:remote_jdk11 --noremote_accept_cached --spawn_strategy=sandboxed //PATH/TO:TARGET
```
* <code>--combined_report</code> Specifies lcov as desired cumulative coverage report type.
* <code>--coverage_report_generator</code> Location of the binary that is used to generate coverage reports.
* <code>--instrument_test_targets</code> When coverage is enabled, specifies whether to consider instrumenting test rules. When set, test rules included by <code>--instrumentation_filter</code> are instrumented.
* <code>--javabase</code> JAVABASE used for the JDK invoked by Bazel. This is the java_runtime which will be used to execute external Java commands.
* <code>--noremote_accept_cached</code> If set to true, <code>--noremote_upload_local_results</code> and <code>--noremote_accept_cached</code> will not apply to the disk cache. If a combined cache is used: <code>--noremote_upload_local_results</code> will cause results to be written to the disk cache, but not uploaded to the remote cache

```
lcov --summary /PATH/TO/coverage.dat

genhtml -o /PATH/TO/dustom/output_dir /PATH/TO/coverage.dat

firefox /PATH/TO/CUSTOM/OUTPUT_DIR/index.html
```