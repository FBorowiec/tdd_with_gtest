# Static analysis

_"Deleted code is debugged code."_ - **Jeff Sickel**

## **Motivation**

Static program analysis is the analysis of computer software that is performed without actually executing programs, in contrast with dynamic analysis, which is analysis performed on programs while they are executing. In most cases the analysis is performed on some version of the source code, and in the other cases, some form of the object code.

The term is usually applied to the analysis performed by an automated tool, with human analysis being called program understanding, program comprehension, or code review. Software inspections and software walkthroughs are also used in the latter case.

## **Clang Check**

The Clang Static Analyzer is a source code analysis tool that finds bugs in C, C++, and Objective-C programs. The analyzer is 100% open source and is part of the Clang project. Like the rest of Clang, the analyzer is implemented as a C++ library that can be used by other tools and applications.

### **Running `clang-check`**

Do not forget the `--` at the end of the command

* `clang-check -analyze _/path/to/source/code.cpp_ --`

Running clang-check recursively in the project:

* `find _path/to/project_ -name '*.cpp'|xargs clang-check -analyze`

Use [cppinsights](https://cppinsights.io) for insights on how the code really looks like for the compiler.

## **Clang Format**

_ClangFormat_ describes a set of tools that are built on top of _LibFormat_. It can support your workflow in a variety of ways including a standalone tool and editor integrations.

### **Configuring Style with `clang-format`**

`clang-format` supports two ways to provide custom style options: directly specify style configuration in the `-style=` command line option or use `-style=file` and put style configuration in the `.clang-format` or `_clang-format` file in the project directory.

When using `-style=file`, `clang-format` for each input file will try to find the `.clang-format` file located in the closest parent directory of the input file. When the standard input is used, the search is started from the current directory.

The `.clang-format` file uses YAML format:

```cpp
key1: value1
key2: value2
# A comment.
...
```

The configuration file can consist of several sections each having different Language: parameter denoting the programming language this section of the configuration is targeted at. See the description of the Language option below for the list of supported languages. The first section may have no language set, it will set the default style options for all lanugages. Configuration sections for specific language will override options set in the default section.

When clang-format formats a file, it auto-detects the language using the file name. When formatting standard input or a file that doesn’t have the extension corresponding to its language, `-assume-filename=` option can be used to override the file name `clang-format` uses to detect the language.

An easy way to get a valid `.clang-format` file containing all configuration options of a certain predefined style is:

* `clang-format -style=llvm -dump-config > .clang-format`

For another style f.e. Google's:

* `clang-format -style=google -dump-config > .clang-format`

When specifying configuration in the `-style=` option, the same configuration is applied for all input files. The format of the configuration is:

* `-style='{key1: value1, key2: value2, ...}'`

Therefore to change indentation width from the default 4 to 2:

* `clang-format -style='{BasedOnStyle: Google, IndentWidth: 2}' -dump-config > .clang-format`

Changing column limit inside the Google style and IndentWidth = 2:

* `clang-format -style='{BasedOnStyle: Google, IndentWidth: 2, ColumnLimit: 120}' -dump-config > .clang-format`

To execute clang-format following the content of the .clang-format file:

* `clang-format -i -style=file /path/to/src`

### **Disabling Formatting on a Piece of Code**

Clang-format understands also special comments that switch formatting in a delimited range. The code between a comment `// clang-format off` or `/\* clang-format off \*/` up to a comment `// clang-format on` or `/\* clang-format on \*/` will not be formatted. The comments themselves will be formatted (aligned) normally.

```cpp
int formatted_code;
// clang-format off
    void    unformatted_code  ;
// clang-format on
void formatted_code_again;
```
