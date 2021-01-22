# Profiling

## **Motivation**

Profiling is used to identify memory leaks inside a program. In computer science, a memory leak is a type of resource leak that occurs when a computer program incorrectly manages memory allocations in such a way that memory which is no longer needed is not released. A memory leak may also happen when an object is stored in memory but cannot be accessed by the running code. A memory leak has symptoms similar to a number of other problems and generally can only be diagnosed by a programmer with access to the programs' source code.

A space leak occurs when a computer program uses more memory than necessary. In contrast to memory leaks, where the leaked memory is never released, the memory consumed by a space leak is released, but later than expected.

Because they can exhaust available system memory as an application runs, memory leaks are often the cause of or a contributing factor to software aging.

## **Valgrind**

Valgrind is an instrumentation framework for building dynamic analysis tools. It can automatically detect many memory management and threading bugs, and profile your programs in detail.

### **Using vallgrind with Bazel**

`bazel run --copt=-O0 -c dbg --run_under='valgrind --leak-check=yes' //path/to:target`

### **Callgrind**

Callgrind is a call-graph generating cache and branch prediction profiler.
To use this tool, you must specify `--tool=callgrind` on the Valgrind command line.

`vallgrind --tool=callgrind /path/to/executable`

## **Instalation**

`sudo apt install vallgrind callgrind graphviz`

You can also install `gprof2dot`. This is a Python script to convert the output from many profilers into a dot graph:

`git clone https://github.com/jrfonseca/gprof2dot.git`

`chmod +x gprof2dot.py`

1. Create callgrind.out file:
`valgrind --tool=callgrind /path/to/executable`

2. Create .dot callmap with gprof2dot:
`./gprof2dot.py --format=callgrind --output=out.dot callgrind.out.PID`

3. Convert .dot callmap to .png:
`dot -Tpng out.dot -o graph.png`

4. Open png file:
`display graph.png`
