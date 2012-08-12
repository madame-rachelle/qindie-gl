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
#include "d3d_state.h"

//=========================================
// Evaluators
//-----------------------------------------
// TODO: implement them like in Mesa lib?
//=========================================

OPENGL_API void WINAPI glEvalCoord1d( GLdouble u )
{
	logPrintf("WARNING: glEvalCoord1d: evaluators are not supported\n");
}

OPENGL_API void WINAPI glEvalCoord1dv( const GLdouble *u )
{
	logPrintf("WARNING: glEvalCoord1dv: evaluators are not supported\n");
}

OPENGL_API void WINAPI glEvalCoord1f( GLfloat u )
{
	logPrintf("WARNING: glEvalCoord1f: evaluators are not supported\n");
}

OPENGL_API void WINAPI glEvalCoord1fv( const GLfloat *u )
{
	logPrintf("WARNING: glEvalCoord1fv: evaluators are not supported\n");
}

OPENGL_API void WINAPI glEvalCoord2d( GLdouble u,  GLdouble v )
{
	logPrintf("WARNING: glEvalCoord2d: evaluators are not supported\n");
}

OPENGL_API void WINAPI glEvalCoord2dv( const GLdouble *u )
{
	logPrintf("WARNING: glEvalCoord2dv: evaluators are not supported\n");
}

OPENGL_API void WINAPI glEvalCoord2f( GLfloat u,  GLfloat v )
{
	logPrintf("WARNING: glEvalCoord2f: evaluators are not supported\n");
}

OPENGL_API void WINAPI glEvalCoord2fv( const GLfloat *u )
{
	logPrintf("WARNING: glEvalCoord2fv: evaluators are not supported\n");
}

OPENGL_API void WINAPI glEvalMesh1( GLenum mode,  GLint i1,  GLint i2 )
{
	logPrintf("WARNING: glEvalMesh1: evaluators are not supported\n");
}

OPENGL_API void WINAPI glEvalMesh2( GLenum mode,  GLint i1,  GLint i2,  GLint j1,  GLint j2 )
{
	logPrintf("WARNING: glEvalMesh2: evaluators are not supported\n");
}

OPENGL_API void WINAPI glEvalPoint1( GLint i )
{
	logPrintf("WARNING: glEvalPoint1: evaluators are not supported\n");
}

OPENGL_API void WINAPI glEvalPoint2( GLint i,  GLint j )
{
	logPrintf("WARNING: glEvalPoint2: evaluators are not supported\n");
}

OPENGL_API void WINAPI glGetMapdv (GLenum target,  GLenum query,  GLdouble *v)
{
	logPrintf("WARNING: glGetMapdv: evaluators are not supported\n");
}

OPENGL_API void WINAPI glGetMapfv (GLenum target,  GLenum query,  GLfloat *v)
{
	logPrintf("WARNING: glGetMapfv: evaluators are not supported\n");
}

OPENGL_API void WINAPI glGetMapiv (GLenum target,  GLenum query,  GLint *v)
{
	logPrintf("WARNING: glGetMapiv: evaluators are not supported\n");
}

OPENGL_API void WINAPI glMap1d (GLenum target,  GLdouble u1,  GLdouble u2,  GLint stride,  GLint order,  const GLdouble *points)
{
	logPrintf("WARNING: glMap1d: evaluators are not supported\n");
}

OPENGL_API void WINAPI glMap1f (GLenum target,  GLfloat u1,  GLfloat u2,  GLint stride,  GLint order,  const GLfloat *points)
{
	logPrintf("WARNING: glMap1f: evaluators are not supported\n");
}

OPENGL_API void WINAPI glMap2d (GLenum target,  GLdouble u1,  GLdouble u2,  GLint ustride,  GLint uorder,  GLdouble v1,  GLdouble v2,  GLint vstride,  GLint vorder,  const GLdouble *points)
{
	logPrintf("WARNING: glMap2d: evaluators are not supported\n");
}

OPENGL_API void WINAPI glMap2f (GLenum target,  GLfloat u1,  GLfloat u2,  GLint ustride,  GLint uorder,  GLfloat v1,  GLfloat v2,  GLint vstride,  GLint vorder,  const GLfloat *points)
{
	logPrintf("WARNING: glMap2f: evaluators are not supported\n");
}

OPENGL_API void WINAPI glMapGrid1d (GLint un,  GLdouble u1,  GLdouble u2)
{
	logPrintf("WARNING: glMapGrid1d: evaluators are not supported\n");
}

OPENGL_API void WINAPI glMapGrid1f (GLint un,  GLfloat u1,  GLfloat u2)
{
	logPrintf("WARNING: glMapGrid1f: evaluators are not supported\n");
}

OPENGL_API void WINAPI glMapGrid2d (GLint un,  GLdouble u1,  GLdouble u2,  GLint vn,  GLdouble v1,  GLdouble v2)
{
	logPrintf("WARNING: glMapGrid2d: evaluators are not supported\n");
}

OPENGL_API void WINAPI glMapGrid2f (GLint un,  GLfloat u1,  GLfloat u2,  GLint vn,  GLfloat v1,  GLfloat v2)
{
	logPrintf("WARNING: glMapGrid2f: evaluators are not supported\n");
}