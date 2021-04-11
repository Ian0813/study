#!/bin/bash


change(){
	for i in 3 4 5 6 7 8 9;
	do
		if [ -e 1-$i.c ]
		then
			mv 1-$i.c 1-0$i.c
		fi
	done
	echo "Hello"
}

move_file(){
	number=9
	#echo $file
	file=`find . -name "*.c"|grep "03"`
	echo $num
	for i in {3..24}
	do
	       if [ "$i" -le "$number" ];
	       then	       
	      	       file=`find . -name "*.c"|grep "0$i"`
	     	       echo $file
		       mv $file ./Exercise_0$i
	       else
		       mv 1-$i.c ./Exercise_$i
       	       fi
	done
}

create_folder(){
	num=9
	for i in {3..24}
	do
#		rm -rf Exercise_$i
		if [ !  -e Exercise_$i ]
		then
			#rm -rf Exercise_$i
			if [ "$i" -le "$num" ] 
			then 
				mkdir Exercise_0$i
				touch 1-0$i.c
			else
				mkdir Exercise_$i
				echo "Hello"
				touch 1-$i.c
				echo $i
			fi
		fi
	done
}
change
#create_folder
move_file
#create_folder

