FROM ubuntu:18.04

# Install dependencies and libFuzzer
RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    build-essential flex gdb automake bison g++-multilib \
    llvm-9 lld-9 clang-9 libclang-common-9-dev \
    libtool libtool-bin python autoconf automake cmake \
    lcov python-subprocess32 \
    protobuf-compiler libprotobuf-dev ninja-build pkg-config \
    python3-dev python3-setuptools \
    python-dev python-setuptools \
    iproute2 net-tools iputils-ping \
    git subversion \
    wget curl lynx w3m links \
    screen vim joe nano \
    unzip \
    liblzma-dev libglib2.0-dev libpixman-1-dev && \
    cd / && \
    git clone https://github.com/AFLplusplus/AFLplusplus afl++ && \
    git clone https://github.com/vanhauser-thc/afl-cov afl-cov && \
    git clone https://github.com/vanhauser-thc/libfuzzer-cov libfuzzer-cov && \
    ln -s /usr/bin/llvm-cov-9 /usr/bin/llvm-cov && \
    git clone https://github.com/vanhauser-thc/fuzzing-targets fuzzing-targets && \
    wget http://xmlsoft.org/sources/libxml2-2.9.2.tar.gz && \
    wget https://github.com/google/fuzzer-test-suite/raw/master/libxml2-v2.9.2/crash-50b12d37d6968a2cd9eb3665d158d9a2fb1f6e28 && \
    apt clean all && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Build AFL++
RUN cd /afl++ && \
    ln -s /usr/bin/llvm-config-9 /usr/bin/llvm-config && \
    make source-only && \
    make install

RUN cd /afl-cov && \
    make install

# Build libxml with libFuzzer
RUN cd / && \
    tar xfz libxml2-2.9.2.tar.gz && \
    mv libxml2-2.9.2 libxml2-libfuzzer && \
    cp -r libxml2-libfuzzer libxml2-afl++ && \
    cd libxml2-libfuzzer && \
    FUZZ_CXXFLAGS="-O2 -fno-omit-frame-pointer -g -fsanitize=address -fsanitize=fuzzer-no-link" && \
    CXX="clang++-9 $FUZZ_CXXFLAGS" CC="clang-9 $FUZZ_CXXFLAGS" ./configure --disable-shared && \
    make

# Build libxml with AFL++
RUN cd /libxml2-afl++ && \
    export CC=/afl++/afl-clang-fast && export CXX=/afl++/afl-clang-fast++ && \
    ./configure --disable-shared && \
    export AFL_USE_ASAN=1 && \
    make

ENV PATH=/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/sbin:/usr/local/bin
ENV AFL_SKIP_CPUFREQ=1
