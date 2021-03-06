#define SLEEF_LIB
#include "SleefVsSvml.h"

#ifdef _USRDLL
#define EXPORT_FCNS
#include "SleefVsSvmlDll.h"
#endif // _USRDLL
#ifndef _USRDLL

#endif // !_USRDLL

void ExpSleefSse(float* vO, float* vI, int numElements)
{

	int ii;
	__m128 elmI;

	for (ii = 0; ii < numElements; ii += SSE_STRIDE_32B) {
		elmI = _mm_loadu_ps(&vI[ii]);
		elmI = Sleef_expf4_u10sse4(elmI);
		_mm_store_ps(&vO[ii], elmI);
	}


}


void ExpSleefAvx(float* vO, float* vI, int numElements)
{

	int ii;
	__m256 elmI;

	for (ii = 0; ii < numElements; ii += AVX_STRIDE_32B) {
		elmI = _mm256_loadu_ps(&vI[ii]);
		elmI = Sleef_expf8_u10avx2(elmI);
		_mm256_store_ps(&vO[ii], elmI);
	}


}


void ExpSvmlSse(float* vO, float* vI, int numElements)
{

	int ii;
	__m128 elmI;

	for (ii = 0; ii < numElements; ii += SSE_STRIDE_32B) {
		elmI = _mm_loadu_ps(&vI[ii]);
		elmI = _mm_exp_ps(elmI);
		_mm_store_ps(&vO[ii], elmI);
	}


}


void ExpSvmlAvx(float* vO, float* vI, int numElements)
{

	int ii;
	__m256 elmI;

	for (ii = 0; ii < numElements; ii += AVX_STRIDE_32B) {
		elmI = _mm256_loadu_ps(&vI[ii]);
		elmI = _mm256_exp_ps(elmI);
		_mm256_store_ps(&vO[ii], elmI);
	}


}