// This code contains NVIDIA Confidential Information and is disclosed to you
// under a form of NVIDIA software license agreement provided separately to you.
//
// Notice
// NVIDIA Corporation and its licensors retain all intellectual property and
// proprietary rights in and to this software and related documentation and
// any modifications thereto. Any use, reproduction, disclosure, or
// distribution of this software and related documentation without an express
// license agreement from NVIDIA Corporation is strictly prohibited.
//
// ALL NVIDIA DESIGN SPECIFICATIONS, CODE ARE PROVIDED "AS IS.". NVIDIA MAKES
// NO WARRANTIES, EXPRESSED, IMPLIED, STATUTORY, OR OTHERWISE WITH RESPECT TO
// THE MATERIALS, AND EXPRESSLY DISCLAIMS ALL IMPLIED WARRANTIES OF NONINFRINGEMENT,
// MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE.
//
// Information and code furnished is believed to be accurate and reliable.
// However, NVIDIA Corporation assumes no responsibility for the consequences of use of such
// information or for any infringement of patents or other rights of third parties that may
// result from its use. No license is granted by implication or otherwise under any patent
// or patent rights of NVIDIA Corporation. Details are subject to change without notice.
// This code supersedes and replaces all information previously supplied.
// NVIDIA Corporation products are not authorized for use as critical
// components in life support devices or systems without express written approval of
// NVIDIA Corporation.
//
// Copyright (c) 2008-2020 NVIDIA Corporation. All rights reserved.


#ifndef BLAST_FAMILY_MODEL_SIMPLE_H
#define BLAST_FAMILY_MODEL_SIMPLE_H

#include "BlastFamily.h"
#include "BlastAssetModelSimple.h"

class SimpleRenderMesh;
class Renderable;
class Renderer;

class BlastFamilyModelSimple : public BlastFamily
{
public:
	//////// ctor ////////

	BlastFamilyModelSimple(PhysXController& physXController, ExtPxManager& pxManager, Renderer& renderer, const BlastAssetModelSimple& blastAsset, const BlastAsset::ActorDesc& desc);
	virtual ~BlastFamilyModelSimple();

protected:
	//////// abstract implementation ////////

	virtual void onActorCreated(const ExtPxActor& actor);
	virtual void onActorUpdate(const ExtPxActor& actor);
	virtual void onActorDestroyed(const ExtPxActor& actor);
	virtual void onActorHealthUpdate(const ExtPxActor& pxActor);

private:
	//////// internal data ////////

	Renderer& m_renderer;

	struct Chunk
	{
		std::vector<SimpleRenderMesh*> renderMeshes;
		std::vector<Renderable*> renderables;
	};

	std::vector<Chunk> m_chunks;
};


#endif //BLAST_FAMILY_MODEL_SIMPLE_H