#!/bin/bash
assert() {
    expected="$1"
    input="$2"

    ./atcc "$input" > tmp.s
    cc -o tmp tmp.s
    ./tmp
    actual="$?"

    if [ "$actual" = "$expected" ]; then
        echo "$input => $actual"
    else
        echo "$input => $expected expected, but got $actual"
        exit 1
    fi
}


assert 0 0
assert 42 42
assert 22 5+21-4
assert 22 '5 + 21 - 4'

echo OK