#!/usr/bin/env expect
set timeout 2
spawn ./dreadnaut
expect "Dreadnaut version 2.6 \(64 bits\).\n>" {send "n = 13\r"}
expect "> " {send "n = 13\r"}
expect "> " {send "g\r"}
expect "0 :" {send "REPLACE_G1\r"}
expect "> " {send "x @\r"}
expect "> " {send "c\r"}
expect "> " {send "g\r"}
expect "0 :" {send "REPLACE_G2\r"}
expect "> " {send "x @\r"}
expect "> " {send "##\r"}
expect "> " {send "q\r"}
