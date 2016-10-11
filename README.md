# SOM++ based on 32bit omr. Let's call this project as SOMR( SOM+OMR).

To make it work , following instructions could do help. 

	#build the omr firstly.
	make omr
	
	#clean the omr
	make omrclean
	
	#build the som++
	make 
	
	#clean the som++
	make clean
	
	#build the omr and som++ together. 
	make somr
	
	#Clean the omr and som++
	make somrclean

	#Run the SOM
	./SOM++ -cp Smalltalk Examples/Hello/Hello.som
	./SOM++ -cp Smalltalk Examples/Benchmarks/Sum.som