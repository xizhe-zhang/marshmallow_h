/*
 * Copyright 2011 Marshmallow Engine. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this list of
 *      conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice, this list
 *      of conditions and the following disclaimer in the documentation and/or other materials
 *      provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY MARSHMALLOW ENGINE ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MARSHMALLOW ENGINE OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those of the
 * authors and should not be interpreted as representing official policies, either expressed
 * or implied, of Marshmallow Engine.
 */

#include "graphics/quadmesh.h"

/*!
 * @file
 *
 * @author Guillermo A. Amaral B. (gamaral) <g@maral.me>
 */

#include "graphics/factory.h"
#include "graphics/itexturecoordinatedata.h"
#include "graphics/ivertexdata.h"
#include "graphics/textureasset.h"

MARSHMALLOW_NAMESPACE_USE;
using namespace Graphics;

const Core::Type QuadMesh::Type("Graphics::QuadMesh");

QuadMesh::QuadMesh(const Math::Vector2 &tl,
                   const Math::Vector2 &bl,
                   const Math::Vector2 &br,
                   const Math::Vector2 &tr)
    : MeshBase(Factory::CreateTextureCoordinateData(QUAD_VERTEXES),
               Factory::CreateVertexData(QUAD_VERTEXES))
{
	setVertex(0, tl);
	setTextureCoordinate(0, 0, 0);
	setVertex(1, bl);
	setTextureCoordinate(1, 0, 1);
	setVertex(2, tr);
	setTextureCoordinate(2, 1, 0);
	setVertex(3, br);
	setTextureCoordinate(3, 1, 1);
}

QuadMesh::QuadMesh(const Math::Rect2  &r)
    : MeshBase(Factory::CreateTextureCoordinateData(QUAD_VERTEXES),
               Factory::CreateVertexData(QUAD_VERTEXES))
{
	setVertex(0, r.topLeft());
	setTextureCoordinate(0, 0, 0);
	setVertex(1, r.bottomLeft());
	setTextureCoordinate(1, 0, 1);
	setVertex(2, r.topRight());
	setTextureCoordinate(2, 1, 0);
	setVertex(3, r.bottomRight());
	setTextureCoordinate(3, 1, 1);
}

QuadMesh::QuadMesh(void)
    : MeshBase(Factory::CreateTextureCoordinateData(QUAD_VERTEXES),
               Factory::CreateVertexData(QUAD_VERTEXES))
{
	setTextureCoordinate(0, 0, 0);
	setTextureCoordinate(1, 0, 1);
	setTextureCoordinate(2, 1, 0);
	setTextureCoordinate(3, 1, 1);
}

QuadMesh::QuadMesh(SharedTextureCoordinateData tc, SharedVertexData v)
    : MeshBase(tc, v)
{
}

QuadMesh::~QuadMesh(void)
{
}

