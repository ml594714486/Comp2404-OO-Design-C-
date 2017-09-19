#include "Subject.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
using namespace std;

Subject::Subject(){
	size = 0;
}
void Subject::subscribe(Observer* obj){
	if (size >= MAX_ARR)
		 return;

	list[size] = obj;
        ++size;

}
void Subject::unsubscribe(Observer* obj){
	int i;
	for(i=0;i<size;i++){
		if(list[i]==obj){
			int x;
			for(x=i;x<size-1;x++){
				list[x]=list[x+1];
			
				}	
			list[size-1]=NULL;
			i=size;
			size--;
		  }

	}
}
Observer** Subject::getlist(){
	return list;
}

void Subject::notify(){
	int i;

	for(i=0;i<size;i++){
		list[i]->update();
	}


}

