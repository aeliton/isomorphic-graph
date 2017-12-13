#!/bin/bash

while read G1; do
    read G2
    echo -e "$G1\n$G2" | ./brute
    read
done < instances
