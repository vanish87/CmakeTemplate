#include <iostream>
#include "assimp/anim.h"
#include "tinyxml2.h"
#include "lua.h"
#include "ft2build.h"
#include FT_FREETYPE_H
//#include "FX11/d3dx11effect.h"
#include "Common/Header/CommonPreDec.h"
#include "Common/Header/Vector.h"
#include "Common/Header/Math.h"

using namespace std;
using namespace vEngine;

int main(int argc, char* argv[])
{
    cout<<"Hello World"<<endl;
  //  aiVector2D vectortest;
    //D3DX11_EFFECT_DESC desc;
    
	FT_Library  library;
	FT_Face     face;
    
	FT_Error error = FT_Init_FreeType(&library);
	error = FT_Done_FreeType(library);


	float3 pos = float3(0);
	pos.x() += 1;

	float test = Math::InvSqrt(10);
}
