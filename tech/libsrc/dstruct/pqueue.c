#include <io.h>
#include "pqueue.h"
#include "string.h"
/*
 * $Source: r:/prj/lib/src/dstruct/rcs/pqueue.c $
 * $Revision: 1.1 $
 * $Author: mahk $
 * $Date: 1993/08/09 20:30:58 $
 *
 * $Log: pqueue.c $
 * Revision 1.1  1993/08/09  20:30:58  mahk
 * Initial revision
 * 
 *
 */
// -------
// DEFINES
// -------

#define LCHILD(i) (2*(i)+2)
#define RCHILD(i) (2*(i)+1)
#define PARENT(i) (((i)-1)/2)
#define NTH(pq,n)  ((void*)(((pq)->vec)+(n)*((pq)->elemsize)))
#define LESS(pq,i1,i2) ((pq)->comp(NTH(pq,i1),NTH(pq,i2)) < 0)
#define NULL_CHILD 0xFFFFFFFF


// -------
// GLOBALS
// -------

static char* swap_buffer = NULL;
static int swap_bufsize = 0;
// ---------
// INTERNALS
// ---------

void swapelems(PQueue* q,int i, int j)
{
   memcpy(swap_buffer,NTH(q,i),q->elemsize);
   memcpy(NTH(q,i),NTH(q,j),q->elemsize);
   memcpy(NTH(q,j),swap_buffer,q->elemsize);
}

void re_heapify(PQueue *q)
{
   uint head = 0;
   while (head < q->fullness)
   {
      uint lchild = LCHILD(head); 
      uint rchild = RCHILD(head);
      uint minchild = NULL_CHILD;
      if (rchild >= q->fullness)
         minchild = lchild;
      if (lchild >= q->fullness)
         minchild = rchild;
      if (minchild == NULL_CHILD)
         if (LESS(q,lchild,rchild))
         {
            minchild = lchild;
         }
         else
         {
            minchild = rchild;
         }
      if (minchild < q->fullness && LESS(q,minchild,head))
      {
         swapelems(q,head,minchild);
         head = minchild;
      }
      else break;
   }
}


void double_re_heapify(PQueue *q, int head)
{
   uint lchild = LCHILD(head); 
   uint rchild = RCHILD(head);
   uint minchild = NULL_CHILD;
   uint maxchild = NULL_CHILD;
   if (rchild >= q->fullness)
      minchild = lchild;
   if (lchild >= q->fullness)
      minchild = rchild;
   if (minchild == NULL_CHILD)
      if (LESS(q,lchild,rchild))
      {
         minchild = lchild;
         maxchild = rchild;
      }
      else
      {
         minchild = rchild;
         maxchild = lchild;
      }
   if (minchild < q->fullness && LESS(q,minchild,head))
   {
      swapelems(q,head,minchild);
      double_re_heapify(q,minchild);
      if (maxchild < q->fullness)
         double_re_heapify(q,maxchild);
   }
}
      
// ---------
// EXTERNALS
// ---------

errtype pqueue_init(PQueue* q, int size, int elemsize, QueueCompare comp, bool grow)
{
   if (size < 1) return ERR_RANGE;
   q->vec = Malloc(elemsize*size);
   if (q->vec == NULL) return ERR_NOMEM;
   if (elemsize > swap_bufsize)
   {
      if (swap_buffer == NULL) swap_buffer = Malloc(elemsize);
      else swap_buffer = Realloc(swap_buffer,elemsize);
      swap_bufsize = elemsize;
      if (swap_buffer == NULL) return ERR_NOMEM;
   }
   q->size = size;
   q->fullness = 0;
   q->elemsize = elemsize;
   q->comp = comp;
   q->grow = grow;
   return OK;
}

errtype pqueue_insert(PQueue* q, void* elem)
{
   int n;
   if (!q->grow && q->fullness >= q->size)
      return ERR_DOVERFLOW;
   while (q->fullness >= q->size)
   {
      q->vec = Realloc(q->vec,q->elemsize*q->size*2);
      q->size*=2;
      if (q->vec == NULL) return ERR_NOMEM;
   }
   n = q->fullness++;
   memcpy(NTH(q,n),elem,q->elemsize);
   while(n > 0)
   {
      if (LESS(q,PARENT(n),n))
         break;
      swapelems(q,n,PARENT(n));
      n = PARENT(n);
   }
   return OK;
}

errtype pqueue_extract(PQueue* q, void* elem)
{
   if (q->fullness == 0) return ERR_DUNDERFLOW;
   memcpy(elem,NTH(q,0),q->elemsize);
   memcpy(NTH(q,0),NTH(q,q->fullness-1),q->elemsize);
   q->fullness--;
   re_heapify(q);
   return OK;
}

errtype pqueue_least(PQueue* q, void* elem)
{
   if (q->fullness == 0) return ERR_DUNDERFLOW;
   memcpy(elem,NTH(q,0),q->elemsize);
   return OK;
}

errtype pqueue_write(PQueue* q, int fd, void (*writefunc)(int fd, void* elem))
{
   int i;
   _write(fd,(char*)q,sizeof(PQueue));
   for(i = 0; i < q->fullness; i++)
   {
      if (writefunc != NULL)
         writefunc(fd,NTH(q,i));
      else _write(fd,(char*)NTH(q,i),q->elemsize);
   }
   return OK;
}

errtype pqueue_read(PQueue* q, int fd, void (*readfunc)(int fd, void* elem))
{
   int i;
   _read(fd,(char*)q,sizeof(PQueue));
   if (q->grow) q->size = q->fullness;
   q->vec = Malloc(q->size*q->elemsize);
   if (q->vec == NULL) return ERR_NOMEM;
   for(i = 0; i < q->fullness; i++)
   {
      if (readfunc != NULL)
         readfunc(fd,NTH(q,i));
      else _read(fd,(char*)NTH(q,i),q->elemsize);
   }
   return OK;
}

errtype pqueue_destroy(PQueue* q)
{
   Free(q->vec);
   q->fullness = 0;
   return OK;
}
