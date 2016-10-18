#pragma once
#ifndef HEAP_H_
#define HEAP_H_

/*
 *
 *
Copyright (c) 2007 Michael Haupt, Tobias Pape, Arne Bergmann
Software Architecture Group, Hasso Plattner Institute, Potsdam, Germany
http://www.hpi.uni-potsdam.de/swa/

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
  */


#include <vector>

//#include "GarbageCollector.h"

#include "../misc/defs.h"

#include "../vmobjects/ObjectFormats.h"



class VMObject;
class VMFreeObject;
class MM_EnvironmentBase;
class MM_ObjectAllocationInterface;
class MM_GCExtensionsBase;
class MM_Heap;
class OMR_VM_Example;
class OMR_VMThread;

//macro to access the heap
#define _HEAP Heap::GetHeap()

struct FreeListEntry 
{
    size_t size;
} ;

extern OMR_VMThread * omrVMThread;


class Heap
{
	//friend class GarbageCollector;

public:
    static Heap* GetHeap();
    static void InitializeHeap(int objectSpaceSize = 1048576,OMR_VM_Example *vm=NULL);
    static void DestroyHeap();
	Heap(uintptr_t objectSpaceSize = 1048576,OMR_VM_Example *vm=NULL);

	~Heap();
    VMObject* AllocateObject(size_t size);
	void* Allocate(size_t size);
    void Free(void* ptr);
	void Destroy(VMObject*);
	
    void StartUninterruptableAllocation() { ++uninterruptableCounter; } ;
    void EndUninterruptableAllocation() { --uninterruptableCounter; } ;

   // void PrintFreeList();
    
    void FullGC();
    OMR_VM_Example * getVM(){return _vm;}
    
private:
    static class Heap * theHeap;

    void internalFree(void* ptr);
	void* internalAllocate(size_t size);
	int uninterruptableCounter;
	OMR_VM_Example * _vm;
	OMR_VMThread * _vmthread ;
	MM_Heap * omrHeap;
	MM_EnvironmentBase *env;
	MM_ObjectAllocationInterface *allocationInterface;
	MM_GCExtensionsBase *extensions ;
	uint32_t numAlloc;
	/* zg. This class is just a wrapper of extensions->heap.
	void* objectSpace;

	VMFreeObject* freeListStart;
    
    
	
    int objectSpaceSize;
	int buffersizeForUninterruptable;

	int sizeOfFreeHeap;

	GarbageCollector* gc;

    uint32_t numAlloc;
    uint32_t spcAlloc;
    uint32_t numAllocTotal;
    */
};

#endif
