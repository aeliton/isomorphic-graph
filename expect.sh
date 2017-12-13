#!/usr/bin/env expect

spawn ./dreadnaut
expect "Dreadnaut version 2.6 \(64 bits\).\n>" {send "n = 13\r"}
expect "> " {send "n = 13\r"}
expect "> " {send "g\r"}
expect "0 :" {send "5 2 3 9 1 4 6;9 2 4 5 3 8 10 6 7 11;8 7 0 4 3 6 12 10 5 9;11 12 1 4 10 5 7 0 2 6;7;4 2 8 7 9 10 6 3 11;8 7 0 9 5;2 4 8 3 6 11 5;7 2 0 1 6 9 10 12 11 3 4;5 12 10 11 6 8;9 3 12 5 7;12 0 1 2;10.\r"}
expect "> " {send "x @\r"}
expect "> " {send "c\r"}
expect "> " {send "g\r"}
expect "0 :" {send "8 3 6 9 1;11 10 8 3 9 2 0 7 4;9 7 12 1 3;10 11 8 7 0 4 1;12 6 5 10;9 10 11 1 7 8 2 0 3 4;1 10 7 9 5 11 0;4 12 5 11 2 1 3 6 10 0;3 10 6 5 0 9 2 12 4 7 11;1 12 2 4 0 8;8 3 6 11 7 0 12 2 1 9;3;2.\r"}
expect "> " {send "x @\r"}
expect "> " {send "##\r"}
expect "> " {send "q\r"}
