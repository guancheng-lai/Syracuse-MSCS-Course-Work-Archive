#!/bin/bash 

mkdir /tmp/allcfiles
workDir="$PWD"
echo "$workDir"

function findC {
	for fd in */; do
		cp find *.c /tmp/allcfiles
		if [ -d "$fd" ]; then
			echo $fd
			cd "$fd"
			findC
			cd ..
		fi
	done
}

findC
echo "Found all the .c files and copied to /tmp/allcfiles"

#cd /tmp/allcfiles
#echo "Changed directory to /tmp/allcfiles"

#tar cvfz allcfiles.tar *.c
#echo "Achived the .c files"

tar -C /tmp/allcfiles -cvf allcfiles.tar ./

cp allcfiles.tar "$workDir"
echo "Copy the archive to working directory"

