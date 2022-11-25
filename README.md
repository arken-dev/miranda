# TITAN

Web server async multithreading based on Linux api.

## BUILD

- clone in package directory
```
cd arkenplatform
git clone git@github.com:arkenplatform/titan.git packages/titan
Cloning into 'packages/miranda'...
remote: Enumerating objects: 30, done.
remote: Counting objects: 100% (30/30), done.
remote: Compressing objects: 100% (22/22), done.
remote: Total 30 (delta 10), reused 25 (delta 5), pack-reused 0
Receiving objects: 100% (30/30), 65.68 KiB | 0 bytes/s, done.
Resolving deltas: 100% (10/10), done.
Checking connectivity... done.
```

- build  project

```
mkdir build
cd build
cmake ..
make -j4 (4 is number of cores)

ARKEN BACKEND embedded
ARKEN BASE64 embedded
ARKEN DIGEST embedded
ARKEN MVM CONTAINER deque-stack
etc, etc
PACKAGE: titan
-- Configuring done
-- Generating done
-- Build files have been written to: /home/ariveira/projetos/arken/build

Building CXX object packages/miranda/CMakeFiles/titan.dir/src/main.cpp.o
Linking CXX executable ../../../bin/titan
Built target titan

```

### Config
config/titan.json

```
{
  "port"    : 2345,
  "threads" : 5,
  "pid"     : "tmp/pid/titan.pid"
}

```

## LICENSE
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
