#!/bin/bash

for script in expect_*; do echo $script; expect $script; done | tee -a expect_nauty_results

