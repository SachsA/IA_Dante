#!/bin/bash

begin=
finishas=
finishbr=
finishde=
finishto=

if [ -z $1 ] ; then
    echo -e "\033[31;1;5mSorry but there is no file in parameter !\033[0m"
    exit
elif !( [ -f $1 ] ) || !( [ -r $1 ] ) ; then
    echo -e "\033[33;1;5mHey that's not a file or i can't read it sorry !\033[0m"
    exit
else
    echo -e "\033[32;1;4mThat file is perfect !\033[0m\n"
fi



if [ -f ./astar/solver ] && [ -x ./astar/solver ] ; then
    echo -e "\033[35;1mASTAR ALGORITHM STARTS NOW !!!\033[0m"
    begin=$(date +%S%3N)
    ./astar/solver $1 1> /dev/null
    finishas=$(expr $(date +%S%3N) - $begin)
    echo -e "\033[35;1mTime of the ASTAR :\t\t\033[34m${finishas} ms\033[0m\n"
else
    echo -e "\033[31;1;5mI can't find your ASTAR's binary, sorry ! :(\033[0m\n"
fi



if [ -f ./breadth/solver ] && [ -x ./breadth/solver ] ; then
    echo -e "\033[36;1mBREADTH ALGORITHM STARTS NOW !!!\033[0m"
    begin=$(date +%S%3N)
    ./breadth/solver $1 1> /dev/null
    finishbr=$(expr $(date +%S%3N) - $begin)
    echo -e "\033[36;1mTime of the BREADTH :\t\t\033[34m${finishbr} ms\033[0m\n"
else
    echo -e "\033[31;1;5mI can't find your BREADTH's binary, sorry ! :(\033[0m\n"
fi



if [ -f ./depth/solver ] && [ -x ./depth/solver ] ; then
    echo -e "\033[33;1mDEPTH ALGORITHM STARTS NOW !!!\033[0m"
    begin=$(date +%S%3N)
    ./depth/solver $1 1> /dev/null
    finishde=$(expr $(date +%S%3N) - $begin)
    echo -e "\033[33;1mTime of the DEPTH :\t\t\033[34m${finishde} ms\033[0m\n"
else
    echo -e "\033[31;1;5mI can't find your DEPTH's binary, sorry ! :(\033[0m\n"
fi



if [ -f ./tournament/solver ] && [ -x ./tournament/solver ] ; then
    echo -e "\033[32;1mTOURNAMENT ALGORITHM STARTS NOW !!!\033[0m"
    begin=$(date +%S%3N)
    ./tournament/solver $1 1> /dev/null
    finishto=$(expr $(date +%S%3N) - $begin)
    echo -e "\033[32;1mTime of the TOURNAMENT :\t\033[34m${finishto} ms\033[0m"
else
    echo -e "\033[31;1;5mI can't find your TOURNAMENT's binary, sorry ! :(\033[0m"
fi
