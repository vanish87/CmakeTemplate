#ifndef COMMON_PREDEC_H_
#define COMMON_PREDEC_H_

#pragma once

//dll defines
//#define VENGINE_API __declspec(dllexport)
#define VENGINE_API

#include <cstdint>

//debug and assert
#include "Common/Header/DebugMessage.h"

#include "vEngine/vEngine-version.h"

#define PRINT(x) std::cout<<x<<std::endl;
#define PRINT_VAR(x) std::cout<<#x<<": "<<std::endl;x.Print();
#define PRINT_WARNING(x) WarningText(x);
#define PRINT_ERROR(x) ErrorText(x);
#define PRINT_AND_RETURN(x, returnVal) {PRINT(x);return returnVal;}
#define PRINT_FILE_AND_FUCTION PRINT("in File "<<__FILE__<<" Line "<<__LINE__<<" Function "<<__FUNCTION__);
#if _MSC_VER >= 1400 
#define DEBUG_BREAK __debugbreak();
#else
#include <signal.h>
#define DEBUG_BREAK raise(SIGTRAP);
#endif
#define PRINT_AND_BREAK(x) \
{\
	PRINT(x); \
	PRINT_FILE_AND_FUCTION;\
	DEBUG_BREAK\
}	
#define CHECK_AND_ASSERT(condition,x) \
{\
	if(!(condition)){\
		PRINT(x); \
		PRINT_FILE_AND_FUCTION;\
		DEBUG_BREAK}\
}
#define CHECK_ASSERT(condition) \
{\
	if(!(condition)){\
		PRINT_FILE_AND_FUCTION;\
		DEBUG_BREAK}\
}
#define COMPILE_PRINT_AND_ASSERT(exp, x) {static_assert(exp, x);}

#define DEBUG_CLASS_FILE_NAME virtual std::string GetName() override { return __FILE__; };
#define DEBUG_CLASS_NAME(x) virtual std::string GetName() override { return x; };

//try to add Init function to init class_name
#define SINGLETON_PRAVATE(class_name)\
private:\
	class_name(); \
	class_name(class_name const&){__debugbreak();}; \
	class_name& operator=(class_name const&){__debugbreak();}; \
	~class_name(); 

//another way to link static libs
//#pragma comment(lib, LIB_FILE_NAME)

//#define ENABLE_TEST
//#define ENABLE_SCENE_TEST

namespace vEngine
{
	typedef std::int8_t  int8_t;
	typedef std::int16_t int16_t;
	typedef std::int32_t int32_t;
	typedef std::int64_t int64_t;
	typedef unsigned char	 byte;
	typedef std::uint8_t  uint8_t;
	typedef std::uint16_t uint16_t;
	typedef std::uint32_t uint32_t;
	typedef std::uint64_t uint64_t;
	
	template <typename T>
	class Vec2;
	typedef Vec2<int32_t> int2;
	typedef Vec2<float> float2;

	template <typename T>
	class Vec3;
	typedef Vec3<int32_t> int3;
	typedef Vec3<float> float3;

	template <typename T>
	class Vec4;
	typedef Vec4<int32_t> int4;	
	typedef Vec4<float> float4;

 	template <typename T>
 	class Matrix;
	typedef Matrix<float> float4x4;

	template <typename T>
	class Matrix3D;
	typedef Matrix3D<float> float3x3;

	template <typename T>
	class Matrix2D;
	typedef Matrix2D<float> float2x2;

	class Timer;

	template <typename T>
	class Sphere;
	typedef Sphere<float> sphere;

	#ifdef _DEBUG
	class StringHash;
	typedef StringHash string_hash;
	#else
	#warning "This is not workign here becasue size_t(string xxx) will return address of this string"
	typedef size_t string_hash;
	#endif

	class Ray;
	class AABBox;

	class ReturnCode;
}

#endif