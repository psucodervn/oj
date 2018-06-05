#!/bin/bash
if ! g++ -std=c++14 -Wall main.cc -o main; then exit; fi
TASK_IN=tttt.in
TASK_OUT=tttt.out
INPUT_EXT=in
ANSWER_EXT=ans
OUTPUT_EXT=out

function gen_tests() {
  local id=0; local begin=1; local ex_id=0
  local exts=($INPUT_EXT $ANSWER_EXT)
  rm -R $2/* &> /dev/null
  mkdir -p $2
  while IFS='' read -r line || [[ -n "$line" ]]; do
    if [ "$line" == "-=-=-=" ]; then
      let ex_id=0;
      let begin=1;
    elif [ -z "$line" ]; then
      let begin=1;
      let ex_id=1;
    else
      if [ $begin -eq 1 ]; then
        if [ $ex_id -eq 0 ]; then let id+=1; fi
        let begin=0;
        echo $line > tests/$id.${exts[$ex_id]};
      else
        echo $line >> tests/$id.${exts[$ex_id]};
      fi
    fi
  done < $1
}

function run_test() {
  local TASK_ANS=$1;
  local TEST_NUM=$2;
  if ! `which gtime` -o time.out -f "(%es)" ../main < $TASK_IN > $TASK_OUT; then
    echo [1m[31mSample test \#$TEST_NUM: Runtime Error[0m `cat time.out`
    echo ========================================
    echo Sample Input \#$TEST_NUM
    cat $TASK_IN
  else
    if diff --brief --strip-trailing-cr --ignore-space-change $TASK_OUT $TASK_ANS; then
      echo [1m[32mSample test \#$TEST_NUM: Accepted[0m `cat time.out`
    else
      echo [1m[31mSample test \#$TEST_NUM: Wrong Answer[0m `cat time.out`
      echo ========================================
      echo Sample Input \#$TEST_NUM
      cat $TASK_IN
      echo ========================================
      echo Sample Output \#$TEST_NUM
      cat $TASK_ANS
      echo ========================================
      echo My Output \#$TEST_NUM
      cat $TASK_OUT
      echo ========================================
    fi
  fi
}

gen_tests test.data tests
cd tests
for test_file in *.$INPUT_EXT; do
  i=$((${#INPUT_EXT}))
  test_case=${test_file:0:$i-1}
  cp $test_file $TASK_IN
  run_test $test_case.$ANSWER_EXT $test_case
done

cd ..
rm -r ./tests main