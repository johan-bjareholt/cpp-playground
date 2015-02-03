Heap
====

MaxHeap:
- Föräldern är alltid större än sina barn
- Fylls alltid enligt principen för ett komplett träd
- Byt plats med största barnet om det är större än sig själv

	ParentPos = (Pos-1)/2
	LeftChildPos = Pos+*2+1
	RightChildPos = Pos*2+2

5,8,12,4,55,9,1,17,11