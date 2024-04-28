#!/bin/sh

# get command line args
filesdir=$1
searchstr=$2


if [ -z "$filesdir" ] || [ -z "$searchstr" ]
then
	echo "Use this script as '$0 <filesdir> <filestr>'"
	exit 1
fi


if [ -d "$filesdir" ]
then
	X=$(grep -rl $searchstr $filesdir | wc -l)
	Y=$(grep -r $searchstr $filesdir | wc -l)
	echo "The number of files are $X and the number of matching lines are $Y"
else
	echo "Directory '$filesdir' does not exists"
	exit 1
fi

