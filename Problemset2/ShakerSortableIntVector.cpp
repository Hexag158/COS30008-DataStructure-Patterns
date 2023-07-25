#include "ShakerSortableIntVector.h"

ShakerSortableIntVector :: ShakerSortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements) : SortableIntVector(aArrayOfIntegers, aNumberOfElements)
{
}

void ShakerSortableIntVector::sort(Comparable aOrderFunction)
{  
	size_t start = 0;
	size_t end = size() - 1;
	do 
	{
		for (size_t i = start; i < end; i++) {
			if (aOrderFunction(get(i), get(i+1)))
				swap(i, i + 1);
		}
		end --;
		for (size_t j = end ; j > start; j--) {
			if (aOrderFunction(get(j-1),get(j)))
				swap(j, j - 1);
		}
		start ++;
	} 
	while (start < end); 
};