# /bin/bash
path=`pwd`
base=`basename $path`
if [ -f $base.c ]
then
	echo $base ".c already exist."
else
	touch $base.c
fi

if [ -f $base.h ]
then
	echo $base ".h already exist."
else
	touch $base.h
fi
