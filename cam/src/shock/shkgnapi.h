/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/t2repos/thief2/src/shock/shkgnapi.h,v 1.18 2000/01/31 09:55:48 adurant Exp $
#pragma once

This file has been moved to gunapi.h AMSD


#ifndef __SHKGNAPI_H
#define __SHKGNAPI_H

#include <objtype.h>
#include <matrixs.h>
#include <matrixc.h>

//------------------------------------
// Gun API
//

// @TODO: This should really become a COM interface, I guess

// Load the gun with an ammo object
#define LF_NONE         0  // just load it and leave on cursor
#define LF_AUTOPLACE    1  // autoplace generated items in inventory
#define LF_JUGGLE       2  // delay autoplacement long enough to not hurl into world

EXTERN void GunLoad(ObjID gunID, ObjID ammoID, uint flags);
// For use by player animation 
EXTERN void GunLoadSound(ObjID gunID);
// Unload the gun, create new clip obj
EXTERN ObjID GunUnload(ObjID gunID, uint flags);

// Ammo
// Get the projectile object (archetype) for the current ammo in the gun
EXTERN ObjID GetProjectile(ObjID gunID);
// find the projectile object (archetype) of a given "gun", with an order
EXTERN ObjID GetProjectileByOrder(ObjID gunID, int order);
// Can the gun load this clip?
BOOL GunCanLoad(ObjID gunID, ObjID clipID);
// Get the projectile associated with a given clip
// NOTE: returns OBJ_NULL if more than one proj/clip
ObjID GetProjectileFromClip(ObjID clipID, ObjID gunID);
// Get clip archetype for a projectile archetype
ObjID GetClip(ObjID projID);
// Get the next valid projectile (archetype) for the gun
EXTERN ObjID GetNextProjectile(ObjID gunID, ObjID projID);
EXTERN void SetProjectile(ObjID gunID, ObjID projID);
EXTERN int GunGetAmmoCount(ObjID gunID);

// Condition
EXTERN float GunGetCondition(ObjID gunID);
EXTERN void GunSetCondition(ObjID gunID, float condition);
EXTERN void GunGetConditionString(ObjID gunID, char *buf, int buflen);

// Settings
// Note: all setting changes should go through this API!
EXTERN int GunGetSetting(ObjID gunID);
EXTERN void GunSetSetting(ObjID gunID, int setting);

// Mod
EXTERN int GunGetModification(ObjID gunID);
EXTERN void GunSetModification(ObjID gunID, int modification);

// Init the whole gun system
EXTERN void GunInit(void);
#endif
