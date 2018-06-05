#!/bin/bash
if ! g++ -g -std=c++14 -Wall $DBG main.cc; then
    exit
fi
cd tests
INPUT_EXT=in
OUTPUT_EXT=out
MY_EXT=res
rm -R *$MY_EXT &>/dev/null
for test_file in *.$INPUT_EXT
do
    i=$((${#INPUT_EXT}))
    test_case=${test_file:0:$i-1}
    if ! `which gtime` -o time.out -f "(%es)" ../a.out < $test_case.$INPUT_EXT > $test_case.$MY_EXT; then
        echo [1m[31mSample test \#$test_case: Runtime Error[0m `cat time.out`
        echo ========================================
        echo Sample Input \#$test_case
        cat $test_case.$INPUT_EXT
    else
        if diff --brief --strip-trailing-cr $test_case.$MY_EXT $test_case.$OUTPUT_EXT; then
            echo [1m[32mSample test \#$test_case: Accepted[0m `cat time.out`
        else
            echo [1m[31mSample test \#$test_case: Wrong Answer[0m `cat time.out`
            echo ========================================
            echo Sample Input \#$test_case
            cat $test_case.$INPUT_EXT
            echo ========================================
            echo Sample Output \#$test_case
            cat $test_case.$OUTPUT_EXT
            echo ========================================
            echo My Output \#$test_case
            cat $test_case.$MY_EXT
            echo ========================================
        fi
    fi
done