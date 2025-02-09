#!/usr/bin/env fish

 cmake --build ./cmake-build-debug/ --target clox -j 14
 ./cmake-build-debug/clox
