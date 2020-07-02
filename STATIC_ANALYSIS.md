# Static analysis

## **Motivation**:
Static program analysis is the analysis of computer software that is performed without actually executing programs, in contrast with dynamic analysis, which is analysis performed on programs while they are executing. In most cases the analysis is performed on some version of the source code, and in the other cases, some form of the object code.

The term is usually applied to the analysis performed by an automated tool, with human analysis being called program understanding, program comprehension, or code review. Software inspections and software walkthroughs are also used in the latter case.

## **Clang Check**
The Clang Static Analyzer is a source code analysis tool that finds bugs in C, C++, and Objective-C programs. The analyzer is 100% open source and is part of the Clang project. Like the rest of Clang, the analyzer is implemented as a C++ library that can be used by other tools and applications.

### **Running <code>clang-check</code>**
Do not forget the <code>--</code> at the end of the command.
* <code>clang-check -analyze _/path/to/source/code.cpp_ --</code>

Running clang-check recursively in the project:
* <code>find _path/to/project_ -name '*.cpp'|xargs clang-check -analyze</code>

Use <url>https://cppinsights.io</url> for insights on how the code really looks like for the compiler.

## **Clang Format**
_ClangFormat_ describes a set of tools that are built on top of _LibFormat_. It can support your workflow in a variety of ways including a standalone tool and editor integrations.

### **Configuring Style with <code>clang-format</code>**

<code>clang-format</code> supports two ways to provide custom style options: directly specify style configuration in the <code>-style=</code> command line option or use <code>-style=file</code> and put style configuration in the <code>.clang-format</code> or <code>_clang-format</code> file in the project directory.

When using <code>-style=file</code>, <code>clang-format</code> for each input file will try to find the <code>.clang-format</code> file located in the closest parent directory of the input file. When the standard input is used, the search is started from the current directory.

The <code>.clang-format</code> file uses YAML format:
```
key1: value1
key2: value2
# A comment.
...
```

The configuration file can consist of several sections each having different Language: parameter denoting the programming language this section of the configuration is targeted at. See the description of the Language option below for the list of supported languages. The first section may have no language set, it will set the default style options for all lanugages. Configuration sections for specific language will override options set in the default section.

When clang-format formats a file, it auto-detects the language using the file name. When formatting standard input or a file that doesn’t have the extension corresponding to its language, <code>-assume-filename=</code> option can be used to override the file name <code>clang-format</code> uses to detect the language.

An easy way to get a valid <code>.clang-format</code> file containing all configuration options of a certain predefined style is:

* <code>clang-format -style=llvm -dump-config > .clang-format</code>

For another style f.e. Google's:

* <code>clang-format -style=google -dump-config > .clang-format</code>

When specifying configuration in the <code>-style=</code> option, the same configuration is applied for all input files. The format of the configuration is:

* <code>-style='{key1: value1, key2: value2, ...}'</code>

Therefore to change identation width from the default 4 to 2:
* <code>clang-format -style='{BasedOnStyle: Google, IndentWidth: 2}' -dump-config > .clang-format</code>

Changing column limit inside the Google style and IndentWidth = 2:
* <code>clang-format -style='{BasedOnStyle: Google, IndentWidth: 2, ColumnLimit: 120}' -dump-config > .clang-format</code>

To execute clang-format following the conent of the .clang-format file:
* <code>clang-format -i -style=file /path/to/src</code>

### **Disabling Formatting on a Piece of Code**

Clang-format understands also special comments that switch formatting in a delimited range. The code between a comment <code>// clang-format off</code> or <code>/\* clang-format off \*/</code> up to a comment <code> // clang-format on</code> or <code>/\* clang-format on \*/</code> will not be formatted. The comments themselves will be formatted (aligned) normally.

```
int formatted_code;
// clang-format off
    void    unformatted_code  ;
// clang-format on
void formatted_code_again;
```
