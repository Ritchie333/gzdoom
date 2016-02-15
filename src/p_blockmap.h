#ifndef __P_BLOCKMAP_H
#define __P_BLOCKMAP_H

#include "doomtype.h"

class AActor;

// [RH] Like msecnode_t, but for the blockmap
struct FBlockNode
{
	AActor *Me;						// actor this node references
	int BlockIndex;					// index into blocklinks for the block this node is in
	FBlockNode **PrevActor;			// previous actor in this block
	FBlockNode *NextActor;			// next actor in this block
	FBlockNode **PrevBlock;			// previous block this actor is in
	FBlockNode *NextBlock;			// next block this actor is in

	static FBlockNode *Create (AActor *who, int x, int y);
	void Release ();

	static FBlockNode *FreeBlocks;
};

extern int*				blockmaplump;	// offsets in blockmap are from here

extern int*				blockmap;
extern int				bmapwidth;
extern int				bmapheight; 	// in mapblocks
extern fixed_t			bmaporgx;
extern fixed_t			bmaporgy;		// origin of block map
extern FBlockNode**		blocklinks; 	// for thing chains

#endif
