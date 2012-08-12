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
#include "d3d_utils.h"

//=========================================
// Display Lists
//-----------------------------------------
// BIG TODO!
//=========================================

OPENGL_API void WINAPI glListBase (GLuint base)
{
	static bool warningPrinted = false;
	if (!warningPrinted) {
		warningPrinted = true;
		logPrintf("WARNING: glListBase: lists are not supported\n");
	}	
}

OPENGL_API void WINAPI glNewList (GLuint list,  GLenum mode)
{
	static bool warningPrinted = false;
	if (!warningPrinted) {
		warningPrinted = true;
		logPrintf("WARNING: glNewList: lists are not supported\n");
	}	
}

OPENGL_API void WINAPI glEndList (void)
{
	static bool warningPrinted = false;
	if (!warningPrinted) {
		warningPrinted = true;
		logPrintf("WARNING: glEndList: lists are not supported\n");
	}
}

OPENGL_API void WINAPI glCallList (GLuint list)
{
	static bool warningPrinted = false;
	if (!warningPrinted) {
		warningPrinted = true;
		logPrintf("WARNING: glCallList: lists are not supported\n");
	}
}

OPENGL_API void WINAPI glCallLists (GLsizei n,  GLenum type,  const GLvoid *lists)
{
	static bool warningPrinted = false;
	if (!warningPrinted) {
		warningPrinted = true;
		logPrintf("WARNING: glCallLists: lists are not supported\n");
	}
}

OPENGL_API void WINAPI glDeleteLists (GLuint list,  GLsizei range)
{
	static bool warningPrinted = false;
	if (!warningPrinted) {
		warningPrinted = true;
		logPrintf("WARNING: glDeleteLists: lists are not supported\n");
	}
}

OPENGL_API GLuint WINAPI glGenLists (GLsizei range)
{
	static bool warningPrinted = false;
	if (!warningPrinted) {
		warningPrinted = true;
		logPrintf("WARNING: glGenLists: lists are not supported\n");
	}
	return 0;
}

OPENGL_API GLboolean WINAPI glIsList (GLuint list)
{
	static bool warningPrinted = false;
	if (!warningPrinted) {
		warningPrinted = true;
		logPrintf("WARNING: glIsList: lists are not supported\n");
	}
	return GL_FALSE;
}