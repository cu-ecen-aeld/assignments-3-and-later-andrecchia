#!/bin/sh

# get command line args
writefile=$1
writestr=$2


if [ -z "$writefile" ] || [ -z "$writestr" ]
then
	echo "Use this script as '$0 <writedir> <writestr>'"
        exit 1
fi

# Create path if not exists, take path from $writefile
# It exits with 1 error if not possible to create the folder
mkdir -p "$(dirname $writefile)"

#Write on file
echo "$writestr" > $writefile
