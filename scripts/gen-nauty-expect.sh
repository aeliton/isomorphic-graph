#!/bin/bash

X=0
while read G1; do
    read G2
    read
    sed "s/REPLACE_G1/$G1/;s/REPLACE_G2/$G2/" expect.sh > nauty/expect_${X}.sh
    X=$((X+1))
done < instances
