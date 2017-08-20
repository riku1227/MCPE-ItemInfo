#pragma once

#include "Mob.h"

class Player : public Mob
{
public:
    virtual void normalTick();
public:
    ItemInstance* getSelectedItem()const;
};