#pragma once

class ItemInstance;

class Player {
public:
    virtual void normalTick();

    ItemInstance* getSelectedItem() const;
};