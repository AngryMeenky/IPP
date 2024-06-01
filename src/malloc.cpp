#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


Ref<IppBuffer> IPP::malloc_8u(int len) {
  return IppBuffer::create_empty(len, IPP::TYPE_8U);
}


Ref<IppBuffer> IPP::malloc_16u(int len) {
  return IppBuffer::create_empty(len, IPP::TYPE_16U);
}


Ref<IppBuffer> IPP::malloc_32u(int len) {
  return IppBuffer::create_empty(len, IPP::TYPE_32U);
}


Ref<IppBuffer> IPP::malloc_64u(int len) {
  return IppBuffer::create_empty(len, IPP::TYPE_64U);
}


Ref<IppBuffer> IPP::malloc_8s(int len) {
  return IppBuffer::create_empty(len, IPP::TYPE_8S);
}


Ref<IppBuffer> IPP::malloc_16s(int len) {
  return IppBuffer::create_empty(len, IPP::TYPE_16S);
}


Ref<IppBuffer> IPP::malloc_32s(int len) {
  return IppBuffer::create_empty(len, IPP::TYPE_32S);
}


Ref<IppBuffer> IPP::malloc_64s(int len) {
  return IppBuffer::create_empty(len, IPP::TYPE_64S);
}


Ref<IppBuffer> IPP::malloc_32f(int len) {
  return IppBuffer::create_empty(len, IPP::TYPE_32F);
}


Ref<IppBuffer> IPP::malloc_64f(int len) {
  return IppBuffer::create_empty(len, IPP::TYPE_64F);
}


Ref<IppBuffer> IPP::malloc_8sc(int len) {
  return IppBuffer::create_empty(len, IPP::TYPE_8SC);
}


Ref<IppBuffer> IPP::malloc_16sc(int len) {
  return IppBuffer::create_empty(len, IPP::TYPE_16SC);
}


Ref<IppBuffer> IPP::malloc_32sc(int len) {
  return IppBuffer::create_empty(len, IPP::TYPE_32SC);
}


Ref<IppBuffer> IPP::malloc_64sc(int len) {
  return IppBuffer::create_empty(len, IPP::TYPE_64SC);
}


Ref<IppBuffer> IPP::malloc_32fc(int len) {
  return IppBuffer::create_empty(len, IPP::TYPE_32FC);
}


Ref<IppBuffer> IPP::malloc_64fc(int len) {
  return IppBuffer::create_empty(len, IPP::TYPE_64FC);
}

