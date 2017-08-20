#pragma once

/*
Minecraft 1.2.0.15
*/

#include <string>

class ClientInstance;

class GuiData
{
public:
    GuiData(ClientInstance &);
    ~GuiData();
public:
    void tick();
    void showTipMessage(std::string const&);
};