#!/usr/bin/env bash
# -*- coding: utf-8 -*-
#
# DESCRIPTION: run_me Example usage of snip, rsnip and lsnip utilities
#
# VERSION: 23.10.2
#
# AUTHOR: Jordi Roca
# CREATED: 2023/10/02
#
# LICENSE: See LICENSE file.
#


chmod +x *.sh
./install.sh
./center_haikus.sh < sample.txt > haikus.txt

echo "Left snipping"
echo "============="
cat haikus.txt | ./lsnip | tr " " "_"
echo -e "\n\nRight snipping"
echo "=============="
cat haikus.txt | ./rsnip | tr " " "_"
echo -e "\n\nSnipping"
echo "========"
cat haikus.txt | ./snip | tr " " "_"
echo
