/***************************************************************************
* Copyright (C) 2011-2012, Chain Studios.
* 
* This file is part of QindieGL source code.
* Please note that QindieGL is not driver, it's emulator.
* 
* QindieGL source code is free software; you can redistribute it and/or 
* modify it under the terms of the GNU General Public License as 
* published by the Free Software Foundation; either version 2 of 
* the License, or (at your option) any later version.
* 
* QindieGL source code is distributed in the hope that it will be 
* useful, but WITHOUT ANY WARRANTY; without even the implied 
* warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
* See the GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software 
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
***************************************************************************/
#include "d3d_wrapper.h"
#include "d3d_global.h"
#include "d3d_utils.h"
#include "d3d_extension.h"

//This will enable export of our custom extensions
#define ALLOW_CHS_EXTENSIONS

//TODO:
//GL_ARB_depth_texture
//GL_ARB_vertex_buffer_object
//GL_ARB_point_sprite

OPENGL_API const char* WINAPI wglGetExtensionsStringARB( HDC hdc )
{
	return D3DGlobal.szWExtensions;
}

typedef struct glext_entry_point_s
{
	char *name;
	char *extname;
	int  enabled;
	PROC func;
} glext_entry_point_t;

#define GL_EXT_ENTRY_POINT( postfix, extname, func )				{ #func, "GL_" ## postfix ## "_" ## extname, -1, (PROC)func }, \
																	{ #func ## postfix, "GL_" ## postfix ## "_" ## extname, -1, (PROC)func }
#define WGL_EXT_ENTRY_POINT( postfix, extname, func )				{ #func, "WGL_" ## postfix ## "_" ## extname, -1, (PROC)func }, \
																	{ #func ## postfix, "WGL_" ## postfix ## "_" ## extname, -1, (PROC)func }

static glext_entry_point_t glext_EntryPoints[] =
{
	//GL_EXT_texture_object (not and extension in GL 1.1)
	GL_EXT_ENTRY_POINT( "EXT", "texture_object", glDeleteTextures ),
	GL_EXT_ENTRY_POINT( "EXT", "texture_object", glGenTextures ),
	GL_EXT_ENTRY_POINT( "EXT", "texture_object", glIsTexture ),
	GL_EXT_ENTRY_POINT( "EXT", "texture_object", glBindTexture ),
	GL_EXT_ENTRY_POINT( "EXT", "texture_object", glAreTexturesResident ),
	GL_EXT_ENTRY_POINT( "EXT", "texture_object", glPrioritizeTextures ),

	//GL_ARB_multitexture
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glActiveTexture ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glClientActiveTexture ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord1s ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord1i ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord1f ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord1d ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord2s ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord2i ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord2f ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord2d ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord3s ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord3i ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord3f ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord3d ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord4s ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord4i ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord4f ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord4d ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord1sv ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord1iv ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord1fv ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord1dv ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord2sv ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord2iv ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord2fv ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord2dv ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord3sv ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord3iv ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord3fv ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord3dv ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord4sv ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord4iv ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord4fv ),
	GL_EXT_ENTRY_POINT( "ARB", "multitexture", glMultiTexCoord4dv ),

	//GL_ARB_transpose_matrix
	GL_EXT_ENTRY_POINT( "ARB", "transpose_matrix", glLoadTransposeMatrixf ),
	GL_EXT_ENTRY_POINT( "ARB", "transpose_matrix", glLoadTransposeMatrixd ),
	GL_EXT_ENTRY_POINT( "ARB", "transpose_matrix", glMultTransposeMatrixf ),
	GL_EXT_ENTRY_POINT( "ARB", "transpose_matrix", glMultTransposeMatrixd ),

	//GL_EXT_blend_color
	GL_EXT_ENTRY_POINT( "EXT", "blend_color", glBlendColor ),

	//GL_EXT_blend_minmax and GL_EXT_blend_subtract
	GL_EXT_ENTRY_POINT( "EXT", "blend_minmax", glBlendEquation ),
	GL_EXT_ENTRY_POINT( "EXT", "blend_subtract", glBlendEquation ),

	//GL_EXT_compiled_vertex_array
	GL_EXT_ENTRY_POINT( "EXT", "compiled_vertex_array", glLockArrays ),
	GL_EXT_ENTRY_POINT( "EXT", "compiled_vertex_array", glUnlockArrays ),

	//GL_EXT_draw_range_elements
	GL_EXT_ENTRY_POINT( "EXT", "draw_range_elements", glDrawRangeElements ),

	//GL_EXT_multi_draw_arrays
	GL_EXT_ENTRY_POINT( "EXT", "multi_draw_arrays", glMultiDrawArrays ),
	GL_EXT_ENTRY_POINT( "EXT", "multi_draw_arrays", glMultiDrawElements ),
	GL_EXT_ENTRY_POINT( "SUN", "multi_draw_arrays", glMultiDrawArrays ),
	GL_EXT_ENTRY_POINT( "SUN", "multi_draw_arrays", glMultiDrawElements ),

	//GL_EXT_secondary_color
	GL_EXT_ENTRY_POINT( "EXT", "secondary_color", glSecondaryColor3b ),
	GL_EXT_ENTRY_POINT( "EXT", "secondary_color", glSecondaryColor3bv ),
	GL_EXT_ENTRY_POINT( "EXT", "secondary_color", glSecondaryColor3d ),
	GL_EXT_ENTRY_POINT( "EXT", "secondary_color", glSecondaryColor3dv ),
	GL_EXT_ENTRY_POINT( "EXT", "secondary_color", glSecondaryColor3f ),
	GL_EXT_ENTRY_POINT( "EXT", "secondary_color", glSecondaryColor3fv ),
	GL_EXT_ENTRY_POINT( "EXT", "secondary_color", glSecondaryColor3i ),
	GL_EXT_ENTRY_POINT( "EXT", "secondary_color", glSecondaryColor3iv ),
	GL_EXT_ENTRY_POINT( "EXT", "secondary_color", glSecondaryColor3s ),
	GL_EXT_ENTRY_POINT( "EXT", "secondary_color", glSecondaryColor3sv ),
	GL_EXT_ENTRY_POINT( "EXT", "secondary_color", glSecondaryColor3ub ),
	GL_EXT_ENTRY_POINT( "EXT", "secondary_color", glSecondaryColor3ubv ),
	GL_EXT_ENTRY_POINT( "EXT", "secondary_color", glSecondaryColor3ui ),
	GL_EXT_ENTRY_POINT( "EXT", "secondary_color", glSecondaryColor3uiv ),
	GL_EXT_ENTRY_POINT( "EXT", "secondary_color", glSecondaryColor3us ),
	GL_EXT_ENTRY_POINT( "EXT", "secondary_color", glSecondaryColor3usv ),
	GL_EXT_ENTRY_POINT( "EXT", "secondary_color", glSecondaryColorPointer ),

	//GL_EXT_fog_coord
	GL_EXT_ENTRY_POINT( "EXT", "fog_coord", glFogCoordd ),
	GL_EXT_ENTRY_POINT( "EXT", "fog_coord", glFogCoordf ),
	GL_EXT_ENTRY_POINT( "EXT", "fog_coord", glFogCoorddv ),
	GL_EXT_ENTRY_POINT( "EXT", "fog_coord", glFogCoordfv ),
	GL_EXT_ENTRY_POINT( "EXT", "fog_coord", glFogCoordPointer ),

	//GL_SGIS_multitexture
	GL_EXT_ENTRY_POINT( "SGIS", "multitexture", glSelectTexture ),
	GL_EXT_ENTRY_POINT( "SGIS", "multitexture", glMTexCoord2f ),
	GL_EXT_ENTRY_POINT( "SGIS", "multitexture", glMTexCoord2fv ),

	//GL_EXT_texture3D
	GL_EXT_ENTRY_POINT( "EXT", "texture3D", glTexImage3D ),
	GL_EXT_ENTRY_POINT( "EXT", "texture3D", glTexSubImage3D ),
	GL_EXT_ENTRY_POINT( "EXT", "texture3D", glCopyTexImage3D ),
	GL_EXT_ENTRY_POINT( "EXT", "texture3D", glCopyTexSubImage3D ),

	//GL_EXT_stencil_two_side
	GL_EXT_ENTRY_POINT( "EXT", "stencil_two_side", glActiveStencilFace ),

	//WGL_EXT_swap_control
	WGL_EXT_ENTRY_POINT( "EXT", "swap_control", wglSwapInterval ),
	WGL_EXT_ENTRY_POINT( "EXT", "swap_control", wglGetSwapInterval ),

	//WGL_ARB_extensions_string
	WGL_EXT_ENTRY_POINT( "ARB", "extensions_string", wglGetExtensionsStringARB ),

	{ NULL, NULL }
};

class CExtensionBuf
{
public:
	CExtensionBuf() 
	{
		m_size = 256;
		m_cur = 0;
		m_buf = (char*)UTIL_Alloc( m_size );
	}
	~CExtensionBuf()
	{
		UTIL_Free(m_buf);
	}
	char *CopyBuffer()
	{
		if (m_cur == 0)	return "";
		return UTIL_AllocString( m_buf );
	}
	void AddExtension( const char *ext )
	{
		if (!ext) return;
		if (!D3DGlobal_GetRegistryValue(ext, "Extensions")) return;
		size_t len = strlen(ext);
		CheckSpace( len + 2 );
		strcpy_s( m_buf + m_cur, len + 1, ext );
		*(m_buf + m_cur + len) = ' ';
		*(m_buf + m_cur + len + 1) = '\0';
		m_cur += len + 1;
	}
	void CheckSpace( int len )
	{
		if (m_size > m_cur + len) return;
		m_size += 256;
		m_buf = (char*)UTIL_Realloc( m_buf, m_size );
	}
private:
	int m_size;
	int m_cur;
	char *m_buf; 
};

void D3DExtension_BuildExtensionsString( void )
{
	assert( D3DGlobal.pD3D != NULL );
	assert( D3DGlobal.pDevice != NULL );

	CExtensionBuf ExtensionBuf;
	CExtensionBuf WExtensionBuf;
	int checkCaps;
	bool bCombineSupportEXT = true;
	bool bCombineSupportARB = true;

	if (D3DGlobal.maxActiveTMU > 1) ExtensionBuf.AddExtension( "GL_ARB_multitexture" );
	
	checkCaps = (D3DPTADDRESSCAPS_BORDER);
	if ((D3DGlobal.hD3DCaps.TextureAddressCaps & checkCaps) == checkCaps) ExtensionBuf.AddExtension( "GL_ARB_texture_border_clamp" );
	checkCaps = (D3DPTEXTURECAPS_CUBEMAP);
	if ((D3DGlobal.hD3DCaps.TextureCaps & checkCaps) == checkCaps) ExtensionBuf.AddExtension( "GL_ARB_texture_cube_map" );
	checkCaps = (D3DTEXOPCAPS_ADD);
	if ((D3DGlobal.hD3DCaps.TextureOpCaps & checkCaps) == checkCaps) ExtensionBuf.AddExtension( "GL_ARB_texture_env_add" );

	checkCaps = (D3DTEXOPCAPS_SELECTARG1);
	if ((D3DGlobal.hD3DCaps.TextureOpCaps & checkCaps) != checkCaps) bCombineSupportARB = false;
	checkCaps = (D3DTEXOPCAPS_MODULATE);
	if ((D3DGlobal.hD3DCaps.TextureOpCaps & checkCaps) != checkCaps) bCombineSupportARB = false;
	checkCaps = (D3DTEXOPCAPS_ADD);
	if ((D3DGlobal.hD3DCaps.TextureOpCaps & checkCaps) != checkCaps) bCombineSupportARB = false;
	checkCaps = (D3DTEXOPCAPS_ADDSIGNED);
	if ((D3DGlobal.hD3DCaps.TextureOpCaps & checkCaps) != checkCaps) bCombineSupportARB = false;
	checkCaps = (D3DTEXOPCAPS_LERP);
	if ((D3DGlobal.hD3DCaps.TextureOpCaps & checkCaps) != checkCaps) bCombineSupportARB = false;
	bCombineSupportEXT = bCombineSupportARB;
	checkCaps = (D3DTEXOPCAPS_SUBTRACT);
	if ((D3DGlobal.hD3DCaps.TextureOpCaps & checkCaps) != checkCaps) bCombineSupportARB = false;
	if (bCombineSupportARB) ExtensionBuf.AddExtension( "GL_ARB_texture_env_combine" );

	checkCaps = (D3DTEXOPCAPS_DOTPRODUCT3);
	if ((D3DGlobal.hD3DCaps.TextureOpCaps & checkCaps) == checkCaps) ExtensionBuf.AddExtension( "GL_ARB_texture_env_dot3" );

	checkCaps = (D3DPTADDRESSCAPS_MIRROR);
	if ((D3DGlobal.hD3DCaps.TextureAddressCaps & checkCaps) == checkCaps) ExtensionBuf.AddExtension( "GL_ARB_texture_mirrored_repeat" );

	if (!(D3DGlobal.hD3DCaps.TextureCaps & D3DPTEXTURECAPS_POW2) &&
		(!(D3DGlobal.hD3DCaps.TextureCaps & D3DPTEXTURECAPS_CUBEMAP) || !(D3DGlobal.hD3DCaps.TextureCaps & D3DPTEXTURECAPS_CUBEMAP_POW2)) &&
		(!(D3DGlobal.hD3DCaps.TextureCaps & D3DPTEXTURECAPS_VOLUMEMAP) || !(D3DGlobal.hD3DCaps.TextureCaps & D3DPTEXTURECAPS_VOLUMEMAP_POW2))) {
			ExtensionBuf.AddExtension( "GL_ARB_texture_non_power_of_two" );
	}

	//we implement them at driver level
	ExtensionBuf.AddExtension( "GL_ARB_transpose_matrix" );

	checkCaps = (D3DPTADDRESSCAPS_MIRRORONCE);
	if ((D3DGlobal.hD3DCaps.TextureAddressCaps & checkCaps) == checkCaps) ExtensionBuf.AddExtension( "GL_ATI_texture_mirror_once" );

#ifdef ALLOW_CHS_EXTENSIONS
	//our own specific extensions 
	//use CHS prefix (CHain Studios)
	checkCaps = (D3DPTEXTURECAPS_MIPVOLUMEMAP);
	if ((D3DGlobal.hD3DCaps.TextureCaps & checkCaps) == checkCaps) ExtensionBuf.AddExtension( "GL_CHS_mipmap_texture3D" );
#endif

	//we implement them at driver level
	ExtensionBuf.AddExtension( "GL_EXT_abgr" );
	ExtensionBuf.AddExtension( "GL_EXT_bgra" );

	checkCaps = (D3DPBLENDCAPS_BLENDFACTOR);
	if ((D3DGlobal.hD3DCaps.SrcBlendCaps & checkCaps) == checkCaps) {
		if ((D3DGlobal.hD3DCaps.DestBlendCaps & checkCaps) == checkCaps) {
			ExtensionBuf.AddExtension( "GL_EXT_blend_color" );
		}
	}
	checkCaps = (D3DPMISCCAPS_BLENDOP);
	if ((D3DGlobal.hD3DCaps.PrimitiveMiscCaps & checkCaps) == checkCaps) {
		ExtensionBuf.AddExtension( "GL_EXT_blend_minmax" );
		ExtensionBuf.AddExtension( "GL_EXT_blend_subtract" );
	}
	
	//we implement them at driver level
	ExtensionBuf.AddExtension( "GL_EXT_compiled_vertex_array" );
	ExtensionBuf.AddExtension( "GL_EXT_draw_range_elements" );
	ExtensionBuf.AddExtension( "GL_EXT_multi_draw_arrays" );
	ExtensionBuf.AddExtension( "GL_EXT_fog_coord" );
	ExtensionBuf.AddExtension( "GL_EXT_packed_pixels" );
	ExtensionBuf.AddExtension( "GL_EXT_secondary_color" );

	checkCaps = (D3DPTEXTURECAPS_VOLUMEMAP);
	if ((D3DGlobal.hD3DCaps.TextureCaps & checkCaps) == checkCaps) ExtensionBuf.AddExtension( "GL_EXT_texture3D" );
	checkCaps = (D3DPTEXTURECAPS_CUBEMAP);
	if ((D3DGlobal.hD3DCaps.TextureCaps & checkCaps) == checkCaps) ExtensionBuf.AddExtension( "GL_EXT_texture_cube_map" );
	
	checkCaps = (D3DTEXOPCAPS_ADD);
	if ((D3DGlobal.hD3DCaps.TextureOpCaps & checkCaps) == checkCaps) ExtensionBuf.AddExtension( "GL_EXT_texture_env_add" );
	if (bCombineSupportEXT) ExtensionBuf.AddExtension( "GL_EXT_texture_env_combine" );
	checkCaps = (D3DTEXOPCAPS_DOTPRODUCT3);
	if ((D3DGlobal.hD3DCaps.TextureOpCaps & checkCaps) == checkCaps) ExtensionBuf.AddExtension( "GL_EXT_texture_env_dot3" );

	if (D3DGlobal.hD3DCaps.MaxAnisotropy > 1) ExtensionBuf.AddExtension( "GL_EXT_texture_filter_anisotropic" );

	checkCaps = (D3DPRASTERCAPS_MIPMAPLODBIAS);
	if ((D3DGlobal.hD3DCaps.RasterCaps & checkCaps) == checkCaps) {
		ExtensionBuf.AddExtension( "GL_EXT_texture_lod" );		//assume per-object bias
		ExtensionBuf.AddExtension( "GL_EXT_texture_lod_bias" );	//assume per-stage bias
	}

	ExtensionBuf.AddExtension( "GL_EXT_texture_object" );	//GL 1.0 legacy, but exists in modern drivers, therefore we add it too

	checkCaps = (D3DSTENCILCAPS_TWOSIDED);
	if ((D3DGlobal.hD3DCaps.StencilCaps & checkCaps) == checkCaps) ExtensionBuf.AddExtension( "GL_EXT_stencil_two_side" );
	checkCaps = (D3DSTENCILCAPS_INCRSAT|D3DSTENCILCAPS_DECRSAT);
	if ((D3DGlobal.hD3DCaps.StencilCaps & checkCaps) == checkCaps) ExtensionBuf.AddExtension( "GL_EXT_stencil_wrap" );

	checkCaps = (D3DPTADDRESSCAPS_MIRROR);
	if ((D3DGlobal.hD3DCaps.TextureAddressCaps & checkCaps) == checkCaps) ExtensionBuf.AddExtension( "GL_IBM_texture_mirrored_repeat" );


	checkCaps = (D3DPBLENDCAPS_SRCCOLOR|D3DPBLENDCAPS_INVSRCCOLOR);
	if ((D3DGlobal.hD3DCaps.SrcBlendCaps & checkCaps) == checkCaps) {
		checkCaps = (D3DPBLENDCAPS_DESTCOLOR|D3DPBLENDCAPS_INVDESTCOLOR);
		if ((D3DGlobal.hD3DCaps.DestBlendCaps & checkCaps) == checkCaps) {
			ExtensionBuf.AddExtension( "GL_NV_blend_square" );
		}
	}

	//we implement it at driver level
	ExtensionBuf.AddExtension( "GL_NV_texgen_reflection" );

//	checkCaps = (D3DCAPS2_CANAUTOGENMIPMAP);
	//if ((D3DGlobal.hD3DCaps.Caps2 & checkCaps) == checkCaps) ExtensionBuf.AddExtension( "GL_SGIS_generate_mipmap" );

	//For Quake2 that won't use ARB extension
	if (D3DGlobal.maxActiveTMU > 1) ExtensionBuf.AddExtension( "GL_SGIS_multitexture" );

	//an alias to GL_EXT_multi_draw_arrays
	ExtensionBuf.AddExtension( "GL_SUN_multi_draw_arrays" );

	//we implement it at driver level
	ExtensionBuf.AddExtension( "WGL_ARB_extensions_string" );
	ExtensionBuf.AddExtension( "WGL_EXT_swap_control" );

	//add WGL extensions
	WExtensionBuf.AddExtension( "WGL_ARB_extensions_string" );
	WExtensionBuf.AddExtension( "WGL_EXT_swap_control" );

	D3DGlobal.szExtensions = ExtensionBuf.CopyBuffer();
	D3DGlobal.szWExtensions = WExtensionBuf.CopyBuffer();
}

//=========================================
// wglGetProcAddress
//-----------------------------------------
// Return a requested extension proc address
//=========================================
OPENGL_API PROC WINAPI wrap_wglGetProcAddress( LPCSTR s )
{
	const char *pszDisabledExt = NULL;

	for (int i = 0; ; i++) {
		// no more entrypoints
		if (!glext_EntryPoints[i].name) 
			break;

		if (glext_EntryPoints[i].enabled < 0) {
			glext_EntryPoints[i].enabled = D3DGlobal_GetRegistryValue(glext_EntryPoints[i].extname, "Extensions");
		}

		if (!strcmp(s, glext_EntryPoints[i].name)) {
			if (!glext_EntryPoints[i].enabled) {
				pszDisabledExt = glext_EntryPoints[i].extname;
				break;
			} else {
				logPrintf("wglGetProcAddress: queried proc '%s'\n", s);
				return glext_EntryPoints[i].func;
			}
		}
	}

	if (pszDisabledExt)
		logPrintf("WARNING: wglGetProcAddress: queried disabled proc '%s' (extension '%s')\n", s, pszDisabledExt);
	else
		logPrintf("WARNING: wglGetProcAddress: queried unknown proc '%s'\n", s);

	return (PROC)NULL;
}

OPENGL_API PROC WINAPI wrap_wglGetDefaultProcAddress( LPCSTR s )
{
	return wrap_wglGetProcAddress(s);
}

