/*
 *  PolyPolygon.h
 *  Poly
 *
 *  Created by Ivan Safrin on 3/14/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

// @package BasicTypes

#pragma once
#include "PolyString.h"
#include <math.h>
#include "PolyGlobals.h"
#include "PolyVertex.h"
#include "PolyVector3.h"
#include "PolyVector2.h"
#include "PolyRectangle.h"
#include <vector>

using std::vector;

using std::min;
using std::max;

namespace Polycode {

	class _PolyExport Polygon {
	
		public:
			Polygon();
			~Polygon();
			
			unsigned int getVertexCount();
			Vertex *getVertex(unsigned int index);
			Vertex *addVertex(Number x, Number y, Number z);
			
			void removeVertex(int index);
		
			void addTexCoord(Number u, Number v);
			void addTexCoord2(Number u, Number v);
			Vector2 getTexCoord(int index);
			Vector2 getTexCoord2(int index);
			void addVertex(Vertex *vertex);
			Vertex *addVertex(Number x, Number y, Number z, Number u, Number v);
			void calculateNormal();
			
			Vector3 getFaceNormal();
			Rectangle getBounds2D();
			
			void setNormal(Vector3 normal);
											
			bool useVertexNormals;
		
			void flipUVY();
			
			void setUseFaceUV(bool val);
			bool usesFaceUV();

			bool hasSecUVs;
						
		private:
		
			bool useFaceUV;
			unsigned int vertexCount;
			vector<Vertex*> vertices;
			vector<Vector2> texCoords;
			vector<Vector2> texCoords2;
			Vector3			normal;
	};

}