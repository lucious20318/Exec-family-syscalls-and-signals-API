all: sr st ques2

sr: SR.c
	gcc SR.c -o first
st: ST.c
	gcc ST.c -o sec
ques2: quest2.c
	gcc quest2.c -o question2
	./question2
