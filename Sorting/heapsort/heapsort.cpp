#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Heap class has its internal array. The following array is only used for input
// where A[0] is used as one of the input elements.
int A[] = {66, 78, 300, 99, 88, 100, 45, 38, 12, 62, 42, 34, 8, 24, 66, 48};
int N = 16;


class Heap
{

    // #define  MaxHeapSize 100    

public:
        
    Heap(int N);
    ~Heap();
    
    void Insert(int v);
    int  Remove();
    
    
protected:
    
    void Upheap(int k);
    void Downheap(int k);
    
    
private:
    
    int * m_heapArray;
    int m_theLast;
};


Heap::Heap(int N)
{
    // It is an empty array now
    m_theLast = 0;
	// creating dynamic array based on input N; and set it 0
	// array is 1-based with memory being stored at index 1 instead of 0
	m_heapArray = (int *) malloc((N+1)* sizeof(int));
	memset(m_heapArray, 0, (N+1)* sizeof(int));
}

Heap::~Heap()
{
	if (m_heapArray)
	{
		free (m_heapArray);
		m_heapArray = NULL;
	}
	
}
    

void Heap::Insert(int v)
{
   m_theLast++;
   m_heapArray[m_theLast] = v;
   Upheap(m_theLast);   
}

int Heap::Remove()
{
   int v = m_heapArray[1];
   m_heapArray[1] = m_heapArray[m_theLast--];
   Downheap(1);
   
   return v;    
}

void Heap::Upheap(int k)
{
   int v = m_heapArray[k];
   /* m_heapArray[0] = 0xffff; */
   
   while ( k/2 > 0 && m_heapArray[k/2] <= v)
   {
      m_heapArray[k] = m_heapArray[k/2];
      k = k/2;  
   }

   m_heapArray[k] = v;
}

void Heap::Downheap(int k)
{
   int j, v;
   v = m_heapArray[k];
   
   while (k <= m_theLast/2)
   {
     j = k+k;
     if ((j<m_theLast)&&(m_heapArray[j]<m_heapArray[j+1])) j++;
     if (v >= m_heapArray[j]) break;
     m_heapArray[k] = m_heapArray[j];
     k = j;
   }
    
   m_heapArray[k] = v;  
}



// ------------------------------------------------
// 
//            Testing Case
//
// ------------------------------------------------
// void Heapsort(int a[], int n);

void Heapsort(int a[], int n)
{
   int i;
   Heap myHeap(n);
   
   for (i=0; i<n; i++) 
        myHeap.Insert(a[i]);
 
   for (i=n-1; i>=0; i--) 
        a[i] = myHeap.Remove(); 
}


int main()
{
   int i;
   
   printf("\nBefore sorting A[] = ");
   for (i=0; i<N; i++) printf("%d ", A[i]);
   printf("\n");
   
   Heapsort(&A[0], N);
   
   printf("After Heap C++ sorting A[] = ");
   for (i=0; i<N; i++) printf("%d ", A[i]);
   printf("\n\n");
   
   return 0;    
}
